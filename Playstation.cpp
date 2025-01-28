#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include <string>
#include <limits>
#include "UI.h"
#include "Playstation.h"
using namespace std;

int Playstation::pemesanan(){
    return menuRental();
}

bool Playstation:: cekBalance(string us, int rent){
    header();
    int currentLine = 1;
    int targetLine = -7;
    ifstream myfile("account.txt");
    string line;
        
    if(myfile.is_open()){
        while(getline(myfile, line)){
            if(us == line){
                targetLine = currentLine;
            } else if (currentLine == targetLine + 6){
                balance = stoi(line);
                break;
            }
            currentLine++;
        }
        myfile.close();
    }

    if (balance >= rent){
        return true;
    } else {
        return false;
    }
}

void Playstation::mengurangiBalance(string us, int rent){
    fstream file("account.txt", ios::in);
    fstream tempFile("temp.txt", ios::out);

    string line;
    int currentLine = 1;
    int targetLine, minusBalance;
    while(getline(file, line)){
        if(us == line){
            targetLine = currentLine;
            tempFile << line << endl;
        } else if(currentLine == targetLine + 6) {
            minusBalance = stoi(line) - rent;
            tempFile << minusBalance << endl;
        } else {
            tempFile << line << endl;
        }
        currentLine++;
    }

    file.close();
    tempFile.close();

    // Hapus file asli
    if (remove("account.txt") != 0) {
        cout << "Gagal menghapus file asli." << endl;
        return;
    }

    // Ganti nama file sementara menjadi nama file asli
    if (rename("temp.txt", "account.txt") != 0) {
        cout << "Gagal mengganti nama file." << endl;
        return;
    }
}

int Playstation:: lamaPenyewaan(){
    cout << "Masukkan Berapa Lama Penyewaan(hari): " << endl;
    cin >> rentTime;
    return rentTime;
}

void Playstation:: pesanan(int ps, int rent, int time, string us){
    ofstream file1("history.txt", ios::app);
    ofstream file2("listPesanan.txt", ios::app);
    if(ps == 1){
        file1 << "\n" << us << endl;
        file1 << "Playstation 5" << endl;
        file1 << "Lama        : " << time << " hari" << endl;
        file1 << "Harga       : " << rent << endl; 
        file1 << "Pengembalian: belum\n" << endl;
        file2 << us << endl;
        file2 << "Playstation 5" << endl;
        file2 << "Lama        : " << time << " hari" << endl;
        file2 << "Harga       : " << rent << endl; 
        file2 << "Pengembalian: belum\n" << endl;
    } else if (ps == 2){
        file1 << "\n" << us << endl;
        file1 << "Playstation 4" << endl;
        file1 << "Lama        : " << time << " hari" << endl;
        file1 << "Harga       : " << rent << endl; 
        file1 << "Pengembalian: belum\n" << endl;
        file2 << us << endl;
        file2 << "Playstation 4" << endl;
        file2 << "Lama        : " << time << " hari" << endl;
        file2 << "Harga       : " << rent << endl; 
        file2 << "Pengembalian: belum\n" << endl;
    } else if (ps == 3){
        file1 << "\n" << us << endl;
        file1 << "Playstation 3" << endl;
        file1 << "Lama        : " << time << " hari" << endl;
        file1 << "Harga       : " << rent << endl; 
        file1 << "Pengembalian: belum\n" << endl;
        file2 << us << endl;
        file2 << "Playstation 3" << endl;
        file2 << "Lama        : " << time << " hari" << endl;
        file2 << "Harga       : " << rent << endl; 
        file2 << "Pengembalian: belum\n" << endl;
    }
    file1.close();
    file2.close();
}

void Playstation::mengurangiKetersediaan(int ps){
    fstream file("playstation.txt", ios::in);
    fstream tempFile("temp.txt", ios::out);

    string line, PS;
    int currentLine = 1;
    int targetLine, minusPS;

    if(ps == 1){
        PS = "Playstation 5";
    } else if (ps == 2){
        PS = "Playstation 4";
    } else if (ps == 3){
        PS = "Playstation 3";
    }

    while(getline(file, line)){
        if(line == PS){
            targetLine = currentLine;
            tempFile << line << endl;
        } else if(currentLine == targetLine + 2) {
            minusPS = stoi(line) - 1;
            tempFile << minusPS << endl;
        } else {
            tempFile << line << endl;
        }
        currentLine++;
    }

    file.close();
    tempFile.close();

    // Hapus file asli
    if (remove("playstation.txt") != 0) {
        cout << "Gagal menghapus file asli." << endl;
        return;
    }

    // Ganti nama file sementara menjadi nama file asli
    if (rename("temp.txt", "playstation.txt") != 0) {
        cout << "Gagal mengganti nama file." << endl;
        return;
    }
}

