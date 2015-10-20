#ifndef DELETEGRADEBOOKDIALOG_H
#define DELETEGRADEBOOKDIALOG_H
#include "gradebookmanager.h"
#include <QDialog>
#include <iostream>

/*	The DeleteGradebookDialog class will be used to delete a class's gradebook
	from the whole gradebook program. This is an action that cannot be undone,
	so the user is warned before deleting and must confirm the action.
*/

class QString;
class QLabel;
class QListWidget;
class QPushButton;
class QMessageBox;

class DeleteGradebookDialog: public QDialog
{
	Q_OBJECT
public:
	DeleteGradebookDialog(GradebookManager &gbmanager, QWidget *parent = 0);
	~DeleteGradebookDialog();
	void loadClassnames();
private:
	QLabel *titleLabel;
	QListWidget *classList;
	QPushButton *deleteButton;
	QPushButton *closeButton;

	GradebookManager & manager;
	QMessageBox *messageWin;

	// Utility functions
	void connectWidgets();
	QString getSelectionName() const;
	bool classExists(const std::string &classname) const;
private slots:
	void deleteClass();
	void close();
};

#endif
