#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <vector>

#include "Graph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_ver_btn_clicked();

    void on_del_ver_btn_clicked();

    void on_add_edge_btn_clicked();

    void on_del_edge_btn_clicked();

    void on_BFS_btn_clicked();

    void on_DFS_btn_clicked();

    void on_DA_btn_clicked();

    void on_example_graph_btn_clicked();

    void on_example_graph_btn_2_clicked();

private:
    Ui::MainWindow *ui;
    Graph G;
    vector<QString> VerNames;
    QGraphicsScene* CreateScene();
};
#endif // MAINWINDOW_H
