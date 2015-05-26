/*
 * FileParser.cpp
 *
 *  Created on: 11/gen/2015
 *      Author: nicola
 */

#include "FileParser.hpp"

using namespace std;

const string FileParser::HELP = "help";
const string FileParser::INPUT = "input";
const string FileParser::LIST = "list";
const string FileParser::OUTPUT = "output";


FileParser::FileParser(int argc, char* argv[]) :
	OPTIONS(buildOptions()), PROG_NAME(argv[0]),
	commandsOK(true) {

	bpo::variables_map vm;
	try {
		bpo::store(bpo::command_line_parser(argc, argv).
				options(OPTIONS).run(), vm);
	} catch (bpo::unknown_option &er) {
		cout << "Sintassi chiamata programma errata: " << er.what() << endl;
		cout << OPTIONS << endl;
		commandsOK = false;
		return;
	}
    bpo::notify(vm);

	if (vm.count(INPUT))
		inputDirectory = vm[INPUT].as<string>();
	else if (vm.count(LIST)) {
		listItems = vm[LIST].as< vector<string> >();
	} else
		commandsOK = false;

	if (vm.count(OUTPUT))
		outputDirectory = vm[OUTPUT].as<string>();
	else
		commandsOK = false;

	if (vm.count(HELP) || !commandsOK) {
	    cout << OPTIONS << "\n";
	}
}

const string& FileParser::getInputDirectory() const {
	return inputDirectory;
}

void FileParser::setInputDirectory(const string& inputDirectory) {
	this->inputDirectory = inputDirectory;
}

const string& FileParser::getOutputDirectory() const {
	return outputDirectory;
}

bool FileParser::isCommandsOk() const {
	return commandsOK;
}

void FileParser::setCommandsOk(bool commandsOk) {
	commandsOK = commandsOk;
}

void FileParser::setOutputDirectory(const string& outputDirectory) {
	this->outputDirectory = outputDirectory;
}

const std::vector<std::string>& FileParser::getListItems() const {
	return listItems;
}

FileParser::~FileParser() {
}

const bpo::options_description FileParser::buildOptions() {

	bpo::options_description optionDesc("Uso Programma");
	optionDesc.add_options()
			(Utility::string2char(HELP+",h"), "visualizza questa guida")
			(Utility::string2char(INPUT+",i"), bpo::value<string>(), "specifica la directory di input")
			(Utility::string2char(OUTPUT+",o"), bpo::value<string>(), "specifica la directory di output")
			(Utility::string2char(LIST+",l"), bpo::value< vector<string> >()->multitoken(), "specifica la lista di singoli file di input");

	return optionDesc;
}

