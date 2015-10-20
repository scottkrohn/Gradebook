#ifndef ADDALLEXTRAPOINTS_H
#define ADDALLEXTRAPOINTS_H
#include <QDialog>
#include "gradebook.h"

class QLabel;
class QPushButton;
class QLineEdit;
class QMessageBox;

class AddAllExtraPoints: public QDialog
{
	Q_OBJECT
public:
    AddAllExtraPoints(Gradebook *book, QWidget *parent = 0);
    void changeGradebook(Gradebook *book);
private:
    Gradebook *gradebook;
    QLabel *titleLabel;
    QLabel *boxLabel;
    QLineEdit *pointsBox;
    QPushButton *submitButton;
    QPushButton *cancelButton;
	QMessageBox *messageWin;

    void connectWidgets();
private slots:
    void close();
    void enableSubmitButton(const QString &text);
    void addPoints();
signals:
	void extraPointsAdded();
};

#endif
