//
// Created by KoTz on 30/06/2025.
//

#include "managers/UIManager.h"

#include "GlobalAccess.h"
#include "JsonParser.h"

Style_Table::Style::Style() {
}

std::string ts_ () {
    if (getOperatingSystem() == 1) {
        return "//";
    }
    if (getOperatingSystem() == -1) {
        return "\\";
    }
    return "";
}

std::string gets (std::string name ) {
    bool windows_ = false;
    bool linux_ = false;

    if (getOperatingSystem() == 1) {
        linux_ = true;
        windows_ = false;
    }
    if (getOperatingSystem() == -1) {
        windows_ = true;
        linux_ = false;
    }
    std::array<std::string, 7> style_sheet_paths_ =  {
        "resources//styles//ui_styles.qss", // 0
         "resources//styles//styles_tabel_widget.qss", // 1
         "resources//styles//window_dark.qss", // 2
         "resources//styles//window_branco.qss", // 3
         "resources//styles//button_default.qss", // 4
         "resources//styles//button_save.qss",  // 5
         "resources//styles//PreferencesWindowStyles.qss" // 6
     };

    for (auto & path : style_sheet_paths_) {
        if (path.find(name) != std::string::npos) {
            if (windows_) {
                std::ranges::replace(path,'//','\\');
                return path;
            }
            if (linux_) {
                std::ranges::replace(path,'\\','//');
                return path;
            }
        }
    }
    return "";
}

void Style_Table::Style::setRowResult(QTableWidget *table, int row, int status) {
     if (table != nullptr) {
         if (status == 0) {
             table->item(row,7)->setText("Reprovado por falta");
             table->item(row,7)->setBackground(QColor(Qt::red));
         }

         if (status == 1) {
             table->item(row,7)->setText("Aprovado");
             table->item(row,7)->setBackground(QColor(Qt::darkGreen));

         }

         if (status == 2) {
             table->item(row,7)->setText("Reprovado");
             table->item(row,7)->setBackground(QColor(Qt::red));
         }
     }

    return;
}
void Style_Table::Style::clearCell(QTableWidget *table, int row, int column) {
    table->item(row,column)->setText("");
    table->item(row, column)->setBackground(QColor::fromRgb(44,44,44,44));
}

void ui_controller::applyTheme(QString themeName) {

    if (themeName == "Claro") {
        applyLightTheme(GLOBAL::WINDOW::UI,GLOBAL::WINDOW::_ui_option);
    }
    if (themeName == "Escuro") {
        applyDarkTheme(GLOBAL::WINDOW::UI,GLOBAL::WINDOW::_ui_option);
    }
}

void ui_controller::applyTheme() {
    if ((JsonParser::readJsonKey(GLOBAL::FILE_PATHS::CONFIG,"tema") == "Claro")) {
       applyLightTheme(GLOBAL::WINDOW::UI,GLOBAL::WINDOW::_ui_option);
    }
    if ((JsonParser::readJsonKey(GLOBAL::FILE_PATHS::CONFIG,"tema") == "Escuro")) {
        applyDarkTheme(GLOBAL::WINDOW::UI,GLOBAL::WINDOW::_ui_option);
    }
}

QByteArray findw (QString name) {
    for (auto & i : style_sheet_paths ) {

        if (QString(QUrl(QString::fromStdString(i.string())).fileName()).contains(name) == true) {
            QFile file(i);
             if (file.open(QFile::ReadOnly)){}
            return file.readAll();
        }
    }
    return "";
}

void ui_controller::applyLightTheme(Ui_MainWindow *ui,PreferencesWindow *op) {
    bool get = op != nullptr;
    qDebug () << gets("button_default.qss");
    if (ui != nullptr && op != nullptr) {
           op->setStyleSheet(findw(QString::fromStdString(gets("PreferencesWindowStyles.qss"))));
           op->ui()->btn_salvar->setStyleSheet(findw(QString::fromStdString(gets("button_save.qss"))));
           op->ui()->btn_aplicar->setStyleSheet(findw(QString::fromStdString(gets("button_default.qss"))));
          op->ui()->btn_search_paste->setStyleSheet(findw(QString::fromStdString(gets("button_default.qss"))));
    }
}
void ui_controller::applyTableStyle(Ui_MainWindow *ui) {
    QFile filew(ui_styles_tabel_widget);
    if (ui != nullptr) {
        filew.open(QFile::ReadOnly);
        QString styleSheet = filew.readAll();
        ui->tableWidget->setStyleSheet(styleSheet);
    }
}

