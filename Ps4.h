#ifndef PS4_H
#define PS4_H

#include "Playstation.h"

class Ps4 : public Playstation {
    private:
        int ps4RentalRate;
        int ps4Availability;
        int totalRentalRate;
        int rentTime;

    
    public:
        Ps4();
        //Fungsi untuk mengonstruksi class
        //Postcondition: ps4RentalRate = 0

        Ps4(int rate);
        //Fungsi untuk mengonstruksi class dengan parameter
        //Postcondition: ps4RentalRate = rate

        int getPS4RentalRate();
        //Fungsi untuk mengembalikan ps4RentalRate
        //Postcondition: Nilai ps4RentalRate dikembalikan

        int getPS4Availability();
        //Fungsi untuk mengembalikan jumlah ps4 yang tersedia
        //Postcondition: Nilai jumlah ps4 yang tersedia dikembalikan

        void displayPS4();
        //Fungsi untuk mencetak ketersediaan dan harga rental ps4
        //Postcondition: Ketersediaan dan harga rental di cetak di terminal

        int countRentalRatePS4(int rentTime);
        //Fungsi untuk menghitung harga rental
        //Postcondition: Harga rental dikali dengan lama penyewaan, kemudian mengembalikan nilai perkaliannya
        
};

#endif //PS4_H
