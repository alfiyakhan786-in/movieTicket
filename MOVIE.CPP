#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

class MovieBooking
{
    struct Movie
    {
        int id;
        char name[40];
        char time[15];
        int price;
        int seats;
    };

    struct Booking
    {
        int ticketNo;
        char customerName[40];
        char movieName[40];
        int seats;
        int amount;
    };

public:

    Movie movies[15];
    Booking bookings[50];
    int bookingCount;

    MovieBooking()
    {
        bookingCount = 0;

        Movie temp[15] =
        {
            {1, "Avengers", "10:00 AM", 200, 50},
            {2, "Avatar", "11:00 AM", 180, 50},
            {3, "Spider-Man", "12:00 PM", 150, 50},
            {4, "RRR", "01:00 PM", 220, 50},
            {5, "Titanic", "02:00 PM", 200, 50},
            {6, "Chichore", "03:00 PM", 180, 50},
            {7, "3 Idiots", "04:00 PM", 150, 50},
            {8, "Bahubali", "05:00 PM", 200, 50},
            {9, "Pushpa", "06:00 PM", 180, 50},
            {10, "Animal", "07:00 PM", 220, 50},
            {11, "War", "08:00 PM", 200, 50},
            {12, "Singham", "09:00 PM", 170, 50},
            {13, "Drishyam", "10:00 AM", 150, 50},
            {14, "Brahmastra", "11:00 AM", 190, 50},
            {15, "Kabir Singh", "12:00 PM", 180, 50}
        };

        for (int i = 0; i < 15; i++)
            movies[i] = temp[i];
    }

    void saveBookings()
    {
        FILE *file;

        file = fopen("bookings.txt", "w");

        if (file == NULL)
        {
            cout << "\nFile cannot be opened!";
            return;
        }

        for (int i = 0; i < bookingCount; i++)
        {
            fprintf(file, "Ticket No: %d\n", bookings[i].ticketNo);
            fprintf(file, "Customer: %s\n", bookings[i].customerName);
            fprintf(file, "Movie: %s\n", bookings[i].movieName);
            fprintf(file, "Seats: %d\n", bookings[i].seats);
            fprintf(file, "Amount: Rs.%d\n", bookings[i].amount);
            fprintf(file, "----------------------------------------\n");
        }

        fclose(file);
    }

    void displayMovies()
    {
        clrscr();

        cout << "\n==============================================================";
        cout << "\n *** NOW SHOWING ***";
        cout << "\n==============================================================";

        cout << "\nID MOVIE NAME SLOT PRICE VACANT";
        cout << "\n--------------------------------------------------------------";

        for (int i = 0; i < 15; i++)
        {
            cout << "\n";
            cout << movies[i].id << " ";
            cout << movies[i].name;
            cout << "\t\t";
            cout << movies[i].time;
            cout << "\t";
            cout << "Rs." << movies[i].price;
            cout << "\t";
            cout << movies[i].seats;
        }

        cout << "\n--------------------------------------------------------------";

        getch();
    }

    void searchMovie()
    {
        char searchName[40];
        int found = 0;

        clrscr();

        cout << "\n================================================";
        cout << "\n *** SEARCH MOVIE ***";
        cout << "\n================================================";

        cin.get();

        cout << "\n\nEnter Movie Name: ";
        cin.getline(searchName, 40);

        for (int i = 0; i < 15; i++)
        {
            if (strcmpi(movies[i].name, searchName) == 0)
            {
                cout << "\n\n+------------------------------------------+";
                cout << "\n| MOVIE FOUND!                             |";
                cout << "\n+------------------------------------------+";

                cout << "\n Movie Name : " << movies[i].name;
                cout << "\n Show Slot : " << movies[i].time;
                cout << "\n Ticket Price : Rs." << movies[i].price;
                cout << "\n Vacant Seats : " << movies[i].seats;

                cout << "\n+------------------------------------------+";

                found = 1;
                break;
            }
        }

        if (found == 0)
            cout << "\n\n*** MOVIE NOT FOUND! ***";

        getch();
    }

