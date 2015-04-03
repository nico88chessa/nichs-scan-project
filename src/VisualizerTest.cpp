#include <iostream>

#include "visualizer/KeyboardHandler.hpp"
#include "visualizer/IOVisualizer.hpp"
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <events/NextImageEvent.hpp>
#include <events/PreviousImageEvent.hpp>
#include "ImageLoader.hpp"
#include "ImageScroller.hpp"
#include <iostream>
#include "configuration/FileParser.hpp"
#include <utility>

using namespace std;

int main(int argc, char** argv) {

	FileParser fp(argc, argv);

	if (!fp.isCommandsOk())
		exit(-1);

	const std::string& input = fp.getInputDirectory();
	const std::string& output = fp.getOutputDirectory();

	ImageLoader imageLoader(input);
	ImageScroller::Ptr imageScroller = boost::make_shared<ImageScroller>(std::move(imageLoader.getImages()));
	// here imageLoader is in non-defined state

	KeyboardHandler::Ptr test = boost::make_shared<KeyboardHandler>();
	IOVisualizer::Ptr testWin2 = boost::make_shared<IOVisualizer>("ciao", test);

	NextImageEvent::Ptr nextImage = boost::make_shared<NextImageEvent>(testWin2, imageScroller);
	PreviousImageEvent::Ptr previousImage = boost::make_shared<PreviousImageEvent>(testWin2, imageScroller);
	test->addEvent(nextImage, 'n');
	test->addEvent(previousImage, 'p');

	testWin2->show();

}
