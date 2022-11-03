#include "student.h"
#include <iostream>

using namespace student;
using namespace std;
using namespace degree;

Student::Student(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3,
                 DegreeProgram degreeProgram) {
  m_studentID = studentID;
  m_firstName = firstName;
  m_lastName = lastName;
  m_emailAddress = emailAddress;
  m_age = age;
  m_daysInCourses[0] = daysInCourse1;
  m_daysInCourses[1] = daysInCourse2;
  m_daysInCourses[2] = daysInCourse3;
  m_degreeProgram = degreeProgram;
}

// Would prefer to use format header or libfmt here
void Student::print() {
  cout << m_studentID << "\t";
  cout << "First Name: " << m_firstName << "\t";
  cout << "Last Name: " << m_lastName << "\t";
  cout << "Age: " << m_age << "\t";
  cout << "daysInCourse: {" << m_daysInCourses[0] << ", " << m_daysInCourses[1]
       << ", " << m_daysInCourses[2] << "}\t";
  cout << "Degree Program: " << degreeProgramStrings[m_degreeProgram] << endl;
}

string Student::getStudentID() { return m_studentID; }

string Student::getFirstName() { return m_firstName; }

string Student::getLastName() { return m_lastName; }

string Student::getEmailAddress() { return m_emailAddress; }

int Student::getAge() { return m_age; }

int *Student::getDaysInCourses() { return m_daysInCourses; }

degree::DegreeProgram Student::getDegreeProgram() { return m_degreeProgram; }

void Student::setStudentID(string newID) { m_studentID = newID; }

void Student::setfirstName(string newFirstName) { m_firstName = newFirstName; }

void Student::setlastName(string newLastName) { m_lastName = newLastName; }

void Student::setemailAddress(string newEmailAddress) {
  m_emailAddress = newEmailAddress;
}

void Student::setage(int newAge) { m_age = newAge; }

void Student::setdaysInCourses(int newDaysInCourses[3]) {
  m_daysInCourses[0] = newDaysInCourses[0];
  m_daysInCourses[1] = newDaysInCourses[1];
  m_daysInCourses[2] = newDaysInCourses[2];
}

void Student::setdegreeProgram(degree::DegreeProgram newDegreeProgram) {
  m_degreeProgram = newDegreeProgram;
}
