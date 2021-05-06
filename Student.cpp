#include <iostream>
#include <string.h>
#include "Student.h"
#include "Faculty.h"


using namespace std;

Student::Student() : Person()
{
  major = "";
  gpa = 0;
  advisor = 0;
}

Student::Student(int setid) : Person(setid,"","")
{
  major = "";
  gpa = 0;
  advisor = 0;
}

Student::Student(int setid, string setname, string setlevel, string setmajor, double setgpa, int setadvisor) : Person(setid,setname,setlevel)
{
  major = setmajor;
  gpa = setgpa;
  advisor = setadvisor;
}

Student::~Student()
{}

string Student::getMajor()
{
  return major;
}

double Student::getGPA()
{
  return gpa;
}

int Student::getAdvisor()
{
  return advisor;
}

void Student::setMajor(string setMajor)
{
  major = setMajor;
}

void Student::setGPA(double setGPA)
{
  gpa = setGPA;
}

void Student::setAdvisor(int setAdvisor)
{
  advisor = setAdvisor;
}

string Student::toString()
{
  string result = "";
  string temp = "Student ID: " + to_string(getID());
  string sName = "\nName: " + getName();
  string sLevel = "\nLevel: " + getLevel();
  string sMajor = "\nMajor: " + getMajor();
  string sGPA = "\nGPA: " + to_string(getGPA());
  string sAdvisor = "\nAdvisor: " + to_string(getAdvisor());
  result = temp + sName + sLevel + sMajor + sGPA + sAdvisor;
  return result;
}

void Student::print()
{
  cout << toString() << endl;
}
