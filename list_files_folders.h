#ifndef LIST_FILES_FOLDERS_H
#define LIST_FILES_FOLDERS_H

#include <QString>

void list_all(QString str);
void list_favorites();
void list_devices();
void list_os_type();
void list_storage();
void list_mont_points();

void write_to_file(QString filename, QString str);

#endif // LIST_FILES_FOLDERS_H
