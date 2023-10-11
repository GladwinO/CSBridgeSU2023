// gto219_hw13.cpp:

#include <iostream>
#include <cstdlib>
#include <ctime>

//area for const variables
const int numRows = 4;
const int numCols = 4;
const int maxAnts = 2;
const int maxDoodleBugs = 3;
const int maxBugs = maxAnts + maxDoodleBugs;

class Organism {
private:
    int xPos = 0;
    int yPos = 0;
    int numMoves = 0;
    char symb = '-';
protected:
    //I will have the helper fucntions for the move function here so the derived class versions of the helper functions can be called during 
    //runtime. I do not want these functions accessible publically
public:
    Organism();
    Organism(int userXPos);
    Organism(int userXPos, int userYPos);
    Organism(int userXPos, int userYPos, int moves);
    int getXPos() const;
    int getYPos() const;
    int getNumMoves() const;
    char getSymb() const;
    void setXPos(int xPosition);
    void setYPos(int yPosition);
    void setMoves(int userNumMoves);
    void setSymb(char userSymb); //i only want the derived classes using it so should it be protected instead?
    //virtual void Move(Organism* orgArrPtr);//still trying to figure out what the parameters should be
    friend std::ostream& operator<<(std::ostream& outs, const Organism& bug);

};

class Ant : public Organism {
    //this may need some private variables I have not thought of yet
public:
    Ant();
    Ant(int userXPos);
    Ant(int userXPos, int userYPos);
    Ant(int userXPos, int userYPos, int moves);
    friend std::ostream& operator <<(std::ostream& outs, const Ant& bug);
};

class Doodlebug : public Organism {
    //this may need some private variables I have not thought of yet
public:
    Doodlebug();
    Doodlebug(int userXPos);
    Doodlebug(int userXPos, int userYPos);
    Doodlebug(int userXPos, int userYPos, int moves);
    friend std::ostream& operator <<(std::ostream& outs, const Doodlebug& bug);
};

/// non-member functions declaration list
void createBaseGrid(Organism* orgArrPtr[][numCols]);

void createPlayableGrid(Organism* orgArrPtr[][numCols]);

void printGrid(Organism* orgArrPtr[][numCols]);

void deleteGrid(Organism* orgArrPtr[][numCols]);


int main()
{
    Organism* orgArrPtr[numRows][numCols];
    createBaseGrid(orgArrPtr);
    printGrid(orgArrPtr);
    createPlayableGrid(orgArrPtr);

    
    printGrid(orgArrPtr);
    deleteGrid(orgArrPtr);

    
}

//Class defintions



Organism::Organism() {
    //do nothing because the private member variables are set to base values when they were initialzed in the class
}
Organism::Organism(int userXPos) : xPos(userXPos) {
    if (userXPos < 0 || userXPos >= numRows) {
        xPos = 0;
        std::cout << "Row position out of range. Row position has been set equal to 0. Please reassign row position to a number "
            << "between 0 and 19." << std::endl;
    }
}
Organism::Organism(int userXPos, int userYPos) {
    if (userXPos < 0 || userXPos >= numRows) {
        xPos = 0;
        std::cout << "Row position out of range. Row position has been set equal to 0. Please reassign row position to a number "
            << "between 0 and 19." << std::endl;
    }
    if (userYPos < 0 || userYPos >= numCols) {
        yPos = 0;
        std::cout << "Column position out of range. Column position has been set equal to 0. Please reassign column position to a number "
            << "between 0 and 19." << std::endl;
    }
}
Organism::Organism(int userXPos, int userYPos, int moves) {
    if (userXPos < 0 || userXPos >= numRows) {
        xPos = 0;
        std::cout << "Row position out of range. Row position has been set equal to 0. Please reassign row position to a number "
            << "between 0 and 19." << std::endl;
    }
    if (userYPos < 0 || userYPos >= numCols) {
        yPos = 0;
        std::cout << "Column position out of range. Column position has been set equal to 0. Please reassign column position to a number "
            << "between 0 and 19." << std::endl;
    }
    if (moves < 0) {
        numMoves = 0;
        std::cout << "The number of moves was less than 0 which is impossible. Please reassign the number of moves." << std::endl;
    }
}
int Organism::getXPos() const {
    return xPos;
}
int Organism::getYPos() const {
    return yPos;
}
int Organism::getNumMoves() const {
    return numMoves;
}
char Organism::getSymb() const {
    return symb;
}
void Organism::setXPos(int xPosition) {
    xPos = xPosition;
}
void Organism::setYPos(int yPosition) {
    yPos = yPosition;
}
void Organism::setMoves(int userNumMoves) {
    numMoves = userNumMoves;
}
void Organism::setSymb(char userSymb) {
    symb = userSymb;
}

