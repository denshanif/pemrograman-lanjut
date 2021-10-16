// Deklarasi prepocessor directive
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Deklarasi Struct
typedef struct akademik {
	int semester;
	float ipk;
} akademik;

// Deklarasi Struct
struct datamhs {
	char npm[20];
	char nama[20];
	char fakultas[20];
	char prodi[20];
	akademik akademik;
} mhs[80], tukar;

// Deklarasi integer indexBaru untuk menampung index jumlah data
int indexBaru = 0;

// Deklarasi fungsi
void tambahData();
void tampilData();
void hapusData();
void cariData();
void editData();
void urutData();
int cariIndex(char npm[20]);

int main() {
	int menu; // Integer menu untuk menampung hasil pilihan dari menu
	char kembali; // Char kembali untuk menampung input kembali ke menu

	// Do While untuk pengulangan menu pilihan
	do {
		system("clear"); // System clear untuk membersihkan terminal
		// Output judul program
		printf("==============================================\n");
		printf("====== PROGRAM MANAJEMEN DATA MAHASISWA ======\n");
		printf("======== HANIF AL FATHONI 20081010001 ========\n");
		printf("==============================================\n");
		// Menu pilihan
		printf("\n=== SILAHKAN PILIH MENU YANG DI BAWAH INI ===\n");
		printf("1. TAMBAH DATA MAHASISWA\n");
		printf("2. TAMPILKAN DATA MAHASISWA\n");
		printf("3. HAPUS DATA MAHASISWA\n");
		printf("4. CARI DATA MAHASISWA\n");
		printf("5. EDIT DATA MAHASISWA\n");
		printf("6. URUT DATA MAHASISWA\n");

		// Input pilihan menu dari user
		printf("Masukkan pilihan anda: ");
		scanf("%d", &menu);

		printf("\n");

		// Switch case untuk masing-masing menu
		switch(menu) {
			case 1 :
				tambahData();
				printf("\n");
				break;
			case 2 :
				tampilData();
				printf("\n");
				break;
			case 3 :
				hapusData();
				printf("\n");
				break;
			case 4 :
				cariData();
				printf("\n");
				break;
			case 5 :
				editData();
				printf("\n");
				break;
			case 6 :
				urutData();
				printf("\n");
				break;
			default :
				printf("Maaf, input yang anda masukkan salah/invalid");
				printf("\n");
				break;
		}
		printf("\n");

		// Pilihan kembali ke menu awal
		printf("Ingin kembali ke menu pilihan? (Y/T): ");
		scanf("%c", &kembali); scanf("%c", &kembali);
	}
	while(kembali == 'y' || kembali == 'Y');
}

// Deklarasi fungsi untuk pengecekan ketersediaan npm
bool cekNPM(char npm[20], int index) {
	int i;
	for (i = 0; i < indexBaru; i++) {
		// Pengecekan NPM
		if (index != i && strcmp(npm, mhs[i].npm) == 0) {
			return false;
		}
	}
	return true;
}

// Pemanggilan fungsi untuk penginputan data mahasiswa
void inputData(int index) {
	printf("\n\n============== Input Data Mahasiswa ==============\n");\

	// Input NPM
	printf("Masukkan NPM mahasiswa: ");
	fflush(stdin);
	scanf("%s", &mhs[index].npm);

	// Pengecekan NPM dengan pemanggilan fungsi cekNPM
	if (!cekNPM(mhs[index].npm, index)) {
		printf("NPM %s telah ada, silahkan masukkan npm lain: ", mhs[index].npm);
		inputData(index);
	}
	else {
		printf("Masukkan nama mahasiswa: ");
		fflush(stdin);
		scanf("%[^\n]", mhs[index].nama);

		printf("Masukkan program studi mahasiswa: ");
		fflush(stdin);
		scanf("%[^\n]", mhs[index].prodi);

		printf("Masukkan fakultas mahasiswa: ");
		fflush(stdin);
		scanf("%[^\n]", mhs[index].fakultas);

		printf("Masukkan semester mahasiswa: ");
		fflush(stdin);
		scanf("%d", &mhs[index].akademik.semester);

		printf("Masukkan ipk mahasiswa: ");
		fflush(stdin);
		scanf("%f", &mhs[index].akademik.ipk);

		printf("\n");
	}
}

