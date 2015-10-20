#ifndef DELETEALLASSIGNMENTDIALOG_H
#define DELETEALLASSIGNMENTDIALOG_H
#include <QDialog>
#include "gradebook.h"
#include "assignment.h"
#include <string>

class QLineEdit;
class QLabel;
class QListWidget;
class QPushButton;
class QMessageBox;
class ConfirmDeleteAssignment;

class DeleteAllAssignmentDialog: public QDialog
{
	Q_OBJECT
public:
	DeleteAllAssignmentDialog(Gradebook *book, QWidget *parent = 0);
	void changeGradebook(Gradebook *book);
private:
	Gradebook *gradebook;

	QLabel *titleLabel;
	QLabel *assignmentLabel;
	QPushButton *closeButton;
	QPushButton *deleteButton;
	QListWidget *assignmentList;
	QMessageBox *messageWin;
	ConfirmDeleteAssignment *confirmWin;

	void connectWidgets();
	void populateCommonAssignments();
private slots:
	void close();
	void deleteAssignment();
	void emitDeleted();
signals:
	void assignmentDeleted();
};

class ConfirmDeleteAssignment: public QDialog
{
	Q_OBJECT
public:
	ConfirmDeleteAssignment(const std::string &assignName, Gradebook *book, QWidget *parent = 0);
	void changeAssignment(const std::string &assignName, Gradebook *book);
private:
	Gradebook *gradebook;
	std::string assignmentName;

	QLabel *titleLabel;
	QLabel *boxLabel;
	QLineEdit *deleteBox;
	QPushButton *cancelButton;
	QPushButton *deleteButton;
	QMessageBox *messageWin;

	void connectWidgets();
private slots:
	void enableDeleteButton(const QString &text);
	void close();
	void deleteAssignment();
signals:
	void assignmentDeleted();
};

#endif
