
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;

//FUNCTION PROTOTYPES
void intro();
void issue_book();
void deposit_book();
void admin_menu();
void new_student();
void display_allstudents();
void newbook();
void display_allbooks();
void admin_student();
void admin_book();
void display_specific_student(int);
void delete_specific_student(int);
void display_specific_book(int);
void delete_specific_book(int);
bool authenticate_admin();

//SETS CONCOLE TEXT COLORS
void SetColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

//MAIN FUNCTION
int main()
{
    intro();
    _getch();
    return 0;
}

//FUNCTION FOR PROGRAM INTRO
void intro()
{
    int option;
    system("CLS");
    SetColor(14);
    cout << "\n\n\t\t\t ===========================================  WELCOME TO THE LIBRARY!  ====================================================" << endl << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t= DEVELOPERS:                     =";
    cout << "\n\t\t\t\t\t\t\t\t= MUHAMMAD ZAKRIA KHAN            =";
    cout << "\n\t\t\t\t\t\t\t\t= MOMINA KIYANI                   =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    SetColor(7);
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=            MAIN MENU            =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t 1.AVAILABLE BOOKS";
    cout << "\n\n\t\t\t\t\t\t\t\t 2.ISSUE A BOOK";
    cout << "\n\n\t\t\t\t\t\t\t\t 3.DEPOSIT A BOOK";
    cout << "\n\n\t\t\t\t\t\t\t\t 4.ADMIN MENU";
    cout << "\n\n\t\t\t\t\t\t\t\t 5.EXIT";
    cout << "\n\n\t\t\t\t\t\t\t\t PLEASE CHOOSE YOUR OPTION(1-4) ";
    cin >> option;
    switch (option)
    {
    case 1:
        system("CLS");
        display_allbooks();
        break;
    case 2:
        system("CLS");
        issue_book();

        break;
    case 3:
        system("CLS");
        deposit_book();

        break;
    case 4:
        system("CLS");
        if (authenticate_admin())
        {
            system("CLS");
            admin_menu();
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\t\t\tINVALID USERNAME OR PASSWORD!" << endl;
            _getch();
            system("CLS");
            intro();
        }

        break;
    case 5:
        exit(0);
    default:
        system("CLS");
        cout << "\n\n\n\t\t\t\t\t\t\t\tINVALID OPTION! PLEASE SELECT ANOTHER OPTION.";
        _getch();
        intro();
    }
}

//FUNCTION FOR ADMINISTRATOR MENU
void admin_menu()
{
    system("CLS");
    SetColor(6);
    int option;
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=        ADMINISTRATOR MENU       =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\n\n\n\t\t\t\t\t\t\t\t1. STUDENT MENU";
    cout << "\n\n\t\t\t\t\t\t\t\t2. BOOK CORNER";
    cout << "\n\n\t\t\t\t\t\t\t\t3. BACK TO MAIN MENU";
    cout << "\n\n\t\t\t\t\t\t\t\tENTER YOUR OPTION(1-3)";
    cin >> option;
    switch (option)
    {
    case 1:
        system("CLS");
        admin_student();
        break;
    case 2:
        system("CLS");
        admin_book();
        break;
    case 3:
        system("CLS");
        intro();
        break;
    default:
        cout << "\n\n\n\t\t\t\t\t\t\t\tINVALID OPTION! PLEASE CHOOSE ANOTHER OPTION.";
        _getch();
        admin_menu();
    }
}

//FUNCTION FOR STUDENTS RELATED ACTIONS
void admin_student()
{
    SetColor(11);
    int option;
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=          STUDENT MENU           =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\n\n\n\t\t\t\t\t\t\t\t1.CREATE STUDENT RECORD";
    cout << "\n\n\t\t\t\t\t\t\t\t2.DISPLAY ALL STUDENTS RECORD";
    cout << "\n\n\t\t\t\t\t\t\t\t3.SPECIFIC STUDENT RECORD";
    cout << "\n\n\t\t\t\t\t\t\t\t4.DELETE STUDENT RECORD";
    cout << "\n\n\t\t\t\t\t\t\t\t5.BACK TO ADMIN MENU";
    cout << "\n\n\t\t\t\t\t\t\t\tENTER YOUR OPTION(1-5)";
    cin >> option;

    switch (option)
    {
    case 1:
        system("CLS");
        new_student();
        break;
    case 2:
        system("CLS");
        display_allstudents();
        break;
    case 3:
        system("CLS");
        int addnum;
        cout << "\n\n\n\t\t\t\t\t\t\t\tENTER THE ADMISSION NUMBER OF THE STUDENT: ";
        cin >> addnum;
        display_specific_student(addnum);
        break;
    case 4:
        system("CLS");
        int delnum;
        cout << "\n\n\n\t\t\t\t\t\t\t\tENTER THE ADMISSION NUMBER OF THE STUDENT: ";
        cin >> delnum;
        delete_specific_student(delnum);
        break;
    case 5:
        system("CLS");
        admin_menu();
        break;
    default:
        cout << "\n\n\n\t\t\t\t\t\t\t\tINVALID OPTION! PLEASE CHOOSE ANOTHER OPTION.";
        _getch();
        admin_menu();
    }
}

