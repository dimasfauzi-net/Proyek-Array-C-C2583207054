#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PROD 50

// Deklarasi Array Global sesuai ketentuan
char nama[MAX_PROD][50] = {"Nasi Goreng", "Mie Ayam", "Es Teh Manis", "Roti Bakar", "Kopi Hitam"};
int harga[MAX_PROD] = {15000, 12000, 4000, 10000, 5000};
int stok[MAX_PROD] = {20, 15, 30, 10, 25};
int terjual[MAX_PROD] = {0, 0, 0, 0, 0};

int jumlah_produk = 5;

// Fungsi utilitas untuk pencarian agar tidak case-sensitive
int cocokkanString(char *str, char *keyword) {
    char tempStr[50], tempKey[50];
    strcpy(tempStr, str);
    strcpy(tempKey, keyword);
    for(int i = 0; tempStr[i]; i++) tempStr[i] = tolower(tempStr[i]);
    for(int i = 0; tempKey[i]; i++) tempKey[i] = tolower(tempKey[i]);
    return strstr(tempStr, tempKey) != NULL;
}

// 1. Fitur Lihat Daftar Produk
void tampilProduk() {
    printf("\n=== DAFTAR PRODUK ===\n");
    printf("%-5s | %-20s | %-12s | %-5s\n", "No", "Nama Produk", "Harga (Rp)", "Stok");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < jumlah_produk; i++) {
        printf("%-5d | %-20s | %-12d | %-5d\n", i + 1, nama[i], harga[i], stok[i]);
    }
}

// 2. Fitur Tambah Produk
void tambahProduk() {
    if (jumlah_produk >= MAX_PROD) {
        printf("Kapasitas penyimpanan penuh (Maksimal %d produk)!\n", MAX_PROD);
        return;
    }

    printf("\n--- TAMBAH PRODUK BARU ---\n");
    printf("Masukkan Nama Produk: ");
    scanf(" %[^\n]s", nama[jumlah_produk]);

    do {
        printf("Masukkan Harga: Rp ");
        scanf("%d", &harga[jumlah_produk]);
        if(harga[jumlah_produk] < 0) printf("Error: Harga tidak boleh negatif!\n");
    } while (harga[jumlah_produk] < 0);

    do {
        printf("Masukkan Stok Awal: ");
        scanf("%d", &stok[jumlah_produk]);
        if(stok[jumlah_produk] < 0) printf("Error: Stok tidak boleh negatif!\n");
    } while (stok[jumlah_produk] < 0);

    terjual[jumlah_produk] = 0;
    jumlah_produk++;
    printf("Produk berhasil ditambahkan!\n");
}

// 3. Fitur Ubah Produk
void ubahProduk() {
    tampilProduk();
    int pilihan;
    printf("\nMasukkan nomor produk yang ingin diubah (0 untuk batal): ");
    scanf("%d", &pilihan);

    if (pilihan == 0) return;
    if (pilihan < 1 || pilihan > jumlah_produk) {
        printf("Error: Nomor produk tidak ditemukan!\n");
        return;
    }

    int idx = pilihan - 1;
    do {
        printf("Masukkan Harga Baru untuk %s (Saat ini: %d): ", nama[idx], harga[idx]);
        scanf("%d", &harga[idx]);
        if(harga[idx] < 0) printf("Error: Harga tidak boleh negatif!\n");
    } while (harga[idx] < 0);

    do {
        printf("Masukkan Stok Baru untuk %s (Saat ini: %d): ", nama[idx], stok[idx]);
        scanf("%d", &stok[idx]);
        if(stok[idx] < 0) printf("Error: Stok tidak boleh negatif!\n");
    } while (stok[idx] < 0);

    printf("Data produk berhasil diperbarui!\n");
}

