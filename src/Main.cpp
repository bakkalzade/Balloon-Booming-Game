#include "vector"
#include "string"
#include "Helper.cpp"
#include "SecondPart.h"

using namespace std;


int main(int argc, char* argv[]) {

    string txt1 = argv[1];
    string txt2 = argv[2];
    string output = argv[3];

    string message;//output text

    //part1 begins
    vector<string> all_lines_txt_1;


    all_lines_txt_1 = Helper::readFile(txt1);//read all lines in input_1.txt


    int gridRange = Helper::strToInt(all_lines_txt_1[0]);


    FirstPart firstPart(gridRange);

    message += firstPart.command(all_lines_txt_1, firstPart);//execute the commands that are taken from txt file

    //part2 begins
    vector<string> all_lines_txt_2;

    all_lines_txt_2 = Helper::readFile(txt2);//read all lines in input_2.txt

    gridRange = Helper::strToInt(all_lines_txt_2[0]);//define the range

    SecondPart secondPart(gridRange);

    message += secondPart.command(all_lines_txt_2, secondPart);//execute the commands that are taken from txt file

    Helper::write(output,message);

    return 0;
}
