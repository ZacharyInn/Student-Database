#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Person.h"

using namespace std;

class Student : public Person
{
public:
  Student();
  Student(int setid);
  Student(int setid, string setname, string setlevel, string setmajor, double setgpa, int setadvisor);
  ~Student();
  string getMajor();
  double getGPA();
  int getAdvisor();
  void setMajor(string setMajor);
  void setGPA(double setGPA);
  void setAdvisor(int setAdvisor);
  string toString();
  void print();
  string major;
  double gpa;
  int advisor;

  friend bool operator==(Student s1, Student s2)
  {
    return (s1.getID() == s2.getID());
  }
  friend bool operator!=(Student s1, Student s2)
  {
    return (s1.getID() != s2.getID());
  }
  friend ostream& operator<<(ostream &out, Student s)
  {
    out << s.id << "\n" << s.name << "\n" << s.level << "\n" << s.major << "\n" << s.gpa << "\n" << s.advisor <<endl;
    return out;
  }
  friend istream& operator>>(istream &in, Student s)
  {
    in >> s.id;
    in >> s.name;
    in >> s.level;
    in >> s.major;
    in >> s.gpa;
    in >> s.advisor;
    return in;
  }
  friend bool operator<(Student s1, Student s2)
  {
    return (s1.getID() < s2.getID());
  }
  friend bool operator>(Student s1, Student s2)
  {
    return (s1.getID() > s2.getID());
  }
};



#endif
