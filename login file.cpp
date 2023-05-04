#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void login();
void regstr();
void forgot();
int main()
{
	int ch;
	cout << "1.Login\n2.Register\n3.Forgot credential\nEnter your choice:";
	cin >> ch;
	
	switch(ch)
	{
		case 1:
			login();
			break;
		case 2:
			regstr();
			break;
		case 3:
			forgot();
			break;
		default:
			cout << "Sorry, wrong choice selected." << endl;
	}
	
	cout << endl;
	int x;
	cout << "Enter non-integer to continue:";
	cin >> x;
	
	if(x)
	{
		main();
	}
	else
	{
		return 0;
	}
}

void regstr()
{
	int t = 0;
	string usr,pas,u,p;
	system("cls");
	cout << "Enter username:";
	cin >> usr;
	ofstream write("username.txt",ios::app); // username file created which of append type 
	ifstream read("username.txt");
	while(read >> u >> p)
	{
		if(u == usr)
		{
			t = 1;
			break;
		}
	}
	if(t == 1)
	{
		cout << "Username is already taken." << endl;
	}
	else
	{
		cout << "Enter password:";
		cin >> pas;
		write << usr << " " << pas << endl;
		cout << "Registration is successfull." << endl;
	}
	write.close();
}

void login()
{
	int t = 0;
	string usr,pas,u,p;
	cout << "Enter the username: ";
	cin >> usr;
	cout << "Enter the password: ";
	cin >> pas;
	ifstream read("username.txt"); //ifstream uses here for reading the file
	while(read >> u >> p) // while loop uses here for reading the file till end and in each iteration registered username and password store in u and p respectively
	{
		if(u == usr && p == pas)
		{
			t = 1;
			break;
		}
	}
	read.close();
	if(t == 1)
	{
		cout << "Login successfull" << endl;
	}
	else
	{
		cout << "\nUsername or password incorrect.\nPlease try again." << endl;
	}
}
void forgot()
{
	int ch;
	system("cls");
	cout << "1.Search your account by username\n2.Search Your account by password\n3.Mainmenu\n4.Enter your choice:";
	cin >> ch;
	switch(ch)
	{
		case 1:
			{
				int t = 0;
				string su,u,p;
				cout << "Enter your remembered username:";
				cin >> su;
				ifstream read("username.txt");
				while(read >> u >> p)
				{
					if(su == u)
					{
						t = 1;
						break;
					}
				}
				read.close();
				if(t == 1)
				{
					cout << "Congrats! account found\nPassword is: " << p << endl;
				}
				else
				{
					cout << "Sorry, account not found" << endl;
				}
				break;
			}
		case 2:
			{
				int t = 0;
				string sp,u,p;
				cout << "Enter your remembered password:";
				cin >> sp;
				ifstream read("username.txt");
				while(read >> u >> p)
				{
					if(sp == p)
					{
						t = 1;
						break;
					}
				}
				read.close();
				if(t == 1)
				{
					cout << "Congrats! account found\nUsername is: " << u << endl;
				}
				else
				{
					cout << "Sorry, account not found" << endl;
				}
				break;
			}
	    case 3:
		    {
		    	cout << endl;
		    	main();
		    	break;
			}
		default:
			{
				cout << "Wrong choice selected.press a key to try again!" << endl;
				forgot();
			}
			
	}
}

