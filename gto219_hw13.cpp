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
    void newPos(int& newXLoc, int& newYLoc);

public:
    Organism();
    Organism(int userXPos);
    Organism(int userXPos, int userYPos);
    Organism(int userXPos, int userYPos, int moves);
    Organism(const Organism& bug);
    int getXPos() const;
    int getYPos() const;
    int getNumMoves() const;
    char getSymb() const;
    void setXPos(int xPosition);
    void setYPos(int yPosition);
    void setMoves(int userNumMoves);
    void setSymb(char userSymb); //i only want the derived classes using it so should it be protected instead?
    virtual void Move(Organism* orgArrPtr[][numCols]);//still trying to figure out what the parameters should be
    friend std::ostream& operator<<(std::ostream& outs, const Organism& bug);

};

class Ant : public Organism {
private:
    void newPos(int& newXLoc, int& newYLoc);
public:
    Ant();
    Ant(int userXPos);
    Ant(int userXPos, int userYPos);
    Ant(int userXPos, int userYPos, int moves);
    Ant(Organism bug);
    void Move(Organism* orgArrPtr[][numCols]);
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
    
    int maxNumMoves = 1;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (orgArrPtr[i][j]->getSymb() == 'o' && orgArrPtr[i][j]->getNumMoves() < maxNumMoves) {
                orgArrPtr[i][j]->Move(orgArrPtr);
            }
        }
    }
    printGrid(orgArrPtr);

    deleteGrid(orgArrPtr);


}

//Class defintions

void Organism::newPos(int& newXLoc, int& newYLoc) {
    //do nothing
}


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
Organism::Organism(int userXPos, int userYPos) :xPos(userXPos), yPos(userYPos) {
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
Organism::Organism(int userXPos, int userYPos, int moves) : xPos(userXPos), yPos(userYPos), numMoves(moves) {
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
Organism::Organism(const Organism& bug) {
    xPos = bug.xPos;
    yPos = bug.yPos;
    numMoves = bug.numMoves;
    //may include copying the symbol as well
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

void Organism::Move(Organism* orgArrPtr[][numCols]) {
    //do nothing. I do not want the '-' to move
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
Ant::Ant(Organism bug) : Organism(bug) { setSymb('o'); }

void Ant::newPos(int& newXLoc, int& newYLoc) {
    const int numOptionsPlus1 = 4;
    int randNum = std::rand() % numOptionsPlus1;
    switch (randNum) {
    case 0:
        //up movement
        newXLoc--;
        break;
    case 1:
        //down movement
        newXLoc++;
        break;
    case 2:
        //left movement
        newYLoc--;
        break;
    case 3:
        //rigth movement
        newYLoc++;
        break;
    default:
        //no change in postion
        std::cout << "No position change." << std::endl;
    }
}


void Ant::Move(Organism* orgArrPtr[][numCols]) {
    
    int xLoc = this->getXPos();
    int yLoc = this->getYPos();
    int newXLoc = xLoc;
    int newYLoc = yLoc;

    newPos(newXLoc, newYLoc);
    
    if ((newXLoc < 0 || newXLoc >= numRows) || (newYLoc < 0 || newYLoc >= numCols)) {
        //new position out of grid
        //do nothing
        std::cout << "noGrid" << std::endl;
    }
    else if (orgArrPtr[newXLoc][newYLoc]->getSymb() != '-') {
        //position occupied
        //do nothing
        std::cout << "posOcc" << std::endl;
    }
    else {
        Organism* temp = new Ant(*orgArrPtr[xLoc][yLoc]);
        Organism* temp2 = new Organism(*orgArrPtr[newXLoc][newYLoc]);
        temp->setXPos(newXLoc);
        temp->setYPos(newYLoc);
        temp->setMoves(getNumMoves() + 1);
        temp2->setXPos(xLoc);
        temp2->setYPos(yLoc);

        delete orgArrPtr[xLoc][yLoc];
        delete orgArrPtr[newXLoc][newYLoc];
        orgArrPtr[xLoc][yLoc] = temp2;
        orgArrPtr[newXLoc][newYLoc] = temp;
        
    }
}
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
        int xLoc = std::rand() % numRows;
        int yLoc = std::rand() % numCols;
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