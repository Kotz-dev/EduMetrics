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


#ifdef _WIN32
    static   std::filesystem::path ui_styles_ =  std::filesystem::current_path().remove_filename() / "resources/styles/ui_styles.qss";
    static   std::filesystem::path ui_styles_tabel_widget = std::filesystem::current_path().remove_filename() / "resources/styles/styles_tabel_widget.qss";
    static   std::filesystem::path window_dark =std::filesystem::current_path().remove_filename() / "resources/styles/window_dark.qss";
    static   std::filesystem::path window_light =std::filesystem::current_path().remove_filename() / "resources/styles/window_branco.qss";
#endif


#ifdef __linux__
    // static   std::filesystem::path ui_styles_ =  std::filesystem::current_path().remove_filename() / "styles\\ui_styles.qss";
    // static   QString ui_styles__;
    // static   QString ui_styles_tabel_widget;
    // static   QString window_light;
#endif




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
    static void applyDarkTheme(Ui_MainWindow * ui);
    static void applyLightTheme(Ui_MainWindow * ui, Ui::PreferencesWindow *op);

    static void applyTheme();
    static void applyTheme(QString themeName);
};
struct UI_FONT {
    static void text(QString fonte,Ui::PreferencesWindow * ui,Ui_MainWindow *win);
    static void text(nlohmann::json json,Ui_MainWindow * ui);
    static void text(nlohmann::json json, Ui::PreferencesWindow * ui);
};


#endif //_UI__H
