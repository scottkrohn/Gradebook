#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include "student.h"
#include "assignment.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

class Gradebook
{
public:
	Gradebook(const std::string &name);
	Gradebook();

	// Adding/removing students
	bool addStudent(const std::string &studentName);
	bool addStudent(const Student &student);
	bool removeStudent(const std::string &studentName);

	// Adding/removing assignments
	bool addAssignmentAll(const Assignment &assign);
	bool addAssignment(const std::string &studentName, const Assignment &assign);
	bool deleteAssignmentAll(const std::string &assignName);
	bool deleteAssignment(const std::string &studentName,
						  const std::string &assignName);
	bool addExtraPointsAll(int points);
	bool addExtraPoints(const std::string &studentName, int points);

	// Editing existing assignments
	bool editPointsPossibleAll(const std::string &assignName, double possible);
	bool editPointsPossible(const std::string &studentName,
							const std::string &assignName, double possible);
	bool editAssignment(const std::string &studentName, const std::string &assignName,
						double possible, double earned);


	// Gathering functions
	int classSize() const;
	Student getStudent(const std::string &studentName) const;
	Student & getStudentRef(const std::string &studentName);
	std::vector<Student> getAllStudents() const;
	std::string getClassName() const;
	std::string getCurrentFilename() const;
	std::vector<Assignment> getCommonAssignments() const;
	std::vector<Assignment> getAllAssignments() const;

	// Writing/reading files
	bool writeToFile(const std::string &filename) const;
	bool loadFromFile(const std::string &filename);

	// DEBUG FUNCTIONS
	void DEBUG_printStudentNames() const;
	void DEBUG_printStudentGrades() const;
	void DEBUG_printStudentAssignments() const;
private:
	std::vector<Student> students;
	std::string classname;
	std::string currentFilename;

	bool studentExists(const std::string &studentName) const;
	void sortStudents();
	void loadNewGradebook(const Gradebook &newGradebook);
};

std::string lowercaseString(const std::string &origStr);
int stringToInt(const std::string &str);
double stringToDouble(const std::string &str);
#endif
