#include <iostream>
#include <fstream>
#include "vector"
#include "string"
#include <sstream>

using namespace std;

class Helper{


public:


    static string charToStr(char a){

        string str;

        str += a;

        return str;


    }

    static int charToInt(char a){

        string str = charToStr(a);

        int value = strToInt(str);

        return value;

    }

    //converter of str value to integer
    static int strToInt(string str){

        stringstream intValue(str);
        int number = 0;
        intValue >> number;
        return number;

    }

    //read files and convert the to vector<string>
    static vector<string> readFile(const string& file){


        vector<string> allLines;

        string myText;

        // "../" to absolute path
        ifstream MyReadFile(file);


        while (getline (MyReadFile, myText)) {

            allLines.push_back(myText);

        }

        MyReadFile.close();

        return allLines;

    }

    static vector<string> split (string s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }

    static void write(string fileName,string message){

        // Create and open a text file
        ofstream MyFile(fileName);

        // Write to the file
        MyFile << message;

        // Close the file
        MyFile.close();




    }

};

