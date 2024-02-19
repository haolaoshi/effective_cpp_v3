#include <iostream>
#include <string>


class File{
private:
	FILE* fp;

public:
	File(const std::string& filename,const std::string& mode){
		fp = fopen(filename.c_str(),mode.c_str());
		if(!fp){

			throw std::runtime_error("Cannot ");
		}

	}
	~File(){
		if(fp)
			fclose(fp);
	}
	void write(const std::string& content)
	{
		if(fwrite(content.c_str(),sizeof(char),content.size(),fp) != content.size()){
			throw std::runtime_error("failed to write file");
		}

	}

};

void processFile(const std::string& filename)
{
	File file(filename,"w");
	file.write("Hello World");
}


int main()
{
	try{

		processFile("output.txt");
	}catch(const std::exception& e){

		std::cerr<<"Exceptional corror:"<<e.what()<<std::endl;
	}
	return 0;
}
