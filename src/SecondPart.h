
#ifndef ass1_SECONDPART_H
#define ass1_SECONDPART_H

#include "FirstPart.h"
#include "vector"
#include <iostream>
#include <fstream>
#include "vector"
#include "string"
#include <sstream>
using namespace std;




class SecondPart {

private:

    int **grid;
    int point;
    string message= "PART 2:\n";


public:

    explicit SecondPart(int gridRange);

    string command(vector<string>&,SecondPart&);

    void gridPrinter(SecondPart &secondPart, int size);


    void fillTheGrid(SecondPart& secondPart, int size,vector<string>, int row_value);


    void killTheBomb(Coordinate coordinate, SecondPart& secondPart, int size);

    vector<Coordinate> getAllLinks(Coordinate coordinate, SecondPart &secondPart, int size);
};


#endif //ass1_SECONDPART_H
