#include <iostream>
#include <string>

using namespace std;

#define MAX_USERS 100
#define MAX_BATIK 100

struct User {
    string username;
    string password;
    string role; // "admin" atau "user" yang mau login
};

struct Batik {
    string nama;
    string asal;     
    string kategori;
    string harga;
};

User users[MAX_USERS] = {
    {"Wina Okta Ramadhani", "2409106100", "admin"},
    {"Syalomitha Novindriani Depe", "2409106098", "user"}
};
int userCount = 2;

Batik batiks[MAX_BATIK];
int batikCount = 0;

// ini deklarasi fungsi dan prosedur
void registerUser(User users[], int &userCount);
int login(User users[], int userCount, int attempts = 3);
void adminMenu(Batik batiks[], int &batikCount);
void userMenu(Batik batiks[], int batikCount);
void tambahBatik(Batik batiks[], int &batikCount);
void tampilkanBatik(Batik batiks[], int batikCount);
void tampilkanBatik(Batik batiks[], int batikCount, string kategori); // ini penerapan fungsi overloading nyaa
void updateBatik(Batik batiks[], int batikCount);
void hapusBatik(Batik batiks[], int &batikCount);

int main() {
    int opsi;
    do {
        cout << "\n|============================================|\n";
        cout << "|           Toko Batik Nusantara             |\n";
        cout << "|        ~ Silahkan Register/Login ~         |\n";
        cout << "|============================================|\n";
        cout << "|    1. Register                             |\n";
        cout << "|    2. Login                                |\n";
        cout << "|    3. Exit                                 |\n";
        cout << "|============================================|\n";
        cout << "Pilih opsi: ";
        cin >> opsi;
        cin.ignore();

        if (opsi == 1) {
            registerUser(users, userCount);
        } else if (opsi == 2) {
            int loggedInIndex = login(users, userCount);
            if (loggedInIndex != -1) {
                if (users[loggedInIndex].role == "admin") {
                    adminMenu(batiks, batikCount);
                } else {
                    userMenu(batiks, batikCount);
                }
            }
        } else if (opsi == 3) {
            cout << "Terima kasih telah menggunakan program ini!\n";
        } else {
            cout << "Input tidak valid!\n";
        }

    } while (opsi != 3);

    return 0;
}

// definisi fungsi dan prosedur

void registerUser(User users[], int &userCount) {
    if (userCount >= MAX_USERS) {
        cout << "Jumlah maksimum user telah tercapai.\n";
        return;
    }

    cout << "\n=== Registrasi Pengguna Baru ===\n";
    cout << "Masukkan Username: ";
    getline(cin, users[userCount].username);
    cout << "Masukkan Password: ";
    getline(cin, users[userCount].password);
    users[userCount].role = "user";
    userCount++;

    cout << "Registrasi berhasil! Silakan login.\n";
}

int login(User users[], int userCount, int attempts) {
    if (attempts == 0) {
        cout << "Anda gagal login 3 kali. Akses diblokir.\n";
        return -1;
    }

    string username, password;
    cout << "\nUsername: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username && users[i].password == password) {
            cout << "Login berhasil! Selamat datang, " << users[i].username << "!\n";
            return i;
        }
    }

    cout << "Login gagal! Kesempatan tersisa: " << (attempts - 1) << "\n";
    return login(users, userCount, attempts - 1); // ini penerapan fungsi rekursif nyaa
}

