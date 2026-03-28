#include <iostream>
#include <fstream>
#include <cstdlib>  // for exit()

using namespace std;

class shopping
{
    private:
        int product_code;
        float price;
        float discount;
        string name;
        string product_name;  // FIX: was missing from class declaration

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

void shopping::menu()
{
    // FIX: replaced goto with while(true)
    while (true)
    {
        int choice;
        string email;
        string password;

        cout << "\t\t\t\t__________________________________________________\n";
        cout << "\t\t\t\t                                                  \n";
        cout << "\t\t\t\t             Supermarket Main Menu                \n";
        cout << "\t\t\t\t__________________________________________________\n";
        cout << "\t\t\t\t                                                  \n";
        cout << "\t\t\t\t|   1) Administrator                             |\n";
        cout << "\t\t\t\t|                                                |\n";
        cout << "\t\t\t\t|   2) Buyer                                     |\n";
        cout << "\t\t\t\t|                                                |\n";
        cout << "\t\t\t\t|   3) Exit                                      |\n";
        cout << "\t\t\t\t|                                                |\n";
        cout << "\t\t\t\t Please Select an option                          \n";

        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                cout << "\t\t\t Please Login \n";
                cout << "\t\t\t Enter email  \n";
                cin >> email;
                cout << "\t\t\t Enter password\n";
                cin >> password;

                if (email == "emma@email.com" && password == "emma@123")
                {
                    administrator();
                }
                else
                {
                    cout << "Invalid email and password";
                }
                break;
            }
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
            default:
            {
                cout << "Please select from the given options";
            }
        }
    }
}

void shopping::administrator()
{
    // FIX: replaced goto with while(true)
    while (true)
    {
        int choice;
        cout << "\n\n\n\t\t\t Administrator Menu";
        cout << "\n\t\t\t |________ 1) Add Product __________________|";
        cout << "\n\t\t\t |_________________________________________|";
        cout << "\n\t\t\t |________ 2) Modify the product ___________|";
        cout << "\n\t\t\t |_________________________________________|";
        cout << "\n\t\t\t |________ 3) Delete the product ___________|";
        cout << "\n\t\t\t |_________________________________________|";
        cout << "\n\t\t\t |________ 4) Back to main menu ____________|";
        cout << "\n\n\t Please enter your choice ";
        cin >> choice;

        switch (choice)
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
            default:
                cout << "Invalid choice!";
        }
    }
}

void shopping::buyer()
{
    // FIX: replaced goto with while(true)
    while (true)
    {
        int choice;
        cout << "\t\t\t Buyer         \n";
        cout << "_____________________\n";
        cout << "                     \n";
        cout << "\t\t\t 1 Buy Product  \n";
        cout << "                     \n";
        cout << "\t\t\t 2 Go back      \n";
        cout << "                     \n";
        cout << "\t\t\t Enter your choice: \n";

        cin >> choice;

        switch (choice)
        {
            case 1:
                receipt();
                break;
            case 2:
                menu();
                break;  // FIX: missing break before default caused fall-through
            default:
                cout << "Invalid choice";
        }
    }
}

void shopping::add()
{
    // FIX: replaced goto with while(true)
    while (true)
    {
        fstream data;
        int c;
        int token = 0;
        float p;
        float d;
        string n;

        cout << "\n\n\t\t\t Add new product";
        cout << "\n\n\t Enter the product code of the item(product): "; // FIX: added missing semicolon
        cin >> product_code;
        cout << "\n\n\t Name of the product: ";
        cin >> product_name;  // FIX: was undeclared; now a class member
        cout << "\n\n\t Price of the product: ";
        cin >> price;
        cout << "\n\n\t Discount on the product: ";
        cin >> discount;

        data.open("database.txt", ios::in);
        if (!data)
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << product_code << " " << product_name << " " << price << " " << discount << "\n"; // FIX: added missing <<
            data.close();
        }
        else
        {
            data >> c >> n >> p >> d;

            while (!data.eof())  // FIX: was data.oof() — typo
            {
                if (c == product_code)  // FIX: was pcode — undefined variable
                {
                    token++;
                }
                data >> c >> n >> p >> d;
            }
            data.close();

            if (token == 1)
                continue;  // FIX: was goto m; replaced with continue for while loop
            else
            {
                data.open("database.txt", ios::app | ios::out);
                data << " " << product_code << " " << product_name << " " << price << " " << discount << "\n"; // FIX: was 'product' (undefined); added missing <<
                data.close();
            }
        }  // FIX: was missing closing brace for outer else

        cout << "\n\n\t\t Record inserted! ";
    }
}

