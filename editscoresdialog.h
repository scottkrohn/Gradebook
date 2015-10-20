#ifndef EDITSCORESDIALOG_H
#define EDITSCORESDIALOG_H
#include <QDialog>
#include <string>
#include "gradebook.h"
#include "assignment.h"
#include "student.h"
#include <vector>
#include <utility>

class QTableWidget;
class QPushButton;
class QLabel;
class QDoubleValidator;
class QMessageBox;
class EditScoresDialog;
class QListWidget;

class EditCommonDialog: public QDialog
{
	Q_OBJECT
public:
	EditCommonDialog(Gradebook *book, QWidget *parent = 0);
	~EditCommonDialog();
	void changeGradebook(Gradebook *book);
	void populateAssignments();
private:
	Gradebook *gradebook;

	QLabel *titleLabel;
	QLabel *commonLabel;
	QListWidget *assignmentList;
	QPushButton *editButton;
	QPushButton *closeButton;
	EditScoresDialog *editScoresDialog;
	QMessageBox *messageWin;

	void connectWidgets();
private slots:
	void editAssignment();
	void close();
	void emitSaved();
signals:
	void gradebookSaved();
};

class EditScoresDialog: public QDialog
{
	Q_OBJECT
public:
	EditScoresDialog(const std::string &assignName, Gradebook *book, QWidget *parent);
	~EditScoresDialog();
	void changeAssignment(const std::string &assignName, Gradebook *book);
private:
	Gradebook *gradebook;
	std::string assignmentName;
	double pointsPossible;
	bool hasBeenSaved;

	QLabel *titleLabel;
	QLabel *assignLabel;
	QTableWidget *gradesTable;
	QPushButton *saveButton;
	QPushButton *closeButton;
	QDoubleValidator *dValidator;
	QMessageBox *messageWin;

	std::vector<std::pair<std::string,double> > editedScores;

	void connectWidgets();
	void resizeTable(int studentCount);
	void loadData();
	double getPointsPossible() const;

	// Validate entry returns a pair indicating success/failure and the student name
	std::pair<bool,std::string> validateEntry(QString &entry,
										      const std::string &stuName) const;
private slots:
	void save();
signals:
	void gradebookSaved();
};



#endif
