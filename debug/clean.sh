#!/bin/sh

echo "Rimozione file in corso..."
rm -f *.cmake
rm -f *.txt
rm -Rf CMakeFiles
rm -Rf configuration threading utility visualizer qt data algorithm
rm -f Makefile core
rm -f main main2 VisualizerTest mainQt
rm -f *.sh~
rm -f .cproject .project
rm -f *.cpp
echo "Rimozione eseguita."
