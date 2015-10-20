#ifndef ADDASSIGNMENTDIALOG_H
#define ADDASSIGNMENTDIALOG_H
#include <QDialog>
#include "gradebook.h"
#include "assignment.h"
#include "student.h"

class QString;
class QLabel;
class QLineEdit;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QMessageBox;

class AssignmentDialogBase: public QDialog
{
	Q_OBJECT
public:
	AssignmentDialogBase(QWidget *parent = 0);
protected:
	QLabel *titleLabel;
	QLabel *boxOneLabel;
	QLabel *boxTwoLabel;
	QLineEdit *boxOne;
	QLineEdit *boxTwo;
	QPushButton *submitButton;
	QPushButton *cancelButton;

	QHBoxLayout *topHorLayout;
	QHBoxLayout *midHorLayout;
	QHBoxLayout *botHorLayout;

	QVBoxLayout *vertLayout;

	QMessageBox *messageWin;

	virtual void connectWidgets() = 0;
};

class AddAssignmentDialog: public AssignmentDialogBase
{
	Q_OBJECT
public:
	AddAssignmentDialog(Gradebook *book, QWidget *parent = 0);
	void changeGradebook(Gradebook *book);
private:
	Gradebook *gradebook;

	void connectWidgets();
private slots:
	void addAssignment();
	void enableSubmitButton(const QString &text);
	void close();
signals:
	void assignmentAdded();
};

class AddIndvAssignmentDialog: public AssignmentDialogBase
{
	Q_OBJECT
public:
	AddIndvAssignmentDialog(Student *stu, QWidget *parent = 0);
	void changeStudent(Student *stu);
private:
	Student *student;

	QLineEdit *earnedPointsBox;
	QLabel *earnedPointsLabel;
	void connectWidgets();
private slots:
	void addAssignment();
	void enableSubmitButton(const QString &text);
	void close();
signals:
	void assignmentAdded();
};

class EditIndvAssignmentDialog: public AssignmentDialogBase
{
	Q_OBJECT
public:
	EditIndvAssignmentDialog(Student *stu, const std::string &name = "", QWidget *parent = 0);
	// Change the Student and assignment name on which the dialog is acting
	void changeAssignment(Student *stu, const std::string &name);
private:
	Student *student;
	std::string assignmentName;

	QMessageBox *confirmWin;

	QLineEdit *earnedPointsBox;
	QLabel *earnedPointsLabel;
	QLabel *origName;
	QLabel *origPoints;

	void connectWidgets();
	void displayOrigData();
private slots:
	void enableSubmitButton(const QString &text);
	void editAssignment();
	void close();
signals:
	void assignmentEdited();
};

class AddExtraPointsDialog: public AssignmentDialogBase
{
	Q_OBJECT
public:
	AddExtraPointsDialog(Student * stu, QWidget *parent = 0);
	void changeStudent(Student *stu);
private:
	Student *student;

	void connectWidgets();
private slots:
	void close();
	void addExtraPoints();
	void enableSubmitButton(const QString &text);
signals:
	void extraPointsAdded();
};

#endif
