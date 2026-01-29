#include "train.h"
void AddDefaultTrains()
{
        FILE *fp;
        fp=fopen("train_info","r");
        if(fp==NULL)
        {
          fp=fopen("train_info","w");
          fprintf(fp,"101 AExpress HYD WGL  50\n");
          fprintf(fp,"102 BExpress WGL HYD  50\n");
          fprintf(fp,"103 CExpress HYD CHN  50\n");
          fprintf(fp,"104 DExpress HYD BLR  50\n");
          fprintf(fp,"105 EExpress HYD DEL  5\n");
          fclose(fp);
        }
        else
                fclose(fp);

        fp=fopen("seat_info","r");
        if(fp==NULL)
        {
           fp=fopen("seat_info","w");
           fprintf(fp,"101 50 0 0\n");
           fprintf(fp,"102 50 0 0\n");
           fprintf(fp,"103 50 0 0\n");
           fprintf(fp,"104 50 0 0\n");
           fprintf(fp,"105 5  0 0\n");
           fclose(fp);
}
        else
                fclose(fp);
}
TRAIN *SyncTrain()
{
        FILE *fp;
        fp=fopen("train_info","r");
        TRAIN *train_head=NULL,*temp,*nu;
        if(!fp)
        {
                return NULL;
        }
        while(1)
        {
                nu=malloc(sizeof(TRAIN));
                if(fscanf(fp,"%d %s %s %s %d",&nu->train_no,nu->train_name,nu->source,nu->destination,&nu->no_of_seats)!=5)
                {
                        free(nu);
                        break;
                }
                nu->link=NULL;
                if(!train_head)
                {
                        train_head=temp=nu;
                }
               else
                {
                        temp->link=nu;
                        temp=nu;
                }
        }
        fclose(fp);
        return train_head;
}
void SaveTrain(TRAIN *train_head)
{
        FILE *fp;
        fp=fopen("train_info","w");
        while(train_head)
        {
                fprintf(fp,"%d %s %s %s %d\n",train_head->train_no,train_head->train_name,train_head->source,train_head->destination,train_head->no_of_seats);
                train_head=train_head->link;
        }
        fclose(fp);
}
void DisplayTrains()
{
        TRAIN *t=SyncTrain();
        printf("\n TrainNo Name\t Source\t Destination\t TotalSeats\n");

        while(t)
        {
                printf("%d\t %s\t %s\t %s\t\t %d\n",t->train_no,t->train_name,t->source,t->destination,t->no_of_seats);
                 t=t->link;
        }
}
