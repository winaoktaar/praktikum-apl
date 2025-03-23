#include <iostream>
#include <string>

using namespace std;

#define MAX_USERS 100
#define MAX_BATIK 100

// Struct untuk menyimpan informasi pengguna
struct User {
    string username;
    string password;
    string role; // "admin" atau "user"
};

// Struct untuk menyimpan data Batik
struct Batik {
    string name;
    string origin;
    string category;
    string price;
};

User users[MAX_USERS] = {
    {"Wina Okta Ramadhani", "2409106100", "admin"},
    {"Syalomitha Novindriani Depe", "2409106098", "user"}
};
int userCount = 2;

Batik batiks[MAX_BATIK];
int batikCount = 0;

int main() {
    while (true) {
        cout << "\n|============================================|\n";
        cout << "|           Toko Batik Nusantara             |\n";
        cout << "|        ~ Silahkan Register/Login ~         |\n";
        cout << "|============================================|\n";
        cout << "|    1. Register                             |\n";
        cout << "|    2. Login                                |\n";
        cout << "|    3. Exit                                 |\n";
        cout << "|============================================|\n";
        cout << "Pilih opsi: ";
        
        int opsi;
        cin >> opsi;
        cin.ignore();
        cout << "\n";
        
        if (opsi == 1) { // Registrasi (otomatis role user)
            if (userCount < MAX_USERS) {
                cout << "\n=== Registrasi Pengguna Baru ===\n";
                cout << "Masukkan Username: ";
                getline(cin, users[userCount].username);
                cout << "Masukkan Password: ";
                getline(cin, users[userCount].password);
                users[userCount].role = "user";
                userCount++;
                cout << "\nRegistrasi berhasil! Silakan login.\n";
            } else {
                cout << "\nMaksimum pengguna telah tercapai.\n";
            }
        }
        else if (opsi == 2) { // Login Pengguna
            string username, password;
            int attempts = 0;
            bool loginSuccess = false;
            int loggedInIndex = -1;
            
            while (attempts < 3 && !loginSuccess) {
                cout << "\nUsername: ";
                getline(cin, username);
                cout << "Password: ";
                getline(cin, password);
                for (int i = 0; i < userCount; i++) {
                    if (users[i].username == username && users[i].password == password) {
                        loginSuccess = true;
                        loggedInIndex = i;
                        cout << "\nLogin berhasil! Selamat datang, " << users[i].username << "!\n";
                        break;
                    }
                }
                if (!loginSuccess) {
                    attempts++;
                    cout << "\nLogin gagal! Kesempatan tersisa: " << (3 - attempts) << "\n";
                }
            }
            
            if (!loginSuccess) {
                cout << "\nAnda gagal login 3 kali. Akses diblokir.\n";
                continue;
            }
            
            // Menu Admin
            if (users[loggedInIndex].role == "admin") {
                int adminOption;
                do {
                    cout << "\n|============================================|\n";
                    cout << "|          Pengelolaan Batik                 |\n";
                    cout << "|============================================|\n";
                    cout << "|    1. Tambah Batik                         |\n";
                    cout << "|    2. Tampilkan Batik                      |\n";
                    cout << "|    3. Update Batik                         |\n";
                    cout << "|    4. Hapus Batik                          |\n";
                    cout << "|    5. Logout                               |\n";
                    cout << "|============================================|\n";
                    cout << "Pilih opsi: ";
                    cin >> adminOption;
                    cin.ignore();
                    
                    if (adminOption == 1 && batikCount < MAX_BATIK) {
                        cout << "\nNama Batik: ";
                        getline(cin, batiks[batikCount].name);
                        cout << "Asal Batik: ";
                        getline(cin, batiks[batikCount].origin);
                        cout << "Kategori (Pria/Wanita): ";
                        getline(cin, batiks[batikCount].category);
                        cout << "Harga: ";
                        getline(cin, batiks[batikCount].price);
                        batikCount++;
                        cout << "\nBatik berhasil ditambahkan!\n";
                    }
                    else if (adminOption == 2) {
                        cout << "\n----- Daftar Batik -----\n";
                        for (int i = 0; i < batikCount; i++) {
                            cout << i + 1 << ". " << batiks[i].name << " | "
                                 << batiks[i].origin << " | "
                                 << batiks[i].category << " | "
                                 << batiks[i].price << "\n";
                        }
                    }
                    else if (adminOption == 3) {
                        cout << "\nMasukkan nama batik yang ingin diupdate: ";
                        string namaBatik;
                        getline(cin, namaBatik);
                        bool found = false;
                        for (int i = 0; i < batikCount; i++) {
                            if (batiks[i].name == namaBatik) {
                                cout << "Nama Baru: ";
                                getline(cin, batiks[i].name);
                                cout << "Asal Baru: ";
                                getline(cin, batiks[i].origin);
                                cout << "Kategori Baru (Pria/Wanita): ";
                                getline(cin, batiks[i].category);
                                cout << "Harga Baru: ";
                                getline(cin, batiks[i].price);
                                cout << "\nBatik berhasil diupdate!\n";
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "Batik tidak ditemukan.\n";
                        }
                    }
                    else if (adminOption == 4) {
                        cout << "\nMasukkan nama batik yang ingin dihapus: ";
                        string namaBatik;
                        getline(cin, namaBatik);
                        bool found = false;
                        for (int i = 0; i < batikCount; i++) {
                            if (batiks[i].name == namaBatik) {
                                for (int j = i; j < batikCount - 1; j++) {
                                    batiks[j] = batiks[j + 1];
                                }
                                batikCount--;
                                cout << "\nBatik berhasil dihapus!\n";
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "Batik tidak ditemukan.\n";
                        }
                    }
                    else if (adminOption == 5) {
                        break;
                    }
                    else {
                        cout << "\nOpsi tidak valid.\n";
                    }
                    cout << "\nTekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } while (adminOption != 5);
            }
            // Menu User (hanya bisa melihat daftar batik)
            else {
                int userOption;
                do {
                    cout << "\n|============================================|\n";
                    cout << "|           Menu User                        |\n";
                    cout << "|============================================|\n";
                    cout << "|    1. Tampilkan Batik                      |\n";
                    cout << "|    2. Logout                               |\n";
                    cout << "|============================================|\n";
                    cout << "Pilih opsi: ";
                    cin >> userOption;
                    cin.ignore();
                    
                    if (userOption == 1) {
                        if (batikCount == 0) {
                            cout << "Belum ada batik yang tersedia.\n";
                        } else {
                            for (int i = 0; i < batikCount; i++) {
                                cout << i + 1 << ". " << batiks[i].name << " | "
                                     << batiks[i].origin << " | "
                                     << batiks[i].category << " | "
                                     << batiks[i].price << "\n";
                            }
                        }
                    }
                } while (userOption != 2);
            }
        }
        else if (opsi == 3) {
            cout << "\nTerima kasih telah menggunakan program ini!\n";
            break;
        }
        else {
            cout << "\nInput tidak valid.\n";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}