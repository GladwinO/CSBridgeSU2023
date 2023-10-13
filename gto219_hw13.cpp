// gto219_hw13.cpp:

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//area for const variables
//allows for various testing regimes wihtout having to go into every function
const int numRows = 20;
const int numCols = 20;
const int maxAnts = 100;
const int maxDoodleBugs = 5;
const int maxBugs = maxAnts + maxDoodleBugs;
const int stepsAntBreed = 3;
const int stepsDoodlebugBreed = 8;
const int maxTimeStarvedDoodlebug = 3;

class Organism {
private:
    int xPos = 0; //used to keep track of x position
    int yPos = 0; //used to keep track of y position
    int timeSteps = 0; //used to keep track of number of timesteps of the entire game
    char symb = '-'; //used to set the representation of an organism


public:
    Organism();
    Organism(int userXPos);
    Organism(int userXPos, int userYPos);
    Organism(int userXPos, int userYPos, int userTimeSteps);
    Organism(const Organism& bug);
    int getXPos() const;
    int getYPos() const;
    int getTimeSteps() const;
    virtual int getLastTimeEaten();
    char getSymb() const;
    void setXPos(int xPosition);
    void setYPos(int yPosition);
    void setTimeSteps(int userTimeSteps);
    void setSymb(char userSymb);
    virtual void setLastTimeEaten(int numLastTimeEaten);
    virtual void newPos(int& newXLoc, int& newYLoc);
    virtual void Move(Organism* orgArrPtr[][numCols]);
    virtual void Breed(Organism* orgArrPtr[][numCols]);
    virtual bool Starve(Organism* orgArrPtr[][numCols]);
    friend std::ostream& operator<<(std::ostream& outs, const Organism& bug);

};

class Ant : public Organism {
private:
    void newPos(int& newXLoc, int& newYLoc);
    void suppBreedFunc(Organism* orgArrPtr[][numCols], int& newXLoc, int& newYLoc);
    void Breed(Organism* orgArrPtr[][numCols]);
public:
    Ant();
    Ant(int userXPos);
    Ant(int userXPos, int userYPos);
    Ant(int userXPos, int userYPos, int userTimeSteps);
    Ant(Organism bug);
    void Move(Organism* orgArrPtr[][numCols]);
    friend std::ostream& operator <<(std::ostream& outs, const Ant& bug);
};

class Doodlebug : public Organism {
    int timeSinceLastEaten = 0; //keeps track of time since a doodlebug object moved into a poistion that was occupied by an ant object
    void newPos(int& newXLoc, int& newYLoc);
    void suppBreedFunc(Organism* orgArrPtr[][numCols], int& newXLoc, int& newYLoc);
    void Breed(Organism* orgArrPtr[][numCols]);
    bool Starve(Organism* orgArrPtr[][numCols]);
public:
    Doodlebug();
    Doodlebug(int userXPos);
    Doodlebug(int userXPos, int userYPos);
    Doodlebug(int userXPos, int userYPos, int numSinceLastEaten);
    Doodlebug(Organism bug, int numSinceLastEaten);
    int getLastTimeEaten() const;
    void setLastTimeEaten(int numSinceLastEaten);
    void Move(Organism* orgArrPtr[][numCols]);
    friend std::ostream& operator <<(std::ostream& outs, const Doodlebug& bug);
};

/// non-member functions declaration list
void createBaseGrid(Organism* orgArrPtr[][numCols]);

void createPlayableGrid(Organism* orgArrPtr[][numCols]);

void printGrid(Organism* orgArrPtr[][numCols]);

void runGame(Organism* orgArrPtr[][numCols]);

void deleteGrid(Organism* orgArrPtr[][numCols]);


int main()
{
    Organism* orgArrPtr[numRows][numCols];
    createBaseGrid(orgArrPtr);
    createPlayableGrid(orgArrPtr); //the initial Grid is generated using random position based on current computer time. To test a single scenario comment that code out in this function
    std::cout << "World at time 0:\n" << std::endl;
    printGrid(orgArrPtr);
    std::cout << "Press ENTER to continue\n" << std::endl;
    runGame(orgArrPtr);
    deleteGrid(orgArrPtr);


}

//Class defintions