void Playstation::mengaturKetersediaan(){
    fstream file("playstation.txt", ios::in);
    fstream tempFile("temp.txt", ios::out);

    string line;
    int currentLine = 1;
    int targetLine, play, station;
    station = 5;
    while(getline(file, line)){
        if(line == "Playstation 5"){
            targetLine = currentLine;
            tempFile << line << endl;
        } else if(currentLine == targetLine + 2){
            header();
            cout << "Masukkan jumlah Playstation " << station << " yang tersedia:" << endl;
            cin >> play;
            tempFile << play << endl;
            station--;
        } else if (currentLine == targetLine + 6) {
            header();
            cout << "Masukkan jumlah Playstation " << station << " yang tersedia:" << endl;
            cin >> play;
            tempFile << play << endl;
            station--;
        } else if (currentLine == targetLine + 10){
            header();
            cout << "Masukkan jumlah Playstation " << station << " yang tersedia:" << endl;
            cin >> play;
            tempFile << play << endl;
            station--;
        } else {
            tempFile << line << endl;
        }
        currentLine++;
    }

    file.close();
    tempFile.close();

    // Hapus file asli
    if (remove("playstation.txt") != 0) {
        cout << "Gagal menghapus file asli." << endl;
        return;
    }

    // Ganti nama file sementara menjadi nama file asli
    if (rename("temp.txt", "playstation.txt") != 0) {
        cout << "Gagal mengganti nama file." << endl;
        return;
    }
}


bool Playstation ::pengembalianPS(int ps, string us){
    ifstream myfile("history.txt");
    string line;
    int currentLine = 1;
    int targetLine = -5;
    bool checking = false;
        
    if(myfile.is_open()){
        while(getline(myfile, line)){
            if(ps == 1){
                if(line == us){
                    targetLine = currentLine;
                } else if(line == "Playstation 5" && currentLine == targetLine + 1){
                    targetLine = currentLine;
                    checking = true;
                } else if (currentLine == targetLine + 3 && checking){
                    if(line == "Pengembalian: belum"){
                        myfile.close();
                        return true;
                    }
                }
            } else if (ps == 2) {
                if(line == us){
                    targetLine = currentLine;
                } else if(line == "Playstation 4" && currentLine == targetLine + 1){
                    targetLine = currentLine;
                    checking = true;
                } else if (currentLine == targetLine + 3  && checking){
                    if(line == "Pengembalian: belum"){
                        myfile.close();
                        return true;
                    }
                }
            } else if (ps == 3){
                if(line == us){
                    targetLine = currentLine;
                } else if(line == "Playstation 3" && currentLine == targetLine + 1){
                    targetLine = currentLine;
                    checking = true;
                } else if (currentLine == targetLine + 3  && checking){
                    if(line == "Pengembalian: belum"){
                        myfile.close();
                        return true;
                    }
                }
            }
            currentLine++;
        }
        myfile.close();
    }
    return false;
}

bool Playstation ::cekKetersediaan(int ps){
    ifstream myfile("playstation.txt");
    string line;
    int currentLine = 1;
    int targetLine;
        
    if(myfile.is_open()){
        while(getline(myfile, line)){
            if(ps == 1){
                if(line == "Playstation 5"){
                    targetLine = currentLine;
                } else if (currentLine == targetLine + 2){
                    if(line == "0"){
                        myfile.close();
                        return false;
                    }
                } else {
                    myfile.close();
                    return true;;
                }
            } else if (ps == 2) {
                if(line == "Playstation 4"){
                    targetLine = currentLine;
                } else if (currentLine == targetLine + 2){
                    if(line == "0"){
                        myfile.close();
                        return false;
                    }
                } else {
                    myfile.close();
                    return true;
                }
            } else if (ps == 3){
                if(line == "Playstation 3"){
                    targetLine = currentLine;
                } else if (currentLine == targetLine + 3){
                    if(line == "0"){
                        myfile.close();
                        return false;
                    }
                } else {
                    myfile.close();
                    return true;
                }
            }
        }
        myfile.close();
    }
    return false;
}

void Playstation::riwayatPemesanan(string us){
    header();
    ifstream myfile("history.txt");
    string line;
    int currentLine = -1;
    int targetLine = -10;
        
    if(myfile.is_open()){
        while(getline(myfile, line)){
            if(line == us){
                targetLine = currentLine;
            } else if (currentLine == targetLine + 1){
                cout << line << endl;
            } else if (currentLine == targetLine + 2){
                cout << line << endl;
            } else if (currentLine == targetLine + 3){
                cout << line << endl;
            } else if (currentLine == targetLine + 4){
                cout << line << endl;
                cout << endl;
            }
            currentLine++;
        }
        myfile.close();
    }
}