//FUNCTION FOR BOOKS RELATED ACTIONS
void admin_book()
{
    SetColor(11);
    int option;
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=           BOOK CORNER           =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t1.CREATE BOOK";
    cout << "\n\n\t\t\t\t\t\t\t\t2.DISPLAY ALL BOOKS";
    cout << "\n\n\t\t\t\t\t\t\t\t3.DISPLAY SPECIFIC BOOK";
    cout << "\n\n\t\t\t\t\t\t\t\t4.DELETE BOOK";
    cout << "\n\n\t\t\t\t\t\t\t\t5.BACK TO ADMIN MENU";
    cout << "\n\n\t\t\t\t\t\t\t\tENTER YOUR OPTION(1-5)";
    cin >> option;

    switch (option)
    {
    case 1:
        system("CLS");
        newbook();
        break;
    case 2:
        system("CLS");
        display_allbooks();
        break;
    case 3:
        system("CLS");
        int booknum;
        cout << "\n\n\n\t\t\t\t\t\t\t\tENTER THE BOOK NUMBER: ";
        cin >> booknum;
        display_specific_book(booknum);
        break;
    case 4:
        system("CLS");
        int delbook;
        cout << "\n\n\n\t\t\t\t\t\t\t\tENTER THE BOOK NUMBER: ";
        cin >> delbook;
        delete_specific_book(delbook);
        break;
    case 5:
        system("CLS");
        admin_menu();
        break;
    default:
        cout << "\n\n\n\t\t\t\t\t\t\t\tINVALID OPTION! PLEASE CHOOSE ANOTHER OPTION.";
        _getch();
        admin_menu();
    }
}

//FUNCTION  FOR ADDING A NEW STUDENT RECORD
void new_student()
{
    string name;
    string dep;
    int admin_no;
    ofstream file("newstudent.txt", ios::app);
    if (!file)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tFILE NOT FOUND!";
        _getch();
        admin_student();
    }
    int size;
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=        ADD NEW STUDENT          =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\n\n\n\t\t\t\t\t\t\t\tENTER THE NUMBER OF STUDENTS TO BE ADDED:";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "============================================================================================================================================================================" << endl;

        cout << "\n\t\t\t\t\t\t\t\tENTER STUDENT NAME: ";
        cin.ignore();
        getline(cin, name);
        cout << "\n\t\t\t\t\t\t\t\tENTER STUDENT DEPARTMENT: ";
        getline(cin, dep);
        cout << "\n\t\t\t\t\t\t\t\tENTER STUDENT ADMISSION NO. ";
        cin >> admin_no;
        cout << "============================================================================================================================================================================" << endl;

        file << name << endl << dep << endl << admin_no << endl;
        //system("CLS");
    }
    file.close();
    system("CLS");
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=  NEW STUDENT ADDED SUCCESFULLY! =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    _getch();
    admin_menu();
}

//FUNCTION  FOR DISPLAYING ALL THE STUDENTS RECORD STORED
void display_allstudents()
{
    ifstream infile("newstudent.txt");
    if (!infile) {
        cout << "\n\n\n\t\t\t\t\t\t\t\tERROR OPENING FILE!";
        _getch();
        admin_student();
    }

    string name;
    string dep;
    int admin_num;
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=      DISPLAYING ALL STUDENTS    =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    while (infile >> name >> dep >> admin_num)
    {
        cout << "============================================================================================================================================================================" << endl;
        cout << "\n\t\t\t\t\t\t\t\t==>STUDENT NAME: " << name << endl;
        cout << "\n\t\t\t\t\t\t\t\t==>STUDENT DEPARTMENT: " << dep << endl;
        cout << "\n\t\t\t\t\t\t\t\t==>STUDENT ADMISSION NO: " << admin_num << endl;
        cout << "============================================================================================================================================================================" << endl;

    }
    infile.close();
    _getch();
    admin_menu();
}

