//
// Created by KoTz on 23/10/2025.
//

#ifndef LANGUAGE_MANAGER_H
#define LANGUAGE_MANAGER_H


#include <ui_MainWindow.h>
#include <nlohmann/json.hpp>
#include <ui_option.h>


enum TYPE_IDIOMA{
    IDIOMA_WINDOWS = 0,
    IDIOMA_OPTION = 1,
    IDIOMA_ALL    = 2
};


class LanguageUI {
public :
    LanguageUI();
    static void initialize(nlohmann::json & config, Ui::MainWindow * mainWindowUi, QString & currentLanguage);
    static void applyLanguage(QString & languageKey);
    static nlohmann::json getTranslation(QString languageKey, QString textKey);
    static int getLanguageIndex(QString languageKey);
};


#endif //LANGUAGE_MANAGER_H