# Educational Management System

**Students and Doctors stored in linked list data structure and this data written on files Student.dat and Doctor.dat**

## Doctor
  *can display his information like name , email , id
  *can edit his information name , email , password
  *can add a course to system courses and his teaching courses
  *remove his course
  *access his course and show students who registered in this course
  *every doctor have it's own teaching courses , id , name , username, password , email, stored in node

## Student
 *can display his information like name , email , id
 *can edit his information name , email , password
 *can display system Courses and registered in a course
 *can display his courses
 *remove course
 *every student have it's own courses , id , name , username, password and email, stored in node


## Course
*every course have its registered students,doctor , name and code.


**How to compile with g++ compiler and run**
`g++ -o EDU_MS info.cpp Main.cpp Student.cpp Doctor.cpp`
`./EDU_MS`