void Playstation::ringkasanAdmin(int pilihan, int rent, int time){
    header();
    fstream file("ringkasan.txt", ios::in);
    fstream tempFile("temp.txt", ios::out);

    string line;
    int add;
    int currentLine = 1;
    while(getline(file, line)){
        if(currentLine == pilihan){
            add = stoi(line) + time;
            tempFile << add << endl;
        } else if (currentLine == 4){
            add = stoi(line) + rent;
            tempFile << add << endl;
        } else {
            tempFile << line << endl;
        }
        currentLine++;
    }

    file.close();
    tempFile.close();

    // Hapus file asli
    if (remove("ringkasan.txt") != 0) {
        cout << "Gagal menghapus file asli." << endl;
        return;
    }

    // Ganti nama file sementara menjadi nama file asli
    if (rename("temp.txt", "ringkasan.txt") != 0) {
        cout << "Gagal mengganti nama file." << endl;
        return;
    }
}

void Playstation:: konfirmasi(int ps, string us){
    ifstream myfile("history.txt");
    string line;
    int currentLine = 1;
    int targetLine = -5;
    bool checking = false;
        
    if(myfile.is_open()){
        while(getline(myfile, line)){
            if(ps == 1){
                if(line == us){
                    targetLine = currentLine;
                } else if(line == "Playstation 5" && currentLine == targetLine + 1){
                    targetLine = currentLine;
                    checking = true;
                } else if (currentLine == targetLine + 3 && checking){
                    if(line == "Pengembalian: belum"){
                        myfile.close();
                        break;
                    }
                }
            } else if (ps == 2) {
                if(line == us){
                    targetLine = currentLine;
                } else if(line == "Playstation 4" && currentLine == targetLine + 1){
                    targetLine = currentLine;
                    checking = true;
                } else if (currentLine == targetLine + 3  && checking){
                    if(line == "Pengembalian: belum"){
                        myfile.close();
                        break;
                    }
                }
            } else if (ps == 3){
                if(line == us){
                    targetLine = currentLine;
                } else if(line == "Playstation 3" && currentLine == targetLine + 1){
                    targetLine = currentLine;
                    checking = true;
                } else if (currentLine == targetLine + 3  && checking){
                    if(line == "Pengembalian: belum"){
                        myfile.close();
                        break;
                    }
                }
            }
            currentLine++;
        }
        myfile.close();
    }

    ifstream myfile2("history.txt");
    ofstream file("konfirmasi.txt", ios::app);
    targetLine = currentLine;
    currentLine = 1;

    if(myfile2.is_open()){
        while(getline(myfile2,line)){
            if(targetLine - 4 == currentLine){
                file << line << endl;
            } else if (targetLine - 3 == currentLine){
                file << line << endl;
            } else if (targetLine - 2 == currentLine){
                file << line << endl;
            } else if (targetLine - 1 == currentLine){
                file << line << endl;
            } else if (targetLine == currentLine){
                file << line << endl;
                file << endl;
                break;
            }
            currentLine++;
        }
        myfile2.close();
    }
    file.close();
}

