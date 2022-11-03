#include "roster.h"
#include <iostream>

using namespace std;
using namespace degree;
using namespace roster;

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
  // Add each student to classRoster
  // classRoster.add("A1", "John", "Smith", "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);
  classRoster.printAll();
  classRoster.printInvalidEmails();
  // Loop through classRosterArray and for each element: printAverageDays
  classRoster.printByDegreeProgram(SOFTWARE);
  classRoster.remove("A3");
  classRoster.printAll();
  classRoster.remove("A3");
  return 0;
}
