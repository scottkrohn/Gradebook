#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H
#include <QDialog>
#include "gradebook.h"
#include "student.h"

class QMessageBox;
class QLabel;
class QPushButton;
class QLineEdit;

class AddStudentDialog: public QDialog
{
	Q_OBJECT
public:
	AddStudentDialog(Gradebook *book, QWidget *parent = 0);
	void changeGradebook(Gradebook *book);
private:
	Gradebook *gradebook;

	QLabel *titleLabel;
	QLabel *nameLabel;
	QLineEdit *nameBox;
	QPushButton *cancelButton;
	QPushButton *submitButton;
	QMessageBox *messageWin;

	void connectWidgets();
	std::string getName() const;
private slots:
	void close();
	void addStudent();
	void enableSubmitButton(const QString &text);
signals:
	void studentAdded();
};

#endif
