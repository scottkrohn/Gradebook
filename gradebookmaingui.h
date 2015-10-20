#ifndef GRADEBOOKGUI_H
#define GRADEBOOKGUI_H
#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include "gradebook.h"
#include "addgradebookdialog.h"
#include "viewclassdialog.h"
#include "gradebookmanager.h"
#include "deletegradebookdialog.h"

class QLabel;
class QListView;
class QPushButton;
class QAction;
class QMessageBox;

class GradebookMain: public QMainWindow
{
	Q_OBJECT
public:
	GradebookMain();
private:
	// Gradebook
	Gradebook gradebook;

	// GradebookManager object to manage saved/new gradebooks
	GradebookManager manager;

	// Labels
	QLabel *classesLabel;

	// Main list display on the main window
	QListWidget *classesList;

	// Buttons
	QPushButton *openClassButton;
	QPushButton *addClassButton;

	// Dialog/message windows
	AddGradebookDialog *addGradebookDialog;
	DeleteGradebookDialog *deleteGradebookDialog;
	QMessageBox *messageWin;
	ViewClassDialog *viewClass;



	// Actions
	QAction *exitAction;
	QAction *deleteAction;

	// Menus
	QMenu *fileMenu;

	// Setup Functions
	void createMenus();
	void createActions();
	void connectWidgets();

	// Utility Functions
	QString getSelectionName() const;
	bool createNewFile(const std::string &filename);
private slots:
	void addNewGradebook();
	void deleteGradebook();
	void addClassname(const QString &classname);
	void openGradebook();
	void openGradebookClick(QListWidgetItem *item);	// Opens a gradebook when it's double clicked
	void loadCurrentClasses();
	void displayGradebook();
};

#endif
