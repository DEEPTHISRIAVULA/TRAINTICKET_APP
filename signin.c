#include "train.h"
void signin(void)
{
        int attempts=0;
        int found=0;
        char loginname[50],loginpw[50];
        printf("Enter login details\n");
      p:printf("Enter Username\n");
        scanf("%s",loginname);
        printf("Enter login password\n");
        scanf("%s",loginpw);
        FILE *fp;
        char name[50],password[50];
        fp=fopen("usr_logins","r");
        if(fp==NULL)
        {
                   printf("usr_logins file not found\n");
                   return;
        }
        while(fscanf(fp,"%s %s",name,password)==2)
        {
          if(strcmp(name,loginname)==0)
           {
             if(strcmp(password,loginpw)==0)
              {
                   found=1;
                   break;
              }
           }
        }
       fclose(fp);
       if(found)
           {
                printf("signin successfully!\n");
                printf("MENU2\n");
                menu2();
           }
       else
           {
                ++attempts;
                if(attempts<3)
                {
                  printf("Invalid login details\n");
                  printf("login again for another %d times\n",3-attempts);
                  goto p;
                }
                else
                {
                  printf("You have reached max no.of attempts,please wait for 5 mins to login again\n");
                }
           }
}