// Pemanggilan fungsi untuk penambahan data mahasiswa
void tambahData() {
	// Setiap pemanggilan fungsi input data index akan ditambahkan
	inputData(indexBaru);
	indexBaru++;
}


// Pemanggilan fungsi untuk mengetahui keberadaan data pada array
int cariIndex(char npm[20]) {
	int i;
	int index = -1;

	for (i = 0; i < indexBaru && index < 0; i++) {
		if (strcmp(mhs[i].npm, npm) == 0) {
			index = i;
		}
	}
	return index;
}

// Pemanggilan fungsi untuk menampilkan seluruh data mahasiswa
void tampilData() {
	int i;

	printf("======================= Daftar Data Mahasiswa =======================\n\n");

	// Data ditampilkan menggunakan looping berdasarkan banyaknya index/data yang tersimpan di array
	for(i = 0; i < indexBaru; i++) {
		printf("\n=== DATA MAHASISWA KE-%d ===\n", i+1);
		printf("NPM Mahasiswa : %s \n", mhs[i].npm);
		printf("Nama Mahasiswa : %s \n", mhs[i].nama);
		printf("Program Studi Mahasiswa : %s \n", mhs[i].prodi);
		printf("Fakultas Mahasiswa : %s \n", mhs[i].fakultas);
		printf("Semester Mahasiswa : %d \n", mhs[i].akademik.semester);
		printf("IPK Mahasiswa : %f \n", mhs[i].akademik.ipk);
	}
}

// Deklarasi fungsi untuk mekanisme hapus data pada sebuah index
void hapus(int index) {
	int i, tempat = 0;

	for (i = 0; i < indexBaru; i++) {
		if (i != index) {
			mhs[tempat] = mhs[i];
			tempat++;
		}
	}
	indexBaru--;

	printf("\n=== Data mahasiswa setelah dihapus ===\n");
	for(i = 0; i < indexBaru; i++) {
		printf("\n=== DATA MAHASISWA KE-%d ===\n", i+1);
		printf("NPM Mahasiswa : %s \n", mhs[i].npm);
		printf("Nama Mahasiswa : %s \n", mhs[i].nama);
		printf("Program Studi Mahasiswa : %s \n", mhs[i].prodi);
		printf("Fakultas Mahasiswa : %s \n", mhs[i].fakultas);
		printf("Semester Mahasiswa : %d \n", mhs[i].akademik.semester);
		printf("IPK Mahasiswa : %f \n", mhs[i].akademik.ipk);
	}
}

// Pemanggilan fungsi untuk menghapus data berdasarkan NPM mahasiswa
void hapusData() {
	char npm[20];

	printf("Masukkan NPM mahasiswa yang datanya ingin dihapus: ");
	scanf("%s", &npm);

	// Pencocokan NPM inputan dengan NPM yang sudah ada sebelum dilakukan penghapusan
	int index = cariIndex(npm);
	if (index < 0) {
		printf("Data tidak ditemukan\n");
		hapusData();
	}
	else {
		hapus(index);
	}
}

// Pemanggilan fungsi untuk mencari data mahasiswa berdasarkan NPM atau nama mahasiswa
void cariData() {
	char cari[20];

	printf("Masukkan nama atau NPM mahasiswa yang datanya ingin dicari: ");
	scanf("%s", &cari);

	int i;

	// Dilakukan pengecekan nama/NPM pada setiap index/data
	for(i = 0; i < indexBaru; i++) {
		if (strcmp(mhs[i].npm, cari) == 0 || strcmp(mhs[i].nama, cari) == 0) {
			printf("NPM Mahasiswa : %s \n", mhs[i].npm);
			printf("Nama Mahasiswa : %s \n", mhs[i].nama);
			printf("Program Studi Mahasiswa : %s \n", mhs[i].prodi);
			printf("Fakultas Mahasiswa : %s \n", mhs[i].fakultas);
			printf("Semester Mahasiswa : %d \n", mhs[i].akademik.semester);
			printf("IPK Mahasiswa : %f \n", mhs[i].akademik.ipk);

			return ;
		}
	}
	printf("Data tidak ditemukan\n");
}


