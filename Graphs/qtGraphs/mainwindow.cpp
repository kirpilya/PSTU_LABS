#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <cmath>
#include <string>
#include <sstream>

#include "Graph.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QGraphicsScene* MainWindow::CreateScene()
{
    int R = 200;
    int ell_r = 50;
    double pi = 3.14;

    QGraphicsScene* new_Scene = new QGraphicsScene;

    //ОТРИСОВКА РЁБЕР
    int ver_c = 0;
    for(auto ver : G.Smatr)
    {
        double angle_s = ((2 * pi) / G.Smatr.size()) * (ver_c);
        for(unsigned int j = 0; j < ver.size(); j++)
        {
            if(ver[j])
            {
                double angle_f = ((2 * pi) / G.Smatr.size()) * j;
                QGraphicsLineItem *edge = new_Scene->addLine(R*std::cos(angle_s), R*std::sin(angle_s), R*std::cos(angle_f), R*std::sin(angle_f));
                QPen PenEdge(Qt::black);
                edge->setPen(PenEdge);
            }
        }
        ver_c += 1;
    }

    //ОТРИСОВКА ВЕСОВ РЁБЕР
    ver_c = 0;
    for(auto ver : G.Smatr)
    {
        double angle_s = ((2 * pi) / G.Smatr.size()) * (ver_c);
        for(unsigned int j = 0; j < ver.size(); j++)
        {
            if(ver[j])
            {
                double angle_f = ((2 * pi) / G.Smatr.size()) * j;
                QGraphicsTextItem *text = new_Scene->addText(QString::number(ver[j]));
                text->setDefaultTextColor(Qt::black);
                text->setHtml(QString("<div style='background:rgba(255, 255, 255, 100%);'>" + QString::number(ver[j]) + QString("</div>")));
                text->setFont(QFont("Arial", 12));
                QPointF textPos = QPointF(R*std::cos(angle_s) + (R*std::cos(angle_f) -  R*std::cos(angle_s)) / 2 - 3, R*std::sin(angle_s) + (R*std::sin(angle_f) -  R*std::sin(angle_s)) / 2);
                text->setPos(textPos);
            }
        }
        ver_c += 1;
    }

    //ОТРИСОВКА ВЕРШИН
    for(unsigned int i = 0; i < G.Smatr.size(); i++)
    {
        double angle = ((2 * pi) / G.Smatr.size()) * i;
        QGraphicsEllipseItem *ELL = new_Scene->addEllipse(R*std::cos(angle) - ell_r/2, R*std::sin(angle) - ell_r/2, ell_r, ell_r);
        QPen penELL(Qt::black);
        QBrush brushELL(Qt::red);
        ELL->setPen(penELL);
        ELL->setBrush(brushELL);

        QGraphicsTextItem *text = new_Scene->addText(/*QString::number(i+1)*/ VerNames[i]);
        text->setDefaultTextColor(Qt::black);
        text->setFont(QFont("Arial", 14));
        text->setPos(R*std::cos(angle)-10, R*std::sin(angle)-14);
    }

    return new_Scene;
}

