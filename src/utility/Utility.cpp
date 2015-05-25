/*
 * Utility.cpp
 *
 *  Created on: 17/gen/2015
 *      Author: nicola
 */

#include "Utility.hpp"

using namespace std;
using namespace boost::filesystem;
using namespace cv;

Utility::Utility() {
}

Utility::~Utility() {
}

const char* Utility::string2char(const string& stringa) {
	return stringa.c_str();
}

short Utility::loadImagesFromPath(const string& pathFolder, vector<Mat>& images) {
	path p(pathFolder);
	if (exists(p)) {
		if (is_directory(p)) {
			// copy(directory_iterator(p), directory_iterator(), ostream_iterator<directory_entry>(cout, "\n"));
			cout << endl;
			directory_iterator it(p);
			directory_iterator endit;
			while (it != endit) {
				if (it->path().extension().string().compare(".jpg")==0) {
					// cout << it->path().extension() << endl;
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

	return 0;
}

short Utility::loadImagesFromPath(const std::string& pathFolder, Container<std::string, Image>& container) {
	path p(pathFolder);
	if (exists(p)) {
		if (is_directory(p)) {
			// copy(directory_iterator(p), directory_iterator(), ostream_iterator<directory_entry>(cout, "\n"));
			cout << endl;
			directory_iterator it(p);
			directory_iterator endit;
			while (it != endit) {
				if (it->path().extension().string().compare(".jpg")==0) {
					// cout << it->path().extension() << endl;
					string currentFileName = it->path().string();
					cout << "jpg caricato: " << currentFileName << endl;
					Mat img = imread(currentFileName);
					container.add(currentFileName, Image(currentFileName, img));
				}
				it++;
			}
			cout << "#images: " << container.size() << endl;
		} else
			cout << "La path digitata non e' una directory." << endl;
	} else {
		cout << "La path digitata non esiste." << endl;
	}
	return 0;
}

short Utility::loadImagesFromList(const vector<string>& imagesNames, vector<Mat>& images) {

	if (imagesNames.empty())
		return -1;

	vector<string>::const_iterator it = imagesNames.begin();
	while (it != imagesNames.end()) {
		string currentFileName = *it++;
		path p(currentFileName);
		if (exists(p)) {
			Mat img = imread(currentFileName);
			images.push_back(img);
		}
	}

	return 0;
}

short Utility::loadImagesFromList(const vector<string>& imagesNames, Container<std::string, Image>& container) {

	if (imagesNames.empty())
		return -1;

	vector<string>::const_iterator it = imagesNames.begin();
	while (it != imagesNames.end()) {
		string currentFileName = *it++;
		path p(currentFileName);
		if (exists(p)) {
			Mat img = imread(currentFileName);
			container.add(std::move(currentFileName), Image(currentFileName, img));
		}
	}

	return 0;
}
