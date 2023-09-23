#include "declaration.h"
#include "functions.h"
// Main Function
int main()
{
    int choice;
    Registration();
    do
    {
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
            printf("\t\t\t\t\tIncorrect Choice\n");
            mainmenu();
            break;
        }
    } while (choice == exitCode);
    return 0;
}