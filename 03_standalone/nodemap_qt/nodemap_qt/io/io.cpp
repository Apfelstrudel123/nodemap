#include "io.h"
#include <QJsonDocument>
#include <QFile>
#include <QFileDialog>
#include "console.h"

namespace IO
{
    ProjectData* open_project()
    {
        QString path = QFileDialog::getOpenFileName(nullptr, "Open Project", "", "Nodemap Project file (*.nmp)");
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
            UI::Console::write("Couldn't open project.");
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
        //Metadata
        project->path = read_string(json, "path");
        project->version = read_string(json, "version");
        //Body
        //TODO:  Read graphs, Read nodes
        return project;
    }

    QString read_string(const QJsonObject& json, const QString& key, const QString& def)
    {
        if (json.contains(key) && json[key].isString())
            return json[key].toString();
        return def;
    }

    bool save_project(ProjectData* project)
    {
        QString path = QFileDialog::getSaveFileName(nullptr, "Open Project", project->path, "Nodemap Project file (*.nmp)");
        if (path == "")
            return false;
        project->path = path;

        QJsonObject json;
        head_to_json(*project, &json);

        //TODO: Graphs to json
        //TODO: Nodes to json
        
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly)) 
        {
            UI::Console::write("Couldn't save project.", Qt::GlobalColor::red);
            return false;
        }
        
        file.write(QJsonDocument(json).toJson());
        return true;
    }

    void head_to_json(const ProjectData& project, QJsonObject* json)
    {
        json->insert("path", project.path);
        json->insert("version", project.version);
    }
}