void MainWindow::on_add_ver_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString VerName = ui->add_ver_vername_textEdit->toPlainText();
    if(VerName == "")
    {
        ui->add_ver_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_ver_status_label->setText("не задано имя вершины");
        return;
    }
    VerNames.push_back(VerName);
    ui->add_ver_vername_textEdit->setText("");

    stringstream ss(ui->add_ver_textEdit->toPlainText().toStdString());
    ui->add_ver_textEdit->setText("");
    vector<int> vers; int a;
    while (ss >> a) {vers.push_back(a);}
    if(vers.size() == 0)
    {
        for(int i = 0; i < G.Smatr.size(); i++)
        {
            vers.push_back(0);
        }
    }
    if(vers.size() != G.Smatr.size())
    {
        ui->add_ver_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_ver_status_label->setText("неверное кол-во рёбер");
        return;
    }

    for (unsigned int i = 0; i < G.Smatr.size(); i++)
    {
        G.Smatr[i].push_back(vers[i]);
    }
    vers.push_back(0);
    G.Smatr.push_back(vers);

    ui->add_ver_status_label->setStyleSheet("QLabel {color : black;}");
    ui->add_ver_status_label->setText(QString("Вершин: ") + QString::number(G.Smatr.size()));

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_del_ver_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    /*
    stringstream ss(ui->del_ver_textEdit->toPlainText().toStdString());
    ui->del_ver_textEdit->setText("");
    vector<int> vers; int a;
    while (ss >> a) {vers.push_back(a);}
    if(vers.size() != 1 || vers[0] > G.Smatr.size() || vers[0] < 1)
    {
        ui->del_ver_status_label->setStyleSheet("QLabel {color : red;}");
        ui->del_ver_status_label->setText("неверный номер вершины");
        return;
    }
    */

    QString VerName = ui->del_ver_textEdit->toPlainText();
    ui->del_ver_textEdit->setText("");

    if(VerName == "")
    {
        ui->del_ver_status_label->setStyleSheet("QLabel {color : red;}");
        ui->del_ver_status_label->setText("не задана вершина");
        return;
    }
    bool flag = false; int index = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(VerName == VerNames[i])
        {
            flag = true; index = i;
        }
    }

    if(flag)
    {
        for (unsigned int i = 0; i < G.Smatr.size(); i++)
        {
            auto it = G.Smatr[i].begin();
            advance(it, index);
            G.Smatr[i].erase(it);
        }
        auto it = G.Smatr.begin();
        advance(it, index);
        G.Smatr.erase(it);

        auto it_vn = VerNames.begin();
        advance(it_vn, index);
        VerNames.erase(it_vn);
    }
    else
    {
        ui->del_ver_status_label->setStyleSheet("QLabel {color : red;}");
        ui->del_ver_status_label->setText("неверный номер вершины");
        return;
    }

    ui->del_ver_status_label->setStyleSheet("QLabel {color : black;}");
    ui->del_ver_status_label->setText("");
    ui->add_ver_status_label->setText(QString("Вершин: ") + QString::number(G.Smatr.size()));

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_add_edge_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString from = ui->add_edge_f_textEdit->toPlainText();
    QString to = ui->add_edge_s_textEdit->toPlainText();
    QString ves = ui->add_edge_ves_textEdit->toPlainText();

    if(from == "" || to == "")
    {
        ui->add_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_edge_status_label->setText("неверные вершины");

        ui->add_edge_f_textEdit->setText("");
        ui->add_edge_s_textEdit->setText("");
        ui->add_edge_ves_textEdit->setText("");

        return;
    }
    if(from == to)
    {
        ui->add_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_edge_status_label->setText("неподходящее ребро");

        ui->add_edge_f_textEdit->setText("");
        ui->add_edge_s_textEdit->setText("");
        ui->add_edge_ves_textEdit->setText("");

        return;
    }
    if(ves == "")
    {
        ui->add_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_edge_status_label->setText("не задан вес ребра");

        ui->add_edge_f_textEdit->setText("");
        ui->add_edge_s_textEdit->setText("");
        ui->add_edge_ves_textEdit->setText("");

        return;
    }

    bool flag_f = false; bool flag_s = false; int index_f = -1; int index_s = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(from == VerNames[i])
        {
            flag_f = true; index_f = i;
        }
        else if(to == VerNames[i])
        {
            flag_s = true; index_s = i;
        }

    }

    if(flag_f && flag_s)
    {
        G.Smatr[index_f][index_s] = ves.toInt();
        G.Smatr[index_s][index_f] = ves.toInt();
    }
    else
    {
        ui->add_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->add_edge_status_label->setText("неверные вешины");
        ui->add_edge_f_textEdit->setText("");
        ui->add_edge_s_textEdit->setText("");
        ui->add_edge_ves_textEdit->setText("");

        return;
    }

    ui->add_edge_f_textEdit->setText("");
    ui->add_edge_s_textEdit->setText("");
    ui->add_edge_ves_textEdit->setText("");
    ui->add_edge_status_label->setStyleSheet("QLabel {color : black;}");
    ui->add_edge_status_label->setText("");


    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_del_edge_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString from = ui->del_edge_f_textEdit->toPlainText();
    QString to = ui->del_edge_s_textEdit->toPlainText();

    if(from == "" || to == "")
    {
        ui->del_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->del_edge_status_label->setText("неверные вершины");

        ui->del_edge_f_textEdit->setText("");
        ui->del_edge_s_textEdit->setText("");

        return;
    }
    if(from == to)
    {
        ui->del_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->del_edge_status_label->setText("неподходящее ребро");

        ui->del_edge_f_textEdit->setText("");
        ui->del_edge_s_textEdit->setText("");

        return;
    }

    bool flag_f = false; bool flag_s = false; int index_f = -1; int index_s = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(from == VerNames[i])
        {
            flag_f = true; index_f = i;
        }
        else if(to == VerNames[i])
        {
            flag_s = true; index_s = i;
        }

    }

    if(flag_f && flag_s)
    {
        G.Smatr[index_f][index_s] = 0;
        G.Smatr[index_s][index_f] = 0;
    }
    else
    {
        ui->del_edge_status_label->setStyleSheet("QLabel {color : red;}");
        ui->del_edge_status_label->setText("неверные вешины");
        return;
    }

    ui->del_edge_f_textEdit->setText("");
    ui->del_edge_s_textEdit->setText("");
    ui->del_edge_status_label->setStyleSheet("QLabel {color : black;}");
    ui->del_edge_status_label->setText("");

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_BFS_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString start_ver = ui->BFS_textEdit->toPlainText();

    if(start_ver== "")
    {
        ui->BFS_status_label->setStyleSheet("QLabel {color : red;}");
        ui->BFS_status_label->setText("неверная вершина");
        ui->BFS_textEdit->setText("");
        ui->BFS_result_textBrowser->setText("");

        ui->BFS_textEdit->setText("");

        return;
    }

    bool flag = false; int index = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(start_ver == VerNames[i])
        {
            flag = true; index = i;
        }

    }

    if(flag)
    {
        QString RESULT = "";

        // ОБХОД В ШИРИНУ
        vector<bool> visited(G.Smatr.size(), false);
        queue<int> q;

        visited[index] = true;
        q.push(index);

        while(!q.empty())
        {
            int curVer = q.front();
            q.pop();

            RESULT += VerNames[curVer];
            RESULT += " ";

            for(int neighbor = 0; neighbor < G.Smatr.size(); neighbor++)
            {
                if(G.Smatr[curVer][neighbor] != 0 && !visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        ui->BFS_result_textBrowser->setText(RESULT);

    }
    else
    {
        ui->BFS_status_label->setStyleSheet("QLabel {color : red;}");
        ui->BFS_status_label->setText("неверная вешина");
        ui->BFS_textEdit->setText("");
        ui->BFS_result_textBrowser->setText("");

        return;
    }

    ui->BFS_textEdit->setText("");
    ui->BFS_status_label->setStyleSheet("QLabel {color : black;}");
    ui->BFS_status_label->setText("");

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_DFS_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString start_ver = ui->DFS_textEdit->toPlainText();

    if(start_ver== "")
    {
        ui->DFS_status_label->setStyleSheet("QLabel {color : red;}");
        ui->DFS_status_label->setText("неверная вершина");
        ui->DFS_textEdit->setText("");
        ui->DFS_result_textBrowser->setText("");

        ui->DFS_textEdit->setText("");

        return;
    }

    bool flag = false; int index = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(start_ver == VerNames[i])
        {
            flag = true; index = i;
        }

    }

    if(flag)
    {
        QString RESULT = "";

        // ОБХОД В ШИРИНУ
        vector<bool> visited(G.Smatr.size(), false);
        stack<int> s;

        visited[index];
        s.push(index);

        while(!s.empty())
        {
            int curVer = s.top();
            s.pop();

            if(!visited[curVer])
            {
                visited[curVer] = true;
                RESULT += VerNames[curVer];
                RESULT += " ";

                for(int neighbor = 0; neighbor < G.Smatr.size(); neighbor++)
                {
                    if(G.Smatr[curVer][neighbor] != 0 && !visited[neighbor])
                    {
                        s.push(neighbor);
                    }
                }
            }
        }

        ui->DFS_result_textBrowser->setText(RESULT);

    }
    else
    {
        ui->DFS_status_label->setStyleSheet("QLabel {color : red;}");
        ui->DFS_status_label->setText("неверная вешина");
        ui->DFS_textEdit->setText("");
        ui->DFS_result_textBrowser->setText("");

        return;
    }

    ui->DFS_textEdit->setText("");
    ui->DFS_status_label->setStyleSheet("QLabel {color : black;}");
    ui->DFS_status_label->setText("");

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_DA_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    QString start_ver = ui->DA_textEdit->toPlainText();

    if(start_ver== "")
    {
        ui->DA_status_label->setStyleSheet("QLabel {color : red;}");
        ui->DA_status_label->setText("неверная вершина");
        ui->DA_textEdit->setText("");
        ui->DA_result_textBrowser->setText("");

        ui->DA_textEdit->setText("");

        return;
    }

    bool flag = false; int index = -1;
    for(unsigned int i = 0; i < VerNames.size(); i++)
    {
        if(start_ver == VerNames[i])
        {
            flag = true; index = i;
        }

    }

    if(flag)
    {
        // АЛГОРИТМ ДЕЙКСТРЫ
        int numVertices = G.Smatr.size();
        vector<bool> visited(numVertices, false);
        vector<int> distances;
        distances.resize(numVertices, std::numeric_limits<int>::max());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distances[index] = 0;
        pq.push(make_pair(0, index));

        while(!pq.empty())
        {
            int currentVertex = pq.top().second;
            pq.pop();

            // ?
            if (visited[currentVertex])
            {
                continue;
            }

            visited[currentVertex] = true;

            for (int neighbor = 0; neighbor < numVertices; ++neighbor)
            {
                int weight = G.Smatr[currentVertex][neighbor];

                if (weight > 0)
                {
                    int distance = distances[currentVertex] + weight;

                    if (distance < distances[neighbor])
                    {
                        distances[neighbor] = distance;
                        pq.push(make_pair(distance, neighbor));
                    }
                }
            }
        }

        QString RESULT = "";
        for(int i = 0; i < numVertices; i++)
        {
            if(distances[i] == numeric_limits<int>::max())
            {
                RESULT += VerNames[i]; RESULT += ":"; RESULT += " inf"; RESULT += " ";
            }
            else
            {
                RESULT += VerNames[i]; RESULT += ": "; RESULT += QString::number(distances[i]); RESULT += " ";
            }
        }
        ui->DA_result_textBrowser->setText(RESULT);

    }
    else
    {
        ui->DA_status_label->setStyleSheet("QLabel {color : red;}");
        ui->DA_status_label->setText("неверная вешина");
        ui->DA_textEdit->setText("");
        ui->DA_result_textBrowser->setText("");

        return;
    }

    ui->DA_textEdit->setText("");
    ui->DA_status_label->setStyleSheet("QLabel {color : black;}");
    ui->DA_status_label->setText("");

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_example_graph_btn_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    G.Smatr.clear();
    VerNames.clear();

    G.Smatr = { {0, 3, 0, 10, 0, 0}, {3, 0, 7, 0, 0, 0}, {0, 7, 0, 1, 1, 0}, {10, 0, 1, 0, 0, 5}, {0, 0, 1, 0, 0, 8}, {0, 0, 0, 5, 8, 0} };
    VerNames = {"A", "B", "C", "D", "E", "F"};

    ui->add_ver_status_label->setText(QString("Вершин: ") + QString::number(G.Smatr.size()));

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}


void MainWindow::on_example_graph_btn_2_clicked()
{
    QGraphicsScene *prev_scene = ui->graphicsView->scene();

    G.Smatr.clear();
    VerNames.clear();
    ui->add_ver_status_label->setText(QString("Вершин: ") + QString::number(G.Smatr.size()));

    QGraphicsScene *new_Scene = CreateScene();
    ui->graphicsView->setScene(new_Scene);

    if(prev_scene) delete prev_scene;
}

//xcpskg
