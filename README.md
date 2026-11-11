# Proyek-Array-C-C2583207054
Proyek ini adalah aplikasi console sederhana berbasis bahasa pemrograman C yang dibuat untuk memfasilitasi pengelola kantin kampus. Aplikasi ini memungkinkan pengguna untuk memantau ketersediaan stok, menghitung transaksi penjualan dengan tepat, dan melihat laporan produk yang paling banyak terjual.
dentitas Mahasiswa

dentitas Mahasiswa

Nama Lengkap: Dimas Ahmad Fauzi

NIM: C2583207054

Kelas: PTI3A

Mata Kuliah: Algoritma dan Pemrograman Lanjutan

Program Studi: Pendidikan Teknologi Informasi

Universitas: Universitas Muhammadiyah Tasikmalaya

Deskripsi Singkat Proyek

Proyek ini adalah aplikasi console sederhana berbasis bahasa pemrograman C yang dibuat untuk memfasilitasi pengelola kantin kampus. Aplikasi ini memungkinkan pengguna untuk memantau ketersediaan stok, menghitung transaksi penjualan dengan tepat, dan melihat laporan produk yang paling banyak terjual. Seluruh data disimpan sementara di dalam memori menggunakan struktur data array selama program berjalan (tanpa database eksternal).

Daftar Fitur

Lihat Daftar Produk: Menampilkan seluruh nama, harga, dan stok produk saat ini.

Tambah Produk: Menambahkan produk baru dengan validasi kapasitas maksimal (50 produk).

Ubah Produk: Memperbarui harga dan stok produk yang sudah ada.

Transaksi Penjualan: Memproses pembelian lebih dari satu jenis produk dalam satu keranjang belanja.

Tambah Stok: Menambahkan jumlah stok pada produk tertentu.

Cari Produk: Mencari produk berdasarkan nama (tidak case-sensitive).

Urutkan Produk: Mengurutkan produk menggunakan metode Bubble Sort berdasarkan Harga (Termurah - Termahal) atau Jumlah Terjual (Terbanyak - Sedikit).

Laporan Penjualan: Menampilkan rekapitulasi unit terjual per produk, total keseluruhan unit terjual, total pendapatan kotor, dan produk paling laris.

Cek Stok Menipis: Memberikan peringatan untuk produk yang stoknya tersisa kurang dari 5 unit.

Penjelasan Penggunaan Array

Program ini secara penuh memanfaatkan struktur data array global (maksimal 50 indeks) untuk menyimpan data yang berelasi pada indeks yang sama (Parallel Arrays):

Array Karakter 2 Dimensi: char nama[50][50] digunakan untuk menyimpan kumpulan string (nama-nama produk).

Array 1 Dimensi (Integer):

int harga[50] untuk menyimpan harga masing-masing produk.

int stok[50] untuk memantau sisa stok produk.

int terjual[50] untuk mencatat akumulasi jumlah produk yang telah terjual.

Petunjuk Kompilasi dan Menjalankan Program

Menggunakan Terminal / Command Prompt (Kompilator GCC):

Buka terminal dan arahkan ke direktori tempat file main.c berada.

Jalankan perintah kompilasi berikut:

gcc main.c -o aplikasi_kantin


Jalankan program hasil kompilasi:

Windows: aplikasi_kantin.exe

Linux / Mac: ./aplikasi_kantin
