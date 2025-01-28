#ifndef TRANSIT_H
#define TRANSIT_H

class transit {
    private: 
        string usernameFix;
        int pilihanKedua;
        int pilihanProfil;
        int pilihanRental;
        int pilihanKembali;
        int pilihanAdmin;
        int rentalRate;
        int rentTime;
    
    public:
    void transisi(); 
    //Fungsi untuk pindah menu
    //Postcondition: Fungsi untuk menjalankan program sepenuhnya

};

#endif //TRANSIT_H
