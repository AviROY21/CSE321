#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

#define MSG_SIZE 64


struct msg {
    long int type;
    char txt[MSG_SIZE];
};

int main() {
    pid_t pid;
    int msgid;
    struct msg message;

    
    key_t key = ftok("msgq", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    
    printf("Please enter the workspace name: ");
    fflush(stdout);
    char workspace[20];
    scanf("%s", workspace);

    if (strcmp(workspace, "cse321") != 0) {
        printf("Invalid workspace name\n");
        exit(0);
    }

    
    pid = fork();
    if (pid == 0) {  
        strcpy(message.txt, workspace);
        message.type = 1;
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Workspace name sent to otp generator from log in: %s\n", message.txt);

        
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("OTP generator received workspace name from log in: %s\n", message.txt);

        
        sprintf(message.txt, "%d", getpid());
        message.type = 2;
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("OTP sent to log in from OTP generator: %s\n", message.txt);

        
        message.type = 3;
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("OTP sent to mail from OTP generator: %s\n", message.txt);

        exit(0);
    } else {  
        
        msgrcv(msgid, &message, sizeof(message), 2, 0);
        printf("Log in received OTP from OTP generator: %s\n", message.txt);

        
        msgrcv(msgid, &message, sizeof(message), 3, 0);
        printf("Log in received OTP from mail: %s\n", message.txt);

        
        message.type = 4;
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("OTP sent to log in from mail: %s\n", message.txt);

        
        if (strcmp(message.txt, message.txt) == 0)
            printf("OTP Verified\n");
        else
            printf("OTP Incorrect\n");

        
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}

//20301269
