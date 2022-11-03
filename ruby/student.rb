class Student
  attr_accessor :student_id, :fname, :lname, :email, :age, :days_per_course, :major

  def initialize(student_id, fname, lname, email, age, days_per_course, major)
    @student_id = student_id
    @fname = fname
    @lname = lname
    @email = email
    @age = age
    @days_per_course = days_per_course.map(&:to_i)
    @major = major
  end

  def print
    puts "#{student_id} \t First Name: #{fname} \t Last Name: #{lname} \t Age: #{age} \
    \t Days in Course: #{days_per_course} \t Degree Program: #{major}"
  end
end
