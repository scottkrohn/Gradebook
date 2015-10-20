#include "gradebook.h"
#include <fstream>
#include <boost/regex.hpp>
#include <sstream>
#include <stdexcept>
#include <set>

Gradebook::Gradebook(const std::string &name)
	:classname(name),
	currentFilename("")
{
}

Gradebook::Gradebook()
	:classname("EMPTY CLASS")
{
}

/************** ADDING/REMOVING STUDENTS ******************/
bool Gradebook::addStudent(const std::string &studentName)
{
	// Is this student already in the gradebook or an invalid student?
	if(studentExists(studentName) || studentName == "INVALID STUDENT")
	{
		return false;
	}
	// If the student doesn't already exist, add their name and return true
	students.push_back(Student(studentName));
	sortStudents();
	return true;
}

bool Gradebook::addStudent(const Student &student)
{
	// If the student already exists or is an invalid student, return false
	if(studentExists(student.getName()) || student.getName() == "INVALID STUDENT")
	{
		return false;
	}

	students.push_back(student);
	sortStudents();
	return true;
}

bool Gradebook::removeStudent(const std::string &studentName)
{
	// Is this student in the gradebook?
	if(!studentExists(studentName))
	{
		return false;
	}

	// If the student is in the gradebook...
	for(std::vector<Student>::iterator i = students.begin();
		i != students.end(); ++i)
	{
		if(lowercaseString(i->getName()) == lowercaseString(studentName))
		{
			students.erase(i);
			break;
		}
	}
	return true;
}

/************** ADDING/REMOVING ASSIGNMENTS ****************/
bool Gradebook::addAssignmentAll(const Assignment &assign)
{
	// Only a non-graded assignment can be added to all students
	if(assign.getPointsEarned() != 0)
	{
		return false;
	}

	// Store an unmodified copy of the students vector in case adding fails
	std::vector<Student> backupStudents(students);
	for(std::vector<Student>::iterator i = students.begin();
		i != students.end(); ++i)
	{
		// If the addition wasn't successful, restore students and return false
		if(!(i->addAssignment(assign)))
		{
			students = backupStudents;
			return false;
		}
	}
	return true;
}

bool Gradebook::addAssignment(const std::string &studentName,
							  const Assignment &assign)
{
	// Individual assignment allows you to add an already graded assignment

	// Does this student exist in the gradebook?
	if(!studentExists(studentName))
	{
		return false;
	}

	// Get a reference to the student being modified
	Student & student(getStudentRef(studentName));

	// Was the assignment successfully added?
	if(!student.addAssignment(assign))
	{
		return false;
	}
	return true;
}

bool Gradebook::deleteAssignmentAll(const std::string &assignName)
{
	for(std::vector<Student>::iterator i = students.begin();
		i != students.end(); ++i)
	{
		i->deleteAssignment(assignName);
	}
	return true;
}

bool Gradebook::deleteAssignment(const std::string &studentName,
								 const std::string &assignName)
{
	// Does this student exist in the gradebook?
	if(!studentExists(studentName))
	{
		return false;
	}


	// Get a reference to the student being modified
	Student & student(getStudentRef(studentName));



	// Was the assignment successfully removed?
	if(!student.deleteAssignment(assignName))
	{
		return false;
	}
	return true;
}

bool Gradebook::addExtraPointsAll(int points)
{
	// Cannot add a negative extra point value
	if(points < 0)
	{
		return false;
	}

	// Store a copy of the unmodified student vector in case of problems
	std::vector<Student> backupStudents(students);

	for(std::vector<Student>::iterator i = students.begin();
		i != students.end(); ++i)
	{
		// If adding points fails for a student, restore students and return false
		if(!i->addExtraPoints(points))
		{
			students = backupStudents;
			return false;
		}
	}
	return true;
}

bool Gradebook::addExtraPoints(const std::string &studentName, int points)
{
	// Check for valid points value and valid student name
	if(points < 0 || !studentExists(studentName))
	{
		return false;
	}

	Student & student(getStudentRef(studentName));
	if(!student.addExtraPoints(points))
	{
		return false;
	}
	return true;
}

