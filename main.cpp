#include "mainwindow.h"
#include <QApplication>
#include <QStandardPaths>
#include "list_files_folders.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationDomain("unknown.com");
    app.setApplicationName("Wanderer.V0.1");

    QIcon icon(":/icon/Resources/my_icons/folder/folder.png");
    app.setWindowIcon(icon);
    MainWindow w;
    // set QSizePolicy
    w.show();

    auto path = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
//    list_all(path);
//    list_favorites();
//    list_devices();
//    list_storage();
//    list_mont_points();
//    list_os_type();

    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
//    QIcon::setThemeName("tango");
     qDebug() << "QIcon::themeName() " << QIcon::themeName();

    return app.exec();
}
