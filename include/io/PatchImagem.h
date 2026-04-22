//
// Created by KoTz on 20/04/2026.
//

#ifndef PUCSIMULATOR_PATCHIMAGEM_H
#define PUCSIMULATOR_PATCHIMAGEM_H
#include <filesystem>
#include <QPixmap>
#include <QString>


enum PATCH_TYPE_ {
     FILE_styles = 0,
     FILE_IMAGE = 1,
     FILE_IDIOMA_ = 2
 };


struct Convertefrom {
    std::filesystem::path path;
    std::unique_ptr<QPixmap> pixmap;
};

class PatchImagem {

public :
     static std::filesystem::path path_ (std::string name,PATCH_TYPE_ type);
     static QString FromStr(std::filesystem::path path);
     static void LoadImagen(QString path);
};



#endif //PUCSIMULATOR_PATCHIMAGEM_H
