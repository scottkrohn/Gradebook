#include "viewclassdialog.h"
#include <QMessageBox>
#include "addassignmentdialog.h"
#include <QLabel>
#include <string>
#include <QPushButton>
#include <QString>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <vector>
#include <QFrame>
#include <QFont>

ViewClassDialog::ViewClassDialog(Gradebook *book, QWidget *parent)
	:QDialog(parent),
	gradebook(book),
	editedGradebook(*book),
	hasBeenEdited(false),
	titleLabel(new QLabel("", this)),
	listViewLabel(new QLabel("Students", this)),
	editStudentButton(new QPushButton("Edit Student", this)),
	addAssignmentButton(new QPushButton("Add Assignment", this)),
	editAssignmentButton(new QPushButton("Edit Assignment Total", this)),
	editAssignmentEarnedButton(new QPushButton("Edit Assignment Earned", this)),
	deleteAssignmentButton(new QPushButton("Delete Assignment", this)),
	addExtraPointsButton(new QPushButton("Add Extra Credit", this)),
	viewAllGradesButton(new QPushButton("View All Grades", this)),
	addStudentButton(new QPushButton("Add Student", this)),
	removeStudentButton(new QPushButton("Remove Student", this)),
	saveButton(new QPushButton("Save", this)),
	closeButton(new QPushButton("Close", this)),
	messageWin(new QMessageBox(this)),
	addAssignmentDialog(new AddAssignmentDialog(&editedGradebook, this)),
	editStudentDialog(new EditStudentDialog(NULL, NULL, this)),
	addStudentDialog(new AddStudentDialog(NULL, this)),
	deleteStudentDialog(new DeleteStudentDialog("", NULL, this)),
	editAllAssignmentsDialog(new EditAllAssignmentsDialog(NULL, this)),
	editScoresDialog(new EditCommonDialog(NULL, this)),
	deleteAllAssignmentDialog(new DeleteAllAssignmentDialog(NULL, this)),
	addAllExtraPoints(new AddAllExtraPoints(NULL, this)),
	viewGradesTable(new ViewGradesTable(this)),
	studentList(new QListWidget(this))
{
	setWindowTitle("View Class");

	titleLabel->setAlignment(Qt::AlignHCenter);
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);
	listViewLabel->setAlignment(Qt::AlignHCenter);

	QVBoxLayout *leftLayout = new QVBoxLayout;
	QVBoxLayout *rightLayout = new QVBoxLayout;

	QHBoxLayout *bottomLayout = new QHBoxLayout;

	QVBoxLayout *mainVertLayout = new QVBoxLayout;
	QHBoxLayout *mainHorLayout = new QHBoxLayout;

	leftLayout->addSpacing(40);
	leftLayout->addWidget(editStudentButton);
	leftLayout->addWidget(addAssignmentButton);
	leftLayout->addWidget(editAssignmentButton);
	leftLayout->addWidget(editAssignmentEarnedButton);
	leftLayout->addWidget(deleteAssignmentButton);
	leftLayout->addWidget(addExtraPointsButton);
	leftLayout->addWidget(viewAllGradesButton);
	leftLayout->addStretch(1);

	rightLayout->addSpacing(20);
	rightLayout->addWidget(listViewLabel);
	rightLayout->addWidget(studentList);
	rightLayout->addWidget(addStudentButton);
	rightLayout->addWidget(removeStudentButton);

	bottomLayout->addWidget(saveButton);
	bottomLayout->addWidget(closeButton);

	mainHorLayout->addLayout(leftLayout);
	mainHorLayout->addLayout(rightLayout);

	mainVertLayout->addWidget(titleLabel);
	mainVertLayout->addLayout(mainHorLayout);
	mainVertLayout->addSpacing(20);
	mainVertLayout->addLayout(bottomLayout);

	setLayout(mainVertLayout);
	connectWidgets();
	resize(sizeHint());
}

void ViewClassDialog::loadGradebook(Gradebook *book)
{
	gradebook = book;
	editedGradebook = *gradebook;

	std::string htmlClassname("<font size=4><b>");
	htmlClassname += editedGradebook.getClassName();
	htmlClassname += "</b></font>";
	titleLabel->setText(QString(htmlClassname.c_str()));

	addAssignmentDialog->changeGradebook(&editedGradebook);
	populateStudentList();
}

void ViewClassDialog::populateStudentList()
{
	studentList->clear();
	std::vector<Student> students(editedGradebook.getAllStudents());
	for(std::vector<Student>::const_iterator i = students.begin();
		i != students.end(); ++i)
	{
		studentList->addItem(QString((i->getName()).c_str()));
	}
}

