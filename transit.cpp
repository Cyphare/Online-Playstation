#include "UI.h"
#include "User.h"
#include "Playstation.h"
#include "Ps3.h"
#include "Ps4.h"
#include "Ps5.h"
#include "transit.h"
#include <conio.h>
#include <iostream>


void transit::transisi(){

    User users; //Mengkonstruksi class User
    Playstation ps;
    Ps3 ps3(50000);
    Ps4 ps4(100000);
    Ps5 ps5(200000);

    usernameFix = "-1";
    while(usernameFix == "-1"){
        usernameFix = users.mulai(); //Menu Login dan Register
        
        if(usernameFix == "3"){
            while(true){
                pilihanAdmin = users.menuAdministrator();
                if(pilihanAdmin == 1){
                    users.ringkasan();
                    users.menuKembali();
                    continue;
                } else if (pilihanAdmin == 2){
                    ps.mengaturKetersediaan();
                    users.menuKembali();
                    continue;     
                } else if (pilihanAdmin == 3){
                    ps.konfirmasiAdmin();
                    continue;
                } else if (pilihanAdmin == 4){
                    ps.listPesanan();
                    users.menuKembali();
                    continue;
                } else if (pilihanAdmin == 5){
                    users.listUserTerdaftar();
                    users.menuKembali();
                    continue;
                } else if (pilihanAdmin == 6){
                    usernameFix = "-1";
                    break;
                }
            }
            continue;
        }
        pilihanKedua = 1;
        
        while(pilihanKedua != 0){
            pilihanKedua = users.secondMenu();
            switch(pilihanKedua){
                case 1:
                    pilihanProfil = 1;
                    while(pilihanProfil == 1){
                        pilihanProfil = users.profil(usernameFix);
                        if(pilihanProfil == 1){
                            users.updateData(usernameFix);
                            break;
                        }else if (pilihanProfil == 2){
                            users.addBalance(usernameFix);
                            break;
                        }else if (pilihanProfil == 3){
                            users.header();
                            cout <<"Tekan 1 jika anda yakin untuk menghapus akun, tekan lainnya untuk kembali" << endl;
                            int isDelete = _getch();
                            if(isDelete == 49){
                                users.Delete(usernameFix);
                                pilihanKedua = 0;
                                usernameFix = "-1";
                                break;
                            } else {
                                pilihanProfil = 1;
                                continue;
                            }
                            
                            users.Delete(usernameFix);
                            pilihanKedua = 0;
                            break;
                        }else {
                            pilihanProfil = 0;
                            break;
                        }                     
                    }
                    break;
                case 2:
                    pilihanRental = 1;
                    while(pilihanRental == 1){
                        ps.header();
                        ps5.displayPS5();
                        ps4.displayPS4();
                        ps3.displayPS3();
                        pilihanRental = ps.pemesanan();
                        if(pilihanRental == 1 && ps.cekKetersediaan(pilihanRental)){
                            ps.header();
                            rentTime = ps.lamaPenyewaan();
                            rentalRate = ps5.countRentalRatePS5(rentTime);
                            if(ps.cekBalance(usernameFix, rentalRate)){
                                if(users.konfirmasiPemesanan() == 1){
                                    users.pembayaranBerhasil();
                                    ps.mengurangiBalance(usernameFix, rentalRate);
                                    ps.pesanan(pilihanRental, rentalRate, rentTime, usernameFix);
                                    ps.mengurangiKetersediaan(pilihanRental);
                                    ps.ringkasanAdmin(pilihanRental, rentalRate, rentTime);
                                    pilihanRental = 0;
                                    break;
                                } else {
                                    pilihanRental = 0;
                                    break;
                                }       
                                break;                     
                            } else {
                                users.balanceKurang();
                                pilihanRental = 0;                                
                                break;
                            }
                        } else if (pilihanRental == 1 && !ps.cekKetersediaan(pilihanRental)){
                            ps.header();
                            cout << "Playstation 5 sudah tersewa semua" << endl;
                            pilihanRental = 1;
                            break;
                        } else if (pilihanRental == 2 && ps.cekKetersediaan(pilihanRental)){
                            ps.header();
                            rentTime = ps.lamaPenyewaan();
                            rentalRate = ps4.countRentalRatePS4(rentTime);
                            if(ps.cekBalance(usernameFix, rentalRate)){
                                if(users.konfirmasiPemesanan() == 1){
                                    users.pembayaranBerhasil();
                                    ps.mengurangiBalance(usernameFix, rentalRate);
                                    ps.pesanan(pilihanRental, rentalRate, rentTime, usernameFix);
                                    ps.mengurangiKetersediaan(pilihanRental);
                                    ps.ringkasanAdmin(pilihanRental, rentalRate, rentTime);
                                    pilihanRental = 0;
                                    break;
                                } else {
                                    pilihanRental = 0;
                                    break;
                                }                            
                            } else {
                                users.balanceKurang();
                                pilihanRental = 0;
                                break;
                            }
                            break;
                        } else if (pilihanRental == 2 && !ps.cekKetersediaan(pilihanRental)){
                            ps.header();
                            cout << "Playstation 4 sudah tersewa semua" << endl;
                            pilihanRental = 1;
                            break;
                        } else if (pilihanRental == 3 && ps.cekKetersediaan(pilihanRental)){
                            ps.header();
                            rentTime = ps.lamaPenyewaan();
                            rentalRate = ps3.countRentalRatePS3(rentTime);
                            if(ps.cekBalance(usernameFix, rentalRate)){
                                if(users.konfirmasiPemesanan() == 1){
                                    users.pembayaranBerhasil();
                                    ps.mengurangiBalance(usernameFix, rentalRate);
                                    ps.pesanan(pilihanRental, rentalRate, rentTime, usernameFix);
                                    ps.mengurangiKetersediaan(pilihanRental);
                                    ps.ringkasanAdmin(pilihanRental, rentalRate, rentTime);
                                    pilihanRental = 0;
                                    break;
                                } else {
                                    pilihanRental = 0;
                                    break;
                                }                            
                            } else {
                                users.balanceKurang();
                                pilihanRental = 0;
                                break;
                            }
                            break;
                        } else if (pilihanRental == 3 && !ps.cekKetersediaan(pilihanRental)){
                            ps.header();
                            cout << "Playstation 3 sudah tersewa semua" << endl;
                            pilihanRental = 1;
                            break;
                        } else {
                            pilihanRental = 0;
                            break;
                        }
                    }
                    break;
                case 3:
                    pilihanKembali = users.menuPengembalian();
                    if(pilihanKembali == 1 || pilihanKembali == 2 || pilihanKembali == 3){
                        if(ps.pengembalianPS(pilihanKembali, usernameFix)){
                            if(users.konfirmasiPengembalian() == 1){
                                ps.konfirmasi(pilihanKembali, usernameFix);
                                break;
                            } else{
                                break;
                            }
                        } else {
                            cout << "Tidak ada playstation yang belum dikembalikan" << endl;
                            break;
                        }
                    } else {
                        break;
                    }
                case 4:
                    ps.riwayatPemesanan(usernameFix);
                    users.menuKembali();
                    break;
                case 5:
                    usernameFix = "-1";
                    pilihanKedua = 0;
                    break;
                
            }
        }
        continue;
    }
}
