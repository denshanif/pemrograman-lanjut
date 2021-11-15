// Deklarasi prepocessor directive
#include <stdio.h>
#include <string.h>
#include <math.h>

// Deklarasi struct untuk data buku
struct dataBuku {
    int kodeBuku;
    char judulBuku[25];
    char namaPengarang[15];
} dataBuku[10], tukar;

// Deklarasi konstanta integer untuk jumlah data buku
const int jumlahData = 10;

// Deklarasi Fungsi
void tampilBuku();
void cariBuku();

// Program Utama
void main() {
    // Deklarasi variabel untuk menu dan opsi kembali
    int menu;
    char kembali;

    // Pendefinisian setiap data buku

    //Buku 1
    dataBuku[0].kodeBuku = 3031;
    strcpy(dataBuku[0].judulBuku, "C Programming");
    strcpy(dataBuku[0].namaPengarang, "James Lee");

    //Buku 2
    dataBuku[1].kodeBuku = 101;
    strcpy(dataBuku[1].judulBuku, "Wordpress Expert");
    strcpy(dataBuku[1].namaPengarang, "Andrew Octa");

    //Buku 3
    dataBuku[2].kodeBuku = 8812;
    strcpy(dataBuku[2].judulBuku, "Web From Zero to Hero");
    strcpy(dataBuku[2].namaPengarang, "David Guetta");

    //Buku 4
    dataBuku[3].kodeBuku = 790;
    strcpy(dataBuku[3].judulBuku, "Laravel");
    strcpy(dataBuku[3].namaPengarang, "Hans Jackson");

    //Buku 5
    dataBuku[4].kodeBuku = 66;
    strcpy(dataBuku[4].judulBuku, "Master Flutter");
    strcpy(dataBuku[4].namaPengarang, "Ozur Haskels");

    //Buku 6
    dataBuku[5].kodeBuku = 111;
    strcpy(dataBuku[5].judulBuku, "CodeIgniter 4 the guide");
    strcpy(dataBuku[5].namaPengarang, "Ganz Patrick");

    //Buku 7
    dataBuku[6].kodeBuku = 678;
    strcpy(dataBuku[6].judulBuku, "Raspberry Pi 4");
    strcpy(dataBuku[6].namaPengarang, "Tony Watts");

    //Buku 8
    dataBuku[7].kodeBuku = 901;
    strcpy(dataBuku[7].judulBuku, "Building Robotic AI");
    strcpy(dataBuku[7].namaPengarang, "Leny Imelda");

    //Buku 9
    dataBuku[8].kodeBuku = 303;
    strcpy(dataBuku[8].judulBuku, "Data Science with Python");
    strcpy(dataBuku[8].namaPengarang, "Ranya Sundar");

    //Buku 10
    dataBuku[9].kodeBuku = 4089;
    strcpy(dataBuku[9].judulBuku, "Go Lang Introduction");
    strcpy(dataBuku[9].namaPengarang, "Brian Macakzie");

    // Menu Utama
    do {
        system("cls"); // System clear untuk membersihkan terminal
		// Output judul program
		printf("===================================================\n");
		printf("======= PROGRAM MANAJEMEN BUKU PERPUSTAKAAN =======\n");
		printf("=========== HANIF AL FATHONI 20081010001 ==========\n");
		printf("===================================================\n");
		// Menu pilihan
		printf("\n=== SILAHKAN PILIH MENU YANG DI BAWAH INI ===\n");
		printf("1. MENAMPILKAN DATA SEMUA BUKU\n");
		printf("2. PENCARIAN BUKU\n");

        // Input pilihan menu dari user
		printf("Masukkan pilihan anda: ");
		scanf("%d", &menu);

		printf("\n");

		// Switch case untuk masing-masing menu
		switch(menu) {
			case 1 :
				tampilBuku();
				printf("\n");
				break;
			case 2 :
				cariBuku();
				printf("\n");
				break;
			default :
				printf("Maaf, input yang anda masukkan salah/invalid");
				printf("\n");
				break;
		}
		printf("\n");

        // Pilihan kembali ke menu utama
		printf("Ingin kembali ke menu utama? (Y/T): ");
		scanf("%c", &kembali); scanf("%c", &kembali);
    }
    while(kembali == 'y' || kembali == 'Y');
}

