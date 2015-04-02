/*
 * ImageLoader.cpp
 *
 *  Created on: 10/feb/2015
 *      Author: nicola
 */

#include "ImageLoader.hpp"

using namespace std;
using namespace cv;
using namespace boost::filesystem;

ImageLoader::ImageLoader(const string& inputFolder): images(0) {

	path p(inputFolder);
	if (exists(p)) {
		if (is_directory(p)) {
//			copy(directory_iterator(p), directory_iterator(), ostream_iterator<directory_entry>(cout, "\n"));
			cout << endl;
			directory_iterator it(p);
			directory_iterator endit;
			while (it != endit) {
				if (it->path().extension().string().compare(".jpg")==0) {
//					cout << it->path().extension() << endl;
					string currentFileName = it->path().string();
					cout << "jpg caricato: " << currentFileName << endl;
					Mat img = imread(currentFileName);
					images.push_back(img);
				}
				it++;
			}
			cout << "#images: " << images.size() << endl;
		} else
			cout << "La path digitata non e' una directory." << endl;
	} else {
		cout << "La path digitata non esiste." << endl;
	}

//	vector<Mat>::const_iterator iter = images.begin();
//	for (; iter!=images.end(); iter++) {
//		cout << "prova" << endl;
//	}

}

ImageLoader::ImageLoader(const vector<string>& inputItems): images() {

	if (inputItems.empty())
		return;

	vector<string>::const_iterator it = inputItems.begin();
	while (it != inputItems.end()) {
		string currentFileName = *it++;
		Mat img = imread(currentFileName);
		images.push_back(img);
	}
}

ImageLoader::~ImageLoader() {
}

const vector<Mat>& ImageLoader::getImages() const {
	return images;
}
