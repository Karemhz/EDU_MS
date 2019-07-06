# Educational Management System


## Doctor
  * Can display his information like name, username , email and id
  * Can edit his information name , email , password
  * Can add a course to system courses and his teaching courses
  * Remove his course
  * Access his course and show students who registered in this course
  * Every doctor have it's own teaching courses, id, name , username, password , email, stored in node

## Student
 * Can display his information like name, username, email and id
 * Can edit his information name , email , password
 * Can display system Courses and register in a course
 * Can display his courses
 * Remove course
 * Every student have it's own courses, id, name, username, password and email, stored in node

**Students and Doctors stored in linked list data structure and this data written on files Student.dat and Doctor.dat**


## Course
* Every course have it's registered students, doctor, name and code.


**How to compile with g++ compiler and run**
```
g++ -o EDU_MS info.cpp Main.cpp Student.cpp Doctor.cpp
./EDU_MS

```
