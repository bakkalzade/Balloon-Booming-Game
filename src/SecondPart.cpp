#include "SecondPart.h"
#include "vector"
#include "string"
#include "Helper.cpp"

using namespace std;


//create a grid and set the point equal to 0
SecondPart::SecondPart(int gridRange) {

    grid= new int *[gridRange];
    point=0;


    for (int i = 0; i < gridRange; i++) {

        grid[i]=new int[gridRange];

    }


    for (int i = 0; i < gridRange; i++) {

        for (int j = 0; j < gridRange; j++) {

            grid[i][j]=0;

        }

    }
}

//fills the given grid with the given numbers accordingly
void SecondPart::fillTheGrid(SecondPart &secondPart, int size, vector<string> seperatedNumbers,int row_value) {


    for (int i = 0; i < seperatedNumbers.size(); i++) {

        secondPart.grid[row_value][i]=Helper::strToInt(seperatedNumbers[i]);

    }

}

string SecondPart::command(vector<string>  &commands, SecondPart &secondPart) {


    int size= Helper::strToInt(commands[0]);//define size of the grid

    for(int i =1 ; i<= size; i++){//fill the grid with relative numbers

        vector<string> seperatedNumbers = Helper::split(commands[i]," ");

        fillTheGrid(secondPart,size,seperatedNumbers,i-1);
    }



    for (int i = size+1; i < commands.size(); ++i) {


        //split the line and take the strings as an integer
        vector<string> seperatedNumbers = Helper::split(commands[i]," ");

        //x and y values are stored
        int row_value = Helper::strToInt(seperatedNumbers[0]);
        int column_value = Helper::strToInt(seperatedNumbers[1]);


        Coordinate bombCoor{row_value,column_value};

        killTheBomb(bombCoor,secondPart, size);// detonate the bomb



    }
    gridPrinter(secondPart,size);// write the output

    return this->message;






}

void SecondPart::gridPrinter(SecondPart &secondPart, int size) {

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            secondPart.message+=std::to_string(secondPart.grid[i][j]);
            secondPart.message+=" ";

        }
        secondPart.message+="\n";

    }
    secondPart.message+="Final Point: ";
    secondPart.message+=std::to_string(secondPart.point);
    secondPart.message+="p";


}

void SecondPart::killTheBomb(Coordinate coordinate, SecondPart &secondPart, int size) {

    int value = secondPart.grid[coordinate.x][coordinate.y];


    vector<Coordinate> allLinks = getAllLinks(coordinate,secondPart,size);//all diagonals and perpendiculars

    int counter = 0 ;
    for(auto coor : allLinks) {

        int x = coor.x; int y = coor.y;

        if (secondPart.grid[x][y]==value){

            secondPart.grid[x][y]=0;

            counter++;

        }

    }

    secondPart.point+= counter*value;

}

vector<Coordinate> SecondPart::getAllLinks(Coordinate coordinate, SecondPart &secondPart, int size) {

    vector<Coordinate> allCoordinates;

    int x = coordinate.x; int y = coordinate.y;

    for (int i = 1-size ; i < size; i++) {

        //horizontal ascending links
        if (x-i < size && x-i >= 0 && y-i <size && y-i >= 0){

            Coordinate newCoor{x-i,y-i};

            allCoordinates.push_back(newCoor);

        }//vertical ascending links
        if (x-i < size && x-i >= 0 && y+i <size && y+i >= 0){

            Coordinate newCoor{x-i,y+i};

            allCoordinates.push_back(newCoor);

        }

    }//perpendicular links
    for (int i = 0; i < size; i++) {

        Coordinate newCoorx{x,i}; Coordinate newCoory{i,y};

        allCoordinates.push_back(newCoorx); allCoordinates.push_back(newCoory);

    }

    return allCoordinates;

}
