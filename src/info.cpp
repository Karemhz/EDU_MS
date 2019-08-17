#include "info.h"

using namespace informations;
//# info #


void person::display(const Data* A)
{
	std::cout << "----------------------------------------\n";
	std::cout << "ID:       \t" << A->id <<"\n";
	std::cout << "Name:     \t" << A->name << "\n";
	std::cout << "Username: \t" << A->username << "\n";
	std::cout << "Email:    \t" << A->email << "\n";
	std::cout << "----------------------------------------\n";
}
void person::quickEdit(Data* &plist, Data* &A, bool isStudent){

short choice;

       input:
       std::cout << "1- Edit Info\n2- Back\n";
	   std::cin >> std::setw(1) >> choice;
		while (std::cin.fail())
		{
			std::cout << "Wrong Input Data Please Try again!\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "1- Edit Info\n2- Back\n";
			std::cin >> std::setw(1) >> choice;
			std::cin.ignore();
		}
		switch (choice)
		{
		case 1:
			system(CLEAR);
			edit(plist,A,isStudent);
			break;
		case 2:
			system(CLEAR);
			return;

		default:
			std::cout << "Wrong Input Data Please Try again!\n";
			goto input;
		}

}
void person::edit(Data* &plist,Data* &A, bool isStudent)
{
	Data* here = plist;
	short choice;
input:	std::cout << "1-Name\n2-Password\n3-Email\n4-back\n";
	    std::cin >> std::setw(1) >> choice;
	    std::cin.ignore();
	    while (std::cin.fail())
			{
				std::cout << "Wrong Input Data Please Try again!\n";
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			    goto input;
			}
	switch (choice)
	{
	case 1:
		std::cout << "Enter New Name: ";
		std::getline(std::cin, A->name);
		break;
	case 2:
		std::cout << "Enter New Password: ";
		std::getline(std::cin, A->password);
		break;
	case 3:
		std::cout << "Enter New Email: ";
		std::getline(std::cin, A->email);
		break;
	case 4:
		return;

	default:
		break;
	}
	if(isStudent)
	{

		std::ofstream s("Student.dat", std::ios::trunc);
		while(here != NULL)
		{
	           s << "Name: " +here->name + "\n";
	           s << "Username: " +here->username + "\n" ;
	           s << "Password: "+here->password + "\n" ;
	           s << "Email: "+here->email + "\n";
	           s << "ID: "<<here->id << "\n";
			   s << "-------------------------------------------\n";
			   here = here->link;
		}
		s.close();
	}
    if(!isStudent)
    {
    	std::ofstream s("Doctor.dat", std::ios::trunc);
    	while(here != NULL)
   		{
	           s << "Name: " +here->name + "\n";
               s << "Username: " +here->username + "\n" ;
   	           s << "Password: "+here->password + "\n" ;
   	           s << "Email: "+here->email + "\n";
   	           s << "ID: "<<here->id << "\n";
   			   s << "-------------------------------------------\n";
   			   here = here->link;
 		}
    	s.close();
    }
  return;

}
void person::showMyCourses(Data* A)
{
	for (unsigned int i =0; i < A->DMyCourses.size();i++) // Check if the Course has been removed by the Doctor
		{
			if(findCourse(A->DMyCourses[i]->code) == -1 )
			{
				A->DMyCourses.erase(A->DMyCourses.begin()+i);
			}
		}

    std::cout << "**You Have "<<A->DMyCourses.size()<<" Course**\n";

	for (unsigned int i =0; i < A->DMyCourses.size();i++)
	{
			std::cout << "-----------------------------------\n";
			std::cout << "Course Name: " << A->DMyCourses[i]->name << "\n";
			std::cout << "Course Code: " << A->DMyCourses[i]->code << "\n";
			std::cout << "-----------------------------------\n";
     }
}

int person::findCourse(std::string code)
{
	for(unsigned int i = 0; i < Course::AllCourses.size(); i++)
		if(Course::AllCourses[i]->code == code)
			return i;

     return -1;
}
void person::addPerson(Data* &plist, std::string username, std::string name, std::string password, std::string email)
{
	Data* here = plist;
		if (plist == NULL)
		{
			plist = new Data();
			plist->name = name;
			plist->username = username;
			plist->password = password;
			plist->email = email;
			return;
		}
		else if (here->link == NULL)
		{
			here->link = new Data();
			here->link->name = name;
			here->link->username = username;
			here->link->email = email;
			here->link->password = password;
			++here->link->id;
			return;
		}
		else
		{
			while (here->link != NULL)
				here = here->link;

			if (here->link == NULL)
			{
				here->link = new Data();
				here->link->name = name;
				here->link->username = username;
				here->link->email = email;
				here->link->password = password;
				here->link->id = here->id + 1;

			}
		 return;
		}
}

Data* person::findPerson(Data* plist, const std::string username)
{
	Data* here = plist;
	while (here != NULL && here->username != username)
		here = here->link;
    if(here == NULL)
    	return NULL;
    else
	return here;
}
Data* person::logIn(Data* plist)
{
   	std::cout << "Please Enter your Name: ";
	std::getline(std::cin, P.name);
	std::cout << "Please Enter your Password: ";
	std::getline(std::cin, P.password);
	system(CLEAR);
	Data* A = verfiy(plist,P.name,P.password);

	return A;
}


