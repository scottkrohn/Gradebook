#include "editallassignmentsdialog.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDoubleValidator>
#include <QMessageBox>

EditAllAssignmentsDialog::EditAllAssignmentsDialog(Gradebook *book, QWidget *parent)
	:QDialog(parent),
	gradebook(book),
	titleLabel(new QLabel("<font size=4><b>Edit Common Assignments</b></font>", this)),
	commonLabel(new QLabel("Common Assignments", this)),
	assignmentList(new QListWidget(this)),
	editButton(new QPushButton("Edit Assignment", this)),
	closeButton(new QPushButton("Cancel", this)),
	editWindow(new EditMultipleAssignments("", NULL, this)),
	messageWin(new QMessageBox(this))
{
	setWindowTitle("Edit Common Assignments");
	titleLabel->setAlignment(Qt::AlignHCenter);
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);
	commonLabel->setAlignment(Qt::AlignHCenter);

	QVBoxLayout *vertLayout = new QVBoxLayout;
	QHBoxLayout *botLayout = new QHBoxLayout;

	botLayout->addWidget(closeButton);
	botLayout->addWidget(editButton);

	vertLayout->addWidget(titleLabel);
	vertLayout->addWidget(commonLabel);
	vertLayout->addWidget(assignmentList);
	vertLayout->addLayout(botLayout);

	connectWidgets();
	if(gradebook)
	{
		populateAssignments();
	}
	setLayout(vertLayout);
	resize(sizeHint());
}

// Change the gradebook on which the dialog is listing common assignments
void EditAllAssignmentsDialog::changeGradebook(Gradebook *book)
{
	gradebook = book;
	populateAssignments();
}

void EditAllAssignmentsDialog::connectWidgets()
{
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(editButton, SIGNAL(clicked()), this, SLOT(editAssignment()));
	connect(editWindow, SIGNAL(saveGradebook()), this, SLOT(emitSaveGradebook()));
	connect(editWindow, SIGNAL(editComplete()), this, SLOT(close()));
}

// List all assignments common to students in the gradebook
void EditAllAssignmentsDialog::populateAssignments()
{
	assignmentList->clear();
	std::vector<Assignment> assignments(gradebook->getCommonAssignments());
	for(std::vector<Assignment>::const_iterator i = assignments.begin();
		i != assignments.end(); ++i)
	{
		assignmentList->addItem(QString(i->getName().c_str()));
	}
}

// Get the name of the selected assignment from the assignmentList.
// Pass the name of the assignment and the current gradebook to the editWindow
void EditAllAssignmentsDialog::editAssignment()
{
	if(assignmentList->currentItem() == NULL)
	{
		messageWin->setWindowTitle("ALERT");
		messageWin->setText("No assignment has been selected.");
		messageWin->exec();
		return;
	}
	QString assignmentName(assignmentList->currentItem()->text());
	std::string assignmentNameStr(assignmentName.toAscii());
	editWindow->changeAssignment(assignmentNameStr, gradebook);
	editWindow->exec();
}

void EditAllAssignmentsDialog::close()
{
	assignmentList->clear();
	QDialog::close();
}

// Emits a signal to notify the ViewClassDialog that the gradebook needs to be saved
void EditAllAssignmentsDialog::emitSaveGradebook()
{
	emit saveGradebook();
}

