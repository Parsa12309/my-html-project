#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;
int Wallet_user1=60;
int Wallet_user2=35;
int Wallet_user3=250;
int n=10;
struct Product
{
    string name;
    int redmainder;
    int price;
};

struct Role
{
    string Username;
    int Password;
};

void User ( int , Product* , int);

void Admin (Product* , int);

int login(Product* product , int n)
{
    string user;
    int password;
    
    Role admin1{"parsa",524};
    Role admin2{"mohammad",874};
    Role user1{"reza",963};
    Role user2{"farzad",612};
    Role user3{"mani",258};
    cout<<endl<<"Do you want to log in?(y/n): ";
    string log;
    cin>>log;
    if(log=="y")
    {

        cout<<"Enter Username: ";
        cin>>user;
        cout<<"Enter password: ";
        while (!(cin >> password))
        {
            cout<<"Error"<<endl;
            return 0; 
        }    
        if((user==admin1.Username&&password==admin1.Password)||(user==admin2.Username&&password==admin2.Password))
        {
            Admin(product , n);
        }    
        
        else if((user==user1.Username&&password==user1.Password)||(user==user2.Username&&password==user2.Password)||(user==user3.Username&&password==user3.Password))
        {
            if((user==user1.Username&&password==user1.Password))
                User(Wallet_user1 , product , n);
            else if((user==user2.Username&&password==user2.Password))
                User(Wallet_user2 , product , n);
            else if((user==user3.Username&&password==user3.Password))
                User(Wallet_user3 , product , n);
        }
        
        else
        {
            cout<<"The password or username are incorrect "<<endl;
            login(product , n);
        }
    }
    else if(log=="n")
        return 0;
    else
    {
       cout<<"The entered Word is not valid";
        login(product , n);
    }

       return 0;

}

void outputt(Product* product , int n)
{
    ofstream outputFile("information.txt");
    if(!outputFile)
    {
        cerr<<"Error opening file for writing!" << endl;
    }
    outputFile<<setw(20)<<left<<"Product Name"<<setw(20)<<"Remainder"<<setw(10)<<"price"<<endl;
    for(int i=0;i<n;i++)
    {

        outputFile<<setw(22)<<product[i].name<<setw(19)<<product[i].redmainder<<product[i].price<<"$"<<endl;
    }
    outputFile.close();
}

void inputt(Product* product , int n)
{
    cout << "List of items:" << endl;
    for(int i=0;i<n;++i)
    {
        cout <<setw(10)<<left<< product[i].name<<endl;
    }
}

