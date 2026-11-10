/*
 * ==================== PENJELASAN PROGRAM ====================
 * Soal: hitung f(n) untuk n ganjil, dengan pola
 *   f(5) = 5 * (4/2) * 3 * (2/2) * 1
 *   f(7) = 7 * (6/2) * 5 * (4/2) * 3 * (2/2) * 1
 *
 * Cara membaca pola:
 *   Mulai dari n lalu turun satu-satu sampai 1. Tiap angka jadi satu faktor:
 *   - angka GANJIL  -> faktornya angka itu sendiri  (5, 3, 1)
 *   - angka GENAP   -> faktornya angka itu dibagi 2 (4/2, 2/2)
 *
 * Rumus rekursifnya:
 *   f(1) = 1                    -> kasus dasar (berhenti)
 *   f(k) = k     * f(k-1)       -> jika k ganjil
 *   f(k) = (k/2) * f(k-1)       -> jika k genap
 *
 * Contoh yang dipakai terus di seluruh penjelasan: f(5)
 *
 * Fase 1 - memanggil diri sendiri (turun):
 *   f(5) -> 5 ganjil, jadi 5     * f(4)
 *   f(4) -> 4 genap,  jadi (4/2) * f(3)
 *   f(3) -> 3 ganjil, jadi 3     * f(2)
 *   f(2) -> 2 genap,  jadi (2/2) * f(1)
 *   f(1) -> kasus dasar, hasilnya 1
 *
 * Fase 2 - hasil dikembalikan (naik):
 *   f(1) = 1
 *   f(2) = (2/2) * 1 = 1 * 1 = 1
 *   f(3) = 3 * 1     = 3
 *   f(4) = (4/2) * 3 = 2 * 3 = 6
 *   f(5) = 5 * 6     = 30
 *
 * Cek untuk f(7): 7 * 3 * 5 * 2 * 3 * 1 * 1 = 630
 * =============================================================
 */

#include <iostream>        // dipakai untuk cin dan cout
using namespace std;       // supaya tidak perlu menulis std:: berulang kali

// Fungsi rekursif: menghitung f(k) sesuai pola di atas
long long f(int k) {
    // Kasus dasar: pada contoh f(5), rekursi berhenti saat k menjadi 1
    if (k == 1) {
        return 1;
    }

    // Jika k ganjil (pada f(5): k = 5 dan k = 3)
    // kalikan k dengan hasil f(k-1)
    if (k % 2 == 1) {
        return k * f(k - 1);
    }
    // Jika k genap (pada f(5): k = 4 dan k = 2)
    // kalikan (k/2) dengan hasil f(k-1)
    else {
        return (k / 2) * f(k - 1);
    }
}

int main() {
    int n;                                  // menyimpan angka dari pengguna (contoh: 5)

    cout << "Enter an odd number n (n >= 1): ";
    cin >> n;                               // baca nilai n (contoh: pengguna mengetik 5)

    // Validasi: n harus ganjil dan minimal 1 (contoh: 5 lolos, 4 tidak lolos)
    if (n < 1 || n % 2 == 0) {
        cout << "n must be a positive odd number." << endl;
        return 1;                           // keluar dengan kode error
    }

    // Panggil f(n) lalu tampilkan (contoh: f(5) = 30)
    cout << "f(" << n << ") = " << f(n) << endl;

    return 0;                               // program selesai tanpa error
}
