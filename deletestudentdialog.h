#ifndef DELETESTUDENTDIALOG_H
#define DELETESTUDENTDIALOG_H
#include <QDialog>
#include "gradebook.h"
#include "student.h"
#include <string>

class QLabel;
class QPushButton;
class QLineEdit;
class QString;
class QMessageBox;

class DeleteStudentDialog: public QDialog
{
	Q_OBJECT
public:
	DeleteStudentDialog(const std::string &name, Gradebook *book, QWidget *parent = 0);
	void changeStudent(const std::string &name, Gradebook *book);
private:
	std::string studentName;
	Gradebook *gradebook;

	QLabel *titleLabel;
	QLabel *boxLabel;
	QLineEdit *deleteBox;
	QPushButton *submitButton;
	QPushButton *cancelButton;
	QMessageBox *messageWin;

	void connectWidgets();
private slots:
	void close();
	void enableSubmitButton(const QString &text);
	void deleteStudent();
signals:
	void studentDeleted();
};

#endif
