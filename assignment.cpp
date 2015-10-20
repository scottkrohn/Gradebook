#include "assignment.h"

/************************ ASSIGNMENT CLASS FUNCTIONS *************************/
Assignment::Assignment(double possible, double earned, const std::string &name)
	:pointsPoss(possible), pointsEarned(earned), assignmentName(name)
{
	// Are the initial points values invalid?
	if(possible < 0 || earned < 0)
	{
		throw std::runtime_error("Invalid initial argument for Assignment.");
	}
}

Assignment::Assignment(const Assignment &assign)
{
	this->pointsPoss = assign.pointsPoss;
	this->pointsEarned = assign.pointsEarned;
	this->assignmentName = assign.assignmentName;
}

Assignment & Assignment::operator=(const Assignment &assign)
{
	this->pointsPoss = assign.pointsPoss;
	this->pointsEarned = assign.pointsEarned;
	this->assignmentName = assign.assignmentName;
	return *this;
}

bool Assignment::operator<(const Assignment &assign)
{
	return assignmentName < assign.getName();
}

const bool Assignment::operator<(const Assignment &assign) const
{
	return assignmentName < assign.getName();
}

bool Assignment::updatePointsEarned(double earned)
{
	// Is the earned amount valid?
	if(earned < 0)
	{
		return false;
	}
	pointsEarned = earned;
	return true;
}

bool Assignment::updatePointsPossible(double possible)
{
	// Is the possible amount valid?
	if(possible < 0)
	{
		return false;
	}
	pointsPoss = possible;
	return true;
}

bool Assignment::updateName(const std::string &newAssignName)
{
	if(newAssignName == "INVALID ASSIGNMENT")
	{
		return false;
	}
	assignmentName = newAssignName;
}

bool Assignment::updateAssignmentNumber(int num)
{
	if(num <= 0)
	{
		return false;
	}
	assignmentNumber = num;
	return true;
}

double Assignment::getGrade() const
{
	return pointsEarned / pointsPoss;
}

std::string Assignment::getName() const
{
	return assignmentName;
}

double Assignment::getPointsPossible() const
{
	return pointsPoss;
}

double Assignment::getPointsEarned() const
{
	return pointsEarned;
}
int Assignment::getAssignmentNumber() const
{
	return assignmentNumber;
}


