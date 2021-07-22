/*
RAILWAY MANAGEMENT SYSTEM IN C++..........

Project Made By :
1)Gajendra Pal
2)Gaurav Kumar Sharma
3)Karan Dua

*/



// Header Files
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
char f[10] = "f";
char s[10] = "s";
int addr, ad, flag, f1, d, m, i, amt;
float tamt;

// created a map to store the user data and sort it according to their Unique Id
map<string, vector<string>> mapp;

// Class Login to take and display user data
class login
{
private:
  string age;
  string address;
  string aadhar_num;
  string phone_num;

public:
  static int unique_ID;
  char id[100];
  char pass[100];
  char password[10];
  void getid()
  {
    unique_ID++;
    cout << "\nEnter your id:";
    cin >> id;
    cout << "Enter the Password: ";
    cin >> password;
    strcpy(pass, password);
    cout << "Enter your address: ";
    fflush(stdin);
    getline(cin, address);
    cout << "Enter your age: ";
    fflush(stdin);
    getline(cin, age);
    cout << "Enter You Aadhar Number: ";
    fflush(stdin);
    getline(cin, aadhar_num);
    while (aadhar_num.length() != 12)
    {
      cout << "INVALID AADHAR NUMBER..NOTE THE AADHAR NUMBER MUST BE ATLEAST OF 12 DIGITS.......PLEASE RENTER." << endl;
      fflush(stdin);
      getline(cin, aadhar_num);
    }
    cout << "Enter Your Phone Number: ";
    fflush(stdin);
    getline(cin, phone_num);
    while (phone_num.length() != 10)
    {
      cout << "INVALID MOBILE NUMBER..NOTE THE MOBILE  NUMBER MUST BE ATLEAST OF 10 DIGITS.......PLEASE RENTER" << endl;
      fflush(stdin);
      getline(cin, phone_num);
    }
  }

  void pushtomap()
  {
    mapp[id] = {pass, age, aadhar_num, phone_num, address};
  }

  void displayfrommap()
  {
    vector<string> v{"Pass", "Age", "Aadhar_Number", "Phone_Number", "Address"};

    cout << "Fetching From Database" << endl;
    cout << setw(31) << setfill('.') << "Please Wait!" << endl;

    //This is Basically a Delay Loop
    for (long long int i = 0; i < 1000000000; i++)
    {
    }
    cout << "Data Fetched........Clustering Data And Showing it on Console.........." << endl;
    for (long long int i = 0; i < 100000000; i++)
    {
    }
    for (auto &&i : mapp)
    {
      int k = 0;

      cout << setw(71) << setfill('-') << "" << endl;
      cout << "User Name: ";
      cout << i.first << endl;
      for (auto &&j : i.second)
      {
        cout << "\t\t|"
             << v[k] << ": "
             << j << "|\n";

        k++;
      }
      cout << setw(71) << setfill('-') << "" << endl;
      cout << endl;
      cout << endl;
    }
  }
};

// Static Data Member to store Unique Id of each user...You can consider this ID as a token which is generated when a user registers on our server
int login::unique_ID;

// Train Details stored here by admin
class Detail
{
public:
  int tno;
  char tname[100];
  char bp[100];
  char dest[100];

  int c1, c1fare;
  int c2, c2fare;
  int d, m, y;
  // Getting Detauks of Trains From Admin
  void getDetail()
  {
    cout << endl;
    cout << setw(19) << setfill('-') << "Add New details" << setw(4) << setfill('-') << "" << endl;
    cout << "Train no: ";
    cin >> tno;
    cout << "Train Name: ";
    cin >> tname;
    cout << "Boarding point: ";
    cin >> bp;
    cout << "Destination pt: ";
    cin >> dest;
    cout << "No of seats in first class & fare per ticket: ";
    cin >> c1 >> c1fare;
    cout << "No of seats in second class & fare per ticket: ";
    cin >> c2 >> c2fare;
    cout << "Date of travel\n";
    cout << "Day: ";
    cin >> d;
    cout << "Month: ";
    cin >> m;
    cout << "Year: ";
    cin >> y;
  }
  // Displays Train Detail
  void displaydetail()
  {
    cout << "\n|Train No."
         << "\t"
         << "|Train Name"
         << "\t"
         << "|Boarding pt."
         << "\t"
         << "|Destination pt."
         << "\t";
    cout << "|F-Class"
         << "\t"
         << "|F-Class Fare"
         << "\t"
         << "|S-Class"
         << "\t"
         << "|S-Class Fare"
         << "\t";
    cout << "|Day"
         << "-"
         << "Month"
         << "-"
         << "Year"
         << "\n";

    cout << "|" << tno << "\t\t"
         << "|" << tname << "\t\t"
         << "|" << bp << "\t\t"
         << "|" << dest << "\t\t\t";
    cout << "|" << c1 << "\t\t"
         << "|" << c1fare << "\t\t"
         << "|" << c2 << "\t\t"
         << "|" << c2fare << "\t\t";
    cout << "|" << d << "-" << m << "-" << y << "\n";
  }
};

