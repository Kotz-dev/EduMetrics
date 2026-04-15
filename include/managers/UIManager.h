#ifndef _UI__H
#define _UI__H

#include <ui_MainWindow.h>
#include <QDir>
#include "io/FileManager.h"

#include "PreferencesWindow.h"
#include "ui_option.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class Style;}
QT_END_NAMESPACE



std::string gets (std::string name);
std::string ts_();


#ifdef _WIN32
    static   std::filesystem::path ui_styles_ =  std::filesystem::current_path().remove_filename() / ui_styles;
    static   std::filesystem::path ui_styles_tabel_widget = std::filesystem::current_path().remove_filename() / ui_styles_tabel_widget__;
    static   std::filesystem::path window_dark = std::filesystem::current_path().remove_filename() /  window_dark___;
    static   std::filesystem::path window_light = std::filesystem::current_path().remove_filename() / window_light___;
    static   std::filesystem::path button_default = std::filesystem::current_path().remove_filename() /  button_default_;
    static   std::filesystem::path button_save = std::filesystem::current_path().remove_filename() / button_save_;
    static   std::filesystem::path _PreferencesWindow_ = std::filesystem::current_path().remove_filename() / PreferencesWindowStyles;
#endif

#ifdef __linux__
    static   std::filesystem::path ui_styles_ =  std::filesystem::current_path().remove_filename() / gets("ui_styles.qss");
    static   std::filesystem::path ui_styles_tabel_widget = std::filesystem::current_path().remove_filename() / gets("styles_tabel_widget.qss");
    static   std::filesystem::path window_dark = std::filesystem::current_path().remove_filename() /  gets("window_dark.qss");
    static   std::filesystem::path window_light = std::filesystem::current_path().remove_filename() / gets("window_branco.qss");
    static   std::filesystem::path button_default = std::filesystem::current_path().remove_filename() /  gets("button_default.qss");
    static   std::filesystem::path button_save = std::filesystem::current_path().remove_filename() / gets("button_save.qss");
    static   std::filesystem::path _PreferencesWindow_ = std::filesystem::current_path().remove_filename() / gets("PreferencesWindowStyles.qss");
#endif

const std::array<std::filesystem::path, 7> style_sheet_paths =
    {
    ui_styles_,
    ui_styles_tabel_widget,
    window_dark,
    window_light,
    button_default,
    button_save,
    _PreferencesWindow_
    };


namespace Style_Table {
        class Style {
        public :
            static void setRowResult(QTableWidget *table, int row, int status);
            static void clearCell(QTableWidget *table, int row, int column);
            Style();
    };

}
enum TYPE {
    MAIN_WINDOW = 0,
    PREFERENCE_SYSTEM = 1
};
class ui_controller {
public:
    static void applyTableStyle(Ui_MainWindow * ui);
    static void applyButtonStyles(TYPE windowType, Ui_MainWindow * ui);
    static void applyDarkTheme(Ui_MainWindow * ui, PreferencesWindow *Prefe);
    static void applyLightTheme(Ui_MainWindow * ui,PreferencesWindow *op);

    static void applyTheme();
    static void applyTheme(QString themeName);
};
struct UI_FONT {
    static void text(QString fonte,Ui::PreferencesWindow * ui,Ui_MainWindow *win);
    static void text(nlohmann::json json,Ui_MainWindow * ui);
    static void text(nlohmann::json json, Ui::PreferencesWindow * ui);
};


#endif //_UI__H
