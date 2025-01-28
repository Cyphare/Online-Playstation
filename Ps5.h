#ifndef PS5_H
#define PS5_H

#include "Playstation.h"

class Ps5 : public Playstation {
    private:
        int ps5RentalRate;
        int ps5Availability;
        int totalRentalRate;
        int rentTime;

    
    public:
        Ps5();
        //Fungsi untuk mengonstruksi class
        //Postcondition: ps5RentalRate = 0

        Ps5(int rate);
        //Fungsi untuk mengonstruksi class dengan parameter
        //Postcondition: ps5RentalRate = rate

        int getPS5RentalRate();
        //Fungsi untuk mengembalikan ps5RentalRate
        //Postcondition: Nilai ps5RentalRate dikembalikan

        int getPS5Availability();
        //Fungsi untuk mengembalikan jumlah ps5 yang tersedia
        //Postcondition: Nilai jumlah ps5 yang tersedia dikembalikan

        void displayPS5();
        //Fungsi untuk mencetak ketersediaan dan harga rental ps5
        //Postcondition: Ketersediaan dan harga rental di cetak di terminal

        int countRentalRatePS5(int rentTime);
        //Fungsi untuk menghitung harga rental
        //Postcondition: Harga rental dikali dengan lama penyewaan, kemudian mengembalikan nilai perkaliannya
};

#endif //PS5_H
