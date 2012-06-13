#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include "finddialog.h"

#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
     Q_OBJECT

public:
     FindDialog(QWidget *parent = 0);

signals:
     void findNext(const QString &str, Qt::CaseSensitivity cs);
     void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
     void findClicked();
     void enableFindButton();

private:
     QLabel *labelFirst;
     QLineEdit *lineEditFirst;
     QLabel *labelSecond;
     QLineEdit *lineEditSecond;
     QPushButton *calcButton;
     QPushButton *closeButton;
};

#endif