//FUNCTION  FOR DISPLAYING A SPECIFIC STUDENT RECORD 
void display_specific_student(int admin_num)
{
    ifstream infile("newstudent.txt");
    if (!infile) {
        cout << "\n\n\n\t\t\t\t\t\t\t\tERROR OPENING FILE!";
        _getch();
        admin_student();
    }

    string name;
    string dep;
    int admin_no;
    bool found = false;

    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=      DISPLAYING STUDENT RECORD  =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;

    while (infile >> name >> dep >> admin_no) {
        if (admin_no == admin_num)
        {
            cout << "============================================================================================================================================================================" << endl;
            cout << "\n\t\t\t\t\t\t\t\t==>STUDENT NAME: " << name << endl;
            cout << "\n\t\t\t\t\t\t\t\t==>STUDENT DEPARTMENT: " << dep << endl;
            cout << "\n\t\t\t\t\t\t\t\t==>STUDENT ADMISSION NO: " << admin_no << endl;
            cout << "============================================================================================================================================================================" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n\n\t\t\t\t\t\t\t\tSTUDENT RECORD NOT FOUND!";
    }

    infile.close();
    _getch();
    system("CLS");
    admin_student();
}

//FUNCTION FOR DELETING A SPECIFIC STUDENT RECORD
void delete_specific_student(int admin_num)
{
    ifstream infile("newstudent.txt");
    ofstream temp("temp.txt");

    if (!infile || !temp) {
        cout << "\n\n\n\t\t\t\t\t\t\t\tERROR OPENING FILE!";
        _getch();
        admin_student();
    }

    string name;
    string dep;
    int admin_no;
    bool found = false;

    while (infile >> name >> dep >> admin_no) {
        if (admin_no == admin_num) {
            found = true;
        }
        else {
            temp << name << endl << dep << endl << admin_no << endl;
        }
    }

    infile.close();
    temp.close();

    remove("newstudent.txt");
    rename("temp.txt", "newstudent.txt");

    if (found) {
        cout << "\n\n\t\t\t\t\t\t\t\tSTUDENT RECORD DELETED SUCCESSFULLY!";
    }
    else {
        cout << "\n\n\t\t\t\t\t\t\t\tSTUDENT RECORD NOT FOUND!";
    }

    _getch();
    system("cls");
    admin_student();
}

//FUNCTION FOR ADDING A NEW BOOK
void newbook()
{
    string name;
    string author;
    int book_id;
    ofstream file("newbook.txt", ios::app);
    if (!file)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tFILE NOT FOUND!";
        _getch();
        admin_book();
    }
    int size;
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=          ADD NEW BOOK           =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\n\n\n\t\t\t\t\t\t\t\tENTER THE NUMBER OF BOOKS TO BE ADDED:";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "============================================================================================================================================================================" << endl;
        cout << "\n\t\t\t\t\t\t\t\tENTER BOOK NAME: ";
        cin.ignore();
        getline(cin, name);
        cout << "\n\t\t\t\t\t\t\t\tENTER AUTHOR NAME: ";
        getline(cin, author);
        cout << "\n\t\t\t\t\t\t\t\tENTER BOOK ID. ";
        cin >> book_id;
        cout << "============================================================================================================================================================================" << endl;

        file << name << endl << author << endl << book_id << endl;

    }
    file.close();
    system("CLS");
    cout << "\n\n\n\t\t\t\t\t\t\t\tNEW BOOK RECORD ADDED SUCCESSFULLY!";
    _getch();
    admin_menu();
}

//FUNCTION FOR DISPLAYING ALL BOOKS RECORD STORED
void display_allbooks()
{
    ifstream infile("newbook.txt");
    if (!infile) {
        cout << "\n\n\n\t\t\t\t\t\t\t\tERROR OPENING FILE!";
        _getch();
        admin_book();
    }

    string name;
    string author;
    int book_id;
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=       DISPLAYING ALL BOOKS      =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    while (infile >> name >> author >> book_id)
    {
        cout << "============================================================================================================================================================================" << endl;
        cout << "\n\t\t\t\t\t\t\t\t==>BOOK NAME: " << name << endl;
        cout << "\n\t\t\t\t\t\t\t\t==>AUTHOR NAME: " << author << endl;
        cout << "\n\t\t\t\t\t\t\t\t==>BOOK ID: " << book_id << endl;
        cout << "============================================================================================================================================================================" << endl;

    }
    infile.close();
    _getch();
    admin_menu();
}

