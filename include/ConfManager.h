#ifndef CONFMANAGER_H
#define CONFMANAGER_H

#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QStringList>

class ConfManager {
private :
    const char *fileName;
public:
    ConfManager(const char *name) : fileName(name) {setDefault();}
    void parseFile();
    QMap<const char*, const char*> map;
private :
    void parseLine(QString);
    void setDefault();
};

#endif // CONFMANAGER_H
