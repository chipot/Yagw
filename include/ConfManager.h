#ifndef CONFMANAGER_H
#define CONFMANAGER_H

#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QStringList>

class ConfManager {
private :
    const char *fileName;
    QMap<QString, QString> map;
public:
    ConfManager(const char *name) : fileName(name) {setDefault();}
    void parseFile();
    QString getProfileIndex(QString) const;
private :
    void parseLine(QString);
    void setDefault();
};

#endif // CONFMANAGER_H
