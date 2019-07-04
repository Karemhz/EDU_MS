#ifndef STUDENT_H
#define STUDENT_H

#include "info.h"
#include<iostream>
#include<stdlib.h>
#include<iomanip>


class Student: private informations::person
{

private:
    const bool isStudent = true;
	informations::Data* StudentList = NULL;
	informations::Data* student = NULL;
	void addCourse(informations::Data* &student);
	void studentMenu(informations::Data* student);
    void removeCourse(informations::Data* &student);
public:
	Student();
	void mainMenu();

};
#endif
