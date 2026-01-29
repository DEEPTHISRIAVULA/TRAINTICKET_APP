#include "train.h"
PASSENGER *SyncPassenger()
{
        FILE *fp;
        fp=fopen("passenger_info","r");
        PASSENGER *passenger_head=NULL;
        PASSENGER *temp,*nu;
        if(!fp)
        {
                return NULL;
        }
        while(1)
        {
                nu=malloc(sizeof(PASSENGER));
                if(fscanf(fp,"%d %s %s %d %c %d",&nu->train_no,nu->date,nu->name,&nu->age,&nu->gender,&nu->seat_no)!=6)
                {
                        free(nu);
                        break;
                }
                nu->link=NULL;
                if(!passenger_head)
                {
                        passenger_head=temp=nu;
                }
                else
                {
                        temp->link=nu;
                        temp=nu;
                }
        }
        fclose(fp);
        return passenger_head;
}
void SavePassenger(PASSENGER *passenger_head)
{
        FILE *fp;
        fp=fopen("passenger_info","w");
        while(passenger_head)
        {
                fprintf(fp,"%d %s %s %d %c %d\n",passenger_head->train_no,passenger_head->date,passenger_head->name,passenger_head->age,passenger_head->gender,passenger_head->seat_no);
                 passenger_head=passenger_head->link;
        }
        fclose(fp);
}
