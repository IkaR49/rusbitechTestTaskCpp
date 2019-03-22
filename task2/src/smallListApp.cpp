#include "smallListApp.hpp"

smallListApp::smallListApp(QWidget* parent) : QWidget(parent)
{
    this->setWindowTitle("TestTask2");
    this->setContextMenuPolicy(Qt::NoContextMenu);

    lineEdit = new QLineEdit(this);
    lineEdit->setContextMenuPolicy(Qt::NoContextMenu);

    delButton = new QPushButton(this);
    delButton->setText(QString::fromUtf8("Удалить"));

    addButton = new QPushButton(this);
    addButton->setText(QString::fromUtf8("Добавить"));

    listWidget = new QListWidget(this);
    listWidget->setContextMenuPolicy(Qt::NoContextMenu);

    /* Задаём размеры */
    int space = 2;
    int smallWidth = 99;
    int smallHeight = 26;

    int bigWidth = smallWidth * 2 + space;
    int bigHeight = 240;

    int fullWidth = space * 2 + bigWidth;
    int fullHeight = smallHeight * 2 + bigHeight + space * 4;

    this->resize(fullWidth, fullHeight);
    lineEdit->setGeometry(QRect(space, space, bigWidth, smallHeight));
    delButton->setGeometry(QRect(space, space * 2 + smallHeight, smallWidth, smallHeight));
    addButton->setGeometry(QRect(space * 2 + smallWidth, space * 2 + smallHeight, smallWidth, smallHeight));
    listWidget->setGeometry(QRect(space, space * 3 + smallHeight * 2, bigWidth, bigHeight));

    /* Подключаем слоты и сигналы */
    connect(delButton, SIGNAL(clicked(bool)), this, SLOT(delTextFromList()));
    connect(addButton, SIGNAL(clicked(bool)), this, SLOT(copyTextToList()));
}

smallListApp::~smallListApp()
{
    //
}

void smallListApp::copyTextToList()
{
    QString text = lineEdit->text();
    if (!text.isEmpty())
    {
        listWidget->addItem(text);
        lineEdit->clear();
    }
}

void smallListApp::delTextFromList()
{
    delete listWidget->takeItem(listWidget->currentRow());
}

// По-хорошему это следовало бы создать отдельные классы для QLineEdit и QListWidget (наследующие их),
// к ним прикручивать это отслеживание нажатых клавиш, а уже полученные классы использовать в этом виджете.
// Но делать я этого конечно же не буду (необоснованное усложнение минимального проекта).
void smallListApp::keyPressEvent(QKeyEvent* event)
{
    int key = event->key();
    switch(key) {
        case Qt::Key_Enter :
        case Qt::Key_Return :
            this->copyTextToList();
            break;
        case Qt::Key_Delete :
            this->delTextFromList();
            break;
    }
}