/******************** EDITING EXISTING ASSIGNMENTS ******************/
bool Gradebook::editPointsPossibleAll(const std::string &assignName,
									  double possible)
{
	// An assignment cannot have a negative point value
	if(possible < 0)
	{
		return false;
	}

	// Loop through each student and edit the named assignment
	for(std::vector<Student>::iterator i = students.begin();
		i != students.end(); ++i)
	{
		// Get the points earned on the assignment, this will not be edited
		double earned = (i->getAssignment(assignName)).getPointsEarned();
		i->editAssignmentGrade(assignName, possible, earned);
	}
	return true;
}

bool Gradebook::editPointsPossible(const std::string &studentName,
								const std::string &assignName, double possible)
{
	// Does the student exist in the gradebook?
	if(!studentExists(studentName))
	{
		return false;
	}

	Student & student(getStudentRef(studentName));
	double earned = (student.getAssignment(assignName)).getPointsEarned();
	if(!(student.editAssignmentGrade(assignName, possible, earned)))
	{
		return false;
	}
	return true;
}

bool Gradebook::editAssignment(const std::string &studentName,
							   const std::string &assignName,
							   double possible, double earned)
{
	// Does the student exist in the gradebook?
	if(!studentExists(studentName))
	{
		return false;
	}

	Student & student(getStudentRef(studentName));
	if(!student.editAssignmentGrade(assignName, possible, earned))
	{
		return false;
	}
	return true;
}

/********************* GATHERING FUNCTIONS ******************/
int Gradebook::classSize() const
{
	return students.size();
}

Student Gradebook::getStudent(const std::string &studentName) const
{
	if(!studentExists(studentName))
	{
		return Student("INVALID STUDENT");
	}

	// Find the student and return a copy of it
	for(std::vector<Student>::const_iterator i = students.begin();
		i != students.end(); ++i)
	{
		if(lowercaseString(i->getName()) == lowercaseString(studentName))
		{
			return *i;
		}
	}
}

std::vector<Student> Gradebook::getAllStudents() const
{
	return students;
}

std::string Gradebook::getClassName() const
{
	return classname;
}

std::string Gradebook::getCurrentFilename() const
{
	return currentFilename;
}

std::vector<Assignment> Gradebook::getCommonAssignments() const
{
	std::vector<Assignment> commonAssignments;
	Student firstStudent("");

	// If there are no students in the class, return empty assignment vector
	if(students.size() == 0)
	{
		std::cout << "size = 0" << std::endl;
		return commonAssignments;
	}
	else // make a copy of the first student in the class
	{
		firstStudent = students[0];
	}
	// Loop through all the assignments for the first student, checking each other
	// student to see if they have the assignment. If the firstStudent is missing any
	// assignments that other Students have, it means it wasn't a common
	// assignment anyway and can safely be ignored for this function.
	std::vector<Assignment> firstStuAssigns = firstStudent.getAllAssignments();
	for(std::vector<Assignment>::const_iterator assignIter = firstStuAssigns.begin();
		assignIter != firstStuAssigns.end(); ++assignIter)
	{
		bool hasAssignment = true;
		// Check each student to see if they have an assignment
		for(std::vector<Student>::const_iterator stuIter = students.begin();
			stuIter != students.end(); ++stuIter)
		{
			// If a student doesn't have the assignment, set false
			if(!stuIter->hasAssignment(assignIter->getName()))
			{
				std::cout << stuIter->getName() << " didn't have " << assignIter->getName() << std::endl;
				hasAssignment = false;
				break;
			}
		}
		// If all the students had the assignment, add to the commonAssignment vector
		if(hasAssignment)
		{
			commonAssignments.push_back(*assignIter);
		}
	}
	return commonAssignments;
}