void User(int wallet , Product* product , int n)
{
    outputt(product , n);

    cout<<"# show ITEM"<<endl;
    cout<<"# buy ITEM"<<endl;
    cout<<"# balanc"<<endl;
    cout<<"# help COMMAND"<<endl;

    string choose;
    cin>>choose;
    cout<<"#"<<endl;
    if(choose=="show")
    {

        string name_item;
        cin.ignore();
        getline(cin , name_item);
        if(name_item.empty()) 
        {
        inputt(product, n);
        }
        else
        {
            int chek=0;
            for(int i=0 ;i<n;++i)
            {
                if(name_item==product[i].name)
                {
                    cout<<setw(20)<<left<<"Product Name"<<setw(20)<<"Remainder"<<setw(10)<<"price"<<endl;
                    cout<<setw(22)<<left<<product[i].name<<setw(19)<<product[i].redmainder<<product[i].price<<endl;
                    break;
                }
                ++chek;
            }
            if(chek==n)
            {
                cout<<"There is no such product!!!"<<endl;
            }
        }
        cout<<"You want to log out(y/n)"<<endl;
        string ritorout;
        cin>>ritorout;
        if(ritorout=="n")
        {
            User(wallet,product , n);
        }
        else if(ritorout=="y")
            login(product , n);
        
        else 
        {
            cout<<"The entered Word is not valid";
            login(product , n);
        }
    }        
    else if(choose=="buy") 
    {
        string name;
        cin>>name;
        for(int i=0;i<n;++i)
        {
            if(product[i].name==name)
            {
                if(wallet-product[i].price<0)
                    cout<<"Not enough inventory!!!"<<endl;
                else
                {
                    wallet-=product[i].price;
                    product[i].redmainder-=1;
                }
            }
        }   
        cout<<"You want to log out(y/n)"<<endl;
        string ritorout;
        cin>>ritorout;
        if(ritorout=="n")
        {
            User(wallet,product , n);
        }
        else if(ritorout=="y")
            login(product , n);
        
        else 
        {
            cout<<"The entered Word is not valid";
            login(product , n);
        }
    }       
    else if(choose=="balanc")
    {
        cout<<wallet<<"$"<<endl;
        cout<<"You want to log out(y/n)"<<endl;
        string ritorout;
        cin>>ritorout;
        if(ritorout=="n")
        {
            User(wallet,product , n);
        }
        else if(ritorout=="y")
            login(product , n);
        
        else 
        {
            cout<<"The entered Word is not valid";
            login(product , n);
        }
    }        
    else if(choose=="help")
    {
        string name_help;
        cin>>name_help;
        if(name_help=="by")
        {
            cout<<"To buy,Enter(buy + product name)";
        }
        else if(name_help=="balanc")
        {
            cout<<"To viwe wallet,Enter(balanc)";
        }
        else if(name_help=="show")
        {
            cout<<"To view products,Enter(show) and To see mor detalis Enter name product";
        }
        cout<<endl<<"You want to log out(y/n)"<<endl;
        string ritorout;
        cin>>ritorout;
        if(ritorout=="n")
        {
            User(wallet,product , n);
        }
        else if(ritorout=="y")
            login(product , n);
        else 
        {
            cout<<"The entered Word is not valid";
            login(product , n);
        }

    }        
    else
    {

        cout<<"Error Enter number";
        cout<<"You want to log out(y/n)"<<endl;
        string ritorout;
        cin>>ritorout;
        if(ritorout=="n")
        {
            User(wallet,product , n);
        }
        else if(ritorout=="y")
            login(product , n);
        else 
        {
            cout<<"The entered Word is not valid";
            login(product , n);
        }
    }
}

