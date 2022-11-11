#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <vector>

namespace roster {
class Roster {
private:
  student::Student *classRosterArray[5];
  int m_nbrStudents;

public:
  Roster();
  ~Roster();
  void add(std::string studentID, std::string firstName, std::string lastName,
           std::string emailAddress, int age, int daysInCourse1,
           int daysInCourse2, int daysInCourse3,
           degree::DegreeProgram degreeProgram);
  void remove(std::string studentID);
  void printAll();
  void printAverageDaysInCourse(std::string studentID);
  void printInvalidEmails();
  void printByDegreeProgram(degree::DegreeProgram degreeProgram);
  student::Student getStudent(int idx);
  int getNbrStudents();
};
} // namespace roster

#endif