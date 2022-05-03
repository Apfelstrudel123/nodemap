#include "io.h"

namespace IO
{
    ProjectData* open_project()
    {
        //TODO: File Explorer
        QString path = QFileDialog::getOpenFileName();
        QJsonObject* json = read_project(path);
        if (json)
            return read_data(*json);
        return nullptr;
    }

    QJsonObject* read_project(const QString& path)
    {
        QFile load_file(path);

        if (!load_file.open(QIODevice::ReadOnly))
        {
            qWarning("Couldn't open save file.");
            return nullptr;
        }

        QByteArray data = load_file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(data));

        QJsonObject* json = new QJsonObject();
        *json = doc.object();
        return json;
    }
    ProjectData* read_data(const QJsonObject& json)
    {
        ProjectData* project = new ProjectData();
        if (json.contains("name") && json["name"].isString())
            project->name = json["name"].toString();
        return project;
    }
    void save_project(ProjectData* project)
    {

    }
}