//FUNCTION FOR DISPLAYING A SPECIFIC BOOK RECORD
void display_specific_book(int booknum)
{
    ifstream infile("newbook.txt");
    if (!infile) {
        cout << "\n\n\n\t\t\t\t\t\t\t\tERROR OPENING FILE!";
        _getch();
        admin_book();
    }

    string name;
    string author;
    int book_id;
    bool found = false;

    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=      DISPLAYING BOOK RECORD     =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;

    while (infile >> name >> author >> book_id) {
        if (book_id == booknum) {
            cout << "============================================================================================================================================================================" << endl;
            cout << "\n\t\t\t\t\t\t\t\t==>BOOK NAME: " << name << endl;
            cout << "\n\t\t\t\t\t\t\t\t==>AUTHOR NAME: " << author << endl;
            cout << "\n\t\t\t\t\t\t\t\t==>BOOK ID: " << book_id << endl;
            cout << "============================================================================================================================================================================" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n\n\t\t\t\t\t\t\t\tBOOK RECORD NOT FOUND!";
    }

    infile.close();
    _getch();
    system("CLS");
    admin_book();
}

//FUNCTION FOR DELETING A SPECIFIC BOOK RECORD
void delete_specific_book(int booknum)
{
    ifstream infile("newbook.txt");
    ofstream temp("temp.txt");

    if (!infile || !temp) {
        cout << "\n\n\n\t\t\t\t\t\t\t\tERROR OPENING FILE!";
        _getch();
        admin_book();
    }

    string name;
    string author;
    int book_id;
    bool found = false;

    while (infile >> name >> author >> book_id) {
        if (book_id == booknum) {
            found = true;
        }
        else
        {
            temp << name << endl << author << endl << book_id << endl;
        }
    }

    infile.close();
    temp.close();

    remove("newbook.txt");
    rename("temp.txt", "newbook.txt");

    if (found) {
        cout << "\n\n\t\t\t\t\t\t\t\tBOOK RECORD DELETED SUCCESSFULLY!";
    }
    else {
        cout << "\n\n\t\t\t\t\t\t\t\tBOOK RECORD NOT FOUND!";
    }

    _getch();
    system("CLS");
    admin_book();
}

//FUNCTION FOR ISSUING A BOOK
void issue_book()
{
    ifstream infile("newbook.txt");
    ofstream outfile("issuedbooks.txt", ios::app);
    ofstream temp("temp.txt");

    if (!infile || !outfile || !temp) {
        cout << "\n\n\t\t\t\t\t\t\t\tERROR OPENING FILE!";
        _getch();
        intro();
    }

    string name;
    string author;
    int book_id;
    int entered_bookid;
    bool found = false;

    SetColor(11);
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=          ISSUE A BOOK           =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\tENTER BOOK ID TO ISSUE: ";
    cin >> entered_bookid;

    while (infile >> name >> author >> book_id) {
        if (book_id == entered_bookid) {
            outfile << name << endl << author << endl << book_id << endl;
            found = true;
        }
        else {
            temp << name << endl << author << endl << book_id << endl;
        }
    }

    infile.close();
    outfile.close();
    temp.close();

    remove("newbook.txt");
    rename("temp.txt", "newbook.txt");

    if (found) {
        cout << "\n\n\t\t\t\t\t\t\t\tBOOK ISSUED SUCCESSFULLY!";
    }
    else {
        cout << "\n\n\t\t\t\t\t\t\t\tBOOK NOT FOUND!";
    }

    _getch();
    intro();
}

//FUNCTION FOR RETURNING A BOOK
void deposit_book()
{
    ifstream infile("issuedbooks.txt");
    ofstream outfile("newbook.txt", ios::app);
    ofstream temp("temp.txt");

    if (!infile || !outfile || !temp) {
        cout << "\n\n\t\t\t\t\t\t\t\tERROR OPENING FILE!";
        _getch();
        intro();
    }

    string name;
    string author;
    int book_id;
    int entered_bookid;
    bool found = false;

    SetColor(11);
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=          DEPOSIT A BOOK         =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\tENTER BOOK ID TO DEPOSIT: ";
    cin >> entered_bookid;

    while (infile >> name >> author >> book_id) {
        if (book_id == entered_bookid) {
            outfile << name << endl << author << endl << book_id << endl;
            found = true;
        }
        else {
            temp << name << endl << author << endl << book_id << endl;
        }
    }

    infile.close();
    outfile.close();
    temp.close();

    remove("issuedbooks.txt");
    rename("temp.txt", "issuedbooks.txt");

    if (found) {
        cout << "\n\n\t\t\t\t\t\t\t\tBOOK DEPOSITED SUCCESSFULLY!";
    }
    else {
        cout << "\n\n\t\t\t\t\t\t\t\tERROR! SOMETHING WENT WRONG.";
    }

    _getch();
    intro();
}

bool authenticate_admin()
{
    const string admin_username = "admin";
    const string admin_password = "password123";
    string username;
    string password;
    cout << "\n\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t\t\t\t=      ADMINISTRATOR LOGIN        =";
    cout << "\n\t\t\t\t\t\t\t\t===================================" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\tENTER USERNAME: ";
    cin >> username;
    cout << "\n\n\t\t\t\t\t\t\t\tENTER PASSWORD:: ";
    cin >> password;
    if (username == admin_username && password == admin_password)
    {
        return true;
    }
    return false;

}
