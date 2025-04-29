#include <iostream>
#include <string>
#include <cstdlib>  // ini buat exit nya getohh

using namespace std;

#define MAKS_PENGGUNA 100
#define MAKS_BATIK 100

struct Pengguna {
    string namaPengguna;
    string kataSandi;
    string peran; // yang mo login admin atau user
};

struct Batik {
    string nama;
    string asal;
    string kategori;
    double harga;
};

Pengguna daftarPengguna[MAKS_PENGGUNA] = {
    {"Wina Okta Ramadhani", "2409106100", "admin"},
    {"Syalomitha Novindriani Depe", "2409106098", "user"}
};
int jumlahPengguna = 2;

Batik daftarBatik[MAKS_BATIK];
int jumlahBatik = 0;

// Fungsi pointer menggunakan increment dengan dereference
void tambahJumlah(int *jumlah) {
    (*jumlah)++;
}

// Fungsi tukar dua Batik menggunakan pointer & dereference
void tukarBatik(Batik *b1, Batik *b2) {
    Batik temp = *b1;
    *b1 = *b2;
    *b2 = temp;
}

// Cetak satu Batik menggunakan pointer
void cetakBatik(const Batik *b) {
    cout << b->nama << " | " << b->asal
         << " | " << b->kategori << " | "
         << b->harga << endl;
}

// Sorting nama descending
void urutNamaMenurun(Batik daftar[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (daftar[j].nama < daftar[j + 1].nama) {
                tukarBatik(&daftar[j], &daftar[j + 1]);
            }
        }
    }
}

// Sorting harga ascending
void urutHargaMenaik(Batik daftar[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (daftar[j].harga > daftar[j + 1].harga) {
                tukarBatik(&daftar[j], &daftar[j + 1]);
            }
        }
    }
}

// Sorting asal ascending
void urutAsalMenaik(Batik daftar[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (daftar[j].asal > daftar[j + 1].asal) {
                tukarBatik(&daftar[j], &daftar[j + 1]);
            }
        }
    }
}

// Deklarasi fungsi dan prosedur
void daftarPenggunaBaru(Pengguna daftar[], int *jumlahPengguna);
int masuk(Pengguna daftar[], int jumlahPengguna, int kesempatan = 3);
void menuAdmin(Batik daftar[], int &jumlahBatik);
void menuUser(Batik daftar[], int jumlahBatik);
void tambahBatik(Batik daftar[], int *jumlahBatik);
void tampilkanBatik(Batik daftar[], int jumlahBatik);
void tampilkanBatik(Batik daftar[], int jumlahBatik, const string &kategori);
void ubahBatik(Batik daftar[], int jumlahBatik);
void hapusBatik(Batik daftar[], int *jumlahBatik);

