#include "deleteallassignmentdialog.h"
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>

DeleteAllAssignmentDialog::DeleteAllAssignmentDialog(Gradebook *book, QWidget *parent)
	:QDialog(parent),
	gradebook(book),
	titleLabel(new QLabel("<font size=3><b>Delete Common Assignment</b></font>", this)),
	assignmentLabel(new QLabel("Common Assignments", this)),
	closeButton(new QPushButton("Close", this)),
	deleteButton(new QPushButton("Delete Assignment", this)),
	assignmentList(new QListWidget(this)),
	messageWin(new QMessageBox(this)),
	confirmWin(new ConfirmDeleteAssignment("", NULL, this))
{
	setWindowTitle("Delete Common Assignments");
	titleLabel->setAlignment(Qt::AlignHCenter);
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);

	assignmentLabel->setAlignment(Qt::AlignHCenter);

	QVBoxLayout *vertLayout = new QVBoxLayout;
	QHBoxLayout *botLayout = new QHBoxLayout;

	botLayout->addWidget(deleteButton);
	botLayout->addWidget(closeButton);

	vertLayout->addWidget(titleLabel);
	vertLayout->addWidget(assignmentLabel);
	vertLayout->addWidget(assignmentList);
	vertLayout->addLayout(botLayout);

	if(gradebook)
	{
		populateCommonAssignments();
	}
	setLayout(vertLayout);
	connectWidgets();
	resize(sizeHint());
}

void DeleteAllAssignmentDialog::changeGradebook(Gradebook *book)
{
	gradebook = book;
	if(gradebook)
	{
		populateCommonAssignments();
	}
}

void DeleteAllAssignmentDialog::connectWidgets()
{
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteAssignment()));
	connect(confirmWin, SIGNAL(assignmentDeleted()), this, SLOT(emitDeleted()));
}

void DeleteAllAssignmentDialog::populateCommonAssignments()
{
	assignmentList->clear();
	std::vector<Assignment> commonAssignments(gradebook->getCommonAssignments());
	for(std::vector<Assignment>::const_iterator i = commonAssignments.begin();
		i != commonAssignments.end(); ++i)
	{
		assignmentList->addItem(QString(i->getName().c_str()));
	}
}

void DeleteAllAssignmentDialog::close()
{
	assignmentList->clear();
	QDialog::close();
}

void DeleteAllAssignmentDialog::deleteAssignment()
{
	if(assignmentList->currentItem() == NULL)
	{
		messageWin->setWindowTitle("Notice");
		messageWin->setText("No assignment has been selected to delete.");
		messageWin->exec();
		return;
	}
	std::string assignmentName(assignmentList->currentItem()->text().toAscii());
	confirmWin->changeAssignment(assignmentName, gradebook);
	confirmWin->exec();
}

void DeleteAllAssignmentDialog::emitDeleted()
{
	emit assignmentDeleted();
	close();
}
/************************* ConfirmDeleteAssignment Functions ******************/
ConfirmDeleteAssignment::ConfirmDeleteAssignment(const std::string &assignName,
												 Gradebook *book, QWidget *parent)
	:QDialog(parent),
	gradebook(book),
	assignmentName(assignName),
	titleLabel(new QLabel("<font size=3><b>Delete Assignment</b></font>", this)),
	boxLabel(new QLabel("", this)),
	deleteBox(new QLineEdit(this)),
	cancelButton(new QPushButton("Cancel", this)),
	deleteButton(new QPushButton("Delete Assignment", this)),
	messageWin(new QMessageBox(this))
{
	setWindowTitle("Delete Confirmation");
	boxLabel->setText("Type \"DELETE\" to delete the assignment: " + QString(assignName.c_str()));
	titleLabel->setAlignment(Qt::AlignHCenter);
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);

	QVBoxLayout *vertLayout = new QVBoxLayout;
	QHBoxLayout *botLayout = new QHBoxLayout;

	botLayout->addWidget(cancelButton);
	botLayout->addWidget(deleteButton);

	vertLayout->addWidget(titleLabel);
	vertLayout->addWidget(boxLabel);
	vertLayout->addWidget(deleteBox);
	vertLayout->addLayout(botLayout);

	setLayout(vertLayout);
	connectWidgets();
	deleteButton->setEnabled(false);
	resize(sizeHint());
}

void ConfirmDeleteAssignment::changeAssignment(const std::string &assignName, Gradebook *book)
{
	gradebook = book;
	assignmentName = assignName;
	boxLabel->setText("Type \"DELETE\" to delete the assignment: " + QString(assignName.c_str()));
}

void ConfirmDeleteAssignment::connectWidgets()
{
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(deleteBox, SIGNAL(textChanged(QString)), this, SLOT(enableDeleteButton(QString)));
	connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteAssignment()));
}

void ConfirmDeleteAssignment::enableDeleteButton(const QString &text)
{
	QString deleteKeyword("DELETE");
	if(text == deleteKeyword)
	{
		deleteButton->setEnabled(true);
	}
	else
	{
		deleteButton->setEnabled(false);
	}
}

void ConfirmDeleteAssignment::close()
{
	deleteBox->clear();
	QDialog::close();
}

void ConfirmDeleteAssignment::deleteAssignment()
{
	gradebook->deleteAssignmentAll(assignmentName);
	messageWin->setWindowTitle("Confirmation");
	messageWin->setText("The assignment has been successfully deleted.");
	messageWin->exec();
	emit assignmentDeleted();
	close();
}

