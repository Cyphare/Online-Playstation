#include "UI.h"
#include "Playstation.h"
#include "Ps4.h"

Ps4::Ps4(){
    ps4RentalRate = 0;
}

Ps4::Ps4(int rate){
    ps4RentalRate = rate;
}

int Ps4::getPS4RentalRate(){
    return ps4RentalRate;
}

int Ps4::getPS4Availability(){
    ifstream myfile("playstation.txt");
    string line;
    int currentLine = 1;
    int targetLine;

    if(myfile.is_open()){
        while(getline(myfile, line)){
            if(line == "Playstation 4"){
                targetLine = currentLine;
            } else if (currentLine == targetLine + 2){
                ps4Availability = stoi(line);
                break;
            }
            currentLine++;
        }
        myfile.close();
    }

    return ps4Availability;
}

void Ps4::displayPS4(){
    cout << "Playstation 4" <<endl;
    cout << "Tersedia    : " << getPS4Availability() << endl;
    cout << "Harga Rental: " << getPS4RentalRate() << "/hari\n" << endl;
}

int Ps4::countRentalRatePS4(int rentTime){
    totalRentalRate = rentTime * ps4RentalRate;
    return totalRentalRate;
}