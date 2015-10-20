#include "deletegradebookdialog.h"
#include <QMessageBox>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <QListWidgetItem>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>
#include <string>


DeleteGradebookDialog::DeleteGradebookDialog(GradebookManager &gbmanager, QWidget *parent)
	:QDialog(parent),
	titleLabel(new QLabel("<font size=4><b>Delete Class</b></font>", this)),
	classList(new QListWidget(this)),
	deleteButton(new QPushButton("Delete Class", this)),
	closeButton(new QPushButton("Close", this)),
	manager(gbmanager),
	messageWin(new QMessageBox(this))
{
	setWindowTitle("Delete Class");
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);
	titleLabel->setAlignment(Qt::AlignHCenter);

	QVBoxLayout *vertLayout = new QVBoxLayout;
	QHBoxLayout *bottomLayout = new QHBoxLayout;

	bottomLayout->addWidget(deleteButton);
	bottomLayout->addWidget(closeButton);

	vertLayout->addWidget(titleLabel);
	vertLayout->addWidget(classList);
	vertLayout->addLayout(bottomLayout);

	loadClassnames();
	connectWidgets();
	setLayout(vertLayout);
	resize(sizeHint());
}

DeleteGradebookDialog::~DeleteGradebookDialog()
{
	delete titleLabel;
	delete classList;
	delete deleteButton;
	delete closeButton;
	delete messageWin;
}

void DeleteGradebookDialog::connectWidgets()
{
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteClass()));
}

void DeleteGradebookDialog::loadClassnames()
{
	classList->clear();
	std::vector<std::string> classnames(manager.getClassnames());
	for(std::vector<std::string>::const_iterator i = classnames.begin();
		i != classnames.end(); ++i)
	{
		classList->addItem(QString(i->c_str()));
	}
}

QString DeleteGradebookDialog::getSelectionName() const
{
	QListWidgetItem *currentItem(classList->currentItem());
	if(currentItem)
	{
		return currentItem->text();
	}
	return QString("");
}

/******************* DeleteGradebookDialog Private Slots***********************/
void DeleteGradebookDialog::deleteClass()
{
	if(classList->currentItem() == NULL)
	{
		messageWin->setText("No class has been selected.");
		messageWin->exec();
		return;
	}
	std::string classname(getSelectionName().toAscii());
	std::string filename(classname + ".txt");
	if(!manager.classExists(classname))
	{
		throw std::runtime_error("Item selected for deletion doesn't exist.");
	}

	QMessageBox *confirmWin = new QMessageBox(this);
	confirmWin->setWindowTitle("Confirm Delete");
	confirmWin->setText("Are you sure you want to delete this class?\nTHIS CANNOT"
						" BE UNDONE\n\nClassname: "
						+ QString(classname.c_str()));
	confirmWin->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
	if(confirmWin->exec() == QMessageBox::Yes)
	{
		if(remove(filename.c_str()))
		{
			throw std::runtime_error("Unable to delete class.");
		}
		else
		{
			manager.deleteClassname(classname);
		}
	}
	else
	{
	}
	loadClassnames();
}

void DeleteGradebookDialog::close()
{
	emit rejected();
	QDialog::close();
}
