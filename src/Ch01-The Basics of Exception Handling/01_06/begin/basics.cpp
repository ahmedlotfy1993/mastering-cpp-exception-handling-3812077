#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;

const string readConfigFile(const string& filename) 
{
    ifstream file(filename);
    if(!file.good())throw std::runtime_error {"File couldn't be opened"};
    string line;
    string text;
    while (getline(file, line)) 
    {
        text += line;
        text += '\n';
    }

    return text;
}

int main() 
{    try{
        cout << "Reading configuration:" << endl;
        string text = readConfigFile("configuration.txt");
        cout << text;
    }catch(const std::exception& ex){
        cerr << ex.what() << endl;
        return -1;
    }
    
    return 0;
}

