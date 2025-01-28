#include "UI.h"
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

void userInterface::header(){ //Header Hiasan
    cout << "\n" << "========================" << endl;
    cout << "   Rental Playstation   " << endl;
    cout << "========================" << endl;
}

int userInterface::firstMenu(){ //Menu ketika pertama kali membuka aplikasi(login atau signUp)
    header();
    cout << "1. Login as Member" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Login as Administrator" << endl;
    cout << "Pilih Opsi(1-3): " << endl;
    pilihanMenuPertama = _getch();
    switch(pilihanMenuPertama){
        case 49:
            pilihanMenuPertama = 1;
            break;
        case 50:
            pilihanMenuPertama = 2;
            break;
        case 51:
            pilihanMenuPertama = 3;
            break;
        default:
            pilihanMenuPertama = -1;
    }
    return pilihanMenuPertama;
}

int userInterface::secondMenu(){ // Menu setelah login
    header();
    cout << "1. Profil" << endl;
    cout << "2. Rental PS" << endl;
    cout << "3. Pengembalian Barang" << endl;
    cout << "4. Riwayat Transaksi" << endl;
    cout << "5. Log Out" << endl;
    cout << "Pilih Opsi(1-5): " << endl;
    pilihanMenuKedua = _getch();
    switch(pilihanMenuKedua){
        case 49:
            pilihanMenuKedua = 1;
            break;
        case 50:
            pilihanMenuKedua = 2;
            break;
        case 51:
            pilihanMenuKedua = 3;
            break;
        case 52:
            pilihanMenuKedua = 4;
            break;
        case 53:
            pilihanMenuKedua = 5;
            break;
    }
    return pilihanMenuKedua;
}

int userInterface::menuProfil(){
    cout << "1. Update Data" << endl;
    cout << "2. Setor Balance" << endl;
    cout << "3. Hapus Akun" << endl;
    cout << "Tekan lainnya untuk kembali" << endl;
    pilihanMenuProfil = _getch();
    switch(pilihanMenuProfil){
        case 49:
            pilihanMenuProfil = 1;
            break;
        case 50:
            pilihanMenuProfil = 2;
            break;
        case 51:
            pilihanMenuProfil = 3;
            break;
    }
    return pilihanMenuProfil;
}

int userInterface::menuRental(){
    cout << "1. Rental Playstation 5" << endl;
    cout << "2. Rental Playstation 4" << endl;
    cout << "3. Rental Playstation 3" << endl;
    cout << "Tekan lainnya untuk kembali" << endl;
    pilihanMenuRental = _getch();
    switch(pilihanMenuRental){
        case 49:
            pilihanMenuRental = 1;
            break;
        case 50:
            pilihanMenuRental = 2;
            break;
        case 51:
            pilihanMenuRental = 3;
            break;
    }
    return pilihanMenuRental;
}

int userInterface::konfirmasiPemesanan(){
    header();
    cout << "Apakah anda yakin membuat pesanan (Tekan 1 jika ya, tekan lainnya untuk kembali)" << endl;
    konfirmasi = _getch();
    switch(konfirmasi){
        case 49:
            konfirmasi = 1;
            break;
    }
    return konfirmasi;
}

void userInterface::balanceKurang(){
    header();
    cout << "Balance anda kurang, silahkan isi ulang (Tekan apapun untuk kembali)" << endl;
    kembali = _getch();
}

void userInterface::pembayaranBerhasil(){
    header();
    cout << "Pembayaran Berhasil (Tekan apapun untuk kembali)" << endl;
    kembali = _getch();
}

int userInterface::menuPengembalian(){
    header();
    cout << "1. Playstation 5" << endl;
    cout << "2. Playstation 4" << endl;
    cout << "3. Playstation 3" << endl;
    cout << "Playstation mana yang ingin anda kembalikan(1-3)" << endl;
    cout << "Tekan apapun untuk kembali" << endl;
    pilihanPengembalian = _getch();
    switch(pilihanPengembalian){
        case 49:
            pilihanPengembalian = 1;
            break;
        case 50:
            pilihanPengembalian = 2;
            break;
        case 51:
            pilihanPengembalian = 3;
            break;
    }
    return pilihanPengembalian;
}

int userInterface::konfirmasiPengembalian(){
    header();
    cout << "Konfirmasi Pengembalian? (tekan 1 jika ya dan lainnya untuk kembali)" << endl;
    konfirmasi = _getch();
    switch(konfirmasi){
        case 49:
            konfirmasi = 1;
            break;
    }
    return konfirmasi;
}

void userInterface::menuKembali(){
    cout << "Tekan apapun untuk kembali" << endl;
    kembali = _getch();
}

int userInterface::menuAdministrator(){
    header();
    cout << "1. Jumlah Pendapatan" << endl;
    cout << "2. Mengatur Ketersediaan" << endl;
    cout << "3. Konfirmasi Pengembalian" << endl;
    cout << "4. List Terpesan" << endl;
    cout << "5. List User Terdaftar" << endl;
    cout << "6. Log Out" << endl;
    cout << "Pilih Opsi(1-6)" << endl;
    pilihanAdministrator = _getch();
    switch(pilihanAdministrator){
        case 49:
            pilihanAdministrator = 1;
            break;
        case 50:
            pilihanAdministrator = 2;
            break;
        case 51:
            pilihanAdministrator = 3;
            break;
        case 52:
            pilihanAdministrator = 4;
            break;
        case 53:
            pilihanAdministrator = 5;
            break;
        case 54:
            pilihanAdministrator = 6;
            break;
    }
    return pilihanAdministrator;
}

void userInterface::ringkasan(){
    header();
    ifstream myfile("ringkasan.txt");
    string line;
    int currentLine = 1;
        
    if(myfile.is_open()){
        while(getline(myfile, line)){
            if(currentLine == 1){
                cout << "Total Playstation 5 tersewa(hari) : " << line << endl;
            } else if (currentLine == 2){
                cout << "Total Playstation 4 tersewa(hari) : " << line << endl;
            } else if (currentLine == 3){
                cout << "Total Playstation 3 tersewa(hari) : " << line << endl;
            } else if (currentLine == 4){
                cout << "Pendapatan Total: " << line << endl;
            }
            currentLine++;
        }
        myfile.close();
    }
}

