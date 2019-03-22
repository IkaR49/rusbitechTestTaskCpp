#include <QApplication>
#include "smallListApp.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    smallListApp mainFrame;

    mainFrame.show();
    return app.exec();
}

