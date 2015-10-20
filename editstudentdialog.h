#ifndef EDITSTUDENTDIALOG_H
#define EDITSTUDENTDIALOG_H
#include <QDialog>
#include "student.h"
#include "gradebook.h"
#include "assignment.h"
#include "addassignmentdialog.h"

/*	The EditStudentDialog class is used when the user is editing one specific
	student. Actions allowed are adding/removing an assignment, editing an
	assignment, and adding extra credit to the student. It also displays the
	students current grade, extra credit and points earned vs points possible.
*/

class QLabel;
class QLineEdit;
class QPushButton;
class QListWidget;
class QMessageBox;

class EditStudentDialog: public QDialog
{
	Q_OBJECT
public:
	EditStudentDialog(Gradebook *book, Student *stu, QWidget *parent = 0);
	void changeStudent(Gradebook *book, Student *stu);
private:
	Gradebook *gradebook;
	Student *student;
	Student editedStudent;
	bool hasBeenEdited;

	QLabel *titleLabel;
	QLabel *studentNameLabel;
	QLabel *currentGradeLabel;
	QLabel *currentPointsLabel;
	QLabel *extraCreditLabel;
	QLabel *totalPointsLabel;
	QListWidget *assignmentList;
	QPushButton *editAssignment;
	QPushButton *addAssignment;
	QPushButton *deleteAssignment;
	QPushButton *addExtraPoints;
	QPushButton *saveButton;
	QPushButton *closeButton;

	// Edit Windows
	AddIndvAssignmentDialog *addDialog;
	EditIndvAssignmentDialog *editDialog;
	AddExtraPointsDialog *extraPointsDialog;

	QMessageBox *messageWin;
	QMessageBox *confirmWin;

	//Utility functions
	void connectWidgets();
	void loadAssignments();
	void loadStats();
private slots:
	void closeConfirm();		// Close window, check for save
	void addAssignmentSlot();	// Display dialog to add new assignment
	void editAssignmentSlot();	// Display dialog to edit an existing assignment
	void deleteAssignmentSlot();// Display confirmation window to delete selected assignment
	void addExtraPointsSlot();	// Give the user extra credit points
	void setEdited();			// Set flag if there has been an unsaved edit
	void save();				// Write changes to the file stored by Gradebook
	void updateStudentInfo();	// Update the displayed assignment and stats
signals:
	void assignmentEdited();
	void gradebookSaved();
};



#endif
