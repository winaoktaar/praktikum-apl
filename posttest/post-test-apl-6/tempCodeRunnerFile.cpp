#include <iostream>
#include <string>

using namespace std;

#define MAKS_PENGGUNA 100
#define MAKS_BATIK 100

struct Pengguna {
    string namaPengguna;
    string kataSandi;
    string peran; // yang mo login user atau admin
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

// Cetak satu Batik dengan pointer
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
        cout << "|        ~ Silahkan Daftar/Masuk ~           |\n";
        cout << "|============================================|\n";
        cout << "|    1. Daftar                               |\n";
        cout << "|    2. Masuk                                |\n";
        cout << "|    3. Keluar                               |\n";
        cout << "|============================================|\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            daftarPenggunaBaru(daftarPengguna, &jumlahPengguna);
        } else if (pilihan == 2) {
            int idxLogin = masuk(daftarPengguna, jumlahPengguna);
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
    cout << "Daftar berhasil! Silakan masuk.\n";
}

int masuk(Pengguna daftar[], int jumlahPengguna, int kesempatan) {
    if (kesempatan == 0) {
        cout << "Akses diblokir setelah 3 kali gagal.\n";
        return -1;
    }
    string namaPengguna, kataSandi;
    cout << "\nNama Pengguna: "; getline(cin, namaPengguna);
    cout << "Kata Sandi: "; getline(cin, kataSandi);
    for (int i = 0; i < jumlahPengguna; i++) {
        if (daftar[i].namaPengguna == namaPengguna && daftar[i].kataSandi == kataSandi) {
            cout << "Masuk berhasil! Selamat, " << daftar[i].namaPengguna << "!\n";
            return i;
        }
    }
    cout << "Gagal masuk! Kesempatan tersisa: " << kesempatan - 1 << "\n";
    return masuk(daftar, jumlahPengguna, kesempatan - 1);
}

void menuAdmin(Batik daftar[], int &jumlahBatik) {
    int pilihanAdmin;
    do {
        cout << "\n|===== Menu Admin =====|\n";
        cout << "1. Tambah Batik\n";
        cout << "2. Tampilkan Semua Batik\n";
        cout << "3. Tampilkan Batik Wanita\n";
        cout << "4. Ubah Batik\n";
        cout << "5. Hapus Batik\n";
        cout << "6. Tukar Batik\n";
        cout << "7. Urut Nama Menurun\n";
        cout << "8. Urut Harga Menaik\n";
        cout << "9. Urut Asal Menaik\n";
        cout << "10. Keluar\n";
        cout << "Pilih menu: "; cin >> pilihanAdmin; cin.ignore();
        switch (pilihanAdmin) {
            case 1: tambahBatik(daftar, &jumlahBatik); break;
            case 2: tampilkanBatik(daftar, jumlahBatik); break;
            case 3: tampilkanBatik(daftar, jumlahBatik, "Wanita"); break;
            case 4: ubahBatik(daftar, jumlahBatik); break;
            case 5: hapusBatik(daftar, &jumlahBatik); break;
            case 6: {
                int idx1, idx2;
                cout << "Indeks 1 dan 2 (1-based): "; cin >> idx1 >> idx2; cin.ignore();
                if (idx1<=jumlahBatik && idx2<=jumlahBatik)
                    tukarBatik(&daftar[idx1-1], &daftar[idx2-1]), cout<<"Tukar berhasil!\n";
                else cout<<"Indeks tidak valid.\n";
            } break;
            case 7: urutNamaMenurun(daftar, jumlahBatik); cout<<"Nama diurut menurun.\n"; break;
            case 8: urutHargaMenaik(daftar, jumlahBatik); cout<<"Harga diurut menaik.\n"; break;
            case 9: urutAsalMenaik(daftar, jumlahBatik); cout<<"Asal diurut menaik.\n"; break;
            case 10: cout<<"Keluar...\n"; break;
            default: cout<<"Pilihan tidak valid.\n";
        }
    } while (pilihanAdmin != 10);
}

void menuUser(Batik daftar[], int jumlahBatik) {
    int pilihanUser;
    do {
        cout << "\n|===== Menu User =====|\n";
        cout << "1. Lihat Batik\n";
        cout << "2. Keluar\n";
        cout << "Pilih menu: "; cin >> pilihanUser; cin.ignore();
        if (pilihanUser == 1) tampilkanBatik(daftar, jumlahBatik);
    } while (pilihanUser != 2);
}

void tambahBatik(Batik daftar[], int *jumlahBatik) {
    if (*jumlahBatik >= MAKS_BATIK) { cout<<"Penuh.\n"; return; }
    cout<<"\n=== Tambah Batik ===\n";
    cout<<"Nama: "; getline(cin, daftar[*jumlahBatik].nama);
    cout<<"Asal: "; getline(cin, daftar[*jumlahBatik].asal);
    cout<<"Kategori: "; getline(cin, daftar[*jumlahBatik].kategori);
    cout<<"Harga: "; cin>>daftar[*jumlahBatik].harga; cin.ignore();
    tambahJumlah(jumlahBatik);
    cout<<"Batik berhasil ditambah!\n";
}

void tampilkanBatik(Batik daftar[], int jumlahBatik) {
    cout<<"\n=== Daftar Batik ===\n";
    for (int i=0; i<jumlahBatik; i++)
        cetakBatik(&daftar[i]);
}

void tampilkanBatik(Batik daftar[], int jumlahBatik, const string &kategori) {
    cout<<"\n=== Batik Kategori "<<kategori<<" ===\n";
    for (int i=0; i<jumlahBatik; i++)
        if (daftar[i].kategori == kategori)
            cetakBatik(&daftar[i]);
}

void ubahBatik(Batik daftar[], int jumlahBatik) {
    cout<<"Nama batik yang diubah: "; string namaCari; getline(cin, namaCari);
    for (int i=0; i<jumlahBatik; i++) {
        if (daftar[i].nama == namaCari) {
            cout<<"Nama Baru: "; getline(cin, daftar[i].nama);
            cout<<"Asal Baru: "; getline(cin, daftar[i].asal);
            cout<<"Kategori Baru: "; getline(cin, daftar[i].kategori);
            cout<<"Harga Baru: "; cin>>daftar[i].harga; cin.ignore();
            cout<<"Batik berhasil diubah!\n";
            return;
        }
    }
    cout<<"Batik tidak ditemukan.\n";
}

void hapusBatik(Batik daftar[], int *jumlahBatik) {
    cout<<"Nama batik yang dihapus: "; string namaCari; getline(cin, namaCari);
    for (int i=0; i<*jumlahBatik; i++) {
        if (daftar[i].nama == namaCari) {
            for (int j=i; j<*jumlahBatik-1; j++)
                daftar[j] = daftar[j+1];
            (*jumlahBatik)--;
            cout<<"Batik berhasil dihapus!\n";
            return;
        }
    }
    cout<<"Batik tidak ditemukan.\n";
}

// alhamdulilah Selesai dehh :D