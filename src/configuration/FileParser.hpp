/*
 * FileParser.hpp
 *
 *  Created on: 11/gen/2015
 *      Author: nicola
 */

#ifndef CONFIGURATION_FILEPARSER_HPP_
#define CONFIGURATION_FILEPARSER_HPP_

#include <boost/program_options.hpp>
#include "../utility/Utility.hpp"
#include <iostream>

namespace bpo = boost::program_options;


class FileParser {
private:
	static const std::string HELP;
	static const std::string INPUT;
	static const std::string OUTPUT;

	const bpo::options_description OPTIONS;
	const bpo::positional_options_description POSITIONALS;
	const std::string PROG_NAME;

	const bpo::options_description buildOptions();
	const bpo::positional_options_description buildPositionalsOptions();

	std::string inputDirectory;
	std::string outputDirectory;
	bool commandsOK;

public:
	FileParser(int argc, char* argv[]);
	virtual ~FileParser();

	const std::string& getInputDirectory() const;
	void setInputDirectory(const std::string& inputDirectory);
	const std::string& getOutputDirectory() const;
	void setOutputDirectory(const std::string& outputDirectory);
	bool isCommandsOk() const;
	void setCommandsOk(bool commandsOk);
};

#endif /* CONFIGURATION_FILEPARSER_HPP_ */
