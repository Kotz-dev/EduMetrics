//
// Created by KoTz on 24/10/2025.
//

#include "utils/GlobalAccess.h"


namespace GLOBAL {
    QString idioma;
    bool is_aplica;
    bool is_close_window_option;
    namespace WINDOW {
        Ui::MainWindow * UI;
        Ui::PreferencesWindow    *_ui_option;
    }
    nlohmann::json json;
    void init_global(Ui::MainWindow * windows) {
        if (windows != nullptr) {
            WINDOW::UI = windows;
        }
    }
    void init_global( Ui::PreferencesWindow * option) {
        if (option != nullptr) {
            WINDOW::_ui_option = option;
        }
    }
}