std::vector<Assignment> Gradebook::getAllAssignments() const
{
	std::set<Assignment> allAssignments;

	// Loop through each student in the gradebook
	for(std::vector<Student>::const_iterator stuIter = students.begin();
		stuIter != students.end(); ++stuIter)
	{
		// Create a vector of the current students assignments, loop through vector
		std::vector<Assignment> assignments(stuIter->getAllAssignments());
		for(std::vector<Assignment>::const_iterator assignIter = assignments.begin();
			assignIter != assignments.end(); ++assignIter)
		{
			// Only unique assignments will be added because the containter is a set
			allAssignments.insert(*assignIter);
		}
	}
	// Return a vector with all the contents of the std::set allAssignments
	return std::vector<Assignment>(allAssignments.begin(), allAssignments.end());
}

/************************ WRITING/READING FILES *********************/
bool Gradebook::writeToFile(const std::string &filename) const
{
	// Open outfile and test that it was successfully opened
	std::ofstream outfile(filename.c_str());
	if(!outfile)
	{
		return false;
	}

	outfile << "classname " << classname << "\n";
	outfile << "students " << students.size() << "\n";
	for(std::vector<Student>::const_iterator stu = students.begin();
		stu != students.end(); ++stu)
	{
		std::vector<Assignment> currAssigns(stu->getAllAssignments());
		outfile << "(\"" << stu->getName() << "\"," << currAssigns.size() << ")\n";
		for(std::vector<Assignment>::const_iterator assign = currAssigns.begin();
			assign != currAssigns.end(); ++assign)
		{
			outfile << "\t\"" << assign->getName() << "\"" << ",";
			outfile << assign->getPointsEarned() << "/" << assign->getPointsPossible();
			outfile << "\n";
		}
		outfile << "\textra " << stu->getExtraPoints() << "\n";
	}
	return true;
}

bool Gradebook::loadFromFile(const std::string &filename)
{
	// Open input file and test that it was successsfully opened
	std::ifstream infile(filename.c_str());
	if(!infile)
	{
		return false;
	}

	// Create copy of current gradebook in case of failure to load
	Gradebook backupGradebook(*this);

	// Data used by the gathering process for a gradebook
	std::string sentinalStr;
	std::string className;
	std::string line;
	int assignCount;
	int studentCount;

	// regex patterns used to find student names and assignments
	boost::regex classnamePattern("classname\\s([\\w\\s]+)");
	boost::regex studentsPattern("students\\s(\\d+)");
	boost::regex namePattern("..(\\w+\\s\\w+)..(\\d+).");
	boost::regex assignPattern("\\s\"([\\w\\s.-]+)\",(\\d+)/(\\d+)");
	boost::regex extraPattern("\\s(\\w+)\\s(\\d+)");
	boost::smatch match;

	std::getline(infile, line);
	if(boost::regex_match(line, match, classnamePattern))
	{
		className = match[1];
	}
	else
	{
		return false;
	}

	std::getline(infile, line);
	if(boost::regex_match(line, match, studentsPattern))
	{
		studentCount = stringToInt(match[1]);
	}
	else
	{
		return false;
	}

	Gradebook loadedGradebook(className);

	// Loop once for each student in the gradebook
	for(int stuNum = 0; stuNum != studentCount; ++stuNum)
	{

		// Check for valid student name and assignment count line
		std::getline(infile, line);
		if(!boost::regex_match(line, match, namePattern))
		{
			loadNewGradebook(backupGradebook);
			return false;
		}

		Student student(match[1]);

		assignCount = stringToInt(match[2]);

		// Loop once for each assignment a student has
		for(int assignNum = 0; assignNum != assignCount; ++assignNum)
		{
			// Check for a valid assignment
			std::getline(infile, line);
			if(boost::regex_match(line, match, assignPattern))
			{
				try	// Attempt to create an assignment, catch exception if thrown
				{
					Assignment assign(stringToDouble(match[3]),
									  stringToDouble(match[2]),
									  match[1]);
					if(!student.addAssignment(assign)) // Throw if adding fails
					{
						throw std::runtime_error("");
					}
				}
				catch(std::exception &e)	// Restore gradebook is exception thrown
				{
					loadNewGradebook(backupGradebook);
					return false;
				}
			}
			else	// Restore original gradebook and return false if invalid format
			{
				loadNewGradebook(backupGradebook);
				return false;
			}
		}

		// Get the extra credit line and checking for valid format
		std::getline(infile, line);
		if(boost::regex_match(line, match, extraPattern))
		{
			student.addExtraPoints(stringToDouble(match[2]));
		}
		else	// Restore gradebook and return false if format invalid
		{
			loadNewGradebook(backupGradebook);
			return false;
		}
		// If all formatting is correct for a student and their assignments,
		// ass them to the newly loaded gradebook.
		loadedGradebook.addStudent(student);
	}
	// If all students are successfully loaded, load the gradebook and return true
	loadNewGradebook(loadedGradebook);
	// Save the name of the file that was used to create the gradebook
	currentFilename = filename;
	return true;
}

