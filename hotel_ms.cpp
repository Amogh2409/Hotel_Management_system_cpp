#include <iostream>  
#include <string.h>  
#include <conio.h>  
#define max 100  
using namespace std;  
// Class Customer  
class Customer  
{  
public:  
    char name[100];  
    char address[100];  
    char phone[12];  
    char from_date[20];  
    char to_date[20];  
    float payment_advance;  
    int booking_id;  
};  
class Room  
{  
public:  
    char type;  
    char stype;  
    char ac;  
    int roomNumber;  
    int rent;  
    int status;  
  
    class Customer cust;  
    class Room addRoom(int);  
    void searchRoom(int);  
  
    void displayRoom(Room);  
};  
  
// Global Declarations  
class Room rooms[max];  
int count = 0;  
  
Room Room::addRoom(int rno)  
{  
    class Room room;  
    room.roomNumber = rno;  
    cout << "\t\tType AC/Non-AC (A/N) : ";  
    cin >> room.ac;  
    cout << "\t\tType Comfort (S/N) : ";  
    cin >> room.type;  
    cout << "\t\tType Size (B/S) : ";  
    cin >> room.stype;  
    cout << "\t\tDaily Rent : ";  
    cin >> room.rent;  
    room.status = 0;  
  
    cout << "\t\t Room Added Successfully!";  
    getch();  
    return room;  
}  
void Room::searchRoom(int rno)  
{  
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].roomNumber == rno)  
        {  
            found = 1;  
            break;  
        }  
    }  
    if (found == 1)  
    {  
        cout << "Room Details\t\t"<<endl;  
        if (rooms[i].status == 1)  
        {  
            cout << "\t\tRoom is Reserved";  
        }  
        else  
        {  
            cout << "\t\tRoom is available"<<endl;  
        }  
        displayRoom(rooms[i]);  
        getch();  
    }  
    else  
    {  
        cout << "\t\tRoom not found";  
        getch();  
    }  
}  
  
void Room::displayRoom(Room tempRoom)  
{  
    cout << "\t\tRoom Number: \t" << tempRoom.roomNumber<<endl;  
    cout << "\t\tType AC/Non-AC (A/N) " << tempRoom.ac<<endl;  
    cout << "\t\tType Comfort (S/N) " << tempRoom.type<<endl;  
    cout << "\t\tType Size (B/S) " << tempRoom.stype<<endl;  
    cout << "\t\tRent: " << tempRoom.rent<<endl;  
}  
  
// hotel management class  
class HotelMgnt : protected Room  
{  
public:  
    void checkIn();  
    void getAvailRoom();  
    void searchCustomer(char *);  
    void checkOut(int);  
    void guestSummaryReport();  
};  
  
void HotelMgnt::guestSummaryReport()  
{  
  
    if (count == 0)  
    {  
        cout << "\t\t No Guest in Hotel !!";  
    }  
    for (int i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 1)  
        {  
            cout << "\t\t Customer First Name : " << rooms[i].cust.name<<endl;  
            cout << "\t\t Room Number : " << rooms[i].roomNumber<<endl;  
            cout << "\t\t Address (only city) : " << rooms[i].cust.address<<endl;  
            cout << "\t\t Phone : " << rooms[i].cust.phone<<endl;  
            cout << "\t\t---------------------------------------";  
        }  
    }  
  
    getch();  
}  
  
// hotel management reservation of room  
void HotelMgnt::checkIn()  
{  
    int i, found = 0, rno;  
  
    class Room room;  
    cout << "\t\tEnter Room number : ";  
    cin >> rno;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].roomNumber == rno)  
        {  
            found = 1;  
            break;  
        }  
    }  
    if (found == 1)  
    {  
        if (rooms[i].status == 1)  
        {  
            cout << "\t\tRoom is already Booked";  
            getch();  
            return;  
        }  
  
        cout << "\t\tEnter booking id: ";  
        cin >> rooms[i].cust.booking_id;  
  
        cout << "\t\tEnter Customer Name (First Name): ";  
        cin >> rooms[i].cust.name;  
  
        cout << "\t\tEnter Address (only city): ";  
        cin >> rooms[i].cust.address;  
  
        cout << "\t\tEnter Phone: ";  
        cin >> rooms[i].cust.phone;  
  
        cout << "\t\tEnter From Date: ";  
        cin >> rooms[i].cust.from_date;  
  
        cout << "\t\tEnter to  Date: ";  
        cin >> rooms[i].cust.to_date;  
  
        cout << "\t\tEnter Advance Payment: ";  
        cin >> rooms[i].cust.payment_advance;  
  
        rooms[i].status = 1;  
  
        cout << "\t\t Customer Checked-in Successfully..";  
        getch();  
    }  
}  
  
// hotel management shows available rooms  
void HotelMgnt::getAvailRoom()  
{  
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 0)  
        {  
            displayRoom(rooms[i]);  
            cout << "\t\tPress enter for next room";  
            found = 1;  
            getch();  
        }  
    }  
    if (found == 0)  
    {  
        cout << "\t\tAll rooms are reserved";  
        getch();  
    }  
}  
  
// hotel management shows all persons that have booked room  
void HotelMgnt::searchCustomer(char *pname)  
{  
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 1 && stricmp(rooms[i].cust.name, pname) == 0)  
        {  
            cout << "\t\tCustomer Name: " << rooms[i].cust.name<<endl;  
            cout << "\t\tRoom Number: " << rooms[i].roomNumber<<endl;  
  
            cout << "\t\tPress enter for next record";  
            found = 1;  
            getch();  
        }  
    }  
    if (found == 0)  
    {  
        cout << "\t\tPerson not found.";  
        getch();  
    }  
}  
  
