#include "utility/Utility.hpp"
#include "utility/ImageUtils.hpp"
#include "visualizer/KeyboardHandler.hpp"
#include "visualizer/IOVisualizer.hpp"
#include "events/NextImageEvent.hpp"
#include "events/PreviousImageEvent.hpp"
#include "events/ExitEvent.hpp"
#include "utility/FileParser.hpp"

#include <iostream>
#include <Utility.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>

#include "qt/mainwindow.hpp"
#include <QtWidgets/qwidget.h>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]) {

	FileParser fp(argc, argv);

	if (!fp.isCommandsOk())
		exit(-1);

	const string& inputDirectory = fp.getInputDirectory();
	const vector<string>& inputFiles = fp.getListItems();
	const string& output = fp.getOutputDirectory();

	vector<cv::Mat> images;
	Utility::loadImagesFromPath(inputDirectory, images);
	vector<cv::Mat> images2;
	Utility::loadImagesFromList(inputFiles, images2);

	///////////////////////////////////////////////////////////////////////////////

	Container<string, Image> images3;
	Utility::loadImagesFromPath(inputDirectory, images3);

	std::vector<Image> imagesList = images3.getValues();
	std::vector<Image>::iterator itList = imagesList.begin();
	for (; itList != imagesList.end(); itList++)
		std::cout << itList->getImageName() << std::endl;

	///////////////////////////////////////////////////////////////////////////////

    QApplication qAppl(argc, argv);
    MainWindow w2(images3);
	w2.show();
    return qAppl.exec();
}
