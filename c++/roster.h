#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <vector>

namespace Roster {
class Roster {
private:
  std::vector<Student::Student> classRosterArray;

public:
  Roster();
  void add(std::string studentID, std::string firstName, std::string lastName,
           std::string emailAddress, int age, int daysInCourse1,
           int daysInCourse2, int daysInCourse3,
           Degree::DegreeProgram degreeProgram);
  void remove(std::string studentID);
  void printAll();
  void printAverageDaysInCourse(std::string studentID);
  void printInvalidEmails();
  void printByDegreeProgram(Degree::DegreeProgram degreeProgram);
};
} // namespace Roster

#endif