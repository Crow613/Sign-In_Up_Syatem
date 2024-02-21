#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void login();
void registr();
void forgot();

string path = "DB/database.json";

int main()
{
    int choice;
    cout<<"****************************************"<<endl;
    cout<<"**************** WELCOME ****************"<<endl;
    cout<<"MENU: "<<endl;
    cout<<"1. Login"<<endl;
    cout<<"2. Register"<<endl;
    cout<<"3. Forgot Username or Password"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter Your Choice: "<<endl;
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1:
        login();
        break;
         case 2:
        registr();
        break;
         case 3:
        forgot();
        break;
         case 4:
        system("cls");
        cout<<"You have made a mistake, please try again.";
        main();

    }
    return 0;
}

void login()
{
        int count = 0; 
        string user,pass,u,p;
        system("cls");
        cout<<"Please Enter the following details: "<<endl;
        cout<<"Username: ";
        cin>>user;
        cout<<"Password: ";
        cin>>pass;

        ifstream input(path); 
        while(input>>u>>p)
        {
            if(u==user && p==pass)
            {
                count = 1;
                system("cls");
            }
        }
        input.close();
        if (count == 1)
        {
            cout<<"Hello "<<user<<"\n <LOGIN SUCCESSFUL>\n";
            cin.get();
            main();
        }
        else
        {
          cout<<"\nLOGIN ERROR!!!!\n Please check your username and Password."<<endl;
          main();
        }
}

void registr()
{
      string reguser,regpass,ru,pu;
      system("cls");
      cout<<"Enter the Username: "; 
      cin>>reguser;
      cout<<"Enter the Password: "; 
      cin>>regpass;

      ofstream reg(path,ios::app);
      reg<<"{"<<endl;
      reg<<" '"<<reguser<<"':"<<" '"<<regpass<<"',"<<endl;
      reg<<"}"<<endl;
      system("cls");
      cout<<"\nRegistration Successful. "<<endl;
      main();
}

void forgot()
{
     int ch;
     system("cls");
     cout<<"Forgotten? We're here to help. "<<endl;
     cout<<"1. Search your id by username"<<endl;
     cout<<"2. Main menu"<<endl;
     cin>>ch;
      switch(ch)
      {
        case 1:
          int count = 0;
          string searchuser,su,sp;
          cout<<"\n Enter your remembered username: ";
          cin>>searchuser;

          ifstream searchu(path);

          while(searchu>>su>>sp)
          {
              if(su==searchuser)
              {
                  count = 1;
              }
          }
           searchu.close();
          if (count == 1)
          {
            cout<<"\nAccount Found"<<endl; 
            cout<<"\nYour Password is: "<<sp;
            cin.get();
            system("cls");
            main();
          }
          else
          {
            cout<<"\nSorry, Your userID is not found in our Database.\n";
            cin.get();
            main();
          }
          break;
    }
}
