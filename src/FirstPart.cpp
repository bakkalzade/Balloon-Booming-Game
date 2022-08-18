
#include "FirstPart.h"
#include <iostream>
#include "vector"
#include "string"
#include "Helper.cpp"

using namespace std;




vector<Coordinate> find_possible_links(int row_value,int column_value, int size ){

    vector<Coordinate> possible;

    for (int i:{1,-1}){

            if (0 <= row_value+i && row_value+i < size){

                Coordinate a{row_value+i,column_value};

                possible.push_back(a);

            }
            if (0 <= column_value+i && column_value+i < size){

                Coordinate a{row_value,column_value+i};

                possible.push_back(a);

            }
    }

    return possible;
}

void FirstPart::gridPrinter(FirstPart &firstPart, int size) {

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            firstPart.message+=std::to_string(firstPart.grid[i][j]);
            firstPart.message+=" ";

        }
        firstPart.message+="\n";

    }
    firstPart.message+="\n";

}

void FirstPart::findLinks(int row_value, int column_value, int size, FirstPart &firstPart,   vector<Coordinate> &coordinates) {

    Coordinate thisCoor{row_value,column_value};

    int value = firstPart.grid[row_value][column_value];


    vector<Coordinate> possibleLinks;

    vector<Coordinate> removableLinks = find_possible_links(row_value,column_value,size);

    for(auto a : removableLinks){

        int x = a.x; int y = a.y;

        if (firstPart.grid[x][y]==value){

            possibleLinks.push_back(a);
            coordinates.push_back(a);

        }

    }
    for(auto a : possibleLinks){

        vector<Coordinate> newCoor = findSecondLinks(a.x,a.y,size,firstPart,thisCoor);

        coordinates.insert(coordinates.end(),newCoor.begin(),newCoor.end());

    }

    if (coordinates.size()>2){

        killLinks(coordinates,firstPart);

        firstPart.grid[row_value][column_value]=value+1;

        vector<Coordinate> a;
        findLinks(row_value,column_value,size,firstPart,a);
    }

}

vector<Coordinate> FirstPart::findSecondLinks(int row_value, int column_value, int size, FirstPart &firstPart, Coordinate previousCoor) {

    int value = firstPart.grid[row_value][column_value];

    vector<Coordinate> allPossibleLinks;


    vector<Coordinate> possibleLinks;

    vector<Coordinate> removableLinks = find_possible_links(row_value,column_value,size);

    for(auto a : removableLinks){

        int x = a.x; int y = a.y;

        if (firstPart.grid[x][y]==value){

                possibleLinks.push_back(a);

        }

    }

    return possibleLinks;

}

void FirstPart::killLinks( vector<Coordinate>& links_to_kill,FirstPart &firstPart) {


    for (auto a: links_to_kill) {

        int x= a.x ; int y = a.y;

        firstPart.grid[x][y]=0;

    }

}

string FirstPart::command(vector<string> &commands, FirstPart &firstPart) {


    int size= Helper::strToInt(commands[0]);

    for (int i = 1; i < commands.size(); ++i) {


        vector<string> seperatedNumbers = Helper::split(commands[i]," ");

        int value = Helper::strToInt(seperatedNumbers[0]);

        //x and y values are stored
        int row_value = Helper::strToInt(seperatedNumbers[1]);
        int column_value = Helper::strToInt(seperatedNumbers[2]);


        firstPart.grid[row_value][column_value]=value;


        vector<Coordinate> coordinates;

        Coordinate previousCoor{-1,-1};

        findLinks(row_value,column_value,size,firstPart,coordinates);


    }
    gridPrinter(firstPart,size);

    return this->message;

}

FirstPart::FirstPart(int gridRange) {

    grid= new int *[gridRange];

    for (int i = 0; i < gridRange; i++) {

        grid[i]=new int[gridRange];

    }


    for (int i = 0; i < gridRange; i++) {

        for (int j = 0; j < gridRange; j++) {

            grid[i][j]=0;

        }

    }

}


