#include "editscoresdialog.h"
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDoubleValidator>
#include <QMessageBox>
#include <QListWidget>

EditCommonDialog::EditCommonDialog(Gradebook *book, QWidget *parent)
	:QDialog(parent),
	gradebook(book),
	titleLabel(new QLabel("<font size=3><b>Edit Common Assignments</b></font>", this)),
	commonLabel(new QLabel("Common Assignments", this)),
	assignmentList(new QListWidget(this)),
	editButton(new QPushButton("Edit Assignment", this)),
	closeButton(new QPushButton("Close", this)),
	editScoresDialog(new EditScoresDialog("", NULL, this)),
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

EditCommonDialog::~EditCommonDialog()
{
	delete titleLabel;
	delete commonLabel;
	delete assignmentList;
	delete editButton;
	delete closeButton;
	delete editScoresDialog;
	delete messageWin;
}

void EditCommonDialog::populateAssignments()
{
	assignmentList->clear();
	std::vector<Assignment> assignments(gradebook->getCommonAssignments());
	for(std::vector<Assignment>::const_iterator i = assignments.begin();
		i != assignments.end(); ++i)
	{
		assignmentList->addItem(QString(i->getName().c_str()));
	}
}

void EditCommonDialog::close()
{
	assignmentList->clear();
	QDialog::close();
}

void EditCommonDialog::editAssignment()
{
	QString assignmentName(assignmentList->currentItem()->text());
	std::string assignNameString(assignmentName.toAscii());
	editScoresDialog->changeAssignment(assignNameString, gradebook);
	editScoresDialog->exec();
}

void EditCommonDialog::changeGradebook(Gradebook *book)
{
	gradebook = book;
	populateAssignments();
}

void EditCommonDialog::emitSaved()
{
	emit gradebookSaved();
}

void EditCommonDialog::connectWidgets()
{
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(editButton, SIGNAL(clicked()), this, SLOT(editAssignment()));
	connect(editScoresDialog, SIGNAL(gradebookSaved()), this, SLOT(emitSaved()));
}

/******************************************************************************/

EditScoresDialog::EditScoresDialog(const std::string &assignName, Gradebook *book,
								   QWidget *parent)
	:QDialog(parent),
	gradebook(book),
	assignmentName(assignName),
	hasBeenSaved(false),
	titleLabel(new QLabel("<font size=3><b>Edit Multiple Assignments</b></font>", this)),
	assignLabel(new QLabel("", this)),
	gradesTable(new QTableWidget(this)),
	saveButton(new QPushButton("Save Scores", this)),
	closeButton(new QPushButton("Close", this)),
	dValidator(new QDoubleValidator(0, 1000, 2, this)),
	messageWin(new QMessageBox(this))
{
	setWindowTitle("Edit Multiple Assignments");
	titleLabel->setAlignment(Qt::AlignHCenter);
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);
	assignLabel->setAlignment(Qt::AlignHCenter);

	QVBoxLayout *vertLayout = new QVBoxLayout;
	QHBoxLayout *botLayout = new QHBoxLayout;

	botLayout->addWidget(closeButton);
	botLayout->addWidget(saveButton);

	vertLayout->addWidget(titleLabel);
	vertLayout->addWidget(assignLabel);
	vertLayout->addWidget(gradesTable);
	vertLayout->addLayout(botLayout);

	setLayout(vertLayout);

	if(gradebook)
	{
		pointsPossible = getPointsPossible();
	}

	connectWidgets();
	resize(sizeHint());
}

EditScoresDialog::~EditScoresDialog()
{
	delete titleLabel;
	delete assignLabel;
	delete gradesTable;
	delete saveButton;
	delete closeButton;
}

void EditScoresDialog::changeAssignment(const std::string &assignName, Gradebook *book)
{
	gradebook = book;
	assignmentName = assignName;
	resizeTable(gradebook->classSize());
	pointsPossible = getPointsPossible();
	loadData();
}

void EditScoresDialog::connectWidgets()
{
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
}

void EditScoresDialog::resizeTable(int studentCount)
{
	// There are always only two columns: Names and Score
	gradesTable->setColumnCount(2);
	gradesTable->setRowCount(studentCount+1);
	resize(sizeHint());
}

void EditScoresDialog::loadData()
{
	std::vector<Student> students(gradebook->getAllStudents());
	gradesTable->setItem(0, 0, new QTableWidgetItem("Names"));
	gradesTable->item(0, 0)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
	gradesTable->setItem(0, 1, new QTableWidgetItem(assignmentName.c_str()));
	gradesTable->item(0, 1)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
	int rowCount = 1;
	for(std::vector<Student>::const_iterator i = students.begin();
		i != students.end(); ++i)
	{
		QTableWidgetItem *item = new QTableWidgetItem(i->getName().c_str());
		item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
		gradesTable->setItem(rowCount, 0, item);
		QString grade(QString::number(i->getAssignmentGrade(assignmentName)));
		gradesTable->setItem(rowCount, 1, new QTableWidgetItem(grade));
		++rowCount;
	}

	assignLabel->setText(QString(assignmentName.c_str()) + ": " + QString::number(pointsPossible) + " points");
}

double EditScoresDialog::getPointsPossible() const
{
	std::vector<Assignment> commonAssignments(gradebook->getCommonAssignments());
	for(std::vector<Assignment>::const_iterator i = commonAssignments.begin();
		i != commonAssignments.end(); ++i)
	{
		if(i->getName() == assignmentName)
		{
			return i->getPointsPossible();
		}
	}
}

std::pair<bool,std::string> EditScoresDialog::validateEntry(QString &entry,
													const std::string &stuName) const
{
	int pos = 0;
	QValidator::State valResult(dValidator->validate(entry, pos));
	if(valResult == QValidator::Invalid)
	{
		return std::pair<bool,std::string>(false,stuName);
	}
	else if(valResult == QValidator::Intermediate)
	{
		return std::pair<bool,std::string>(false,stuName);
	}
	else if(valResult == QValidator::Acceptable)
	{
		return std::pair<bool,std::string>(true,stuName);
	}
	else
	{
		throw std::runtime_error("Unexpected result in EditScoresDialog::validateEntry()");
	}
}

void EditScoresDialog::save()
{
	std::vector<std::pair<std::string,double> > newScores;
	std::vector<Student> students(gradebook->getAllStudents());
	std::vector<double> grades;
	for(int i = 1; i != gradesTable->rowCount(); ++i)
	{
		grades.push_back(gradesTable->item(i, 1)->text().toDouble());
	}

	if(grades.size() != students.size())
	{
		throw std::runtime_error("Non-matching container sizes in EditScoresDialog::save()");
	}

	for(int i = 0; i != students.size(); ++i)
	{
		gradebook->editAssignment(students[i].getName(), assignmentName, pointsPossible, grades[i]);
	}

	if(gradebook->writeToFile(gradebook->getCurrentFilename()))
	{
		messageWin->setWindowTitle("Save Successful");
		messageWin->setText("Gradebook has been successfully saved.");
		messageWin->exec();
		emit gradebookSaved();
		close();
	}
	else
	{
		messageWin->setWindowTitle("Error");
		messageWin->setText("There was an error saving the gradebook");
		messageWin->exec();
	}
}

