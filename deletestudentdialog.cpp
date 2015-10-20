#include "deletestudentdialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

DeleteStudentDialog::DeleteStudentDialog(const std::string &name, Gradebook *book, QWidget *parent)
	:QDialog(parent),
	studentName(name),
	gradebook(book),
	titleLabel(new QLabel("<font size=4><b>Delete Student</b></font>", this)),
	boxLabel(new QLabel("", this)),
	deleteBox(new QLineEdit(this)),
	submitButton(new QPushButton("Submit", this)),
	cancelButton(new QPushButton("Cancel", this)),
	messageWin(new QMessageBox(this))
{
	setWindowTitle("Delete Student");

	titleLabel->setAlignment(Qt::AlignHCenter);
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);

	std::cout << name << std::endl;
	boxLabel->setText("Type \"DELETE\" to delete the student: " + QString(name.c_str()));

	boxLabel->setAlignment(Qt::AlignHCenter);

	QHBoxLayout *botLayout = new QHBoxLayout;
	QHBoxLayout *midLayout = new QHBoxLayout;

	QVBoxLayout *vertLayout = new QVBoxLayout;

	botLayout->addWidget(submitButton);
	botLayout->addWidget(cancelButton);

	midLayout->addStretch(1);
	midLayout->addWidget(deleteBox);
	midLayout->addStretch(1);

	vertLayout->addWidget(titleLabel);
	vertLayout->addWidget(boxLabel);
	vertLayout->addLayout(midLayout);
	vertLayout->addLayout(botLayout);

	submitButton->setEnabled(false);
	connectWidgets();
	setLayout(vertLayout);
	resize(sizeHint());
}

void DeleteStudentDialog::changeStudent(const std::string &name, Gradebook *book)
{
	gradebook = book;
	studentName = name;
	boxLabel->setText("Type \"DELETE\" to delete the student: " + QString(name.c_str()));
}

void DeleteStudentDialog::connectWidgets()
{
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(deleteBox, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
	connect(submitButton, SIGNAL(clicked()), this, SLOT(deleteStudent()));
}

void DeleteStudentDialog::close()
{
	deleteBox->clear();
	QDialog::close();
}

void DeleteStudentDialog::enableSubmitButton(const QString &text)
{
	QString deleteKeyword("DELETE");
	if(text == deleteKeyword)
	{
		submitButton->setEnabled(true);
	}
	else
	{
		submitButton->setEnabled(false);
	}
}

void DeleteStudentDialog::deleteStudent()
{
	gradebook->removeStudent(studentName);
	emit studentDeleted();
	messageWin->setWindowTitle("Delete Student");
	messageWin->setText("Student successfully deleted.");
	messageWin->exec();
	close();
}
