

# include <iostream>

# include <fstream>

using namespace std;


class Shopping
{
    private:
    int prod_code;
    float price;
    float discount;
    string prod_name;

    public:
    void menu();
    void admin();
    void customer();
    void add();
    void del();
    void edit();
    void list();
    void Receipt();

};

// Creating menu function

void Shopping :: menu()
{
    m:
    // Take input from the user what he wants to do
    int choice;
    // Email and password variable for user login
    string email;
    string password;

    // Displaying the Menu for user to select his choice from the options
    cout << "-------------------------       ------------------------- \n";
    cout << "--------------------------------------------------------- \n";

    cout << " ****************** Supermarket Main Menu *************** \n ";

    cout << "--------------------------------------------------------- \n";
    cout << "--------------------------------------------------------- \n";

    cout << " 1. Administrator " << endl;

    cout << " 2. Customer " << endl;

    cout << " 3. Exit " << endl;

    cout << " Kindly select your choice from the options :  " << endl;

    // Taking user input and storing in Choice

    cin >> choice;

    // Following operations will be done based on the choice selected by user

    switch(choice)
    {
        // if user selects 1 , we ask him to login first using email and password
        case 1:
        {
            cout << " Kindly login first ...  \n \n ";
            cout << endl << " Enter your email : " << endl;
            cin >> email;

            cout << endl<< " Password : " << endl;
            cin >> password;

            // CHeck if the user is normal user or admin user

            // Default email and password for admin are specified here

            if( email == "admin@gmail.com" && password == "admin@123")
            {
                admin();
                
            }
            else
            {
                cout << " Invalid email / password ... " << endl;
            }
            break;
        }
    
        case 2:
        {
            customer();
        }

        case 3:
        {
            exit(0);
        }
        default:
        {
            cout << " Enter choice from the given options only ..." << endl;
        }
   
    }
    goto m;
}


// Shopping class

void Shopping :: admin()
{
    m1:
    int choice;
    // Creating a new menu for Administrator

    cout << endl << " ************* Admin's Menu ****************** " << endl<< endl;
    cout <<  "1) Adding new product" << endl;
    cout <<  "2) Edit/ Modify the product " << endl;
    cout <<  "3) Remove the product " << endl;
    cout <<  "4) Back to Main Menu " << endl;

    // Take input from admin
    cout << " Enter your choice : " << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            cout << " Adding new product to the system" << endl;
            add();
            break;
        }
        

        case 2:
        {
            cout << " Modifying the existing product to the system" << endl;
            edit();
            break;
        }
        
        case 3:
        {
            cout << " Delete the product from the system" << endl;
            del();
            break;
        }
        case 4:
        {
            cout << " Back to Main Menu " << endl;
            menu();
            break;
        }
        default:
            cout << " Invalid Choice selected .. ";

    }

    goto m1;
}

// Customer function

void Shopping :: customer()
{
    m2:

    int choice;
    cout << " Customer \n";

    cout << " --------------------------------- \n\n" << endl;
    cout << endl << " 1) Buy the product " << endl;
    cout << endl << " 2) Go back " << endl;

    cout << endl << " Enter your choice : " << endl;

    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            cout << " Buying new product " << endl;
            Receipt();
            break;
        }

        case 2:
        {
            cout << " Back to Main Menu " << endl;
            menu();
            break;
        }


        default:
            cout << " Invalid Choice selected .. ";

    }
    goto m2;


}

// Function to add the products ti the system by admin
void Shopping :: add()
{
    m3:

    // Function add so the admin can add new items to the system
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "   Add new product \n" ;
    cout << " \n Product code of the product : " << endl;

    cin >> prod_code;

    cout << endl << " Name of the product : " << endl;
    cin >> prod_name;

    cout << endl << " Price of the product : " << endl ;
    cin >> price;

    cout << endl << " Discount foe product : " << endl;
    cin >> discount;

    // Open a file in read mode to store the details of the products

    data.open("database.txt", ios::in);

    // check if the database file is not existing, then create a new database file 
    if(!data)
    {
        // ios :: app --> appends the data to the file
        // ios :: out --> is used to open the file in write mode

        data.open("database.txt", ios:: app | ios:: out);
        // Writing inside the txt file
        data << " " << prod_code << " " << prod_name << " " << price << " " <<  discount <<"\n";
        // close the opened file
        data.close();

    }
    else
    {
        // if file exists, we read the data from the file

        // initialize the file to access the data and iterate in the file
        data >> c >> n >> p >> d;
        
        // iterate until we reach end of the file 

        while( !data.eof())
        {
            // if there is a product having the code same as that in the file then the token will be increamented
            if( c == prod_code)
            {
                token++;
            }
            // read from the file

            data >> c >> n >> p >> d;
        }
        // CLose the opened file
        data.close();
    

    // if token is incremented i.e duplicate entry done then it will ask admin to reenter the data again using new product code

        if( token == 1)
        {
            goto m3;
        }
        else
        {
            // if the token is not increamented, i.e no duplicate value entered
            // write inside the file
            data.open("database.txt", ios::app | ios:: out);

            data << " " << prod_code << " " << prod_name << " " << price << " " << discount << " \n" ;
            data.close();
        }
    }

    cout << " Record inserted in the system !!" << endl;

}


