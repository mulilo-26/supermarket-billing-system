#include <iostream>
#include <fstream>

using namespace std;

 class shopping
    {
        private:
            int pcode;
            float price;
            float dis;
            string name;

        public:
            void menu();
            void administrator();
            void buyer();
            void add();
            void edit();
            void remove();
            void list();
            void receipt();
    };

    void shopping :: menu()
    {
        m:
        int choice;
        string email;
        string password;

        cout <<"\t\t\t\t__________________________________________________\n";
        cout <<"\t\t\t\t                                                  \n";
        cout <<"\t\t\t\t             Supermarket Main Menu                \n";
        cout <<"\t\t\t\t__________________________________________________\n";
        cout <<"\t\t\t\t                                                  \n";
        cout <<"\t\t\t\t|   1) Administrator                             |\n";
        cout <<"\t\t\t\t|                                                |\n";
        cout <<"\t\t\t\t|   2) Buyer                                     |\n";
        cout <<"\t\t\t\t|                                                |\n";
        cout <<"\t\t\t\t|   3) Exit                                      |\n";
        cout <<"\t\t\t\t|                                                |\n";
        cout <<"\t\t\t\t Please Slect an option                           \n";

        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout <<"\t\t\t Please Login \n";
                cout <<"\t\t\t Enter email  \n";
                cin >>email;
                cout <<"\t\t\t Enter password\n";
                cin >>password;

                if(email=="emma@email.com" && password=="emma@123")
                {
                        administrator();
                } else 
                {
                    cout <<"invalid email and password";
                }
    
            }
                break;
            case 2:
            {
                buyer();
                break;
            }
            case 3:
            {
                exit(0);
                break;
            }
            default :
            {
                cout <<"Please select from the given options";
            }
        }
    goto m;
    }

    void shopping :: administrator() 
    {
        m:
        int choice;
        cout <<"\n\n\n\t\t\t Administrator Menu";
        cout <<"\n\t\t\t |________ 1) Add Procduct ________________|";
        cout <<"\n\t\t\t |_________________________________________|";
        cout <<"\n\t\t\t |________ 2) Modify the product __________|";
        cout <<"\n\t\t\t |_________________________________________|";
        cout <<"\n\t\t\t |________ 3) Delete the product __________|";
        cout <<"\n\t\t\t |_________________________________________|";
        cout <<"\n\t\t\t |________ 4) Back to main menu ___________|";
        cout <<"\n\n\t Please enter your choice ";
        cin >>choice;

        switch(choice)
        {
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                remove();
                break;
            case 4:
                menu();
                break;
            default :
                cout <<"Invalid choice!";
        }
        goto m;
    }

void shopping :: buyer()
{
    int choice;
    cout <<"\t\t\t Buyer \n";
    cout <<"                     \n";
    cout <<"";
}

int main(){
   shopping();


    return 0;
}