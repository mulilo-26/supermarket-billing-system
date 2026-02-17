#include <iostream>
#include <fstream>

using namespace std;

 class shopping
    {
        private:
            int product_code;
            float price;
            float discount;
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
    m:
    int choice;
    cout <<"\t\t\t Buyer         \n";
    cout <<"_____________________\n";
    cout <<"                     \n";
    cout <<"\t\t\t 1 Buy Product  \n";
    cout <<"                     \n";
    cout <<"\t\t\t 2 Go back      \n";
    cout <<"                     \n";
    cout <<"\t\t\t Enter your choice: \n";

    cin >>choice;

    switch(choice)
    {
        case 1:
            reciept();
            break;
        case 2:
            menu();

            default;
            cout <<"Invalid choice";
    }
    goto m;
    
}

void shopping ::add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    sting n;

    cout <<"\n\n\t\t\t Add new product";
    cout <<"\n\n\t Enter the procduct code of the item(product)"
    cin >>product_code;
    cout <<"\n\n\t Name of the product: ";
    cin >>product_name;
    cout <<"\n\n\t Price of the prouct";
    cin >>price;
    cout <<"\n\n\t Discount on the product";
    cin >>discount;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data <<" " <<product <<" " <<product_name <<" " <<price <<" " <<discount "\n";
        data.close();
    } else
    {
        data >>c >>n >>p >>d;

        while(!data.oof())
        {
            if(c == pcode)
            {
                token++;
            }
            data >>c >>n >>p >>d;
        }
        data.close();

    if (token == 1)
    goto m;
        else{
            data.open("database.txt", ios::app|ios::out);
            data <<" " <<product <<" " <<product_name <<" " <<price <<" " <<discount "\n";
            data.close();
        }
}
        cout <<"\n\n\t\t Record inserted! ";
}


int main(){
   shopping();


    return 0;
}