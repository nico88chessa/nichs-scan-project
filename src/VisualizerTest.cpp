#include "utility/Utility.hpp"
#include "visualizer/KeyboardHandler.hpp"
#include "visualizer/IOVisualizer.hpp"
#include "events/NextImageEvent.hpp"
#include "events/PreviousImageEvent.hpp"
#include "events/ExitEvent.hpp"
#include <Container.hpp>
#include "utility/FileParser.hpp"

#include <iostream>
#include <utility>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>


using namespace std;

int main(int argc, char** argv) {

	FileParser fp(argc, argv);

	if (!fp.isCommandsOk())
		exit(-1);

	const string& inputDirectory = fp.getInputDirectory();
	const vector<string>& inputFiles = fp.getListItems();
	const string& output = fp.getOutputDirectory();

	Container<string, Image> images;
//	vector<cv::Mat> images;
	Utility::loadImagesFromPath(inputDirectory, images);
	Container<string, Image> images2;
//	vector<cv::Mat> images2;
	Utility::loadImagesFromList(inputFiles, images2);

//	ImageScroller::Ptr imageScroller;
//	if (!images.empty())
//		imageScroller = boost::make_shared<ImageScroller>(move(images));
//	else if (!images2.empty())
//		imageScroller = boost::make_shared<ImageScroller>(move(images2));
//	else {
//		cout << "Nessuna Immagina caricata." << endl;
//		exit(-1);
//	}
	// here imageLoader is in non-defined state



	KeyboardHandler::Ptr test = boost::make_shared<KeyboardHandler>();
	IOVisualizer::Ptr testWin2 = boost::make_shared<IOVisualizer>("ciao", test);
	Container<string, Image>::CyclicIterator temp = images.iterator();
	Container<string, Image>::CyclicIterator::Ptr imageScroller = boost::make_shared<Container<string, Image>::CyclicIterator>(images.iterator());

	NextImageEvent::Ptr nextImage = boost::make_shared<NextImageEvent>(testWin2, imageScroller);
	PreviousImageEvent::Ptr previousImage = boost::make_shared<PreviousImageEvent>(testWin2, imageScroller);
	ExitEvent::Ptr exitEvent = boost::make_shared<ExitEvent>(testWin2);

	test->addEvent(nextImage, 'n');
	test->addEvent(previousImage, 'p');
	test->addEvent(exitEvent, 'q');

	testWin2->wait();

	cout << "END" << endl;

}
