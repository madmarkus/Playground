#include <QtGui>
#include <iostream>

extern "C" {
	#include "mean.h"
}

#include "finddialog.h"


FindDialog::FindDialog(QWidget *parent)
     : QDialog(parent)
{
    lineEditFirst = new QLineEdit;
    labelFirst    = new QLabel(tr("F&irst Number:"));
    labelFirst->setBuddy(lineEditFirst);
    connect(lineEditFirst, SIGNAL(textChanged(const QString &)),
           this, SLOT(enableFindButton()));

    lineEditSecond = new QLineEdit;
    labelSecond    = new QLabel(tr("&Second Number:"));
    labelSecond->setBuddy(lineEditSecond);
    connect(lineEditSecond, SIGNAL(textChanged(const QString &)),
           this, SLOT(enableFindButton()));

    calcButton = new QPushButton(tr("&Calc"));
    calcButton->setDefault(true);
    calcButton->setEnabled(false);
    connect(calcButton, SIGNAL(clicked()),
           this, SLOT(findClicked()));

    closeButton = new QPushButton(tr("Close"));
    connect(closeButton, SIGNAL(clicked()),
           this, SLOT(close()));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(labelFirst);
    topLeftLayout->addWidget(lineEditFirst);

    QHBoxLayout *bottomleftLayout = new QHBoxLayout;
    bottomleftLayout->addWidget(labelSecond);
    bottomleftLayout->addWidget(lineEditSecond);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addLayout(bottomleftLayout);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(calcButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("Mean"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::enableFindButton()
{
    int length1 = lineEditFirst->text().length();
    int length2 = lineEditSecond->text().length();

    calcButton->setEnabled( length1 != 0 && length2 != 0 );
}

void FindDialog::findClicked()
{
    int a = atoi(lineEditFirst->text().toLocal8Bit().constData());
    int b = atoi(lineEditSecond->text().toLocal8Bit().constData());

    QString message = QString("The mean between %1 and %2 is %3").arg(a).arg(b).arg(mean(a,b));
    QMessageBox box;

    box.setWindowTitle("The Mean");
    box.setText(message);

    box.addButton(QMessageBox::Ok);
    box.addButton(QMessageBox::Cancel);

    box.exec();
}

