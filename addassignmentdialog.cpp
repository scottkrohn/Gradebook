#include "addassignmentdialog.h"
#include <QMessageBox>
#include <QLabel>
#include <vector>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QString>
#include <QIntValidator>
#include <QDoubleValidator>

/**********************AssignmentDialogBase Functions**************************/
AssignmentDialogBase::AssignmentDialogBase(QWidget *parent)
	:QDialog(parent),
	titleLabel(new QLabel("Title Label", this)),
	boxOneLabel(new QLabel("Box One Label:", this)),
	boxTwoLabel(new QLabel("Box Two Label:", this)),
	boxOne(new QLineEdit(this)),
	boxTwo(new QLineEdit(this)),
	submitButton(new QPushButton("Submit", this)),
	cancelButton(new QPushButton("Cancel", this)),
	topHorLayout(new QHBoxLayout),
	midHorLayout(new QHBoxLayout),
	botHorLayout(new QHBoxLayout),
	vertLayout(new QVBoxLayout),
	messageWin(new QMessageBox(this))
{
	titleLabel->setAlignment(Qt::AlignHCenter);
	boxOneLabel->setAlignment(Qt::AlignHCenter);
	boxTwoLabel->setAlignment(Qt::AlignHCenter);

	topHorLayout->addWidget(boxOneLabel);
	topHorLayout->addWidget(boxOne);

	midHorLayout->addStretch(1);
	midHorLayout->addWidget(boxTwoLabel);
	midHorLayout->addWidget(boxTwo);

	botHorLayout->addWidget(submitButton);
	botHorLayout->addWidget(cancelButton);

	vertLayout->addWidget(titleLabel);
	vertLayout->addLayout(topHorLayout);
	vertLayout->addLayout(midHorLayout);
	vertLayout->addLayout(botHorLayout);

	setLayout(vertLayout);
}

/*****************************************************************************/
AddAssignmentDialog::AddAssignmentDialog(Gradebook *book, QWidget *parent)
	:AssignmentDialogBase(parent),
	gradebook(book)
{
	setWindowTitle("Add Assignment All");
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);
	titleLabel->setText("<font size=4><b>Add Assignment All</b></font>");
	boxOneLabel->setText("Assignment name:");
	boxTwoLabel->setText("Point value:");

	submitButton->setEnabled(false);
	boxTwo->setValidator(new QDoubleValidator(this));
	boxTwo->setMaxLength(5);
	connectWidgets();
}

void AddAssignmentDialog::changeGradebook(Gradebook *book)
{
	gradebook = book;
}

