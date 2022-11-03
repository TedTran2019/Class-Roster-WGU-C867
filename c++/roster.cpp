#include "roster.h"
#include <iostream>

using namespace roster;
using namespace student;
using namespace std;

Roster::Roster() { m_classRosterArray = vector<student::Student>(); };

void Roster::add(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3,
                 degree::DegreeProgram degreeProgram) {
  Student newStudent =
      Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1,
              daysInCourse2, daysInCourse3, degreeProgram);
  m_classRosterArray.push_back(newStudent);
}

void Roster::remove(string studentID) {
  for (int i = 0; i < m_classRosterArray.size(); i++) {
    if (m_classRosterArray[i].getStudentID() == studentID) {
      m_classRosterArray.erase(m_classRosterArray.begin() + i);
      return;
    }
  }
  cout << "A student with this ID was not found." << endl;
}

void Roster::printAll() {
  for (int i = 0; i < m_classRosterArray.size(); i++) {
    m_classRosterArray[i].print();
  }
}

void Roster::printAverageDaysInCourse(string studentID) {
  for (int i = 0; i < m_classRosterArray.size(); i++) {
    if (m_classRosterArray[i].getStudentID() == studentID) {
      int *daysInCourses = m_classRosterArray[i].getDaysInCourses();
      int averageDaysInCourse =
          (daysInCourses[0] + daysInCourses[1] + daysInCourses[2]) / 3;
      cout << "Average days in course for student #" << studentID << ": "
           << averageDaysInCourse << endl;
      return;
    }
  }
  cout << "A student with this ID was not found." << endl;
}

// valid email: include an ('@') and period ('.'), exclude (' ')
// I could just use a REGEX here like i did in my Ruby version
void Roster::printInvalidEmails() {
  for (int i = 0; i < m_classRosterArray.size(); i++) {
    string emailAddress = m_classRosterArray[i].getEmailAddress();
    if (emailAddress.find('@') == string::npos ||
        emailAddress.find('.') == string::npos ||
        emailAddress.find(' ') != string::npos) {
      cout << emailAddress << endl;
    }
  }
}

void Roster::printByDegreeProgram(degree::DegreeProgram degreeProgram) {
  for (int i = 0; i < m_classRosterArray.size(); i++) {
    if (m_classRosterArray[i].getDegreeProgram() == degreeProgram) {
      m_classRosterArray[i].print();
    }
  }
}
