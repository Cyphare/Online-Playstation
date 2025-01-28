#ifndef PS3_H
#define PS3_H

#include "Playstation.h"

class Ps3 : public Playstation {
    private:
        int ps3RentalRate;
        int ps3Availability;
        int totalRentalRate;
        int rentTime;
    
    public:
        Ps3();
        //Fungsi untuk mengonstruksi class
        //Postcondition: ps3RentalRate = 0

        Ps3(int rate);
        //Fungsi untuk mengonstruksi class dengan parameter
        //Postcondition: ps3RentalRate = rate

        int getPS3RentalRate();
        //Fungsi untuk mengembalikan ps3RentalRate
        //Postcondition: Nilai ps3RentalRate dikembalikan

        int getPS3Availability();
        //Fungsi untuk mengembalikan jumlah ps3 yang tersedia
        //Postcondition: Nilai jumlah ps3 yang tersedia dikembalikan

        void displayPS3();
        //Fungsi untuk mencetak ketersediaan dan harga rental ps3
        //Postcondition: Ketersediaan dan harga rental di cetak di terminal

        int countRentalRatePS3(int rentTime);
        //Fungsi untuk menghitung harga rental
        //Postcondition: Harga rental dikali dengan lama penyewaan, kemudian mengembalikan nilai perkaliannya
        
};

#endif //PS3_H
