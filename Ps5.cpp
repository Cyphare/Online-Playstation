#include "UI.h"
#include "Playstation.h"
#include "Ps5.h"
#include <fstream>

Ps5::Ps5(){
    ps5RentalRate = 0;
}

Ps5::Ps5(int rate){
    ps5RentalRate = rate;
}

int Ps5::getPS5RentalRate(){
    return ps5RentalRate;
}

int Ps5::getPS5Availability(){
    ifstream myfile("playstation.txt");
    string line;
    int currentLine = 1;
    int targetLine;

    if(myfile.is_open()){
        while(getline(myfile, line)){
            if(line == "Playstation 5"){
                targetLine = currentLine;
            } else if (currentLine == targetLine + 2){
                ps5Availability = stoi(line);
                break;
            }
            currentLine++;
        }
        myfile.close();
    }

    return ps5Availability;
}

void Ps5::displayPS5(){
    cout << "Playstation 5" << endl;
    cout << "Tersedia    : " << getPS5Availability() << endl;
    cout << "Harga Rental: " << getPS5RentalRate() << "/hari\n" << endl;
}

int Ps5::countRentalRatePS5(int rentTime){
    totalRentalRate = rentTime * ps5RentalRate;
    return totalRentalRate;
}