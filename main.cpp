#include <iostream>
#include <fstream>
#include <string>
#include "GenStack.h"
#include "BST.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
using namespace std;

int main(int argc, char* argv[])
{
  int input = 0;
  ifstream inputStream;
  ofstream outputStream;
  BST<Student> *masterStudent = new BST<Student>();
  BST<Faculty> *masterFaculty = new BST<Faculty>();
  GenStack<char> *typeChange = new GenStack<char>();
  GenStack<Student> *studentRoll = new GenStack<Student>();
  GenStack<Faculty> *facultyRoll = new GenStack<Faculty>();

  inputStream.open("BST.txt");
  if (!inputStream.is_open())
  {
    cout << "There is no previous saved file. One named BST.txt shall be created." << endl;
  }
  else
  {
    string firstF = "";
    string nameF = "";
    int idF = 0;
    string levelF = "";
    string departmentF = "";

    getline(inputStream, firstF);
    while (firstF != "@@@@@@@@@@@@@@")
    {
      idF = stoi(firstF);
      getline(inputStream, nameF);
      getline(inputStream, levelF);
      getline(inputStream, departmentF);

      Faculty temp(idF, nameF, levelF, departmentF);
      masterFaculty->insert(temp);

      getline(inputStream,firstF);
    }

    string nameS = "";
    int idS = 0;
    string levelS = "";
    string majorS = "";
    string tempGpa = "";
    double gpaS = 0.0;
    string tempAdv = "";
    int advisorS = 0;

    getline(inputStream, firstF);
    while (firstF != "@@@@@@@@@@@@@@")
    {
      idS = stoi(firstF);
      getline(inputStream, nameS);
      getline(inputStream, levelS);
      getline(inputStream, majorS);
      getline(inputStream, tempGpa);
      gpaS = stoi(tempGpa);
      getline(inputStream, tempAdv);
      advisorS = stoi(tempAdv);

      Student temp(idS, nameS, levelS, majorS, gpaS, advisorS);
      masterStudent->insert(temp);

      if (advisorS != -1)
      {
        Faculty temp1(advisorS);
        Faculty temp2 = masterFaculty->find(temp1);
        temp2.addAdvisee(temp);
        masterFaculty->removeNode(temp1);
        masterFaculty->insert(temp2);
      }

      getline(inputStream,firstF);
    }
  }
  inputStream.close();
  do
  {
    cout << "1. Print all students' info" << endl;
    cout << "2. Print all faculty info" << endl;
    cout << "3. Find and display student info given ID" << endl;
    cout << "4. Find and display faculty info given ID" << endl;
    cout << "5. Print student's faculty advisor's info given student ID" << endl;
    cout << "6. Print all names and info of a faculty's advisees given faculty ID" << endl;
    cout << "7. Add new student" << endl;
    cout << "8. Delete student given ID" << endl;
    cout << "9. Add new faculty member" << endl;
    cout << "10. Delete faculty member given ID" << endl;
    cout << "11. Change a student's advisor given student ID and new faculty ID" << endl;
    cout << "12. Remove an advisee from a faculty member given the faculty and student ID" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    while (!(cin >> input))
    {
      cout << "Enter a valid input. Please input a number between 1-14." << endl;
      cin.clear();
      cin.ignore(128, '\n');
    }
    string trash;
    getline(cin,trash);
    if (input <= 0 || input >= 15)
    {
      cout << "Not a valid input. Please input a number between 1-14." << endl;
      continue;
    }
    if (input == 1)
    {
      if (masterStudent->isEmpty())
      {
        cout << "There are no students in database." << endl;
        continue;
      }
      else
      {
        masterStudent->printTree();
      }
    }
    else if (input == 2)
    {
      if (masterFaculty->isEmpty())
      {
        cout << "There are no faculty members in database." << endl;
        continue;
      }
      else
      {
        masterFaculty->printTree();
      }
    }
    else if (input == 3)
    {
      int id = 0;
      cout << "What is the ID of the student?" << endl;
      while (!(cin >> id))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      string trash;
      getline(cin,trash);
      Student temp(id);
      if (masterStudent->contains(temp))
      {
        cout << (masterStudent->find(temp)).toString();
      }
      else
      {
        cout << "Student with that ID number does not exist." << endl;
        continue;
      }
    }
    else if (input == 4)
    {
      int id = 0;
      cout << "What is the ID of the faculty member?" << endl;
      while (!(cin >> id))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      string trash;
      getline(cin,trash);
      Faculty temp(id);
      if (masterFaculty->contains(temp))
      {
        cout << masterFaculty->find(temp);
      }
      else
      {
        cout << "Faculty member with that ID number does not exist." << endl;
        continue;
      }
    }
    else if (input == 5)
    {
      int id = 0;
      cout << "What is the student ID of the student that you want to print the faculty info for?" << endl;
      while (!(cin >> id))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      string trash;
      getline(cin,trash);
      Student temp(id);
      if (masterStudent->contains(temp))
      {
        if (masterStudent->find(temp).getAdvisor() == -1)
        {
          cout << "Student does not have an advisor. No action was taken." << endl;
          continue;
        }
        else
        {
          int tempID = masterStudent->find(temp).getAdvisor();
          Faculty temp(tempID);
          cout << masterFaculty->find(temp);
        }
      }
      else
      {
        cout << "Student with that ID number does not exist." << endl;
        continue;
      }
    }
    else if (input == 6)
    {
      int id = 0;
      cout << "What is the ID of the faculty member that you want to display student info for?" << endl;
      while (!(cin >> id))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      string trash;
      getline(cin,trash);
      Faculty temp(id);
      if (masterFaculty->contains(temp))
      {
        masterFaculty->find(temp).printStudents();
      }
      else
      {
        cout << "Faculty member with that ID number does not exist." << endl;
        continue;
      }
    }
    else if (input == 7)
    {
      string answer = "";
      string name = "";
      int id = 0;
      string stand = "";
      string major = "";
      double gpa = 0.0;
      int adId = 0;
      cout << "What is the student's name?" << endl;
      getline(cin,name);
      cout << "What is the student's ID?" << endl;
      while (!(cin >> id))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      string trash;
      getline(cin,trash);
      cout << "What is the student's standing?" << endl;
      getline(cin,stand);
      cout << "What is the student's major?" << endl;
      getline(cin,major);
      cout << "What is the student's GPA?" << endl;
      while (!(cin >> gpa))
      {
        cout << "Enter a valid GPA. Please input GPA in decimal form." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      getline(cin,trash);
      cout << "Do you want to add an advisor? (y/n)" << endl;
      getline(cin,answer);
      while (answer != "y" && answer != "n")
      {
        cout << "Please enter a valid answer. Either y or n." << endl;
        getline(cin,answer);
      }
      if (answer == "y")
      {
        cout << "What is the student's advisor's ID number?" << endl;
        while (!(cin >> adId))
        {
          cout << "Enter a valid ID. Please input an integer." << endl;
          cin.clear();
          cin.ignore(128, '\n');
        }
        getline(cin,trash);
        Faculty temp(adId);
        if (masterFaculty->contains(temp))
        {
          Student newStudent(id, name, stand, major, gpa, adId);
          masterStudent->insert(newStudent);
          studentRoll->push(newStudent);
          typeChange->push('s');
          Faculty tempF = masterFaculty->find(temp);
          tempF.addAdvisee(newStudent);
          masterFaculty->removeNode(temp);
          masterFaculty->insert(tempF);
          continue;
        }
        else
        {
          cout << "Faculty member with that ID number does not exist." << endl;
          continue;
        }
      }
      else
      {
        adId = -1;
      }
      Student newStudent(id, name, stand, major, gpa, adId);
      masterStudent->insert(newStudent);
      studentRoll->push(newStudent);
      typeChange->push('s');
    }
    else if (input == 8)
    {
      int id = 0;
      cout << "What is the ID of the student that you want to delete?" << endl;
      while (!(cin >> id))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      string trash;
      getline(cin,trash);
      Student temp(id);
      if (masterStudent->contains(temp))
      {
        studentRoll->push(masterStudent->find(temp));
        if ((masterStudent->find(temp)).getAdvisor() != -1)
        {
          int fID = masterStudent->find(temp).getAdvisor();
          Faculty tempF(fID);
          Faculty holder = masterFaculty->find(tempF);
          holder.removeAdvisee(temp);
          masterFaculty->removeNode(tempF);
          masterFaculty->insert(holder);
        }
        masterStudent->removeNode(masterStudent->find(temp));
        typeChange->push('s');
      }
      else
      {
        cout << "A student with that ID does not exist." << endl;
        continue;
      }
    }
    else if (input == 9)
    {
      string name = "";
      int id = 0;
      string level = "";
      string department = "";
      cout << "What is the faculty's name?" << endl;
      getline(cin,name);
      cout << "What is the faculty's ID?" << endl;
      while (!(cin >> id))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      string trash;
      getline(cin,trash);
      cout << "What is the faculty's level?" << endl;
      getline(cin,level);
      cout << "What is the faculty's department?" << endl;
      getline(cin,department);

      Faculty newFaculty(id, name, level, department);
      facultyRoll->push(newFaculty);
      masterFaculty->insert(newFaculty);
      typeChange->push('f');
    }
    else if (input == 10)
    {
      int id = 0;
      cout << "What is the ID of the faculty member that you want to delete?" << endl;
      while (!(cin >> id))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      string trash;
      getline(cin,trash);
      Faculty temp (id);
      if (masterFaculty->contains(temp))
      {
        if ((masterFaculty->find(temp)).hasStudents())
        {
          cout << "Error. Please remove all advisees from this faculty member before deleting." << endl;
          continue;
        }
        else
        {
          facultyRoll->push(masterFaculty->find(temp));
          masterFaculty->removeNode(masterFaculty->find(temp));
          typeChange->push('f');
        }
      }
      else
      {
        cout << "A faculty member with that ID does not exist." << endl;
        continue;
      }
    }
    else if (input == 11)
    {
      int sId = 0;
      int fId = 0;
      cout << "What is the ID of the student who you want to change the advisor for?" << endl;
      while (!(cin >> sId))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      string trash;
      getline(cin,trash);
      cout << "What is the ID of the student's new advisor?" << endl;
      while (!(cin >> fId))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      getline(cin,trash);
      Student tempS(sId);
      Faculty tempF(fId);
      if (masterStudent->contains(tempS))
      {
        if (masterFaculty->contains(tempF))
        {
          studentRoll->push(masterStudent->find(tempS));
          facultyRoll->push(masterFaculty->find(tempF));
          int oldFacID = (masterStudent->find(tempS)).getAdvisor();
          Student temp = masterStudent->find(tempS);
          masterStudent->removeNode(tempS);
          temp.setAdvisor(fId);
          fId = (masterStudent->find(temp)).getAdvisor();
          Faculty tempF(fId);
          Faculty holder = masterFaculty->find(tempF);
          holder.addAdvisee(temp);
          masterFaculty->removeNode(holder);
          masterFaculty->insert(holder);
          masterStudent->insert(temp);
          if (oldFacID == -1)
          {
            typeChange->push('b');
          }
          else
          {
            int fID = (masterStudent->find(temp)).getAdvisor();
            Faculty tempF(fID);
            Faculty holder = masterFaculty->find(tempF);
            holder.removeAdvisee(temp);
            masterFaculty->removeNode(holder);
            masterFaculty->insert(holder);
            typeChange->push('b');
          }
        }
        else
        {
        cout << "A faculty member with that ID does not exist." << endl;
        continue;
        }
      }
      else
      {
        cout << "A student with that ID does not exist." << endl;
        continue;
      }
    }
    else if (input == 12)
    {
      int sID = 0;
      int fID = 0;
      cout << "What is the ID of the student that you want to remove?" << endl;
      while (!(cin >> sID))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      string trash;
      getline(cin,trash);
      cout << "What is the ID of the faculty member that you want to remove the student from?" << endl;
      while (!(cin >> fID))
      {
        cout << "Enter a valid ID. Please input an integer." << endl;
        cin.clear();
        cin.ignore(128, '\n');
      }
      getline(cin,trash);
      Student tempS(sID);
      Faculty tempF(fID);
      if (masterStudent->contains(tempS))
      {
        if (masterFaculty->contains(tempF))
        {
          studentRoll->push(masterStudent->find(tempS));
          facultyRoll->push(masterFaculty->find(tempF));
          int fID = (masterStudent->find(tempS)).getAdvisor();
          Faculty holder = masterFaculty->find(tempF);
          holder.addAdvisee(tempS);
          masterFaculty->removeNode(holder);
          masterFaculty->insert(holder);
          Student holderS = masterStudent->find(tempS);
          holderS.setAdvisor(-1);
          masterStudent->removeNode(tempS);
          masterStudent->insert(holderS);
          typeChange->push('b');
        }
        else
        {
        cout << "A faculty member with that ID does not exist." << endl;
        continue;
        }
      }
      else
      {
        cout << "A student with that ID does not exist." << endl;
        continue;
      }
    }
    else if (input == 13)
    {
      if(!typeChange->isEmpty())
      {
        char type = typeChange->pop();
        if (type == 's')
        {
          Student temp = studentRoll->pop();
          if(masterStudent->contains(temp))
          {
            if ((masterStudent->find(temp)).getAdvisor() != -1)
            {
              int fID = (masterStudent->find(temp)).getAdvisor();
              Faculty tempF(fID);
              Faculty holder = masterFaculty->find(tempF);
              holder.removeAdvisee(temp);
              masterFaculty->removeNode(holder);
              masterFaculty->insert(holder);
            }
            masterStudent->removeNode(temp);
          }
          else
          {
            masterStudent->insert(temp);
            if ((masterStudent->find(temp)).getAdvisor() != -1)
            {
              int fID = (masterStudent->find(temp)).getAdvisor();
              Faculty tempF(fID);
              Faculty holder = masterFaculty->find(tempF);
              holder.addAdvisee(temp);
              masterFaculty->removeNode(holder);
              masterFaculty->insert(holder);
            }
          }
        }
        else if (type == 'f')
        {
          Faculty temp = facultyRoll->pop();
          if(masterFaculty->contains(temp))
          {
            masterFaculty->removeNode(temp);
          }
          else
          {
            masterFaculty->insert(temp);
          }
        }
        else if (type == 'b')
        {
          Student sTemp = studentRoll->pop();
          Faculty fTemp = facultyRoll->pop();
          masterFaculty->removeNode(masterFaculty->find(fTemp));
          masterFaculty->insert(fTemp);
          masterStudent->removeNode(masterStudent->find(sTemp));
          masterStudent->insert(sTemp);
        }
      }
      else
      {
        cout << "No changes were made." << endl;
      }
    }
    else if (input == 14)
    {
      cout << "Saving to file: BST.txt" << endl;
      outputStream.open("BST.txt");
      if (!outputStream.is_open())
      {
        cout << "Could not open BST.txt." << endl;
      }
      ofstream out("BST.txt");

      while (!masterFaculty->isEmpty())
      {
        Faculty tempF = masterFaculty->getMin();
        out << tempF;
        masterFaculty->removeNode(masterFaculty->getMin());
      }
      out << "@@@@@@@@@@@@@@" << endl;
      while (!masterStudent->isEmpty())
      {
        Student temp = masterStudent->getMin();
        out << temp;
        masterStudent->removeNode(masterStudent->getMin());
      }
      out << "@@@@@@@@@@@@@@" << endl;
      out.close();

      cout << "Exiting program..." << endl;
      return 0;
    }
  }
  while (input != 14);
  return 0;
}
