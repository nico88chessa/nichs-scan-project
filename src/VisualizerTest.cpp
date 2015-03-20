#include <iostream>

#include "visualizer/KeyboardHandler.hpp"
#include "visualizer/Visualizer.hpp"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	KeyboardHandler test;

	Visualizer testWin("prova");
	testWin.showWindow();

	while (1) {
		cout << "Inserire carattere: ";
		char c;
		cin >> c;
		test.process(c).doEvent();
	}

}
