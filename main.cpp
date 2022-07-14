#include <bits/stdc++.h>
using namespace std;
//Phone directory program using linked list and file handling
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
fstream fileobject;
struct node
{
//parts of a node.
string name;
string number;
string id;
node*next;
node()
{
next=NULL;
}
};
class contacts
{
//pointers to handle the linklist
node *first,*p,*t;
public:
contacts()
{

first=NULL;
}
//function to create nodes
void creat_file (string nameInput,string numberInput,string idInput)
{
//create 1st node...
if(first==NULL)
{
first=new node;
first->next=NULL;
first->name=nameInput;
first->number=numberInput;
first->id=idInput;
fileobject.open ("phonebook.txt",ios::out | ios::app);
fileobject<<"Name :"<<first->name<<"|ID:"<<first->id<<" |PhoneNumber: 
"<<first->number<<endl;
fileobject.close();
}
//to create new node..
else
{
p=first;
while(p->next!=NULL)
{
p=p->next;
}
t=new node;

t->name=nameInput;
t->number=numberInput;
t->id=idInput;
t->next=NULL;
p->next=t;
fileobject.open ("phonebook.txt",ios::out| ios::app);
fileobject<<"Name :"<<t->name<<"|ID:"<<t->id<<" |PhoneNumber:"<<t-
>number<<endl;
fileobject.close();
}
}
void terminating_file(string nameInput)
{
p=first;
if(first->name==nameInput)
{
t=first;
first=first->next;
delete t;
}
else
{
while(p->name!=nameInput)
{
if(p->next==NULL)
{
cout<<"Any case of "<<nameInput<<" does not exist"<<endl;
return ;
}

t=p;
p=p->next;
}
t->next=p->next;
delete p;
}
 /* t = NULL;
 p = first;
 if(first->name == nameInput){
 first = first->next;
 delete(p);
 }else{
 while(p!=NULL){
 t=p;
 p=p->next;
 if(p->name == nameInput){
 t->next=p->next;
 delete(p);
 }
 }
}
return; */
}
//print data of the linklist.
void print_now()
{
p=first;
int c;

cout<<"Person #"<<" ---> Name \tNumber \tID"<<endl;
for(c=1;p->next!=NULL;c++)
{
cout<<"Person "<<c<<" ---> "<<p->name<<"\t"<<p->number<<"\t"<<p-
>id<<endl;
p=p->next;
}
cout<<"Person "<<c<<" ---> "<<p->name<<"\t"<<p->number<<"\t"<<p-
>id<<endl;
}
void search(string nameInput)
{
p=first;
while(p!=NULL)
{
if(p->name==nameInput)
{
char mod;
cout<<"\n\t DATA FOUND \n\n";
cout<<"Name : "<<p->name<<endl;
cout<<"ID : "<<p->id<<endl;
cout<<"Phone # : "<<p->number<<endl;
cout<<"\nDo You want to modify Phone Number (y/n) : ";
cin>>mod;
if(mod=='y' || mod=='Y')
{
cout<<"Enter New Phone Number ";
cin>>p->number;

cout<<"\n\t Data Updated "<<endl;
}
break;
}
p=p->next;
}
if(p==NULL){
cout<<"\n\t DATA NOT FOUND \n\n";
}
}
void print(){
//this function reads the data from file
string s;
fileobject.open("phonebook.txt",ios::in);
while(!fileobject.eof())
{
fileobject>>s;
cout<<s<<endl;
}
fileobject.close();
}
};
int main()
{
contacts mainObject;
int nooffiles,i,p,choice;
string nameInput , numberInput, idInput;

cout<<"\n\t===============================================\n\
n";
cout<<"\t\t\t PHONEBOOK \n";
cout<<"\n\t===============================================\n\
n";
cout<<"\n\t===============================================\n\
n";
cout<<"\n\t1- CAN SAVE CONTACTS\n";
cout<<"\n\t2- CAN SEARCH AND UPDATE THE CONTACTS\n";
cout<<"\n\t3- CAN DELETE CONTACTS\n";
cout<<"\n\t4- CAN SEE THE CONTATCS LIST ANY TIME\n";
cout<<"\n\t=================================================
\n\n";
cout<<"\n\t========================SAVE 
NUMBER==============\n"<<endl;
//no. of files.
cout<<"\t how many contacts you want to add?"<<endl;
cin>>nooffiles;
//create/save data of each member....function call pass data..
for(i=1;i<=nooffiles;i++)
{
cout<<"\n\t Enter Name : \t";
cin.ignore();
getline(cin, nameInput);
cout<<"\n\tEnter Phone number : \t";
cin>>numberInput;
cout<<"\n\tEnter ID : \t";
cin>>idInput;

mainObject.creat_file(nameInput,numberInput,idInput);
}
system("CLS");
do
{
cout<<"\n\n What You want to do with your cases now?"<<endl;
cout<<"\n 1 - Add new contact\n";
cout<<" 2 - Delete a contact"<<endl;
cout<<" 3 - Search and Modify a contact"<<endl;
cout<<" 4 - See the contacts list"<<endl;
cout<<" 5 - Exit \n"<<endl;
cin>>choice;
system("CLS");
switch(choice)
{
case 1:
cout<<"\n\t============================SAVE NEW 
NUMBER============================\n\n";
cout<<" Enter following Data to save new contact'"<<endl;
cout<<"\n Enter Name : \t";
cin.ignore();
getline(cin,nameInput);
cout<<"\n Enter Phone number : \t";
cin>>numberInput;
cout<<" Enter ID : \t";
cin>>idInput;
mainObject.creat_file(nameInput,numberInput,idInput);

cout<<"Phone Number of "<<nameInput<<" has been added to your contacts 
list"<<endl;
break;
case 2:
cout<<"\n\t=========================DELETE 
NUMBER============================\n\n";
cout<<"\n Enter name of the person whose contact you want to delete 
\n"<<endl;
cin.ignore();
getline(cin,nameInput);
mainObject.terminating_file(nameInput);
cout<<"\n Number of "<<nameInput<<" has been deleted from your contacts 
list "<<endl;
break;
case 3:
cout<<"\n\t=====================SEARCH AND UPDATE 
NUMBER=====================\n\n";
cout<<"Enter name of the Person you wish to search/update\t";
cin>>nameInput;
mainObject.search(nameInput);
break;
case 4:
cout<<"\n\t=====================PRINTING YOUR 
PHONEBOOK============================\n\n";
mainObject.print();
break;
case 5:

cout<<"\n\t====================list of contacts added 
recently======================\n\n";
mainObject.print_now();
break;
default:
cout<<"\t----------Invalid----------"<<endl;
}
}while(choice!=5);
cout<<"\n THANK YOU "<<endl;
getch();
}
