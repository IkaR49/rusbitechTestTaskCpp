#pragma once

#include <QtGui/QWidget>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QListWidget>
#include <QtGui/QKeyEvent>

class smallListApp : public QWidget
{
    Q_OBJECT;
    private:
        QLineEdit* lineEdit;
        QPushButton* addButton;
        QPushButton* delButton;
        QListWidget* listWidget;
    public slots:
        void copyTextToList();
        void delTextFromList();
    protected:
        virtual void keyPressEvent(QKeyEvent*);
    public:
        smallListApp(QWidget* = 0);
        ~smallListApp();
};