// Ticket Reservation
class reser : public Detail
{
public:
  int pnr;
  char pname[10][100];
  int age[20];
  char clas[10];
  int nosr;
  int i;
  int con;

  float amc;

  // Getting Ticket reservation data from user
  void getresdet()
  {
    cout << "Enter the details as follows\n";
    cout << "Train no:";
    cin >> tno;
    cout << "Train name:";
    cin >> tname;
    cout << "Boarding point:";
    cin >> bp;
    cout << "Destination pt:";
    cin >> dest;
    cout << "No of seats required:";
    cin >> nosr;
    for (i = 0; i < nosr; i++)
    {
      cout << "Passenger name:";
      cin >> pname[i];
      cout << "Passenger age:";
      cin >> age[i];
    }
    cout << "Enter the class f-first class s-second class:";
    cin >> clas;
    cout << "Date of travel:";
    cin >> d >> m >> y;
    // Concession Category
    cout << "Enter the concession category\n";
    cout << "1.Military\n2.Senior citizen\n";
    cout << "3.Children below 5 yrs\n4.None\n";
    cin >> con;
    cout << setw(32) << setfill('-') << "END OF GETTING DETAILS" << setw(10) << setfill('-') << "" << endl;
  }
  // Displaying reserved Ticket Information
  void displayresdet()
  {
    cout << "Pnr no: " << pnr;
    cout << "\nTrain no: " << tno;
    cout << "\nTrain name: " << tname;
    cout << "\nBoarding point: " << bp;
    cout << "\nDestination pt: " << dest;
    cout << "\nNo of seats reserved: " << nosr;
    for (i = 0; i < nosr; i++)
    {
      cout << "\nPassenger name: ";
      puts(pname[i]);
      cout << "Passenger age: " << age[i];
    }

    cout << "\nYour class: ";
    puts(clas);
    cout << "\nDate of reservation: " << d << "-" << m << "-" << y;
    cout << "\nYour concession category: " << con;
    cout << "\nYou must pay: " << amc << endl;
    cout << "*\n";
  }
};

// For cancelling Reserved Ticket
class canc
{
public:
  int pnr;
  int tno;
  char tname[100];
  char bp[10];
  char dest[100];
  char pname[10][100];
  int age[20];
  int i;
  char clas[10];
  int nosc;
  int d, m, y;
  float amr;
  // getting ticket cancellation data
  void getcancdet()
  {
    cout << "Enter the details as follows\n";
    cout << "Pnr no:";
    cin >> pnr;
    cout << "Date of cancellation:";
    cin >> d >> m >> y;
    cout << setw(34) << setfill('-') << "END OF GETTING DETAILS" << setw(12) << setfill('-') << "" << endl;
  }
  void displaycancdet()
  {
    cout << setw(30) << setfill('-') << "" << endl;
    cout << setw(30) << setfill('-') << "" << endl;
    cout << "Pnr no:" << pnr << endl;
    cout << "\nTrain no:" << tno << endl;
    cout << "\nTrain name:";
    cout << tname << endl;
    cout << "Boarding point:";
    cout << bp << endl;
    cout << "Destination pt:";
    cout << dest << endl;
    cout << "\nYour class:";
    cout << clas << endl;
    cout << "no of seats to be cancelled:" << nosc << endl;
    for (i = 0; i < nosc; i++)
    {
      cout << "Passenger name:";
      cout << pname[i] << endl;
      cout << "passenger age:" << age[i] << endl;
    }
    cout << "\nDate of cancellation:" << d << "-" << m << "-" << y << endl;
    cout << "Your Cancellation request Has been approved....Your Refund Has Been Made......" << endl;
    cout << "\nYou can collect:" << amr << "rs" << endl;
    cout << "*\n";
    cout << setw(28) << setfill('-') << "END OF CANCELLATION" << setw(9) << setfill('-') << endl;
    cout << "*\n";
  }
};
void manage();
void can();
void user();

