#!/bin/bash

if [[ ! -d "build" ]]; then
	mkdir "build"
fi

cd build || exit

cmake -DCMAKE_BUILD_TYPE=Debug .. || exit
make || exit 

current_path=$(pwd)
if [[ $current_path == *"build"* ]]; then
	project_name=`grep add_executable ../CMakeLists.txt |awk '{split($1,str,"("); print(str[2]); }'`


	if [[ -z ${project_name} ]]; then
		echo "no project name in CMakeLists.txt"
		exit 1
	fi
	
	if [ -f "./${project_name}" ] && [ -x "./${project_name}" ]; then
		echo "run ..."${project_name}
		echo '----------------------------'
		"./${project_name}"
		echo 

	fi
	if [[ ! -f  "./${project_name}" ]]; then
		echo "no executable file: ./${project_name} aaaaa"
		exit 1
	fi
#	echo
#	echo "run ..."${project_name}
#	echo '----------------------------'
#	"./${project_name}"
	echo 
else

	echo "$current_path is not right."
fi
