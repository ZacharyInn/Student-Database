#include <iostream>
#include "Person.h"

using namespace std;

Person::Person()
{
  id = 0;
  name = "";
  level = "";
}

Person::Person(int setid, string setname, string setlevel)
{
  id = setid;
  name = setname;
  level = setlevel;
}

Person::~Person()
{}

int Person::getID()
{
  return id;
}

string Person::getName()
{
  return name;
}

string Person::getLevel()
{
  return level;
}

void Person::setID(int setID)
{
  id = setID;
}

void Person::setName(string setName)
{
  name = setName;
}

void Person::setLevel(string setLevel)
{
  level = setLevel;
}
