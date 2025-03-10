#include <iostream>
#include <cmath>

using namespace std;
const double PI = 3.14;
double getPositiveInput(const string& prompt);
const string USERNAME = "Wina Okta Ramadhani";
const string PASSWORD = "2409106100";


void menuUtama();
void menuLuas();
void menuKeliling();
void menuVolume();
void login();

int main() {
    login();
    return 0;
}

void login() {
    string inputUsername, inputPassword;
    int attempt = 3; 

    while (attempt > 0) {
        cout << "\n|| Please enter your username and password correctly! ||\n";
        cout << "Username: ";
        getline(cin, inputUsername);
        cout << "Password: ";
        getline(cin, inputPassword);

        if (inputUsername == USERNAME && inputPassword == PASSWORD) {
            cout << "\nLogin successful, Welcome! " << USERNAME << ".\n";
            menuUtama();
            return;
        } else {
            attempt--;
            cout << "\nLogin failed! Remaining login attempts: " << attempt << "\n";
        }
    }

    cout << "\nYou failed to login! Your access is blocked.\n";
}

void menuUtama() {
    int pilihan;
    do {
        cout << "\n===========================================\n";
        cout << "|  SISTEM HITUNG BANGUN DATAR & RUANG     |\n";
        cout << "===========================================\n";
        cout << "| 1. Hitung luas                          |\n";
        cout << "| 2. Hitung keliling                      |\n";
        cout << "| 3. Hitung volume                        |\n";
        cout << "| 4. eXIT                                 |\n";
        cout << "===========================================\n";
        cout << "Pilih menu: "; cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1: menuLuas(); break;
            case 2: menuKeliling(); break;
            case 3: menuVolume(); break;
            case 4: cout << "Logout berhasil.\n"; return;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (true);
}

void menuLuas() {
    int pilihan;
    double sisi, panjang, lebar, rr, alas, tinggi;
    do {
        cout << "\n===========================================\n";
        cout << "|           HITUNG LUAS                   |\n";
        cout << "===========================================\n";
        cout << "| 1. Persegi                              |\n";
        cout << "| 2. Persegi Panjang                      |\n";
        cout << "| 3. Lingkaran                            |\n";
        cout << "| 4. Segitiga                             |\n";
        cout << "| 5. Trapesium                            |\n"; 
        cout << "| 6. Kembali Menu Utama                   |\n";
        cout << "===========================================\n";
        cout << "Pilih: "; cin >> pilihan;
        
        switch (pilihan) {
            case 1: 
                sisi = getPositiveInput("Sisi: ");
                cout << "Luas: " << sisi * sisi << "\n"; 
                break;
                break;
            case 2: 
                panjang = getPositiveInput("Panjang: ");
                lebar = getPositiveInput("Lebar: ");
                cout << "Luas: " << panjang * lebar << "\n"; 
                break;
                break;
            case 3: 
                rr = getPositiveInput("Jari-jari: ");
                cout << "Luas: " << PI * rr * rr << "\n"; 
                break;
                break;
            case 4: 
                alas = getPositiveInput("Alas: ");
                tinggi = getPositiveInput("Tinggi: ");
                cout << "Luas: " << 0.5 * alas * tinggi << "\n"; 
                break;
                break;
            case 5: // Trapesium
                double alas1, alas2;
                alas1 = getPositiveInput("Alas 1: ");
                alas2 = getPositiveInput("Alas 2: ");
                tinggi = getPositiveInput("Tinggi: ");
                cout << "Luas: " << 0.5 * (alas1 + alas2) * tinggi << "\n"; 
                break;
                break;
            case 6: return;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (true);
}

void menuKeliling() {
    int pilihan;
    double sisi, panjang, lebar, rr, sisi_i, sisi_n, sisi_a;
    do {
        cout << "\n===========================================\n";
        cout << "|          HITUNG KELILING                |\n";
        cout << "===========================================\n";
        cout << "| 1. Persegi                              |\n";
        cout << "| 2. Persegi Panjang                      |\n";
        cout << "| 3. Lingkaran                            |\n";
        cout << "| 4. Segitiga                             |\n";
        cout << "| 5. Kembali                              |\n";
        cout << "===========================================\n";
        cout << "Pilih: "; cin >> pilihan;
        
        switch (pilihan) {
            case 1: 
                sisi = getPositiveInput("Sisi: ");
                cout << "Keliling: " << 4 * sisi << "\n"; 
                break;
            case 2: 
                panjang = getPositiveInput("Panjang: ");
                lebar = getPositiveInput("Lebar: ");
                cout << "Keliling: " << 2 * (panjang + lebar) << "\n"; 
                break;
            case 3: 
                rr = getPositiveInput("Jari-jari: ");
                cout << "Keliling: " << 2 * PI * rr << "\n"; 
                break;
            case 4: 
                cout << "Sisi 1: "; cin >> sisi_i; 
                cout << "Sisi 2: "; cin >> sisi_n; 
                cout << "Sisi 3: "; cin >> sisi_a; 
                cout << "Keliling: " << sisi_i + sisi_n + sisi_a << "\n"; 
                break;
            case 5: return;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (true);
}

void menuVolume() {
    int pilihan;
    double sisi, panjang, lebar, tinggi, rr;
    do {
        cout << "\n===========================================\n";
        cout << "|          HITUNG VOLUME                  |\n";
        cout << "===========================================\n";
        cout << "| 1. Kubus                                |\n";
        cout << "| 2. Balok                                |\n";
        cout << "| 3. Bola                                 |\n";
        cout << "| 4. Kerucut                              |\n";
        cout << "| 5. Kembali                              |\n";
        cout << "===========================================\n";
        cout << "Pilih: "; 
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: 
                sisi = getPositiveInput("Sisi: ");
                cout << "Volume: " << sisi * sisi * sisi << "\n"; 
                break;
            case 2: 
                panjang = getPositiveInput("Panjang: ");
                lebar = getPositiveInput("Lebar: ");
                tinggi = getPositiveInput("Tinggi: ");
                cout << "Volume: " << panjang * lebar * tinggi << "\n"; 
                break;
            case 3: 
                rr = getPositiveInput("Jari-jari: ");
                cout << "Volume: " << (4.0 / 3) * PI * rr * rr * rr << "\n"; 
                break;
            case 4: 
                rr = getPositiveInput("Jari-jari: ");
                tinggi = getPositiveInput("Tinggi: ");
                cout << "Volume: " << (1.0 / 3) * PI * rr * rr * tinggi << "\n"; 
                break;
            case 5: return;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (true);
}

double getPositiveInput(const string& prompt) {
    double value;
    do {
        cout << prompt;
        cin >> value;
        if (value < 0) {
            cout << "Input tidak boleh negatif. Silakan coba lagi.\n";
        }
    } while (value < 0);
    return value;
}
