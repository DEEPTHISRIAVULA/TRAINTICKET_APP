a.out:main.o signup.o signin.o menu2.o reserve.o train1.o seat1.o passenger.o cancel.o book.o
        cc main.o signup.o signin.o menu2.o reserve.o train1.o seat1.o passenger.o cancel.o book.o
main.o:main.c
        cc -c main.c
signup.o:signup.c
        cc -c signup.c
signin.o:signin.c
        cc -c signin.c
menu2.o:menu2.c
        cc -c menu2.c
reserve.c:reserve.c
        cc -c reserve.c
train1.c:train1.c
        cc -c train1.c
seat1.c:seat1.c
        cc -c seat1.c
passenger.c:passenger.c
        cc -c passenger.c
cancel.c:cancel.c
        cc -c cancel.c
book.c:book.c
        cc -c book.c
