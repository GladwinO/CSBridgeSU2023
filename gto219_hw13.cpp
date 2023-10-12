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
const int stepsBreed = 3;

class Organism {
private:
    int xPos = 0;
    int yPos = 0;
    int numMoves = 0;
    int timeSteps = 0;
    char symb = '-';
    

public:
    Organism();
    Organism(int userXPos);
    Organism(int userXPos, int userYPos);
    Organism(int userXPos, int userYPos, int moves);
    Organism(int userXPos, int userYPos, int moves, int userTimeSteps);
    Organism(const Organism& bug);
    int getXPos() const;
    int getYPos() const;
    int getNumMoves() const;
    int getTimeSteps() const;
    virtual int getTimesEaten();
    char getSymb() const;
    void setXPos(int xPosition);
    void setYPos(int yPosition);
    void setTimeSteps(int userTimeSteps);
    void setMoves(int userNumMoves);
    void setSymb(char userSymb); //i only want the derived classes using it so should it be protected instead?
    virtual void setTimesEaten(int numEaten);
    virtual void newPos(int& newXLoc, int& newYLoc);
    virtual void Move(Organism* orgArrPtr[][numCols]);
    virtual void Breed(Organism* orgArrPtr[][numCols]);
    friend std::ostream& operator<<(std::ostream& outs, const Organism& bug);

};

class Ant : public Organism {
private:
    void newPos(int& newXLoc, int& newYLoc);
    void Breed(Organism* orgArrPtr[][numCols]);
public:
    Ant();
    Ant(int userXPos);
    Ant(int userXPos, int userYPos);
    Ant(int userXPos, int userYPos, int moves);
    Ant(int userXPos, int userYPos, int moves, int userTimeSteps);
    Ant(Organism bug);
    void Move(Organism* orgArrPtr[][numCols]);
    //void Breed(Organism* orgArrPtr[][numCols]);
    friend std::ostream& operator <<(std::ostream& outs, const Ant& bug);
};

class Doodlebug : public Organism {
    int timesEaten = 0;
    void newPos(int& newXLoc, int& newYLoc);
public:
    Doodlebug();
    Doodlebug(int userXPos);
    Doodlebug(int userXPos, int userYPos);
    Doodlebug(int userXPos, int userYPos, int moves);
    Doodlebug(int userXPos, int userYPos, int moves, int numEaten);
    Doodlebug(Organism bug, int numEaten);
    int getTimesEaten() const;
    void setTimesEaten(int numEaten);
    void Move(Organism* orgArrPtr[][numCols]);
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

    int maxTimeSteps = 1;
    for (int m = 0; m < 6; m++) {
        
        for (int k = 0; k < numRows; k++) {
            for (int l = 0; l < numCols; l++) {
                if (orgArrPtr[k][l]->getSymb() == 'X' && orgArrPtr[k][l]->getTimeSteps() < maxTimeSteps) {
                    orgArrPtr[k][l]->Move(orgArrPtr);
                }
            }
        }

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (orgArrPtr[i][j]->getSymb() == 'o' && orgArrPtr[i][j]->getTimeSteps() < maxTimeSteps) {
                    orgArrPtr[i][j]->Move(orgArrPtr);
                    
                    
                }
            }
        }
        maxTimeSteps++;


        printGrid(orgArrPtr);
    }
    /*int maxTimeSteps = 1;
    for (int k = 0; k < numRows; k++) {
        for (int l = 0; l < numCols; l++) {
            if (orgArrPtr[k][l]->getSymb() == 'X' && orgArrPtr[k][l]->getTimeSteps() < maxTimeSteps) {
                orgArrPtr[k][l]->Move(orgArrPtr);
            }
        }
    }
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (orgArrPtr[i][j]->getSymb() == 'o' && orgArrPtr[i][j]->getTimeSteps() < maxTimeSteps) {
                orgArrPtr[i][j]->Move(orgArrPtr);
                orgArrPtr[i][j]->Breed(orgArrPtr);
            }
        }
    }
    maxTimeSteps++;
    

    printGrid(orgArrPtr);*/

    deleteGrid(orgArrPtr);


}

//Class defintions

