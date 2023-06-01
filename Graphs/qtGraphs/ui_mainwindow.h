/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *add_ver_btn;
    QTextEdit *add_ver_textEdit;
    QLabel *add_ver_status_label;
    QLabel *add_ver_name_label;
    QLabel *add_ver_info_label;
    QLabel *dell_ver_info_label;
    QLabel *del_ver_status_label;
    QLabel *del_ver_name_label;
    QPushButton *del_ver_btn;
    QTextEdit *del_ver_textEdit;
    QTextEdit *add_ver_vername_textEdit;
    QLabel *add_edge_name_label;
    QLabel *add_edge_f_label;
    QTextEdit *add_edge_f_textEdit;
    QTextEdit *add_edge_s_textEdit;
    QLabel *add_edge_s_label;
    QTextEdit *add_edge_ves_textEdit;
    QLabel *add_edge_ves_label;
    QPushButton *add_edge_btn;
    QLabel *add_edge_status_label;
    QLabel *del_edge_name_label;
    QTextEdit *del_edge_f_textEdit;
    QPushButton *del_edge_btn;
    QLabel *del_edge_f_label;
    QTextEdit *del_edge_s_textEdit;
    QLabel *del_edge_s_label;
    QLabel *del_edge_status_label;
    QLabel *BFS_name_label;
    QLabel *BFS_info_label;
    QTextEdit *BFS_textEdit;
    QPushButton *BFS_btn;
    QTextBrowser *BFS_result_textBrowser;
    QLabel *BFS_status_label;
    QTextEdit *DFS_textEdit;
    QLabel *DFS_info_label;
    QLabel *DFS_status_label;
    QLabel *DFS_name_label;
    QTextBrowser *DFS_result_textBrowser;
    QPushButton *DFS_btn;
    QPushButton *DA_btn;
    QLabel *DA_name_label;
    QTextEdit *DA_textEdit;
    QLabel *DA_info_label;
    QLabel *DA_status_label;
    QTextBrowser *DA_result_textBrowser;
    QPushButton *example_graph_btn;
    QPushButton *example_graph_btn_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1160, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1160, 700));
        MainWindow->setMaximumSize(QSize(1160, 700));
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(460, 20, 680, 660));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        add_ver_btn = new QPushButton(centralwidget);
        add_ver_btn->setObjectName(QString::fromUtf8("add_ver_btn"));
        add_ver_btn->setGeometry(QRect(220, 60, 30, 30));
        add_ver_textEdit = new QTextEdit(centralwidget);
        add_ver_textEdit->setObjectName(QString::fromUtf8("add_ver_textEdit"));
        add_ver_textEdit->setGeometry(QRect(70, 60, 140, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        add_ver_textEdit->setFont(font);
        add_ver_status_label = new QLabel(centralwidget);
        add_ver_status_label->setObjectName(QString::fromUtf8("add_ver_status_label"));
        add_ver_status_label->setGeometry(QRect(260, 60, 170, 30));
        add_ver_status_label->setFont(font);
        add_ver_name_label = new QLabel(centralwidget);
        add_ver_name_label->setObjectName(QString::fromUtf8("add_ver_name_label"));
        add_ver_name_label->setGeometry(QRect(20, 15, 145, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        add_ver_name_label->setFont(font1);
        add_ver_info_label = new QLabel(centralwidget);
        add_ver_info_label->setObjectName(QString::fromUtf8("add_ver_info_label"));
        add_ver_info_label->setGeometry(QRect(20, 35, 431, 21));
        add_ver_info_label->setFont(font);
        dell_ver_info_label = new QLabel(centralwidget);
        dell_ver_info_label->setObjectName(QString::fromUtf8("dell_ver_info_label"));
        dell_ver_info_label->setGeometry(QRect(20, 120, 365, 21));
        dell_ver_info_label->setFont(font);
        del_ver_status_label = new QLabel(centralwidget);
        del_ver_status_label->setObjectName(QString::fromUtf8("del_ver_status_label"));
        del_ver_status_label->setGeometry(QRect(210, 145, 170, 30));
        del_ver_status_label->setFont(font);
        del_ver_name_label = new QLabel(centralwidget);
        del_ver_name_label->setObjectName(QString::fromUtf8("del_ver_name_label"));
        del_ver_name_label->setGeometry(QRect(20, 100, 145, 20));
        del_ver_name_label->setFont(font1);
        del_ver_btn = new QPushButton(centralwidget);
        del_ver_btn->setObjectName(QString::fromUtf8("del_ver_btn"));
        del_ver_btn->setGeometry(QRect(170, 145, 30, 30));
        del_ver_textEdit = new QTextEdit(centralwidget);
        del_ver_textEdit->setObjectName(QString::fromUtf8("del_ver_textEdit"));
        del_ver_textEdit->setGeometry(QRect(20, 145, 140, 30));
        del_ver_textEdit->setFont(font);
        add_ver_vername_textEdit = new QTextEdit(centralwidget);
        add_ver_vername_textEdit->setObjectName(QString::fromUtf8("add_ver_vername_textEdit"));
        add_ver_vername_textEdit->setGeometry(QRect(20, 60, 40, 30));
        add_ver_vername_textEdit->setFont(font);
        add_edge_name_label = new QLabel(centralwidget);
        add_edge_name_label->setObjectName(QString::fromUtf8("add_edge_name_label"));
        add_edge_name_label->setGeometry(QRect(20, 185, 220, 20));
        add_edge_name_label->setFont(font1);
        add_edge_f_label = new QLabel(centralwidget);
        add_edge_f_label->setObjectName(QString::fromUtf8("add_edge_f_label"));
        add_edge_f_label->setGeometry(QRect(20, 210, 20, 30));
        add_edge_f_label->setFont(font);
        add_edge_f_textEdit = new QTextEdit(centralwidget);
        add_edge_f_textEdit->setObjectName(QString::fromUtf8("add_edge_f_textEdit"));
        add_edge_f_textEdit->setGeometry(QRect(50, 210, 40, 30));
        add_edge_f_textEdit->setFont(font);
        add_edge_s_textEdit = new QTextEdit(centralwidget);
        add_edge_s_textEdit->setObjectName(QString::fromUtf8("add_edge_s_textEdit"));
        add_edge_s_textEdit->setGeometry(QRect(120, 210, 40, 30));
        add_edge_s_textEdit->setFont(font);
        add_edge_s_label = new QLabel(centralwidget);
        add_edge_s_label->setObjectName(QString::fromUtf8("add_edge_s_label"));
        add_edge_s_label->setGeometry(QRect(100, 210, 10, 30));
        add_edge_s_label->setFont(font);
        add_edge_ves_textEdit = new QTextEdit(centralwidget);
        add_edge_ves_textEdit->setObjectName(QString::fromUtf8("add_edge_ves_textEdit"));
        add_edge_ves_textEdit->setGeometry(QRect(205, 210, 40, 30));
        add_edge_ves_textEdit->setFont(font);
        add_edge_ves_label = new QLabel(centralwidget);
        add_edge_ves_label->setObjectName(QString::fromUtf8("add_edge_ves_label"));
        add_edge_ves_label->setGeometry(QRect(170, 210, 25, 30));
        add_edge_ves_label->setFont(font);
        add_edge_btn = new QPushButton(centralwidget);
        add_edge_btn->setObjectName(QString::fromUtf8("add_edge_btn"));
        add_edge_btn->setGeometry(QRect(260, 210, 30, 30));
        add_edge_status_label = new QLabel(centralwidget);
        add_edge_status_label->setObjectName(QString::fromUtf8("add_edge_status_label"));
        add_edge_status_label->setGeometry(QRect(300, 210, 150, 30));
        add_edge_status_label->setFont(font);
        del_edge_name_label = new QLabel(centralwidget);
        del_edge_name_label->setObjectName(QString::fromUtf8("del_edge_name_label"));
        del_edge_name_label->setGeometry(QRect(20, 255, 220, 20));
        del_edge_name_label->setFont(font1);
        del_edge_f_textEdit = new QTextEdit(centralwidget);
        del_edge_f_textEdit->setObjectName(QString::fromUtf8("del_edge_f_textEdit"));
        del_edge_f_textEdit->setGeometry(QRect(50, 280, 40, 30));
        del_edge_f_textEdit->setFont(font);
        del_edge_btn = new QPushButton(centralwidget);
        del_edge_btn->setObjectName(QString::fromUtf8("del_edge_btn"));
        del_edge_btn->setGeometry(QRect(175, 280, 30, 30));
        del_edge_f_label = new QLabel(centralwidget);
        del_edge_f_label->setObjectName(QString::fromUtf8("del_edge_f_label"));
        del_edge_f_label->setGeometry(QRect(20, 280, 20, 30));
        del_edge_f_label->setFont(font);
        del_edge_s_textEdit = new QTextEdit(centralwidget);
        del_edge_s_textEdit->setObjectName(QString::fromUtf8("del_edge_s_textEdit"));
        del_edge_s_textEdit->setGeometry(QRect(120, 280, 40, 30));
        del_edge_s_textEdit->setFont(font);
        del_edge_s_label = new QLabel(centralwidget);
        del_edge_s_label->setObjectName(QString::fromUtf8("del_edge_s_label"));
        del_edge_s_label->setGeometry(QRect(100, 280, 10, 30));
        del_edge_s_label->setFont(font);
        del_edge_status_label = new QLabel(centralwidget);
        del_edge_status_label->setObjectName(QString::fromUtf8("del_edge_status_label"));
        del_edge_status_label->setGeometry(QRect(215, 280, 231, 30));
        del_edge_status_label->setFont(font);
        BFS_name_label = new QLabel(centralwidget);
        BFS_name_label->setObjectName(QString::fromUtf8("BFS_name_label"));
        BFS_name_label->setGeometry(QRect(20, 325, 121, 20));
        BFS_name_label->setFont(font1);
        BFS_info_label = new QLabel(centralwidget);
        BFS_info_label->setObjectName(QString::fromUtf8("BFS_info_label"));
        BFS_info_label->setGeometry(QRect(20, 350, 125, 30));
        BFS_info_label->setFont(font);
        BFS_textEdit = new QTextEdit(centralwidget);
        BFS_textEdit->setObjectName(QString::fromUtf8("BFS_textEdit"));
        BFS_textEdit->setGeometry(QRect(155, 350, 40, 30));
        BFS_textEdit->setFont(font);
        BFS_btn = new QPushButton(centralwidget);
        BFS_btn->setObjectName(QString::fromUtf8("BFS_btn"));
        BFS_btn->setGeometry(QRect(210, 350, 30, 30));
        BFS_result_textBrowser = new QTextBrowser(centralwidget);
        BFS_result_textBrowser->setObjectName(QString::fromUtf8("BFS_result_textBrowser"));
        BFS_result_textBrowser->setGeometry(QRect(20, 390, 220, 30));
        BFS_result_textBrowser->setFont(font);
        BFS_status_label = new QLabel(centralwidget);
        BFS_status_label->setObjectName(QString::fromUtf8("BFS_status_label"));
        BFS_status_label->setGeometry(QRect(250, 350, 190, 30));
        BFS_status_label->setFont(font);
        DFS_textEdit = new QTextEdit(centralwidget);
        DFS_textEdit->setObjectName(QString::fromUtf8("DFS_textEdit"));
        DFS_textEdit->setGeometry(QRect(155, 460, 40, 30));
        DFS_textEdit->setFont(font);
        DFS_info_label = new QLabel(centralwidget);
        DFS_info_label->setObjectName(QString::fromUtf8("DFS_info_label"));
        DFS_info_label->setGeometry(QRect(20, 460, 125, 30));
        DFS_info_label->setFont(font);
        DFS_status_label = new QLabel(centralwidget);
        DFS_status_label->setObjectName(QString::fromUtf8("DFS_status_label"));
        DFS_status_label->setGeometry(QRect(250, 460, 190, 30));
        DFS_status_label->setFont(font);
        DFS_name_label = new QLabel(centralwidget);
        DFS_name_label->setObjectName(QString::fromUtf8("DFS_name_label"));
        DFS_name_label->setGeometry(QRect(20, 435, 121, 20));
        DFS_name_label->setFont(font1);
        DFS_result_textBrowser = new QTextBrowser(centralwidget);
        DFS_result_textBrowser->setObjectName(QString::fromUtf8("DFS_result_textBrowser"));
        DFS_result_textBrowser->setGeometry(QRect(20, 500, 220, 30));
        DFS_result_textBrowser->setFont(font);
        DFS_btn = new QPushButton(centralwidget);
        DFS_btn->setObjectName(QString::fromUtf8("DFS_btn"));
        DFS_btn->setGeometry(QRect(210, 460, 30, 30));
        DA_btn = new QPushButton(centralwidget);
        DA_btn->setObjectName(QString::fromUtf8("DA_btn"));
        DA_btn->setGeometry(QRect(210, 570, 30, 30));
        DA_name_label = new QLabel(centralwidget);
        DA_name_label->setObjectName(QString::fromUtf8("DA_name_label"));
        DA_name_label->setGeometry(QRect(20, 545, 135, 20));
        DA_name_label->setFont(font1);
        DA_textEdit = new QTextEdit(centralwidget);
        DA_textEdit->setObjectName(QString::fromUtf8("DA_textEdit"));
        DA_textEdit->setGeometry(QRect(155, 570, 40, 30));
        DA_textEdit->setFont(font);
        DA_info_label = new QLabel(centralwidget);
        DA_info_label->setObjectName(QString::fromUtf8("DA_info_label"));
        DA_info_label->setGeometry(QRect(20, 570, 125, 30));
        DA_info_label->setFont(font);
        DA_status_label = new QLabel(centralwidget);
        DA_status_label->setObjectName(QString::fromUtf8("DA_status_label"));
        DA_status_label->setGeometry(QRect(250, 570, 190, 30));
        DA_status_label->setFont(font);
        DA_result_textBrowser = new QTextBrowser(centralwidget);
        DA_result_textBrowser->setObjectName(QString::fromUtf8("DA_result_textBrowser"));
        DA_result_textBrowser->setGeometry(QRect(20, 610, 320, 30));
        DA_result_textBrowser->setFont(font);
        example_graph_btn = new QPushButton(centralwidget);
        example_graph_btn->setObjectName(QString::fromUtf8("example_graph_btn"));
        example_graph_btn->setGeometry(QRect(20, 655, 100, 25));
        example_graph_btn->setFont(font);
        example_graph_btn_2 = new QPushButton(centralwidget);
        example_graph_btn_2->setObjectName(QString::fromUtf8("example_graph_btn_2"));
        example_graph_btn_2->setGeometry(QRect(130, 655, 100, 25));
        example_graph_btn_2->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1160, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "qtGraphs", nullptr));
        add_ver_btn->setText(QApplication::translate("MainWindow", "+", nullptr));
        add_ver_status_label->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\210\320\270\320\275: 0", nullptr));
        add_ver_name_label->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
        add_ver_info_label->setText(QApplication::translate("MainWindow", "\320\243\320\272\320\260\320\266\320\270\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\270 \320\262\320\265\321\200\321\210\320\270\320\275\321\213 \320\264\320\273\321\217 \321\201\320\262\321\217\320\267\320\270 (0 \320\270\320\273\320\270 \320\262\320\265\321\201 \321\200\320\265\320\261\321\200\320\260) \321\207\320\265\321\200\320\265\320\267 \320\277\321\200\320\276\320\261\320\265\320\273", nullptr));
        dell_ver_info_label->setText(QApplication::translate("MainWindow", "\320\243\320\272\320\260\320\266\320\270\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213 \320\264\320\273\321\217 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\321\217", nullptr));
        del_ver_status_label->setText(QString());
        del_ver_name_label->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
        del_ver_btn->setText(QApplication::translate("MainWindow", "-", nullptr));
        add_edge_name_label->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 (\320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265) \321\200\320\265\320\261\321\200\320\260", nullptr));
        add_edge_f_label->setText(QApplication::translate("MainWindow", "\320\236\321\202", nullptr));
        add_edge_s_label->setText(QApplication::translate("MainWindow", "\320\232", nullptr));
        add_edge_ves_label->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\201", nullptr));
        add_edge_btn->setText(QApplication::translate("MainWindow", "+", nullptr));
        add_edge_status_label->setText(QString());
        del_edge_name_label->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \321\200\320\265\320\261\321\200\320\260", nullptr));
        del_edge_btn->setText(QApplication::translate("MainWindow", "-", nullptr));
        del_edge_f_label->setText(QApplication::translate("MainWindow", "\320\236\321\202", nullptr));
        del_edge_s_label->setText(QApplication::translate("MainWindow", "\320\232", nullptr));
        del_edge_status_label->setText(QString());
        BFS_name_label->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\205\320\276\320\264 \320\262 \321\210\320\270\321\200\320\270\320\275\321\203", nullptr));
        BFS_info_label->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\320\265\321\200\321\210\320\270\320\275\320\260", nullptr));
        BFS_btn->setText(QApplication::translate("MainWindow", "->", nullptr));
        BFS_status_label->setText(QString());
        DFS_info_label->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\320\265\321\200\321\210\320\270\320\275\320\260", nullptr));
        DFS_status_label->setText(QString());
        DFS_name_label->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\205\320\276\320\264 \320\262 \320\263\320\273\321\203\320\261\320\270\320\275\321\203", nullptr));
        DFS_btn->setText(QApplication::translate("MainWindow", "->", nullptr));
        DA_btn->setText(QApplication::translate("MainWindow", "->", nullptr));
        DA_name_label->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\224\320\265\320\271\320\272\321\201\321\202\321\200\321\213", nullptr));
        DA_info_label->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\320\265\321\200\321\210\320\270\320\275\320\260", nullptr));
        DA_status_label->setText(QString());
        example_graph_btn->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\321\200 \320\263\321\200\320\260\321\204\320\260", nullptr));
        example_graph_btn_2->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
