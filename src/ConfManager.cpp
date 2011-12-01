#include "ConfManager.h"


void ConfManager::parseFile() {
    QFile file(fileName);
    if (!file.exists())
        return;
    if (!file.open(QIODevice::ReadOnly))
        return;
    QTextStream stream(&file);
    while (!stream.atEnd()) {
        parseLine(stream.readLine());
    }
    file.close();
}

void ConfManager::parseLine(QString line) {
    if (line.isEmpty())
        return;
    QStringList params = line.split('=');
    if (params.length() != 2)
        return;

    QString first = params.first();
    QString second = params.last();
    map.insert(first.toStdString().c_str(), second.toStdString().c_str());
}

void ConfManager::setDefault() {
    map.insert("greensquare", "following");
    map.insert("greencrosssquare", "followinggrowing");
    map.insert("pacman", "followingrotating");
    map.insert("shuriken", "rapidefollowing");
    map.insert("star", "immobilefiring");
    map.insert("ship", "charging");
}
