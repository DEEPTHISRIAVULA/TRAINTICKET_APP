#include "train.h"
int main()
{
    int ch,s;
    printf("\n----------------------------------------------------\n");
    printf("\n            TRAIN TICKET BOOKING APP                \n");
    printf("\n----------------------------------------------------\n");
    AddDefaultTrains();
menu1: printf("\n-------------------MENU1--------------------------\n");
          printf("1.Sign-up(to create new login)\n");
          printf("2.Sign-in(to login existing users)\n");
          scanf("%d",&ch);
          if(ch==1)
          {
             printf("sign-up\n");
             Signup();
             goto menu1;
          }
          else if(ch==2)
          {
             printf("signin\n");
             signin();
          }
          else
          goto menu1;
}
