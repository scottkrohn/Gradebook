#include "editstudentdialog.h"
#include <QMessageBox>
#include <QString>
#include <vector>
#include "assignment.h"
#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

EditStudentDialog::EditStudentDialog(Gradebook *book, Student *stu, QWidget *parent)
	:QDialog(parent),
	gradebook(book),
	student(stu),
	editedStudent(Student("")),
	hasBeenEdited(false),
	titleLabel(new QLabel("<font size=4><b>Edit Student</b></font>", this)),
	//studentNameLabel(new QLabel(QString((stu->getName()).c_str()), this)),
	currentGradeLabel(new QLabel("", this)),
	currentPointsLabel(new QLabel("", this)),
	extraCreditLabel(new QLabel("", this)),
	totalPointsLabel(new QLabel("", this)),
	assignmentList(new QListWidget(this)),
	editAssignment(new QPushButton("Edit Assignment", this)),
	addAssignment(new QPushButton("Add Assignment", this)),
	deleteAssignment(new QPushButton("Delete Assignment", this)),
	addExtraPoints(new QPushButton("Add Extra Points", this)),
	saveButton(new QPushButton("Save", this)),
	closeButton(new QPushButton("Close", this)),
	addDialog(new AddIndvAssignmentDialog(NULL, this)),
	editDialog(new EditIndvAssignmentDialog(NULL, "", this)),
	extraPointsDialog(new AddExtraPointsDialog(NULL, this)),
	messageWin(new QMessageBox(this)),
	confirmWin(new QMessageBox(this))
{
	if(stu)
	{
		editedStudent = *stu;
		studentNameLabel = new QLabel(QString((stu->getName()).c_str()), this);
	}
	else
	{
		studentNameLabel = new QLabel("", this);
	}
	titleLabel->setAlignment(Qt::AlignHCenter);
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);
	studentNameLabel->setAlignment(Qt::AlignHCenter);
	currentGradeLabel->setAlignment(Qt::AlignLeft);
	currentPointsLabel->setAlignment(Qt::AlignLeft);
	extraCreditLabel->setAlignment(Qt::AlignLeft);

	QHBoxLayout *topLayout = new QHBoxLayout;
	QHBoxLayout *midLayout = new QHBoxLayout;
	QHBoxLayout *botLayout = new QHBoxLayout;

	QVBoxLayout *mainLayout = new QVBoxLayout;
	QVBoxLayout *leftLayout = new QVBoxLayout;
	QVBoxLayout *rightLayout = new QVBoxLayout;

	mainLayout->addLayout(topLayout);
	mainLayout->addLayout(midLayout);
	mainLayout->addLayout(botLayout);

	topLayout->addWidget(titleLabel);
	midLayout->addLayout(leftLayout);
	midLayout->addLayout(rightLayout);
	botLayout->addWidget(saveButton);
	botLayout->addWidget(closeButton);

	leftLayout->addStretch(3);
	leftLayout->addWidget(editAssignment);
	leftLayout->addWidget(addAssignment);
	leftLayout->addWidget(deleteAssignment);
	leftLayout->addWidget(addExtraPoints);
	leftLayout->addWidget(currentGradeLabel);
	leftLayout->addWidget(currentPointsLabel);
	leftLayout->addWidget(extraCreditLabel);
	leftLayout->addWidget(totalPointsLabel);
	leftLayout->addStretch(1);

	rightLayout->addWidget(studentNameLabel);
	rightLayout->addWidget(assignmentList);
	rightLayout->addSpacing(30);

	setLayout(mainLayout);
	setWindowTitle("Edit Student");
	loadAssignments();

	connectWidgets();
	if(gradebook && student)
	{
		loadStats();
	}
	resize(sizeHint());
}

void EditStudentDialog::changeStudent(Gradebook *book, Student *stu)
{
	gradebook = book;
	student = stu;
	editedStudent = *stu;
	assignmentList->clear();
	loadAssignments();
	loadStats();
}

void EditStudentDialog::connectWidgets()
{
	connect(closeButton, SIGNAL(clicked()), this, SLOT(closeConfirm()));
	connect(addAssignment, SIGNAL(clicked()), this, SLOT(addAssignmentSlot()));
	connect(addDialog, SIGNAL(assignmentAdded()), this, SLOT(setEdited()));
	connect(addDialog, SIGNAL(assignmentAdded()), this, SLOT(updateStudentInfo()));
	connect(editDialog, SIGNAL(assignmentEdited()), this, SLOT(setEdited()));
	connect(editDialog, SIGNAL(assignmentEdited()), this, SLOT(updateStudentInfo()));
	connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
	connect(editAssignment, SIGNAL(clicked()), this, SLOT(editAssignmentSlot()));
	connect(deleteAssignment, SIGNAL(clicked()), this, SLOT(deleteAssignmentSlot()));
	connect(this, SIGNAL(assignmentEdited()), this, SLOT(setEdited()));
	connect(addExtraPoints, SIGNAL(clicked()), this, SLOT(addExtraPointsSlot()));
	connect(extraPointsDialog, SIGNAL(extraPointsAdded()), this, SLOT(setEdited()));
	connect(extraPointsDialog, SIGNAL(extraPointsAdded()), this, SLOT(updateStudentInfo()));
}

