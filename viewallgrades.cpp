#include "viewallgrades.h"
#include <iostream>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include <QTableWidgetItem>

AssignmentReport::AssignmentReport(const Assignment &assign)
	:assignmentName(assign.getName()),
	pointsPossible(assign.getPointsPossible())
{
}

void AssignmentReport::addGrade(const std::string &studentName, double grade)
{
	grades.push_back(std::make_pair(studentName, grade));
	std::sort(grades.begin(), grades.end(), sortGradePair);
}

std::string AssignmentReport::getAssignmentName() const
{
	return assignmentName;
}

void AssignmentReport::DEBUG_printAll() const
{
	std::cout << "*** " << assignmentName << "  " << pointsPossible << " ***" << std::endl;
	for(std::vector<std::pair<std::string,double> >::const_iterator i = grades.begin();
		i != grades.end(); ++i)
	{
		std::cout << "\t" << i->first << " -> " << i->second << std::endl;
	}
}

// Comparison function used with the std::sort algorithm for pair<string,double>
bool sortGradePair(const std::pair<std::string,double> &pairOne, const std::pair<std::string,double> &pairTwo)
{
	return pairOne.first < pairTwo.first;
}


std::vector<std::pair<std::string,double> > AssignmentReport::getScores() const
{
	return grades;
}

/******************************************************************************/
GradingReport::GradingReport(const Gradebook &gradebook)
{
	loadGrades(gradebook);
}

void GradingReport::changeGradebook(const Gradebook &gradebook)
{
	assignmentGrades.clear();
	loadGrades(gradebook);
}

std::map<std::string,AssignmentReport> GradingReport::getGrades() const
{
	return assignmentGrades;
}

int GradingReport::getStudentCount() const
{
	return studentCount;
}

int GradingReport::getAssignmentCount() const
{
	return assignmentCount;
}

void GradingReport::loadGrades(const Gradebook &gradebook)
{
	// Create a vector of all the assignments and all the students in a gradebook
	std::vector<Assignment> allAssignments(gradebook.getAllAssignments());
	std::vector<Student> allStudents(gradebook.getAllStudents());

	// Set the student and assignment counts
	assignmentCount = allAssignments.size();
	studentCount = allStudents.size();

	// Loop through each assignment in the vector
	for(std::vector<Assignment>::const_iterator assignIter = allAssignments.begin();
		assignIter != allAssignments.end(); ++assignIter)
	{
		// Create an AssignmentReport object with the current assignment
		AssignmentReport report(*assignIter);
		// Loop through each student in the gradebook
		for(std::vector<Student>::const_iterator stuIter = allStudents.begin();
			stuIter != allStudents.end(); ++ stuIter)
		{
			// Add each student's grade for the current assignment to the report
			report.addGrade(stuIter->getName(), stuIter->getAssignmentGrade(assignIter->getName()));
		}
		// Add each assignment name and report object to the std::map
		assignmentGrades[report.getAssignmentName()] = report;
	}
}

void GradingReport::DEBUG_printAll() const
{
	for(std::map<std::string,AssignmentReport>::const_iterator i = assignmentGrades.begin();
		i != assignmentGrades.end(); ++i)
	{
		i->second.DEBUG_printAll();
	}
}

/******************************************************************************/
ViewGradesTable::ViewGradesTable(const GradingReport &report, QWidget *parent)
	:QDialog(parent),
	grades(report),
	gradesTable(new QTableWidget(this))
{
	QVBoxLayout *vertLayout = new QVBoxLayout;
	vertLayout->addWidget(gradesTable);
	setLayout(vertLayout);
}

ViewGradesTable::ViewGradesTable(QWidget *parent)
	:QDialog(parent),
	gradesTable(new QTableWidget(this))
{
	QVBoxLayout *vertLayout = new QVBoxLayout;
	vertLayout->addWidget(gradesTable);
	setLayout(vertLayout);
}

ViewGradesTable::~ViewGradesTable()
{
	delete gradesTable;
}

void ViewGradesTable::changeGradeReport(const GradingReport &report)
{
	grades = report;
	setTableSize(grades.getStudentCount() +1, grades.getAssignmentCount() +1);
	loadGrades();
}

void ViewGradesTable::setTableSize(int rows, int columns)
{
	gradesTable->clear();
	gradesTable->setRowCount(rows);
	gradesTable->setColumnCount(columns);
	resize(115*columns, 50*rows);
}

void ViewGradesTable::loadGrades()
{
	typedef std::map<std::string,AssignmentReport> AssignmentData;
	AssignmentData data = grades.getGrades();

	for(int rowCount = 0; rowCount != gradesTable->rowCount(); ++rowCount)
	{
		int colCount = 0;
		for(AssignmentData::const_iterator i = data.begin(); i != data.end(); ++i)
		{
			if(rowCount == 0 && colCount == 0)
			{
				gradesTable->setItem(rowCount, colCount, new QTableWidgetItem("Name"));
				++colCount;
			}
			if(rowCount == 0)
			{
				gradesTable->setItem(rowCount, colCount, new QTableWidgetItem(i->first.c_str()));
			}

			if(rowCount > 0)
			{
				std::vector<std::pair<std::string,double> > assignData = i->second.getScores();
				if(colCount == 0)
				{
					gradesTable->setItem(rowCount, colCount, new QTableWidgetItem(assignData[rowCount-1].first.c_str()));

				}
				QString gradeString;
				double pointValue = assignData[rowCount-1].second;
				if(pointValue >= 0)
				{
					gradeString = QString::number(pointValue);
				}
				else
				{
					gradeString = "-";
				}
				gradesTable->setItem(rowCount, colCount+1, new QTableWidgetItem(gradeString));
			}
			++colCount;
		}
	}
}
