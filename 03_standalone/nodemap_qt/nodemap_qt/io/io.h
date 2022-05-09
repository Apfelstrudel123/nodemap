#pragma once
#include <QJsonObject>
#include "../nodes/graph.h"

namespace IO
{
    struct ProjectData
    {
        //Metadata
        QString version = "0.0.1";
        QString path = "untitled.nmp";
        //Body
        QString users = "none";
        //Nodes

        QList<Graph> graphs;
    };

    ProjectData* open_project();
    QJsonObject* read_project(const QString& path);
    ProjectData* read_data(const QJsonObject& json);
    QString read_string(const QJsonObject& json, const QString& key, const QString& def = QStringLiteral(""));
    bool save_project(ProjectData* project);

    void head_to_json(const ProjectData& project, QJsonObject* obj);
}
