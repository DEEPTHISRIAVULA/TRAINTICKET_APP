#include "train.h"
void ReserveTicket(void)
{
       int train_no,req_seats;
       char date[15];
  
       printf("Enter train number:\n");
       scanf("%d",&train_no);
       printf("Enter date of journey\n");
       scanf("%s",date);
       printf("Enter number of seats to reserve:\n");
       scanf("%d",&req_seats);

       SEAT *seat_head=SyncSeat();
       SEAT *sp=seat_head;
       if(seat_head==NULL)
       {
               printf("Seat database is not available\n");
               return;
       }
       while(sp)
       {
               if(sp->train_no==train_no)
                       break;
               sp=sp->link;
       }
      if(sp==NULL)
       {
               printf("Invalid Train Number\n");
               return;
       }
       int booked=0;
       if(sp->total_seats >= req_seats)
       {
               booked=req_seats;
       }
       else
       {
               booked=sp->total_seats;
               sp->waiting_list += (req_seats-booked);
               printf("Only %d seats booked,rest in waiting list\n",booked);
       }
       PASSENGER *passenger_head=SyncPassenger();
       for(int i=0;i<booked;i++)
       {
               PASSENGER *nu=malloc(sizeof(PASSENGER));
               nu->train_no=train_no;
               strcpy(nu->date,date);
               printf("passenger %d details\n",i+1);
               printf("Name:\n");
               scanf("%s",nu->name);
               printf("Age:\n");
               scanf("%d",&nu->age);
               printf("Gender:\n");
               scanf(" %c",&nu->gender);
               nu->seat_no= ++sp->current_booking_seat_number;
               printf("Seat Alloted : %d\n",nu->seat_no);
               nu->link=passenger_head;
               passenger_head=nu;
       }
       sp->total_seats -= booked;
       SavePassenger(passenger_head);
       SaveSeat(seat_head);
       printf("Reservation Completed Successfully\n");
       printf("Seats Booked:%d\n",booked);
}