void Playstation::konfirmasiAdmin(){
    header();
    ifstream myfile("konfirmasi.txt");
    string line;
    int linePivot = 0, currentLine = 1;
    string nama, ps, lama, harga, kembali;

    if(myfile.is_open()){
        while(getline(myfile, line)){
            cout << line << endl;
            if(currentLine % 6 == 1){
                nama = line;
                currentLine++;
            } else if (currentLine % 6 == 2){
                ps = line;
                currentLine++;
            } else if (currentLine % 6 == 3){
                lama = line;
                currentLine++;
            } else if (currentLine % 6 == 4){
                harga = line;
                currentLine++;
            } else if (currentLine % 6 == 5){
                kembali = line;
                currentLine++;
            } else if (currentLine % 6 == 0){
                cout << "1. Konfirmasi" << endl;
                cout << "2. Selanjutnya" << endl;
                cout << "Pilih Opsi(1-2), tekan lainnya untuk kembali" << endl;
                pilihanKonfirmasi = _getch();
                switch(pilihanKonfirmasi){
                    case 49:
                        pilihanKonfirmasi = 1;
                        break;
                    case 50:
                        pilihanKonfirmasi = 2;
                        break;
                }
                currentLine++;
                linePivot++;
                if(pilihanKonfirmasi == 2){
                    header();
                    continue;
                }
                break;
            }
        }
        myfile.close();
    } 
    if (pilihanKonfirmasi == 2){
        cout << "1. Konfirmasi" << endl;
        cout << "Pilih Opsi, tekan lainnya untuk kembali" << endl;
        pilihanKonfirmasi = _getch();
        switch(pilihanKonfirmasi){
            case 49:
                pilihanKonfirmasi = 1;
                break;
        }
        currentLine++;
        linePivot++;
    }
    
    if(pilihanKonfirmasi != 1){
        return;
    }

    fstream file("konfirmasi.txt", ios::in);
    fstream tempFile("temp.txt", ios::out);

    currentLine = 1;
    linePivot = (6*linePivot) + 1;
    while(getline(file, line)){
        if(currentLine >= linePivot && currentLine <= linePivot + 5){
        } else {
            tempFile << line << endl;
        }
        currentLine++;
    }

    file.close();
    tempFile.close();

    // Hapus file asli
    if (remove("konfirmasi.txt") != 0) {
        cout << "Gagal menghapus file asli." << endl;
        return;
    }

    // Ganti nama file sementara menjadi nama file asli
    if (rename("temp.txt", "konfirmasi.txt") != 0) {
        cout << "Gagal mengganti nama file." << endl;
        return;
    }

    ifstream fileList("listPesanan.txt");
    currentLine = 1;
    linePivot = -8;
    bool checkNama = false, checkPS = false, checkLama = false, checkHarga = false, cekKembali = false, done = false;

    while(getline(fileList, line)){
        if(nama == line){
            checkNama = true;
            linePivot = currentLine;
        } else if(ps == line && currentLine == linePivot + 1){
            checkPS = true;
        } else if(lama == line && currentLine == linePivot + 2){
            checkLama = true;
        } else if(harga == line && currentLine == linePivot + 3){
            checkHarga = true;
        } else if(kembali == line && currentLine == linePivot + 4){
            cekKembali = true;
            linePivot = currentLine;
        }
        if(checkNama){
            if(checkPS){
                if(checkLama){
                    if (checkHarga){
                        if(cekKembali){
                            break;
                        }
                    }
                }
            }
        }
        currentLine++;
    }
    fileList.close();

    fstream file1("listPesanan.txt", ios::in);
    fstream tempFile1("temp.txt", ios::out);

    currentLine = 1;
    while(getline(file1, line)){
        if(currentLine >= linePivot - 4  && currentLine <= linePivot + 1){
        } else {
            tempFile1 << line << endl;
        }
        currentLine++;
    }

    file1.close();
    tempFile1.close();

    // Hapus file asli
    if (remove("listPesanan.txt") != 0) {
        cout << "Gagal menghapus file asli." << endl;
        return;
    }

    // Ganti nama file sementara menjadi nama file asli
    if (rename("temp.txt", "listPesanan.txt") != 0) {
        cout << "Gagal mengganti nama file." << endl;
        return;
    }

    ifstream fileHistory("history.txt");
    currentLine = 1;
    linePivot = -8;
    checkNama = false, checkPS = false, checkLama = false, checkHarga = false, cekKembali = false;

    while(getline(fileHistory, line)){
        if(nama == line){
            checkNama = true;
            linePivot = currentLine;
        } else if(ps == line && currentLine == linePivot + 1){
            checkPS = true;
        } else if(lama == line && currentLine == linePivot + 2){
            checkLama = true;
        } else if(harga == line && currentLine == linePivot + 3){
            checkHarga = true;
        } else if(kembali == line && currentLine == linePivot + 4){
            cekKembali = true;
            linePivot = currentLine;
        }
        if(checkNama){
            if(checkPS){
                if(checkLama){
                    if (checkHarga){
                        if(cekKembali){
                            break;
                        }
                    }
                }
            }
        }
        currentLine++;
    }
    fileHistory.close();

    fstream file2("history.txt", ios::in);
    fstream tempFile2("temp.txt", ios::out);

    currentLine = 1;
    while(getline(file2, line)){
        if(linePivot == currentLine){
            tempFile2 << "Pengembalian: sudah" << endl;
        } else {
            tempFile2 << line << endl;
        }
        currentLine++;
    }

    file2.close();
    tempFile2.close();

    // Hapus file asli
    if (remove("history.txt") != 0) {
        cout << "Gagal menghapus file asli." << endl;
        return;
    }

    // Ganti nama file sementara menjadi nama file asli
    if (rename("temp.txt", "history.txt") != 0) {
        cout << "Gagal mengganti nama file." << endl;
        return;
    }
}

void Playstation::listPesanan(){
    header();
    ifstream myfile("listPesanan.txt");
    string line;
        
    if(myfile.is_open()){
        while(getline(myfile, line)){
            cout << line << endl;
        }
        myfile.close();
    }
}




