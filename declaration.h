#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void Registration(void);
void ticket(char ticketName[][50], int seatNo[], int billNo[1000], int quantityTicket, int movieCode, char movieDate[15], char movieTime[10], char movieZone);
int Choice(void);
int Payment(int, char);
void Cancel(void);
void Booking(void);
void Exit(void);
void mainmenu(void);
void ListOfMovies(void);

char Password[100];
char zone[15];
char dataMovie[3][50] = {"83", "Spider Man : No Way Home", "Pushpa : The Rise"};
int price;
char dataZone[3][15] = {"Gold", "Silver", "Platinum"};
int bookingId = 1, billNo[1000];
int seatNo[50];
char ticketName[50][50];
char exitCode = '0';
int count = 0;
