#include "gradebookmaingui.h"
#include <stdexcept>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListView>
#include <iostream>
#include <QPushButton>
#include <QAction>
#include <QToolBar>
#include <QMenuBar>
#include <string>
#include <QString>
#include <QMessageBox>

GradebookMain::GradebookMain()
	:gradebook(Gradebook()),
	manager("classnamelist.txt"),
	classesLabel(new QLabel("<font size=4><b>Classes</b></font>", this)),
	classesList(new QListWidget(this)),
	openClassButton(new QPushButton("&Open Class", this)),
	addClassButton(new QPushButton("&Add New Class", this)),
	addGradebookDialog(new AddGradebookDialog(manager, this)),
	deleteGradebookDialog(new DeleteGradebookDialog(manager, this)),
	messageWin(new QMessageBox(this))
{
	setWindowTitle("Gradebook BETA");
	classesLabel->setAlignment(Qt::AlignHCenter);
	classesLabel->setFrameStyle(QFrame::Box);
	classesLabel->setLineWidth(1);

	viewClass = new ViewClassDialog(&gradebook, this);
	messageWin->setWindowTitle("Gradebook");

	QHBoxLayout *topLayout = new QHBoxLayout;
	QHBoxLayout *midLayout = new QHBoxLayout;
	QHBoxLayout *botLayout = new QHBoxLayout;
	QVBoxLayout *verLayout = new QVBoxLayout;
	QWidget *mainWidget = new QWidget(this);

	topLayout->addWidget(classesLabel);
	midLayout->addWidget(classesList);
	botLayout->addWidget(openClassButton);
	botLayout->addWidget(addClassButton);

	verLayout->addLayout(topLayout);
	verLayout->addLayout(midLayout);
	verLayout->addLayout(botLayout);

	mainWidget->setLayout(verLayout);
	setCentralWidget(mainWidget);

	createActions();
	createMenus();
	connectWidgets();
	loadCurrentClasses();
	resize(sizeHint());
	setGeometry(600,300, width(), height());
}

void GradebookMain::createActions()
{
	exitAction = new QAction("Exit", this);
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

	deleteAction = new QAction("Delete Class", this);
	connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteGradebook()));

}

void GradebookMain::createMenus()
{
	fileMenu = menuBar()->addMenu("File");
	fileMenu->addAction(exitAction);

	fileMenu->addAction(deleteAction);
}

void GradebookMain::connectWidgets()
{
	connect(addClassButton, SIGNAL(clicked()), this, SLOT(addNewGradebook()));
	connect(addGradebookDialog, SIGNAL(returnClassname(QString)),
			this, SLOT(addClassname(QString)));
	connect(addGradebookDialog, SIGNAL(accepted()),
			addGradebookDialog, SLOT(close()));
	connect(openClassButton, SIGNAL(clicked()), this, SLOT(openGradebook()));
	connect(classesList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(openGradebookClick(QListWidgetItem*)));
	connect(viewClass, SIGNAL(accepted()), this, SLOT(show()));
	connect(viewClass, SIGNAL(rejected()), this, SLOT(show()));
	connect(deleteGradebookDialog, SIGNAL(accepted()), this, SLOT(loadCurrentClasses()));
	connect(deleteGradebookDialog, SIGNAL(rejected()), this, SLOT(loadCurrentClasses()));
}

QString GradebookMain::getSelectionName() const
{
	QListWidgetItem *currentItem(classesList->currentItem());
	if(currentItem)
	{
		return currentItem->text() + QString(".txt");
	}
	return QString("");
}

void GradebookMain::loadCurrentClasses()
{
	// Clear list before loading to prevent duplicate entried
	classesList->clear();
	// Get a vector of all currently stored classnames
	std::vector<std::string> classnames(manager.getClassnames());
	// Loop through classname vector and add each
	for(std::vector<std::string>::const_iterator i = classnames.begin();
		i != classnames.end(); ++i)
	{
		classesList->addItem(QString(i->c_str()));
	}
}


/****************** GradebookMain SLOTS ************************/
void GradebookMain::addNewGradebook()
{
	addGradebookDialog->exec();
	deleteGradebookDialog->loadClassnames();
}

void GradebookMain::deleteGradebook()
{
	deleteGradebookDialog->exec();
}

void GradebookMain::addClassname(const QString &classname)
{
	classesList->addItem(classname);
}

void GradebookMain::openGradebook()
{
	// Get the name of the gradebook and create a std::string out of QString
	QString gradebookName(getSelectionName());
	const std::string gradebookNameStr(gradebookName.toAscii());

	// Did the gradebook load successfully?
	if(!gradebook.loadFromFile(gradebookNameStr))
	{
		messageWin->setText("Unable to open gradebook.");
		messageWin->exec();
		return;
	}
	else
	{
		viewClass->loadGradebook(&gradebook);
		viewClass->exec();
	}
}

void GradebookMain::openGradebookClick(QListWidgetItem *item)
{
	QString gradebookName(item->text());
	std::string gradebookNameStr(gradebookName.toAscii());
	gradebookNameStr += ".txt";

	if(!gradebook.loadFromFile(gradebookNameStr))
	{
		std::cout << gradebookNameStr << std::endl;
		messageWin->setText("Unable to open gradebook.");
		messageWin->exec();
		return;
	}
	else
	{
		std::cout << gradebook.getClassName() << std::endl;
		viewClass->loadGradebook(&gradebook);
		viewClass->exec();
	}
}

void GradebookMain::displayGradebook()
{
	gradebook.DEBUG_printStudentAssignments();
}