void ui_controller::applyDarkTheme(Ui_MainWindow *ui,PreferencesWindow *Prefe) {

    QFile filew(window_dark);
    if (ui != nullptr && Prefe != nullptr) {
        if (filew.open(QFile::ReadOnly)) {}
        QString styleSheet = filew.readAll();
        ui->menuBar->setStyleSheet("");
        ui->frame->setStyleSheet("");
        ui->centralwidget->setStyleSheet("");
    }
}

void ui_controller::applyButtonStyles(TYPE TY,Ui_MainWindow * ui) {
    QFile filew(ui_styles_);


   if (TY == TYPE::MAIN_WINDOW) {
       if (filew.open(QFile::ReadOnly)) {
           QString styleSheet = filew.readAll();
           ui->logo->setStyleSheet(styleSheet);
           ui->btn_add->setStyleSheet(styleSheet);
           ui->btn_remover->setStyleSheet(styleSheet);
           filew.close();
       } else {
           qDebug() << "Erro ao abrir o arquivo de estilo:" << filew.errorString();
       }
   }
}
void UI_FONT::text(QString fonte,Ui::PreferencesWindow * ui,Ui_MainWindow *win) {
     if (ui == nullptr) {
         return;
     }
    ui->label_tema->setFont(QFont(fonte));
    ui->label_fonte->setFont(QFont(fonte));
    ui->comboBox->setFont(QFont(fonte));
    ui->fontComboBox->setFont(QFont(fonte));
    ui->Combox_tema->setFont(QFont(fonte));
    ui->lineEdit->setFont(QFont(fonte));
    ui->btn_search_paste->setFont(QFont(fonte));
    ui->btn_aplicar->setFont(QFont(fonte));
    ui->btn_salvar->setFont(QFont(fonte));
    ui->label->setFont(QFont(fonte));

    win->menuArquivos->setFont(QFont(fonte));
    win->menuFerramentas->setFont(QFont(fonte));
    win->tableWidget->setFont(QFont(fonte));

    for (int a =0; a < win->tableWidget->columnCount();a++) {
        for (int b = 0; b < win->tableWidget->rowCount();b++) {
            win->tableWidget->item(b,a)->setFont(QFont(fonte));
        }
        win->tableWidget->horizontalHeaderItem(a)->setFont(QFont(fonte));
    }
   win->label->setFont(QFont(fonte));
}

void UI_FONT::text(nlohmann::json json, Ui::PreferencesWindow *ui) {
    if (ui != nullptr) {
        auto get = json["Fonte"];
        ui->label_tema->setFont(QString::fromStdString(get).remove("\\"));
        ui->label_fonte->setFont(QString::fromStdString(get).remove("\\"));
        ui->comboBox->setFont(QString::fromStdString(get).remove("\\"));
        ui->fontComboBox->setFont(QString::fromStdString(get).remove("\\"));
        ui->Combox_tema->setFont(QString::fromStdString(get).remove("\\"));
        ui->lineEdit->setFont(QString::fromStdString(get).remove("\\"));
        ui->btn_search_paste->setFont(QString::fromStdString(get).remove("\\"));
        ui->btn_aplicar->setFont(QString::fromStdString(get).remove("\\"));
        ui->btn_salvar->setFont(QString::fromStdString(get).remove("\\"));
        ui->label->setFont(QString::fromStdString(get).remove("\\"));
    }
}
 void UI_FONT::text(nlohmann::json json,Ui_MainWindow * ui) {
    if (ui != nullptr) {
        auto get = json["Fonte"];
        ui->menuArquivos->setFont(QFont(QString::fromStdString(get).remove("\\")));
        ui->menuFerramentas->setFont(QFont(QString::fromStdString(get).remove("\\")));
        ui->tableWidget->setFont(QFont(QString::fromStdString(get).remove("\\")));
        for (int a =0; a < ui->tableWidget->columnCount();a++) {
            ui->tableWidget->horizontalHeaderItem(a)->setFont(QString::fromStdString(get).remove("\\"));
        }
    }
}

