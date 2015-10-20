#ifndef ADDGRADEBOOKGUI_H
#define ADDGRADEBOOKGUI_H
#include <QDialog>
#include "gradebookmanager.h"

class QLabel;
class QLineEdit;
class QPushButton;

/*	AddGradebookDialog will be used when the Gradebook user is adding a new
	Gradebook to the system. It will get the basics necessary to create the
	Gradebook, then the user can edit the Gradebook from another GUI.
*/
class AddGradebookDialog: public QDialog
{
	Q_OBJECT
public:
	AddGradebookDialog(GradebookManager & gbmanager, QWidget *parent = 0);
private:
	QLabel *titleLabel;
	QLabel *lineEditLabel;
	QLineEdit *classNameBox;
	QPushButton *submitButton;
	QPushButton *cancelButton;

	GradebookManager & manager;
	QString newClassname;

	void connectButtons();
	bool createNewClass(const std::string &classname);
private slots:
	void submitDialog();
signals:
	void returnClassname(const QString &classname);
};

#endif
