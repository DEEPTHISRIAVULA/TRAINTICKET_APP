#include "train.h"
SEAT *SyncSeat()
{
        FILE *fp;
        fp=fopen("seat_info","r");
        SEAT *seat_head=NULL,*temp,*nu;
        if(!fp)
                return NULL;
        while(1)
        {
                nu=malloc(sizeof(SEAT));
                if(fscanf(fp,"%d %d %d %d",&nu->train_no,&nu->total_seats,&nu->waiting_list,&nu->current_booking_seat_number)!=4)
                {
                        free(nu);
                        break;
                }
                nu->link=NULL;
                if(!seat_head)
                        seat_head=temp=nu;
                else
                {
                        temp->link=nu;
                        temp=nu;
                }
        }
                fclose(fp);
                return seat_head;
}
void SaveSeat(SEAT *seat_head)
{
        FILE *fp;
        fp=fopen("seat_info","w");
        while(seat_head)
        {
                fprintf(fp,"%d %d %d %d\n",seat_head->train_no,seat_head->total_seats,seat_head->waiting_list,seat_head->current_booking_seat_number);
                seat_head=seat_head->link;
        }
        fclose(fp);
}
