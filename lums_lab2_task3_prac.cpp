#include <iostream>

using namespace std;

struct Customer{
    public:
    string name;
    double balance;
};

struct Product{
    public:
    string name;
    double price;
    int quantity;
};

Customer C[20];
Product P[20];

void menu()
{
    cout<<"Welcome to the Online Marketplace Management System!"<<endl;
    cout<<"1. Add Customer"<<endl;
    cout<<"2. Add Product"<<endl;
    cout<<"3. Display Customer Information"<<endl;
    cout<<"4. Display Product listings"<<endl;
    cout<<"5. Make a purchase"<<endl;
    cout<<"6. Exit"<<endl;
}

int c_count = 0, p_count = 0;

void addCustomers()
{
    if(c_count>=20)
    {cout<<"Customer limit reached";}
    else
    {
    cout<<"Enter customer name: ";
    cin>>C[c_count].name;
    cout<<"Enter wallet balance: ";
    cin>>C[c_count].balance;
    c_count++;
    }
}

void addProducts()
{
    if(p_count>=20)
    {cout<<"Product limit reached";}
    else
    {
    cout<<"Enter product name: ";
    cin>>P[p_count].name;
    cout<<"Enter product price: PKR";
    cin>>P[p_count].price;
    cout<<"Enter product quantity: ";
    cin>>P[p_count].quantity;
    p_count++;
    }
}

void displayCustomers()
{
    cout<<"List of Customers: "<<endl;
    for(int i = 0; i<c_count; i++)
    {
        cout<<i+1<<". "<<C[i].name<<" (Balance: "<<C[i].balance<<")"<<endl;
    }
}

void displayProducts()
{
    cout<<"List of Products: "<<endl;
    for(int i = 0; i<p_count; i++)
    {
        cout<<i+1<<". "<<P[i].name<<" (Price: "<<P[i].price<<") quantity: "<<P[i].quantity<<endl;;
    }
}

void purchaseProducts()
{
    if(c_count==0 || p_count==0)
    {
        cout<<"no customer or product available for purchase"<<endl;
        return;
    }

    string Cust_Name;
    string Prod_Name;
    int x;
    cout<<"Enter Customer name: ";
    cin>>Cust_Name;
    cout<<"Enter Product name: ";
    cin>>Prod_Name;
    cout<<"Enter quantity: ";
    cin>>x;

    int c_index = -1, p_index = -1;

    for(int i = 0; i<c_count; i++)
    {
        if(Cust_Name==C[i].name)
        {
            c_index = i;
        }
    }

    for(int i = 0; i<p_count; i++)
    {
        if(Prod_Name==P[i].name)
        {
            p_index = i;
        }
    }

    if(c_index == -1)
    {
        cout<<"Customer not found"<<endl;
    }

    if(p_index == -1)
    {
        cout<<"Product not found"<<endl;
    }

    for(int i = 0; i<p_count; i++)
    {
        if((Prod_Name==P[i].name) && (x>P[i].quantity))
        {
            cout<<"customer demand exceeds quantity of product in inventory"<<endl;
            return;
        }
    }

    double T_Cost = x * P[p_index].price;

    if(C[c_index].balance < T_Cost)
    {
        cout<<"insufficient funds"<<endl;
        return;
    }

    C[c_index].balance -= T_Cost;
    P[p_index].quantity -= x;

    cout << "Purchase successful!" << endl;
}   

int main()
{
    // Customer C[20];
    // Product P[20];  cannot declare arrays here since functions declared before main require these arrays to be declared before themselves

    while(true)
    {    
    int a;
    menu();
    cout<<"PLease enter your choice: ";
    cin>>a;

    switch(a)
    {
        case 1:
        addCustomers();
        break;

        case 2:
        addProducts();
        break;

        case 3:
        displayCustomers();
        break;

        case 4:
        displayProducts();
        break;

        case 5:
        purchaseProducts();
        break;

        case 6:
        cout<<"exiting program";
        return 0;
        break;
    }
    }

}