Data* person::verfiy(Data* &plist,std::string username, std::string password)
{
	Data* here = plist;
	if (here == NULL)
	{
		system(CLEAR);
		std::cout << "!!!!!!!!!!*Please SignUp First*!!!!!!!!!! \n";

		return NULL;
	}
	while (here != NULL && username != here->username)
		here = here->link;

	if (here != NULL && here->username == username
			&& here->password == password)
	{
		Data* A = findPerson(plist,username);
		if (A != NULL)
		    return A;
	}
	else if (here != NULL && here->username == username
			&& here->password != password)
	{
		system(CLEAR);
		std::cout << "Wrong Password\n";
        return NULL;
   }
	else
	{
		system(CLEAR);
		std::cout << "!!!!!!!!!!*Not Found*!!!!!!!!!!\n";
		return NULL;
	}
	return NULL;
}


void person::signUp(Data* &plist)
{

	std::string password;
	  std::cout << "Please Enter your Full Name: ";
	  std::getline(std::cin, P.name);
   username:
	  std::cout << "Please Enter your Username: ";
	  std::getline(std::cin, P.username);
	if(person::findPerson(plist,P.username) != NULL)
	{
		std::cout << "!!!!*Username already exists*!!!!\n";
	    goto username;
	}
	password:
	  std::cout << "Enter your Password: ";
	  std::getline(std::cin, P.password);
	  std::cout << "Enter your Password again: ";
	  std::getline(std::cin, password);
	 if(password != P.password)
	 {
       std::cout<< "!!!!*Please Try again*!!!!\n";
       goto password;

	 }

	email: std::cout << "Enter your Email: ";
	std::getline(std::cin, P.email);
	if (!(this->is_valid_email(P.email)))
	{
		std::cout << "!!!!*Please Enter a valid Email*!!!!\n";
		goto email;
	}

	system(CLEAR);
	person::addPerson(plist,P.username, P.name, P.password, P.email);
}


void person::writeData(Data* &plist, bool isStudent)
{
	Data* before;
	Data* here = before = plist;
	while(here != NULL)
	{
		before = here;
		here = here->link;
	}

	if(isStudent)
	{
		std::ofstream s("Student.dat",std::ios::app);

		if(before != NULL)
		{
           s << "Name: " +before->name + "\n";
           s << "Username: " +before->username + "\n" ;
           s << "Password: "+before->password + "\n" ;
           s << "Email: "+before->email + "\n";
           s << "ID: "<<before->id << "\n";
		   s << "-------------------------------------------\n";
		}
	    s.close();
	}
	else if(!isStudent)
	{
		std::ofstream s("Doctor.dat",std::ios::app);

		if(before != NULL)
		{
			 s << "Name: " +before->name + "\n";
			 s << "Username: " +before->username + "\n" ;
			 s << "Password: "+before->password + "\n" ;
			 s << "Email: "+before->email + "\n";
			 s << "ID: "<<before->id << "\n";
			 s << "-------------------------------------------\n";
		}
     s.close();
	}

	else return;

	return;
}
void person::readData(Data* &plist, bool isStudent)
{
	Data p;
	if(isStudent)
	{
	std::ifstream s("Student.dat", std::ios::in);

	if(!s.is_open())
     return;

	while(true)
    {
    s.ignore(50,'N'); // read the next name

    if(s.eof())
    {
    	s.close();
		return;
    }

    std::getline(s.seekg(5,std::ios_base::cur),p.name);
    std::getline(s.seekg(10, std::ios_base::cur),p.username);
    std::getline(s.seekg(10, std::ios_base::cur),p.password);
    std::getline(s.seekg(7, std::ios_base::cur),p.email);
    addPerson(plist,p.username,p.name,p.password,p.email);
    }
    }
	else
	{
	std::ifstream s("Doctor.dat", std::ios::in);

	if(!s.is_open())
     return;

	while(true)
    {
    s.ignore(50,'N');

    if(s.eof())
    {
    	s.close();
		return;
    }

    std::getline(s.seekg(5,std::ios_base::cur),p.name);
    std::getline(s.seekg(10, std::ios_base::cur),p.username);
    std::getline(s.seekg(10, std::ios_base::cur),p.password);
    std::getline(s.seekg(7, std::ios_base::cur),p.email);
    addPerson(plist,p.username,p.name,p.password,p.email);
    }
	}
}








//# Course #


std::vector<informations::Course*> Course::AllCourses;
Course::Course(){}
Course::Course(std::string name, std::string code,std::string docName)
{
	informations::Course::docName = docName;
	informations::Course::name = name;
	informations::Course::code = code;
}
void Course::add_to_AllCourses(std::string name, std::string code, std::string docName)
{
  Course::AllCourses.push_back(new Course(name, code,docName));
}
void Course::showAll()
{
	std::cout << "==>There's a "<<AllCourses.size()<<" Courses in System<==\n";
    std::cout << "---------------------------------------------------------\n";
	for (const auto &c : Course::AllCourses)
	{
		std::cout << "Course Name: " << c->name << "\n";
		std::cout << "Course Code: " << c->code << "\n";
	    std::cout << "This Course With Doctor: "<< c->docName<<"\n";
	    std::cout << "---------------------------------------------------------\n";
	}
}