// 4. Fitur Transaksi Penjualan (Mendukung beberapa produk)
void transaksiPenjualan() {
    int pilihan, qty;
    long total_pembayaran = 0;
    char lanjut;

    printf("\n=== TRANSAKSI PENJUALAN ===\n");
    do {
        tampilProduk();
        printf("\nMasukkan nomor produk yang dibeli: ");
        scanf("%d", &pilihan);

        if (pilihan < 1 || pilihan > jumlah_produk) {
            printf("Error: Nomor produk tidak ditemukan!\n");
        } else {
            int idx = pilihan - 1;
            printf("Masukkan jumlah pembelian untuk '%s': ", nama[idx]);
            scanf("%d", &qty);

            if (qty <= 0) {
                printf("Error: Jumlah pembelian harus lebih dari 0!\n");
            } else if (qty > stok[idx]) {
                printf("Error: Transaksi ditolak! Jumlah melebihi stok yang tersedia (%d).\n", stok[idx]);
            } else {
                stok[idx] -= qty;
                terjual[idx] += qty;
                long subtotal = harga[idx] * qty;
                total_pembayaran += subtotal;
                printf("-> %d %s berhasil ditambahkan ke keranjang. (Subtotal: Rp %ld)\n", qty, nama[idx], subtotal);
            }
        }

        printf("\nBeli produk lain? (y/n): ");
        scanf(" %c", &lanjut);
    } while (lanjut == 'y' || lanjut == 'Y');

    printf("\n===================================\n");
    printf("Total Pembayaran Keseluruhan: Rp %ld\n", total_pembayaran);
    printf("===================================\n");
}

// 5. Fitur Tambah Stok
void tambahStok() {
    tampilProduk();
    int pilihan, tambahan;
    printf("\nMasukkan nomor produk untuk ditambah stok (0 untuk batal): ");
    scanf("%d", &pilihan);

    if (pilihan == 0) return;
    if (pilihan < 1 || pilihan > jumlah_produk) {
        printf("Error: Nomor produk tidak ditemukan!\n");
        return;
    }

    int idx = pilihan - 1;
    printf("Masukkan jumlah stok yang ingin ditambahkan: ");
    scanf("%d", &tambahan);

    if (tambahan <= 0) {
        printf("Error: Jumlah penambahan harus lebih dari 0!\n");
    } else {
        stok[idx] += tambahan;
        printf("Stok berhasil ditambah! Stok %s saat ini menjadi %d.\n", nama[idx], stok[idx]);
    }
}

