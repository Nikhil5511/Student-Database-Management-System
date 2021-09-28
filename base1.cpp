#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

//global variables
string gen_reg,fname,middle_name,lname,gender,mother_name,class_name,phone_num,Religion,category;

// Functions
void fixbar();
void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

int main()
{
    short int choice;
    int x;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\t\tStudent Database.";
    cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t> ";
    cin >> choice;

    switch(choice)
    {
       
        case 1:
            fixbar();  
            addContact(); 
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4:
            self_exit();
            break;
        default:
            cout << "\n\n\tInvalid Input !";
            cout << "\n\tPress Any Key To Continue..";
            getch();
            main();
    }
    return 0;
}

void self_exit()
{
    system("cls");
    cout << "\n\n\n\t\tThank You For Using !";
    exit(1);
}

void help()
{
    cout << "This displays help";
}
void fixbar(){
    ofstream myFile;
    myFile.open("new1.csv");
    myFile <<"Reg. Number "<<","<<"First Name  "<<", "<<"Middle Name  "<<", "<<"Last Name  "
    <<", "<<"Gender "<<", "<<" Mothers Name:"<<", "<<"Standard "<<", "<<"Religion "<<","
    <<"category"<<","<<"Phone number "<<endl; 
}

void addContact()
{
    ofstream phone("new1.csv", ios::app);
    system("cls");
    cout << "Enter The General Register Number : ";
    cin >> gen_reg;
    cout << "Enter First Name : ";
    cin >> fname;
    cout << "Enter Middle Name : ";
    cin >> middle_name;
    cout << "Enter Last Name : ";
    cin >> lname;
    cout << "Enter the Gender: ";
    cin >> gender;
    cout << "Enter the Mothers Name: ";
    cin >> mother_name;
    cout << "Enter the Standard : ";
    cin >> class_name;
    cout << "Enter the Religion: ";
    cin >> Religion;
    cout << "Enter the category: ";
    cin >> category;
    cout << "Enter 10-Digit Phone Number : ";
    cin >> phone_num;

    if(check_digits(phone_num) == true)
    {
        if(check_numbers(phone_num) == true)
        {
            if(phone.is_open())
            {
                cout<<endl;
                phone<< gen_reg << "," << fname << "," << middle_name << "," << lname << ","<< gender<< "," 
                <<mother_name<< "," <<class_name  << "," <<Religion << "," <<category<< "," << phone_num<< endl;
                cout << "\n\tContact Saved Successfully !";
            }
            else
            {
                cout << "\n\tError Opening File !";
            }
        }
        else
        {
            cout << "\n\tA Phone Number Must Contain Numbers Only !";
        }
    }
    else
    {
        cout << "\n\tA Phone Number Must COntain 10 Digits.";
    }
    phone.close();
}

void searchContact()
{
    bool found = false;
    ifstream myfile("new1.csv");
    string keyword;
    cout << "\n\tEnter Name To Search : ";
    cin >> keyword;
    while(myfile >>gen_reg >> fname>> middle_name >> lname >> gender>> mother_name >>class_name >>phone_num>>Religion>>category)
    {
        if(keyword == fname|| keyword==middle_name  || keyword == lname || keyword==class_name)
        {
            system("cls");
            cout << "Contact details.."<<endl;
            cout << "General Register Number : " << gen_reg<<endl;
            cout << "First Name : " << fname<<endl;
            cout << "Middle Name : " << middle_name<<endl;
            cout << "Last Name : " << lname<<endl;
            cout << "Gender : " << gender<<endl;
            cout << "Mothers Name : " << mother_name<<endl;
            cout << "Class Name : " << class_name<<endl;
            cout << "Phone Number : " << phone_num<<endl;
            cout << "Religion : " << Religion<<endl;
            cout << "Category : " << category<<endl;

            
            
            

            found = true;
            break;
        }
    }
    if(found == false)
    cout << "\n\tNo Such Contact Found";
}

bool check_digits(string x)
{
    if(x.length() == 10)
    return true;
    else
    return false;
}

bool check_numbers(string x)
{
    bool check = true;

    for(int i=0; i < x.length(); i++)
    {
        if(!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            check = false;
            break;
        }
    }

    if(check == true)
    return true;
    if(check == false)
    return false;
}
