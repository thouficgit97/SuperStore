/*
Question asked in round 3:

Super Store

Build an online shopping interface where buyers and sellers can buy and sell inventory and engage in efficient transactions across a wide range of products.

Modules :

    Profile service.
    Inventory service.
    Order service.
    Payment service.

Requirements :

    Allow buyers and sellers to register and log in.
    Allow sellers to manage their inventory of products. (Operations : addItem(), updateItem())
    Allow buyers to add items to the cart, place the order, and make payment (Operations: listInventory(), buyItem(), addToCart(), makePayment ()).
    Orders should be validated against inventory.
    Password validation and encryption.
*/
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

class Product
{
    string productName,sellerName;
    int price,quantity;
    public:
        Product(string sellerName,string productName,int price,int quantity)
        {
            this->sellerName = sellerName;
            this->productName = productName;
            this->price = price;
            this->quantity = quantity;
        }
        
        int getPrice()
        {
            return price;
        }
        void setPrice(int price)
        {
            this->price = price;
        }
        int getQuantity()
        {
            return quantity;
        }
        string getSellerName()
        {
            return sellerName;
        }
        string getProductName()
        {
            return productName;
        }
        void setQuantity(int quantity)
        {
            this->quantity = quantity;
        }
        void setName(string productName)
        {
            this->productName = productName;
        }
};
vector<Product>productDetails;
class Seller
{
    string username,password;
    public:
        Seller(string username,string password){
            this->username = username;
            this->password = password;
        }
        string getuserName()
        {
            return username;
        }
        string getPassword()
        {
            return password;
        }
        void sellerMenu()
        {
            short choice;
            while(true)
            {
                cout<<"1.Add Item"<<endl;
                cout<<"2.Update Item"<<endl;
                cout<<"3.View Products"<<endl;
                cout<<"4.Log Out"<<endl;
                cout<<"Enter your choice:";
                cin>>choice;
                if(choice == 1)
                {
                    addItem();
                }
                else if(choice == 2)
                {
                    updateItem();
                }
                else if(choice == 3)
                {
                    viewProducts();
                }
                else if(choice == 4)
                {
                    cout<<"Logged out successfully!"<<endl;
                    break;
                }
                else
                {
                    cout<<"Invalid Choice!"<<endl;
                }
            }
        }
        void addItem()
        {
            string productName;
            int price,quantity;
            cout<<"Enter your Product name:";
            cin>>productName;
            cout<<"Enter the price:";
            cin>>price;
            cout<<"Enter the quantity:";
            cin>>quantity;
            productDetails.push_back(Product(username,productName,price,quantity));
            cout<<"The added product Id is : "<<productDetails.size()<<endl;

        }
        void updateItem()
        {
            if(productDetails.size() == 0)
            {
                cout<<"No products are available!"<<endl;
                return;
            }
            string updateName;
            int productId;
            while(true)
            {
                cout<<"Enter the product Id:";
                cin>>productId;
                if(productDetails.size() > productId || productId<=0)
                {
                    cout<<"Invalid Product Id!"<<endl;
                }
                else
                    break;
            }
            cout<<"What do you want to update(price/quantity/name)?";
            cin>>updateName;
            if(updateName == "price")
            {
                int price;
                cout<<"Enter the new price :";
                cin>>price;
                productDetails[productId-1].setPrice(price);
                cout<<"Price Updated!"<<endl;
            }
            else if(updateName == "quantity")
            {
                int quantity;
                cout<<"Enter the new quantity:";
                cin>>quantity;
                productDetails[productId-1].setQuantity(quantity);
                cout<<"Quantity Updated!"<<endl;
            }
            else if(updateName == "name")
            {
                string name;
                cout<<"Enter the new name:";
                cin>>name;
                productDetails[productId-1].setName(name);
                cout<<"product name Updated!"<<endl;
            }
        }
        void viewProducts()
        {
            for(int i = 0;i<productDetails.size();i++)
            {
                if(productDetails[i].getSellerName() == username)
                {
                    cout<<"--------------------------------------------------"<<endl;
                    cout<<"Id           "<<":"<<i+1<<endl;
                    cout<<"Seller Name  "<<":"<<productDetails[i].getSellerName()<<endl;
                    cout<<"Product Name "<<":"<<productDetails[i].getProductName()<<endl;
                    cout<<"Quantity     "<<":"<<productDetails[i].getQuantity()<<endl;
                    cout<<"--------------------------------------------------"<<endl;
                }
            }
        }
};
class Buyer{
    vector<Product>cart;
    string username,password;
    public:
        Buyer(string username,string password){
            this->username = username;
            this->password = password;
        }
        string getuserName()
        {
            return username;
        }
        string getPassword()
        {
            return password;
        }
        void buyerMenu()
        {
            while(true)
            {
                short choice;
                cout<<"1.list Inventory"<<endl;
                cout<<"2.Buy Item"<<endl;
                cout<<"3.Add To Cart"<<endl;
                cout<<"4.Display My Cart"<<endl;
                cout<<"5.Log Out"<<endl;
                cout<<"Enter your choice:";
                cin>>choice;
                if(choice == 1)
                {
                    listInventories();
                }
                else if(choice == 2)
                {
                    buyItem();
                }
                else if(choice == 3)
                {
                    addToCart();
                }
                else if(choice == 4)
                {
                    displayCart();
                }
                else if(choice == 5)
                {
                    break;
                }
                else
                {
                    cout<<"Invalid Choice!"<<endl;
                }
            }
        }
        void listInventories()
        {
            if(productDetails.size() == 0)
            {
                cout<<"No products are added!"<<endl;
                return;
            }
            for(int i = 0;i<productDetails.size();i++)
            {
                cout<<"--------------------------------------------------"<<endl;
                cout<<"Id           "<<":"<<i+1<<endl;
                cout<<"Seller Name  "<<":"<<productDetails[i].getSellerName()<<endl;
                cout<<"Product Name "<<":"<<productDetails[i].getProductName()<<endl;
                cout<<"Quantity     "<<":"<<productDetails[i].getQuantity()<<endl;
                cout<<"--------------------------------------------------"<<endl;
            }
        }
        void buyItem()
        {
            if(productDetails.size() == 0)
            {
                cout<<"No products are available!"<<endl;
                return;
            }
            int productId; 
            cout<<"Enter the product id you are going to buy:";
            cin>>productId;
            if(productId>productDetails.size() || productId<=0)
            {
                cout<<"Invalid Product Id!"<<endl;
            }
            else
            {
                int quantity; 
                cout<<"Enter the quantity:";
                cin>>quantity;
                if(productDetails[productId-1].getQuantity()<quantity)
                {
                    cout<<"Stock unavailable!";
                }
                else
                {
                    int count = productDetails[productId-1].getQuantity();
                    productDetails[productId-1].setQuantity(count-quantity);
                    if(productDetails[productId-1].getQuantity() == 0)
                    {
                        productDetails.erase(productDetails.begin()+(productId-1));
                    }

                }
            }      
        }
        void addToCart()
        {
            if(productDetails.size() == 0)
            {
                cout<<"No products are available!"<<endl;
                return;
            }
            int productId;
            cout<<"Enter the product Id:";
            cin>>productId;
            if(productId>productDetails.size() || productId<=0)
            {
                cout<<"Invalid Product Id!"<<endl;
            }
            else
            {
                cart.push_back(productDetails[productId-1]);
                cout<<"product added to Cart successfully!"<<endl;
            }
        }
        void displayCart()
        {
            if(cart.size() == 0)
            {
                cout<<"No products are added yet!"<<endl;
                return ;
            }
            for(int i = 0;i<cart.size();i++)
            {
                cout<<"--------------------------------------------------"<<endl;
                cout<<"Id           "<<":"<<i+1<<endl;
                cout<<"Seller Name  "<<":"<<cart[i].getSellerName()<<endl;
                cout<<"Product Name "<<":"<<cart[i].getProductName()<<endl;
                cout<<"Quantity     "<<":"<<cart[i].getQuantity()<<endl;
                cout<<"--------------------------------------------------"<<endl;
            }
        }
};
class UserManagement{
    string username,password;
    char user;
    vector<Buyer>buyerDetails;
    vector<Seller>sellerDetails;
    public:
        void Registerorlogin(char user,short choice)
        {
            cout<<"Enter your Username:";
            cin>>username;
            cout<<"Enter your Password:";
            cin>>password;
            if(choice == 1)
            {
                if(user == 'b')
                {
                    buyerDetails.push_back(Buyer(username,password));
                    cout<<"Registerd succefully!"<<endl;
                }
                else
                {
                    sellerDetails.push_back(Seller(username,password));
                    cout<<"Registerd succefully!"<<endl;
                }
            }
            else
            {
                if(user == 'b')
                {
                    int i;
                    bool flag = false,userflag = false;
                    for(i = 0;i<buyerDetails.size();i++)
                    {
                        if(buyerDetails[i].getuserName() == username)
                        {
                            userflag = true;
                            if(buyerDetails[i].getPassword() == password)
                            {
                                cout<<"Logged in successfully!"<<endl;
                                flag = true;
                                break;
                            }
                            else
                            {
                                cout<<"Incorrect Password!"<<endl;
                            }
                        }
                    }
                    if(flag) 
                        buyerDetails[i].buyerMenu();
                    else if(!userflag)
                        cout<<"Username doesn\'t Exist!"<<endl;
                }
                else
                {
                    int i;
                    bool flag = false,userflag = false;
                    for(i = 0;i<sellerDetails.size();i++)
                    {
                        if(sellerDetails[i].getuserName() == username)
                        {
                            userflag = true;
                            if(sellerDetails[i].getPassword() == password)
                            {
                                cout<<"Logged in successfully!"<<endl;
                                flag = true;
                                break;
                            }
                            else
                            {
                                cout<<"Incorrect Password!"<<endl;
                            }
                        }
                    }
                    if(flag) 
                        sellerDetails[i].sellerMenu();
                    else if(!userflag)
                        cout<<"Username doesn\'t Exist!"<<endl;
                   
                }
            }

        }
        void menu()
        {
            short choice;
            while(true)
            {
                while(true)
                {
                    cout<<"Enter B for Buyer or S for seller:";
                    cin>>user;
                    if(tolower(user) != 'b' && tolower(user) != 's')
                        cout<<"Invalid Choice!"<<endl;
                    else 
                        break;
                }
                cout<<"1.Register"<<endl;
                cout<<"2.Login"<<endl;
                cout<<"3.Exit"<<endl;
                cout<<"Enter your choice(1/2):";
                cin>>choice;
                if(choice!=1 && choice!=2 && choice!=3)
                {
                    cout<<"Invalid Choice!"<<endl;
                }
                else if(choice == 1)
                {
                    Registerorlogin(user,choice);
                }
                else if(choice == 2)
                {
                    if(buyerDetails.size() == 0 && user == 'b')
                        cout<<"No buyers are registered yet!"<<endl;
                    else if(sellerDetails.size() == 0 && user == 's')
                        cout<<"No sellers are registered yet!"<<endl;
                    else 
                        Registerorlogin(user,choice);
                }
                else if(choice == 3)
                    return;
            }
            
        }
            
};
int main()
{
    UserManagement usermanagement;
    usermanagement.menu();   
}