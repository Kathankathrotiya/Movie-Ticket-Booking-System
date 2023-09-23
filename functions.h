
// Registration Function
void Registration()
{
    char Name[100], EmailId[100], MobileNo[10];

    int capcha1;
    srand(time(0));
    int capcha = rand();

    printf("\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t\t+                                                                  +\n");
    printf("\t\t\t\t\t+                       Movie Ticket Booking                       +\n");
    printf("\t\t\t\t\t+                                                                  +\n");
    printf("\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("\t\t\t\t\t--------------------------------------------------------------------\n");
    printf("\t\t\t\t\t                            Registration                            \n");
    printf("\t\t\t\t\t--------------------------------------------------------------------\n\n");
    fflush(stdin);
    printf("\t\t\t\t\tEnter Your Name       :: ");
    gets(Name);

    int temp = 0, i;
    do
    {
        printf("\n\t\t\t\t\tEnter Your E-mail Id  :: ");
        gets(EmailId);
        for (i = 0; EmailId[i] != '\0'; i++)
        {
            if (EmailId[i] == '@')
            {
                temp = 1;
                break;
            }
            else if (EmailId[i] != '@')
            {
                temp = 0;
            }
        }
        if (temp == 0)
        {
            printf("\n\t\t\t\t\tPlease Enter Valid Email Id ! ! !\n");
        }
    } while (temp == 0);

    do
    {
        printf("\n\t\t\t\t\tEnter Your Mobile No  :: ");
        gets(MobileNo);
        if (strlen(MobileNo) != 10)
        {
            printf("\n\t\t\t\t\tPlease Enter 10 Digit Number ! ! !\n");
        }
    } while (strlen(MobileNo) != 10);

    printf("\n\t\t\t\t\tEnter Your Password   :: ");
    char P;
    i = 0;
    while ((P = _getch()) != 13)
    {
        Password[i] = P;
        i++;
        printf("*");
    }
    Password[i] = '\0';

    printf("\n\n\t\t\t\t\t              Capcha  :: %d\n", capcha);
    printf("\n\t\t\t\t\tEnter Capcha Here     :: ");
    scanf("%d", &capcha1);
    printf("\n");

    if (capcha == capcha1)
    {
        printf("\t\t\t\t\tYour Registration Is Successful . . . \n\n");
    }
    else
    {
        printf("\t\t\t\t\tYour Registration Is Unsuccessful ! ! !\n");
        printf("\t\t\t\t\tTry Again ! ! !\n\n");
        Registration();
    }
}

// Choice Function
int Choice()
{
    int choice;
    printf("\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t\t+                                                                  +\n");
    printf("\t\t\t\t\t+                       Movie Ticket Booking                       +\n");
    printf("\t\t\t\t\t+                                                                  +\n");
    printf("\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("\t\t\t\t\tPress 1    List Of Movies\n\n");
    printf("\t\t\t\t\tPress 2    Book Your Ticket\n\n");
    printf("\t\t\t\t\tPress 3    Cancel Booked Ticket\n\n");
    printf("\t\t\t\t\tPress 4    Exit System\n\n");

    printf("\t\t\t\t\tEnter Your Choice :: ");
    scanf("%d", &choice);

    return choice;
}

void ticket(char ticketName[][50], int seatNo[], int billNo[1000], int quantityTicket, int movieCode, char movieDate[15], char movieTime[15], char movieZone)
{
    char movieName[50];
    switch (movieCode)
    {
    case 1:
        strcpy(movieName, dataMovie[0]);
        break;
    case 2:
        strcpy(movieName, dataMovie[1]);
        break;
    case 3:
        strcpy(movieName, dataMovie[2]);
        break;
    }

    int p1;
    switch (movieZone)
    {
    case 'g':
    case 'G':
        p1 = 180;
        break;

    case 's':
    case 'S':
        p1 = 150;
        break;

    case 'p':
    case 'P':
        p1 = 200;
        break;
    }

    for (int i = 0; i < count; i++)
    {
        if (seatNo[i] != 0)
        {
            printf("\n\n");
            printf("\t\t\t\t\t--------------------THEATER BOOKING TICKET------------------\n");
            printf("\t\t\t\t\t============================================================\n");
            printf("\t\t\t\t\t Bill Number : %d \t\t\tShow Name : %s\n", billNo[i], movieName);
            printf("\t\t\t\t\t Customer  : %s\n", ticketName[i + 1]);
            printf("\t\t\t\t\t\t\t                              Date      : %s\n", movieDate);
            printf("\t\t\t\t\t                                              Time      : %s:00 PM\n", movieTime);
            printf("\t\t\t\t\t                                              Zone      : %s\n", zone);
            printf("\t\t\t\t\t                                              Seat No. : %d  \n", seatNo[i]);
            printf("\t\t\t\t\t                                              Price . : %d  \n\n", p1);
            printf("\t\t\t\t\t============================================================\n");
        }
    }
}

// Payment Function
int Payment(int quantityTicket, char movieZone)
{
    // Copying Zone name to print in Ticket
    switch (movieZone)
    {
    case 'g':
    case 'G':
        strcpy(zone, dataZone[0]);
        price = quantityTicket * 180;
        break;

    case 's':
    case 'S':
        strcpy(zone, dataZone[1]);
        price = quantityTicket * 150;
        break;

    case 'p':
    case 'P':
        strcpy(zone, dataZone[2]);
        price = quantityTicket * 200;
        break;
    }

    // Verfying Card Details
    int a = 0, amount;
    char pass[100], x[50], y[50];

    printf("\n\n\t\t\t\t\t--------------------------------------------------------------------\n");
    printf("\t\t\t\t\t                            Card Details                            \n");
    printf("\t\t\t\t\t--------------------------------------------------------------------\n\n");
    fflush(stdin);
    printf("\t\t\t\t\tAmount To Be Paid :: %d\n", price);

    int s;
    do
    {
        printf("\t\t\t\t\tEnter Your Card Number :: ");
        gets(x);
        s = strlen(x);
        if (s != 16)
        {
            printf("\t\t\t\t\tEnter 16 Digit Number Please ! ! !\n");
        }
    } while (s != 16);

    printf("\t\t\t\t\tEnter Expiry Date :: ");
    gets(y);

    do
    {
        printf("\t\t\t\t\tEnter Amount :: ");
        scanf("%d", &amount);

        if (price != amount)
        {
            printf("\t\t\t\t\tPlease Enter Correct Amount As Mentioned Above ! ! !\n");
        }
    } while (price != amount);

    fflush(stdin);
    printf("\t\t\t\t\tEnter Your Login Password :: ");
    char P;
    int i = 0;
    while ((P = _getch()) != 13)
    {
        pass[i] = P;
        i++;
        printf("*");
    }
    pass[i] = '\0';

    if (strcmp(pass, Password) == 0)
    {
        a = 121;
    }

    return a;
}

// Booking Function
void Booking(void)
{
    int movieCode;
    char movieTime[15], movieDate[15], movieZone;

    printf("\n\n\t\t\t\t\t--------------------------------------------------------------------\n");
    printf("\t\t\t\t\t                            Ticket Booking                         \n");
    printf("\t\t\t\t\t--------------------------------------------------------------------\n\n");
    fflush(stdin);

    // Asking of Movie and Show Details
    printf("\t\t\t\t\t\tMovie-Code  \t     Movie Name\n\n");
    printf("\t\t\t\t\t\t    1       \t          83    \n\n");
    printf("\t\t\t\t\t\t    2       \t   Pushpa : The Rise\n\n");
    printf("\t\t\t\t\t\t    3       \tSpider Man : No Way Home\n\n");
    printf("\t\t\t\t\tEnter Movie Code You Want To See :: ");
    scanf("%d", &movieCode);

    if (movieCode != 1 && movieCode != 2 && movieCode != 3)
    {
        do
        {
            printf("\n\t\t\t\t\tEnter Valid Movie Code ! ! !\n");
            printf("\t\t\t\t\tEnter Movie Code You Want To See :: ");
            scanf("%d", &movieCode);
        } while (movieCode != 1 && movieCode != 2 && movieCode != 3);
    }

    fflush(stdin);

    int f = 0;

    do
    {

        fflush(stdin);
        printf("\n\n\t\t\t\t\t--------------------------------------------------------------------\n");
        printf("\t\t\t\t\t                            Select Zone                         \n");
        printf("\t\t\t\t\t--------------------------------------------------------------------\n");
        printf("\n\n\t\t\t\t\tEnter S For Silver\n");
        printf("\n\t\t\t\t\tEnter G For Gold\n");
        printf("\n\t\t\t\t\tEnter P For Platinum\n");
        printf("\n\t\t\t\t\tEnter Zone :: ");
        scanf("%c", &movieZone);

        if (movieZone == 'G' || movieZone == 'S' || movieZone == 'P' || movieZone == 'g' || movieZone == 's' || movieZone == 'p')
        {
            f = 1;
        }
        else
        {
            printf("\n\t\t\t\t\tOnly Three Zones are Available ! ! !\n\n");
            f = 0;
        }

    } while (f == 0);

    fflush(stdin);

    printf("\n\t\t\t\t\tEnter Date Of Movie :: ");
    gets(movieDate);

    int o;
    printf("\n\n\t\t\t\t\t--------------------------------------------------------------------\n");
    printf("\t\t\t\t\t                            Select Time                         \n");
    printf("\t\t\t\t\t--------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tEnter 3 For 3:00 PM\n\n");
    printf("\t\t\t\t\tEnter 6 For 6:00 PM\n\n");
    printf("\t\t\t\t\tEnter 9 For 9:00 PM\n\n");
    int p = 0;
    do
    {
        printf("\t\t\t\t\tEnter Time Of Movie :: ");
        gets(movieTime);
        for (o = 0; movieTime[o] != '\0'; o++)
        {
            if (movieTime[o] == '9' || movieTime[o] == '6' || movieTime[o] == '3')
            {
                p = 1;
                break;
            }
            else
            {
                p = 0;
            }
        }
        if (p == 0)
        {
            printf("\t\t\t\t\tPlease Enter The Choice As Given Above . . .\n\n");
        }
    } while (p == 0);

    // Printing Sitting Layout
    int i;
    printf("\n\n\t\t\t\t\t\t\t\t\tSCREEN\n\n\n");
    for (i = 1; i <= 50; i++)
    {
        printf("%15d", i);
        if (i % 10 == 0)
            printf("\n\n");
    }

    int quantityTicket;

    do
    {
        printf("\t\t\t\t\tEnter Quantity Of Tickets You Want To Book :: ");
        scanf("%d", &quantityTicket);
        if (quantityTicket > 50)
        {
            printf("\t\t\t\t\tSorry ! ! !\t Max Limit is 50.\n");
        }
    } while (quantityTicket > 50);

    // Taking info of Costumer
    int j = 0;
    do
    {
        printf("\n\t\t\t\t\tEnter Name :: ");
        scanf("%s", &ticketName[count][50]);

        printf("\t\t\t\t\tEnter Seat No. :: ");
        scanf("%d", &seatNo[count]);

        for (int i = 0; i < count; i++)
        {
            if (seatNo[i] == seatNo[count])
            {
                printf("\t\t\t\t\tSeat is Already Booked ! ! !\n\t\t\t\t\tEnter Another Seat No. :: ");
                scanf("%d", &seatNo[count]);
            }
        }

        do
        {
            if (seatNo[count] > 50)
            {
                printf("\t\t\t\t\tMaximum Seat No. is 50.\n\t\t\t\t\tEnter Another Seat No. :: ");
                scanf("%d", &seatNo[count]);
            }
        } while (seatNo[count] > 50);

        billNo[count] = bookingId;
        bookingId++;
        j++;
        count = count + 1;

        printf("%d", count);

    } while (j < quantityTicket);

    fflush(stdin);

    char confirmation;
    printf("\n\t\t\t\t\tDo You Want To Confirm The Tickets ?");
    printf("\n\t\t\t\t\tEnter Y For YES\n");
    printf("\t\t\t\t\tEnter N For NO\n");
    printf("\n\t\t\t\t\tEnter Your Choice :: ");
    scanf("%c", &confirmation);

    if (confirmation == 'y' || confirmation == 'Y')
    {
        // Storing returned value in p
        int p = Payment(quantityTicket, movieZone);

        if (p == 121)
        {
            // Redirecting to function ticket
            ticket(ticketName, seatNo, billNo, quantityTicket, movieCode, movieDate, movieTime, movieZone);

            char conf;
            printf("\t\t\t\t\tDo You Want To Go To Main Menu ? ");
            printf("\n\t\t\t\t\tEnter Y For YES\n");
            printf("\t\t\t\t\tEnter N For NO\n");
            printf("\t\t\t\t\tEnter Your Choice :: ");
            scanf("%c", &conf);

            if (conf != 'y' && conf != 'Y' && conf != 'N' && conf != 'n')
            {
                do
                {
                    fflush(stdin);
                    printf("\t\t\t\t\tPlease Enter Right choice ! ! !");
                    scanf("%c", &conf);
                } while (conf != 'y' && conf != 'Y' && conf != 'N' && conf != 'n');
            }

            if (conf == 'Y' || conf == 'y')
            {
                mainmenu();
            }
        }
        else
        {
            printf("\n\t\t\t\t\tIncorrect Password ! ! !\n");
            Payment(quantityTicket, movieZone);
        }
    }
    else
    {
        mainmenu();
    }
}

// Cancel Function
void Cancel()
{
    int x, i, size;
    printf("\n\n\t\t\t\t\t--------------------------------------------------------------------\n");
    printf("\t\t\t\t\t                            Ticket Cancellation                     \n");
    printf("\t\t\t\t\t--------------------------------------------------------------------\n\n");
    fflush(stdin);
    printf("\t\t\t\t\tEnter Your Bill No. :: ");
    scanf("%d", &x);

    printf("\t\t\t\t\t%s Your Seat %d is Cancelled.", ticketName[x], seatNo[x - 1]);

    seatNo[x - 1] = 0;

    char confi;

    fflush(stdin);
    printf("\n\n\t\t\t\t\tDo you want to continue ?");
    printf("\n\t\t\t\t\tEnter Y For YES\n");
    printf("\t\t\t\t\tEnter N For NO\n");
    printf("\n\t\t\t\t\tEnter Your Choice :: ");
    scanf("%c", &confi);

    if (confi == 'y' || confi == 'Y')
        ;
    {
        mainmenu();
    }
}

// Exit Function
void Exit()
{
    exitCode = '-';
}

void mainmenu()
{
    int choice;

    do
    {
        fflush(stdin);
        choice = Choice();

        switch (choice)
        {
        case 1:
            ListOfMovies();
            break;
        case 2:
            Booking();
            break;
        case 3:
            Cancel();
            break;
        case 4:
            Exit();
            break;

        default:
            printf("\t\t\t\t\tYour Choice Is Not Available ! ! !");
            mainmenu();
            break;
        }
    } while (choice == exitCode);
}

// List Of Movies Function
void ListOfMovies()
{

    printf("\n\n\t\t\t\t\t--------------------------------------------------------------------\n");
    printf("\t\t\t\t\t                            Movie Details                           \n");
    printf("\t\t\t\t\t--------------------------------------------------------------------\n\n");
    fflush(stdin);

    printf("\t\t\t\t\t----------------------------->   83   <------------------------------\n\n");
    printf("\t\t\t\t\t\t1983 Cricket World Cup taught India to win. 14 men fought against  \n");
    printf("\t\t\t\t\tall odds. This is their Story!\n\n");
    printf("\t\t\t\t\t2 hr 43 min     --     Drama,Sport      --    U    --    24 Dec, 2021\n\n");
    printf("\t\t\t\t\t\t\tSilver      150 Rs.\n");
    printf("\t\t\t\t\t\t\tGold        180 Rs.\n");
    printf("\t\t\t\t\t\t\tPlatinum     200 Rs.\n\n");
    printf("\t\t\t\t\t---------------------->   Pushpa : The Rise   <----------------------\n\n");
    printf("\t\t\t\t\t\tBased on the smuggling of red sander trees in Seshachalam forest,  \n");
    printf("\t\t\t\t\tAndhra Pradesh, Pushpa tells the story of a lorry driver who is part \n");
    printf("\t\t\t\t\tof the illegal business.\n\n");
    printf("\t\t\t\t\t2 hr 59 min    --     Action,Thriller    --    U    --   17 Dec, 2021\n\n");
    printf("\t\t\t\t\t\t\tSilver      150 Rs.\n");
    printf("\t\t\t\t\t\t\tGold        180 Rs.\n");
    printf("\t\t\t\t\t\t\tPlatinum     200 Rs.\n\n");
    printf("\t\t\t\t\t-------------------->   Spider Man : No Way Home   <-----------------\n\n");
    printf("\t\t\t\t\t\tFor the first time in the cinematic history of Spider-Man, our     \n");
    printf("\t\t\t\t\tfriendly neighborhood hero is unmasked and no longer able to separate\n");
    printf("\t\t\t\t\this normal life from the high-stakes of being a Super Hero.          \n\n");
    printf("\t\t\t\t\t\tWhen he asks for help from Doctor Strange the stakes become even more\n");
    printf("\t\t\t\t\t dangerous, forcing him to discover what it truly means to be Spider-Man.\n\n");
    printf("\t\t\t\t\t2 hr 28 min    --     Action,Sci-Fi     --     U    --    16 Dec, 2021\n\n");
    printf("\t\t\t\t\t\t\tSilver      150 Rs.\n");
    printf("\t\t\t\t\t\t\tGold        180 Rs.\n");
    printf("\t\t\t\t\t\t\tPlatinum     200 Rs.\n\n");

    int z;
    printf("\t\t\t\t\tPress 1    To Book your ticket\n\n");
    printf("\t\t\t\t\tPress 2    To Go to Mainmenu \n\n");
    printf("\t\t\t\t\tEnter Your Choice :: ");
    scanf("%d", &z);

    if (z == 1)
    {
        return Booking();
    }
    else if (z == 2)
    {
        return mainmenu();
    }
}