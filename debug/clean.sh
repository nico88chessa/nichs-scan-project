#!/bin/sh

echo "Rimozione file in corso..."
rm -f *.cmake
rm -f *.txt
rm -Rf CMakeFiles
rm -Rf configuration threading utility visualizer
rm -f Makefile core
rm -f main main2 VisualizerTest
rm -f *.sh~
rm -f .cproject .project
echo "Rimozione eseguita."
