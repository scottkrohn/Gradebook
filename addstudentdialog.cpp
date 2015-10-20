#include "addstudentdialog.h"
#include <boost/regex.hpp>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <string>
#include <QString>
#include <iostream>

AddStudentDialog::AddStudentDialog(Gradebook *book, QWidget *parent)
	:QDialog(parent),
	gradebook(book),
	titleLabel(new QLabel("<font size=4><b>Add New Student</b></font>", this)),
	nameLabel(new QLabel("Student name:", this)),
	nameBox(new QLineEdit(this)),
	cancelButton(new QPushButton("Cancel", this)),
	submitButton(new QPushButton("Submit and Save", this)),
	messageWin(new QMessageBox(this))
{
	setWindowTitle("Add New Student");
	titleLabel->setAlignment(Qt::AlignHCenter);
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);
	nameLabel->setAlignment(Qt::AlignHCenter);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	QHBoxLayout *topLayout = new QHBoxLayout;
	QHBoxLayout *midLayout = new QHBoxLayout;
	QHBoxLayout *botLayout = new QHBoxLayout;

	mainLayout->addLayout(topLayout);
	mainLayout->addLayout(midLayout);
	mainLayout->addLayout(botLayout);

	topLayout->addWidget(titleLabel);
	midLayout->addWidget(nameLabel);
	midLayout->addWidget(nameBox);
	botLayout->addWidget(submitButton);
	botLayout->addWidget(cancelButton);

	setLayout(mainLayout);
	connectWidgets();
	submitButton->setEnabled(false);
	resize(sizeHint());
}

void AddStudentDialog::changeGradebook(Gradebook *book)
{
	gradebook = book;
}

void AddStudentDialog::connectWidgets()
{
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(nameBox, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
	connect(submitButton, SIGNAL(clicked()), this, SLOT(addStudent()));
}

std::string AddStudentDialog::getName() const
{
	std::string name(nameBox->text().toAscii());
	return name;
}

void AddStudentDialog::close()
{
	nameBox->clear();
	QDialog::close();
}

void AddStudentDialog::addStudent()
{
	std::string newStudentName(getName());

	// Acceptable student names are anything with at least 2 names(first and last).
	boost::regex acceptedNamePat("^(\\w+) (\\w+)( \\w+)*");
	boost::smatch match;

	// Check to make sure the name entered is acceptable
	if(boost::regex_match(newStudentName, match, acceptedNamePat))
	{
		// Attempt to add the student to the gradebook
		if(gradebook->addStudent(newStudentName))
		{
			messageWin->setWindowTitle("Success!");
			messageWin->setText("Student successfully added!");
			messageWin->exec();
			emit studentAdded();
			close();
			return;
		}
		else
		{
			messageWin->setWindowTitle("Unable To Add Student");
			if(newStudentName == "INVALID STUDENT")
			{
				messageWin->setText("You cannot name a student \"INVALID STUDENT\"");
			}
			else
			{
				messageWin->setText("This student name already exists in the gradebook.");
			}
			messageWin->exec();
			return;
		}
	}
	else	// If the entered name didn't match the accepted naming pattern
	{
		messageWin->setWindowTitle("Invalid Student Name");
		messageWin->setText("Invalid format for student name.");
		messageWin->exec();
	}
}

void AddStudentDialog::enableSubmitButton(const QString &text)
{
	if(text.isEmpty())
	{
		submitButton->setEnabled(false);
	}
	else
	{
		submitButton->setEnabled(true);
	}
}
