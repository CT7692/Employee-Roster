//*****************************************************************************************************
//
//		File:				EmpRosterDriver.cpp
//
//		Contributor:			Joseph Rydel
//
//		Description: This program is the driver file
//					 for a linked list to demonstrate
//					 the reversal of a linked list.
//
//      Other files required: Node.h
//							  Employee.h
//							  Employee.cpp
//							  LinkedList.h	
//							  
//*****************************************************************************************************

#include "LinkedList.h"
#include "Employee.h"

#include<iostream>
#include<fstream>

using namespace std;

//*****************************************************************************************************

void formList(LinkedList<Employee>&, Employee&);

//*****************************************************************************************************

int main()
{
	const string LINE = string(50, '*');
	LinkedList<Employee> obj;
	Employee info;
	ostream& os = cout;
	formList(obj, info);
	int size = obj.getSize();

	cout << "List size: ";
	cout << size << "\n" << endl;

	cout << LINE << endl;
	cout << "Ordered: " << endl;
	obj.display(os);

	cout << LINE << endl;
	cout << "Front: " << endl;
	obj.viewFront(os);

	obj.reverse();
	cout << LINE << endl;
	cout << "Reversed: " << endl;
	obj.display(os);

	return 0;
}

//*****************************************************************************************************

void formList(LinkedList<Employee>& obj, Employee& info)
{

	fstream fin;
	fin.open("EmployeeRoster.txt");
	if (fin.fail())
		cout << "File failed to load." << endl;

	else
	{
		while (!fin.eof())
		{
			fin >> info;
			obj.insert(info);
		}

		cout << "File loaded successfully.\n" << endl;
		fin.close();

	}
}

//*****************************************************************************************************

//File loaded successfully.
//
//List size : 10
//
//* *************************************************
//Ordered :
//	Davidson, Roger
//	128195
//
//	Henderson, Alexander
//	130989
//
//	Hoffman, Andrea
//	115179
//
//	Katsumata, Yuto
//	100378
//
//	McCallister, Danielle
//	101928
//
//	Rydel, Joseph
//	111329
//
//	Seeger, Jerry
//	108921
//
//	Seethree, Pio
//	126969
//
//	Watanabe, Juri
//	119066
//
//	Wilson, Angela
//	124133
//
//	* *************************************************
//	Front:
//Davidson, Roger
//128195
//
//* *************************************************
//Reversed :
//	Wilson, Angela
//	124133
//
//	Watanabe, Juri
//	119066
//
//	Seethree, Pio
//	126969
//
//	Seeger, Jerry
//	108921
//
//	Rydel, Joseph
//	111329
//
//	McCallister, Danielle
//	101928
//
//	Katsumata, Yuto
//	100378
//
//	Hoffman, Andrea
//	115179
//
//	Henderson, Alexander
//	130989
//
//	Davidson, Roger
//	128195
//
//
//	C:\Users\josep\source\repos\ClassRoster\x64\Debug\EmployeeRoster.exe(process 183876) exited with code 0.
//	Press any key to close this window . . .