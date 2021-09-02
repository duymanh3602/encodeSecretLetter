//@duymanh3602 - 1/9/2021
#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

string enCode(int n);
string enCodeLetter(string s);
int deCode(string s);
string deCodeLetter(string s);

int main ()
{

    while (1)
    {
        system("cls");
    	cout<<"Menu Options:"<<endl;
	    cout<<"1. EnCode a \"SECRET\" letter"<<endl;
	    cout<<"2. DeCode a letter"<<endl;
	    cout<<"3. Exit"<<endl;
	    char g=getch();
	    if (g=='1')
	    {
	    	char choose='y';
	    	while (choose=='y')
	    	{
	    	    system("cls");
		        cout<<"EnCode a \"SECRET\" letter\nEnter your code: ";
		        string s;
		        getline(cin,s);
		        cout<<"Letter: \""<<s<<"\" after enCode is: "<<enCodeLetter(s);
		        cout<<"\nContinue? (y/n)"<<endl;
				choose=getch();
			}
		}
	    else if (g=='2')
	    {
	    	char choose='y';
	    	while (choose=='y')
	    	{
	    	    system("cls");
		        cout<<"DeCode a letter\nEnter your letter: ";
		        string s;
		        getline(cin,s);
		        cout<<"Letter: "<<s<<" after deCode is: "<<deCodeLetter(s);
		        cout<<"\nContinue? (y/n)"<<endl;
				choose=getch();
	        }
	    }
	    else if (g=='3')
            exit(0);
	}

}

string enCode(int n)
{
	string ans="";
	int i=0;
	while (i!=8)
	{
		ans=to_string(n%2)+ans;
		n/=2;
		i++;
	}
	return ans;
}

string enCodeLetter(string s)
{
	string ans="";
	for (int i=0;i<s.size();i++)
	{
		ans+=enCode((int)s[i]);
	}
	return ans;
}

int deCode(string s)
{
	int res=0;
	for (int i=0;i<8;i++)
	{
		res=res*2+(int)s[i]-48;
	}
	return res;
}

string deCodeLetter(string s)
{
	string temp="";
	string res="";
	for (int i=0;i<s.size();i++)
	{
		if (i%8==0&&i!=0)
		{
			res+=(char)(deCode(temp));
			temp="";
			temp+=s[i];
		}
		else
		{
			temp+=s[i];
		}
		if (i==s.size()-1)
        {
            res+=(char)(deCode(temp));
        }
	}
	return res;
}


