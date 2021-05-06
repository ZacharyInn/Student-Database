#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include "LinkedList.h"
#include "Person.h"
#include "Student.h"

using namespace std;

class Faculty : public Person
{
public:
  Faculty();
  Faculty(int setid);
  Faculty(int setid, string setname, string setlevel, string setdepartment);
  ~Faculty();
  string getDepartment();
  void setDepartment(string setDepartment);
  void addAdvisee(Student sID);
  void removeAdvisee(Student sID);
  void print();
  string toString();
  bool hasStudents();
  void printStudents();
  string department;
  DoublyLinkedList<Student>* advisees;
  friend bool operator==(Faculty f1, Faculty f2)
  {
    return (f1.getID() == f2.getID());
  }
  friend bool operator!=(Faculty f1, Faculty f2)
  {
    return (f1.getID() != f2.getID());
  }
  friend ostream& operator<<(ostream &out, const Faculty f)
  {
    out << f.id << "\n" << f.name << "\n" << f.level << "\n" << f.department<< endl;
    return out;
  }
  friend istream& operator>>(istream &in, Faculty f)
  {
    in >> f.id;
    in >> f.name;
    in >> f.level;
    in >> f.department;
    return in;
  }
  friend bool operator<(Faculty f1, Faculty f2)
  {
    return (f1.getID() < f2.getID());
  }
  friend bool operator>(Faculty f1, Faculty f2)
  {
    return (f1.getID() > f2.getID());
  }
};

#endif
