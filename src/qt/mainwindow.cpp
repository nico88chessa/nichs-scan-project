#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::~MainWindow() {
    delete ui;
}

MainWindow::MainWindow(const Container<std::string, Image>& _container, QWidget* parent)
	: QMainWindow(parent), ui(new Ui::MainWindow), container(_container) {
	ui->setupUi(this);
	ui->InputImages->setIterator(container.iterator());

	std::vector<Image> images = container.getValues();
	std::vector<Image>::iterator it = images.begin();
	for (; it != images.end(); it++)
		ui->imageInputList->addImageString(it->getImageName());

}

void MainWindow::on_imageInputList_clicked(const QModelIndex &index) {
    emit ui->imageInputList->selectedInputImage(ui->imageInputList->getModel()->stringList().at(index.row()).toStdString());
}
