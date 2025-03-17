#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

#define MAX_BATIK 100
#define MAX_FAVORITE 50

int main() {
    string batikNames[MAX_BATIK];
    string batikOrigins[MAX_BATIK];
    string batikCategories[MAX_BATIK];
    string batikPrices[MAX_BATIK];
    int batikCount = 0;

    string adminUsername = "Wina Okta Ramadhani";
    string adminPassword = "2409106100";
    string userUsername = "Syalomitha Novindriani Depe";
    string userPassword = "2409106098";

    while (true) {
        cout << "|============================================|\n";
        cout << "|           Toko Batik Nusantara             |\n";
        cout << "|             ~Silahkan Login~               |\n";
        cout << "|============================================|\n";
        cout << "|    1. Login                                |\n";
        cout << "|    2. Exit                                 |\n";
        cout << "|============================================|\n";
        cout << "Pilih opsi: ";

        int opsi;
        cin >> opsi;
        cin.ignore();

        if (opsi == 1) {
            string username, password;
            int attempts = 0;
            bool loginSuccess = false;

            while (attempts < 3) {
                cout << "Username: ";
                getline(cin, username);
                cout << "Password: ";
                getline(cin, password);

                if ((username == adminUsername && password == adminPassword) || 
    (username == userUsername && password == userPassword)) {
    loginSuccess = true;
    cout << "\nLogin successful, Welcome! " << username << "!\n";  
    break;
} else {
    attempts++;
    cout << "\nLogin failed! Remaining login attempts: " << (3 - attempts) << "\n";
}
            }

            if (!loginSuccess) {
                cout << "You failed to login! Your access is blocked.\n";
                continue;
            }

            if (username == adminUsername && password == adminPassword) {
                int adminOption;
                do {
                    cout << "|============================================|\n";
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
                        cout << "Nama Batik: ";
                        getline(cin, batikNames[batikCount]);
                        cout << "Asal Batik: ";
                        getline(cin, batikOrigins[batikCount]);
                        cout << "Kategori (Pria/Wanita): ";
                        getline(cin, batikCategories[batikCount]);
                        cout << "Harga: ";
                        getline(cin, batikPrices[batikCount]);
                        batikCount++;
                        cout << "Batik berhasil ditambahkan!\n";
                    } 
                    else if (adminOption == 2) {
                        cout << "Daftar Batik:\n";
                        for (int i = 0; i < batikCount; i++) {
                            cout << i + 1 << ". " << batikNames[i] << " | " << batikOrigins[i] << " | " << batikCategories[i] << " | " << batikPrices[i] << "\n";
                        }
                    } 
                    else if (adminOption == 3) {
                        cout << "Masukkan nama batik yang ingin diupdate: ";
                        string namaBatik;
                        getline(cin, namaBatik);
                        bool found = false;
                        for (int i = 0; i < batikCount; i++) {
                            if (batikNames[i] == namaBatik) {
                                cout << "Nama Baru: ";
                                getline(cin, batikNames[i]);
                                cout << "Asal Baru: ";
                                getline(cin, batikOrigins[i]);
                                cout << "Kategori Baru (Pria/Wanita): ";
                                getline(cin, batikCategories[i]);
                                cout << "Harga Baru: ";
                                getline(cin, batikPrices[i]);
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
                        cout << "Masukkan nama batik yang ingin dihapus: ";
                        string namaBatik;
                        getline(cin, namaBatik);
                        bool found = false;
                        for (int i = 0; i < batikCount; i++) {
                            if (batikNames[i] == namaBatik) {
                                for (int j = i; j < batikCount - 1; j++) {
                                    batikNames[j] = batikNames[j + 1];
                                    batikOrigins[j] = batikOrigins[j + 1];
                                    batikCategories[j] = batikCategories[j + 1];
                                    batikPrices[j] = batikPrices[j + 1];
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
                } while (adminOption != 5);
            } 
            else if (username == userUsername && password == userPassword) {
                cout << "\nLogin berhasil sebagai User!\n";
                int userOption;
                do {
                    cout << "|============================================|\n";
                    cout << "|           Menu User                        |\n";
                    cout << "|============================================|\n";
                    cout << "|    1. Tampilkan Batik                      |\n";
                    cout << "|    2. Logout                               |\n";
                    cout << "|============================================|\n";
                    cout << "Pilih opsi: ";
                    cin >> userOption;
                    cin.ignore();
            
                    if (userOption == 1) {
                        for (int i = 0; i < batikCount; i++) {
                            cout << i + 1 << ". " << batikNames[i] << " | " << batikOrigins[i] << " | " << batikCategories[i] << " | " << batikPrices[i] << "\n";
                        }
                    }
                } while (userOption != 2); 
            }
        }
    }
}