void shopping::edit()
{
    fstream data, data1;
    int product_key;
    int token = 0;
    int c;        // FIX: was 'int = c;' — invalid syntax
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code :";
    cin >> product_key;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\nFile doesn't exist! ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> product_code >> product_name >> price >> discount;
        while (!data.eof())
        {
            if (product_key == product_code)
            {
                cout << "\n\t\t Product new code :";
                cin >> c;
                cout << "\n\t\t Name of the product :";
                cin >> n;
                cout << "\n\t\t Price :";
                cin >> price;
                cout << "\n\t\t Discount :";
                cin >> discount;
                data1 << " " << c << " " << n << " " << price << " " << discount << "\n "; // FIX: was writing p and d (unassigned) instead of price and discount
                cout << "\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                data1 << " " << product_code << " " << product_name << " " << price << " " << discount << "\n";
            }
            data >> product_code >> product_name >> price >> discount;
        }
    }
    data.close();
    data1.close();

    ::remove("database.txt");
    rename("database1.txt", "database.txt");  // FIX: was "dataabsae1.txt" — typo in filename

    if (token == 0)
    {
        cout << "\n\n Record not found sorry!";
    }
}

void shopping::remove()
{
    fstream data, data1;
    int product_key;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code :";
    cin >> product_key;
    data.open("database.txt", ios::in);  // FIX: was missing semicolon
    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> product_code >> product_name >> price >> discount;
        while (!data.eof())
        {
            if (product_code == product_key)
            {
                cout << "\n\n\t Product deleted successfully";
                token++;  // FIX: token was never incremented — "record not found" always printed
            }
            else
            {
                data1 << " " << product_code << " " << product_name << " " << price << " " << discount << "\n";
            }
            data >> product_code >> product_name >> price >> discount;
        }
        data.close();
        data1.close();
        ::remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n_______________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n_______________________________________________\n";
    data >> product_code >> product_name >> price >> discount;  // FIX: was data >>.product_name — stray dot
    while (!data.eof())
    {
        cout << product_code << "\t\t" << product_name << "\t\t" << price << "\n";  // FIX: was missing << operators
        data >> product_code >> product_name >> price >> discount;  // FIX: was 'dis' (undefined) and missing price read
    }
    data.close();
}

void shopping::receipt()  // FIX: was 'void shopping receipt()' — missing ::
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int count = 0;  // FIX: using count consistently as the array index
    float amount = 0;
    float totalDiscount = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);  // FIX: was database.txt without quotes; also added missing semicolon

    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();

        list();
        cout << "\n______________________________________________\n";
        cout << "\n|                                            |\n";
        cout << "\n              Please place the order          \n";
        cout << "\n|                                            |\n";
        cout << "\n______________________________________________\n";

        do
        {
            // FIX: was cin >> arrq[choice] (char index) — now using arrc[count] for code, arrq[count] for quantity
            cout << "\n\n Enter Product Code: ";
            cin >> arrc[count];
            cout << "\n\n Enter the product quantity: ";
            cin >> arrq[count];

            for (int i = 0; i < count; i++)
            {
                if (arrc[count] == arrc[i])
                {
                    cout << "\n\n Duplicate product code. Please try again.";
                    count--;  // cancel the increment below
                    break;
                }
            }
            count++;

            cout << "\n\n Do you want to buy another product? If yes, then press y, else n: ";
            cin >> choice;

        } while (choice == 'y');  // FIX: was "y" (string) — must use char literal 'y'

        // FIX: receipt printing moved OUTSIDE the do-while — it was incorrectly inside the while condition block
        cout << "\n\n\t\t\t___________________RECEIPT___________________\n";
        cout << "\nProduct No.\tProduct Name\tQuantity\tPrice\tAmount after discount\n";

        for (int i = 0; i < count; i++)
        {
            data.open("database.txt", ios::in);
            data >> product_code >> product_name >> price >> discount;
            while (!data.eof())
            {
                if (product_code == arrc[i])
                {
                    amount = price * arrq[i];
                    float discounted = amount - (amount * discount / 100);
                    total = total + discounted;
                    cout << "\n" << product_code << "\t\t" << product_name << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << discounted;
                }
                data >> product_code >> product_name >> price >> discount;  // FIX: was '>product_name' — missing >
            }
            data.close();
        }

        cout << "\n\n________________________________________________________";
        cout << "\n Total Amount: " << total;  // FIX: stray 'c' after total was removed
    }
}

int main()
{
    shopping s;
    s.menu();
    return 0;
}
