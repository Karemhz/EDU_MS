#ifndef DOCTOR_H_
#define DOCTOR_H_
#include "info.h"
#include<iostream>
#include<vector>
#include<string>
class Doctor : public informations::person
{
private:
    const bool isStudent = false; // To make sure which file to write or read
	informations::Data* DoctorList = NULL;
    informations::Data* doctor = NULL;
	void docMenu(informations::Data* Doctor);
	void accessCourse(informations::Data* doc); //To make sure that the course is belong to this doctor
	void showStudents(std::vector<informations::Data*> studentsInCourse);
	void openCourse(Course* OwnedCourse);
	void createCourse(informations::Data* doc);
	void removeCourse(informations::Data* doctor);

public:
	Doctor();
	void mainMenu();

};

#endif
