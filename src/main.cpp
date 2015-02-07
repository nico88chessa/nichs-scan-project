#include <iostream>

#include "configuration/FileParser.hpp"
#include "Prova.hpp"

Prova metodo(void);

int main(int argc, char** argv) {

	FileParser fp(argc, argv);

	if (!fp.isCommandsOk())
		exit(-1);

	const std::string& input = fp.getInputDirectory();
	const std::string& output = fp.getOutputDirectory();

	std::cout << input << "\t" << output << std::endl;



}
