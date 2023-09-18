#include <iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<windows.h>
using namespace std;
string setcolor(unsigned short color){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    return "";
}
struct Customer{
char C_name[30];
int p_number;
};
class Item{
private:
    char name[30];
    int quantity;
    string measurement;
    double bought_price;
    double selling_price;
    Customer cust_data;
public:
    void main_page();
    void addItem();
    void updateItem();
    void displayItem();
    void addQuantity();
    void buyItem();
    void decQuantity(char M_Name[30],double qua);
    void customerList();
    void soldItem(char Sname[30],int Squa,double SBprice,double SSprice,double Profit);
    void DisplaySold();
};
void Item::main_page(){
cout<<"\n\n\t\t\t**************************************\n";
cout<<"\t\t\t* \t\t\t\t     *\n";
cout<<"\t\t\t* \t\t\t\t     *\n";
cout<<"\t\t\t*    Welcome to the shopping center  *\n";
cout<<"\t\t\t* \t\t\t\t     *\n";
cout<<"\t\t\t* \t\t\t\t     *\n";
cout<<"\t\t\t**************************************\n";
cout<<"\t\t\t* \t\t\t\t     *\n";
cout<<"\t\t\t* \t1) Owner \t\t     *\n";
cout<<"\t\t\t* \t2) customer\t\t     *\n";
cout<<"\t\t\t* \t3) Members\t\t     *\n";
cout<<"\t\t\t* \t\t\t\t     *\n";
cout<<"\t\t\t**************************************\n";

m:
int choice;
cout<<"\t\t\tEnter: ";cin>>choice;
if(choice==1){
string username,password;
cout<<"\t\t\t**************************************\n";
cout<<"\t\t\tusername\t";cin>>username;
cout<<"\t\t\tpassword\t";cin>>password;
            if(username=="project"&& password=="project"){ system("cls");
      int service;
 cout<<"\n\n\n\t\t\t1) Add Item\n";
        cout<<"\t\t\t2) update Item\n";
        cout<<"\t\t\t3) Display Item\n";
        cout<<"\t\t\t4) Quantity add\n";
        cout<<"\t\t\t5) Customer list\n";
        cout<<"\t\t\t6) Display Sold Items\n";
 s:       cout<<"\n\n\t\twhich service you want to get: ";
        cin>>service;
   if(cin.fail()) {
       system("cls");
        cout<<"Thank you for visiting us \n";
        goto k;
   }
        switch(service){
            case 1:
                system("cls");
                addItem();
                break;
            case 2:
                system("cls");
                updateItem();
                break;
            case 3:
                system("cls");
                displayItem();
                break;
            case 4:
                system("cls");
               addQuantity();
                break;
            case 5:
                customerList();
                break;
            case 6:
                system("cls");
                DisplaySold();
                break;
            default:
                setcolor(4);
                cout<<"\t\tplease select from listed services\n";
                setcolor(7);
                goto s;
}
}else{
        setcolor(4);
        cout<<"unauthorized username and password\n";setcolor(7);
        goto m;
}
}else if (choice==2){
    system("cls");
     buyItem();
}else if(choice==3){
    system("cls");
    k:
        system("color 8F");
cout<<"\n\n\n\t\t\t Enkutatash Eshetu\t\tETS0533\\14\n";
cout<<"\t\t\t Edom Mulugeta\t\t\tETS0503\\14\n";
cout<<"\t\t\t Emnet Teshome\t\t\tETS0529\\14\n";
cout<<"\t\t\t Ermiyas Ayele\t\t\tETS0541\\14\n";
cout<<"\t\t\t Bethel Solomon\t\t\tETS0318\\14\n";
cout<<"\t\t\t Ekhlas Abdulmelik\t\tETS0511\\14\n";
}else if(cin.fail()){
     system("cls");
    goto k;
}else{
    system("cls");
    setcolor(4);
    cout<<"Please enter valid input\n";setcolor(7);
    main_page();

}
}
void Item::customerList(){
    // list customers
fstream file("customerList.txt",ios::in);
if(file.is_open()){
        system("cls");
cout<<"customer Name Phone Number\n";
file>>cust_data.C_name>>cust_data.p_number;
 while(!file.eof()){
       setcolor(1);
cout<<cust_data.C_name;setcolor(6);cout<<"\t\t"<<cust_data.p_number<<endl;
file>>cust_data.C_name>>cust_data.p_number;
 }
 file.close();
}
}
void Item::addItem(){
naming:
char addName[30];
bool new_name=true;
fstream file("storeData.txt",ios::app|ios::in);
if(file.is_open()){
       cout<<"\n\n\t\t---------------------------------\n";
cout<<"\t\t|\t\t\t\t|\n";
cout<<"\t\t|\t\t\t\t|\n";
cout<<"\t\t|\tName\t";cin>>addName;
cout<<"\t\t|\t\t\t\t|\n";
cout<<"\t\t|\t\t\t\t|\n";
cout<<"\t\t---------------------------------\n";
file>>name>>measurement>>quantity>>bought_price>>selling_price;
while(!file.eof()){
    if(strcmpi(addName,name)==0){
        new_name=false;
    }
file>>name>>measurement>>quantity>>bought_price>>selling_price;
}
file.close();
}
file.open("storeData.txt",ios::app);
if(file.is_open() && new_name==true){
        strcpy(name,addName);
cout<<"\t\t---------------------------------\n";
cout<<"\t\t| Measurement\t";cin>>measurement;
cout<<"\t\t| Quantity\t";cin>>quantity;
cout<<"\t\t| Bought price\t";cin>>bought_price;
cout<<"\t\t| selling price\t";cin>>selling_price;
cout<<"\n\n\t\t\t---------------------------------------------\n";
cout<<"\t\t\t\t"<<name<<" successfully added to store\n";
cout<<"\t\t\t---------------------------------------------\n";
file<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
file.close();
}else{
    system("cls");
    setcolor(4);
cout<<"Item with this name exist. Assign other name \n";setcolor(7);
goto naming;
}
}
void Item::updateItem(){
//system("cls");
fstream file,file1;
char M_Name[30];
file.open("storeData.txt",ios::in);
if(!file) {setcolor(4);
    cout<<"file not present ";setcolor(7);
    file.close();
}else{
    int found=0;
cout<<"\n\n\t\t---------------------------------\n";
cout<<"\t\t|\t\t\t\t|\n";
cout<<"\t\t|\tName\t";cin>>M_Name;
cout<<"\t\t|\t\t\t\t|\n";
cout<<"\t\t---------------------------------\n";
    file1.open("Data.txt",ios::app|ios::out);
    file>>name>>measurement>>quantity>>bought_price>>selling_price;
    while(!file.eof()){
            //check if old name exist in the file then change
        if(strcmpi(M_Name,name)!=0){
            file1<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
        }else{
        cout<<"\t\t\tItem found\t"<<name<<endl;
        cout<<"\t\t\t Quantity\t";cin>>quantity;
        cout<<"\t\t\t Bought price\t";cin>>bought_price;
        cout<<"\t\t\t selling price\t";cin>>selling_price;
        file1<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
        cout<<"\n\n\t\t---------------------------------------------\n";
        cout<<"\t\t\t"<<name<<" successfully updated\n";
        cout<<"\t\t---------------------------------------------\n";
        found++;
        }
        file>>name>>measurement>>quantity>>bought_price>>selling_price;
    }if(found==0){
        system("cls");
        setcolor(4);
            cout<<"no Item is found\n";setcolor(7);
            displayItem();
            updateItem();
        }
    file1.close();
    file.close();
    remove("storeData.txt");
    rename("Data.txt","storeData.txt");
}

}
void Item::displayItem(){
fstream file("storeData.txt",ios::app|ios::in);
if(file.is_open()){

cout<<"Item name   Measurement   Quantity       bought price       selling price\n";
file>>name>>measurement>>quantity>>bought_price>>selling_price;
 while(!file.eof()){

     cout<<setcolor(2)<<name<<"\t\t"<<setcolor(6)<<measurement<<"\t\t"<<setcolor(2)<<quantity<<"\t\t"<<setcolor(6)<<bought_price<<"\t\t"<<setcolor(2)<<selling_price<<"\n";
      file>>name>>measurement>>quantity>>bought_price>>selling_price;
 }
 file.close();
}
setcolor(7);
}
void Item::addQuantity(){
fstream file,file1;
char M_Name[30];
file.open("storeData.txt",ios::in);
if(!file) {
        setcolor(4);
    cout<<"file not present ";setcolor(7);
    file.close();
}else{
    int found=0;
    cout<<"\n\n\t\t---------------------------------\n";
    cout<<"\t\t|\t\t\t\t|\n";
    cout<<"\t\t|\tName\t";cin>>M_Name;
    cout<<"\t\t|\t\t\t\t|\n";
     cout<<"\n\n\t\t---------------------------------\n";
    file1.open("Data.txt",ios::app|ios::out);
    file>>name>>measurement>>quantity>>bought_price>>selling_price;
    while(!file.eof()){
        if(strcmpi(M_Name,name)!=0){
            file1<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
        }else{
            int Add_Quantity;
            system("cls");
            cout<<"\n\n\t\t---------------------------------\n";
    cout<<"\t\t|\t\t\t\t|\n";
    cout<<"\t\t|\tName\t"<<name<<endl;
    cout<<"\t\t|\t\t\t\t|\n";
     cout<<"\t\t---------------------------------\n";
        cout<<"\t\t\t Quantity\t";cin>>Add_Quantity;
        cout<<"\t\t\t selling price\t";cin>>selling_price;
        quantity=quantity+Add_Quantity;
        file1<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
        found++;
        cout<<"\n\n\t\t---------------------------------------------\n";
        cout<<"\t\t\t"<<name<<" successfully added\n";
        cout<<"\t\t---------------------------------------------\n";
        }
        file>>name>>measurement>>quantity>>bought_price>>selling_price;
    }if(found==0){
                   setcolor(4);
                   system("cls");
            cout<<"no Item is found\n";setcolor(7);
            displayItem();
            addQuantity();
        }
    file1.close();
    file.close();
    remove("storeData.txt");
    rename("Data.txt","storeData.txt");
}
}
void Item::buyItem(){
     {
    fstream customer("customerList.txt",ios::in);
            char cust_name[30];
            int cust_phone;
            bool new_cus=true;
cout<<"\n\n\t\t\t**************************************\n";
cout<<"\t\t\t* \t\t\t\t     *\n";
cout<<"\t\t\t* \t\t\t\t     *\n";
cout<<"\t\t\t* customer userName:  ";cin>>cust_data.C_name;
cout<<"\t\t\t* customer phone Number:  ";cin>>cust_data.p_number;
      if(customer.is_open()){
      customer>>cust_name>>cust_phone;
            while(!customer.eof()){
                    if(strcmpi(cust_name,cust_data.C_name)==0&& cust_phone==cust_data.p_number) new_cus=false;
            customer>>cust_name>>cust_phone;
            }
            customer.close();
      }
      customer.open("customerList.txt",ios::app);
            if(customer.is_open()&&new_cus==true){
                    customer<<cust_data.C_name<<" "<<cust_data.p_number<<"\n";
                        customer.close();
            }
      }
    // 2D vector for receipt purpose
    vector<vector<string>> bought;
    string S_qua,S_price,S_cost;
    double totalCost=0;
sell:
system("cls");
if(totalCost>0){
        setcolor(5);
    cout<<"Total cost: "<<totalCost<<endl;setcolor(7);
}
{//show available item in store
fstream store("storeData.txt",ios::in);
    if(store.is_open()){
    cout<<" Item name   Measurement   Available Quantity        selling price\n";
    store>>name>>measurement>>quantity>>bought_price>>selling_price;
     while(!store.eof()){
            if(quantity>0){
                cout<<setcolor(6)<<name<<"\t\t"<<measurement<<"\t\t"<<setcolor(3)<<quantity<<"\t\t\t"<<setcolor(2)<<selling_price<<"\n";
            }
          store>>name>>measurement>>quantity>>bought_price>>selling_price;
     }
     store.close();
    }
setcolor(7);
}
char purchase[30];
cout<<"Enter the name of the item you want to purchase ";cin>>purchase;
fstream Data("storeData.txt",ios::in);
fstream updateStore("Data.txt",ios::app|ios::out);
if(Data.is_open()){
    bool available=false;
   Data>>name>>measurement>>quantity>>bought_price>>selling_price;
   while(!Data.eof()){
       //check the item from file line by line if not same copy to updateStore file
       //else modify its quantity and copy to updateStore file
    if(strcmpi(purchase,name)!=0){
         updateStore<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
    }else{
        available=true;
        if(quantity==0){
                setcolor(4);
                cout<<"item is not available now\n";setcolor(7);
        }else{
         cout<<"your preference is "<<name<<" and its cost is "<<selling_price<<endl;
         Qua:
        double CusQuantity;
        cout<<"How many of "<<name<<" do you need? ";cin>>CusQuantity;
        if(CusQuantity<=quantity){
            //add bought item to the vector
            if(CusQuantity!=0){
                vector<string>row;
                double cost=CusQuantity*selling_price;
           totalCost+=cost;
           cout<<"cost is "<<cost<<endl;
           cout<<"Total price is "<<totalCost<<endl;
           S_qua=to_string(roundf(CusQuantity));
           S_cost=to_string(cost);
           S_price=to_string(selling_price);
           string ss_qua=S_qua.substr(0,S_qua.find(".")+3);
           string ss_price=S_price.substr(0,S_price.find(".")+3);
           string ss_cost=S_cost.substr(0,S_cost.find(".")+3);
           row.push_back(name);
           row.push_back(ss_qua);
           row.push_back(ss_price);
           row.push_back(ss_cost);
           bought.push_back(row);
            quantity=quantity-CusQuantity;
            double profit=CusQuantity*(selling_price-bought_price);
            soldItem(name,CusQuantity,bought_price,selling_price,profit);
            }
        }else{
            setcolor(4);
        cout<<"We have no "<<CusQuantity<<" amount of "<<name<<" in the store.";setcolor(7);cout<<" Please enter the amount again ";goto Qua;
        }

     updateStore<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
    }
    }
    Data>>name>>measurement>>quantity>>bought_price>>selling_price;
   }
   if(available==false){
        setcolor(4);
    cout<<"Item is not available in our store\n";setcolor(7);
   }
    Data.close();
    updateStore.close();
    remove("storeData.txt");
    rename("Data.txt","storeData.txt");
}
 char other;
 setcolor(2);
        cout<<"Do you want to purchase other Item \npress Y or y For yes other key for stop ";cin>>other;
       setcolor(7);
        if(other=='y' |other=='Y'){
        goto sell;
        }else{
        system("cls");
        cout<<"\n\n\t\t\t***********************************************\n\n";
         cout<<"\t\t\tThank you for visiting us "<<cust_data.C_name<<"\n ";
         cout<<"\n\n\t\t\t**********************************************\n";
          if(totalCost>0){
              //receipt print
                 cout<<"Item\t quantity\t   price\t total\n";
                    for(int i=0;i<bought.size();i++){
                    for(int j=0;j<4;j++){
                            setcolor(j+1);
                                 cout<<bought[i][j]<<" \t   ";
                            }
                             cout<<endl;
                    }
                    setcolor(7);
            cout<<"\n\n\n\t\t\t\t Total cost:  "<<totalCost<<endl;
        }
        }
}

