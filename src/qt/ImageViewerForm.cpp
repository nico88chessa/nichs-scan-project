#include "ImageViewerForm.hpp"
#include "ui_ImageViewerForm.h"

ImageViewerForm::ImageViewerForm(QWidget *parent)
	: QWidget(parent), ui(new Ui::ImageViewerForm) {
	ui->setupUi(this);
}

ImageViewerForm::~ImageViewerForm() {
    delete ui;
}

void ImageViewerForm::on_PreviousImage_clicked() {
	cv::Mat&& current = imageIterator.previous().getImageCopy();
	QImage image = ImageUtils::cv2Qimage(current);
	ui->Image->setPixmap(QPixmap::fromImage(image));
}

void ImageViewerForm::on_NextImage_clicked() {
	cv::Mat&& current = imageIterator.next().getImageCopy();
	QImage image = ImageUtils::cv2Qimage(current);
	ui->Image->setPixmap(QPixmap::fromImage(image));

}

void ImageViewerForm::setIterator(const Container<std::string, Image>::CyclicIterator& _iterator) {
	imageIterator = _iterator;
}

void ImageViewerForm::setIterator(Container<std::string, Image>::CyclicIterator&& _iterator) {
	imageIterator = std::move(_iterator);
}

void ImageViewerForm::setImage(const std::string& _str) {
    ui->Image->setText(QString(_str.c_str()));
}

void ImageViewerForm::setIteratorAt(const std::string& _str) {

	cv::Mat&& current = imageIterator.at(_str).getImageCopy();
	QImage image = ImageUtils::cv2Qimage(current);
	ui->Image->setPixmap(QPixmap::fromImage(image));
}
