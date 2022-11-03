require_relative 'roster'

student_data = ['A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY',
                'A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK',
                'A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE',
                'A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY',
                'A5,Ted,Tran,TedTran2019@gmail.com,27,1,1,1,SOFTWARE']

# Use enum in C++ version

puts 'Scripting and Programming Applications, Ruby, A5, Ted Tran'
class_roster = Roster.new
student_data.each { |student| class_roster.add(student) }
class_roster.print_all
class_roster.print_invalid_emails
class_roster.class_roster_array.each { |student| class_roster.print_average_days_per_course(student.student_id) }
class_roster.print_by_major('SOFTWARE')
class_roster.remove('A3')
class_roster.print_all
class_roster.remove('A3')
# In C++ version, free memory. In Ruby, garbage collection will take care of it.
