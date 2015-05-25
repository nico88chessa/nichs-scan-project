#ifndef IMAGEVIEWERFORM_HPP
#define IMAGEVIEWERFORM_HPP

#include <iostream>
#include <QWidget>

#include "../utility/ImageUtils.hpp"
#include "../data/Container.hpp"
#include "../data/Image.hpp"

namespace Ui {
	class ImageViewerForm;
}

class ImageViewerForm : public QWidget {
    Q_OBJECT

private:
    std::string test;
    Container<std::string, Image>::CyclicIterator imageIterator;

public:
    explicit ImageViewerForm(QWidget *parent = 0);

    ~ImageViewerForm();

private slots:
    void on_PreviousImage_clicked();

    void on_NextImage_clicked();

public slots:
	void setIterator(const Container<std::string, Image>::CyclicIterator& _iterator);

    void setIterator(Container<std::string, Image>::CyclicIterator&& _iterator);

    void setImage(const std::string& _str);

    void setIteratorAt(const std::string& _str);

signals:
    void updateIterator(const std::string& str);

private:
    Ui::ImageViewerForm *ui;
};

#endif // IMAGEVIEWERFORM_HPP