void adminMenu(Batik batiks[], int &batikCount) {
    int adminOption;
    do {
        cout << "\n|========= Menu Admin =========|\n";
        cout << "1. Tambah Batik\n";
        cout << "2. Tampilkan Semua Batik\n";
        cout << "3. Tampilkan Batik Wanita (Overload)\n";
        cout << "4. Update Batik\n";
        cout << "5. Hapus Batik\n";
        cout << "6. Logout\n";
        cout << "Pilih opsi: ";
        cin >> adminOption;
        cin.ignore();

        switch (adminOption) {
            case 1: tambahBatik(batiks, batikCount); break;
            case 2: tampilkanBatik(batiks, batikCount); break;
            case 3: tampilkanBatik(batiks, batikCount, "Wanita"); break;
            case 4: updateBatik(batiks, batikCount); break;
            case 5: hapusBatik(batiks, batikCount); break;
            case 6: cout << "Logout...\n"; break;
            default: cout << "Opsi tidak valid.\n";
        }
    } while (adminOption != 6);
}

void userMenu(Batik batiks[], int batikCount) {
    int userOption;
    do {
        cout << "\n|========= Menu User =========|\n";
        cout << "1. Lihat Semua Batik\n";
        cout << "2. Logout\n";
        cout << "Pilih opsi: ";
        cin >> userOption;
        cin.ignore();

        if (userOption == 1) {
            tampilkanBatik(batiks, batikCount);
        }

    } while (userOption != 2);
}

void tambahBatik(Batik batiks[], int &batikCount) {
    if (batikCount >= MAX_BATIK) {
        cout << "Kapasitas penyimpanan batik penuh.\n";
        return;
    }

    cout << "\n=== Tambah Batik Baru ===\n";
    cout << "Nama: ";
    getline(cin, batiks[batikCount].nama);
    cout << "Asal: ";
    getline(cin, batiks[batikCount].asal);
    cout << "Kategori (Pria/Wanita): ";
    getline(cin, batiks[batikCount].kategori);
    cout << "Harga: ";
    getline(cin, batiks[batikCount].harga);
    batikCount++;

    cout << "Batik berhasil ditambahkan!\n";
}

void tampilkanBatik(Batik batiks[], int batikCount) {
    cout << "\n=== Daftar Batik ===\n";
    for (int i = 0; i < batikCount; i++) {
        cout << i + 1 << ". " << batiks[i].nama << " | "
             << batiks[i].asal << " | "
             << batiks[i].kategori << " | "
             << batiks[i].harga << "\n";
    }
}

// Fungsi Overloading: tampilkan batik berdasarkan kategori
void tampilkanBatik(Batik batiks[], int batikCount, string kategori) {
    cout << "\n=== Daftar Batik Kategori " << kategori << " ===\n";
    for (int i = 0; i < batikCount; i++) {
        if (batiks[i].kategori == kategori) {
            cout << i + 1 << ". " << batiks[i].nama << " | "
                 << batiks[i].asal << " | "
                 << batiks[i].kategori << " | "
                 << batiks[i].harga << "\n";
        }
    }
}

void updateBatik(Batik batiks[], int batikCount) {
    cout << "\nMasukkan nama batik yang ingin diupdate: ";
    string nama;
    getline(cin, nama);
    for (int i = 0; i < batikCount; i++) {
        if (batiks[i].nama == nama) {
            cout << "Nama Baru: ";
            getline(cin, batiks[i].nama);
            cout << "Asal Baru: ";
            getline(cin, batiks[i].asal);
            cout << "Kategori Baru: ";
            getline(cin, batiks[i].kategori);
            cout << "Harga Baru: ";
            getline(cin, batiks[i].harga);
            cout << "Batik berhasil diupdate!\n";
            return;
        }
    }
    cout << "Batik tidak ditemukan.\n";
}

void hapusBatik(Batik batiks[], int &batikCount) {
    cout << "\nMasukkan nama batik yang ingin dihapus: ";
    string nama;
    getline(cin, nama);
    for (int i = 0; i < batikCount; i++) {
        if (batiks[i].nama == nama) {
            for (int j = i; j < batikCount - 1; j++) {
                batiks[j] = batiks[j + 1];
            }
            batikCount--;
            cout << "Batik berhasil dihapus!\n";
            return;
        }
    }
    cout << "Batik tidak ditemukan.\n";
}