// Fungsi pengurutan kode buku (selection sort ascending)
void urutKode() {
    int i, j, minimum;

	// Looping selection sort
	for (i = 0; i < (jumlahData-1); i++) {
		minimum = i;

		// Looping pengurutan nilai
		for (j = i+1; j < jumlahData; j++) {
			if (dataBuku[j].kodeBuku < dataBuku[minimum].kodeBuku)
				minimum = j;
		}
		if (minimum != i) {
            tukar = dataBuku[minimum];
            dataBuku[minimum] = dataBuku[i];
            dataBuku[i] = tukar;
		}
	}
}

// Fungsi pengurutan judul buku (selection sort ascending)
void urutJudul() {
        int i, j, minimum;

	// Looping selection sort
	for (i = 0; i < (jumlahData-1); i++) {
		minimum = i;

		// Looping pengurutan nilai
		for (j = i+1; j < jumlahData; j++) {
			if (strcmp(dataBuku[j].judulBuku, dataBuku[minimum].judulBuku) < 0)
				minimum = j;
		}
		if (minimum != i) {
            tukar = dataBuku[minimum];
            dataBuku[minimum] = dataBuku[i];
            dataBuku[i] = tukar;
		}
	}
}

// Fungsi menampilkan kode buku yang sudah terurut (ascending)
void tampilKode() {
    urutKode();

    int i;

    printf("KODE BUKU\tJUDUL BUKU\t\t\tNAMA PENGARANG\n\n");

    for(i = 0; i < jumlahData; i++) {
        printf("%-4d\t\t%-24s\t%-14s\n", dataBuku[i].kodeBuku, dataBuku[i].judulBuku, dataBuku[i].namaPengarang);
    }
}

// Fungsi menampilkan judul buku yang sudah terurut (ascending)
void tampilJudul() {
    urutJudul();

    int i;

    printf("KODE BUKU\tJUDUL BUKU\t\t\tNAMA PENGARANG\n\n");

    for(i = 0; i < jumlahData; i++) {
        printf("%-4d\t\t%-24s\t%-14s\n", dataBuku[i].kodeBuku, dataBuku[i].judulBuku, dataBuku[i].namaPengarang);
    }
}

//Fungsi menampilkan seluruh data buku
void tampilBuku() {
    int menu;

    // Menu
    up:
    system("cls");
    printf("=========================== Menampilkan Data Buku ===============================\n\n");
	printf("\n======================= SILAHKAN PILIH OPSI DI BAWAH INI ======================\n");

	printf("1. TAMPILKAN DATA BUKU URUT SESUAI KODE BUKU\n");
	printf("2. TAMPILKAN DATA BUKU URUT SESUAI JUDUL BUKU\n");
	printf("3. KEMBALI KE MENU UTAMA\n");

    printf("Masukkan pilihan anda: ");
	scanf("%d", &menu);

	printf("\n");

	// Switch case pemilihan menu
	switch(menu) {
		case 1 :
			tampilKode();
			printf("\n");
            printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
            getch();
            goto up;
		case 2 :
			tampilJudul();
			printf("\n");
            printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
            getch();
            goto up;
        case 3 :
            break;
		default :
			printf("Maaf, input yang anda masukkan salah/invalid");
			printf("\n");
			printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
            getch();
            goto up;
	}
}