/******************** PRIVATE GRADEBOOK FUNCTIONS *******************/
bool Gradebook::studentExists(const std::string &studentName) const
{
	// Look to see if a student has already been added for a name
	for(std::vector<Student>::const_iterator i = students.begin();
		i != students.end(); ++i)
	{

		// If a match is found, return true
		// Ignores case when finding the student
		if(lowercaseString(i->getName()) == lowercaseString(studentName))
		{
			return true;
		}
	}
	// If the student name is not found, return false
	return false;
}

Student & Gradebook::getStudentRef(const std::string &studentName)
{
	// If the student doesn't exist, throw exception
	if(!studentExists(studentName))
	{
		throw std::runtime_error("Student doesn't exist for get: " + studentName);
	}
	// Find and return a reference to the student being searched for
	for(std::vector<Student>::iterator i = students.begin();
		i != students.end(); ++i)
	{
		if(lowercaseString(studentName) == lowercaseString(i->getName()))
		{
			return *i;
		}
	}
}

void Gradebook::sortStudents()
{
	std::sort(students.begin(), students.end());
}

void Gradebook::loadNewGradebook(const Gradebook &newGradebook)
{
	students = newGradebook.getAllStudents();
	classname = newGradebook.getClassName();
}

// ***************DEBUG FUNCTIONS FOR THE GRADEBOOK CLASS****************
void Gradebook::DEBUG_printStudentNames() const
{
	for(std::vector<Student>::const_iterator i = students.begin();
		i != students.end(); ++i)
	{
		std::cout << i->getName() << std::endl;
	}
}

void Gradebook::DEBUG_printStudentGrades() const
{
	for(std::vector<Student>::const_iterator i = students.begin();
		i != students.end(); ++i)
	{
		std::cout << i->getName() << ": " << i->getPointsEarned();
		std::cout << "/" << i->getPointsPossible() << " -- ";
		std::cout << std::setprecision(4) <<i->getGrade()*100 << "%" << std::endl;
	}
}

void Gradebook::DEBUG_printStudentAssignments() const
{
	for(std::vector<Student>::const_iterator stu = students.begin();
		stu != students.end(); ++stu)
	{
		std::vector<Assignment> currentAssignments(stu->getAllAssignments());
		std::cout << stu->getName() << " - ";
		std::cout << std::setprecision(4) << stu->getGrade()*100 << "%" << std::endl;
		for(std::vector<Assignment>::const_iterator i = currentAssignments.begin();
			i != currentAssignments.end(); ++i)
		{
			std::cout << "\t" << i->getName() << " - " << i->getPointsEarned();
			std::cout << "/" << i->getPointsPossible() << std::endl;
		}
		std::cout << "\tExtra Points: " << stu->getExtraPoints() << std::endl;
	}
}


// --------------NON MEMBER FUNCTIONS----------------------------
std::string lowercaseString(const std::string &origStr)
{
	std::string lowerStr;
	for(std::string::const_iterator i = origStr.begin();
		i != origStr.end(); ++i)
	{
		lowerStr += tolower(*i);
	}
	return lowerStr;
}

int stringToInt(const std::string &str)
{
	std::istringstream iss(str);
	int num;
	iss >> num;
	return num;
}

double stringToDouble(const std::string &str)
{
	std::istringstream iss(str);
	double num;
	iss >> num;
	return num;
}