    void bookTicket()
    {
        char movieName[40];
        int seats;
        int found = 0;
        int paymentChoice;
        char upi[30];
        char cardLast4[5];
        int pin;
        int i;

        clrscr();

        cout << "\n================================================";
        cout << "\n *** BOOK TICKET ***";
        cout << "\n================================================";

        if (bookingCount < 50)
        {
            cin.get();

            cout << "\n\nEnter Customer Name: ";
            cin.getline(bookings[bookingCount].customerName, 40);

            cout << "Enter Movie Name: ";
            cin.getline(movieName, 40);

            for (i = 0; i < 15; i++)
            {
                if (strcmpi(movies[i].name, movieName) == 0)
                {
                    found = 1;

                    cout << "\nMovie Found!";
                    cout << "\nShow Slot : " << movies[i].time;
                    cout << "\nTicket Price : Rs." << movies[i].price;
                    cout << "\nVacant Seats : " << movies[i].seats;

                    cout << "\n\nEnter Number of Seats: ";
                    cin >> seats;

                    if (seats > 0 && seats <= movies[i].seats)
                    {
                        bookings[bookingCount].ticketNo =
                        bookingCount + 1;

                        strcpy(bookings[bookingCount].movieName,
                        movies[i].name);

                        bookings[bookingCount].seats = seats;

                        bookings[bookingCount].amount =
                        seats * movies[i].price;

                        movies[i].seats =
                        movies[i].seats - seats;

                        cout << "\n\nTotal Amount : Rs."
                        << bookings[bookingCount].amount;

                        cout << "\n\n==============================================";
                        cout << "\n          *** PAYMENT METHOD ***";
                        cout << "\n==============================================";

                        cout << "\n\n[1] Cash";
                        cout << "\n[2] UPI";
                        cout << "\n[3] Card";

                        cout << "\n\nEnter Payment Method: ";
                        cin >> paymentChoice;

                        if (paymentChoice == 1)
                        {
                            cout << "\nPayment Mode : Cash";

                            cout << "\nPlease pay Rs."
                            << bookings[bookingCount].amount
                            << " at the counter.";

                            cout << "\nPayment will be confirmed at the counter.";
                        }

                        else if (paymentChoice == 2)
                        {
                            cout << "\n\nEnter UPI ID: ";
                            cin >> upi;

                            cout << "Enter UPI PIN: ";

                            pin = 0;

                            getch();

                            cout << "\n";
                            cout << "\nPayment Mode : UPI";
                            cout << "\nUPI ID : " << upi;
                            cout << "\nPayment Successful!";
                        }

                        else if (paymentChoice == 3)
                        {
                            cout << "\n\nEnter Last 4 Digits of Card: ";
                            cin >> cardLast4;

                            cout << "Enter Card PIN: ";

                            pin = 0;

                            getch();

                            cout << "\n";
                            cout << "\nPayment Mode : Card";
                            cout << "\nCard ending with : " << cardLast4;
                            cout << "\nPayment Successful!";
                        }

                        else
                        {
                            cout << "\nInvalid Payment Method!";
                        }

                        cout << "\n\n************************************************";
                        cout << "\n* TICKET BOOKED SUCCESSFULLY!                 *";
                        cout << "\n************************************************";

                        cout << "\n\n *** TICKET ***";
                        cout << "\n-----------------------------------------------";

                        cout << "\n Ticket No. : "
                        << bookings[bookingCount].ticketNo;

                        cout << "\n Customer : "
                        << bookings[bookingCount].customerName;

                        cout << "\n Movie : "
                        << bookings[bookingCount].movieName;

                        cout << "\n Show Slot : "
                        << movies[i].time;

                        cout << "\n Seats : "
                        << bookings[bookingCount].seats;

                        cout << "\n Total Amount : Rs."
                        << bookings[bookingCount].amount;

                        cout << "\n-----------------------------------------------";
                        cout << "\n ENJOY YOUR MOVIE!";

                        bookingCount++;

                        saveBookings();
                    }
                    else
                    {
                        cout << "\n\n*** NOT ENOUGH SEATS AVAILABLE! ***";
                    }

                    break;
                }
            }

            if (found == 0)
                cout << "\n\n*** MOVIE NOT FOUND! ***";
        }
        else
        {
            cout << "\n\n*** BOOKING LIMIT REACHED! ***";
        }

        getch();
    }

    void viewAllBookings()
    {
        clrscr();

        cout << "\n================================================";
        cout << "\n *** ALL BOOKINGS ***";
        cout << "\n================================================";

        if (bookingCount == 0)
        {
            cout << "\n\nNo bookings available!";
        }
        else
        {
            cout << "\n\n";
            cout << "TICKET CUSTOMER MOVIE";
            cout << "\n------------------------------------------------";

            for (int i = 0; i < bookingCount; i++)
            {
                cout << "\n"
                << bookings[i].ticketNo
                << "\t"
                << bookings[i].customerName
                << "\t"
                << bookings[i].movieName;

                cout << "\nSeats : "
                << bookings[i].seats;

                cout << " Amount : Rs."
                << bookings[i].amount;

                cout << "\n------------------------------------------------";
            }
        }

        getch();
    }

