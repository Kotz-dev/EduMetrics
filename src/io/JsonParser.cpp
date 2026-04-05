//
// Created by KoTz on 20/11/2025.
//

#include "../../include/io/JsonParser.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <nlohmann/json.hpp>
#include <fstream>


void JsonParser::removeQuotes(QString  & str) {
    if (str.isEmpty()) {
        return;
    }
    if (str.contains("\"")) {
        str.remove("\"");
    }
}

bool JsonParser::writeJsonKey(QString pathc,std::string key,std::string value) {
    if (pathc.isEmpty() == false) {
        QFile filew{pathc};
        filew.open(QFile::ReadOnly | QFile::Text | QFile::WriteOnly);
        nlohmann::json json = nlohmann::json::parse(filew.readAll().toStdString());
        json[key] = value;
        std::ofstream outFile(pathc.toStdString());
        outFile << std::setw(2) << json << std::endl;
        outFile.close();
        filew.close();
        return true;
    }
    return false;
}


nlohmann::json JsonParser::buildConfigJson(ConfigFileData obj) {
    nlohmann::json json = {
        {"idioma" ,      obj.idioma},
        {"config",       obj.config},
        {"tema",         obj.tema},
        {"Fonte",        obj.fonte},
    };
    return json;
}


QString JsonParser::readJsonKeyAsString(QString patch, QString key) {
    nlohmann::json json;
    QString get;
    QFile filew{patch};
    filew.open(QFile::ReadOnly | QFile::Text);
    try {
        json = nlohmann::json::parse(filew.readAll().toStdString());
    }catch (nlohmann::json::exception & e) {
        qDebug () << e.what();
        return "Error";
    }
    get = QString::fromStdString(json[key.toStdString()]).remove("'").remove("\\");
    return get;
}
nlohmann::json JsonParser::readJsonKey(QString Patch, QString key) {
    nlohmann::json json;
    QFile filew{Patch};
    filew.open(QFile::ReadOnly | QFile::Text);
    try {
        json = nlohmann::json::parse(filew.readAll().toStdString());
    }catch (nlohmann::json::exception & e) {
        qDebug () << e.what();
        return nlohmann::json {};
    }
    return json[key.toStdString()];
}
JsonParser::JsonParser() {

}
