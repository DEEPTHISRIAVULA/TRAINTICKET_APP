#ifndef TRAIN_H
#define TRAIN_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct passenger
{
        char name[50];
        int age;
        char gender;
        int seat_no;
        int train_no;
        //char train_name[50];
        char date[10];
        struct passenger *link;
}PASSENGER;
typedef struct TrainInfo
{
        int train_no;
        char train_name[50];
        char source[30];
        char destination[30];
        int no_of_seats;
        struct TrainInfo *link;
}TRAIN;
typedef struct SeatInfo
{
        int train_no;
        char train_name[50];
        int total_seats;
        int waiting_list;
        int current_booking_seat_number;
        struct SeatInfo *link;
}SEAT;
/*Train*/
void  AddDefaultTrains();
TRAIN *SyncTrain();
void SaveTrain(TRAIN *);
void DisplayTrains();

/*SEAT*/
SEAT *SyncSeat();
void SaveSeat(SEAT *);

/*PASSENGER*/
PASSENGER *SyncPassenger();
void SavePassenger(PASSENGER *);
void ReserveTicket();
void CancelTicket();
void BookingDetails();

int AdminLogin();


void Signup(void);
void signin(void);
void menu2();

#endif
