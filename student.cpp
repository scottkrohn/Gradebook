#include <iomanip>
#include "student.h"

/************************** STUDENT CLASS FUNCTIONS **************************/
Student::Student(const std::string &name)
	:studentName(name), pointsPoss(0), pointsEarned(0), extraPoints(0), currentGrade(0)
{
}

bool Student::operator<(const Student &student) const
{
	return this->studentName < student.getName();
}

bool Student::addExtraPoints(double extra)
{
	if(extra < 0)
	{
		return false;
	}
	extraPoints += extra;
	calculateGrade();
	return true;
}

bool Student::addAssignment(const Assignment &assign)
{
	if(!validNewAssignment(assign))
	{
		return false;
	}
	assignments.push_back(assign);
	calculateGrade();
	return true;
}

bool Student::insertAssignment(int assignNum, const Assignment &assign)
{
	// Is this a valid assignment number?
	if(assignNum <= 0 || assignments.size() < assignNum)
	{
		return false;
	}
	if(!validNewAssignment(assign))
	{
		return false;
	}
	assignments.insert(assignments.begin() + (assignNum-1), assign);
	calculateGrade();
	return true;
}

bool Student::editAssignmentGrade(int assignNum, double possible, double earned)
{
	// Is this a valid assignment number?
	if((assignNum - 1) < 0 || assignments.size() < assignNum)
	{
		return false;
	}

	// Store copy of the original assignment incase of failure
	Assignment origAssignment(assignments[assignNum-1]);

	// If updating a value fails, return false
	if(!(assignments[assignNum-1].updatePointsPossible(possible)) ||
	   !(assignments[assignNum-1].updatePointsEarned(earned)))
	{
		// Restore the assignment to the orignal value if anything was changed
		assignments[assignNum-1] = origAssignment;
		return false;
	}

	calculateGrade();
	return true;
}

bool Student::editAssignmentGrade(const std::string &assignName, double possible, double earned)
{
	// Find the assignment number and test to make sure it was found
	int assignNum = getAssignmentNumber(assignName);
	if(!assignNum)
	{
		return false;
	}
	else
	{
		return editAssignmentGrade(assignNum, possible, earned);
	}
}

bool Student::editAssignmentName(int assignNum, const std::string &newAssignName)
{
	// Is this a valid assignment number and a valid assignment name?
	if(assignNum < 0 || assignments.size() < assignNum || newAssignName == "INVALID ASSIGNMENT")
	{
		return false;
	}

	// If changing the name fails, return false
	if(!(assignments[assignNum-1].updateName(newAssignName)))
	{
		return false;
	}
	return true;
}

bool Student::deleteAssignment(int assignNum)
{
	// Is this a valid assignment number?
	if(assignNum <= 0 || assignments.size() < assignNum)
	{
		return false;
	}

	assignments.erase(assignments.begin()+assignNum-1);
	calculateGrade();
	return true;
}

bool Student::deleteAssignment(const std::string &assignName)
{
	// getAssignmentNumber returns 0 if the assignment is not found
	int assignNum = getAssignmentNumber(assignName);
	if(!assignNum)
	{
		return false;
	}

	// Was the assignment successfully deleted?
	if(!deleteAssignment(assignNum))
	{
		return false;
	}
	return true;
}

std::string Student::getName() const
{
	return studentName;
}

double Student::getPointsPossible() const
{
	return pointsPoss;
}

double Student::getPointsEarned() const
{
	return pointsEarned;
}

double Student::getExtraPoints() const
{
	return extraPoints;
}

double Student::getGrade() const
{
	return currentGrade;
}

Assignment Student::getAssignment(const std::string &assignName) const
{
	// Find an assignment by the name of assignName
	for(std::vector<Assignment>::const_iterator i = assignments.begin();
		i != assignments.end(); ++i)
	{
		if(i->getName() == assignName)
		{
			return *i;
		}
	}

	// If the assignment doesn't exist, return empty Assignment with "INVALID" name
	return Assignment(0,0,"INVALID ASSIGNMENT");
}

Assignment Student::getAssignment(int assignNum) const
{
	// Is this a valid assignment number?
	if(assignNum < 0 || assignNum > assignments.size())
	{
		return Assignment(0,0,"INVALID ASSIGNMENT");
	}

	return assignments[assignNum];
}

double Student::getAssignmentGrade(const std::string &assignName) const
{
	// If the student doesn't have the assignment, return -1
	if(!hasAssignment(assignName))
	{
		return -1;
	}
	return getAssignment(assignName).getPointsEarned();
}

std::vector<Assignment> Student::getAllAssignments() const
{
	return assignments;
}

void Student::calculateGrade()
{
	double possible = 0;
	double earned = 0;
	for(std::vector<Assignment>::const_iterator i = assignments.begin();
		i != assignments.end(); ++i)
	{
		possible += i->getPointsPossible();
		earned += i->getPointsEarned();
	}
	pointsPoss = possible;
	pointsEarned = earned;
	currentGrade = (pointsEarned + extraPoints) / pointsPoss;
}

bool Student::validNewAssignment(const Assignment &assign) const
{
	// Points possible and points earned must be positive integers
	if(assign.getPointsPossible() < 0 || assign.getPointsEarned() < 0)
	{
		return false;
	}

	// Don't allow assignments named "INVALID" to be added as it has special meaning.
	// "INVALID" assignments are used to signal an error finding an Assignment
	// by other member functions.
	if(assign.getName() == "INVALID ASSIGNMENT")
	{
		return false;
	}

	// Does an assignment with this name already exist for this student?
	for(std::vector<Assignment>::const_iterator i = assignments.begin();
		i != assignments.end(); ++i)
	{
		if(i->getName() == assign.getName())
		{
			return false;
		}
	}
	return true;
}

int Student::getAssignmentNumber(const std::string &assignName) const
{
	int assignmentNumber = 1;
	// Find the matching assignment name and return the assignment number
	for(std::vector<Assignment>::const_iterator i = assignments.begin();
		i != assignments.end(); ++i)
	{
		if(i->getName() == assignName)
		{
			return assignmentNumber;
		}
		else
		{
			++assignmentNumber;
		}
	}
	// If the assignment wasn't found, return 0
	return 0;
}

bool Student::hasAssignment(const std::string &assignName) const
{
	// Loop through the Student's assignments
	for(std::vector<Assignment>::const_iterator i = assignments.begin();
		i != assignments.end(); ++i)
	{
		// If an assignment with a matching name is found, return true
		if(i->getName() == assignName)
		{
			return true;
		}
	}
	// If the assignment wasn't found, return false
	return false;
}

void Student::DEBUG_printAssignments() const
{
	std::cout << "Name: " << studentName << std::endl;
	for(std::vector<Assignment>::const_iterator i = assignments.begin();
		i != assignments.end(); ++i)
	{
		std::cout << i->getName() << ": " << i->getPointsEarned();
		std::cout << "/" << i->getPointsPossible() << std::endl;
	}
	std::cout << "Grade: " << pointsEarned << "/" << pointsPoss << " -- ";
	std::cout << std::setprecision(4) << currentGrade * 100 << "%" << std::endl;
}
