//
// Created by KoTz on 23/10/2025.
//

#include "managers/LanguageManager.h"
#include <ui_option.h>
#include "io/FileManager.h"
#include "utils/GlobalAccess.h"

LanguageUI::LanguageUI() {}

void LanguageUI::initialize(Json & config, Ui::MainWindow * mainWindowUi, QString & currentLanguage) {
    if (config.empty() == true) {
         return;
     }
    QFile file{GLOBAL::FILE_PATHS::LANGUAGE};
    if (file.exists() == true) {
        file.open(QFile::ReadOnly | QFile::Text);
        nlohmann::json json = nlohmann::json::parse(file.readAll().toStdString());
        QString idioma = QString::fromStdString(config["idioma"]);
        currentLanguage = idioma;
        applyLanguage(idioma);
    }
}
nlohmann::json LanguageUI::getTranslation(QString languageKey, QString textKey) {
    nlohmann::json json;
    if (languageKey.isEmpty() == true && textKey.isEmpty() == true) {
        return {};
    }
    if (languageKey == "Ingles") {
        languageKey = "en";
    }
    QFile file{GLOBAL::FILE_PATHS::LANGUAGE};
    file.open(QFile::ReadOnly | QFile::Text);
    try {
       json = nlohmann::json::parse(file.readAll().toStdString());
    }catch (nlohmann::json::exception & e) {
        return nlohmann::json {};
    }
    return json[languageKey.toStdString()][textKey.toStdString()];
}

int LanguageUI::getLanguageIndex(QString languageKey) {
    if (languageKey == "Ingles" || languageKey == "en" || languageKey == "en-us" || languageKey == "En" || languageKey == "EN") {
        return 1;
    }
    if (languageKey == "Português"|| languageKey == "pt" || languageKey == "pt-br"
            || languageKey == "portugues"
            || languageKey == "Portugues") {
        return 0;
    }
}

