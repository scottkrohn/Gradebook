#ifndef VIEWALLGRADES_H
#define VIEWALLGRADES_H
#include <vector>
#include <QDialog>
#include <set>
#include <map>
#include "gradebook.h"
#include "assignment.h"
#include "student.h"
#include <string>
#include <utility>
#include <algorithm>

class QTableWidget;
class QLabel;
class QPushButton;
class QMessageBox;

/*	The AssignmentReport class will store an assignment name, the total point value
	of the assignment, and each students score on the assignment. If the student
	didn't have a score, it will store a negative number to indicate the student
	is exempt from the assignment.
*/
class AssignmentReport
{
public:
	AssignmentReport(const Assignment &assign);
	AssignmentReport() {}

	void addGrade(const std::string &studentName, double grade);
	std::string getAssignmentName() const;
	std::vector<std::pair<std::string,double> > getScores() const;

	void DEBUG_printAll() const;
private:
	std::string assignmentName;
	double pointsPossible;
	std::vector<std::pair<std::string,double> > grades;	// Will store the students name and thier grade

};
bool sortGradePair(const std::pair<std::string,double> &pairOne,
				   const std::pair<std::string,double> &pairTwo);

class GradingReport
{
public:
	GradingReport(const Gradebook &gradebook);
	GradingReport() {}

	void changeGradebook(const Gradebook &gradebook);
	std::map<std::string,AssignmentReport> getGrades() const;
	int getStudentCount() const;
	int getAssignmentCount() const;

	void DEBUG_printAll() const;
private:
	// first = assignment name, second = AssignmentReport containing student names/grades
	std::map<std::string,AssignmentReport> assignmentGrades;
	int studentCount;
	int assignmentCount;

	void loadGrades(const Gradebook &gradebook);
};

class ViewGradesTable: public QDialog
{
public:
	ViewGradesTable(const GradingReport &report, QWidget *parent = 0);
	ViewGradesTable(QWidget *parent = 0);
	~ViewGradesTable();

	void changeGradeReport(const GradingReport &report);
private:
	GradingReport grades;
	QTableWidget *gradesTable;

	void setTableSize(int rows, int columns);
	void loadGrades();
private slots:
};


#endif
