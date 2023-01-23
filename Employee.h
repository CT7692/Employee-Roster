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

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>

//*****************************************************************************************************

class Employee
{
private:
	std::string name;
	int id;

public:
	Employee();
	Employee(std::string, int);
	Employee(const Employee&);
	std::string getName() const;
	int getID() const;

	bool operator == (const Employee&) const;
	bool operator != (const Employee&) const;
	bool operator > (const Employee&) const;
	bool operator < (const Employee&) const;
	bool operator >= (const Employee&) const;
	bool operator <= (const Employee&) const;
	operator std::string();

	friend std::istream& operator >> (std::istream&, Employee&);
	friend std::ostream& operator << (std::ostream&, Employee&);
};

//*****************************************************************************************************

inline std::string Employee::getName() const
	{	return name;	}

//*****************************************************************************************************

inline int Employee::getID() const
	{	return id;	}

//*****************************************************************************************************

inline bool Employee::operator == (const Employee& emp) const
	{	return this->name == emp.name;	}

//*****************************************************************************************************

inline bool Employee::operator != (const Employee& emp) const
	{	return this->name != emp.name;	}

//*****************************************************************************************************

inline bool Employee::operator > (const Employee& emp) const
	{	return this->name > emp.name;	}

//*****************************************************************************************************

inline bool Employee::operator < (const Employee& emp) const
	{	return this->name < emp.name;	}

//*****************************************************************************************************

inline bool Employee::operator >= (const Employee& emp) const
	{	return this->name >= emp.name;	}

//*****************************************************************************************************

inline bool Employee::operator <= (const Employee& emp) const
	{	return this->name <= emp.name;	}

//*****************************************************************************************************

inline Employee::operator std::string()
	{	return this->name;	}

//*****************************************************************************************************

#endif