void Admin(Product* product , int n)
{
    outputt(product , n);
    cout<<"$ add ITEM PRICE"<<endl;
    cout<<"$ remove ITEM"<<endl;
    cout<<"$ rename ITEM NEWITEM"<<endl;
    cout<<"$ price ITEM NEWPRICE"<<endl;
    cout<<"$ credit USER AMOUNT"<<endl;

    string choose;
    cin>> choose;
    cout<<"$"<<endl;
    if(choose=="add")
    {
        Product neww;
        cin>>neww.name;
        cin>>neww.redmainder;        
        cin>>neww.price;

        Product* product_new=new Product[n+1];
        for(int i=0;i<n;++i)
        {
            product_new[i]=product[i];
        }
        product_new[n]={neww.name , neww.redmainder , neww.price};
        delete[] product;
        ++n;
        Product* product= new Product[n];
        for(int i=0;i<n;++i)
        {
            product[i]=product_new[i];
        }
        delete[]product_new;
        outputt(product , n);

        cout<<"You want to log out(y/n)"<<endl;
        string ritorout;
        cin>>ritorout;
        if(ritorout=="n")
        {
            Admin(product , n);
        }
        else if(ritorout=="y")
            login(product , n);
        
        else 
        {
            cout<<"The entered Word is not valid";
            login(product , n);
        }

    }
    else if(choose=="remove")
    {
        string name;
        cin>>name;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (product[i].name != name) {
                count++;
            }
        }

        if (count == n) 
        {
            cout << "not name" << endl;
            cout<<"You want to log out(y/n)"<<endl;
            string ritorout;
            cin>>ritorout;
            if(ritorout=="n")
            {
                Admin(product , n);
            }
            else if(ritorout=="y")
                login(product , n);
            
            else 
            {
            cout<<"The entered Word is not valid";
            login(product , n);
            }
        }
        Product* del = new Product[n-1];
        int j = 0;

        for (int i = 0; i < n ,j<n-1; ++i) {
            if (product[i].name != name) {
                del[j] = product[i];
                ++j;
            }
            else 
            continue;
        }
        delete[] product;
        Product* product= new Product[n];
        n--;   
        for(int i=0;i<n;++i)
        {
            product[i]=del[i];
        } 
        delete[] del;
        outputt(product , n);
        cout<<"You want to log out(y/n)"<<endl;
        string ritorout;
        cin>>ritorout;
        if(ritorout=="n")
        {
            Admin(product , n);
        }
        else if(ritorout=="y")
            login(product , n);
        
        else 
        {
            cout<<"The entered Word is not valid";
            login(product , n);
        }

    }
    else if(choose=="rename")
    {
        string name_first;
        string name_tow;
        cin>>name_first;
        cin>>name_tow;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(product[i].name==name_first)
            {
                product[i].name=name_tow;
                outputt(product,n);
                break;
            }
        }
        if(sum==n)
        {
            cout<<"There is no such product!!!"<<endl;
        }
        cout<<"You want to log out(y/n)"<<endl;
        string ritorout;
        cin>>ritorout;
        if(ritorout=="n")
        {
            Admin(product , n);
        }
        else if(ritorout=="y")
            login(product , n);
        else 
        {
            cout<<"The entered Word is not valid";
            login(product , n);
        }
    }
    else if(choose=="price")
    {
        string name;
        int mani;
        cin>>name;
        cin>>mani;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(product[i].name==name)
            {
                product[i].price=mani;
                outputt(product,n);
                break;
            }
            ++sum;
            
        }
        if(sum==n)
        {
            cout<<"There is no such product!!!"<<endl;
        }
        cout<<"You want to log out(y/n)"<<endl;
        string ritorout;
        cin>>ritorout;
        if(ritorout=="n")
        {
            Admin(product , n);
        }
        else if(ritorout=="y")
            login(product , n);
        else 
        {
            cout<<"The entered Word is not valid";
            login(product , n);
        }
    }
    else if(choose=="credit")
    {
        string name;
        cin>>name;
        int edit_wallet;
        cin>>edit_wallet;
        if(name=="reza")
            Wallet_user1=edit_wallet;
        else if(name=="farzad")
            Wallet_user2=edit_wallet;
        else if(name=="mani")
            Wallet_user3=edit_wallet;
        else 
            cout<<"Error name";

        cout<<"You want to log out(y/n)"<<endl;
        string ritorout;
        cin>>ritorout;
        if(ritorout=="n")
        {
            Admin(product , n);
        }
        else if(ritorout=="y")
            login(product , n);
        else 
        {
            cout<<"The entered Word is not valid";
            login(product , n);
        }
    }
    else
    {
        cout<<"You want to log out(y/n)"<<endl;
        string ritorout;
        cin>>ritorout;
        if(ritorout=="n")
        {
            Admin(product , n);
        }
        else if(ritorout=="y")
            login(product , n);
        
        else 
        {
            cout<<"The entered Word is not valid";
            login(product , n);
        }
    }
}

int main()

{
    Product*product= new Product[10]; 
    product[0]={"albalo",  900 , 45};
    product[1]={"tomato",   200 , 10};
    product[2]={"potato",   300 , 5 };
    product[3]={"banana",   400 , 60};
    product[4]={"cucumber", 800 , 15};
    product[5]={"portugal", 500 , 40};
    product[6]={"apple",    150 , 50};
    product[7]={"tangerine",500 , 40};
    product[8]={"apricot",  100 , 60};
    product[9]={"peach",    300 , 50};

    login(product , 10);

    delete[] product;
    return 0;
}