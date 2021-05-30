#include "IO.hpp"
#include <fstream>
#include <sstream>
#include <sys/stat.h>

namespace StackVM
{
    void IO::WriteAllText(const std::string& text, const std::string& filepath)
    {
	    std::ofstream outfile;

	    std::string file(filepath);

	    outfile.open(file);//std::ios_base::app
	    outfile << text; 
	    outfile.close();
    }

    void IO::WriteAllBytes(std::vector<unsigned char>& bytes, const std::string& filepath)
    {
	    std::ofstream file(filepath);

	    if(file)
	    {
		    file.write(reinterpret_cast<const char*>(&bytes[0]), bytes.size());
	    }

	    if(file.is_open())
		    file.close();
    }

    void IO::WriteAllBytes(unsigned char* bytes, size_t length, const std::string& filepath)
    {
	    std::ofstream file(filepath);

	    if(file)
	    {
		    file.write(reinterpret_cast<const char*>(bytes), length);
	    }

	    if(file.is_open())
		    file.close();
    }

    std::string IO::ReadAllText(const std::string& filepath)
    {
	    std::ifstream file(filepath);
	    std::string str;
	    std::string file_contents;

	    while (std::getline(file, str))
	    {
		    file_contents += str;
		    file_contents.push_back('\n');
	    } 

	    if(file.is_open())
		    file.close();
	    return file_contents; 
    }

    std::vector<std::string> IO::ReadAllLines(const std::string& filepath)
    {
	    std::ifstream file(filepath);
	    std::string str;
	    std::vector<std::string> lines;

	    while (std::getline(file, str))
	    {
		    lines.push_back(str);
	    } 

	    if(file.is_open())
		    file.close();
	    return lines; 
    }

    std::vector<unsigned char> IO::ReadAllBytes(const std::string& filepath)
    {
	    std::vector<unsigned char> bytes;
	    std::ifstream file(filepath, std::ios_base::in | std::ios_base::binary);
	    unsigned char ch = file.get();
	
	    while (file.good())
	    {
		    bytes.push_back(ch);
		    ch = file.get();
	    }
	
	    file.close();
	    return bytes;
    }

    std::string IO::ReadLastLine(const std::string& filepath)
    {
	    std::ifstream file(filepath);
	    std::string str;
	    std::string line;

	    while (std::getline(file, str))
	    {
		    line = str;
	    } 

	    if(file.is_open())
		    file.close();
	    return line;
    }

    long IO::GetFileSize(const std::string& filepath)
    {
        struct stat stat_buf;
        int rc = stat(filepath.c_str(), &stat_buf);
        return rc == 0 ? stat_buf.st_size : -1;
    }

    bool IO::FileExists(const std::string& filepath)
    {
	    struct stat buffer;   
	    return (stat(filepath.c_str(), &buffer) == 0); 
    }
}