#include <QDir>
#include <QStandardPaths>
#include <QDebug>
#include <QStorageInfo>

void list_all(QString str){
    QDir dir(str);

    QFileInfoList list = dir.entryInfoList();
    const int ct= list.size();
    qDebug()<< QString::number(ct)<<" Files and Folders ";
    qDebug() << "Name,type(directory of file),extension,created_date,modified_date,size";
    for (int i = 0; i < ct; ++i) {
        QFileInfo fileInfo = list.at(i);
        qDebug() << QString("Name%1").arg(fileInfo.fileName())
                 << QString(" Size%1").arg(fileInfo.size(), 10)
                << QString(" directory?%1").arg(fileInfo.isDir())
                << QString(" owner%1").arg(fileInfo.owner())
                   << QString(" File?%1").arg(fileInfo.isFile())
//            << QString(" File?%1").arg(fileInfo.birthTime())
//            << QString(" File?%1").arg(fileInfo.lastRead())
//            << QString(" File?%1").arg(fileInfo.lastModified())
//               << QString(" File?%1").arg(fileInfo.permission())
        << QString(" File?%1").arg(fileInfo.isExecutable())
        << QString(" File?%1").arg(fileInfo.bundleName());

    }
}

void write_to_file(QString filename, QString str){
    QDir directory(filename);

    if (directory.exists()){
        qDebug() << directory << " exists";
    }

    auto path = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    qDebug() << path;
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath())) {
        qDebug() << "settings in " << QDir::currentPath();
        QFile f{filename};
        if (f.open(QIODevice::WriteOnly | QIODevice::Truncate))
            f.write(str.toLocal8Bit().constData());
    }

}

void list_favorites(){
    auto path_home = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    auto path_desktop = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    auto path_documents = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    auto path_download = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    auto path_music = QStandardPaths::writableLocation(QStandardPaths::MusicLocation);
    auto path_pictures = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    auto path_movies = QStandardPaths::writableLocation(QStandardPaths::MoviesLocation);


    qDebug() << path_home;
    qDebug() << path_desktop;
    qDebug() << path_documents;
    qDebug() << path_download;
    qDebug() << path_music;
    qDebug() << path_pictures;
    qDebug() << path_movies;
}

void list_devices(){
    auto path_home = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    foreach(QFileInfo qfi, QDir::drives()){
        qDebug() << qfi;
    }


    QString myPath="/dev";// This works when I set it to my dummy folder /home/me/dev with dummy text files in it.
    QDir dir;
    dir.setPath(myPath);
    QStringList filters;
    filters<<"sd*";
    dir.setNameFilters(filters);
//    dir.setSorting(QDir::Name );
    //Search for all files including system files (system means device files on linux)
    dir.setFilter( QDir::AllEntries | QDir::System);

    QFileInfoList list = dir.entryInfoList();

    const int ct= list.size();
    qDebug()<<"Found " <<QString::number(ct)<<" HDD";
    for (int i = 0; i <ct; ++i) {
        QFileInfo fileInfo = list.at(i);
        qDebug()<<"Camera : "<<QString("%1 %2").arg(fileInfo.size(), 10).arg(fileInfo.fileName());

    }

}

void list_storage(){
    QStorageInfo storage = QStorageInfo::root();

        qDebug() << storage.rootPath();
        if (storage.isReadOnly())
            qDebug() << "isReadOnly:" << storage.isReadOnly();

        qDebug() << "name:" << storage.name();
        qDebug() << "fileSystemType:" << storage.fileSystemType();
        qDebug() << "size:" << storage.bytesTotal()/1000/1000 << "MB";
        qDebug() << "availableSize:" << storage.bytesAvailable()/1000/1000 << "MB";


        auto x = storage.device();
        qDebug() << x;
}

void list_network(){

}

void list_mont_points(){
    QFile file("/etc/mtab");
    if (file.open(QFile::ReadOnly)) {
      QStringList mountpoints;
      while(true) {
        QStringList parts = QString::fromLocal8Bit(file.readLine()).trimmed().split(" ");
        if (parts.count() > 1) {
          mountpoints << parts[1];
        } else {
          break;
        }
      }
      qDebug() << mountpoints;
    }

    qDebug() << "mounted volumes" ;
    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
        if (storage.isValid() && storage.isReady()) {
            if (!storage.isReadOnly()) {
//                qDebug() << storage.displayName();
                // ...
            }
            qDebug() << storage.displayName();
        }
    }


    qDebug() << "drives" ;
    foreach( QFileInfo drive, QDir::drives() )
           {
             qDebug() << "Drive: " << drive.absolutePath();
           }
}

void list_os_type(){
    qDebug() << "currentCpuArchitecture():" << QSysInfo::currentCpuArchitecture();
    qDebug() << "productType():" << QSysInfo::productType();
    qDebug() << "productVersion():" << QSysInfo::productVersion();
    qDebug() << "prettyProductName():" << QSysInfo::prettyProductName();

}