void res();
void reserve();
void displaypassdetail();
void cancell();
void enquiry();

// Login To admin Panel
class databaseclass
{

private:
  string pass;

public:
  string password;
  // Admin Password
  databaseclass()
  {
    this->pass = "admin";
  }
  string getpassword()
  {
    cout << setw(71) << setfill('-') << "" << endl;
    cout << "Please Wait While We Connect You to Our Admin Servers";
    cout << setw(28) << setfill('.') << "" << endl;
    //This is Basically a Delay Loop
    for (long long int i = 0; i < 1000000000; i++)
    {
    }
    cout << "Successfully Connected " << endl;
    cout << setw(71) << setfill('-') << "" << endl;
    for (long long int i = 0; i < 100000000; i++)
    {
    }
    cout << "\nEnter the Admin Password: ";
    cin >> password;
    return password;
  }
  string compare_password()
  {
    return pass;
  }
  // Comparing Admin Password
  void database()
  {

    Detail a;
    fstream f;
    int ch;
    char c;

    if (this->compare_password() == this->getpassword())
    {
      char c;
      cout << endl;
      cout << "Verifying The Password.......Please Wait.................." << endl;
      //This is Basically a Delay Loop
      for (long long int i = 0; i < 1000000000; i++)
      {
      }
      cout << "Verified" << setw(11) << setfill('.') << "";
      for (long long int i = 0; i < 100000000; i++)
      {
      }
      cout << " Successful Login" << setw(14) << setfill('.') << endl;

      cout << "Welcome Back, Admin " << endl
           << endl;
      do
      {
        cout << endl;
        // Admin Functions
        cout << setw(23) << setfill('-') << " ADMINISTRATOR MENU ";
        cout << setw(3) << setfill('-') << "" << endl;
        cout << "1. Create detail Database \n";
        cout << "2. Add details \n";
        cout << "3. Display details \n";
        cout << "4. Diplay Passenger details \n";
        cout << "5. Return to Main Menu \n";
        cout << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
          f.open("t.txt", ios::out | ios::binary);
          do
          {
            a.getDetail();
            f.write((char *)&a, sizeof(a));
            cout << "\nDo you want to add one more record?\n";
            cout << "y-for Yes\nn-for No\n";
            cin >> c;
          } while (c == 'y');
          f.close();
          break;
        case 2:
          f.open("t.txt", ios::in | ios::out | ios::binary | ios::app);
          a.getDetail();
          f.write((char *)&a, sizeof(a));
          f.close();
          break;
        case 3:
          f.open("t.txt", ios::in | ios::out | ios::binary | ios::app);
          f.seekg(0);
          while (f.read((char *)&a, sizeof(a)))
          {

            a.displaydetail();
          }
          f.close();
          break;
        case 4:
          displaypassdetail();
          break;
        }
      } while (ch <= 4);
    }
    else
    {
      // Incorrect Admin Password sending back to login Route
      cout << "Enter the password correctly \n";
      cout << "You are not permitted to login this mode\n";
    }
  }
};

void reserve()
{
  int ch;
  do
  {
    // User Functionality TO reserve seat
    cout << "1.Reserve\n2.Return to the main menu\n";
    cout << "Enter your choice:";
    cin >> ch;
    cout << endl;
    switch (ch)
    {
    case 1:
      res();
      break;
    }
  } while (ch == 1);
}

