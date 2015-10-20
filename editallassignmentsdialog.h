#ifndef EDITALLASSIGNMENTSDIALOG_H
#define EDITALLASSIGNMENTSDIALOG_H
#include <QDialog>
#include "gradebook.h"
#include "student.h"
#include "assignment.h"
#include <string>

/*	Edit EditAllAssignmentsDialog class displays a list of the assignments that
	are common to all Students in a gradebook. It allows the user to select a
	common assignment to edit. The only thing that can be edited is the points
	possible value of the assignment. When a common assignment is selected,
	a dialog will appear to take input from the user to change the points possible
	value. When the value is successfully changed, the EditAllAssignmentsDialog
	emits a signal to the ViewClassDialog window to silently save the gradebook.
*/

class QLabel;
class QLineEdit;
class QString;
class QListWidget;
class QPushButton;
class QMessageBox;
class EditMultipleAssignments;

class EditAllAssignmentsDialog: public QDialog
{
	Q_OBJECT
public:
	EditAllAssignmentsDialog(Gradebook *book, QWidget *parent = 0);
	void changeGradebook(Gradebook *book);
	void populateAssignments();
private:
	Gradebook *gradebook;

	QLabel *titleLabel;
	QLabel *commonLabel;
	QListWidget *assignmentList;
	QPushButton *editButton;
	QPushButton *closeButton;
	EditMultipleAssignments *editWindow;
	QMessageBox *messageWin;

	void connectWidgets();
private slots:
	void editAssignment();
	void close();
	void emitSaveGradebook();
signals:
	void saveGradebook();
};

/*	The EditMultipleAssignments dialog displays the current points possible
	value for an assignment that is common to all students in a gradebook. The
	user can input a new value to be used for the assignment's points possible
	data member. Upon clicking save, two signals are emitted to the previous
	screen, saveGradebook and editComplete.
*/

class EditMultipleAssignments: public QDialog
{
	Q_OBJECT
public:
	EditMultipleAssignments(const std::string &assignName, Gradebook *book, QWidget *parent = 0);
	void changeAssignment(const std::string &assignName, Gradebook *book);
private:
	Gradebook *gradebook;
	std::string assignmentName;

	QLabel *titleLabel;
	QLabel *assignNameLabel;
	QLabel *pointValueLabel;
	QLabel *boxLabel;
	QLineEdit *pointsBox;
	QPushButton *saveButton;
	QPushButton *cancelButton;

	QMessageBox *messageWin;

	void connectWidgets();
	void loadAssignmentData();
private slots:
	void enableSaveButton(const QString &text);
	void editAssignment();
	void close();
	void save();
signals:
	void saveGradebook();
	void editComplete();
};
#endif