std::ostream& operator<<(std::ostream& outs, const Organism& bug) {
    outs << bug.symb;
    return outs;
}


////Class Defintion for Ants
Ant::Ant() : Organism() { setSymb('o'); }
Ant::Ant(int userXPos) : Organism(userXPos) { setSymb('o'); }
Ant::Ant(int userXPos, int userYPos) : Organism(userXPos, userYPos) { setSymb('o'); }
Ant::Ant(int userXPos, int userYPos, int moves) : Organism(userXPos, userYPos, moves) { setSymb('o'); }
std::ostream& operator <<(std::ostream& outs, const Ant& bug) {
    outs << bug.getSymb();
    return outs;
}

///////Class Defintion for Doodlebug

Doodlebug::Doodlebug() : Organism() { setSymb('X'); }
Doodlebug::Doodlebug(int userXPos) : Organism(userXPos) { setSymb('X'); }
Doodlebug::Doodlebug(int userXPos, int userYPos) : Organism(userXPos, userYPos) { setSymb('X'); }
Doodlebug::Doodlebug(int userXPos, int userYPos, int moves) : Organism(userXPos, userYPos, moves) { setSymb('X'); }
std::ostream& operator <<(std::ostream& outs, const Doodlebug& bug) {
    outs << bug.getSymb();
    return outs;
}


/// Non-member fucntion Definition list

void createBaseGrid(Organism* orgArrPtr[][numCols]) {
    //creates a 2D array of organism objects
    //creates a copy of the pointer, but the pointer still points to the same memory addresses
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            orgArrPtr[i][j] = new Organism(i, j);
        }
    }
}

void createPlayableGrid(Organism* orgArrPtr[][numCols]) {
    //sets the Ants and Doodlebugs on the Grid
    //creates a copy of the pointer, but the pointer still points to the same memeory addresses
    std::srand(std::time(nullptr));
    int bugCount = 0;
    while (bugCount < maxBugs) {
        int xLoc = std::rand() % 4;
        int yLoc = std::rand() % 4;
        if (orgArrPtr[xLoc][yLoc]->getSymb() == '-') {
            delete orgArrPtr[xLoc][yLoc];
            orgArrPtr[xLoc][yLoc] = nullptr;
            if (bugCount < maxAnts) {
                orgArrPtr[xLoc][yLoc] = new Ant(xLoc, yLoc);
            }
            else {
                orgArrPtr[xLoc][yLoc] = new Doodlebug(xLoc, yLoc);
            }
            bugCount++;
        }
        else {
            continue;
        }
    }
}

void printGrid(Organism* orgArrPtr[][numCols]) {
    // current print array function
    //creates a copy of the pointer, but the pointer still points to the same memory addresses
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << *orgArrPtr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void deleteGrid(Organism* orgArrPtr[][numCols]) {
    //deletes memory element wise, sets elements to nullptr, then deletes the array
    //creates a copy of the pointer, but the pointer still points to the same memory addresses
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            delete orgArrPtr[i][j];
            orgArrPtr[i][j] = nullptr;
        }
    }
}