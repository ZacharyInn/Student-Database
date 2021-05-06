#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty() : Person()
{
  department = "";
  advisees = new DoublyLinkedList<Student>();
}

Faculty::Faculty(int setid) : Person(setid,"","")
{
  department = "";
  name = "";
  level = "";
  advisees = new DoublyLinkedList<Student>();
}

Faculty::Faculty(int setid, string setname, string setlevel, string setdepartment) : Person(setid,setname,setlevel)
{
  department = setdepartment;
  advisees = new DoublyLinkedList<Student>();
}

Faculty::~Faculty()
{}

string Faculty::getDepartment()
{
  return department;
}

bool Faculty::hasStudents()
{
  return !(advisees->isEmpty());
}

void Faculty::setDepartment(string setDepartment)
{
  department = setDepartment;
}

void Faculty::addAdvisee(Student sID)
{
  advisees->insertBack(sID);
}

void Faculty::removeAdvisee(Student sID)
{
  advisees->remove(sID);
}

string Faculty::toString()
{
  string result = "";
  string fID = "Faculty ID: " + to_string(getID());
  string fName = "\nName: " + getName();
  string fLevel = "\nLevel: " + getLevel();
  string fDepartment = "\nDepartment: " + getDepartment();
  result = fID + fName + fLevel + fDepartment;
  return result;
}

void Faculty::print()
{
  cout << "Faculty ID: " << to_string(getID()) << endl;
  cout <<  "Name: " + getName() << endl;
  cout <<  "Level: " + getLevel() << endl;
  cout <<  "Department: " + getDepartment() << endl;
}

void Faculty::printStudents()
{
  advisees->printList();
}
