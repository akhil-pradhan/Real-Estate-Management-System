#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<conio.h>
#include<sstream>
#include<algorithm>
#include<cctype>
using namespace std;

class realest
{
protected:
	string name,password,uid;
	public:
	virtual int login()=0;
	virtual void menu()=0;
	virtual	void see_account_details()=0;
	virtual void user_registration()=0;

};
//----------------------------------------------------------------------------------------------(New class)

class buyers:public realest
{
	vector <string> info_real;
	vector <string> ::iterator i;
	string real_det;
	public:
	void menu();
	int login();
	void user_registration();
	void see_real_estate();
	void see_account_details();
//	void payment_calculator();
	string long_to_string(long);
	void user_choice(string,string,ifstream&);
	string lowercase(string s);
};

void buyers::menu()
{
	int choice,a;
		system("CLS");
		cout<<"WELCOME TO REAL ESTATE MANAGEMENT SYSTEM "<<endl;
		cout<<"1.User Registraion"<<endl;
		cout<<"2.See Available real estate"<<endl;
		cout<<"3.Return to main menu"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				cout<<"1.Sign up"<<endl;
				cout<<"2.See your details"<<endl;
				cout<<"3.Return to previous menu"<<endl;
				cin>>a;
				if(a==1)
				{
					user_registration();
					break;
				}
				else if(a==2)
				{
					see_account_details();
					break;
				}
				else
				{
					break;//to be modified
				}
			}
			case 2:
			{
				see_real_estate();
				break;
			}
			default:
			{
				break;
			}
		}
}

void buyers::user_registration()
{
		char ch;
		long uid_demo;

		system("CLS");
		cout<<"Enter your details :-"<<endl;
		cout<<"Name"<<endl;
		cin>>name;
		cout<<"Enter the password:"<<endl;
		ch=_getch();
		while(ch!=13)
		{
			password.push_back(ch);
			cout<<"*";
			ch=_getch();
		}
		cout<<endl;
		srand(time(NULL));
		uid_demo=rand()%9999999999+1;//create any number i.e.,5 digit
		uid=long_to_string(uid_demo);

		ofstream data("database_buyers.csv",ios::app);
		data<<uid<<","<<name<<","<<password<<endl;
		cout<<"-----Your Unique Identification code is="<<uid<<endl;
		data.close();
}

