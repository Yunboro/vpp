#include "Serializer.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

#include <fstream>
#include <stdexcept>

void Serializer::writeToJson(const char *fname) const
{
    QJsonDocument doc(ik.toJson());
    QFile out_file(fname);

    if(!out_file.open(QFile::WriteOnly))
    {
        throw std::fstream::failure("Datei konnte nicht geoffnet werden!");
    }
    if(out_file.write(doc.toJson()) == -1)
    {
        throw std::fstream::failure("Datei konnte nicht beschrieben werden!");
    }
    out_file.close();
}
