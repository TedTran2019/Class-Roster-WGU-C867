#include "roster.cpp"
#include "roster.h"
#include <iostream>

using namespace std;
using namespace degree;
using namespace roster;

vector<string> str_split(string str, char delimiter) {
  vector<string> result;
  int index;

  while ((index = str.find(delimiter)) != -1) {
    result.push_back(str.substr(0, index));
    str = str.substr(index + 1);
  }
  result.push_back(str);

  return result;
}

void addStudentsToClassRoster(Roster *classRoster, const string studentData[]) {
  for (int i = 0; i < 5; i++) {
    vector<string> studentDataVector = str_split(studentData[i], ',');
    string studentID = studentDataVector[0];
    string firstName = studentDataVector[1];
    string lastName = studentDataVector[2];
    string emailAddress = studentDataVector[3];
    int age = stoi(studentDataVector[4]);
    int daysInCourse1 = stoi(studentDataVector[5]);
    int daysInCourse2 = stoi(studentDataVector[6]);
    int daysInCourse3 = stoi(studentDataVector[7]);
    DegreeProgram degreeProgram = SECURITY;

    if (studentDataVector[8] == "NETWORK") {
      degreeProgram = NETWORK;
    } else if (studentDataVector[8] == "SOFTWARE") {
      degreeProgram = SOFTWARE;
    }

    (*classRoster)
        .add(studentID, firstName, lastName, emailAddress, age, daysInCourse1,
             daysInCourse2, daysInCourse3, degreeProgram);
  }
}

int main() {
  const string studentData[] = {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "010534644,Ted,Tran,TedTran2019@gmail.com,27,1,1,1,SOFTWARE"};

  cout << "Scripting and Programming - Applications - C867, C++, 010534644, "
       << "Ted Tran" << endl;

  Roster classRoster;
  addStudentsToClassRoster(&classRoster, studentData);
  classRoster.printAll();
  classRoster.printInvalidEmails();
  for (int i = 0; i < 5; i++) {
    classRoster.printAverageDaysInCourse(classRoster.getStudent(i).getStudentID());
  }
  classRoster.printByDegreeProgram(SOFTWARE);
  classRoster.remove("A3");
  classRoster.printAll();
  classRoster.remove("A3");
  return 0;
}