int buyers::login()
{
	string _uid,pass;
	char ch;
	int count;

	cout<<"Enter the Unique identification code "<<endl;
	cin>>_uid;
	cout<<"Enter the password:"<<endl;
	ch=_getch();
	while(ch!=13)
	{
		pass.push_back(ch);
		cout<<"*";
		ch=_getch();
	}
	cout<<endl;
	ifstream check("database_buyers.csv");
	while(check.good())
	{
		getline(check,uid,',');
		getline(check,name,',');
		getline(check,password,'\n');

		if(uid==_uid&&password==pass)
		{
			count=1;
		}
	}
	if(count==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	check.close();
}

void buyers::see_real_estate()
{
	system("ClS");
	string city1,demo_city;
	string type1,demo_type;
	int choice;
	int _log;
	_log=login();
	if(_log==1)
	{
		cout<<"WELCOME TO REAL ESTATE MANAGEMENT SECTION"<<endl;
		cout<<"1.BUY"<<endl;
		cout<<"2.RENT"<<endl;
		cout<<"3.Back to previous menu"<<endl;
		cin>>choice;
		if(choice==1)
		{
				cout<<"Enter the city"<<endl;
				cin>>demo_city;
				city1=lowercase(demo_city);
				cout<<"Enter the type of real estate:"<<endl;
				cin>>demo_type;
				type1=lowercase(demo_type);
				ifstream r1("real_buy.csv");
				user_choice(city1,type1,r1);
				r1.close();
		}
		else if(choice==2)
		{
				cout<<"Enter the city"<<endl;
				cin>>city1;
				cout<<"Enter the type of real estate:"<<endl;
				cin>>type1;
				ifstream r1("real_rent.csv");
				user_choice(city1,type1,r1);
				r1.close();
		}
	}
	else
	{
		cout<<"Your account is not in the database"<<endl;
	}
}

void buyers::see_account_details()
{
	string _uid,pass;
	char ch;
	int count=0;

	cout<<"Enter the Unique identification code "<<endl;
	cin>>_uid;
	cout<<"Enter the password:"<<endl;
	ch=_getch();
	while(ch!=13)
	{
		pass.push_back(ch);
		cout<<"*";
		ch=_getch();
	}
	cout<<endl;
	ifstream check("database_buyers.csv");
	while(check.good())
	{
		getline(check,uid,',');
		getline(check,name,',');
		getline(check,password,'\n');
		if(uid==_uid&&password==pass)
		{
			cout<<"You account is detected"<<endl;
			cout<<"UID\t\tNAME\t\tPASSWORD"<<endl;
			cout<<uid<<"\t\t"<<name<<"\t\t"<<password<<endl;
			count=1;
		}
	}
	check.close();
	if(count==0)
	{
		cout<<"YOUR ACCOUNT IS NOT IN THE DATABASE"<<endl;
		count=0;
	}
}

string buyers::long_to_string(long a)
{
  ostringstream outstr;
  outstr<<a;
  return outstr.str();
}

void buyers::user_choice(string city1,string type1,ifstream& r1)
{
	int it,it1;
	it=it1=0;
	system("CLS");
	cout<<"WELCOME TO REAL ESTATE SEARCH ENGINE"<<endl;
	cout<<"Available real estate options are\n"<<endl;
	cout<<"REAL ESTATE ID\tCITY\tAREA\tTYPE\tCOST\tADDRESS"<<endl;//things to be added
	while(r1.good())
	{
		getline(r1,real_det,',');//0
		info_real.push_back(real_det);
		getline(r1,real_det,',');//1
		info_real.push_back(real_det);
		getline(r1,real_det,',');//2
		info_real.push_back(real_det);
		getline(r1,real_det,',');//3
		info_real.push_back(real_det);
		getline(r1,real_det,',');//4
		info_real.push_back(real_det);
		getline(r1,real_det,',');//5
		info_real.push_back(real_det);
		getline(r1,real_det,',');//6
		info_real.push_back(real_det);
		getline(r1,real_det,',');//7
		info_real.push_back(real_det);
		getline(r1,real_det,',');//8
		info_real.push_back(real_det);
		getline(r1,real_det,',');//9
		info_real.push_back(real_det);
		getline(r1,real_det,',');//10
		info_real.push_back(real_det);
		getline(r1,real_det,',');//11
		info_real.push_back(real_det);
		getline(r1,real_det,'\n');//12
		info_real.push_back(real_det);
		i = find (info_real.begin(), info_real.end(), city1);
  	if (i != info_real.end())
    it++;

		i = find (info_real.begin(), info_real.end(),type1);
		if (i != info_real.end())
		it1++;

		if(it==1&&it1==1)
			{
				for(i=info_real.begin();i!=info_real.end();++i)
				{
					cout<<*i<<"\t";
				}
				cout<<endl;
			}
			it=it1=0;
		info_real.clear();
	}
}
string buyers::lowercase(string s)
{
  string r=s;
  for(int i=0;i<r.length();i++)
  r[i]=tolower(r[i]);
  return r;
}
//----------------------------------------------------------------------------------------------(new class)
class sellers:public realest
{
	vector <string> seller_info;
	vector <string>::iterator i;
public:
	void menu();
	int login();
	void enter_data_real_estate();
	void see_account_details();
	void user_registration();
	string long_to_string(long);
	string lowercase(string s);
};

void sellers::menu()
{
	int choice,a;
		system("CLS");
		cout<<"WELCOME TO REAL ESTATE MANAGEMENT SYSTEM "<<endl;
		cout<<"1.User registraion"<<endl;
		cout<<"2.Enter the details of the real estate you want to sell"<<endl;
		cout<<"3.Return to main menu"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				cout<<"1.Sign up"<<endl;
				cout<<"2.See your details"<<endl;
				cout<<"3.Return to previous menu"<<endl;
				cin>>a;
				if(a==1)
				{
					cout<<endl;
					user_registration();
					break;
				}
				else if(a==2)
				{
					cout<<endl;
					see_account_details();
					break;
				}
				else
				{
					break;
				}
			}
			case 2:
			{
				cout<<endl;
				enter_data_real_estate();
				break;
			}
			default:
			{
				break;
			}
		}
}

