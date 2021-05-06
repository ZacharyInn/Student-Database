#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person
{
public:
  Person();
  Person(int setid, string setname, string setlevel);
  ~Person();
  int getID();
  string getName();
  string getLevel();
  void setID(int setID);
  void setName(string setName);
  void setLevel(string setLevel);

protected:
  int id;
  string name;
  string level;
};

#endif
