#ifndef VIEWCLASS_H
#define VIEWCLASS_H
#include <QDialog>
#include "gradebook.h"
#include "student.h"
#include "editstudentdialog.h"
#include "addstudentdialog.h"
#include "deletestudentdialog.h"
#include "editallassignmentsdialog.h"
#include "deleteallassignmentdialog.h"
#include "addallextrapoints.h"
#include "viewallgrades.h"
#include "editscoresdialog.h"

class QPushButton;
class QLabel;
class QListWidget;
class AddAssignmentDialog;
class QMessageBox;

/*	ViewClassDialog will be used when the user clicks "Open Class" from the main
	window of the program. It provides an interface for the user to add/remove
	students, add/remove assignments, add extra credit and save the edited class.
*/

class ViewClassDialog: public QDialog
{
	Q_OBJECT
public:
	ViewClassDialog(Gradebook *book, QWidget *parent = 0);
	void loadGradebook(Gradebook *book);
private:
	Gradebook *gradebook;
	Gradebook editedGradebook;
	bool hasBeenEdited;

	QLabel *titleLabel;
	QLabel *listViewLabel;

	QPushButton *editStudentButton;
	QPushButton *addAssignmentButton;
	QPushButton *editAssignmentButton;
	QPushButton *editAssignmentEarnedButton;
	QPushButton *deleteAssignmentButton;
	QPushButton *addExtraPointsButton;
	QPushButton *viewAllGradesButton;
	QPushButton *addStudentButton;
	QPushButton *removeStudentButton;
	QPushButton *saveButton;
	QPushButton *closeButton;

	QMessageBox *messageWin;
	AddAssignmentDialog *addAssignmentDialog;
	EditStudentDialog *editStudentDialog;
	AddStudentDialog *addStudentDialog;
	DeleteStudentDialog *deleteStudentDialog;
	EditAllAssignmentsDialog *editAllAssignmentsDialog;
	EditCommonDialog *editScoresDialog;
	DeleteAllAssignmentDialog *deleteAllAssignmentDialog;
	AddAllExtraPoints *addAllExtraPoints;
	ViewGradesTable *viewGradesTable;

	QListWidget *studentList;

	void connectWidgets();

	Student & getSelectedStudent();
	bool classIsEmpty();
private slots:
	void populateStudentList();
	void save();
	void silentSave();	// Doesn't display a confirmation window during save
	void loadRecentlySavedGradebook();
	void closeWin();
	void setEdited();
	void addAssignment();
	void editStudent();
	void addStudent();
	void deleteStudent();
	void editAssignment();
	void editAssignmentEarned();
	void deleteAssignment();
	void addExtraPoints();
	void viewAllGrades();
signals:
};

#endif