    void searchBooking()
    {
        char movieName[40];
        int found = 0;

        clrscr();

        cout << "\n================================================";
        cout << "\n *** SEARCH BOOKING ***";
        cout << "\n================================================";

        cin.get();

        cout << "\n\nEnter Movie Name: ";
        cin.getline(movieName, 40);

        for (int i = 0; i < bookingCount; i++)
        {
            if (strcmpi(bookings[i].movieName, movieName) == 0)
            {
                cout << "\n\n+------------------------------------------+";
                cout << "\n| BOOKING FOUND!                           |";
                cout << "\n+------------------------------------------+";

                cout << "\n Ticket No : " << bookings[i].ticketNo;
                cout << "\n Customer : " << bookings[i].customerName;
                cout << "\n Movie : " << bookings[i].movieName;
                cout << "\n Seats : " << bookings[i].seats;
                cout << "\n Amount : Rs." << bookings[i].amount;

                cout << "\n+------------------------------------------+";

                found = 1;
            }
        }

        if (found == 0)
            cout << "\n\n*** NO BOOKING FOUND FOR THIS MOVIE! ***";

        getch();
    }

    /* ==================================================
       OPTION 6 - UPDATE BOOKING
       ================================================== */

    void updateBooking()
    {
        int ticket;
        int newSeats;
        int found = 0;

        clrscr();

        cout << "\n================================================";
        cout << "\n *** UPDATE BOOKING ***";
        cout << "\n================================================";

        cout << "\n\nEnter Ticket No: ";
        cin >> ticket;

        for (int i = 0; i < bookingCount; i++)
        {
            if (bookings[i].ticketNo == ticket)
            {
                cout << "\n\nCustomer Name : "
                << bookings[i].customerName;

                cout << "\nMovie Name : "
                << bookings[i].movieName;

                cout << "\nCurrent Seats : "
                << bookings[i].seats;

                cout << "\nCurrent Amount : Rs."
                << bookings[i].amount;

                cout << "\n\nEnter New Number of Seats: ";
                cin >> newSeats;

                if (newSeats > 0)
                {
                    /* CHANGED j TO k */

                    for (int k = 0; k < 15; k++)
                    {
                        if (strcmpi(movies[k].name,
                        bookings[i].movieName) == 0)
                        {
                            movies[k].seats =
                            movies[k].seats + bookings[i].seats;

                            if (newSeats <= movies[k].seats)
                            {
                                movies[k].seats =
                                movies[k].seats - newSeats;

                                bookings[i].seats = newSeats;

                                bookings[i].amount =
                                newSeats * movies[k].price;

                                saveBookings();

                                cout << "\n\n*** BOOKING UPDATED SUCCESSFULLY! ***";
                            }
                            else
                            {
                                movies[k].seats =
                                movies[k].seats - bookings[i].seats;

                                cout << "\n\n*** NOT ENOUGH SEATS AVAILABLE! ***";
                            }

                            found = 1;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "\n\n*** INVALID NUMBER OF SEATS! ***";
                    found = 1;
                }

                break;
            }
        }

        if (found == 0)
            cout << "\n\n*** BOOKING NOT FOUND! ***";

        getch();
    }

    /* ==================================================
       OPTION 7 - CANCEL TICKET
       ================================================== */

    void cancelTicket()
    {
        int ticket;
        int found = 0;

        clrscr();

        cout << "\n================================================";
        cout << "\n *** CANCEL TICKET ***";
        cout << "\n================================================";

        cout << "\n\nEnter Ticket No: ";
        cin >> ticket;

        for (int i = 0; i < bookingCount; i++)
        {
            if (bookings[i].ticketNo == ticket)
            {
                cout << "\n\nCustomer Name : "
                << bookings[i].customerName;

                cout << "\nMovie Name : "
                << bookings[i].movieName;

                cout << "\nSeats : "
                << bookings[i].seats;

                /* Return seats to movie */

                /* CHANGED j TO k */

                for (int k = 0; k < 15; k++)
                {
                    if (strcmpi(movies[k].name,
                    bookings[i].movieName) == 0)
                    {
                        movies[k].seats =
                        movies[k].seats + bookings[i].seats;

                        break;
                    }
                }

                /* Remove booking */

                /* CHANGED j TO m */

                for (int m = i; m < bookingCount - 1; m++)
                {
                    bookings[m] = bookings[m + 1];
                }

                bookingCount--;

                saveBookings();

                cout << "\n\n************************************************";
                cout << "\n* TICKET CANCELLED SUCCESSFULLY!              *";
                cout << "\n************************************************";

                found = 1;
                break;
            }
        }

        if (found == 0)
            cout << "\n\n*** BOOKING NOT FOUND! ***";

        getch();
    }

    /* ==================================================
       OPTION 8 - AVAILABLE SEATS
       ================================================== */

    void displayAvailableSeats()
    {
        clrscr();

        cout << "\n==============================================================";
        cout << "\n *** AVAILABLE SEATS ***";
        cout << "\n==============================================================";

        cout << "\nID MOVIE NAME SLOT VACANT SEATS";
        cout << "\n--------------------------------------------------------------";

        for (int i = 0; i < 15; i++)
        {
            cout << "\n"
            << movies[i].id
            << " "
            << movies[i].name
            << "\t\t"
            << movies[i].time
            << "\t"
            << movies[i].seats;
        }

        cout << "\n--------------------------------------------------------------";

        getch();
    }

    void calculateAmount()
    {
        char movieName[40];
        int seats;
        int found = 0;

        clrscr();

        cout << "\n================================================";
        cout << "\n *** CALCULATE AMOUNT ***";
        cout << "\n================================================";

        cin.get();

        cout << "\n\nEnter Movie Name: ";
        cin.getline(movieName, 40);

        for (int i = 0; i < 15; i++)
        {
            if (strcmpi(movies[i].name, movieName) == 0)
            {
                found = 1;

                cout << "\nMovie Name : " << movies[i].name;
                cout << "\nTicket Price : Rs." << movies[i].price;

                cout << "\nEnter Number of Seats: ";
                cin >> seats;

                if (seats > 0 && seats <= movies[i].seats)
                {
                    cout << "\nTotal Amount = Rs."
                    << seats * movies[i].price;
                }
                else
                {
                    cout << "\n*** INVALID NUMBER OF SEATS! ***";
                }

                break;
            }
        }

        if (found == 0)
            cout << "\n\n*** MOVIE NOT FOUND! ***";

        getch();
    }

    /* ==================================================
       OPTION 9 - TOTAL BOOKINGS
       ================================================== */

    void totalBookings()
    {
        clrscr();

        cout << "\n================================================";
        cout << "\n *** TOTAL BOOKINGS ***";
        cout << "\n================================================";

        cout << "\n\nTotal Number of Bookings : "
        << bookingCount;

        getch();
    }
};


int main()
{
    MovieBooking obj;

    int choice;

    do
    {
        clrscr();

        cout << "\n";

        cout << "*******************************************************\n";
        cout << "* MOVIE TICKET BOOKING SYSTEM                         *\n";
        cout << "*                                                     *\n";
        cout << "* WELCOME TO CINEMA                                   *\n";
        cout << "*******************************************************\n";

        cout << "\n MAIN MENU";
        cout << "\n-------------------------------------------------------";

        cout << "\n [1] Display All Movies";
        cout << "\n [2] Search Movie";
        cout << "\n [3] Book Ticket";
        cout << "\n [4] View All Bookings";
        cout << "\n [5] Search Booking";
        cout << "\n [6] Update Booking";
        cout << "\n [7] Cancel Ticket";
        cout << "\n [8] Display Available Seats";
        cout << "\n [9] Total Bookings";
        cout << "\n [10] Exit";

        cout << "\n-------------------------------------------------------";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
            obj.displayMovies();

        else if (choice == 2)
            obj.searchMovie();

        else if (choice == 3)
            obj.bookTicket();

        else if (choice == 4)
            obj.viewAllBookings();

        else if (choice == 5)
            obj.searchBooking();

        else if (choice == 6)
            obj.updateBooking();

        else if (choice == 7)
            obj.cancelTicket();

        else if (choice == 8)
            obj.displayAvailableSeats();

        else if (choice == 9)
            obj.totalBookings();

        else if (choice == 10)
        {
            clrscr();

            cout << "\n\n****************************************";
            cout << "\n* Thank you for using the system!     *";
            cout << "\n****************************************";

            getch();
        }

        else
        {
            cout << "\n\n*** INVALID CHOICE! ***";
            getch();
        }

    } while (choice != 10);

    return 0;
}
