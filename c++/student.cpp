#include "student.h"

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
