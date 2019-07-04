#ifndef INFO_H_
#define INFO_H_

#include<iostream>
#include<iomanip>
#include<regex>
#include<vector>
#include<fstream>
namespace informations
{

class person;
class Data;


class Course
{
public:
	std::string name;
	std::string code;
	std::string docName;

	static std::vector<Course*> AllCourses;
    std::vector<informations::Data*> CourseStudents;

	Course();
	~Course(){};
	Course(std::string name, std::string code, std::string docName);
	static void add_to_AllCourses(std::string name, std::string code, std::string docName);
	static void showAll();
};
struct Data
{
public:
	    int id = 0;
		std::string name;
		std::string username;
		std::string password;
		std::string email;
		std::vector<informations::Course*> DMyCourses; //student courses or teaching course for doctor
		Data *link = NULL;
};




class person : public informations::Course
{
private:
	 Data P;
protected:
	void readData(Data* &plist, bool isStudent);
	void writeData(Data* &plist, bool isStudent);
	void display(const Data* A);
	static void showMyCourses(Data* A);
	static int findCourse(std::string code);
	void addCourse(std::string name,std::string code);
	void addPerson(Data* &plist, std::string username, std::string name, std::string password, std::string email);
	Data* findPerson(Data* plist, const std::string username);
	void quickEdit(Data* &plist,Data* &A, bool isstudent);
	void edit(Data* &plist,Data* &A, bool isStudent);
	void signUp(Data* &plist);
	Data* logIn(Data* plist);
	Data* verfiy(Data* &plist, std::string username, std::string password);
	bool is_valid_email(std::string email)
	{
		const std::regex ex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		return std::regex_match(email, ex);
	}

};

};
#endif
