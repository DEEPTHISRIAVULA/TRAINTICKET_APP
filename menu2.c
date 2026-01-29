#include "train.h"
void menu2(void)
{
  char choice;
  DisplayTrains();
  while(1)
  {
     printf("\n--------MENU2--------\n");
m2:  printf("R/r:To reserve ticket\n");
     printf("C/c:To cancel ticket\n");
     printf("B/b:Booking details\n");
     printf("Q/q:Quit from app\n");
     printf("Enter your choice\n");
     scanf(" %c",&choice);
     if(choice=='R'||choice=='r')
     {
          printf("Ticket reservation..\n");
          ReserveTicket();
     }
     else if(choice=='C'||choice=='c')
     {
          printf("Ticket Cancellation..\n");
          CancelTicket();
     }
     else if(choice=='B'||choice=='b')
     {
          printf("Ticket Booking Details\n");
          BookingDetails();
     }
     else if(choice=='Q'||choice=='q')
     {
          printf("EXIT\n");
          exit(0);
     }
     else
     {
            printf("Invalid choice! Try again!!\n");

     }
  }
}