/************************* EditMultipleAssignments ***************************/
EditMultipleAssignments::EditMultipleAssignments(const std::string &assignName,
												 Gradebook *book, QWidget *parent)
	:QDialog(parent),
	gradebook(book),
	assignmentName(assignName),
	titleLabel(new QLabel("<font size=3><b>Edit Multiple Assignments</b></font>", this)),
	assignNameLabel(new QLabel("", this)),
	pointValueLabel(new QLabel("", this)),
	boxLabel(new QLabel("New Point Value:", this)),
	pointsBox(new QLineEdit(this)),
	saveButton(new QPushButton("Save", this)),
	cancelButton(new QPushButton("Cancel", this)),
	messageWin(new QMessageBox(this))
{
	setWindowTitle("Edit Assignment");
	titleLabel->setAlignment(Qt::AlignHCenter);
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);

	assignNameLabel->setAlignment(Qt::AlignHCenter);
	pointValueLabel->setAlignment(Qt::AlignHCenter);

	QVBoxLayout *vertLayout = new QVBoxLayout;
	QHBoxLayout *botLayout = new QHBoxLayout;
	QHBoxLayout *midLayout = new QHBoxLayout;

	botLayout->addWidget(cancelButton);
	botLayout->addWidget(saveButton);

	midLayout->addWidget(boxLabel);
	midLayout->addWidget(pointsBox);

	vertLayout->addWidget(titleLabel);
	vertLayout->addWidget(assignNameLabel);
	vertLayout->addWidget(pointValueLabel);
	vertLayout->addLayout(midLayout);
	vertLayout->addLayout(botLayout);

	setLayout(vertLayout);

	saveButton->setEnabled(false);
	pointsBox->setValidator(new QDoubleValidator(this));
	if(gradebook)
	{
		loadAssignmentData();
	}
	connectWidgets();
	resize(sizeHint());
}

// Change the assignment(and possibly gradebook) on which the edit is being done
void EditMultipleAssignments::changeAssignment(const std::string &assignName, Gradebook *book)
{
	gradebook = book;
	assignmentName = assignName;
	loadAssignmentData();
}

void EditMultipleAssignments::connectWidgets()
{
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(pointsBox, SIGNAL(textChanged(QString)), this, SLOT(enableSaveButton(QString)));
	connect(saveButton, SIGNAL(clicked()), this, SLOT(editAssignment()));
}

// Load the name and current points of the assignment being edited, display them
void EditMultipleAssignments::loadAssignmentData()
{
	std::vector<Assignment> commonAssignments(gradebook->getCommonAssignments());
	// Create an assignment object to hold a copy of the assignment that's being edited
	Assignment editedAssignment(0,0,"");
	// Loop through the gradebook's common assignments to find a match with assignmentName
	for(std::vector<Assignment>::const_iterator i = commonAssignments.begin();
		i != commonAssignments.end(); ++i)
	{
		if(i->getName() == assignmentName)
		{
			editedAssignment = *i;
		}
	}

	// Set up the labels with the correct info, resize the window if necessary
	assignNameLabel->setText("Name: " + QString(editedAssignment.getName().c_str()));
	pointValueLabel->setText("Point Value: " + QString::number(editedAssignment.getPointsPossible()));
	resize(sizeHint());
}

// Only enable the save button if the pointsBox has acceptable text entered
void EditMultipleAssignments::enableSaveButton(const QString &text)
{
	if(text.isEmpty())
	{
		saveButton->setEnabled(false);
	}
	else
	{
		saveButton->setEnabled(true);
	}
}

// Get the point value entered by the user, edit the assignment if the value entered
// is acceptable. Emit signals notifying the calling dialog that the assignment
// as successfully edited.
void EditMultipleAssignments::editAssignment()
{
	QString stringPointValue(pointsBox->text());
	double newPointValue(stringPointValue.toDouble());

	// Is the point value entered greater than zero?
	if(newPointValue <= 0)	// Error, display alert
	{
		messageWin->setWindowTitle("ALERT");
		messageWin->setText("You must enter a point value above zero.");
		messageWin->exec();
		pointsBox->clear();
		return;
	}
	else	// Accept new point value was entered, edit assignment
	{
		messageWin->setWindowTitle("Success!");
		messageWin->setText("Points successfully saved!");
		messageWin->exec();
		gradebook->editPointsPossibleAll(assignmentName, newPointValue);
		save();
		close();
		emit editComplete();
	}
}

void EditMultipleAssignments::close()
{
	pointsBox->clear();
	QDialog::close();
}

void EditMultipleAssignments::save()
{
	emit saveGradebook();
}


