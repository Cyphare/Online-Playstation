#ifndef PLAYSTATION_H
#define PLAYSTATION_H

#include "UI.h"

class Playstation: public userInterface{
    private:
        int balance;
        int rentTime;
        int pilihanKonfirmasi;
    public:
        int pemesanan();
        //Fungsi untuk memilih playstation yang akan dipesan dan mengembalikan pilihannya
        //Postcondition: Pilihan ps dikembalikan

        bool cekBalance(string us, int rent);
        //Fungsi untuk mengecek apakah balance cukup untuk menyewa playstation
        //Postcondition: true jika tersedia, false jika tidak dikembalikan

        void mengurangiBalance(string us, int rent);
        //Fungsi untuk mengurangi balance jika mengonfirmasi akan menyewa playstation
        //Postcondition: Balance dalam account.txt dikurangi

        int lamaPenyewaan();
        //Fungsi untuk menginput berapa lama penyewaan dan mengembalikan nilainya
        //Postcondition: Lama penyewaan dikembalikan

        void pesanan(int ps, int rent, int time, string us);
        //Fungsi untuk mencetak pesanan di history.txt dan listPesanan.txt
        //Postcondition: Pesanan di cetak di history.txt dan listPesanan.txt

        void mengurangiKetersediaan(int ps);
        //Fungsi untuk mengurangi ketersediaan ps setelah mengonfirmasi penyewaan
        //Postcondition: Ketersediaan dalam playstation.txt dikurangi

        void mengaturKetersediaan();
        //Fungsi untuk mengatur ketersediaan ps yang dilakukan oleh Admin
        //Postcondition: Ketersediaan dalam playstation.txt diubah jumlahnya oleh admin

        bool pengembalianPS(int ps, string us);
        //Fungsi untuk mengecek apakah terdapat ps(3/4/5) yang belum dikembalikan
        //Postcondition: Mengembalikan true jika ditemukan, tidak jika sebaliknya

        bool cekKetersediaan(int ps);
        //Fungsi untuk mengecek apakah ps tersedia untuk di sewa
        //Postcondition: Mengembalikan true jika ditemukan, tidak jika sebaliknya

        void riwayatPemesanan(string us);
        //Fungsi untuk mengecek riwayat pemesanan yang dilakukan oleh member
        //Postcondition: Riwayat pemesanan akan dicetak di terminal

        void ringkasanAdmin(int pilihan, int rent, int time);
        //Fungsi untuk mencetak ringkasan untuk Admin
        //Postcondition: Ringkasan untuk admin akan dicetak di terminal

        void konfirmasi(int ps, string us);
        //Fungsi untuk meminta konfirmasi pengembalian ke Admin
        //Postcondition: Konfirmasi akan dicetak di konfirmasi.txt

        void konfirmasiAdmin();
        //Fungsi untuk mengkonfirmasi pengembalian oleh Admin
        //Postcondition: Jika konfirmasi disetujui maka akan menghapus pesanan di konfirmasi.txt dan listPesanan.txt, kemudian mengubah status di history.txt menjadi sudah dikembalika 

        void listPesanan();
        //Fungsi untuk mencetak penyewaan yang sedang berjalan
        //Postcondition: Mencetak list pesanan yang sedang berjalan di terminal
};
#endif //PLAYSTATION_H
