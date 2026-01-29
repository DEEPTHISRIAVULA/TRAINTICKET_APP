#include "train.h"
void BookingDetails()
{
        int train_no,seat_no;
        char train_name[30];
        printf("Enter Train Number:\n");
        scanf("%d",&train_no);
        printf("Enter Seat Number:\n");
        scanf("%d",&seat_no);

        PASSENGER *p=SyncPassenger();
        int found=0;
        while(p)
        {
                if(p->train_no==train_no&&p->seat_no==seat_no)
                {
                        found=1;
                        break;
                }
                p=p->link;
        }
        if(!found)
        {
                printf("Booking not found\n");
                return;
        }
        TRAIN *t=SyncTrain();
        while(t)
        {
                if(t->train_no == train_no)
                {
                        strcpy(train_name,t->train_name);
                        break;
                }
                t=t->link;
        }

        printf("\n---------------Booking Details-------------------\n");
        printf("Train Number : %d\n",p->train_no);
        printf("Train Name   : %s\n",train_name);
        printf("journey Date : %s\n",p->date);
        printf("Name         : %s\n",p->name);
        printf("Age          : %d\n",p->age);
        printf("Gender       : %c\n",p->gender);
        printf("Seat Number  : %d\n",p->seat_no);
}