void AddAssignmentDialog::connectWidgets()
{
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(boxOne, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
	connect(boxTwo, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
	connect(submitButton, SIGNAL(clicked()), this, SLOT(addAssignment()));
}

// Adds an assignment to each Student in the Gradebook, each with a 0 for points earned
void AddAssignmentDialog::addAssignment()
{
	QString assignName(boxOne->text());
	QString pointValue(boxTwo->text());

	std::string assignNameStr(assignName.toAscii());
	double pointValueDouble(pointValue.toDouble());

	if(assignNameStr == "INVALID ASSIGNMENT")
	{
		QMessageBox *messageBox = new QMessageBox(this);
		messageBox->setText("You cannot name an assignment \"INVALID ASSIGNMENT\"");
		messageBox->exec();
		boxOne->clear();
		boxTwo->clear();
		return;
	}

	Assignment newAssignment(pointValueDouble, 0.0, assignNameStr);

	std::vector<Student> studentsCopy(gradebook->getAllStudents());

	if(gradebook->addAssignmentAll(newAssignment))
	{
		messageWin->setText("Assignment added!");
		emit assignmentAdded();
	}
	else
	{
		messageWin->setText("Assignment was not added successfully.");
	}

	messageWin->setWindowTitle("Confirmation");

	messageWin->exec();
	close();
}

// The argument 'text' isn't actually used, it's only there so it takes the same
// number/type of arguments as textChanged from QLineEdit and can be used as a
// slot.
void AddAssignmentDialog::enableSubmitButton(const QString &text)
{
	QString assignmentName(boxOne->text());
	QString pointValue(boxTwo->text());
	if(!assignmentName.isEmpty() && !pointValue.isEmpty())
	{
		submitButton->setEnabled(true);
	}
	else
	{
		submitButton->setEnabled(false);
	}
}

void AddAssignmentDialog::close()
{
	boxOne->clear();
	boxTwo->clear();
	AssignmentDialogBase::close();
}

/********************** AddIndvAssignmentDialog Functions**********************/
AddIndvAssignmentDialog::AddIndvAssignmentDialog(Student *stu, QWidget *parent)
	:AssignmentDialogBase(parent),
	student(stu),
	earnedPointsBox(new QLineEdit(this)),
	earnedPointsLabel(new QLabel("Points earned:", this))
{
	earnedPointsLabel->setAlignment(Qt::AlignHCenter);
	setWindowTitle("Add Individual Assignment");
	titleLabel->setText("<font size=4><b>Add Assignment</b></font>");
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);
	boxOneLabel->setText("Assignment name:");
	boxTwoLabel->setText("Points possible:");

	QHBoxLayout *newHorLayout = new QHBoxLayout;
	newHorLayout->addStretch(1);
	newHorLayout->addWidget(earnedPointsLabel);
	newHorLayout->addWidget(earnedPointsBox);
	vertLayout->insertLayout(3, newHorLayout);

	// Set the tab order for the Widget
	setTabOrder(boxOne, boxTwo);
	setTabOrder(boxTwo, earnedPointsBox);
	setTabOrder(earnedPointsBox, submitButton);
	setTabOrder(submitButton, cancelButton);

	// Set validators and connect widgets
	submitButton->setEnabled(false);
	boxTwo->setValidator(new QDoubleValidator(this));
	boxTwo->setMaxLength(5);
	earnedPointsBox->setValidator(new QDoubleValidator(this));
	earnedPointsBox->setMaxLength(5);
	connectWidgets();
}

void AddIndvAssignmentDialog::changeStudent(Student *stu)
{
	student = stu;
}

void AddIndvAssignmentDialog::connectWidgets()
{
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(submitButton, SIGNAL(clicked()), this, SLOT(addAssignment()));
	connect(boxOne, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
	connect(boxTwo, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
	connect(earnedPointsBox, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
}

void AddIndvAssignmentDialog::addAssignment()
{
	QString assignName(boxOne->text());
	QString pointValue(boxTwo->text());
	QString earnedPoints(earnedPointsBox->text());

	std::string assignNameStr(assignName.toAscii());
	double pointValueDouble(pointValue.toDouble());
	double earnedPointsDouble(earnedPoints.toDouble());

	if(assignNameStr == "INVALID ASSIGNMENT")
	{
		QMessageBox *messageBox = new QMessageBox(this);
		messageBox->setText("You cannot name an assignment \"INVALID ASSIGNMENT\"");
		messageBox->exec();
		boxOne->clear();
		boxTwo->clear();
		return;
	}

	Assignment newAssignment(pointValueDouble, earnedPointsDouble, assignNameStr);

	messageWin->setWindowTitle("Confirmation");
	if(student->addAssignment(newAssignment))
	{
		messageWin->setText("Assignment added!");
		emit assignmentAdded();
	}
	else
	{
		messageWin->setText("Assignment was not added successfully.");
	}
	messageWin->exec();
	close();
}

void AddIndvAssignmentDialog::enableSubmitButton(const QString &text)
{
	QString assignmentName(boxOne->text());
	QString pointValue(boxTwo->text());
	QString earnedPoints(earnedPointsBox->text());

	if(!assignmentName.isEmpty() && !pointValue.isEmpty() && !earnedPoints.isEmpty())
	{
		submitButton->setEnabled(true);
	}
	else
	{
		submitButton->setEnabled(false);
	}
}

void AddIndvAssignmentDialog::close()
{
	boxOne->clear();
	boxTwo->clear();
	earnedPointsBox->clear();
	AssignmentDialogBase::close();
}


/*********************** EditIndvAssignmentDialog *****************************/
EditIndvAssignmentDialog::EditIndvAssignmentDialog(Student *stu, const std::string &name,
												   QWidget *parent)
	:AssignmentDialogBase(parent),
	student(stu),
	assignmentName(name),
	confirmWin(new QMessageBox(this)),
	earnedPointsBox(new QLineEdit(this)),
	earnedPointsLabel(new QLabel("Points earned:", this)),
	origName(new QLabel("", this)),
	origPoints(new QLabel("", this))
{
	titleLabel->setText("<font size=4><b>Edit Assignment</b></font>");
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);
	boxOneLabel->setText("Assignment name:");
	boxTwoLabel->setText("Points possible:");

	origName->setText("<b>Current name:</b> ");
	origPoints->setText("<b>Current points:<b> ");
	origName->setAlignment(Qt::AlignHCenter);
	origPoints->setAlignment(Qt::AlignHCenter);

	QHBoxLayout *newHorLayout = new QHBoxLayout;
	newHorLayout->addStretch(1);
	newHorLayout->addWidget(earnedPointsLabel);
	newHorLayout->addWidget(earnedPointsBox);
	vertLayout->insertLayout(3, newHorLayout);

	vertLayout->insertWidget(1, origName);
	vertLayout->insertWidget(2, origPoints);
	vertLayout->insertSpacing(1, 15);
	vertLayout->insertSpacing(4, 15);

	// Set the tab order for the Widget
	setTabOrder(boxOne, boxTwo);
	setTabOrder(boxTwo, earnedPointsBox);
	setTabOrder(earnedPointsBox, submitButton);
	setTabOrder(submitButton, cancelButton);

	submitButton->setEnabled(false);
	boxTwo->setValidator(new QDoubleValidator(this));
	boxTwo->setMaxLength(5);
	earnedPointsBox->setValidator(new QDoubleValidator(this));
	earnedPointsBox->setMaxLength(5);
	connectWidgets();
	resize(sizeHint());
}

// Change the Student and assignment name on which to make changes
void EditIndvAssignmentDialog::changeAssignment(Student *stu, const std::string &name)
{
	student = stu;
	assignmentName = name;
	displayOrigData();	// Reload the original data displayed for the un-edited assignment
}

void EditIndvAssignmentDialog::displayOrigData()
{
	// Get the assignment before it's been edited
	Assignment currentAssignment(student->getAssignment(assignmentName));
	double pointsPossible(currentAssignment.getPointsPossible());
	double pointsEarned(currentAssignment.getPointsEarned());
	QString points(QString::number(pointsEarned) + "/" + QString::number(pointsPossible));

	// Set the display labels with the original assignment name and point values
	origName->setText(QString("<b>Current name:</b> ") + QString(assignmentName.c_str()));
	origPoints->setText(QString("<b>Current points:</b> ") + points);

	boxOne->insert(QString(assignmentName.c_str()));
	boxTwo->insert(QString::number(pointsPossible));
	earnedPointsBox->insert(QString::number(pointsEarned));

	// Resize the window if the new data is very long
	resize(sizeHint());
}

void EditIndvAssignmentDialog::connectWidgets()
{
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(submitButton, SIGNAL(clicked()), this, SLOT(editAssignment()));
	connect(boxOne, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
	connect(boxTwo, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
	connect(earnedPointsBox, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
}

void EditIndvAssignmentDialog::enableSubmitButton(const QString &text)
{
	// Get the text currently in all three input boxes
	QString assignmentName(boxOne->text());
	QString pointValue(boxTwo->text());
	QString earnedPoints(earnedPointsBox->text());

	// Are any of the boxes empty?
	if(!assignmentName.isEmpty() && !pointValue.isEmpty() && !earnedPoints.isEmpty())
	{
		submitButton->setEnabled(true);		// If not empty, enable the submit button
	}
	else
	{
		submitButton->setEnabled(false);	// If empty, disable the submit button
	}
}

void EditIndvAssignmentDialog::editAssignment()
{
	// Get the current values of each input box as a QString
	QString assignName(boxOne->text());
	QString pointValue(boxTwo->text());
	QString earnedPoints(earnedPointsBox->text());

	// Convert the QString values to useable data types
	std::string assignNameStr(assignName.toAscii());
	double pointValueDouble(pointValue.toDouble());
	double earnedPointsDouble(earnedPoints.toDouble());

	// Guard against the name "INVALID ASSIGNMENT" for assignments(it's reserved)
	if(assignNameStr == "INVALID ASSIGNMENT")
	{
		QMessageBox *messageBox = new QMessageBox(this);
		messageBox->setText("You cannot name an assignment \"INVALID ASSIGNMENT\"");
		messageBox->exec();
		boxOne->clear();
		boxTwo->clear();
		return;
	}

	// Make a copy of the new assignment as the old assignment for comparison
	Assignment newAssignment(pointValueDouble, earnedPointsDouble, assignNameStr);
	Assignment currentAssignment(student->getAssignment(assignmentName));

	// Set the text on the confirmation window
	confirmWin->setWindowTitle("Confirm Edit");
	confirmWin->setText("Are you sure you want to edit this assignment?");
	confirmWin->setStandardButtons(QMessageBox::Yes|QMessageBox::No);

	// If the user confirms the confirmation dialog
	if(confirmWin->exec() == QMessageBox::Yes)
	{
		// Edit the points earned/possible
		student->editAssignmentGrade(currentAssignment.getName(), pointValueDouble, earnedPointsDouble);
		// If the name has been changed
		if(assignNameStr != currentAssignment.getName())
		{
			// Get the assignment number to edit the assignment name
			int assignNum = student->getAssignmentNumber(currentAssignment.getName());
			student->editAssignmentName(assignNum, assignNameStr);
		}
		emit assignmentEdited();
	}
	else	// If the user selects no on the confirmation dialog
	{
		return;
	}
	close();
}

void EditIndvAssignmentDialog::close()
{
	boxOne->clear();
	boxTwo->clear();
	earnedPointsBox->clear();
	AssignmentDialogBase::close();
}

/********************* AddExtraPointsDialog **********************************/
AddExtraPointsDialog::AddExtraPointsDialog(Student *stu, QWidget *parent)
	:AssignmentDialogBase(parent),
	student(stu)
{
	boxOneLabel->setText("Extra points:");
	boxTwoLabel->hide();
	boxTwo->hide();

	submitButton->setEnabled(false);
	boxOne->setValidator(new QDoubleValidator(this));
	connectWidgets();
}

void AddExtraPointsDialog::changeStudent(Student *stu)
{
	student = stu;
}

void AddExtraPointsDialog::connectWidgets()
{
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(submitButton, SIGNAL(clicked()), this, SLOT(addExtraPoints()));
	connect(boxOne, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
}

void AddExtraPointsDialog::close()
{
	boxOne->clear();
	AssignmentDialogBase::close();
}

void AddExtraPointsDialog::addExtraPoints()
{
	double pointsToAdd(boxOne->text().toInt());
	if(pointsToAdd <= 0)
	{
		messageWin->setWindowTitle("Invalid Action");
		messageWin->setText("You must add a positive amount of extra points.");
		messageWin->exec();
		boxOne->clear();
		return;
	}

	if(!student->addExtraPoints(pointsToAdd))
	{
		throw std::runtime_error("Error adding extra points to a student.");
	}
	else
	{
		messageWin->setText("Extra points have been successfully added!");
		messageWin->exec();
		emit extraPointsAdded();
		close();
	}
}

void AddExtraPointsDialog::enableSubmitButton(const QString &text)
{
	if(!text.isEmpty())
	{
		submitButton->setEnabled(true);
	}
	else
	{
		submitButton->setEnabled(false);
	}
}
