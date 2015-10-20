#include "addgradebookdialog.h"
#include <stdexcept>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <iostream>
#include <QVBoxLayout>
#include <boost/regex.hpp>
#include <fstream>

AddGradebookDialog::AddGradebookDialog(GradebookManager &gbmanager, QWidget *parent)
	:QDialog(parent),
	titleLabel(new QLabel("<font size=4><b>Add New Class</b></font>", this)),
	lineEditLabel(new QLabel("Classname: ", this)),
	classNameBox(new QLineEdit(this)),
	submitButton(new QPushButton("Add", this)),
	cancelButton(new QPushButton("Cancel", this)),
	manager(gbmanager)
{
	setWindowTitle("Add New Class");
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);

	QHBoxLayout *topLayout = new QHBoxLayout;
	QHBoxLayout *midLayout = new QHBoxLayout;
	QHBoxLayout *botLayout = new QHBoxLayout;

	QVBoxLayout *mainLayout = new QVBoxLayout;

	topLayout->addWidget(titleLabel);
	midLayout->addWidget(lineEditLabel);
	midLayout->addWidget(classNameBox);
	botLayout->addWidget(submitButton);
	botLayout->addWidget(cancelButton);

	mainLayout->addLayout(topLayout);
	mainLayout->addLayout(midLayout);
	mainLayout->addLayout(botLayout);

	setLayout(mainLayout);

	titleLabel->setAlignment(Qt::AlignHCenter);
	connectButtons();
	resize(sizeHint());
}

void AddGradebookDialog::connectButtons()
{
	// Connect cancel button with closing the window
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	// Connect the submit button with returning the new classname
	connect(submitButton, SIGNAL(clicked()), this, SLOT(submitDialog()));
	// Connect accepted() signal with clearing the classNameBox
	connect(this, SIGNAL(accepted()), classNameBox, SLOT(clear()));
	// Connect the cancelButton with clearing the classNameBox
	connect(cancelButton, SIGNAL(clicked()), classNameBox, SLOT(clear()));
	// Connect closing the window through "X" with clearing the classNameBox
	connect(this, SIGNAL(rejected()), classNameBox, SLOT(clear()));
}

bool AddGradebookDialog::createNewClass(const std::string &classname)
{
	std::string newClassname = classname + ".txt";
	std::ofstream outfile(newClassname.c_str());
	if(!outfile)
	{
		return false;
	}

	outfile << "classname " << classname << "\n";
	outfile << "students " << 0 << "\n";
	return true;
}

void AddGradebookDialog::submitDialog()
{
	boost::regex blankClassname(" *");
	boost::smatch match;

	std::string newClassname((classNameBox->text()).toAscii());
	if(manager.classExists(newClassname))
	{
		QMessageBox *messageBox = new QMessageBox(this);
		messageBox->setText("This classname already exists, try another.");
		messageBox->show();
		classNameBox->clear();
	}
	else if(boost::regex_match(newClassname, match, blankClassname))
	{
		QMessageBox *messageBox = new QMessageBox(this);
		messageBox->setText("Invalid classname, please try again.");
		messageBox->show();
		classNameBox->clear();
	}
	else
	{
		if(createNewClass(newClassname))
		{
			manager.addClassname(newClassname);
			emit returnClassname(classNameBox->text());
			emit accepted();
		}
	}
}

