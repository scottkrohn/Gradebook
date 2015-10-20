#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "assignment.h"
#include <vector>
#include <stdexcept>
#include <iostream>

class Student
{
public:
	Student(const std::string &name);

	bool operator<(const Student &student) const;

	// Adding assignments/extra points
	bool addExtraPoints(double extra);
	bool addAssignment(const Assignment &assign); // Add and end of assignment list
	// Inset as specified location in assignment list
	bool insertAssignment(int assignNum, const Assignment &assign);

	// Editing assignments
	bool editAssignmentGrade(int assignNum, double possible, double earned);
	bool editAssignmentGrade(const std::string &assignName, double possible, double earned);
	bool editAssignmentName(int assignNum, const std::string &newAssignName);

	// Removing assignments
	bool deleteAssignment(int assignNum);
	bool deleteAssignment(const std::string &assignName);

	// Getting grades
	std::string getName() const;
	double getPointsPossible() const;
	double getPointsEarned() const;
	double getExtraPoints() const;
	double getGrade() const;

	// Getting assignments
	Assignment getAssignment(const std::string &assignName) const;
	Assignment getAssignment(int assignNum) const;
	double getAssignmentGrade(const std::string &assignName) const;
	std::vector<Assignment> getAllAssignments() const;
	int getAssignmentNumber(const std::string &assignName) const;
	bool hasAssignment(const std::string &assignName) const;

	// DEBUG FUNCTIONS
	void DEBUG_printAssignments() const;
private:
	std::string studentName;
	double pointsPoss;
	double pointsEarned;
	double extraPoints;
	double currentGrade;
	std::vector<Assignment> assignments;

	// Calculate the current grade based on current points
	void calculateGrade();

	// Check if an assignment has reasonable values
	bool validNewAssignment(const Assignment &assign) const;
};

#endif
