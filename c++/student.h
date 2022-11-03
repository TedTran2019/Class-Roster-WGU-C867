#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>

namespace Student {
class Student {
private:
  std::string studentID;
  std::string firstName;
  std::string lastName;
  std::string emailAddress;
  int age;
  int daysInCourses[3];
  Degree::DegreeProgram degreeProgram;

public:
  Student(std::string studentID, std::string firstName, std::string lastName,
          std::string emailAddress, int age, int daysInCourse1,
          int daysInCourse2, int daysInCourse3,
          Degree::DegreeProgram degreeProgram);
  void print();
  std::string getStudentID();
  std::string getFirstName();
  std::string getLastName();
  std::string getEmailAddress();
  int getAge();
  int *getDaysInCourses();
  Degree::DegreeProgram getDegreeProgram();
  void setStudentID(std::string newID);
  void setfirstName(std::string newFirstName);
  void setlastName(std::string newLastName);
  void setemailAddress(std::string newEmailAddress);
  void setage(int newAge);
  void setdaysInCourses(int newDaysInCourses[3]);
  void setdegreeProgram(Degree::DegreeProgram newDegreeProgram);
};
} // namespace Student

#endif