void LanguageUI::applyLanguage(QString & languageKey) {

    if (languageKey.isEmpty()) {
        return;
    }
    QFile filew{GLOBAL::FILE_PATHS::LANGUAGE};
    filew.open(QFile::ReadOnly | QFile::Text);
    nlohmann::json json;
    try {
        json = nlohmann::json::parse(filew.readAll().toStdString());
    }catch (nlohmann::json::exception & e) {
          return;
    }
    std::vector<QString>    menu_arquivo(GLOBAL::WINDOW::UI->menuArquivos->actions().size()+1);
    std::vector<QString>    menu_ferramentas(GLOBAL::WINDOW::UI->menuFerramentas->actions().size()+1);
    std::array<QString,10>  menu_option;
    std::vector<QString>    tabela_aluno(GLOBAL::WINDOW::UI->tableWidget->columnCount());

        if (languageKey == "Ingles" || languageKey == "en" || languageKey == "en-us" || languageKey == "En" || languageKey == "EN") {

            menu_arquivo[0] = QString::fromStdString(json["en"]["arquivo"]).remove('"');
            menu_arquivo[1] = QString::fromStdString(json["en"]["novo"]).remove('"');
            menu_arquivo[2] = QString::fromStdString(json["en"]["abrir"]).remove('"');
            menu_arquivo[3] = QString::fromStdString(json["en"]["salvar"]).remove('"');
            menu_arquivo[4] = QString::fromStdString(json["en"]["salvar como"]).remove('"');

            tabela_aluno[0]  = QString::fromStdString(json["en"]["nome"]).remove('"');
            tabela_aluno[1]  = QString::fromStdString(json["en"]["aulas previstas"]).remove('"');
            tabela_aluno[2]  = QString::fromStdString(json["en"]["aulas ministradas"]).remove('"');
            tabela_aluno[3]  = QString::fromStdString(json["en"]["numero presença"]).remove('"');
            tabela_aluno[4]  = QString::fromStdString(json["en"]["media"]).remove('"');
            tabela_aluno[5]  = QString::fromStdString(json["en"]["resultado"]).remove('"');
            tabela_aluno[6]  = QString::fromStdString(json["en"]["falta media"]).remove('"');

            menu_ferramentas[0]   =  QString::fromStdString(json["en"]["ferramentas"]).remove('"');
            menu_ferramentas[1]   =  QString::fromStdString(json["en"]["Sistema de Preferencia"]).remove('"');

            menu_option[0] =  QString::fromStdString(json["en"]["idioma"]).remove('"');
            menu_option[1] =  QString::fromStdString(json["en"]["aplicar"]).remove('"');
            menu_option[2] =  QString::fromStdString(json["en"]["salvar"]).remove('"');
            menu_option[3] =  QString::fromStdString(json["en"]["Tema"]).remove('"');
            menu_option[4] =  QString::fromStdString(json["en"]["Fonte"]).remove('"');
        }
        if (languageKey == "Português"|| languageKey == "pt" || languageKey == "pt-br"
            || languageKey == "portugues"
            || languageKey == "Portugues") {

            menu_arquivo[0] = QString::fromStdString(json["Português"]["file"]).remove('"');
            menu_arquivo[1] = QString::fromStdString(json["Português"]["new"]).remove('"');
            menu_arquivo[2] = QString::fromStdString(json["Português"]["open"]).remove('"');
            menu_arquivo[3] = QString::fromStdString(json["Português"]["save"]).remove('"');
            menu_arquivo[4] = QString::fromStdString(json["Português"]["save as"]).remove('"');

            tabela_aluno[0]  = QString::fromStdString(json["Português"]["name"]).remove('"');
            tabela_aluno[1]  = QString::fromStdString(json["Português"]["planned classes"]).remove('"');
            tabela_aluno[2]  = QString::fromStdString(json["Português"]["taught classes"]).remove('"');
            tabela_aluno[3]  = QString::fromStdString(json["Português"]["attendance count"]).remove('"');
            tabela_aluno[4]  = QString::fromStdString(json["Português"]["average"]).remove('"');
            tabela_aluno[5]  = QString::fromStdString(json["Português"]["result"]).remove('"');
            tabela_aluno[6]  = QString::fromStdString(json["Português"]["needed avg"]).remove('"');


            menu_ferramentas[0]   =  QString::fromStdString(json["Português"]["tools"]).remove('"');
            menu_ferramentas[1]   =  QString::fromStdString(json["Português"]["Preference System"]).remove('"');


            menu_option[0] =  QString::fromStdString(json["Português"]["language"]).remove('"');
            menu_option[1] =  QString::fromStdString(json["Português"]["apply"]).remove('"');
            menu_option[2] =  QString::fromStdString(json["Português"]["save"]).remove('"');
            menu_option[3] =  QString::fromStdString(json["Português"]["theme"]).remove('"');
            menu_option[4] =  QString::fromStdString(json["Português"]["Font"]).remove('"');
        }
            GLOBAL::WINDOW::UI->menuArquivos->setTitle(menu_arquivo[0]);
            GLOBAL::WINDOW::UI->actionNovo->setText(menu_arquivo[1]);
            GLOBAL::WINDOW::UI->actionAbrir->setText(menu_arquivo[2]);
            GLOBAL::WINDOW::UI->actionSalvar->setText( menu_arquivo[3]);
            GLOBAL::WINDOW::UI->actionSalvar_como->setText(menu_arquivo[4]);

            GLOBAL::WINDOW::UI->tableWidget->setHorizontalHeaderLabels({
                tabela_aluno[0],
                tabela_aluno[1],
                tabela_aluno[2],
                tabela_aluno[3],
                   "N1",
                   "N2",
                tabela_aluno[4],
                tabela_aluno[5],
                tabela_aluno[6]
            });

            GLOBAL::WINDOW::UI->menuFerramentas->setTitle(menu_ferramentas[0]);
            GLOBAL::WINDOW::UI->actionOpition->setText(menu_ferramentas[1]);;

          if (GLOBAL::WINDOW::_ui_option != nullptr) {
               GLOBAL::WINDOW::_ui_option->ui()->label->setText(menu_option[0]);
               GLOBAL::WINDOW::_ui_option->ui()->btn_aplicar->setText(menu_option[1]);
               GLOBAL::WINDOW::_ui_option->ui()->btn_salvar->setText(menu_option[2]);
               GLOBAL::WINDOW::_ui_option->ui()->label_tema->setText(menu_option[3]);
          }
    }

