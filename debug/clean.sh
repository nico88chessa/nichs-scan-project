#!/bin/sh

echo "Rimozione file in corso..."
rm -f *.cmake
rm -f *.txt
rm -Rf CMakeFiles
rm -Rf configuration
rm -Rf utility
rm -f Makefile
rm -f main
rm -f *.sh~
rm -f .cproject .project
echo "Rimozione eseguita."
