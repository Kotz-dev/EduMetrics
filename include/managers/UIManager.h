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



QString gets (std::string name);

static std::filesystem::path ui_styles_          = std::filesystem::current_path().remove_filename() / "resources/styles/ui_styles.qss";
static std::filesystem::path ui_styles_tabel_widget = std::filesystem::current_path().remove_filename() / "resources/styles/styles_tabel_widget.qss";
static std::filesystem::path window_dark         = std::filesystem::current_path().remove_filename() / "resources/styles/window_dark.qss";
static std::filesystem::path window_light        = std::filesystem::current_path().remove_filename() / "resources/styles/window_branco.qss";
static std::filesystem::path button_default      = std::filesystem::current_path().remove_filename() / "resources/styles/button_default.qss";
static std::filesystem::path button_save         = std::filesystem::current_path().remove_filename() / "resources/styles/button_save.qss";
static std::filesystem::path _PreferencesWindow_ = std::filesystem::current_path().remove_filename() / "resources/styles/PreferencesWindowStyles.qss";

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
