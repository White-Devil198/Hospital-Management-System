#include <iostream>
#include <cstdlib>
#include<fstream>
#include <Windows.h>
#include <string>
using namespace std;
struct info {
	string name, specialist, diseases, discription, gender, address, feild;
	int specialRoomNo, age, fee, date;
};
struct Node {
	info data;
	Node* next;

};
struct appoint {
	string name, diseases, gender, address, appoint_date;
	int specialRoomNo, age, fee, date, Number_of_times_visited;
};
struct node {
	appoint data;
	int priority = 10;
	node* next = NULL;
};
node* front = NULL;
bool isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}
void Color(int color)//to change colour
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void enqueue(int priority)
{
	string k, l, t;
	node* temp = new node;
	system("cls");

	Color(017);
	cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
	cout << "\t\t\t\t\t  ::";
	Color(2);
	cout << "       Enter Data";
	Color(017);
	cout << "             ::\n";
	cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";


	Color(3);
	cout << "\n\n\t\t\t\t\t     Enter Name Of patient : ";
	Color(2);
	cin >> temp->data.name;
	Color(3);
	cout << "\t\t\t\t\t     Enter age of patient: ";
	Color(2);
	cin >> temp->data.age;
	Color(3);
	cout << "\t\t\t\t\t     Enter address of patient: ";
	Color(2);
	cin >> temp->data.address;
	Color(3);
	cout << "\t\t\t\t\t     Enter gender of patient: ";
	Color(2);
	cin >> temp->data.gender;
	Color(3);
	cout << "\t\t\t\t\t     Enter fee of patient: ";
	Color(2);
	cin >> temp->data.fee;
	Color(3);
	cout << "\t\t\t\t\t     Enter Number of times patient\n\t\t\t\t\t      has visited the hospital: ";
	Color(2);
	cin >> temp->data.Number_of_times_visited;
	temp->priority = priority;


	node* start = front;

	if (front == NULL) {
		front = temp;
	}
	else if (front->priority > temp->priority)
	{
		temp->next = front;
		front = temp;
	}
	else {
		while (start->next != NULL && start->next->priority < temp->priority)
		{
			start = start->next;
		}
		temp->next = start->next;
		start->next = temp;
	}

}
void dequeue() {
	node* temp = front;
	if (isEmpty()) {
		cout << "Underflow" << endl;
		return;
	}
	else
		if (front->next != NULL) {
			cout << "Element deleted from queue is : " << endl;
			front = front->next;
			delete temp;
			temp = NULL;
		}
		else {
			cout << "Element deleted from queue is : " << endl;
			delete front;
			front = NULL;
		}
}
void displayFront() {
	if (isEmpty())
		cout << "Queue is empty" << endl;
	else
	{
		system("cls");
		Color(3);
		cout << "\n\n\n\t\t\t\t  Details of 1st Patient In Appointment Are : \n";
		Color(4);
		cout << "\t\t\t\t--------------------------------------------------------";
		Color(2);
		cout << "\n\n\n\t\t\t\t\tName Of Patient:          ";
		Color(6);
		cout << front->data.name << " " << endl;
		Color(2);
		cout << "\t\t\t\t\tAge Of Patient:           ";
		Color(6);
		cout << front->data.age << " " << endl;
		Color(2);
		cout << "\t\t\t\t\tGender Of Patient:        ";
		Color(6);
		cout << front->data.gender << " " << endl;
		Color(2);
		cout << "\t\t\t\t\tFee for Appointment:      ";
		Color(6);
		cout << front->data.fee << " " << endl;
		Color(2);
		cout << "\t\t\t\t\tAddress Of Patient:       ";
		Color(6);
		cout << front->data.address << " " << endl;
		Color(2);
		cout << "\t\t\t\t\tNo. Of Time The Patient \n\t\t\t\t\tHas Come To The Hospital: ";
		Color(6);

		cout << front->data.Number_of_times_visited << " " << endl;
		Color(4);
		cout << "\t\t\t\t--------------------------------------------------------\n";

	}
}
void displayQueue() {
	node* temp = front;
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
		return;
	}

	while (temp != NULL)
	{


		cout << "\n\n\n\t\t\t\t\t\tAll Appointment List: \n";
		Color(4);
		cout << "\t\t\t\t--------------------------------------------------------";
		Color(2);
		cout << "\n\n\n\t\t\t\t\tName Of Patient:          ";
		Color(6);
		cout << temp->data.name << " " << endl;
		Color(2);
		cout << "\t\t\t\t\tAge Of Patient:           ";
		Color(6);
		cout << temp->data.age << " " << endl;
		Color(2);
		cout << "\t\t\t\t\tGender Of Patient:        ";
		Color(6);
		cout << temp->data.gender << " " << endl;
		Color(2);
		cout << "\t\t\t\t\tFee for Appointment:      ";
		Color(6);
		cout << temp->data.fee << " " << endl;
		Color(2);
		cout << "\t\t\t\t\tAddress Of Patient:       ";
		Color(6);
		cout << temp->data.address << " " << endl;
		Color(2);
		cout << "\t\t\t\t\tNo. Of Time The Patient \n\t\t\t\t\tHas Come To The Hospital: ";
		Color(6);

		cout << temp->data.Number_of_times_visited << " " << endl;
		Color(4);
		cout << "\t\t\t\t--------------------------------------------------------\n";
		temp = temp->next;
	}
	cout << endl;
}
void searchappoint(string name)
{
	node* temp = NULL;
	temp = front;
	while (1)
	{
		if (front == NULL)
		{
			cout << "There Are No Appointments" << endl;
		}

		else if (temp->data.name != name && temp->next != NULL)
		{
			temp = temp->next;

		}
		if (temp->data.name == name)
		{

			Color(4);
			cout << "\t\t\t\t--------------------------------------------------------";
			Color(2);
			cout << "\n\n\n\t\t\t\t\tName Of Patient:          ";
			Color(6);
			cout << temp->data.name << " " << endl;
			Color(2);
			cout << "\t\t\t\t\tAge Of Patient:           ";
			Color(6);
			cout << temp->data.age << " " << endl;
			Color(2);
			cout << "\t\t\t\t\tGender Of Patient:        ";
			Color(6);
			cout << temp->data.gender << " " << endl;
			Color(2);
			cout << "\t\t\t\t\tFee for Appointment:      ";
			Color(6);
			cout << temp->data.fee << " " << endl;
			Color(2);
			cout << "\t\t\t\t\tAddress Of Patient:       ";
			Color(6);
			cout << temp->data.address << " " << endl;
			Color(2);
			cout << "\t\t\t\t\tNo. Of Time The Patient \n\t\t\t\t\tHas Come To The Hospital: ";
			Color(6);
			cout << temp->data.Number_of_times_visited << " " << endl;
			Color(4);
			cout << "\t\t\t\t--------------------------------------------------------\n";
			break;
		}
		break;
	}
}
info inputPatient()
{
	string name, gender, diseases, address, discription;
	int  age, specialRoomNo;
	info p;
	system("cls");
	Color(05);
	cout << "\n\n\n\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::\n";
	cout << "\t\t\t\t\t::";
	Color(2);
	cout << "  Data Entering in Patient Section";
	Color(05);
	cout << "  ::\n";
	cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::\n";

	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Name: ";
	cin.ignore();//clearing buffer
	Color(02);
	getline(cin, name);
	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Gender: ";
	Color(02);
	getline(cin, gender);
	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Disease: ";
	Color(02);
	getline(cin, diseases);
	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Discription: ";
	Color(02);
	getline(cin, discription);
	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Address: ";
	Color(02);
	getline(cin, address);
	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Age: ";
	Color(02);
	cin >> age;
	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Special RoomNo: ";
	Color(02);
	cin >> specialRoomNo;
	p.name = name;
	p.gender = gender;
	p.diseases = diseases;
	p.address = address;
	p.discription = discription;
	p.age = age;
	p.specialRoomNo = specialRoomNo;

	system("cls");
	Color(4);
	cout << "\n\n\n\n\t\t\t\t\t**\n";
	cout << "\t\t\t\t\t::  ";
	Color(6);
	clog << "  Completed input operation";
	Color(4);
	cout << "       ::\n";
	cout << "\t\t\t\t\t**\n";
	return p;
}//end of input patient function 
info inputdoctor()
{
	string name, gender, specialist, address;
	int  age, fee;
	info p;

	system("cls");
	Color(05);
	cout << "\n\n\n\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::\n";
	cout << "\t\t\t\t\t::";
	Color(2);
	cout << "  Data Entering in Doctor Section";
	Color(05);
	cout << "  ::\n";
	cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::\n";

	Color(03);
	cout << "\n\t\t\t\t\tENTER THE DOCTOR NAME: ";
	cin.ignore();//clearing buffer
	Color(02);
	getline(cin, name);
	Color(03);
	cout << "\n\t\t\t\t\tENTER THE DOCTOR GENDER: ";
	Color(02);
	getline(cin, gender);
	Color(03);
	cout << "\n\t\t\t\t\tENTER THE DOCTOR specialist: ";
	Color(02);
	getline(cin, specialist);
	Color(03);
	cout << "\n\t\t\t\t\tENTER THE DOCTOR ADDRESS: ";
	Color(02);
	getline(cin, address);
	Color(03);
	cout << "\n\t\t\t\t\tENTER THE DOCTOR AGE: ";
	Color(02);
	cin >> age;
	Color(03);
	cout << "\n\t\t\t\t\tENTER THE DOCTOR fee: ";
	Color(02);
	cin >> fee;
	p.name = name;
	p.gender = gender;
	p.specialist = specialist;
	p.address = address;
	p.age = age;
	p.fee = fee;
	system("cls");
	Color(4);
	cout << "\n\n\n\n\t\t\t\t\t**\n";
	cout << "\t\t\t\t\t::  ";
	Color(6);
	clog << "  Completed input operation";
	Color(4);
	cout << "       ::\n";
	cout << "\t\t\t\t\t**\n";
	return p;
}//end of input doctor function
info inputstaff()
{
	string name, gender, feild, address;
	int  age;
	info p;
	system("cls");
	Color(05);
	cout << "\n\n\n\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::\n";
	cout << "\t\t\t\t\t::";
	Color(2);
	cout << "  Data Entering in Staff Section";
	Color(05);
	cout << "  ::\n";
	cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::\n";

	Color(03);
	cout << "\n\t\t\t\t\tENTER THE Staff NAME: ";
	cin.ignore();//clearing buffer
	Color(02);
	getline(cin, name);
	Color(03);
	cout << "\n\t\t\t\t\tENTER THE Staff GENDER: ";
	Color(02);
	getline(cin, gender);
	Color(03);
	cout << "\n\t\t\t\t\tENTER THE Staff feild: ";
	Color(02);
	getline(cin, feild);
	Color(03);
	cout << "\n\t\t\t\t\tENTER THE Staff ADDRESS: ";
	Color(02);
	getline(cin, address);
	Color(03);
	cout << "\n\t\t\t\t\tENTER THE Staff AGE: ";
	Color(02);
	cin >> age;

	p.name = name;
	p.gender = gender;
	p.feild = feild;
	p.address = address;
	p.age = age;

	system("cls");
	Color(4);
	cout << "\n\n\n\n\t\t\t\t\t**\n";
	cout << "\t\t\t\t\t::  ";
	Color(6);
	clog << "  Completed input operation";
	Color(4);
	cout << "       ::\n";
	cout << "\t\t\t\t\t**\n";
	return p;
}//end of input doctor function
info inputappointment()
{
	string name, gender, diseases, address;
	int  age, date;
	info p;
	system("cls");
	Color(05);
	cout << "\n\n\n\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::\n";
	cout << "\t\t\t\t\t::";
	Color(2);
	cout << "Data Entering in Appointment Section";
	Color(05);
	cout << "  ::\n";
	cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::\n";

	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Name: ";
	cin.ignore();//clearing buffer
	Color(02);
	getline(cin, name);
	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Gender: ";
	Color(02);
	getline(cin, gender);
	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Disease: ";
	Color(02);
	getline(cin, diseases);
	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Address: ";
	Color(02);
	getline(cin, address);
	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Age: ";
	Color(02);
	cin >> age;
	Color(03);
	cout << "\n\t\t\t\t\tEnter The Patient Appointment Date: ";
	Color(02);
	cin >> date;
	p.name = name;
	p.gender = gender;
	p.diseases = diseases;
	p.address = address;
	p.age = age;
	p.date = date;
	system("cls");
	Color(4);
	cout << "\n\n\n\n\t\t\t\t\t**\n";
	cout << "\t\t\t\t\t::  ";
	Color(6);
	clog << "  Completed input operation";
	Color(4);
	cout << "       ::\n";
	cout << "\t\t\t\t\t**\n";
	return p;
}//end of input doctor function
Node* append(Node* head, info data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		return head;
	}
	Node* last = head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = temp;
	Color(4);
	clog << "\n\n\n\t\t\t\t\tAPPEND COMPLETED " << endl;
	return head;
}// end of append function 
void delElement(Node* head, int loc)
{
	Node* temp = new Node;
	temp = head;
	if (head = NULL)
	{
		cout << "Node is NULL" << endl;
		return;
	}
	for (int i = 1; i <= loc; i++)
	{
		temp = temp->next;
		if (i < loc)
		{
			head = head->next;
		}// end of if statement
	}// ned of for statement 
	head->next = temp->next;

}//end of delElement function
Node* searchList(Node* head, string v)
{
	int i = 1;
	if (head == NULL)
	{
		system("Cls");
		Color(4);
		cout << "\n\n\n\n\t\t\t\t\t\t\t EMPTY" << endl;
		return NULL;
	}

	while (head->next != NULL && head->data.name != v)
	{
		head = head->next;
		i++;

	}
	if (head->data.name == v)
		Color(2);
	cout << "\t\t\t\t\tELEMENT FOUND AT LOCATION " << i << endl;

	return head;
}// end of searchlist function 
int listlength(Node* head)
{
	int temp = 0;
	if (head == NULL)
	{
		Color(4);
		cout << "\t\t\t\t\t   List is empty" << endl;
		return 0;
	}
	while (head->next != NULL)
	{
		++temp;
		head = head->next;
	}
	return temp + 1;
}// end of ListLength function 
void readpatientList(Node* head)
{
	char storepatient[50][50] = { 0 };
	ifstream patientread;
	patientread.open("patient.txt");
	if (patientread.fail())
	{
		Color(017);
		cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
		cout << "\t\t\t\t\t  ::";
		Color(2);
		cout << "   Printing Patient List";
		Color(017);
		cout << "       ::\n";
		cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
		cout << "\n\n\t\t\t\t\t\t\tFile Not Opened" << endl;
		return;
	}
	int i = 0;
	Color(017);
	cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
	cout << "\t\t\t\t\t  ::";
	Color(2);
	cout << "   Print Patient List";
	Color(017);
	cout << "      ::\n";
	cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n\n\n\n";
	while (!patientread.eof())
	{
		patientread.getline(storepatient[i], 50);

		i++;
	}
	for (int i = 0; i < 50; i++)
	{
		for (int k = 0; k < 50; k++)
		{

			cout << storepatient[i][k];

		}
		cout << endl;
	}

	patientread.close();
}// end of printlinked list function 
void writepatientList(Node* head)
{
	ofstream patientinfo;

	patientinfo.open("patient.txt", ios::app);
	patientinfo << "Print Patient List: ";
	while (head != NULL)
	{


		patientinfo << endl;
		patientinfo << endl;
		patientinfo << "Name:       " << head->data.name << "         \n";
		patientinfo << "Address:    " << head->data.address << "      \n";
		patientinfo << "Gender:     " << head->data.gender << "       \n";
		patientinfo << "Discription:" << head->data.discription << "  \n";
		patientinfo << "Disease:    " << head->data.diseases << "     \n";
		patientinfo << "AGE:        " << head->data.age << "          \n";
		patientinfo << "Room No:    " << head->data.specialRoomNo << " \n";
		head = head->next;

	}
	patientinfo << endl;

	patientinfo.close();
}// end of printlinked list function 
void readdoctorList(Node* head)
{
	char storedoctor[50][50] = { 0 };
	ifstream doctorread;
	doctorread.open("doctor details.txt");
	if (doctorread.fail())
	{

		Color(017);
		cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
		cout << "\t\t\t\t\t  ::";
		Color(2);
		cout << " Printing  Doctors List";
		Color(017);
		cout << "         ::\n";
		cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
		Color(2);
		cout << "\t\t\t\t-------------------------------------------------\n";
		Color(4);
		cout << "\n\n\t\t\t\t\t   File Not Opened" << endl;
		return;
	}
	int i = 0;
	while (!doctorread.eof())
	{

		doctorread.getline(storedoctor[i], 50);
		i++;
	}
	for (int i = 0; i < 50; i++)
	{
		for (int k = 0; k < 50; k++)
		{

			cout << storedoctor[i][k];

		}
		cout << endl;
	}

	doctorread.close();


}// end of printlinked list function 
void writedoctorList(Node* head)
{
	ofstream doctorinfo;
	doctorinfo.open("doctor details.txt", ios::app);
	doctorinfo << endl;
	Color(017);
	doctorinfo << "Print New Doctors List" << endl;
	while (head->next != NULL)
	{



		Color(02);
		doctorinfo << "Name:       " << head->data.name << "         \n";
		doctorinfo << "Address:    " << head->data.address << "      \n";
		doctorinfo << "Gender:     " << head->data.gender << "       \n";
		doctorinfo << "Specialist: " << head->data.specialist << "   \n";
		doctorinfo << "AGE:        " << head->data.age << "          \n";
		doctorinfo << "Fee:        " << head->data.fee << "          \n";

		head = head->next;
	}
	doctorinfo << endl;
	doctorinfo.close();
}
void readstaffList(Node* head)
{
	char storestaff[50][50] = { 0 };
	ifstream staffread;
	staffread.open("doctor details.txt");
	if (staffread.fail())
	{
		Color(017);
		cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
		cout << "\t\t\t\t\t  ::";
		Color(2);
		cout << "   Printing Staff List";
		Color(017);
		cout << "          ::\n";
		cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
		cout << "\n\n\t\t\t\t\t\t\tFile Is Not Empty" << endl;
		return;
	}
	int i = 0;
	while (staffread.eof())
	{
		staffread.getline(storestaff[i], 50);
		i++;
	}
	for (int i = 0; i < 50; i++)
	{
		for (int k = 0; k < 50; k++)
		{

			cout << storestaff[i][k];

		}
		cout << endl;
	}

	staffread.close();

}// end of printlinked list function 
void writestaffList(Node* head)
{
	ofstream stafflist;
	stafflist.open("staff.txt", ios::app);
	stafflist << "   Print Patient List" << endl;
	stafflist << endl;
	while (head->next != NULL)
	{


		stafflist << "Name:       " << head->data.name << "         \n";
		stafflist << "Address:    " << head->data.address << "      \n";
		stafflist << "Gender:     " << head->data.gender << "       \n";
		stafflist << "Feild:      " << head->data.feild << "        \n";
		stafflist << "AGE:        " << head->data.age << "          \n";

		head = head->next;
	}
	stafflist << endl;
	stafflist.close();
}// end of printlinked list function
void changeNode(Node* head, string data, string newdata)
{
	while (head != NULL)
	{
		if (head->data.name == data)
		{

			head->data.name = newdata;



		}

		head = head->next;
	}

}//end of changeNode function 
Node* InsertFront(Node* head, info data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}// end of insert  front function
void display_programe_title()
{
	Color(017);
	gotoxy(35, 4);
	cout << " :::::::::::::::::::::::::::::::::::::::::";
	gotoxy(35, 5);
	cout << " ::";
	Color(4);
	cout << "   HAH Hospital Management System";
	Color(017);
	cout << "    ::";
	gotoxy(35, 6);
	cout << " :::::::::::::::::::::::::::::::::::::::::";
}
void load_programe()
{
	int f = 47, g = 15;
	system("cls");
	display_programe_title();
	gotoxy(f, g);
	Color(02);
	cout << "------------";
	gotoxy(f, g + 1);
	Color(05);
	cout << "LOADING PROGRAME..";
	gotoxy(f, g + 2);
	Color(02);
	cout << "------------";
	for (int i = 1; i <= 6; i++)
	{
		Sleep(1000);
		gotoxy(f + 11 + i, g);
		cout << "---";
		gotoxy(f + 13 + i, g + 1);
		cout << ".";
		gotoxy(f + 11 + i, g + 2);
		cout << "---";
	}
	system("cls");
}
int main()
{
	load_programe();
	Color(3);
	cout << "\n\n\n\n\n\n\t\t\t\t\tThis program is develope by:\n\n";
	Color(2);
	cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::\n";
	cout << "\t\t\t\t\t::  Muhammad Haris               ::\n";
	cout << "\t\t\t\t\t::  Muhammad Ahsanullah Mangat   ::\n";
	cout << "\t\t\t\t\t::  Hafiz Hammad Sharafat Satti  ::\n";
	cout << "\t\t\t\t\t:::::::::::::::::::::::::::::::::::\n\n";
	Color(4);
	system("pause");
	system("cls");

	Node* head = NULL;
	info Patient;
	info doctor;
	info staff;
	info appointment;
	string nameToSearch;
	string oldname, newname;


	while (1)
	{
		system("cls");
		Color(03);
		cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
		cout << "\t\t\t\t\t  ::";
		Color(6);
		cout << "            WELCOME";
		Color(03);
		cout << "            ::\n";
		cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";

		Color(017);
		cout << "\n\n\n\t\t\t\t\t---------------------------------------";
		cout << "\n\t\t\t\t\t|   ";
		Color(02);
		cout << "Press 1 for Doctor Section";
		Color(017);
		cout << "        | ";
		cout << "\n\t\t\t\t\t|   ";
		Color(02);
		cout << "Press 2 for Patient Section";
		Color(017);
		cout << "       |";
		cout << "\n\t\t\t\t\t|   ";
		Color(02);
		cout << "Press 3 for Staff Section";
		Color(017);
		cout << "         |";
		cout << "\n\t\t\t\t\t|   ";
		Color(02);
		cout << "Press 4 for Appointment Section";
		Color(017);
		cout << "   |";
		cout << "\n\t\t\t\t\t|   ";
		Color(02);
		cout << "Press 5 for Bill Section";
		Color(017);
		cout << "          |\n";
		cout << "\t\t\t\t\t---------------------------------------\n";

		int i;
		cin >> i;
		if (i == 1) {
			int op;
			system("cls");
			Color(06);
			cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
			cout << "\t\t\t\t\t  ::";
			Color(3);
			cout << "   Wellcome To Doctor Section";
			Color(06);
			cout << "  ::\n";
			cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";


			Color(017);
			cout << "\n\n\n\t\t\t\t\t---------------------------------------";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      1-> ADD";
			Color(017);
			cout << "\t\t      | ";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      2-> DEL";
			Color(017);
			cout << "      \t              |";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      3-> SEARCH";
			Color(017);
			cout << "                  |";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      4-> LIST LENGTH";
			Color(017);
			cout << "             |";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      5-> PRINT";
			Color(017);
			cout << "                   |\n";
			cout << "\t\t\t\t\t|   ";
			Color(02);
			cout << "      6-> CHANGE NAME";
			Color(017);
			cout << "             |\n";
			cout << "\t\t\t\t\t|   ";
			Color(02);
			cout << "      7-> Save Data";
			Color(017);
			cout << "         |\n";
			cout << "\t\t\t\t\t---------------------------------------\n";
			while (cin >> op)
			{
				switch (op)
				{


				case 1:
					cout << "ENTER DOCTOR DETAIL BELOW ";
					doctor = inputdoctor();
					head = append(head, doctor);
					break;
				case 2:
					system("cls");

					if (listlength(head) < 2)

					{
						Color(4);
						cout << "\t\t\t\t\t   Length is less than two\n";
						cout << "\t\t\t\t\t   Terminating program" << endl;
						Color(2);
						cout << "\t\t\t\t-------------------------------------------------\n\n\n\n\n\n\n\n\n\n";
						exit(1);
					}
					else {
						Color(2);
						cout << "\t\t\tEnter location where you want to delete a \ndoctor, at least three doctor must be list: ";
						int i;
						cin >> i;
						delElement(head, 1);
					}
					break;
				case 3:
					system("cls");
					Color(06);
					cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t  ::";
					Color(3);
					cout << "      Searching ";
					Color(06);
					cout << "     ::\n";
					cout << "\t\t\t\t\t  :::::::::::::::::::::::::\n\n\n";

					Color(3);
					cout << "\t\t\t\t\t    Enter Name to Search: ";
					Color(2);
					cin.ignore();
					getline(cin, nameToSearch);
					searchList(head, nameToSearch);
					break;
				case 4:
					system("cls");
					Color(06);
					cout << "\n\n\n\n\n\n\t\t\t\t\t    :::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t    ::";
					Color(3);
					cout << "     List Length ";
					Color(06);
					cout << "    ::\n";
					cout << "\t\t\t\t\t    :::::::::::::::::::::::::\n\n\n";
					cout << "\t\t\t\t\t   You have " << listlength(head) << "New Doctor in hospital" << endl;
					break;
				case 5:
					system("cls");
					Color(017);
					cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t  ::";
					Color(2);
					cout << "    Printing  Doctors List";
					Color(017);
					cout << "     ::\n";
					cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n\n\n";
					readdoctorList(head);
					system("pause");
					break;
				case 6:
					system("cls");
					Color(06);
					cout << "\n\n\n\n\n\n\t\t\t\t\t    :::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t    ::";
					Color(3);
					cout << "     Data Change ";
					Color(06);
					cout << "    ::\n";
					cout << "\t\t\t\t\t    :::::::::::::::::::::::::\n\n\n";
					cin.ignore();
					Color(03);
					cout << "\t\t\t\t\tEnter The Old Name: ";
					Color(02);
					getline(cin, oldname);
					Color(03);
					cout << "\t\t\t\t\tEnter The New Name: ";
					Color(02);
					getline(cin, newname);
					changeNode(head, oldname, newname);
					break;
				case 7:
					writedoctorList(head);
					break;

				default:
					break;
				}

				break;
				system("cls");

			}


		}

		if (i == 2) {
			int op;
			system("cls");
			Color(06);
			cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
			cout << "\t\t\t\t\t  ::";
			Color(3);
			cout << "   Wellcome To Patient Section";
			Color(06);
			cout << " ::\n";
			cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";


			Color(017);
			cout << "\n\n\n\t\t\t\t\t---------------------------------------";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      1-> ADD";
			Color(017);
			cout << "\t\t      | ";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      2-> DEL";
			Color(017);
			cout << "      \t              |";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      3-> SEARCH";
			Color(017);
			cout << "                  |";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      4-> LIST LENGTH";
			Color(017);
			cout << "             |";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      5-> PRINT";
			Color(017);
			cout << "                   |\n";
			cout << "\t\t\t\t\t|   ";
			Color(02);
			cout << "      6-> CHANGE NAME";
			Color(017);
			cout << "             |\n";
			cout << "\t\t\t\t\t|   ";
			cout << "       7-> Insert At Front";
			Color(017);
			cout << "             |\n";
			cout << "\t\t\t\t\t|   ";
			Color(02);
			cout << "     8->To Save data";
			Color(017);
			cout << "         |\n";
			cout << "\t\t\t\t\t---------------------------------------\n";
			while (cin >> op)
			{
				switch (op)
				{

				case 1:
					cout << "ENTER PATIENT DETAIL BELOW ";
					Patient = inputPatient();
					head = append(head, Patient);
					break;
				case 2:
					readpatientList(head);
					if (listlength(head) < 2)

					{
						Color(4);
						cout << "\t\t\t\t\t   Length is less than two\n";
						cout << "\t\t\t\t\t   Terminating program" << endl;
						Color(2);
						cout << "\t\t\t\t-------------------------------------------------\n\n\n\n\n\n\n\n\n\n";
						exit(1);
					}
					else {
						Color(2);
						cout << "\t\t\tEnter location where you want to delete a \npatient, at least three patient must be list: ";
						int i;
						cin >> i;
						delElement(head, 1);
					}
					break;
				case 3:
					system("cls");
					Color(06);
					cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t  ::";
					Color(3);
					cout << "      Searching ";
					Color(06);
					cout << "     ::\n";
					cout << "\t\t\t\t\t  :::::::::::::::::::::::::\n\n\n";

					Color(3);
					cout << "\t\t\t\t\t    Enter Name to Search: ";
					Color(2);
					cin.ignore();
					getline(cin, nameToSearch);
					searchList(head, nameToSearch);
					system("pause");
					break;
				case 4:
					system("cls");
					Color(06);
					cout << "\n\n\n\n\n\n\t\t\t\t\t    :::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t    ::";
					Color(3);
					cout << "     List Length ";
					Color(06);
					cout << "    ::\n";
					cout << "\t\t\t\t\t    :::::::::::::::::::::::::\n\n\n";
					cout << "\t\t\t\t\t   You have " << listlength(head) << "New patient in hospital" << endl;
					break;
				case 5:
					system("cls");
					Color(017);
					cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t  ::";
					Color(2);
					cout << "    Printing  Patient List";
					Color(017);
					cout << "     ::\n";
					cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n\n\n";


					readpatientList(head);
					system("pause");
					break;
				case 6:
					system("cls");
					Color(06);
					cout << "\n\n\n\n\n\n\t\t\t\t\t    :::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t    ::";
					Color(3);
					cout << "     Data Change ";
					Color(06);
					cout << "    ::\n";
					cout << "\t\t\t\t\t    :::::::::::::::::::::::::\n\n\n";
					cin.ignore();
					Color(03);
					cout << "\t\t\t\t\tEnter The Old Name: ";
					Color(02);
					getline(cin, oldname);
					Color(03);
					cout << "\t\t\t\t\tEnter The New Name: ";
					Color(02);
					getline(cin, newname);
					changeNode(head, oldname, newname);
					break;
				case 7:
					Patient = inputPatient();
					head = InsertFront(head, Patient);
					break;
				case 8:
					writepatientList(head);
					break;
				}

				break;
				system("cls");

			}
		}
		if (i == 3)
		{
			int op;
			system("cls");
			Color(06);
			cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
			cout << "\t\t\t\t\t  ::";
			Color(3);
			cout << "   Wellcome To Staff Section";
			Color(06);
			cout << "   ::\n";
			cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";


			Color(017);
			cout << "\n\n\n\t\t\t\t\t---------------------------------------";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      1-> ADD";
			Color(017);
			cout << "\t\t      | ";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      2-> DEL";
			Color(017);
			cout << "      \t              |";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      3-> SEARCH";
			Color(017);
			cout << "                  |";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      4-> LIST LENGTH";
			Color(017);
			cout << "             |";
			cout << "\n\t\t\t\t\t|   ";
			Color(02);
			cout << "      5-> PRINT";
			Color(017);
			cout << "                   |\n";
			cout << "\t\t\t\t\t|   ";
			Color(017);
			cout << "      5-> Insert At Front";

			cout << "                   |\n";
			cout << "\t\t\t\t\t|   ";
			Color(02);
			cout << "      6-> Save Data";
			Color(017);
			cout << "         |\n";
			cout << "\t\t\t\t\t---------------------------------------\n";
			while (cin >> op)
			{
				switch (op)
				{
				case 1:
					cout << "ENTER STAFF DETAIL BELOW ";
					staff = inputstaff();
					head = append(head, staff);
					break;
				case 2:
					if (listlength(head) < 2)

					{
						Color(4);
						cout << "\t\t\t\t\t   Length is less than two\n";
						cout << "\t\t\t\t\t   Terminating program" << endl;
						Color(2);
						cout << "\t\t\t\t-------------------------------------------------\n\n\n\n\n\n\n\n\n\n";
						exit(1);
					}
					else {
						Color(2);
						cout << "\t\t\tEnter location where you want to delete a \nStaff, at least three Staff must be list: ";
						int i;
						cin >> i;
						delElement(head, 1);
					}
					break;
				case 3:
					system("cls");
					Color(06);
					cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t  ::";
					Color(3);
					cout << "      Searching ";
					Color(06);
					cout << "     ::\n";
					cout << "\t\t\t\t\t  :::::::::::::::::::::::::\n\n\n";

					Color(3);
					cout << "\t\t\t\t\t    Enter Name to Search: ";
					Color(2);
					cin.ignore();
					getline(cin, nameToSearch);
					searchList(head, nameToSearch);
					break;
				case 4:
					system("cls");
					Color(06);
					cout << "\n\n\n\n\n\n\t\t\t\t\t    :::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t    ::";
					Color(3);
					cout << "     List Length ";
					Color(06);
					cout << "    ::\n";
					cout << "\t\t\t\t\t    :::::::::::::::::::::::::\n\n\n";
					cout << "\t\t\t\t\t   You have " << listlength(head) << "New Staff Member in hospital" << endl;
					break;
				case 5:
					system("cls");
					Color(017);
					cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t  ::";
					Color(2);
					cout << "    Printing Staff List";
					Color(017);
					cout << "     ::\n";
					cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n\n\n";
					readstaffList(head);
					system("pause");
					break;

				case 6:
					staff = inputstaff();
					head = InsertFront(head, staff);
					break;

				case 7:
					writestaffList(head);
					break;
				default:
					cout << "wrong option" << endl;

				}
				break;
				system("cls");
			}
		}
		if (i == 4)
		{
			string name;
			int k, i = 0, l = 0;
			int op;

			while (1)
			{
				system("cls");
				Color(06);
				cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::::::\n";
				cout << "\t\t\t\t\t  ::";
				Color(3);
				cout << "  Wellcome To Appointment Section";
				Color(06);
				cout << "  ::\n";
				cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::::::\n";


				Color(017);
				cout << "\n\n\n\t\t\t\t\t------------------------------------------";
				cout << "\n\t\t\t\t\t|";
				Color(02);
				cout << "  1-> FOR EMERGENCY Appointments ";
				Color(017);
				cout << "       | ";
				cout << "\n\t\t\t\t\t|";
				Color(02);
				cout << "  2-> For Non Emergency Appointment";
				Color(017);
				cout << "     |";
				cout << "\n\t\t\t\t\t|";
				Color(02);
				cout << "  3-> search appointment details";
				Color(017);
				cout << "        |";
				cout << "\n\t\t\t\t\t|";
				Color(02);
				cout << "  4-> Disp All Appointments details";
				Color(017);
				cout << "     |";
				cout << "\n\t\t\t\t\t|";
				Color(02);
				cout << "  5-> Disp Top Priority Patient Details";
				Color(017);
				cout << " |";
				cout << "\n\t\t\t\t\t|";
				cout << "\n\t\t\t\t\t|";
				Color(02);
				cout << "  6-> Delete Top Priority Patient";
				Color(017);
				cout << " |";
				cout << "\n\t\t\t\t\t|";
				Color(02);
				cout << "  7-> Return To Main Menu";
				Color(017);
				cout << "               |\n";

				cout << "\t\t\t\t\t------------------------------------------\n";

				cin >> op;

				l++;


				if (op == 1)
				{
					enqueue(i);
					i++;
				}

				if (op == 2)
				{
					enqueue(l);
				}

				if (op == 3)
				{
					system("cls");
					Color(06);
					cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t  ::";
					Color(3);
					cout << "      Searching ";
					Color(06);
					cout << "     ::\n";
					cout << "\t\t\t\t\t  :::::::::::::::::::::::::\n\n\n";

					Color(3);
					cout << "\t\t\t\t\t    Enter Name to Search : ";
					Color(2);
					cin >> name;
					searchappoint(name);
					system("pause");
				}
				if (op == 4)
				{
					system("cls");
					Color(017);
					cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t  ::";
					Color(2);
					cout << "    Printing AppointmentList";
					Color(017);
					cout << "     ::\n";
					cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n\n\n";
					displayQueue();
					system("pause");

				}
				if (op == 5)
				{
					system("cls");
					Color(017);
					cout << "\n\n\n\n\n\n\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t  ::";
					Color(2);
					cout << "	1st Patient in Appointment List";
					Color(017);
					cout << "     ::\n";
					cout << "\t\t\t\t\t  :::::::::::::::::::::::::::::::::::\n\n\n";
					displayFront();
					system("pause");

				}
				if (op == 6)
				{
					dequeue();

				}
				if (op == 7)
				{
					break;
				}
				system("cls");

			}


		}
		if (i == 5)
		{
			system("cls");

			cout << "\n\n\n\n\n\n\t\t\t\t:::::::::::::::HOSPITAL BIL::::::::::::" << endl;
			cout << "\t\t\t\t\tEnter name to Search: ";
			cin.ignore();
			getline(cin, nameToSearch);
			searchList(head, nameToSearch);

			//printdoctorList(head);
			int q;
			Color(2);
			cout << "\t\t\t\t\tPRESS 1 FOR EMERGENCY \n";
			cout << "\t\t\t\t\tPRESS 2 FOR CHECK UP\n";
			cin >> q;
			if (q == 1)
			{
				system("cls");
				/*cout << "emergency charges\n";
				cout << "OPD = 150\n";
				cout << " DOCTOR CHARGE =500\n";
				cout << "operation charges =5000\n";
				cout << " first aid chrges = 100\n";*/


				int w;
				Color(6);
				cout << "\n\n\n\n\n\t\t\t\t\t PRESS 1 OPERATION EMERGENCY: \n";
				cout << "\t\t\t\t\t PRESS 2 NON -OPERATION EMERGENCY: \n";
				cin >> w;
				if (w == 1)
				{
					Color(2);
					cout << "\t\t\t\t\tEmergency charges\n";
					cout << "\t\t\t\t\tOPD = 150\n";
					cout << "\t\t\t\t\tDOCTOR CHARGE =500\n";
					cout << "\t\t\t\t\tOperation charges =5000\n";
					cout << "\t\t\t\t\tFirst aid chrges = 100\n";
					cout << "\t\t\t\t\tTotal Amount == 5750 RS\n";


				}
				if (w == 2)
				{
					Color(3);
					cout << "\t\t\t\t\tEmergency charges\n";
					cout << "\t\t\t\t\tOPD = 150\n";
					cout << "\t\t\t\t\tDOCTOR CHARGE =500\n";
					cout << "\t\t\t\t\tFirst aid chrges = 100\n";
					cout << "\t\t\t\t\tTotal Amount== 750 RS\n";

				}

			}
			if (q == 2)
			{
				Color(4);
				cout << "\t\t\t\t\tOPD = 150\n";
				cout << "\t\t\t\t\tDOCTOR CHARGE =500\n";
				cout << "\t\t\t\t\tTOTAL AMOUNT == 650 RS\n";
			}

		}
	}
}