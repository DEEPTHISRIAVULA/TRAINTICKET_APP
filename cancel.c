#include "train.h"
void CancelTicket()
{
        int train_no,seat_no;
        printf("Enter Train Number\n");
        scanf("%d",&train_no);
        printf("Enter Seat Number to cancel \n");
        scanf("%d",&seat_no);

        PASSENGER *passenger_head=SyncPassenger();
        PASSENGER *prev=NULL,*cur=passenger_head;
        int found=0;
        while(cur)
        {
                if(cur->train_no==train_no && cur->seat_no ==seat_no)
                {
                        found=1;
                        if(prev==NULL)
                        {
                                passenger_head=cur->link;
                        }
                        else
                                prev->link=cur->link;
                                free(cur);
                                break;
                }
                 prev=cur;
                cur=cur->link;
        }
        if(!found)
        {
                printf("Ticket not found\n");
                return;
        }

        SEAT *seat_head=SyncSeat();
        SEAT *sp=seat_head;
        while(sp)
        {
                if(sp->train_no==train_no)
                {
                        sp->total_seats++;
                        if(sp->waiting_list>0)
                        {
                                sp->waiting_list--;
                                sp->current_booking_seat_number++;
                        }
                        break;
                }
                sp=sp->link;
        }
        SavePassenger(passenger_head);
        SaveSeat(seat_head);
        printf("Ticket Cancelled Successfully\n");
}

         
