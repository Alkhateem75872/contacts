/*namwe: mohammed kabashi hammad
class :second
department: computer*/

/*try to start it with other application like codeblock...*/

#include<fstream>
#include<string>
#include<iostream>
using namespace std;

class contact/*creat class of contact*/
{
	long ph;
	char FirstName[10],LastName[15],add[10],email[10];

	public:

	void create_contact()/*function to make contact information or set contact information*/
	{
		cout<<"Phone: ";
		cin>>ph;

		cout<<"FirstName: ";
		cin.ignore();
		cin>>FirstName;

		cout<<"LastName: ";
		cin.ignore();
		cin>>LastName;

		cout<<"Addresses: ";
		cin.ignore();
		cin>>add;

		cout<<"Email addresses: ";
		cin.ignore();
		cin>>email;
		cout<<"\n";
	}

	void show_contact() /*function to show or display contact information*/
	{
		cout<<endl<<"Phone : "<<ph;
		cout<<endl<<"First Name: "<<FirstName;
		cout<<endl<<"Last Name: "<<LastName;
		cout<<endl<<"Address: "<<add;
		cout<<endl<<"Email Address : "<<email;
	}
	/*functions to return PARAMETERS  values*/
	long getPhone()
	{
		return ph;
	}

	char* getFirstName()
	{
		return FirstName;
	}

	char* getLastName()
	{
		return LastName;
	}

	char* getAddress()
	{
		return add;
	}

	char* getEmail()
	{
		return email;
	}
};

fstream fp;
contact cont;



void show_all_contacts() /*FUNCTION TO BRINGS AND DISPLAYING ALL CONTACTS THAT ON THE FILE*/
{
	cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>\n\t\t\tLIST OF CONTACTS\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	fp.open("contactBook.txt",ios::in);
	while(fp.read((char*)&cont,sizeof(contact)))
	{
		cont.show_contact();
		cout<<endl<<"..............................."<<endl;
	}
	fp.close();
}
void display_contact(int num)/* function Searches for information for a specific contact*/
{
	bool found;
	int ch;

	found=false;
	fp.open("contactBook.txt",ios::in);
	while(fp.read((char*)&cont,sizeof(contact)))
	{
		if(cont.getPhone()==num)
		{
		cont.show_contact();
		found=true;
		}
	}
	fp.close();
	if(found == false){
	cout<<"\n\nNo record found...";}
	getchar();
}
void edit_contact()/*function to add modifications to a specific contact*/
{
	int num;
	bool found=false;

	cout<<"Edit contact\n....................\n\n\t::Enter the number of contact :";
	cin>>num;
	fp.open("contactBook.txt",ios::in|ios::out);
	while(fp.read((char*)&cont,sizeof(contact)) && found==false)
	{
		if(cont.getPhone()==num)
		{
			cont.show_contact();
			cout<<"\Enter the new information: "<<endl;
			cont.create_contact();
			long pos=-1*sizeof(cont);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&cont,sizeof(cont));
			cout<<endl<<endl<<"\t Information has been updated..\n\n";
			found=true;
		}
	}
	fp.close();
	if(found==false)
	cout<<endl<<endl<<"information Not Found...\n\n";
}
void delete_contact()/*A function to delete a contact*/
{
	int num;
	cout<<endl<<endl<<"Please Enter The contact #: ";
	cin>>num;
	fp.open("contactBook.txt",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.txt",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&cont,sizeof(contact)))
	{
		if(cont.getPhone()!=num)
		{
			fp2.write((char*)&cont,sizeof(contact));
		}
	}
}
bool screen()/*function to show and display main menu screen*/
{
	cout << "\n MAIN MENU\n........................ \n(1) Add a new Contact information \n (2) List all Contacts information \n (3) Search for contact information \n (4) edit a Contact information\n (5) Delete a Contact information\n(0)Exit\n.......................|\n\t\t";
	cout << "\n Enter the  number choice: ";

}

int main()/*main function*/
{
	int i;
	cout << "\n\n\t ... Welcome to Contact  System ....";

	while(screen())
	{
		cin >> i;

		switch (i)
		{
		case 0:
			cout << "\n\n\t\t :)\n\t\t................\n\t\t\n\n";
			return 0;
			break;

		case 1:
			show_all_contacts();
			break;
		case 2:
			int num;
			cout << "\n\n\tPhone: ";
			cin >> num;
			display_contact(num);
			break;
		case 3:
			edit_contact();
			break;

		case 4:
			delete_contact();
			break;
		default:
		cout<<"\nERROR : Wrong Choice! ,Try Again..\n";
			break;
		}
	}
	return 0;
}