// Fungsi pencarian data buku berdasarkan kode buku (jump search)
void cariKode() {
    ulangi:

    system("cls");

    // Kode buku diurutkan terlebih dahulu
    urutKode();

    int x;
    printf("=================== Pencarian Data Buku Berdasarkan Kode Buku ===================\n\n");

    // Input kode buku yang ingin dicari
	printf("Masukkan Kode Buku Yang Ingin Dicari: ");
	scanf("%d", &x);

	// Jump Search

	int n = jumlahData, jump = sqrt(n), prev = 0, i = 0;

    while (dataBuku[jump].kodeBuku <= x && jump < n) {
        prev = jump;
        jump += sqrt(n);
        if (prev >= n + 1) {
            printf("Data tidak ditemukan\n");
            printf("Tekan enter untuk mengulangi input kode buku.\n");
            getch();
            goto ulangi;
        }
        i++;
    }

    int ketemu = 0;
    int j;
    for (j = prev; j <= jump; j++) {
        if (dataBuku[j].kodeBuku == x) {
            ketemu = 1;
            printf("Kode Buku %d ditemukan pada index ke-%d\n", x, j);
            printf("\nIdentitas Buku:\n");
            printf("Kode Buku: %d\n", dataBuku[j].kodeBuku);
            printf("Judul Buku: %s\n", dataBuku[j].judulBuku);
            printf("Nama Pengarang: %s\n", dataBuku[j].namaPengarang);
            break;
        }
    }

    if (i == 0 && ketemu == 0) {
        printf("Data tidak ditemukan\n");
        printf("Tekan enter untuk mengulangi input kode buku.\n");
        getch();
        goto ulangi;
    }
}

// Fungsi pencarian data buku berdasarkan judul buku (interpolation search)
void cariJudul() {
    ulangi:

    system("cls");

    // Judul buku diurutkan terlebih dahulu
    urutJudul();

    char cari[25];
    printf("=================== Pencarian Data Buku Berdasarkan Judul Buku ==================\n\n");

    // Input kode buku yang ingin dicari
	printf("Masukkan Judul Buku Yang Ingin Dicari: ");
	gets(cari);
	scanf("%[^\n]", &cari);

	// Interpolation Search

	int low = 0, high = jumlahData - 1, match, ketemu = 0;
    float mid;
    int posisi;

    while ((strcmp(cari, dataBuku[low].judulBuku) >= 0) && (strcmp(cari, dataBuku[high].judulBuku) <= 0)) {
        mid = (float) strcmp(cari, dataBuku[low].judulBuku) / strcmp(dataBuku[high].judulBuku, dataBuku[low].judulBuku) * (high - low) + low;
        posisi = floor(mid);
        if (strcmp(dataBuku[posisi].judulBuku, cari) == 0){
            match = posisi;
            ketemu = 1;
            break;
        }
        if (strcmp(dataBuku[posisi].judulBuku, cari) > 0)
            high = posisi - 1;
        else if (strcmp(dataBuku[posisi].judulBuku, cari) < 0)
            low = posisi + 1;
    }

    if (ketemu == 0){
        printf ("Data Tidak Ditemukan\n");
        printf("Tekan enter untuk mengulangi input judul buku.\n");
        getch();
        goto ulangi;
    }
    else {
            printf("Judul Buku %s ditemukan pada index ke-%d\n", cari, match);
            printf("\nIdentitas Buku:\n");
            printf("Kode Buku: %d\n", dataBuku[match].kodeBuku);
            printf("Judul Buku: %s\n", dataBuku[match].judulBuku);
            printf("Nama Pengarang: %s\n", dataBuku[match].namaPengarang);
    }
}

// Fungsi pencarian data buku
void cariBuku() {
    int menu;

    up:
    system("cls");
    printf("============================ Pencarian Data Buku ================================\n\n");
	printf("\n================== SILAHKAN PILIH OPSI PENCARIAN DI BAWAH INI =================\n");

	printf("1. CARI BERDASARKAN KODE BUKU\n");
	printf("2. CARI BERDASARKAN JUDUL BUKU\n");
    printf("3. KEMBALI KE MENU UTAMA\n");

    printf("Masukkan pilihan anda: ");
	scanf("%d", &menu);

	printf("\n");

	// Switch case pemilihan menu
	switch(menu) {
		case 1 :
			cariKode();
			printf("\n");
			printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
            getch();
            goto up;
		case 2 :
			cariJudul();
			printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
            getch();
            goto up;
        case 3 :
            break;
		default :
			printf("Maaf, input yang anda masukkan salah/invalid");
			printf("\n");
			break;
	}
}
