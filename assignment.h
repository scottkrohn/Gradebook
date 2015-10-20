#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <string>
#include <stdexcept>

/*	An assignment is a simple class that stores a grade for a Student.
	It allows the user to create an Assignment by supplying a possible
	points value and a points earned value. The points possible and points
	earned values can be changed. The user can get the points possible and
	points earned.
*/
class Assignment
{
public:
	Assignment(double possible, double earned, const std::string &name);

	// Copy constructor
	Assignment(const Assignment &assign);
	// Assignment operator
	Assignment & operator=(const Assignment &assign);
	// Less than operator for sorting
	bool operator<(const Assignment &assign);
	const bool operator<(const Assignment &assign) const;

	// Update assignment values
	bool updatePointsEarned(double earned);
	bool updatePointsPossible(double possible);
	bool updateName(const std::string &newAssignName);
	bool updateAssignmentNumber(int num);

	// Get assignment values
	double getGrade() const;
	std::string getName() const;
	double getPointsPossible() const;
	double getPointsEarned() const;
	int getAssignmentNumber() const;
private:
	double pointsPoss;
	double pointsEarned;
	int assignmentNumber;
	std::string assignmentName;
};

#endif