int sellers::login()
{
	string _uid,pass;
	char ch;
	int count;

	cout<<"Enter the Unique identification code "<<endl;
	cin>>_uid;
	cout<<"Enter the password:"<<endl;
	ch=_getch();
	while(ch!=13)
	{
		pass.push_back(ch);
		cout<<"*";
		ch=_getch();
	}
	ifstream check("database_sellers.csv");
	while(check.good())
	{
		getline(check,uid,',');
		getline(check,name,',');
		getline(check,password,'\n');

		if(uid==_uid&&password==pass)
		{
			count=1;
			break;
		}
	}
	check.close();
	if(count==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void sellers::enter_data_real_estate()
{
	int ch;
	string a,city1,type1;
	long real_id;
	int _log;

	system("CLS");
	_log=login();
	cout<<endl;
	if(_log==1)
	{
		cout<<"Enter the Information of Real estate"<<endl;
		srand(time(NULL));
		real_id=rand()%999999999+1;

		a=long_to_string(real_id);
		seller_info.push_back(a);
		cout<<"Enter the CITY"<<endl;
		cin.ignore();
		getline(cin,a);
		city1=lowercase(a);
		seller_info.push_back(city1);
		cout<<"Type of real estate available:"<<endl;		//i.e.,single family home or bunglow or flat etc
		cin.ignore();
		getline(cin,a);
		type1=lowercase(a);
		seller_info.push_back(type1);
		cout<<"Enter the AREA(in sqft) of the real estate:"<<endl;
		cin>>a;
		seller_info.push_back(a);
		cout<<"Enter the ADDRESS of the real estate:"<<endl;
		cout<<"Enter the house no"<<endl;
		cin.ignore();
		getline(cin,a);
		seller_info.push_back(a);
		cout<<"Enter the street"<<endl;
		cin.ignore();
		getline(cin,a);
		seller_info.push_back(a);
		a="Active";
		seller_info.push_back(a);
		cout<<"Enter the Year of built:"<<endl;
		cin>>a;
		seller_info.push_back(a);
		cout<<"Enter the placement for setting up the landmark:"<<endl;
		cout<<"1.Enter the distance(in km) of the nearest school:"<<endl;
		cin>>a;
		seller_info.push_back(a);
		cout<<"2.Enter the distance(in km) of the nearset hospital:"<<endl;
		cin>>a;
		seller_info.push_back(a);
		cout<<"Enter any extra details of your real estate"<<endl;
		cin.ignore();
		getline(cin,a);
		seller_info.push_back(a);
		cout<<"Enter any local information of your real estate"<<endl;
		cin.ignore();
		getline(cin,a);
		seller_info.push_back(a);



		cout<<"The above real estate you want to:- \n1.'SELL' \nor\n 2.put on 'RENT'"<<endl;
		cin>>ch;

		if(ch==1)
		{
			cout<<"Enter the cost on which you want to sell"<<endl;
			cin>>a;
			seller_info.push_back(a);
			ofstream real("real_buy.csv",ios::app);
			for(i=seller_info.begin();i!=seller_info.end();++i)
			{
				real<<*i<<',';
			}
			real<<endl;
			real.close();
		}
		else if(ch==2)
		{
			cout<<"Enter the cost on which you want to rent(per month)"<<endl;
			cin>>a;
			seller_info.push_back(a);
			ofstream real("real_rent.csv",ios::app);
			for(i=seller_info.begin();i!=seller_info.end();++i)
			{
				real<<*i<<",";
			}
			real<<endl;
			real.close();
		}
		cout<<"Your details are successfully added to database";
	}
	else
	{
		cout<<"Your account is not in the database"<<endl;
	}
}

void sellers::see_account_details()
{
	string _uid,pass;
	char ch;
	int count=0;

	cout<<"Enter the Unique identification code "<<endl;
	cin>>_uid;
	cout<<"Enter the password:"<<endl;
	ch=_getch();
	while(ch!=13)
	{
		pass.push_back(ch);
		cout<<"*";
		ch=_getch();
	}
	cout<<endl;
	ifstream check("database_sellers.csv");
	while(check.good())
	{
		getline(check,uid,',');
		getline(check,name,',');
		getline(check,password,'\n');
		if(uid==_uid&&password==pass)
		{
			cout<<"You account is detected"<<endl;
			cout<<"UID\t\tNAME\t\tPASSWORD"<<endl;
			cout<<uid<<"\t\t"<<name<<"\t\t"<<password<<endl;
			count=1;
		}
	}
	check.close();
	if(count==0)
	{
		cout<<"YOUR ACCOUNT IS NOT IN THE DATABASE"<<endl;
		count=0;
	}
}

void sellers::user_registration()
{
	char ch;
	long uid_demo;

	system("CLS");
	cout<<"Enter your details :-"<<endl;
	cout<<"Name"<<endl;
	cin>>name;
	cout<<"Enter the password:"<<endl;
	ch=_getch();
	while(ch!=13)
	{
		password.push_back(ch);
		cout<<"*";
		ch=_getch();
	}
	cout<<endl;

	srand(time(NULL));
	uid_demo=rand()%9999999999+1;
	uid=long_to_string(uid_demo);

	ofstream data("database_sellers.csv",ios::app);
	data<<uid<<","<<name<<","<<password<<endl;
	cout<<"-----Your Unique Identification code is="<<uid<<endl;
	data.close();

}

string sellers::long_to_string(long a)
{
  ostringstream outstr;
  outstr<<a;
  return outstr.str();
}
string sellers::lowercase(string s)
{
  string r=s;
  for(int i=0;i<r.length();i++)
  r[i]=tolower(r[i]);
  return r;
}

//---------------------------------------------------------------------------------------------(new class)
class admin					//to manipulate the buyers and sellers data
{
	string pass;
public:
	admin()
	{
		pass="angelpriya";
	}
	void menu();
	void show_details_of_users();
	void show_real_estate();
};

void admin::menu()
{
	string pass_demo;
	int choice;
	char ch;
	cout<<"Enter the ADMIN's password"<<endl;
	ch=_getch();
	while(ch!=13)
	{
		pass_demo.push_back(ch);
		cout<<"*";
		ch=_getch();
	}
	cout<<endl;

	if(pass==pass_demo)
	{
			system("CLS");
			cout<<"----------WELCOME TO ADMIN ZONE--------"<<endl;
			cout<<"1.SHOW DETAILS OF CURRENT USER"<<endl;
			cout<<"2.SHOW REAL ESTATE ON DATABASE"<<endl;
			cout<<"3.Return to main menu"<<endl;
			cin>>choice;
			switch(choice)
			{
				case 1:
				{
					show_details_of_users();
					break;
				}
				case 2:
				{
					show_real_estate();
					break;
				}
				default:
				break;
			}
		}
		else
		{
			cout<<"You are not our respected admin bitch"<<endl;
		}
}

void admin::show_details_of_users()
{
	string uid,name,password;
	int choice;
	cout<<"-------WELCOME ADMIN-------"<<endl;
	cout<<"1.SEE DETAILS OF SELLERS"<<endl;
	cout<<"2.SEE DETAILS OF BUYERS "<<endl;
	cout<<"3.BACK TO MAIN MENU"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			ifstream check("database_sellers.csv");
			cout<<"THE DETAILS OF THE USERS REGISTERED UNDER SELLERS SECTION"<<endl;
			cout<<"UID\t\tNAME\t\tPASSWORD"<<endl;
			while(getline(check,uid,','))
			{
				getline(check,name,',');
				getline(check,password,'\n');

				cout<<uid<<"\t\t"<<name<<"\t\t"<<password<<endl;
			}
			check.close();
			break;
		}
		case 2:
		{
			ifstream check("database_buyers.csv");
			cout<<"THE DETAILS OF THE USERS REGISTERED UNDER BUYERS SECTION"<<endl;
			cout<<"UID\t\tNAME\t\tPASSWORD"<<endl;
			while(getline(check,uid,','))
			{

				getline(check,name,',');
				getline(check,password,'\n');

				cout<<uid<<"\t\t"<<name<<"\t\t"<<password<<endl;
			}
			check.close();
			break;
		}
		default:
		{
			break;
		}
	}
}