void Organism::newPos(int& newXLoc, int& newYLoc) {
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
Organism::Organism(int userXPos, int userYPos, int moves, int userTimeSteps) : xPos(userXPos), yPos(userYPos), numMoves(moves), timeSteps(userTimeSteps) {
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
    if (timeSteps < 0) {
        timeSteps = 0;
        std::cout << "The number of moves was less than 0 which is impossible. Please reassign the number of moves." << std::endl;
    }

}
Organism::Organism(const Organism& bug) {
    xPos = bug.xPos;
    yPos = bug.yPos;
    numMoves = bug.numMoves;
    timeSteps = bug.timeSteps;
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
int Organism::getTimeSteps() const {
    return timeSteps;
}
char Organism::getSymb() const {
    return symb;
}
int Organism::getTimesEaten() {
    //do nothing
    return 0;
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
void Organism::setTimeSteps(int userTimeSteps) {
    timeSteps = userTimeSteps;
}
void Organism::setSymb(char userSymb) {
    symb = userSymb;
}
void Organism::setTimesEaten(int numEaten) {
    //do nothing;
}

void Organism::Move(Organism* orgArrPtr[][numCols]) {
    //do nothing. I do not want the '-' to move
}

void Organism::Breed(Organism* orgArrPtr[][numCols]) {
    //do nothing. I do not want '-' to breed
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
Ant::Ant(int userXPos, int userYPos, int moves, int userTimeSteps) : Organism(userXPos, userYPos, moves, userTimeSteps) { setSymb('o'); }
Ant::Ant(Organism bug) : Organism(bug) { setSymb('o'); }

void Ant::newPos(int& newXLoc, int& newYLoc) {
    Organism::newPos(newXLoc, newYLoc);
}


void Ant::Move(Organism* orgArrPtr[][numCols]) {

    int xLoc = this->getXPos();
    int yLoc = this->getYPos();
    int newXLoc = xLoc;
    int newYLoc = yLoc;

    newPos(newXLoc, newYLoc);

    if ((newXLoc < 0 || newXLoc >= numRows) || (newYLoc < 0 || newYLoc >= numCols)) {
        //new position out of grid
        this->setTimeSteps(getTimeSteps() + 1);
        std::cout << orgArrPtr[xLoc][yLoc]->getTimeSteps() << " (" << xLoc << "," << yLoc << ")" << std::endl; //for testing

        std::cout << "noGrid" << std::endl; /// will need to get rid of this
    }
    else if (orgArrPtr[newXLoc][newYLoc]->getSymb() != '-') {
        //position occupied
        this->setTimeSteps(getTimeSteps() + 1);
        std::cout << orgArrPtr[xLoc][yLoc]->getTimeSteps() << " (" << xLoc << "," << yLoc << ")" << std::endl;
        orgArrPtr[xLoc][yLoc]->Breed(orgArrPtr);

        std::cout << "posOcc" << std::endl; ///will need to get rid of this
    }
    else {
        Organism* temp = new Ant(*orgArrPtr[xLoc][yLoc]);
        Organism* temp2 = new Organism(*orgArrPtr[newXLoc][newYLoc]);
        temp->setXPos(newXLoc);
        temp->setYPos(newYLoc);
        temp->setMoves(getNumMoves() + 1);
        temp->setTimeSteps(getTimeSteps() + 1);
        temp2->setXPos(xLoc);
        temp2->setYPos(yLoc);

        delete orgArrPtr[xLoc][yLoc];
        delete orgArrPtr[newXLoc][newYLoc];
        orgArrPtr[xLoc][yLoc] = temp2;
        orgArrPtr[newXLoc][newYLoc] = temp;
        std::cout << orgArrPtr[newXLoc][newYLoc]->getTimeSteps() << " (" << newXLoc << "," << newYLoc << ")" << std::endl;
        orgArrPtr[newXLoc][newYLoc]->Breed(orgArrPtr);

    }
    
    
}

void Ant::Breed(Organism* orgArrPtr[][numCols]) {
    int xLoc = this->getXPos();
    int yLoc = this->getYPos();
    int newXLoc = xLoc;
    int newYLoc = yLoc;
    int isBred = false;
    
    if (this->getTimeSteps() > 0 && this->getTimeSteps() % stepsBreed == 0) {
        if ((newXLoc - 1) >= 0 && (newXLoc - 1) < numRows) {
            //breed up
            if (orgArrPtr[newXLoc - 1][newYLoc]->getSymb() == '-' && isBred == false) {
                newXLoc--;
                Organism* temp = new Ant(newXLoc, newYLoc);
                temp->setTimeSteps(this->getTimeSteps());
                delete orgArrPtr[newXLoc][newYLoc];
                orgArrPtr[newXLoc][newYLoc] = temp;
                isBred = true;
            }
        }
        if ((newXLoc + 1) >= 0 && (newXLoc + 1) < numRows) {
            //breed down
            if (orgArrPtr[newXLoc + 1][newYLoc]->getSymb() == '-' && isBred == false) {
                newXLoc++;
                Organism* temp = new Ant(newXLoc, newYLoc);
                delete orgArrPtr[newXLoc][newYLoc];
                orgArrPtr[newXLoc][newYLoc] = temp;
                isBred = true;
            }
        }
        if ((newYLoc - 1) >= 0 && (newYLoc - 1) < numCols) {
            //breed left
            if (orgArrPtr[newXLoc][newYLoc - 1]->getSymb() == '-' && isBred == false) {
                newYLoc--;
                Organism* temp = new Ant(newXLoc, newYLoc);
                delete orgArrPtr[newXLoc][newYLoc];
                orgArrPtr[newXLoc][newYLoc] = temp;
                isBred = true;
            }
        }
        if ((newYLoc + 1) >= 0 && (newYLoc + 1) < numCols) {
            //breed right
            if (orgArrPtr[newXLoc][newYLoc + 1]->getSymb() == '-' && isBred == false) {
                newYLoc++;
                Organism* temp = new Ant(newXLoc, newYLoc);
                delete orgArrPtr[newXLoc][newYLoc];
                orgArrPtr[newXLoc][newYLoc] = temp;
                isBred = true;
            }
        }
        
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
Doodlebug::Doodlebug(int userXPos, int userYPos, int moves, int numEaten) :Organism(userXPos, userYPos, moves), timesEaten(numEaten) { setSymb('X'); }
Doodlebug::Doodlebug(Organism bug, int numEaten) : Organism(bug), timesEaten(numEaten) { setSymb('X'); }
int Doodlebug::getTimesEaten() const {
    return timesEaten;
}
void Doodlebug::setTimesEaten(int numEaten) {
    timesEaten = numEaten;
}

void Doodlebug::newPos(int& newXLoc, int& newYLoc) {
    Organism::newPos(newXLoc, newYLoc);
}
void Doodlebug::Move(Organism* orgArrPtr[][numCols]) {
    int xLoc = this->getXPos();
    int yLoc = this->getYPos();
    int newXLoc = xLoc;
    int newYLoc = yLoc;

    newPos(newXLoc, newYLoc);

    if ((newXLoc < 0 || newXLoc >= numRows) || (newYLoc < 0 || newYLoc >= numCols)) {
        //new position out of grid
        this->setTimeSteps(getTimeSteps() + 1);

        std::cout << "noGrid" << std::endl; /// will need to get rid of this
    }
    else if (orgArrPtr[newXLoc][newYLoc]->getSymb() == 'X') {
        //position occupied by another Doodlebug
        this->setTimeSteps(getTimeSteps() + 1);

        std::cout << "posOccByDood" << std::endl; ///will need to get rid of this
    }
    else if (orgArrPtr[newXLoc][newYLoc]->getSymb() == 'o') {
        Organism* temp = new Doodlebug(*orgArrPtr[xLoc][yLoc], orgArrPtr[xLoc][yLoc]->getTimesEaten());
        Organism* temp2 = new Organism(*orgArrPtr[newXLoc][newYLoc]);
        temp->setXPos(newXLoc);
        temp->setYPos(newYLoc);
        temp->setMoves(getNumMoves() + 1);
        temp->setTimeSteps(getTimeSteps() + 1);
        temp->setTimesEaten(getTimesEaten() + 1);
        temp2->setXPos(xLoc);
        temp2->setYPos(yLoc);

        delete orgArrPtr[xLoc][yLoc];
        delete orgArrPtr[newXLoc][newYLoc];
        orgArrPtr[xLoc][yLoc] = temp2;
        orgArrPtr[newXLoc][newYLoc] = temp;
    }
    else{
        Organism* temp = new Doodlebug(*orgArrPtr[xLoc][yLoc], orgArrPtr[xLoc][yLoc]->getTimesEaten());
        Organism* temp2 = new Organism(*orgArrPtr[newXLoc][newYLoc]);
        temp->setXPos(newXLoc);
        temp->setYPos(newYLoc);
        temp->setMoves(getNumMoves() + 1);
        temp->setTimeSteps(getTimeSteps() + 1);
        temp2->setXPos(xLoc);
        temp2->setYPos(yLoc);

        delete orgArrPtr[xLoc][yLoc];
        delete orgArrPtr[newXLoc][newYLoc];
        orgArrPtr[xLoc][yLoc] = temp2;
        orgArrPtr[newXLoc][newYLoc] = temp;

    }
}
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