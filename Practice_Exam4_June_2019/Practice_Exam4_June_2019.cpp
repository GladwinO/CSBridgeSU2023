// Practice_Exam4_June_2019.cpp :










/*

10)
The window size on the TCP header displays how much data a receiver is willing to accept at a time. The 
sliding window is a specific range of data that includes the data that has currently been ACK by the 
receiver from the data sent within the window size, and the data that has not been ACK by the receiver.
Depending on the size of the window more or less data can be accepted by the receiver. In both the Go-Back-N
and Selective Repeat pipelines a smaller window size would limit the amount of data that could be received at
once, but that would also increase the amount of ACK that would need to be sent. This would decrease network
utilization and decrease throughput to the receiver. It would also increse the congestion of the network which
could lead to a Hold and Wait problem on the sender and receiver ends of the connection. 


11)

12)(10 pts) A slave DNS server is setup to replicate from the master for domain "FinalExam.com,"and 
successfully does so and becomes authoritative for the domain.After a while, its discovered that the
slave is no longer authoritative.Explain why this may have happened andwhat steps you would take to
try to diagnose the problem.

Some reasons that a Slave DNS server could have lost authority is becuase the data that it holds is 
differnt from the Master DNS. A slave server having Authority means that it is an accurate copy of 
the master server. Another reason the slave server could have lost authority could be because the 
master DNS server is down and the slave server did not get any updates from the master slave server 
before it expired. A slave server could lose authority even in the case that the data that was copied
from the master server was corrupted in traffic so the slave and master servers do not match. 
To diagnost the problem I would check to see if the data on the slave and master server match, and if
they dont have the master update the slave server. For the second scenario I would make sure that the 
master server is still up and running.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Software {
private:
    std::string name;
    std::string serNumStr;
    int numLicense;
    std::vector<std::string> installedMach;
public:
    Software(std::string newName = "N/A", std::string newSerNumStr = "N/A", int newNumLic = 0) :
        name(newName), serNumStr(newSerNumStr), numLicense(newNumLic) {}
    void operator +=(const std::string& newMachine) {
        installedMach.push_back(newMachine);
    }
    /* 
    * Different Overloaded Method(probably the preferred one)
    Software& operator +=(const std::string& newMachine){
        instaledMach.push_back(newMachine);
        return *this; 
     }
    */
    bool matches(const std::string& userName, const std::string& userSerNumStr) {
        if (userName == name && userSerNumStr == serNumStr) {
            return true;
        }
        return false;
    }
    bool inCompliance() {
        int numInstalled = installedMach.size();
        if (numInstalled < numLicense) {
            return true;
        }
        return false;
    }
    std::string getName() { return name; }
    std::string getSerNum() { return serNumStr; }

};



void softwareTracker(std::vector<Software>& objectVec){ 
    std::ifstream inputFile;
    inputFile.open("file.txt");
    std::string softName;
    while(inputFile >> softName){
        std::string serNumStr;
        inputFile >> serNumStr;
        std::string machine;
        inputFile >> machine;
        bool found = false;
        for (Software& software : objectVec){
            if(software.matches(softName, serNumStr)){
                software+=machine;
                found = true;
                break;
            }
        }
        if (!found) {
            Software newObject(softName, serNumStr);
            newObject += machine;
            objectVec.push_back(newObject);
        }
    }
    inputFile.close();
}





int main()
{
    std::ifstream inputFile;
    inputFile.open("file.txt");
    
   
}