void Shopping :: edit()
{
    // To modify the details of the product already existing in the system

    fstream data, data1;
    int prod_key;
    int token =0;
    int c;
    float p;
    float d;
    string n;

    cout << endl << " Modify the record " << endl;

    cout << endl << " Enter the product code for which you want to edit the details" << endl;

    cin >> prod_key;

    // check if the file is present in the system
    data.open(" database.txt", ios:: in);
    if(!data)
    {
        cout << " File does not exist !!" << endl;
    }
    else
    {
        // store the changes made to the product in the data1 file and rename the database.txt to database1.txt
        data1.open("database1.txt", ios::app | ios:: out);

        data >> prod_code>> prod_name>> price>> discount;
        while(!data.eof())
        {
            if(prod_key == prod_code)
            {
                cout << " Product new code is : " <<endl;
                cin >> c;

                cout << " Name of the product : " << endl;
                cin >> n;

                cout << " Price :" <<endl;
                cin >> p;

                cout << " Discount :" <<endl;
                cin >> d;

                data << " " << c << " " << n << " " << p << " " << d << endl;
                cout <<  " Record edited successfully .. " << endl;
                token++;
            }
            else
            {
                // if the prod_key entered is not found in the prod_code in database file

                data1 << " " << prod_code << " " << prod_name << " " << price << " " << discount << endl;

            }

            data >> prod_code >> prod_name >> price >> discount;
        }
        data.close();
        data1.close();

        // delete old file

        remove("database.txt");
        // rename the new file witht he previous files name
        rename("database1.txt", "database.txt");

        if(token == 0)
        {
            cout << " Record not found  ... " << endl;
        }
    }
}

// Delete function for admiin to delete the product fron the system
void Shopping :: del()
{
    fstream data, data1;

    int prod_key;
    int token = 0;

    cout << " Delete the product from the system ... " << endl;

    cout << endl << " Enter the product code of the product which you want to delete :" << endl;
    cin >> prod_key;

    // open the file in read mode to check if the data is present in the txt file
    data.open("database.txt", ios:: in);
    if(!data)
    {
        cout << " File does not exist .. " << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> prod_code >> prod_name>> price >> discount;

        while(!data.eof())
        {
            if(prod_code == prod_key)
            {
                cout << " Product deleted fromthe system successfully " << endl;
                token++;
            }
            else
            {
                data1 << " " <<prod_code << " "  << prod_name << " "<< price << " " << discount ;
            }
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0)
        {
            cout << " Record not present in system .. "<< endl;
        }
    }
}



void Shopping :: list()
{
    fstream data;
    data.open("database.txt", ios:: in);

    cout << " Product number \t product name \t price \t discount \n";
    cout << endl <<endl;

    data >> prod_code >> prod_name >> price >> discount;

    while(!data.eof())
    {
        cout << prod_code << " " << prod_name << " " << price << " " << discount  << "\n";

        data >> prod_code >> prod_name >> price >> discount;

    }
    data.close();
}


void Shopping:: Receipt()
{
    m4:
    //object of data
    fstream data;

    int arrc[100];      // array to store the product code
    int arrq[100];      // array to store the quantity of the items
    char choice[1];
    int c = 0;
    float amount = 0;
    float discount = 0;
    float total = 0;

    cout << " Receipt : " ;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout << " Database is empty .. "<<endl;
    }
    else
    {
        data.close();

        list();
        cout << " ******************************************** " << endl;
        cout << " Please your order here  " << endl;
        cout << " ******************************************** " << endl << endl;

        do
        {
            // take the product code and quantity in inout
            cout << " Enter the product code : " << endl;
            cin>> arrc[c];
            cout << endl << endl << " Enter the product quantity : " << endl;
            cin>> arrq[c];

            for( int i = 0; i< c; i++)
            {
                // check if the product code in the input is same as that in the database of system
                if( arrc[c] == arrc[i])
                {
                    cout << " Duplicate product code, kindly check and reneter .. "<< endl;
                    goto m4;
                }
            }
            c++;

            cout << " Do you want to buy anything else ? " << endl;
            cin >> choice;

        }
        while( choice == "y" );

        cout << " Receipt "<< endl << endl;

        cout << " Product number : " << " " << " Product Name " << " " << "Prod. quantity" << " " << "Price" <<  " " << "disxount"  <<endl;

        
        for( int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> prod_code >> prod_name >> price >> discount;

            while(!data.eof())
            {
                // check if code in input is same as that in system 
                if( prod_code == arrc[i])
                {
                    // calculate the amount for the product
                    amount = price * arrq[i];
                    discount = amount - (amount * discount /100);

                    total = total + discount;
                    cout << " " << prod_code<< " " << prod_name << " " << price << " " << amount << " " << discount<<endl;
                }
                data >> prod_code >> prod_name >> price >> discount;
            } 
        }
        data.close();
    
    
    }

    cout << " *******************************************************  \n\n";
    cout << endl << " Total amount : " << total << endl<< endl;
}

int main()
{
    Shopping s;
    s.menu();
}