// hotel managemt generates the bill of the expenses  
void HotelMgnt::checkOut(int roomNum)  
{  
    int i, found = 0, days, rno;  
    float billAmount = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum)  
        {  
            // rno = rooms[i].roomNumber;  
            found = 1;  
            // getch();  
            break;  
        }  
    }  
    if (found == 1)  
    {  
        cout << "\t\tEnter Number of Days:\t";  
        cin >> days;  
        billAmount = days * rooms[i].rent;  
  
        cout << "\t\t\t######## CheckOut Details ########\t\t"<<endl;  
        cout << "\t\tCustomer Name : " << rooms[i].cust.name<<endl;  
        cout << "\t\tRoom Number : " << rooms[i].roomNumber<<endl;  
        cout << "\t\tAddress : " << rooms[i].cust.address<<endl;  
        cout << "\t\tPhone : " << rooms[i].cust.phone<<endl;  
        cout << "\t\tTotal Amount Due : " << billAmount << " /"<<endl;  
        cout << "\t\tAdvance Paid: " << rooms[i].cust.payment_advance << " /"<<endl;  
        cout << "\t\t*** Total Payable: " << billAmount - rooms[i].cust.payment_advance << "/ only"<<endl;  
  
        rooms[i].status = 0;  
    }  
    getch();  
}  
  
// managing rooms (adding and searching available rooms)  
void manageRooms()  
{  
    class Room room;  
    int opt, rno, i, flag = 0;  
    char ch;  
    do  
    {  
        system("cls");  
        cout << "\t\t\t Manage room" << endl;
        cout << "\t\t ------------------------------------" << endl;
        cout << "\t\t 1. Add room" << endl;
        cout << "\t\t 2. Search room" << endl;
        cout << "\t\t 3. Back to main menu" << endl;
        cout << "\t\t ------------------------------------" << endl;
        cout << "\t\t Enter your option: ";  
        cin >> opt;  
  
        // switch statement  
        switch (opt)  
        {  
        case 1:  
            cout << "\t\tEnter Room Number: ";  
            cin >> rno;  
            i = 0;  
            for (i = 0; i < count; i++)  
            {  
                if (rooms[i].roomNumber == rno)  
                {  
                    flag = 1;  
                }  
            }  
            if (flag == 1)  
            {  
                cout << "\t\tRoom Number is Present.\t\tPlease enter unique Number";  
                flag = 0;  
                getch();  
            }  
            else  
            {  
                rooms[count] = room.addRoom(rno);  
                count++;  
            }  
            break;  
        case 2:  
            cout << "\t\tEnter room number: ";  
            cin >> rno;  
            room.searchRoom(rno);  
            break;  
        case 3:  
            // nothing to do  
            break;  
        default:  
            cout << "\t\tPlease Enter correct option";  
            break;  
        }  
    } while (opt != 3);  
}  

int main()  
{  
    class HotelMgnt hm;  
    int i, j, opt, rno;  
    char ch;  
    char pname[100];  
  
    system("cls");  
  
    do  
    {  
        system("cls");  
        cout << "\t\t\t Hotel Management System" << endl;
        cout << "\t\t ------------------------------------" << endl;
        cout << "\t\t 1. Manage room" << endl;
        cout << "\t\t 2. Check-In room" << endl;
        cout << "\t\t 3. Available room" << endl;
        cout << "\t\t 4. Search Customer" << endl;
        cout << "\t\t 5. Check-Out room" << endl;
        cout << "\t\t 6. Guest summary" << endl;
        cout << "\t\t 7. Exit" << endl;
        cout << "\t\t ------------------------------------" << endl;
        cout << "\t\t Enter your choice: ";  
        cin >> opt;  
        switch (opt)  
        {  
        case 1:  
            manageRooms();  
            break;  
        case 2:  
            if (count == 0)  
            {  
                cout << "\t\t ------------------------------------" << endl;
                cout << "\t\t No room available" << endl;
                cout << "\t\t ------------------------------------" << endl;
                cout << "\t\t Press add rooms First" << endl;
                getch();  
            }  
            else  
                hm.checkIn();  
            break;  
        case 3:  
            if (count == 0)  
            {  
                cout << "\t\tRooms data is not available...Please add the rooms first.";
                getch();  
            }  
            else  
                hm.getAvailRoom();  
            break;  
        case 4:  
            if (count == 0)  
            {  
               cout << "\t\tRooms data is not available...Please add the rooms first.";
                getch();  
            }  
            else  
            {  
                cout << "Enter Customer Name: ";  
                cin >> pname;  
                hm.searchCustomer(pname);  
            }  
            break;  
        case 5:  
            if (count == 0)  
            {  
                cout << "\t\tRooms are not available.\t\tPlease add the rooms first.";  
                getch();  
            }  
            else  
            {  
                cout << "Enter Room Number : ";  
                cin >> rno;  
                hm.checkOut(rno);  
            }  
            break;  
        case 6:  
            hm.guestSummaryReport();  
            break;  
        case 7:  
            cout << "\t\tTHANK YOU! FOR USING SOFTWARE";  
            break;  
        default:  
            cout << "\t\tPlease Enter correct option";  
            break;  
        }  
    } while (opt != 7);  
  
    getch();  
}  