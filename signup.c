#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "train.h"
int password_valid(char *newpw)
{
     int len,upper=0,lower=0,numeric=0,special=0;
     char ch;
     len=strlen(newpw);
     if(len<8)
     {
       return 0;
     }
    for(int i=0;i<len;i++)
    {
       ch=newpw[i];
       if(isupper(ch))
       {
          upper++;
       }
       else if(islower(ch))
       {
          lower++;
       }
       else if(isdigit(ch))
       {
          numeric++;
       }
       else
       special++;
    }
    return (upper&&lower&&numeric&&special);
}
int username_exists(char *newname)
{
  FILE *fp;
  char name[50],password[50];
  fp=fopen("usr_logins","r");
  if(fp==NULL)
  {
    printf("usr_logins file not found\n");
    return 0;
  }
  while(fscanf(fp,"%s %s",name,password)==2)
  {
    if(strcmp(name,newname)==0)
    {
      fclose(fp);
      return 1;
    }
  }
  fclose(fp);
  return 0;
}
void Signup(void)
{
    char newname[50],newpw[50];
    int attempts=0;
  p:printf("Enter NEW username: \n");
    scanf("%s",newname);
    if(username_exists(newname))
    {
        printf("Username already exists!\n");
        printf("provide another username\n");
        goto p;
        return;
    }
    while(attempts<5)
    {
       printf("Enter password: \n");
       scanf("%s",newpw);
       if(password_valid(newpw))
          {
             FILE *fp;
             fp=fopen("usr_logins","a");
             if(fp==NULL)
             {
               printf("file not found\n");
               return;
             }
             fprintf(fp,"%s %s\n",newname,newpw);
             fclose(fp);
             printf("Signup successfully!\n");
             return;
          }
          else
          {
             attempts++;
             printf("Invalid Password!\n");
             printf("PASSWORD must contain: \n");
             printf(" -Minimum 8 characters long\n");
             printf(" -atleast one Uppercase\n -lowercase\n -numeric and special\n");
             printf("Attempts left :%d\n",5-attempts);
          }
     }
    printf("TIME OUT!!-signUP AGAIN\n");
}
