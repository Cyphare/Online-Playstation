#include "UI.h"
#include "Playstation.h"
#include "Ps3.h"
#include <fstream>

Ps3::Ps3(){
    ps3RentalRate = 0;
}


Ps3::Ps3(int rate){
    ps3RentalRate = rate;
}

int Ps3::getPS3RentalRate(){
    return ps3RentalRate;
}

int Ps3::getPS3Availability(){
    ifstream myfile("playstation.txt");
    string line;
    int currentLine = 1;
    int targetLine = -3;

    if(myfile.is_open()){
        while(getline(myfile, line)){
            if(line == "Playstation 3"){
                targetLine = currentLine;
            } else if (currentLine == targetLine + 2){
                ps3Availability = stoi(line);
                break;
            }
            currentLine++;
        }
        myfile.close();
    }

    return ps3Availability;
}

void Ps3::displayPS3(){
    cout << "Playstation 3" <<endl;
    cout << "Tersedia    : " << getPS3Availability() << endl;
    cout << "Harga Rental: " << getPS3RentalRate() << "/hari\n" << endl;
}

int Ps3::countRentalRatePS3(int rentTime){
    totalRentalRate = rentTime * ps3RentalRate;
    return totalRentalRate;
}