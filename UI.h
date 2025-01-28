#ifndef UI_H
#define UI_H

#include <iostream>
using namespace std;

class userInterface{
    private:
        int pilihanMenuPertama;
        int pilihanMenuKedua;
        int pilihanMenuProfil;
        int pilihanMenuRental;
        int pilihanPengembalian;
        int pilihanAdministrator;
        int konfirmasi;
        int kembali;
    
    public:
        void header();
        //Fugsi untuk menampilkan header dari tampilan program
        //Postcondition: header ditampilkan di terminal

        int firstMenu();
        //Fungsi untuk menampilkan pilihan(login as member, sign up, atau login as administrator)
        //Postcondition: Pilihan dari firstmenu akan dikembalikan

        int secondMenu();
        //Fungsi untuk menampilkan pilihan(profil, rental ps, pengembalian barang, riwayat transaksi, dan logout)
        //Postcondition: Pilihan dari secondmenu akan dikembalikan

        int menuProfil();
        //Fungsi untuk menampilkan pilihan(update data, setor balance, dan hapus akun)
        //Postcondition: Pilihan dari menuprofil akan dikembalikan

        int menuRental();
        //Fungsi untuk memberi pilihan ps yang akan disewa
        //Postcondition: Pilihan dari menuRental akan dikembalikan

        int konfirmasiPemesanan();
        //Fungsi untuk mengonfirmasi ulang apakah akan membuat pesanan
        //Postcondition: Pilihan konfirmasi akan dikembalikan

        void balanceKurang();
        //Fungsi untuk menampilkan "balance anda kurang" jika balance kurang
        //Postcondition: "Balance anda kurang" ditampilkan di terminal


        void pembayaranBerhasil();
        //Fungsi untuk menampilkan "Pembayaran berhasil"
        //Postcondition: "Pembayaran berhasil" ditampilkan di terminal

        int menuPengembalian();
        //Fungsi untuk memilih playstation yang ingin dikembalikan
        //Postcondition: Mengembalikan pilihan ps yang akan dikembalikan

        int konfirmasiPengembalian();
        //Fungsi untuk menampilkan pilihan yang mengonfirmasi pengembalian
        //Postcondition: Mengembalikan pilihan konfirmasi;

        void menuKembali();
        //Fungsi untuk kembali ke menu sebelumnya
        //Postcondition: Mengambil input sembarang kemudian mengembalikan ke menu sebelumnya

        int menuAdministrator();
        //Fungsi untuk menampilkan pilihan(jumlah pendapatan, mengatur ketersediaan, 
        //konfirmasi pengembalian, list terpesan, list user terdaftar, dan logout)
        //Postcondition: Mengembalikan pilihan menuAdministrator

        void ringkasan();
        //Fungsi untuk menampilkan ringkasan untuk admin
        //Postcondition: Ringkasan ditampilkan di terminal

};

#endif // UI_H
