#include "roster.h"
#include "student.cpp"
#include <iostream>

using namespace roster;
using namespace student;
using namespace std;

Roster::Roster(){ m_nbrStudents = 0; };

Roster::~Roster() { 
  for (int i = 0; i < m_nbrStudents; i++) {
    delete classRosterArray[i];
  }
};

void Roster::add(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3,
                 degree::DegreeProgram degreeProgram) {
  Student *newStudent =
      new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1,
              daysInCourse2, daysInCourse3, degreeProgram);
  classRosterArray[m_nbrStudents] = newStudent;
  m_nbrStudents++;
}

void Roster::remove(string studentID) {
  for (int i = 0; i < m_nbrStudents; i++) {
    if (getStudent(i).getStudentID() == studentID) {
      delete classRosterArray[i];
      if (i < m_nbrStudents - 1) {
        classRosterArray[i] = classRosterArray[m_nbrStudents - 1];
      }
      m_nbrStudents--;
      return;
    }
  }
  cout << "A student with this ID was not found." << endl;
}

void Roster::printAll() {
  for (int i = 0; i < m_nbrStudents; i++) {
    getStudent(i).print();
  }
}

void Roster::printAverageDaysInCourse(string studentID) {
  for (int i = 0; i < m_nbrStudents; i++) {
    if (getStudent(i).getStudentID() == studentID) {
      int *daysInCourses = getStudent(i).getDaysInCourses();
      int averageDaysInCourse =
          (daysInCourses[0] + daysInCourses[1] + daysInCourses[2]) / 3;
      cout << "Average days in course for student #" << studentID << ": "
           << averageDaysInCourse << endl;
      return;
    }
  }
  cout << "A student with this ID was not found." << endl;
}

void Roster::printInvalidEmails() {
  for (int i = 0; i < m_nbrStudents; i++) {
    string emailAddress = getStudent(i).getEmailAddress();
    if (emailAddress.find('@') == string::npos ||
        emailAddress.find('.') == string::npos ||
        emailAddress.find(' ') != string::npos) {
      cout << emailAddress << endl;
    }
  }
}

void Roster::printByDegreeProgram(degree::DegreeProgram degreeProgram) {
  for (int i = 0; i < m_nbrStudents; i++) {
    if (getStudent(i).getDegreeProgram() == degreeProgram) {
      getStudent(i).print();
    }
  }
}

Student Roster::getStudent(int idx) { return *classRosterArray[idx]; }

int Roster::getNbrStudents() { return m_nbrStudents; }