void Organism::newPos(int& newXLoc, int& newYLoc) {
    //determines the possible x and y coordinate of an objects new position could be 
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
    //not used but created just for completion sake
    if (userXPos < 0 || userXPos >= numRows) {
        xPos = 0;
        std::cout << "Row position out of range. Row position has been set equal to 0. Please reassign row position to a number "
            << "between 0 and 19." << std::endl;
    }
}
Organism::Organism(int userXPos, int userYPos) :xPos(userXPos), yPos(userYPos) {
    //will take an x and y position and will construct an organims object based on that information
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
Organism::Organism(int userXPos, int userYPos, int userTimeSteps) : xPos(userXPos), yPos(userYPos), timeSteps(userTimeSteps) {
    //will take an x, y position, and number of timeSteps of the game and construct an organims object based on that information
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
    if (timeSteps < 0) {
        timeSteps = 0;
        std::cout << "The number of moves was less than 0 which is impossible. Please reassign the number of moves." << std::endl;
    }

}
Organism::Organism(const Organism& bug) {
    //necessary copy constructor creating a new organims object in the move function
    //a new organism is created on the heap and assigned to a new location in the grid
    //the new organism will be created using the constructor ex: Organism* temp = new Organism(derefrenced organism pointer);
    xPos = bug.xPos;
    yPos = bug.yPos;
    timeSteps = bug.timeSteps;

}
int Organism::getXPos() const {
    //used to get x position
    return xPos;
}
int Organism::getYPos() const {
    //used to get y position
    return yPos;
}
int Organism::getTimeSteps() const {
    //used to get timesteps
    return timeSteps;
}
char Organism::getSymb() const {
    //used to get object representation symbol
    return symb;
}
int Organism::getLastTimeEaten() {
    //do nothing
    //created as virtual function for the Doodlebug derived class
    /*when moving, breeding, and starving the compiler assumes that the Organism pointer is pointing to a
    organism object so this fucntion was created and labeled virtual so that when it is called on a doodlebug
    object it will execute the doodblebug getLastTimeEaten code that has been defined*/
    return 0;
}
void Organism::setXPos(int xPosition) {
    //set the x position
    xPos = xPosition;
}
void Organism::setYPos(int yPosition) {
    //set the y position
    yPos = yPosition;
}
void Organism::setTimeSteps(int userTimeSteps) {
    //set the number of timesteps, however the code never changes the timesteps for Organism objects
    timeSteps = userTimeSteps;
}
void Organism::setSymb(char userSymb) {
    //set the representation symbol, used for changing the symbol for Ant and Doodlebug derived class
    symb = userSymb;
}
void Organism::setLastTimeEaten(int numLastTimeEaten) {
    //do nothing 
    //Organism does not have this member variable so it was only created virtually so that doodlebug objects that are 
    //pointed to by Organism pointers can call this function from the Doodlebug derived class
}

void Organism::Move(Organism* orgArrPtr[][numCols]) {
    //do nothing. I do not want the '-' to move
    //created so that the Ant and Doodlebug objects can call their move classes through polymorphism
}

void Organism::Breed(Organism* orgArrPtr[][numCols]) {
    //do nothing. I do not want '-' to breed
    //created so that the Ant and Doodlebug objects can call their breed classes through polymorphism
}
bool Organism::Starve(Organism* orgArrPtr[][numCols]) {
    //do nothing. I do not want '-' to starve
    //created so that Doodlebug objects can call the starve class through polymorphism
    return false;
}

std::ostream& operator<<(std::ostream& outs, const Organism& bug) {
    //will send to the console an organism objects representation symbol 
    outs << bug.symb;
    return outs;
}


////Class Defintion for Ants
Ant::Ant() : Organism() { setSymb('o'); }
Ant::Ant(int userXPos) : Organism(userXPos) { setSymb('o'); }
Ant::Ant(int userXPos, int userYPos) : Organism(userXPos, userYPos) { setSymb('o'); }
Ant::Ant(int userXPos, int userYPos, int userTimeSteps) : Organism(userXPos, userYPos, userTimeSteps) { setSymb('o'); }
Ant::Ant(Organism bug) : Organism(bug) { setSymb('o'); }

void Ant::newPos(int& newXLoc, int& newYLoc) {
    //determines the possible x and y coordinate of an objects new position could be 
    Organism::newPos(newXLoc, newYLoc);
}


void Ant::Move(Organism* orgArrPtr[][numCols]) {
    /*will take the current object's postion, choose a random possible position it could move to using newPos,
    then it will check to see if the possible new postion is on the grid and is "empty" empty means an objects
    symbol variable = '-'*/
    /*even if the object does not move, it must keep track of how many timesteps have pased and must breed after
    a certain number of time steps. If it does move a newly created base organism will fill its old spot, since their 
    symbol is automatically '-', and the new position will filled with a newly created Ant organism that copies all 
    of the old ants information useing the copy constructor. Then when the Ant has moved been alive for a predetermined
    number of timesteps it will breed*/
    int xLoc = this->getXPos();
    int yLoc = this->getYPos();
    int newXLoc = xLoc;
    int newYLoc = yLoc;

    newPos(newXLoc, newYLoc);

    if ((newXLoc < 0 || newXLoc >= numRows) || (newYLoc < 0 || newYLoc >= numCols)) {
        //new position out of grid
        this->setTimeSteps(getTimeSteps() + 1);
        orgArrPtr[xLoc][yLoc]->Breed(orgArrPtr);
    }
    else if (orgArrPtr[newXLoc][newYLoc]->getSymb() != '-') {
        //position occupied
        this->setTimeSteps(getTimeSteps() + 1);
        orgArrPtr[xLoc][yLoc]->Breed(orgArrPtr);
    }
    else {
        Organism* temp = new Ant(*orgArrPtr[xLoc][yLoc]);
        Organism* temp2 = new Organism(*orgArrPtr[newXLoc][newYLoc]);
        temp->setXPos(newXLoc);
        temp->setYPos(newYLoc);
        temp->setTimeSteps(getTimeSteps() + 1);
        temp2->setXPos(xLoc);
        temp2->setYPos(yLoc);

        delete orgArrPtr[xLoc][yLoc];
        delete orgArrPtr[newXLoc][newYLoc];
        orgArrPtr[xLoc][yLoc] = temp2;
        orgArrPtr[newXLoc][newYLoc] = temp;
        orgArrPtr[newXLoc][newYLoc]->Breed(orgArrPtr);

    }


}

void Ant::suppBreedFunc(Organism* orgArrPtr[][numCols], int& newXLoc, int& newYLoc) {
    //this is a supportive function for the breed function
    /*here the actually "breeding" occurs where a every adjacent side of an Ant object is teseted to be in the 
    grid and "empty". Every position up, down, left, and right is tested in that order. There is no randomness 
    to the possible breeding direction. This was done to decrease runtime, that would have been higher if every 
    adjacent position was tested randomly. Of course this means if up is always free then an organism will 
    always "breed" into the position directly above it*/

    // newXLoc and newYLoc test if position is in grid
    //isBred is used to skip every other adjacent position is one adjacent position has been bred into
    /*the new ant object will copy the number of timesteps from the parent because the runGame function
    limits the number of times an object can move each run by comparing it to the current maxTimeSteps.
    Assigning new objects with the parent timeStep prevents the new object from moving withing the same timestep*/
    bool isBred = false;
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
            temp->setTimeSteps(this->getTimeSteps());
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
            temp->setTimeSteps(this->getTimeSteps());
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
            temp->setTimeSteps(this->getTimeSteps());
            delete orgArrPtr[newXLoc][newYLoc];
            orgArrPtr[newXLoc][newYLoc] = temp;
            isBred = true;
        }
    }
}

