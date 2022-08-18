
#ifndef ass1_FIRSTPART_H
#define ass1_FIRSTPART_H

#include "vector"
#include <iostream>
#include <fstream>
#include "vector"
#include "string"
#include <sstream>
using namespace std;

struct Coordinate {
    int x;
    int y;


};

class FirstPart {

    private:

        int **grid;
        string message= "PART 1:\n";


    public:

        explicit FirstPart(int gridRange);

        string command(vector<string>&,FirstPart&);


    void killLinks(vector<Coordinate> &links_to_kill, FirstPart &firstPart);

    void gridPrinter(FirstPart &firstPart, int size);


    vector<Coordinate>
    findSecondLinks(int row_value, int column_value, int size, FirstPart &firstPart, Coordinate previousCoor);

    void findLinks(int row_value, int column_value, int size, FirstPart &firstPart, vector<Coordinate> &coordinates);
};


#endif //UNTITLED2_FIRSTPART_H