// 6. Fitur Cari Produk
void cariProduk() {
    char keyword[50];
    int found = 0;
    printf("\nMasukkan nama produk yang dicari: ");
    scanf(" %[^\n]s", keyword);

    printf("\n--- HASIL PENCARIAN ---\n");
    for (int i = 0; i < jumlah_produk; i++) {
        if (cocokkanString(nama[i], keyword)) {
            printf("%d. %s - Rp %d (Stok: %d)\n", i + 1, nama[i], harga[i], stok[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Tidak ada produk yang cocok dengan kata kunci '%s'.\n", keyword);
    }
}

// 7. Fitur Urutkan Produk (Bubble Sort)
void urutkanProduk() {
    int pilihan;
    printf("\n--- PENGURUTAN PRODUK ---\n");
    printf("1. Berdasarkan Harga (Termurah ke Termahal)\n");
    printf("2. Berdasarkan Jumlah Terjual (Terbanyak ke Sedikit)\n");
    printf("Pilih metode (1/2): ");
    scanf("%d", &pilihan);

    if (pilihan != 1 && pilihan != 2) {
        printf("Pilihan tidak valid!\n");
        return;
    }

    for (int i = 0; i < jumlah_produk - 1; i++) {
        for (int j = 0; j < jumlah_produk - i - 1; j++) {
            int tukar = 0;
            if (pilihan == 1 && harga[j] > harga[j+1]) tukar = 1;
            else if (pilihan == 2 && terjual[j] < terjual[j+1]) tukar = 1;

            if (tukar) {
                // Tukar harga
                int tempH = harga[j]; harga[j] = harga[j+1]; harga[j+1] = tempH;
                // Tukar stok
                int tempS = stok[j]; stok[j] = stok[j+1]; stok[j+1] = tempS;
                // Tukar terjual
                int tempT = terjual[j]; terjual[j] = terjual[j+1]; terjual[j+1] = tempT;
                // Tukar nama
                char tempN[50];
                strcpy(tempN, nama[j]);
                strcpy(nama[j], nama[j+1]);
                strcpy(nama[j+1], tempN);
            }
        }
    }
    printf("Produk berhasil diurutkan! Silakan cek di menu 'Lihat Daftar Produk'.\n");
}

// 8. Fitur Laporan Penjualan
void laporanPenjualan() {
    int total_unit = 0;
    long total_pendapatan = 0;
    int max_terjual = -1;
    int idx_terlaris = -1;

    printf("\n=== LAPORAN PENJUALAN ===\n");
    for(int i = 0; i < jumlah_produk; i++) {
        if(terjual[i] > 0) {
            printf("- %s : %d unit terjual (Pendapatan: Rp %ld)\n", nama[i], terjual[i], (long)terjual[i] * harga[i]);
        }
        total_unit += terjual[i];
        total_pendapatan += (long)terjual[i] * harga[i];

        if(terjual[i] > max_terjual) {
            max_terjual = terjual[i];
            idx_terlaris = i;
        }
    }

    printf("----------------------------------\n");
    printf("Total Unit Terjual  : %d unit\n", total_unit);
    printf("Total Pendapatan    : Rp %ld\n", total_pendapatan);

    if (max_terjual > 0) {
        printf("Produk Paling Laris : %s (%d unit)\n", nama[idx_terlaris], max_terjual);
    } else {
        printf("Produk Paling Laris : Belum ada produk yang terjual.\n");
    }
}

// 9. Fitur Cek Stok Menipis
void cekStokMenipis() {
    int found = 0;
    printf("\n--- PERINGATAN STOK MENIPIS ( < 5 ) ---\n");
    for (int i = 0; i < jumlah_produk; i++) {
        if (stok[i] < 5) {
            printf("- %s (Sisa Stok: %d)\n", nama[i], stok[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Semua stok produk masih aman (di atas 4).\n");
    }
}

// Program Utama
int main() {
    int pilihan;
    do {
        printf("\n========================================\n");
        printf("  SISTEM MONITORING KANTIN KAMPUS\n");
        printf("========================================\n");
        printf("1. Lihat Daftar Produk\n");
        printf("2. Tambah Produk\n");
        printf("3. Ubah Produk\n");
        printf("4. Transaksi Penjualan\n");
        printf("5. Tambah Stok\n");
        printf("6. Cari Produk\n");
        printf("7. Urutkan Produk\n");
        printf("8. Laporan Penjualan\n");
        printf("9. Cek Stok Menipis\n");
        printf("0. Keluar\n");
        printf("----------------------------------------\n");
        printf("Pilih menu: ");

        // Cek jika input bukan angka
        if (scanf("%d", &pilihan) != 1) {
            printf("Error: Input harus berupa angka!\n");
            while (getchar() != '\n'); // bersihkan buffer
            continue;
        }

        switch (pilihan) {
            case 1: tampilProduk(); break;
            case 2: tambahProduk(); break;
            case 3: ubahProduk(); break;
            case 4: transaksiPenjualan(); break;
            case 5: tambahStok(); break;
            case 6: cariProduk(); break;
            case 7: urutkanProduk(); break;
            case 8: laporanPenjualan(); break;
            case 9: cekStokMenipis(); break;
            case 0: printf("Terima kasih telah menggunakan sistem ini!\n"); break;
            default: printf("Error: Pilihan menu tidak tersedia!\n");
        }
    } while (pilihan != 0);

    return 0;
}