// Pemanggilan fungsi untuk mengubah data yang sudah ada
void editData() {
	char npm[20];

	printf("Masukkan NPM mahasiswa yang datanya ingin diedit: ");
	scanf("%s", &npm);

	// Dilakukan pengecekan apakah NPM telah ada pada data
	int index = cariIndex(npm);
	if (index < 0) {
		printf("Data tidak ditemukan\n");
	}
	else {
		inputData(index);
	}
}

// Deklarasi fungsi untuk menampilkan data hasil pengurutan
void tampilDataUrut() {
	int i;

	printf("NPM\tNAMA\n\n");

	for(i = 0; i < indexBaru; i++) {
		printf("%s\t%s\n", mhs[i].npm, mhs[i].nama);
	}
}

// Deklarasi fungsi untuk bubble sort npm ascending
void npmAscen() {
	int i, j;

	// Looping bubble sort
	for (i = indexBaru - 1; i > 0; i--) {
		for (j = indexBaru - 1; j >= indexBaru - i; j--) {
			// Dikarenakan variabel bertipe char maka menggunakan strcmp untuk perbandingan
			if (strcmp(mhs[j].npm, mhs[j-1].npm) < 0) {
				tukar = mhs[j];
				mhs[j] = mhs[j-1];
				mhs[j-1] = tukar;
			}
		}
	}
}

// Deklarasi fungsi untuk bubble sort npm descending
void npmDescen() {
	int i, j;

	// Looping bubble sort
	for (i = indexBaru - 1; i > 0; i--) {
		for (j = indexBaru - 1; j >= indexBaru - i; j--) {
			// Dikarenakan variabel bertipe char maka menggunakan strcmp untuk perbandingan
			if (strcmp(mhs[j].npm, mhs[j-1].npm) > 0) {
				tukar = mhs[j];
				mhs[j] = mhs[j-1];
				mhs[j-1] = tukar;
			}
		}
	}
}

// Deklarasi fungsi untuk bubble sort npm descending
void namaAscen() {
	int i, j;

	// Looping bubble sort
	for (i = indexBaru - 1; i > 0; i--) {
		for (j = indexBaru - 1; j >= indexBaru - i; j--) {
			// Dikarenakan variabel bertipe char maka menggunakan strcmp untuk perbandingan
			if (strcmp(mhs[j].nama, mhs[j-1].nama) < 0) {
				tukar = mhs[j];
				mhs[j] = mhs[j-1];
				mhs[j-1] = tukar;
			}
		}
	}
}

// Deklarasi fungsi untuk bubble sort npm descending
void namaDescen() {
	int i, j;

	// Looping bubble sort
	for (i = indexBaru - 1; i > 0; i--) {
		for (j = indexBaru - 1; j >= indexBaru - i; j--) {
			// Dikarenakan variabel bertipe char maka menggunakan strcmp untuk perbandingan
			if (strcmp(mhs[j].nama, mhs[j-1].nama) > 0) {
				tukar = mhs[j];
				mhs[j] = mhs[j-1];
				mhs[j-1] = tukar;
			}
		}
	}
}


// Pemanggilan fungsi untuk menu pengurutan data
void urutData() {
	int menuUrut;

	// Menu pilihan opsi pengurutan
	printf("==================== Pengurutan Data Mahasiswa ====================\n\n");
	printf("\n=== SILAHKAN PILIH OPSI PENGURUTAN DI BAWAH INI ===\n");

	printf("1. URUT NPM ASCENDING\n");
	printf("2. URUT NPM DESCENDING\n");
	printf("3. URUT NAMA ASCENDING\n");
	printf("4. URUT NAMA DESCENDING\n");

	printf("Masukkan pilihan anda: ");
	scanf("%d", &menuUrut);

	printf("\n");

	// Switch case pemilihan menu
	switch(menuUrut) {
		case 1 :
			npmAscen();
			tampilDataUrut();
			printf("\n");
			break;
		case 2 :
			npmDescen();
			tampilDataUrut();
			printf("\n");
			break;
		case 3 :
			namaAscen();
			tampilDataUrut();
			printf("\n");
			break;
		case 4 :
			namaDescen();
			tampilDataUrut();
			printf("\n");
			break;
		default :
			printf("Maaf, input yang anda masukkan salah/invalid");
			printf("\n");
			break;
	}
}
