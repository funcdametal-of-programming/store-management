#include <iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;
class Item{
private:
    char name[30];
    int quantity;
    string measurement;
    double bought_price;
    double selling_price;
public:
    void main_page();
    void addItem();
    void updateItem();
    void displayItem();
    void addQuantity();
    void buyItem();
    void decQuantity(char M_Name[30],double qua);
    void customerList();
};
void Item::main_page(){
cout<<"\t\t\t Welcome to the shopping center \n";
cout<<"\t\t\t 1) Owner \n";
cout<<"\t\t\t 2) customer\n";
m:
int choice;
cout<<"Enter: ";cin>>choice;
if(choice==1){
string username,password;
cout<<"username\t";cin>>username;
cout<<"password\t";cin>>password;
            if(username=="abebe"&& password=="mycompany"){
      int service;
        cout<<"1) Add Item\n";
        cout<<"2) update Item\n";
        cout<<"3) Display Item\n";
        cout<<"4) Quantity add\n";
        cout<<"5) Quantity decrease\n";
        cout<<"6) Customer list\n";
        cout<<"which service you want to get: "; cin>>service;

        switch(service){
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                displayItem();
                break;
            case 4:
               addQuantity();
                break;
            case 5:
                char M_Name[30];
                double dec;
                cout<<"Enter name of the Item ";cin>>M_Name;
                cout<<"How many you want to remove from store ";cin>>dec;
                decQuantity(M_Name,dec);
                break;
            case 6:
                customerList();
                break;
            default:
                cout<<"please select from listed services";
}
}else{
        cout<<"unauthorized username and password\n";
        goto m;
}
}else if (choice==2){
     buyItem();
}
}
void Item::customerList(){
    // list customers
fstream file("customerList.txt",ios::in);
string c_name;
int p_num;
if(file.is_open()){
cout<<"customer Name Phone Number\n";
file>>c_name>>p_num;
 while(!file.eof()){
cout<<c_name<<"\t\t"<<p_num<<endl;
file>>c_name>>p_num;
 }
 file.close();
}
}
void Item::addItem(){
system("cls");
fstream file("storeData.txt",ios::app);
if(file.is_open()){
cout<<"Name\t";cin>>name;
cout<<"Measurement\t";cin>>measurement;
cout<<"Quantity\t";cin>>quantity;
cout<<"Bought price\t";cin>>bought_price;
cout<<"selling price\t";cin>>selling_price;
file<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
file.close();
}
}
void Item::updateItem(){
system("cls");
fstream file,file1;
char M_Name[30];
cout<<"\t\t\tItem name \n";
file.open("storeData.txt",ios::in);
if(!file) {
    cout<<"file not present ";
    file.close();
}else{
    int found=0;
    cout<<"Enter name of the Item ";cin>>M_Name;
    file1.open("Data.txt",ios::app|ios::out);
    file>>name>>measurement>>quantity>>bought_price>>selling_price;
    while(!file.eof()){
            //check if old name exist in the file then change
        if(strcmpi(M_Name,name)!=0){
            file1<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
        }else{
        cout<<"Item found\t"<<name<<endl;
        cout<<"Name\t";cin>>name;
        cout<<"Measurement\t";cin>>measurement;
        cout<<"Quantity\t";cin>>quantity;
        cout<<"Bought price\t";cin>>bought_price;
        cout<<"selling price\t";cin>>selling_price;
        file1<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
        found++;
        }
        file>>name>>measurement>>quantity>>bought_price>>selling_price;
    }if(found==0){
            cout<<"no Item is found\n";
        }
    file1.close();
    file.close();
    remove("storeData.txt");
    rename("Data.txt","storeData.txt");
}

}
void Item::displayItem(){
   // system("cls");
fstream file("storeData.txt",ios::in);
if(file.is_open()){

cout<<"Item name   Measurement   Quantity       bought price       selling price\n";
file>>name>>measurement>>quantity>>bought_price>>selling_price;
 while(!file.eof()){

     cout<<name<<"\t\t"<<measurement<<"\t\t"<<quantity<<"\t\t"<<bought_price<<"\t\t"<<selling_price<<"\n";
      file>>name>>measurement>>quantity>>bought_price>>selling_price;
 }
 file.close();
}
}
void Item::addQuantity(){
system("cls");
fstream file,file1;
char M_Name[30];
cout<<"\t\t\tItem name \n";
file.open("storeData.txt",ios::in);
if(!file) {
    cout<<"file not present ";
    file.close();
}else{
    int found=0;
    cout<<"Enter name of the Item ";cin>>M_Name;
    file1.open("Data.txt",ios::app|ios::out);
    file>>name>>measurement>>quantity>>bought_price>>selling_price;
    while(!file.eof()){
        if(strcmpi(M_Name,name)!=0){
            file1<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
        }else{
            int Add_Quantity;
        cout<<"Item found\t"<<name<<endl;
        cout<<"Quantity\t";cin>>Add_Quantity;
        cout<<"selling price\t";cin>>selling_price;
        quantity=quantity+Add_Quantity;
        file1<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
        found++;
        }
        file>>name>>measurement>>quantity>>bought_price>>selling_price;
    }if(found==0){
            cout<<"no Item is found\n";
        }
    file1.close();
    file.close();
    remove("storeData.txt");
    rename("Data.txt","storeData.txt");
}
}
void Item::buyItem(){
    // 2D vector for receipt purpose
    vector<vector<string>> bought;
    string S_qua,S_price,S_cost;
    double totalCost=0;
    string userName;
     {
    fstream customer("customerList.txt",ios::app);
    int phoneNumber;
      cout<<"customer userName:  ";cin>>userName;
      cout<<"customer phone Number:  ";cin>>phoneNumber;
      if(customer.is_open()){
        customer<<userName<<" "<<phoneNumber<<"\n";
        customer.close();
      }
    }
sell:
system("cls");
if(totalCost>0){
    cout<<"Total cost: "<<totalCost<<endl;
}
{//show available item in store
fstream store("storeData.txt",ios::in);
    if(store.is_open()){
    cout<<" Item name   Measurement   Available Quantity        selling price\n";
    store>>name>>measurement>>quantity>>bought_price>>selling_price;
     while(!store.eof()){
         cout<<name<<"\t\t"<<measurement<<"\t\t"<<quantity<<"\t\t"<<selling_price<<"\n";
          store>>name>>measurement>>quantity>>bought_price>>selling_price;
     }
     store.close();
    }
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
        cout<<"your preference is "<<name<<" and its cost is "<<selling_price<<endl;
         Qua:
        double CusQuantity;
        cout<<"How many of "<<name<<" do you need? ";cin>>CusQuantity;
        if(CusQuantity<=quantity){
            //add bought item to the vector
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
        }else{
        cout<<"We have no "<<CusQuantity<<" amount of "<<name<<" in the store. Please enter the amount again ";goto Qua;
        }
     updateStore<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
    }
    Data>>name>>measurement>>quantity>>bought_price>>selling_price;
   }
   if(available==false){
    cout<<"Item is not available in our store\n";
   }
    Data.close();
    updateStore.close();
    remove("storeData.txt");
    rename("Data.txt","storeData.txt");
}
 char other;
        cout<<"Do you want to purchase other Item \npress Y or y For yes other key for stop ";cin>>other;
        if(other=='y' |other=='Y'){
        goto sell;
        }else{
        system("cls");
         cout<<"Thank you for visiting us "<<userName<<"\n ";
          if(totalCost>0){
              //receipt print
                 cout<<"Item\t quantity\t   price\t total\n";
                    for(int i=0;i<bought.size();i++){
                    for(int j=0;j<4;j++){
                            cout<<bought[i][j]<<"  \t   ";
                            }
                        cout<<endl;
                    }
            cout<<"\t\t\t\t Total cost:  "<<totalCost<<endl;
        }
        }
}
void Item::decQuantity(char M_Name[30],double qua){
    //decrease the quantity intentionally by owner
fstream store("storeData.txt",ios::in);
fstream updateStore("Data.txt",ios::app|ios::out);
if(store.is_open()){
    store>>name>>measurement>>quantity>>bought_price>>selling_price;
    while(!store.eof()){
     if(strcmpi(M_Name,name)!=0){
            updateStore<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
        }else{
         quantity=quantity-qua;
         updateStore<<name<<" "<<measurement<<" "<<quantity<<" "<<bought_price<<" "<<selling_price<<"\n";
        }
        store>>name>>measurement>>quantity>>bought_price>>selling_price;
}
    store.close();
    updateStore.close();
    remove("storeData.txt");
    rename("Data.txt","storeData.txt");
}
}
int main(){
    Item project;
    project.main_page();
}
