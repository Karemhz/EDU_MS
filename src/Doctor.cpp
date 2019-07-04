#include "Doctor.h"


Doctor::Doctor()
{
readData(DoctorList,isStudent);
}


void Doctor::mainMenu()

{
	system("clear");
	short choice;
	input:
	std::cout << "**********************Welcome**********************\n";
	std::cout << "(1) LogIn\n(2) SignUp\n(3) Back\n";
	std::cin >> std::setw(1) >> choice;
	std::cin.ignore();

	if (std::cin.fail())
	{
		system("clear");
		std::cout << "Wrong Input Data Please Try again!\n";
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		goto input;
	}

	system("clear");

	switch (choice)
	{
	case 1:
		doctor = logIn(DoctorList);
		if(doctor == NULL)
			return;
		else
		  docMenu(doctor);
		break;

	case 2:
		signUp(DoctorList);
		writeData(DoctorList,isStudent);
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
void Doctor::docMenu(informations::Data* doctor)
{
	short choice;
	input:
	std::cout << "*********" << "Welcome Dr." << doctor->name << "*********\n";
    std::cout << "(1) Show My informations\n(2) Edit My informations\n(3) Teaching Courses\n(4) Add New Course\n(5) Remove Course\n(6) Access Course\n(7) LogOut\n";
	std::cin >> std::setw(1) >> choice;
	std::cin.ignore();

	if (std::cin.fail())
	{
		system("clear");
		std::cout << "Wrong Input Data Please Try again!\n";
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		goto input;
	}

	system("clear");
	switch (choice)
	{
	case 1:
		display(doctor);
		std::cout << "----------------------------------------\n";
		quickEdit(DoctorList,doctor,isStudent);
		goto input;
		break;
	case 2:
		edit(DoctorList,doctor,isStudent);
		goto input;
		break;
	case 3:
       showMyCourses(doctor);
       goto input;
       return;
	case 4:
	   createCourse(doctor);
       std::cout<<"**Course has been created and add to your Teaching Courses!**\n";
       goto input;
       return;
	case 5:
		removeCourse(doctor);
		goto input;
		return;
	case 6:
		accessCourse(doctor);
		goto input;
		break;
	case 7:
		return;
	default:
		std::cout << "Wrong Input Data Please Try again!\n";
		goto input;
		break;
	}
}


void Doctor::accessCourse(informations::Data* doc)
{
    int index;
	std::string code;
	std::cout<< "Enter Course Code: ";
	std::getline(std::cin,code);
	index = person::findCourse(code); // Searching for the Course to access
	if(index != -1)
	{
		unsigned int x;
        for( x = 0; x < doc->DMyCourses.size(); x++)
        {
        	if(doc->DMyCourses[x]->code == code) //If the Course is found and it belong to that Doctor
        	{
        	   openCourse(AllCourses[index]);
        	   system("clear");
        	   return;
        	}
        }
       	std::cout <<"** This Course Belong to another Doctor ! **\n";  //If the Course is found But it belong to another Doctor
        return;
	}
        std::cout<< "**Course Not Found**\n";  // Wrong Course Code or Course Not found
        return;

}

void Doctor::showStudents(std::vector<informations::Data*> studentsInCourse)
{
	std::cout<< "------------------------------------------\n";
		   for(const auto &s : studentsInCourse)
		   {
		 	   std::cout<<"Student Name: "<<s->name<< "\n";
		       std::cout<< "------------------------------------------\n";
		   }
}


void Doctor::openCourse(informations::Course* OwnedCourse)
{

   short choice;
   input:
   std::cout<< "******************** "<< OwnedCourse->name <<" ***********************\n";
   std::cout<< "(1) Show Course Students\n(2) Back\n";
   std::cin >> std::setw(1) >> choice;
   if(std::cin.fail())
   {
	   std::cin.clear();
	   std::cin.ignore(32767,'\n');
	   system("clear");
	   std::cout<<"==> Wrong Input! , Please Try again!\n";
	   goto input;
   }

   switch(choice)
   {
   case 1:
    showStudents(OwnedCourse->CourseStudents);
    goto input;
    break;
   case 2:
	   return;

   default:
	   system("clear");
	   std::cout<<"==> Wrong Input! , Please Try again ..\n";
       goto input;
   }


}

void Doctor::createCourse(informations::Data* doc)

{

	std::string name,code;
	std::cout<<"Please Enter Course name: ";
	std::getline(std::cin, name);
	std::cout<<"Please Enter Course Code: ";
	std::getline(std::cin,code);
    Course().add_to_AllCourses(name,code,doc->name);
    int x  = person::findCourse(code);
	doc->DMyCourses.push_back(AllCourses[x]);

}

void Doctor::removeCourse(informations::Data* doctor)
{
  system("clear");
  std::string code;
  int index;
  std::cout<<"Please Enter Course Code: ";
  std::getline(std::cin,code);
  index = findCourse(code); //Searching for the Course
  if(index != -1)
  {
	  if(Course().AllCourses[index]->docName == doctor->name) //If the Course is found and it belong to that Doctor
	  {
		  delete AllCourses[index];
		  Course().AllCourses.erase(AllCourses.begin()+index);
		  std::cout<<"Done!\n";
	  }

	  else
		  std::cout<<"This Course Belong to another Doctor!\n"; //If the Course is found but it belong to another Doctor
	  return;
  }
  else std::cout<<"Course Not Found!\n"; //If the Course not Found or Wrong Course Code
  return;

}