void EditStudentDialog::loadAssignments()
{
	std::vector<Assignment> assignments(editedStudent.getAllAssignments());
	for(std::vector<Assignment>::const_iterator i = assignments.begin();
		i != assignments.end(); ++i)
	{
		QString pointsPossible(QString::number(i->getPointsPossible()));
		QString pointsEarned(QString::number(i->getPointsEarned()));
		std::string assignName = i->getName();
		QString assignmentInfo(pointsEarned + "/" + pointsPossible);
		assignmentInfo += "\t";
		assignmentInfo += assignName.c_str();
		assignmentList->addItem(assignmentInfo);
	}

	double grade = editedStudent.getGrade()*100;
	currentGradeLabel->setText(QString::number(grade));
}

void EditStudentDialog::loadStats()
{
	QString grade(QString::number((editedStudent.getGrade() * 100)));
	QString pointsEarned(QString::number(editedStudent.getPointsEarned()));
	QString pointsPossible(QString::number(editedStudent.getPointsPossible()));
	QString totalPoints(QString::number(editedStudent.getPointsEarned() + editedStudent.getExtraPoints()));
	QString extraPoints(QString::number(editedStudent.getExtraPoints()));

	currentGradeLabel->setText("Current Grade: " + grade + "%");
	currentPointsLabel->setText("Earned Points: " + pointsEarned + "/" + pointsPossible);
	extraCreditLabel->setText("Extra Credit:  " + extraPoints);
	totalPointsLabel->setText("Total Points:  " + totalPoints + "/" + pointsPossible);
	studentNameLabel->setText(editedStudent.getName().c_str());
}
/**********************EditStudentDialog Private Slots************************/
void EditStudentDialog::closeConfirm()
{
	// Has the student been edited, but not saved? If so, prompt to save.
	if(hasBeenEdited)
	{
		// Display a confirmation windoow asking the user what they want to do.
		//QMessageBox *confirmWin = new QMessageBox(this);
		confirmWin->setWindowTitle("Confirm Close");
		confirmWin->setText("You have unsaved changes, do you want to save?");
		confirmWin->setStandardButtons(QMessageBox::Yes | QMessageBox::No |QMessageBox::Cancel);

		// Get the result from the user's input and respond accordingly
		int confirmResult = confirmWin->exec();
		if(confirmResult == QMessageBox::Yes)
		{
			save();
			emit accepted();
		}
		else if(confirmResult == QMessageBox::No)
		{
			hasBeenEdited = false;
			emit rejected();
		}
		else if(confirmResult == QMessageBox::Cancel)
		{
			return;
		}
	}
	QDialog::close();
}

void EditStudentDialog::addAssignmentSlot()
{
	addDialog->changeStudent(&editedStudent);
	addDialog->exec();
}

void EditStudentDialog::editAssignmentSlot()
{
	if(assignmentList->currentItem() == NULL)
	{
		messageWin->setWindowTitle("Notice");
		messageWin->setText("No assignment has been selected to edit.");
		messageWin->exec();
		return;
	}
	Assignment assign(editedStudent.getAssignment(assignmentList->currentRow()));
	editDialog->changeAssignment(&editedStudent, assign.getName());
	editDialog->exec();
}

void EditStudentDialog::deleteAssignmentSlot()
{
	if(assignmentList->currentItem() == NULL)
	{
		messageWin->setWindowTitle("Notice");
		messageWin->setText("No assignment has been selected to delete.");
		messageWin->exec();
		return;
	}

	Assignment assign(editedStudent.getAssignment(assignmentList->currentRow()));
	std::string assignmentName(assign.getName());
	confirmWin->setWindowTitle("Confirm Delete");
	confirmWin->setText("Are you sure you want to delete \"" + QString(assignmentName.c_str()));
	confirmWin->setStandardButtons(QMessageBox::Yes|QMessageBox::Cancel);
	if(confirmWin->exec() == QMessageBox::Yes)
	{
		if(!editedStudent.deleteAssignment(assignmentName))
		{
			throw std::runtime_error("Error while delete assignment from student.");
		}
		emit assignmentEdited();
		updateStudentInfo();
	}
	else
	{
		return;
	}
}

void EditStudentDialog::addExtraPointsSlot()
{
	extraPointsDialog->changeStudent(&editedStudent);
	extraPointsDialog->exec();
}

void EditStudentDialog::setEdited()
{
	hasBeenEdited = true;
}

void EditStudentDialog::save()
{
	messageWin->setWindowTitle("Confirmation");
	if(hasBeenEdited)
	{
		*student = editedStudent;
		gradebook->writeToFile(gradebook->getCurrentFilename());
		hasBeenEdited = false;
		messageWin->setText("Student has been successfully saved!");
	}
	else
	{
		messageWin->setText("There are no changes to save.");
	}
	emit gradebookSaved();
	messageWin->exec();
}

void EditStudentDialog::updateStudentInfo()
{
	assignmentList->clear();
	loadAssignments();
	loadStats();
}