void Item::soldItem(char Sname[30],int Squa,double SBprice,double SSprice,double Profit){
fstream soldFile("soldData.txt",ios::app);
if(soldFile.is_open()){
     time_t current=time(0);
     tm *dt=localtime(&current);
    soldFile<<Sname<<" "<<Squa<<" "<<SBprice<<" "<<SSprice<<" "<<Profit<<" "<<dt->tm_mday<<"/"<<dt->tm_mon+1<<"/"<<1900+dt->tm_year<<"\n";
    soldFile.close();
}

}
void Item::DisplaySold(){
fstream soldFile("soldData.txt",ios::in);
double profit;
double Total_profit=0;
char Time[30];
if(soldFile.is_open()){
soldFile>>name>>quantity>>bought_price>>selling_price>>profit>>Time;
cout<<"Name\tQuantity\tBought price\tSelling Price\tProfit\t\tTime\n";
while(!soldFile.eof()){
        cout<<name<<" \t"<<setcolor(3)<<quantity<<" \t\t"<<setcolor(2)<<bought_price<<"\t\t "<<setcolor(8)<<selling_price<<"\t\t "<<setcolor(2)<<profit<<"\t\t "<<setcolor(8)<<Time<<endl;
    Total_profit+=profit;
    soldFile>>name>>quantity>>bought_price>>selling_price>>profit>>Time;
}
soldFile.close();
}
cout<<"\n\n\t\t\t\t\t\t\t\t Total profit: "<<setcolor(5)<<Total_profit<<endl;setcolor(7);
}

int main(){
    Item project;
    project.main_page();
}
