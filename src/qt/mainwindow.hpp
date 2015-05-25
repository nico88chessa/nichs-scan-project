#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include "../data/Container.hpp"
#include "../data/Image.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    Container<std::string, Image> container;

private slots:
    void on_imageInputList_clicked(const QModelIndex &index);

public:

    explicit MainWindow(const Container<std::string, Image>& _container, QWidget *parent = 0);

    ~MainWindow();

};

#endif // MAINWINDOW_H