// Ticket Reservation Ticket Concession Window
void res()
{
  Detail a;
  reser b;
  fstream f1, f2;
  time_t t;
  f1.open("t.txt", ios::in | ios::out | ios::binary);
  f2.open("p.txt", ios::in | ios::out | ios::binary | ios::app);
  int ch;
  b.getresdet();
  while (f1.read((char *)&a, sizeof(a)))
  {
    if (a.tno == b.tno)
    {
      if (strcmp(b.clas, f) == 0)
      {
        if (a.c1 >= b.nosr)
        {
          amt = a.c1fare;
          addr = f1.tellg();
          ad = sizeof(a.c1);
          f1.seekp(addr - (7 * ad));
          a.c1 = a.c1 - b.nosr;
          f1.write((char *)&a.c1, sizeof(a.c1));
          if (b.con == 1)
          {
            cout << "Concession category:MILITARY PERSONNEL\n";
            b.amc = b.nosr * ((amt * 50) / 100);
          }
          else if (b.con == 2)
          {
            cout << "Concession category:SENIOR CITIZEN\n";
            b.amc = b.nosr * ((amt * 60) / 100);
          }
          else if (b.con == 3)
          {
            cout << "Concession category:CHILDERN BELOW FIVE\n";
            b.amc = 0.0;
          }
          else if (b.con == 4)
          {
            cout << "You cannot get any concession\n";
            b.amc = b.nosr * amt;
          }
          srand((unsigned)time(&t));
          b.pnr = rand();
          f2.write((char *)&b, sizeof(b));
          b.displayresdet();
          cout << endl;
          cout << setw(28) << setfill('-') << "Your ticket is reserved" << setw(5) << setfill('-') << "" << endl;
        }
        else
        {
          // When the seats are full
          cout << "Sorry req seats not available\n";
        }
      }
      else if (strcmp(b.clas, s) == 0)
      {
        if (a.c2 >= b.nosr)
        {
          amt = a.c2fare;
          addr = f1.tellg();
          ad = sizeof(a.c2);
          f1.seekp(addr - (5 * ad));
          a.c2 = a.c2 - b.nosr;
          f1.write((char *)&a.c2, sizeof(a.c2));
          if (b.con == 1)
          {
            cout << "Concession category:MILITARY PRESONNEL\n";
            b.amc = b.nosr * ((amt * 50) / 100);
          }
          else if (b.con == 2)
          {
            cout << "Concession category:SENIOR CITIZEN\n";
            b.amc = b.nosr * ((amt * 60) / 100);
          }
          else if (b.con == 3)
          {
            cout << "Concession category:CHILDERN BELOW FIVE\n";
            b.amc = 0.0;
          }
          else if (b.con == 4)
          {
            cout << "You cannot get any concession\n";
            b.amc = b.nosr * amt;
          }
          f2.write((char *)&b, sizeof(b));
          b.displayresdet();
          cout << endl;
          cout << setw(28) << setfill('-') << "Your ticket is reserved" << setw(5) << setfill('-') << "" << endl;
        }
        else
        {
          cout << "*Sorry req no of seats not available\n";
        }
      }
    }
    else
    {
      flag = 0;
    }
  }
  if (flag == 0)
  {
    cout << "!\n";
  }
  f1.close();
  f2.close();
}

// Displaying reserved Passengers Data
void displaypassdetail()
{
  cout << endl;
  cout << setw(25) << setfill('-') << "Passenger Details";
  cout << setw(8) << setfill('-') << "" << endl;
  fstream f;
  reser b;
  f.open("p.txt", ios::in | ios::out | ios::binary);
  f.seekg(0);
  while (f.read((char *)&b, sizeof(b)))
  {
    b.displayresdet();
  }
  f.close();
}
void enquiry()
{
  fstream f;
  f.open("t.txt", ios::in | ios::out | ios::binary);
  Detail a;
  while (f.read((char *)&a, sizeof(a)))
  {
    a.displaydetail();
  }
}

