#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE  sizeof(struct shared)

struct shared {
    char sel[100];
    int b;
};

int main() {
    int shmid;
    key_t key;
    struct shared *shm;
    int pipefd[2];

    key = ftok("banking_app", 'A');
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    
    shm = (struct shared *)shmat(shmid, NULL, 0);
    if (shm == (struct shared *)-1) {
        perror("shmat");
        exit(1);
    }


    shm->b = 1000;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) { 
        close(pipefd[1]); 

        char message[100];
        read(pipefd[0], message, sizeof(message));
        printf("%s", message);

        close(pipefd[0]); 
        exit(0);
    } else { 
        close(pipefd[0]); 

        while (1) {
            printf("Provide Your Input From Given Options:\n");
            printf("1. Type a to Add Money\n");
            printf("2. Type w to Withdraw Money\n");
            printf("3. Type c to Check Balance\n");

            fgets(shm->sel, sizeof(shm->sel), stdin);
            strtok(shm->sel, "\n"); 

            if (strcmp(shm->sel, "a") == 0 || strcmp(shm->sel, "w") == 0 || strcmp(shm->sel, "c") == 0) {
                printf("Your selection: %s\n", shm->sel);
                if (strcmp(shm->sel, "a") == 0) {
                    printf("Enter amount to be added:\n");
                    int amount;
                    scanf("%d", &amount);
                    if (amount > 0) {
                        shm->b += amount;
                        printf("Balance added successfully\n");
                        printf("Updated balance after addition:\n%d\n", shm->b);
                    } else {
                        printf("Adding failed, Invalid amount\n");
                    }
                } else if (strcmp(shm->sel, "w") == 0) {
                    printf("Enter amount to be withdrawn:\n");
                    int amount;
                    scanf("%d", &amount);
                    if (amount > 0 && amount <= shm->b) {
                        shm->b -= amount;
                        printf("Balance withdrawn successfully\n");
                        printf("Updated balance after withdrawal:\n%d\n", shm->b);
                    } else {
                        printf("Withdrawal failed, Invalid amount\n");
                    }
                } else if (strcmp(shm->sel, "c") == 0) {
                    printf("Current balance: %d\n", shm->b);
                }
            } else {
                printf("Invalid selection\n");
            }

            write(pipefd[1], "Thank you for using\n", sizeof("Thank you for using\n"));

            if (strcmp(shm->sel, "a") == 0 || strcmp(shm->sel, "w") == 0 || strcmp(shm->sel, "c") == 0) {
                break;
            }
        }

        close(pipefd[1]); 
        shmdt(shm);       
        shmctl(shmid, IPC_RMID, NULL);
        exit(0);
    }

    return 0;
}