void Ant::Breed(Organism* orgArrPtr[][numCols]) {
    //most of the code is in suppBreedFunc
    //this is done to check that after a certain number of steps, here it is stepsAntBreed, the object will be ready to breed
    int xLoc = this->getXPos();
    int yLoc = this->getYPos();
    int newXLoc = xLoc;
    int newYLoc = yLoc;

    if (this->getTimeSteps() > 0 && this->getTimeSteps() % stepsAntBreed == 0) {
        suppBreedFunc(orgArrPtr, newXLoc, newYLoc);
    }
}

std::ostream& operator <<(std::ostream& outs, const Ant& bug) {
    //will read to console the symbol associated with ant objects = 'o'
    outs << bug.getSymb();
    return outs;
}

///////Class Defintion for Doodlebug

Doodlebug::Doodlebug() : Organism() { setSymb('X'); setLastTimeEaten(0); }
Doodlebug::Doodlebug(int userXPos) : Organism(userXPos) { setSymb('X'); setLastTimeEaten(0); }
Doodlebug::Doodlebug(int userXPos, int userYPos) : Organism(userXPos, userYPos) { setSymb('X'); setLastTimeEaten(0); }
Doodlebug::Doodlebug(int userXPos, int userYPos, int numSinceLastEaten) :Organism(userXPos, userYPos), timeSinceLastEaten(numSinceLastEaten) { setSymb('X'); }
Doodlebug::Doodlebug(Organism bug, int numSinceLastEaten) : Organism(bug), timeSinceLastEaten(numSinceLastEaten) { setSymb('X'); }
int Doodlebug::getLastTimeEaten() const {
    //will return the number of timesteps since the doodlebug object last replaced a grid postion that was occupied by an ant object
    return timeSinceLastEaten;
}
void Doodlebug::setLastTimeEaten(int numSinceLastEaten) {
    //can set the number of timesteps since the doodlebug object last replaced a grid postion that was occupied by an ant object
    timeSinceLastEaten = numSinceLastEaten;
}

