#ifndef FILE_READER
#define FILE_READER

#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 

using namespace std;

class FileReader {
    public:
        static string readFile(string path) {
            ifstream file(path);
                if (!file) {
                    cout << "Error opening file: " << path << endl;
                    return "";
                };

                ostringstream ss;
                ss << file.rdbuf();  
                return ss.str(); 
        }
};

#endif // FILE_READER