void admin::show_real_estate()
{
	vector <string> info_real;
	vector <string> ::iterator i;
	string real_det;
	int choice;
	cout<<"-------WELCOME ADMIN-------"<<endl;
	cout<<"1.SEE REAL ESTATE UNDER BUY SECTION"<<endl;
	cout<<"2.SEE REAL ESTATE UNDER RENT SECTION "<<endl;
	cout<<"3.BACK TO MAIN MENU"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			ifstream check("real_buy.csv");
			cout<<"THE DETAILS OF REAL ESTATE UNDER BUY SECTION"<<endl;
			cout<<"UID\t\tNAME\t\tPASSWORD"<<endl;//to be added
			while(check.good())
			{
				getline(check,real_det,',');//0
				info_real.push_back(real_det);
				getline(check,real_det,',');//1
				info_real.push_back(real_det);
				getline(check,real_det,',');//2
				info_real.push_back(real_det);
				getline(check,real_det,',');//3
				info_real.push_back(real_det);
				getline(check,real_det,',');//4
				info_real.push_back(real_det);
				getline(check,real_det,',');//5
				info_real.push_back(real_det);
				getline(check,real_det,',');//6
				info_real.push_back(real_det);
				getline(check,real_det,',');//7
				info_real.push_back(real_det);
				getline(check,real_det,',');//8
				info_real.push_back(real_det);
				getline(check,real_det,',');//9
				info_real.push_back(real_det);
				getline(check,real_det,',');//10
				info_real.push_back(real_det);
				getline(check,real_det,',');//11
				info_real.push_back(real_det);
				getline(check,real_det,'\n');//12
				info_real.push_back(real_det);
				for(i=info_real.begin();i!=info_real.end();++i)
				{
					cout<<*i<<"\t";
				}
				cout<<endl;
				info_real.clear();
			}
			check.close();
			break;
		}
		case 2:
		{
			ifstream check("real_rent.csv");
			cout<<"THE DETAILS OF REAL ESTATE UNDER RENT SECTION"<<endl;
			cout<<"UID\t\tNAME\t\tPASSWORD"<<endl;//to be added
			while(check.good())
			{
				getline(check,real_det,',');//0
				info_real.push_back(real_det);
				getline(check,real_det,',');//1
				info_real.push_back(real_det);
				getline(check,real_det,',');//2
				info_real.push_back(real_det);
				getline(check,real_det,',');//3
				info_real.push_back(real_det);
				getline(check,real_det,',');//4
				info_real.push_back(real_det);
				getline(check,real_det,',');//5
				info_real.push_back(real_det);
				getline(check,real_det,',');//6
				info_real.push_back(real_det);
				getline(check,real_det,',');//7
				info_real.push_back(real_det);
				getline(check,real_det,',');//8
				info_real.push_back(real_det);
				getline(check,real_det,',');//9
				info_real.push_back(real_det);
				getline(check,real_det,',');//10
				info_real.push_back(real_det);
				getline(check,real_det,',');//11
				info_real.push_back(real_det);
				getline(check,real_det,'\n');//12
				info_real.push_back(real_det);
				for(i=info_real.begin();i!=info_real.end();++i)
				{
					cout<<*i<<"\t";
				}
				cout<<endl;
				info_real.clear();
			}
			check.close();
			break;
		}
		default:
		{
			break;
		}
	}
}
//----------------------------------------------------------------------------------------------(main)
int main()
{
	realest *p;
	int a;
	while(1)
	{

				cout<<"--------Welcome to Real Estate Management System--------"<<endl;
				cout<<" 1.SELLER"<<endl;
				cout<<" 2.BUYER"<<endl;
				cout<<" 3.ADMIN"<<endl;
				cout<<" 4.EXIT"<<endl;
				cin>>a;
				if(a==1)
				{
					system("CLS");
					p=new sellers;
					p->menu();
					delete p;
				}
				else if(a==2)
				{
					system("CLS");
					p=new buyers;
					p->menu();
					delete p;

				}
				else if(a==3)
				{
					system("CLS");
					admin a;
					a.menu();
				}
				else
					exit(0);
	}
	return 0;
}