void Doodlebug::newPos(int& newXLoc, int& newYLoc) {
    //used to find a possible random location for the object to move to
    Organism::newPos(newXLoc, newYLoc);
}

void Doodlebug::Move(Organism* orgArrPtr[][numCols]) {
    /*does the same thing was the ant object, however it will only move into grid positions occupied by Organism and 
    Ant objects (symbol = '-' or 'o') and now everytime a timestep passes, completely unaffected by if
    the doodlebug object moves or not the timeSinceLastEaten will increase. The timeSinceLastEaten will get set
    back to zero when a doodlebug object moves into a poistion that was occupied by an ant "consumes the ant"
    There is a check from the starve function which checks if the doodlebug object has not eaten within after
    a set number of time steps then the doodblebug object will be replaced with an Organims object( the doodlebug dies)*/

    int xLoc = this->getXPos();
    int yLoc = this->getYPos();
    int newXLoc = xLoc;
    int newYLoc = yLoc;
    bool isStarved = false;

    newPos(newXLoc, newYLoc);

    if ((newXLoc < 0 || newXLoc >= numRows) || (newYLoc < 0 || newYLoc >= numCols)) {
        //new position out of grid
        this->setTimeSteps(getTimeSteps() + 1);
        this->setLastTimeEaten(getLastTimeEaten() + 1);
        isStarved = this->Starve(orgArrPtr);
        if (isStarved = false) {
            orgArrPtr[xLoc][yLoc]->Breed(orgArrPtr);
        }
    }
    else if (orgArrPtr[newXLoc][newYLoc]->getSymb() == 'X') {
        //position occupied by another Doodlebug
        this->setTimeSteps(getTimeSteps() + 1);
        this->setLastTimeEaten(getLastTimeEaten() + 1);
        isStarved = this->Starve(orgArrPtr);
        if (isStarved = false) {
            orgArrPtr[xLoc][yLoc]->Breed(orgArrPtr);
        }
    }
    else if (orgArrPtr[newXLoc][newYLoc]->getSymb() == 'o') {
        Organism* temp = new Doodlebug(*orgArrPtr[xLoc][yLoc], orgArrPtr[xLoc][yLoc]->getLastTimeEaten());
        Organism* temp2 = new Organism(*orgArrPtr[newXLoc][newYLoc]);
        temp->setXPos(newXLoc);
        temp->setYPos(newYLoc);
        temp->setTimeSteps(getTimeSteps() + 1);
        temp->setLastTimeEaten(0);
        temp2->setXPos(xLoc);
        temp2->setYPos(yLoc);

        delete orgArrPtr[xLoc][yLoc];
        delete orgArrPtr[newXLoc][newYLoc];
        orgArrPtr[xLoc][yLoc] = temp2;
        orgArrPtr[newXLoc][newYLoc] = temp;
        orgArrPtr[newXLoc][newYLoc]->Breed(orgArrPtr);
    }
    else {
        Organism* temp = new Doodlebug(*orgArrPtr[xLoc][yLoc], orgArrPtr[xLoc][yLoc]->getLastTimeEaten());
        Organism* temp2 = new Organism(*orgArrPtr[newXLoc][newYLoc]);
        temp->setXPos(newXLoc);
        temp->setYPos(newYLoc);
        temp->setTimeSteps(getTimeSteps() + 1);
        temp->setLastTimeEaten(getLastTimeEaten() + 1);
        temp2->setXPos(xLoc);
        temp2->setYPos(yLoc);

        delete orgArrPtr[xLoc][yLoc];
        delete orgArrPtr[newXLoc][newYLoc];
        orgArrPtr[xLoc][yLoc] = temp2;
        orgArrPtr[newXLoc][newYLoc] = temp;
        isStarved = orgArrPtr[newXLoc][newYLoc]->Starve(orgArrPtr);
        if (isStarved = false) {
            orgArrPtr[newXLoc][newYLoc]->Breed(orgArrPtr);
        }

    }
}

