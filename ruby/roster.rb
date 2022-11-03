require_relative 'student'

class Roster
  attr_reader :class_roster_array

  EMAIL_REGEX = /\A[\w+\-.]+@[a-z\d\-]+(\.[a-z\d\-]+)*\.[a-z]+\z/i.freeze

  def initialize
    @class_roster_array = []
  end

  def add(student_info)
    student_info_array = student_info.split(',')
    @class_roster_array << Student.new(*student_info_array[0..4], student_info_array[5..7], student_info_array[8])
  end

  def remove(student_id)
    student = find_student(student_id)
    if student
      @class_roster_array.delete(student)
    else
      puts 'A student with this ID was not found.'
    end
  end

  def print_all
    class_roster_array.each(&:print)
  end

  def print_average_days_per_course(student_id)
    student = find_student(student_id)
    puts student.days_per_course.sum / 3
  end

  def print_invalid_emails
    @class_roster_array.each do |student|
      puts student.email unless student.email =~ EMAIL_REGEX
    end
  end

  def print_by_major(major)
    @class_roster_array.each { |student| student.print if student.major == major }
  end

  private

  def find_student(student_id)
    @class_roster_array.find { |student| student.student_id == student_id }
  end
end
