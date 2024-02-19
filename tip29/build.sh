#!/bin/bash

if [[ ! -d "build" ]]; then
	mkdir "build"
fi

cd build || exit

cmake -DCMAKE_BUILD_TYPE=Debug .. || exit
make || exit 

project_name=`grep add_executable ../CMakeLists.txt |awk '{split($1,str,"("); print(str[2]); }'`


if [[ -z ${project_name} ]]; then
	echo "no project name in CMakeLists.txt"
	exit 1
fi

if [[ ! -e  ${project_name} ]]; then
	echo "no executable file: ${project_name}"
	exit 1
fi

echo "run ..."${project_name}
"./${project_name}"
echo 