void Doodlebug::suppBreedFunc(Organism* orgArrPtr[][numCols], int& newXLoc, int& newYLoc) {
    //works the same way the supportive breed function for the Ant class works, now it creates a Doodlebug object instead of an Ant object
    bool isBred = false;
    if ((newXLoc - 1) >= 0 && (newXLoc - 1) < numRows) {
        //breed up
        if (orgArrPtr[newXLoc - 1][newYLoc]->getSymb() == '-' && isBred == false) {
            newXLoc--;
            Organism* temp = new Doodlebug(newXLoc, newYLoc);
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
            Organism* temp = new Doodlebug(newXLoc, newYLoc);
            temp->setTimeSteps(this->getTimeSteps());
            delete orgArrPtr[newXLoc][newYLoc];
            orgArrPtr[newXLoc][newYLoc] = temp;
            isBred = true;
        }
    }
    if ((newYLoc - 1) >= 0 && (newYLoc - 1) < numCols) {
        //breed left
        if (orgArrPtr[newXLoc][newYLoc - 1]->getSymb() == '-' && isBred == false) {
            newYLoc--;
            Organism* temp = new Doodlebug(newXLoc, newYLoc);
            temp->setTimeSteps(this->getTimeSteps());
            delete orgArrPtr[newXLoc][newYLoc];
            orgArrPtr[newXLoc][newYLoc] = temp;
            isBred = true;
        }
    }
    if ((newYLoc + 1) >= 0 && (newYLoc + 1) < numCols) {
        //breed right
        if (orgArrPtr[newXLoc][newYLoc + 1]->getSymb() == '-' && isBred == false) {
            newYLoc++;
            Organism* temp = new Doodlebug(newXLoc, newYLoc);
            temp->setTimeSteps(this->getTimeSteps());
            delete orgArrPtr[newXLoc][newYLoc];
            orgArrPtr[newXLoc][newYLoc] = temp;
            isBred = true;
        }
    }
}

void Doodlebug::Breed(Organism* orgArrPtr[][numCols]) {
    //will only allow breeding to occur if the Doodlebug has survived stepsDoodlebugBreed tiimes since it was initialized
    int xLoc = this->getXPos();
    int yLoc = this->getYPos();
    int newXLoc = xLoc;
    int newYLoc = yLoc;

    if (this->getTimeSteps() > 0 && this->getTimeSteps() % stepsDoodlebugBreed == 0) {
        suppBreedFunc(orgArrPtr, newXLoc, newYLoc);
    }
}

bool Doodlebug::Starve(Organism* orgArrPtr[][numCols]) {
    /*this fucntion will replace the doodlebug object with an organism object if the doodlebug has not taken the position
    of an ant object withing maxTimeStarvedDoodlebug times. The organism object is used to represent an empty position.
    It will also return a true if the doodlebug is replaced with an organism objeect or false if it hasn't so that in the move
    function breeding does not occur when there is no doodlebug to breed.*/
    int xLoc = this->getXPos();
    int yLoc = this->getYPos();
    int timeLastEaten = this->getLastTimeEaten();
    if (timeLastEaten >= maxTimeStarvedDoodlebug) {
        delete orgArrPtr[xLoc][yLoc];
        orgArrPtr[xLoc][yLoc] = new Organism(xLoc, yLoc);
        return true;
    }
    return false;

}

std::ostream& operator <<(std::ostream& outs, const Doodlebug& bug) {
    //reads to the console the representation symbol for the Doodlebug object
    outs << bug.getSymb();
    return outs;
}


/// Non-member fucntion Definition list

void createBaseGrid(Organism* orgArrPtr[][numCols]) {
    //creates a 2D array of organism objects
    //by not calling by reference the function creates a copy of the pointer, but the pointer still points to the same memory addresses
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            orgArrPtr[i][j] = new Organism(i, j);
        }
    }
}

void createPlayableGrid(Organism* orgArrPtr[][numCols]) {
    //sets the Ants and Doodlebugs on the Grid in random postions. Random number generation dependent on computer time
    //by not calling by reference the function creates a copy of the pointer, but the pointer still points to the same memeory addresses
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
    //by not calling by reference the function creates a copy of the pointer, but the pointer still points to the same memory addresses
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << *orgArrPtr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n" << std::endl;
}

void runGame(Organism* orgArrPtr[][numCols]) {
    //will continue the game after the initial grid has been created as long as the user continues to press enter
    std::string enter;
    std::getline(std::cin, enter);
    int strSize = enter.size();
    int maxTimeSteps = 1;
    while (strSize == 0) {
        std::cout << "World at time " << maxTimeSteps << ":\n\n" << std::endl;
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

        std::cout << "Press ENTER to continue";
        std::getline(std::cin, enter);
        std::cout << "\n" << std::endl;
    }
}

void deleteGrid(Organism* orgArrPtr[][numCols]) {
    //deletes memory element wise, sets elements to nullptr
    //by not calling by reference the function creates a copy of the pointer, but the pointer still points to the same memory addresses
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            delete orgArrPtr[i][j];
            orgArrPtr[i][j] = nullptr;
        }
    }
}