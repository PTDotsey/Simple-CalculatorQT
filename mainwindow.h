#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *root = 0);
    bool onlyNums();
    void boolNum(bool);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QWidget* displayWidget;
    QWidget* calcWidget;
    QWidget* mainWidget;

    QGridLayout* displayLayout;
    QGridLayout* calcLayout;
    QGridLayout* mainLayout;

    void renderDisplay();
    void renderCalcWidget();
    void renderFullCalc();
    bool justNums = true;

public slots:
    void deleteChar();
    void Equals();
    void numSelected();
    void operatorSelected();
    void clearLine();
};

#endif // MAINWINDOW_H