// Function to Cancel The reserved Ticket
void cancell()
{
  int counter = 0;
  Detail a;
  reser b;
  canc c;
  fstream f1, f2, f3;
  ofstream f4;
  f1.open("t.txt", ios::in | ios::out | ios::binary);
  f2.open("p.txt", ios::in | ios::out | ios::binary);
  f3.open("cn.txt", ios::in | ios::out | ios::binary);
  f4.open("temp.txt", ios::binary | ios::out);
  cout << endl;
  cout << setw(23) << setfill('-') << "CANCELLATION MENU";
  cout << setw(6) << setfill('-') << "";
  cout << endl
       << endl;
  c.getcancdet();
  while (f2.read((char *)&b, sizeof(b)))
  {
    if (b.pnr == c.pnr)
    {
      c.tno = b.tno;
      strcpy(c.tname, b.tname);
      strcpy(c.bp, b.bp);
      strcpy(c.dest, b.dest);
      c.nosc = b.nosr;
      for (int j = 0; j < c.nosc; j++)
      {
        strcpy(c.pname[j], b.pname[j]);
        c.age[j] = b.age[j];
      }
      strcpy(c.clas, b.clas);
      if (strcmp(c.clas, f) == 0)
      {
        while (f1.read((char *)&a, sizeof(a)))
        {
          if (a.tno == c.tno)
          {
            a.c1 = a.c1 + c.nosc;
            d = a.d;
            m = a.m;
            addr = f1.tellg();
            ad = sizeof(a.c1);
            f1.seekp(addr - (7 * ad));
            f1.write((char *)&a.c1, sizeof(a.c1));
            tamt = b.amc;
            // Ticket cancellation data taken and showing to user
            if ((c.d == d) && (c.m == m))
            {
              cout << "You are cancelling at the date of departure\n";
              c.amr = tamt - ((tamt * 60) / 100);
            }
            else if (c.m == m)
            {
              cout << "You are cancelling at the month of departure\n";
              c.amr = tamt - ((tamt * 50) / 100);
            }
            else if (m > c.m)
            {
              cout << "You are cancelling one month before the date of departure\n";
              c.amr = tamt - ((tamt * 20) / 100);
            }
            else
            {
              cout << "Cancelling after the departure\n";
              cout << "Your request cannot be completed\n";
            }
            c.displaycancdet();
            counter++;
            goto h;
          }
        }
      }
      else if (strcmp(c.clas, s) == 0)
      {
        while (f1.read((char *)&a, sizeof(a)))
        {
          if (a.tno == c.tno)
          {
            a.c2 = a.c2 + c.nosc;
            d = a.d;
            m = a.m;
            addr = f1.tellg();
            ad = sizeof(a.c2);
            f1.seekp(addr - (5 * ad));
            f1.write((char *)&a.c2, sizeof(a.c2));
            tamt = b.amc;
            // Ticket cancellation data taken and showing to user

            if ((c.d == d) && (c.m == m))
            {
              cout << "You are cancelling at the date of departure\n";
              c.amr = tamt - ((tamt * 60) / 100);
            }
            else if (c.m == m)
            {
              cout << "You are cancelling at the month of departure\n";
              c.amr = tamt - ((tamt * 50) / 100);
            }
            else if (m > c.m)
            {
              cout << "You are cancelling one month before the date of departure\n";
              c.amr = tamt - ((tamt * 20) / 100);
            }
            else
            {
              cout << "Cancelling after the departure\n";
              cout << "Your request cannot be completed\n";
            }
            counter++;
            c.displaycancdet();
            goto h;
          }
        }
      }
    }
    else
    {
      f4.write((char *)&b, sizeof(b));
      flag = 1;
    }
  }
h:
  if (flag == 1 && counter == 0)
  {
    // no ticket reserved under this PNR
    cout << endl;
    cout << "Sorry But No Seat Reserved under this PNR Number" << setw(6) << setfill('.') << "";
    cout << "Please Enter the correct PNR Number again\n";
    cout << endl;
  }
  f1.close();
  f2.close();
  f3.close();
  f4.close();
  remove("p.txt");
  rename("temp.txt", "p.txt");
}
// cancellation menu
void can()
{
  int ch;
  do
  {
    cout << setw(26) << setfill('-') << "CANCELLATION MENU" << setw(9) << setfill('-') << "" << endl;
    cout << "1.Cancel\n2.Return to the main menu\n";
    cout << "Enter your choice:";
    cin >> ch;
    cout << endl;
    switch (ch)
    {
    case 1:
      cancell();
      break;
    }
  } while (ch == 1);
}
// User Login Panel adn authenticating user credentials through the authenticate middleware(Basically we are simply verifying the user credentials here......)
void user()
{
  
/*The main idea while registering is to generate a token(unique_ID) for the authentication of user (through authenticate middleware ) but
 since this authentications through middle is not supported by C++ at this low scale we are restricted to do that through simple check flags . We could also hash the user password but
 again hashing is not supported by C++ at this low scale so we went with simple storing of password and comparing them.*/
  login a;
  int ch;
  cout << endl;
  cout << setw(16) << setfill('-') << "Login User";
  cout << setw(6) << setfill('-') << "";
  cout << endl;
  char password[10];
  fstream f;
  f.open("id.txt", ios::in | ios::out | ios::binary);
  char id[100];
  cout << "Enter your ID : ";
  cin >> id;
  cout << "Enter your Password : ";
  cin >> password;
  cout << endl;
  cout << setw(71) << setfill('-') << "" << endl;
  cout << "Please wait while we confirm your identity" << setw(50) << setfill('-') << "" << endl;
  // Confirming user identity and running a delay loop
  for (long long int i = 0; i < 1000000000; i++)
  {
  }

  while (f.read((char *)&a, sizeof(a)))
  {
    if ((strcmp(a.id, id) == 0) && (strcmp(a.pass, password) == 0))
    {
      cout << "Successfully Identified....It was a succesful Login...Taking You To The Dashboard....Please Wait....................." << endl;
      for (long long int i = 0; i < 10000000; i++)
      {
      }
      do
      {

        cout << "\n1.Reserve\n2.Cancel\n3.Enquiry\n4.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
          reserve();
          break;
        case 2:
          can();
          break;
        case 3:
          enquiry();
          break;
        }
      } while (ch <= 3);
    }
    else
    {
      d = 1;
    }
  }
  // When User record not found in file/Database
  if (d == 1)
  {
    cout << "Either You are not Registered on Our Servers Or UserId Or Password Is Wrong" << setw(28) << setfill('-') << "Please Try Again" << setw(22) << setfill('-') << "" << endl;
  }
}
// User Mode and Functionalities
void user_manage()
{
  int ch;
  fstream f;
  char c;
  login a;
  cout << setw(71) << setfill('-') << "" << endl;
  cout << "Please Wait While We Connect You to Our Users Servers" << setw(28) << setfill('.') << "" << endl;
  for (long long int i = 0; i < 100000000; i++)
  {
  }
  cout << "Successfully Connected " << endl;
  cout << setw(71) << setfill('-') << "" << endl;
  for (long long int i = 0; i < 100000000; i++)
  {
  }
  cout << endl;
  cout << setw(28) << setfill('-') << "WELCOME TO THE USER MODE" << setw(4) << setfill('-') << "" << endl;
  do
  {
    cout << "\n1. Sign Up\n";
    cout << "2. Login\n";
    cout << "3. Display Details\n";
    cout << "4. Return to the main menu\n";
    cout << "Enter your choice: ";
    cin >> ch;
    cout << endl;
    switch (ch)
    {
    case 1:
      // Registering User on Database(Files)
      f.open("id.txt", ios::in | ios::out | ios::binary | ios::app);
      a.getid();
      cout << "Please Wait Sending Data to Database" << setw(11) << setfill('.') << "" << endl;
      for (long long int i = 0; i < 1000000000; i++)
      {
      }
      cout << "Data Sent Successfully..........Please wait while we save your identity" << endl;
      for (long long int i = 0; i < 1000000000; i++)
      {
      }
      cout << endl;
      cout << "Congo! You Have Been Successfully registered on our servers" << setw(50) << setfill('.') << "" << endl;
      f.write((char *)&a, sizeof(a));
      f.close();
      break;
    case 2:
      // Logging In user
      user();
      break;
    case 3:
      f.open("id.txt", ios::in | ios::out | ios::binary);
      f.seekg(0);
      // Reading user data from file and writing to map to sort it
      while (f.read((char *)&a, sizeof(a)))
      {
        a.pushtomap();
      }
      // Displaying data from map
      a.displayfrommap();

      f.close();
      break;
    }
  } while (ch <= 3);
}

int main()
{
  // Using Pointer on class to create an Object of class databaseclass in heap
  databaseclass *d = new databaseclass();
  int ch;
  cout << setw(33) << setfill('-') << " RAILWAY RESERVATION SYSTEM " << setw(4) << setfill('-') << "" << endl;
  do
  {
    // This is basically the main menu where user will be directed on opening the app
    cout << "\n MAIN MENU \n";
    cout << "1.Admin mode\n2.User mode\n3.Exit \n";
    cout << "Enter your choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      // Routing to admin mode
      d->database();
      break;
    case 2:
      // Routing to User Mode
      user_manage();
      break;
    default:
      exit(0);
    }
  }
   while (ch < 3);
  delete (d);
  return 0;
}