int main() {
    int pilihan;
    do {
        cout << "\n|============================================|\n";
        cout << "|           Toko Batik Nusantara             |\n";
        cout << "|      ~ Please Register or Login ~          |\n";
        cout << "|============================================|\n";
        cout << "|    1. Register                            |\n";
        cout << "|    2. Login                               |\n";
        cout << "|    3. Exit                                |\n";
        cout << "|============================================|\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            daftarPenggunaBaru(daftarPengguna, &jumlahPengguna);
        } else if (pilihan == 2) {
            int idxLogin = masuk(daftarPengguna, jumlahPengguna);
            // jika berhasil login masuk menu sesuai role
            if (idxLogin != -1) {
                if (daftarPengguna[idxLogin].peran == "admin")
                    menuAdmin(daftarBatik, jumlahBatik);
                else
                    menuUser(daftarBatik, jumlahBatik);
            }
        } else if (pilihan == 3) {
            cout << "Terima kasih!\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);
    return 0;
}

void daftarPenggunaBaru(Pengguna daftar[], int *jumlahPengguna) {
    if (*jumlahPengguna >= MAKS_PENGGUNA) {
        cout << "Kapasitas pengguna penuh.\n";
        return;
    }
    cout << "\n=== Daftar Pengguna Baru ===\n";
    cout << "Nama Pengguna: "; getline(cin, daftar[*jumlahPengguna].namaPengguna);
    cout << "Kata Sandi: "; getline(cin, daftar[*jumlahPengguna].kataSandi);
    daftar[*jumlahPengguna].peran = "user";
    tambahJumlah(jumlahPengguna);
    cout << "Daftar berhasil! Silakan login.\n";
}

int masuk(Pengguna daftar[], int jumlahPengguna, int kesempatan) {
    if (kesempatan == 0) {
        cout << "Gagal login 3 kali. Program selesai.\n";
        exit(0);  // program berhenti setelah 3 kali gagal login
    }
    string namaPengguna, kataSandi;
    cout << "\nNama Pengguna: "; getline(cin, namaPengguna);
    cout << "Kata Sandi: "; getline(cin, kataSandi);
    for (int i = 0; i < jumlahPengguna; i++) {
        if (daftar[i].namaPengguna == namaPengguna && daftar[i].kataSandi == kataSandi) {
            cout << "Login berhasil! Selamat, " << daftar[i].namaPengguna << "!\n";
            return i;
        }
    }
    cout << "Login gagal! Kesempatan tersisa: " << (kesempatan - 1) << "\n";
    return masuk(daftar, jumlahPengguna, kesempatan - 1);
}

void menuAdmin(Batik daftar[], int &jumlahBatik) {
    int pilihanAdmin;
    do {
        cout << "\n|============================================|\n";
        cout << "|               Menu Admin                  |\n";
        cout << "|============================================|\n";
        cout << "| 1. Tambah Batik                           |\n";
        cout << "| 2. Tampilkan Batik                        |\n";
        cout << "| 3. Update Batik                           |\n";
        cout << "| 4. Hapus Batik                            |\n";
        cout << "| 5. Logout                                 |\n";
        cout << "|============================================|\n";
        cout << "Pilih menu: "; cin >> pilihanAdmin; cin.ignore();
        switch (pilihanAdmin) {
            case 1: tambahBatik(daftar, &jumlahBatik); break;
            case 2: tampilkanBatik(daftar, jumlahBatik); break;
            case 3: ubahBatik(daftar, jumlahBatik); break;
            case 4: hapusBatik(daftar, &jumlahBatik); break;
            case 5: cout << "Logout...\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihanAdmin != 5);
}

void menuUser(Batik daftar[], int jumlahBatik) {
    int pilihanUser;
    do {
        cout << "\n|============================================|\n";
        cout << "|               Menu User                   |\n";
        cout << "|============================================|\n";
        cout << "| 1. Tampilkan Batik                        |\n";
        cout << "| 2. Logout                                 |\n";
        cout << "|============================================|\n";
        cout << "Pilih menu: "; cin >> pilihanUser; cin.ignore();
        switch (pilihanUser) {
            case 1: tampilkanBatik(daftar, jumlahBatik); break;
            case 2: cout << "Logout...\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihanUser != 2);
}

void tambahBatik(Batik daftar[], int *jumlahBatik) {
    if (*jumlahBatik >= MAKS_BATIK) { cout << "Penuh.\n"; return; }
    cout << "\n=== Tambah Batik ===\n";
    cout << "Nama: "; getline(cin, daftar[*jumlahBatik].nama);
    cout << "Asal: "; getline(cin, daftar[*jumlahBatik].asal);
    cout << "Kategori: "; getline(cin, daftar[*jumlahBatik].kategori);
    cout << "Harga: "; cin >> daftar[*jumlahBatik].harga; cin.ignore();
    tambahJumlah(jumlahBatik);
    cout << "Batik berhasil ditambah!\n";
}

void tampilkanBatik(Batik daftar[], int jumlahBatik) {
    cout << "\n=== Daftar Batik ===\n";
    for (int i = 0; i < jumlahBatik; i++)
        cetakBatik(&daftar[i]);
}

void tampilkanBatik(Batik daftar[], int jumlahBatik, const string &kategori) {
    cout << "\n=== Batik Kategori " << kategori << " ===\n";
    for (int i = 0; i < jumlahBatik; i++)
        if (daftar[i].kategori == kategori)
            cetakBatik(&daftar[i]);
}

void ubahBatik(Batik daftar[], int jumlahBatik) {
    cout << "Nama batik yang diubah: "; string namaCari; getline(cin, namaCari);
    for (int i = 0; i < jumlahBatik; i++) {
        if (daftar[i].nama == namaCari) {
            cout << "Nama Baru: "; getline(cin, daftar[i].nama);
            cout << "Asal Baru: "; getline(cin, daftar[i].asal);
            cout << "Kategori Baru: "; getline(cin, daftar[i].kategori);
            cout << "Harga Baru: "; cin >> daftar[i].harga; cin.ignore();
            cout << "Batik berhasil diubah!\n";
            return;
        }
    }
    cout << "Batik tidak ditemukan.\n";
}

void hapusBatik(Batik daftar[], int *jumlahBatik) {
    cout << "Nama batik yang dihapus: "; string namaCari; getline(cin, namaCari);
    for (int i = 0; i < *jumlahBatik; i++) {
        if (daftar[i].nama == namaCari) {
            for (int j = i; j < *jumlahBatik - 1; j++)
                daftar[j] = daftar[j + 1];
            (*jumlahBatik)--;
            cout << "Batik berhasil dihapus!\n";
            return;
        }
    }
    cout << "Batik tidak ditemukan.\n";
}

// Alhamdulilah selesai dehhh :D