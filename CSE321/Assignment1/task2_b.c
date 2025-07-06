#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp1,*fp2;
    fp1= fopen("input.txt","r");
    fp2= fopen("output.txt","w");
    int n;
    char line[200];
    

    while(!feof(fp1)){   
        fgets(line, sizeof(line), fp1);
        
    }

   
    char * token = strtok(line, " ");
   
   while( token != NULL ) {
      for(int i=0; line[i]!='\0'; i++){
      fprintf( fp2 ,"%s ", token );
      
      token = strtok(NULL, " ");
      }
   }
  
    
    
    
    

    fclose(fp1);
    fclose(fp2);
    return 0;


}
