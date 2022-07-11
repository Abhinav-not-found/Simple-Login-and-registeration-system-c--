#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void menu(){
	
	
	
	cout<<"\t\t\t____________________________"<<endl;
	
	cout<<"\t\t\tWelcome to the Login Page"<<endl;
	
	cout<<"\t\t\t------------MENU------------"<<endl;
	
	cout<<"\t\t\t|Press 1 to LOGIN          |"<<endl;
	cout<<"\t\t\t|Press 2 to REGISTRATION   |"<<endl;
	cout<<"\t\t\t|Press 3 to RESET PASSWORD |"<<endl;
	cout<<"\t\t\t|Press 4 to EXIT           |"<<endl;
	
	
	
	
}

void Login();
void Registration();
void Reset();


int main(){
	int ch;
	menu();
	cout<<"\n\t\t\tEnter your choice : ";
	cin>>ch;
	cout<<endl;
	switch(ch){
		case 1:
			Login();
			break;
		case 2:
			Registration();
			break;
		case 3:
			Reset();
			break;
		case 4:
			cout<<"\t\t\t----------Thank You---------\n";
			break;
		default:
		
		 cout<<"\n\t\t\tPlease select from the options given above\n";
		 main();
	}
}



void Login(){
	int count;
	string userid,password,id,pass;
	cout<<"Please Enter the username and password : "<<endl;
	cout<<"USERNAME : " ;
	cin>>userid; 
	cout<<"\nPASSWORD : ";
	cin>>password;
	
	ifstream input("records.txt");
	while(input>>id>>pass){
		if(id==userid && pass==password){
			count=1;
		}
		
	}
	input.close();
	if(count == 1){
		cout<<"\nYour Login is successfull\n Thank you for logging in!\n";
		main();
	}
	else{
		cout<<"\nLOGIN ERROR: \n Please check your username and password\n";
		main();
	}
	

}




void Registration(){
	string ruserid,rpassword,rid,rpass;
	cout<<"Enter your username : ";
	cin>>ruserid;
	cout<<"Enter your password : ";
	cin>>rpassword; 
	ofstream  f1("records.txt", ios::app);
	f1<<ruserid<<' '<<rpassword<<endl;
	cout<<"\nRegistration is successfull! \n";
	main();
}



void Reset(){
	int option;
	cout<<"You forgot your password? No worries \n";
	cout<<"\nPress 1 to search your id by username "<<endl;
	cout<<"Press 2 to go back to the main menu "<<endl;
	cout<<"\nEnter your choice : ";
	cin>>option;
	cout<<endl;
	switch(option){
		case 1:{
			
			int count=0;
			string suserid, sid,spass;
			cout<<"Enter the username which you remembered : ";
			cin>>suserid;
			ifstream f2("records.txt");
			while(f2>>sid>>spass){
				if(sid==suserid){
					count=1;
				}
			}
			f2.close();	
			if(count==1){
				cout<<"Your account is found! ";
				cout<<"Your password is : "<<spass;
				cout<<endl;
				main();
			}
			else{
				cout<<"Sorry your account is not found!"<<endl;
				main();
			}
			break;
	        }
		case 2:{
			main(); 
				}	
		default:{
		
			cout<<"Wrong choice ! Pleas try again \n"<<endl;
			
			main();
		}
	}
	
}
