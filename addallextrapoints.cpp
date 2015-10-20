#include "addallextrapoints.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QMessageBox>

AddAllExtraPoints::AddAllExtraPoints(Gradebook *book, QWidget *parent)
	:QDialog(parent),
	gradebook(book),
	titleLabel(new QLabel("<font size=3><b>Add Extra Credit</b></font>", this)),
	boxLabel(new QLabel("Points:", this)),
	pointsBox(new QLineEdit(this)),
	submitButton(new QPushButton("Submit", this)),
	cancelButton(new QPushButton("Cancel", this)),
	messageWin(new QMessageBox(this))
{
	setWindowTitle("Add Extra Credit");
	titleLabel->setAlignment(Qt::AlignHCenter);
	titleLabel->setFrameStyle(QFrame::Box);
	titleLabel->setLineWidth(1);
	boxLabel->setAlignment(Qt::AlignHCenter);

	QVBoxLayout *vertLayout = new QVBoxLayout;
	QHBoxLayout *botLayout = new QHBoxLayout;
	QHBoxLayout *midLayout = new QHBoxLayout;

	midLayout->addWidget(boxLabel);
	midLayout->addWidget(pointsBox);

	botLayout->addWidget(cancelButton);
	botLayout->addWidget(submitButton);

	vertLayout->addWidget(titleLabel);
	vertLayout->addLayout(midLayout);
	vertLayout->addLayout(botLayout);

	pointsBox->setValidator(new QIntValidator(this));
	setLayout(vertLayout);
	connectWidgets();
	resize(sizeHint());
}

void AddAllExtraPoints::changeGradebook(Gradebook *book)
{
	gradebook = book;
}

void AddAllExtraPoints::connectWidgets()
{
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(pointsBox, SIGNAL(textChanged(QString)), this, SLOT(enableSubmitButton(QString)));
	connect(submitButton, SIGNAL(clicked()), this, SLOT(addPoints()));
}

void AddAllExtraPoints::close()
{
	pointsBox->clear();
	QDialog::close();
}

void AddAllExtraPoints::enableSubmitButton(const QString &text)
{
	if(text.isEmpty())
	{
		submitButton->setEnabled(false);
	}
	else
	{
		submitButton->setEnabled(true);
	}
}

void AddAllExtraPoints::addPoints()
{
	double pointValue(pointsBox->text().toDouble());
	if(pointValue <= 0)
	{
		messageWin->setWindowTitle("Notice");
		messageWin->setText("Extra points amount must be greater than zero.");
		messageWin->exec();
		pointsBox->clear();
		return;
	}

	if(gradebook->addExtraPointsAll(pointValue))
	{
		messageWin->setWindowTitle("Success!");
		messageWin->setText("Extra points successfully added.");
		messageWin->exec();
		close();
		emit extraPointsAdded();
	}
	else
	{
		messageWin->setWindowTitle("Error");
		messageWin->setText("Points were NOT successfully added!");
		messageWin->exec();
		return;
	}
}