void ViewClassDialog::connectWidgets()
{
	connect(closeButton, SIGNAL(clicked()), this, SLOT(closeWin()));
	connect(addStudentButton, SIGNAL(clicked()), this, SLOT(addStudent()));
	connect(this, SIGNAL(accepted()), studentList, SLOT(clear()));
	connect(this, SIGNAL(rejected()), studentList, SLOT(clear()));
	connect(addAssignmentButton, SIGNAL(clicked()), this, SLOT(addAssignment()));
	connect(editStudentButton, SIGNAL(clicked()), this, SLOT(editStudent()));
	connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
	connect(addAssignmentDialog, SIGNAL(assignmentAdded()), this, SLOT(setEdited()));
	connect(addStudentDialog, SIGNAL(studentAdded()), this, SLOT(silentSave()));
	connect(addStudentDialog, SIGNAL(studentAdded()), this, SLOT(populateStudentList()));
	connect(removeStudentButton, SIGNAL(clicked()), this, SLOT(deleteStudent()));
	connect(deleteStudentDialog, SIGNAL(studentDeleted()), this, SLOT(silentSave()));
	connect(deleteStudentDialog, SIGNAL(studentDeleted()), this, SLOT(populateStudentList()));
	connect(editAssignmentButton, SIGNAL(clicked()), this, SLOT(editAssignment()));
	connect(editStudentDialog,  SIGNAL(gradebookSaved()), this, SLOT(loadRecentlySavedGradebook()));
	connect(editAllAssignmentsDialog, SIGNAL(saveGradebook()), this, SLOT(silentSave()));
	connect(deleteAssignmentButton, SIGNAL(clicked()), this, SLOT(deleteAssignment()));
	connect(deleteAllAssignmentDialog, SIGNAL(assignmentDeleted()), this, SLOT(silentSave()));
	connect(addExtraPointsButton, SIGNAL(clicked()), this, SLOT(addExtraPoints()));
	connect(addAllExtraPoints, SIGNAL(extraPointsAdded()), this, SLOT(silentSave()));
	connect(viewAllGradesButton, SIGNAL(clicked()), this, SLOT(viewAllGrades()));
	connect(editAssignmentEarnedButton, SIGNAL(clicked()), this, SLOT(editAssignmentEarned()));
	connect(editScoresDialog, SIGNAL(gradebookSaved()), this, SLOT(loadRecentlySavedGradebook()));
}

Student & ViewClassDialog::getSelectedStudent()
{
	QListWidgetItem *student(studentList->currentItem());
	std::string studentNameStr((student->text()).toAscii());
	return gradebook->getStudentRef(studentNameStr);
}

void ViewClassDialog::save()
{
	messageWin->setWindowTitle("Confirmation");
	if(hasBeenEdited)
	{
		*gradebook = editedGradebook;
		gradebook->writeToFile(gradebook->getCurrentFilename());
		hasBeenEdited = false;
		messageWin->setText("Gradebook has been successfully saved!");
	}
	else
	{
		messageWin->setText("There are no changes to save.");
	}
	messageWin->exec();
}

void ViewClassDialog::silentSave()
{
	*gradebook = editedGradebook;
	gradebook->writeToFile(gradebook->getCurrentFilename());
	hasBeenEdited = false;
}

void ViewClassDialog::loadRecentlySavedGradebook()
{
	editedGradebook = *gradebook;
}

bool ViewClassDialog::classIsEmpty()
{
	if(studentList->count() == 0)
	{
		return true;
	}
	return false;
}

void ViewClassDialog::closeWin()
{
	// Has the gradebook been edited but not saved? If so, prompt to save.
	if(hasBeenEdited)
	{
		QMessageBox *confirmWin = new QMessageBox(this);
		confirmWin->setWindowTitle("Confirm Close");
		confirmWin->setText("You have unsaved changes, do you want to save?");
		confirmWin->setStandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

		int confirmResult = confirmWin->exec();
		if(confirmResult == QMessageBox::Yes)
		{
			save();
			emit accepted();
		}
		else if(confirmResult == QMessageBox::No)
		{
			emit rejected();
		}
		else if(confirmResult == QMessageBox::Cancel)
		{
			return;
		}
	}
	QDialog::close();
}

void ViewClassDialog::setEdited()
{
	hasBeenEdited = true;
}

void ViewClassDialog::addAssignment()
{
	if(classIsEmpty())
	{
		messageWin->setWindowTitle("Notice");
		messageWin->setText("You cannot add an assignment to an empty class.");
		messageWin->exec();
		return;
	}
	addAssignmentDialog->exec();
}

void ViewClassDialog::editStudent()
{
	if(studentList->count() == 0 || studentList->currentItem() == NULL)
	{
		messageWin->setWindowTitle("Notice");
		messageWin->setText("No student has been selected to edit.");
		messageWin->exec();
		return;
	}
	Student &student(getSelectedStudent());
	editStudentDialog->changeStudent(gradebook, &student);
	editStudentDialog->exec();
}

void ViewClassDialog::addStudent()
{
	addStudentDialog->changeGradebook(&editedGradebook);
	addStudentDialog->exec();
}

void ViewClassDialog::deleteStudent()
{
	if(studentList->currentItem() == NULL)
	{
		messageWin->setWindowTitle("Notice");
		messageWin->setText("No student has been selected to delete.");
		messageWin->exec();
		return;
	}
	deleteStudentDialog->changeStudent(getSelectedStudent().getName(), &editedGradebook);
	deleteStudentDialog->exec();
}

void ViewClassDialog::editAssignment()
{
	editAllAssignmentsDialog->changeGradebook(&editedGradebook);
	editAllAssignmentsDialog->exec();
}

void ViewClassDialog::editAssignmentEarned()
{
	editScoresDialog->changeGradebook(gradebook);
	editScoresDialog->exec();
}

void ViewClassDialog::deleteAssignment()
{
	deleteAllAssignmentDialog->changeGradebook(&editedGradebook);
	deleteAllAssignmentDialog->exec();
}

void ViewClassDialog::addExtraPoints()
{
	if(editedGradebook.classSize() == 0)
	{
		messageWin->setWindowTitle("Notice");
		messageWin->setText("You cannot add extra credit to an empty class.");
		messageWin->exec();
		return;
	}
	addAllExtraPoints->changeGradebook(&editedGradebook);
	addAllExtraPoints->exec();
}

void ViewClassDialog::viewAllGrades()
{
	GradingReport report(editedGradebook);
	viewGradesTable->changeGradeReport(report);
	viewGradesTable->exec();
}
