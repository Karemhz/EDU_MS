#include "Student.h"


Student::Student()
{
readData(StudentList,isStudent);
}



void Student::mainMenu()
{
	system(CLEAR);
	short choice;
	input:
	std::cout << "**********************Welcome**********************\n";
	std::cout << "(1) LogIn\n(2) SignUp\n(3) Back\n";
	std::cin >> std::setw(1) >> choice;
	std::cin.ignore();

	if (std::cin.fail())
	{
		system(CLEAR);
		std::cout << "Wrong Input Data Please Try again!\n";
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		goto input;
	}

	system(CLEAR);

	switch (choice)
	{
	case 1:
		student = logIn(StudentList);
		if(student == NULL)
			return;
		else
		  studentMenu(student);
		break;

	case 2:
		signUp(StudentList);
		writeData(StudentList,isStudent);
		std::cout << "Now You Can LogIn :D !\n";
		goto input;
		break;
	case 3:
		return;

	default:
		std::cout << "Wrong Input Data Please Try again!\n";
		goto input;
		break;
	}
}

void Student::studentMenu(informations::Data* student)
{
	short choice;
	std::cout << "*********" << "Welcome " << student->name << "*********\n";
	input: std::cout
			<< "(1) Show My informations\n(2) Edit My informations\n(3) My Courses\n(4) Show All Courses\n(5) Register in Course\n(6) Remove Course\n(7) Logout\n";
	std::cin >> std::setw(1) >> choice;
	std::cin.ignore();
	if (std::cin.fail())
	{
		system(CLEAR);
		std::cout << "Wrong Input Data Please Try again!\n";
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		goto input;
	}

	system(CLEAR);
	switch (choice)
	{
	case 1:
		display(student);
		std::cout << "----------------------------------------\n";
		quickEdit(StudentList,student,isStudent);
		goto input;

		break;
	case 2:
		edit(StudentList,student,isStudent);
		goto input;
		break;
	case 3:
     showMyCourses(student);
		goto input;
     return;
	case 4:
     showAll();
		goto input;
     break;
	case 5:
		addCourse(student);
		goto input;
		break;
	case 6:
		removeCourse(student);
        goto input;
		break;
	case 7:
		return;
	default:
   	 goto input;
	 break;
	}
}

void Student::removeCourse(informations::Data* &student)
{
    system(CLEAR);
    std::string code;
	std::cout<< "Enter Course Code: ";
	std::getline(std::cin,code);
	int index = person::findCourse(code); // Searching for the Course
	if(index != -1)
	{
		for(unsigned int x = 0; x < student->DMyCourses.size(); x++) // to Remove Course from DMyCourses list
		{
			if(student->DMyCourses[x]->code == code)
				student->DMyCourses.erase(student->DMyCourses.begin()+x);

		}


		for(unsigned int x = 0; x < AllCourses[index]->CourseStudents.size(); x++) // to Remove student from Course Students list
		{
			if(AllCourses[index]->CourseStudents[x]->username == student->username)
			{
				AllCourses[index]->CourseStudents.erase(AllCourses[index]->CourseStudents.begin()+x);

				std::cout<<"Done!\n";
				return;
			}
		}
	}
	else std::cout<<"Course Not Found!\n"; // Wrong Course Code or Course Not found

   return;
}


void Student::addCourse(informations::Data* &student)
{
    std::string code;
	std::cout<< "Enter Course Code: ";
	std::getline(std::cin,code);
	int index = person::findCourse(code); //Searching for the Course in all Courses in the System
    if(index != -1)
    {
    	for(const auto &c : student->DMyCourses) // To make sure that the Course is not added before
    	{	if(code == c->code)
    	  {
    		std::cout<< "You have already added the Course\n";
    	    return;
    	  }
    	}
    	student->DMyCourses.push_back(Course::AllCourses[index]); // Add Course to MyCourses list
        AllCourses[index]->CourseStudents.push_back(student);     // Add student to course students list
    	std::cout<<"Done!\n";
    }
    else // Wrong Course Code or Course Not found
    {
    	std::cout<<"Course Not Found!\n";
    	return;
    }

}
