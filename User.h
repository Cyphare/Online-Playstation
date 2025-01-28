#ifndef USER_H
#define USER_H


class User: public userInterface {
    private:
    int targetLine;
    string checkUsername;
    string checkPassword;
    int pilihanRegister;
    string username, password, rePassword;
    bool isCorrect;
    string nama, email; 
    string noTelp, idNumber;
    int balance, plusBalance;
    
    public :

    bool regist();
    //Fungsi untuk melakukan signup member
    //Postcondition: Mengembalikan true jika proses signup berhasil, false jika sebaliknya

    bool loginAsMember();
    //Fungsi untuk melakukan login member
    //Postcondition: Mengembalikan true jika proses login berhasil, false jika sebaliknya

    bool loginAsAdministrator();
    //Fungsi untuk melakukan login administrator
    //Postcondition: Mengembalikan true jika proses login berhasil, false jika sebaliknya

    void listUserTerdaftar();
    //Fungsi untuk menampilkan semua member yang terdaftar
    //Postcondition: Profil semua member yang telah mendaftar akan dicetak di terminal
    
    int profil(string us);
    //Fungsi untuk menampilkan profil member yang telah login
    //Postcondition: Profil akan dicetak di terminal

    void updateData(string us);
    //Fungsi untuk mengubah data menjadi data terbaru
    //Postcondition: Menginput data terbaru kemudian mencetak ulang di account.txt

    void Delete(string us);
    //Fungsi untuk menghapus akun
    //Postcondition: Menghapus akun di account.txt
    
    void addBalance(string us);
    //Fungsi untuk menambahkan balance di akun
    //Postcondition: Mencetak ulang balance di account.txt

    string mulai();
    //Fungsi untuk mengatur login, sign up, dan login as administrator
    //Postcondition: Mengembalikan username;

};
#endif // USER_H
