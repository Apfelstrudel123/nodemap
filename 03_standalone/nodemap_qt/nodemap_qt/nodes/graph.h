#pragma once
#include <QWidget>
#include "ui_graph.h"
#include "node.h"

class Graph : public QWidget, public Ui::Graph
{
	Q_OBJECT

public:
	Graph(QWidget *parent = Q_NULLPTR);
	~Graph();

private:
	QList<Node> nodes;
};
