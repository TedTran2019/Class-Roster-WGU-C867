#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>

namespace student {
class Student {
private:
  std::string m_studentID;
  std::string m_firstName;
  std::string m_lastName;
  std::string m_emailAddress;
  int m_age;
  int m_daysInCourses[3];
  degree::DegreeProgram m_degreeProgram;

public:
  Student(std::string studentID, std::string firstName, std::string lastName,
          std::string emailAddress, int age, int daysInCourse1,
          int daysInCourse2, int daysInCourse3,
          degree::DegreeProgram degreeProgram);
  void print();
  std::string getStudentID();
  std::string getFirstName();
  std::string getLastName();
  std::string getEmailAddress();
  int getAge();
  int *getDaysInCourses();
  degree::DegreeProgram getDegreeProgram();
  void setStudentID(std::string newID);
  void setfirstName(std::string newFirstName);
  void setlastName(std::string newLastName);
  void setemailAddress(std::string newEmailAddress);
  void setage(int newAge);
  void setdaysInCourses(int newDaysInCourses[3]);
  void setdegreeProgram(degree::DegreeProgram newDegreeProgram);
};
} // namespace Student

#endif
