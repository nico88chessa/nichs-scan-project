#ifndef IMAGEINPUTLIST_HPP
#define IMAGEINPUTLIST_HPP

#include <QtWidgets/QListView>
#include <qstringlistmodel.h>
#include <qstringlist.h>
#include <iostream>

class ImageInputList : public QListView {
    Q_OBJECT

private:
    QStringListModel* model;
    QStringList* stringList;

signals:
	void selectedInputImage(const std::string& imageName);

public slots:
	// USELESS
    void setImageSelected() {
        emit selectedInputImage("prova");
    }
    // END USELESS

public:
    explicit ImageInputList(QWidget *parent = 0)
    	: QListView(parent), model(new QStringListModel()),
		  stringList(new QStringList()) {
    	this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    	this->setModel(model);
    }

    void addImageString(const std::string& item) {
		stringList->append(*new QString(item.c_str()));
		model->setStringList(*stringList);
    }

    ~ImageInputList() {
    }

    const QStringListModel* getModel() {
	   return model;
    }

};

#endif // IMAGEINPUTLIST_HPP

