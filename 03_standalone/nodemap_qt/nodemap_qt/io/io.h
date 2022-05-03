#pragma once
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace IO
{
    struct ProjectData;

    ProjectData* open_project();
    QJsonObject* read_project(const QString& path);
    ProjectData* read_data(const QJsonObject& json);
    void save_project(ProjectData* project);

    struct ProjectData
    {
        //Metadata
        QString name;
        QString version;
        QString path;
        //Body
        QString* users;
        //Nodes
    };
}
QT_END_NAMESPACE
