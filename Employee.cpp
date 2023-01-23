//*****************************************************************************************************
//
//		File:					Employee.h
//
//		Contributor:			Joseph Rydel
//
//		Description: This program is a header 
//					 file to create the employee
//					 class.
//
//      Other files required: Node.h
//							  LinkedList.h
//							  Employee.cpp
//							  ClassRosterDriver.cpp	
//							  
//*****************************************************************************************************

#include "Employee.h"

#include<iostream>

using namespace std;

//*****************************************************************************************************

Employee::Employee()
{
	name = "";
	id = 0;
}

//*****************************************************************************************************

Employee::Employee(string n, int i)
{
	name = n;
	id = i;
}

//*****************************************************************************************************

Employee::Employee(const Employee& e)
{
	this->name = e.name;
	this->id = e.id;
}

//*****************************************************************************************************

istream& operator >> (istream& strm, Employee& emp)
{
	getline(strm, emp.name);
	strm >> emp.id;

	if (!strm.eof())
		strm.ignore();

	return strm;
}

//*****************************************************************************************************

ostream& operator << (ostream& strm, Employee& emp)
{
	strm << emp.getName() << "\n"
		<< emp.getID();

	return strm;
}

//*****************************************************************************************************