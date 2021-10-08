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
} mhs[80];

// Deklarasi integer indexBaru untuk menampung index jumlah data
int indexBaru = 0;

// Deklarasi fungsi
void tambahData();
void tampilData();
void hapusData();
void cariData();
void editData();
void urutBubble();
void urutSelection();
void urutInsertion();
int cariIndex(char npm[20]);

int main() {
	int menu; // Integer menu untuk menampung hasil pilihan dari menu
	char kembali; // Char kembali untuk menampung input kembali ke menu

	// Do While untuk pengulangan menu pilihan
	do {
		system("cls"); // System clear untuk membersihkan terminal
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
		printf("6. URUT DATA MAHASISWA (BUBBLE SORT)\n");
		printf("7. URUT DATA MAHASISWA (SELECTION SORT)\n");
		printf("8. URUT DATA MAHASISWA (INSERTION SORT)\n\n");

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
				urutBubble();
				printf("\n");
				break;
            case 7 :
				urutSelection();
				printf("\n");
				break;
            case 8 :
				urutInsertion();
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
void npmBubbleAscen() {
	int i, j;
	char tukar[20];

	// Looping bubble sort
	for (i = indexBaru - 1; i > 0; i--) {
		for (j = indexBaru - 1; j >= indexBaru - i; j--) {
			// Dikarenakan variabel bertipe char maka menggunakan strcmp untuk perbandingan
			if (strcmp(mhs[j].npm, mhs[j-1].npm) < 0) {
				strcpy(tukar, mhs[j].npm); // Untuk penukaran nilai menggunakan strcpy
				strcpy(mhs[j].npm, mhs[j-1].npm);
				strcpy(mhs[j-1].npm, tukar);
			}
		}
	}
}

// Deklarasi fungsi untuk bubble sort npm descending
void npmBubbleDescen() {
	int i, j;
	char tukar[20];

	// Looping bubble sort
	for (i = indexBaru - 1; i > 0; i--) {
		for (j = indexBaru - 1; j >= indexBaru - i; j--) {
			// Dikarenakan variabel bertipe char maka menggunakan strcmp untuk perbandingan
			if (strcmp(mhs[j].npm, mhs[j-1].npm) > 0) {
				strcpy(tukar, mhs[j].npm); // Untuk penukaran nilai menggunakan strcpy
				strcpy(mhs[j].npm, mhs[j-1].npm);
				strcpy(mhs[j-1].npm, tukar);
			}
		}
	}
}

// Deklarasi fungsi untuk bubble sort npm descending
void namaBubbleAscen() {
	int i, j;
	char tukar[20];

	// Looping bubble sort
	for (i = indexBaru - 1; i > 0; i--) {
		for (j = indexBaru - 1; j >= indexBaru - i; j--) {
			// Dikarenakan variabel bertipe char maka menggunakan strcmp untuk perbandingan
			if (strcmp(mhs[j].nama, mhs[j-1].nama) < 0) {
				strcpy(tukar, mhs[j].nama); // Untuk penukaran nilai menggunakan strcpy
				strcpy(mhs[j].nama, mhs[j-1].nama);
				strcpy(mhs[j-1].nama, tukar);
			}
		}
	}
}

// Deklarasi fungsi untuk bubble sort npm descending
void namaBubbleDescen() {
	int i, j;
	char tukar[20];

	// Looping bubble sort
	for (i = indexBaru - 1; i > 0; i--) {
		for (j = indexBaru - 1; j >= indexBaru - i; j--) {
			// Dikarenakan variabel bertipe char maka menggunakan strcmp untuk perbandingan
			if (strcmp(mhs[j].nama, mhs[j-1].nama) > 0) {
				strcpy(tukar, mhs[j].nama); // Untuk penukaran nilai menggunakan strcpy
				strcpy(mhs[j].nama, mhs[j-1].nama);
				strcpy(mhs[j-1].nama, tukar);
			}
		}
	}
}


// Pemanggilan fungsi untuk menu pengurutan data dengan metode bubble sort
void urutBubble() {
	int menuUrut;

	// Menu pilihan opsi pengurutan
	printf("==================== Pengurutan Data Mahasiswa Bubble Sort ====================\n\n");
	printf("\n================ SILAHKAN PILIH OPSI PENGURUTAN DI BAWAH INI ================\n");

	printf("1. URUT NPM ASCENDING\n");
	printf("2. URUT NPM DESCENDING\n");
	printf("3. URUT NAMA ASCENDING\n");
	printf("4. URUT NAMA DESCENDING\n\n");

	printf("Masukkan pilihan anda: ");
	scanf("%d", &menuUrut);

	printf("\n");

	// Switch case pemilihan menu
	switch(menuUrut) {
		case 1 :
			npmBubbleAscen();
			tampilDataUrut();
			printf("\n");
			break;
		case 2 :
			npmBubbleDescen();
			tampilDataUrut();
			printf("\n");
			break;
		case 3 :
			namaBubbleAscen();
			tampilDataUrut();
			printf("\n");
			break;
		case 4 :
			namaBubbleDescen();
			tampilDataUrut();
			printf("\n");
			break;
		default :
			printf("Maaf, input yang anda masukkan salah/invalid");
			printf("\n");
			break;
	}
}

// Deklarasi fungsi untuk selection sort npm ascending
void npmSelectionAscen() {
	int i, j, minimum;
	char tukar[20];

	// Looping selection sort
	for (i = 0; i < (indexBaru-1); i++) {
		minimum = i;

		// Looping pengurutan nilai
		for (j = i+1; j < indexBaru; j++) {
			if (strcmp(mhs[j].npm, mhs[minimum].npm) < 0)
				minimum = j;
		}
		if (minimum != i) {
			strcpy(tukar, mhs[minimum].npm); // Untuk penukaran nilai menggunakan strcpy
            strcpy(mhs[minimum].npm, mhs[i].npm);
            strcpy(mhs[i].npm, tukar);
		}
	}
}

// Deklarasi fungsi untuk selection sort npm descending
void npmSelectionDescen() {
	int i, j, minimum;
	char tukar[20];

	// Looping selection sort
	for (i = 0; i < (indexBaru-1); i++) {
		minimum = i;

		// Looping pengurutan nilai
		for (j = i+1; j < indexBaru; j++) {
			if (strcmp(mhs[j].npm, mhs[minimum].npm) > 0)
				minimum = j;
		}
		if (minimum != i) {
			strcpy(tukar, mhs[minimum].npm); // Untuk penukaran nilai menggunakan strcpy
            strcpy(mhs[minimum].npm, mhs[i].npm);
            strcpy(mhs[i].npm, tukar);
		}
	}
}

// Deklarasi fungsi untuk selection sort nama ascending
void namaSelectionAscen() {
	int i, j, minimum;
	char tukar[20];

	// Looping selection sort
	for (i = 0; i < (indexBaru-1); i++) {
		minimum = i;

		// Looping pengurutan nilai
		for (j = i+1; j < indexBaru; j++) {
			if (strcmp(mhs[j].nama, mhs[minimum].nama) < 0)
				minimum = j;
		}
		if (minimum != i) {
			strcpy(tukar, mhs[minimum].nama); // Untuk penukaran nilai menggunakan strcpy
            strcpy(mhs[minimum].nama, mhs[i].nama);
            strcpy(mhs[i].nama, tukar);
		}
	}
}

// Deklarasi fungsi untuk selection sort nama descending
void namaSelectionDescen() {
	int i, j, minimum;
	char tukar[20];

	// Looping selection sort
	for (i = 0; i < (indexBaru-1); i++) {
		minimum = i;

		// Looping pengurutan nilai
		for (j = i+1; j < indexBaru; j++) {
			if (strcmp(mhs[j].nama, mhs[minimum].nama) > 0)
				minimum = j;
		}
		if (minimum != i) {
			strcpy(tukar, mhs[minimum].nama); // Untuk penukaran nilai menggunakan strcpy
            strcpy(mhs[minimum].nama, mhs[i].nama);
            strcpy(mhs[i].nama, tukar);
		}
	}
}


// Pemanggilan fungsi untuk menu pengurutan data dengan metode selection sort
void urutSelection() {
	int menuUrut;

	// Menu pilihan opsi pengurutan
	printf("==================== Pengurutan Data Mahasiswa Selection Sort ====================\n\n");
	printf("\n================== SILAHKAN PILIH OPSI PENGURUTAN DI BAWAH INI =================\n");

	printf("1. URUT NPM ASCENDING\n");
	printf("2. URUT NPM DESCENDING\n");
	printf("3. URUT NAMA ASCENDING\n");
	printf("4. URUT NAMA DESCENDING\n\n");

	printf("Masukkan pilihan anda: ");
	scanf("%d", &menuUrut);

	printf("\n");

	// Switch case pemilihan menu
	switch(menuUrut) {
		case 1 :
			npmSelectionAscen();
			tampilDataUrut();
			printf("\n");
			break;
		case 2 :
			npmSelectionDescen();
			tampilDataUrut();
			printf("\n");
			break;
		case 3 :
			namaSelectionAscen();
			tampilDataUrut();
			printf("\n");
			break;
		case 4 :
			namaSelectionDescen();
			tampilDataUrut();
			printf("\n");
			break;
		default :
			printf("Maaf, input yang anda masukkan salah/invalid");
			printf("\n");
			break;
	}
}

// Deklarasi fungsi untuk insertion sort npm ascending
void npmInsertionAscen() {
	int i, j;
	char kunci[20];

	// Looping insertion sort
	for (i = 1; i < indexBaru; i++) {
		strcpy(kunci, mhs[i].npm);
		j = i - 1;

		// Looping pengurutan nilai
		while (j >= 0 && strcmp(mhs[j].npm, kunci) > 0) {
			strcpy(mhs[j + 1].npm, mhs[j].npm);
			j = j - 1;
		}
		strcpy(mhs[j + 1].npm, kunci);
	}
}

// Deklarasi fungsi untuk insertion sort npm descending
void npmInsertionDescen() {
	int i, j;
	char kunci[20];

	// Looping insertion sort
	for (i = 1; i < indexBaru; i++) {
		strcpy(kunci, mhs[i].npm);
		j = i - 1;

		// Looping pengurutan nilai
		while (j >= 0 && strcmp(mhs[j].npm, kunci) < 0) {
			strcpy(mhs[j + 1].npm, mhs[j].npm);
			j = j - 1;
		}
		strcpy(mhs[j + 1].npm, kunci);
	}
}

// Deklarasi fungsi untuk insertion sort nama ascending
void namaInsertionAscen() {
	int i, j;
	char kunci[20];

	// Looping insertion sort
	for (i = 1; i < indexBaru; i++) {
		strcpy(kunci, mhs[i].nama);
		j = i - 1;

		// Looping pengurutan nilai
		while (j >= 0 && strcmp(mhs[j].nama, kunci) > 0) {
			strcpy(mhs[j + 1].nama, mhs[j].nama);
			j = j - 1;
		}
		strcpy(mhs[j + 1].nama, kunci);
	}
}

// Deklarasi fungsi untuk insertion sort nama descending
void namaInsertionDescen() {
	int i, j;
	char kunci[20];

	// Looping insertion sort
	for (i = 1; i < indexBaru; i++) {
		strcpy(kunci, mhs[i].nama);
		j = i - 1;

		// Looping pengurutan nilai
		while (j >= 0 && strcmp(mhs[j].nama, kunci) < 0) {
			strcpy(mhs[j + 1].nama, mhs[j].nama);
			j = j - 1;
		}
		strcpy(mhs[j + 1].nama, kunci);
	}
}

// Pemanggilan fungsi untuk menu pengurutan data dengan metode insertion sort
void urutInsertion() {
	int menuUrut;

	// Menu pilihan opsi pengurutan
	printf("==================== Pengurutan Data Mahasiswa Insertion Sort ====================\n\n");
	printf("\n================== SILAHKAN PILIH OPSI PENGURUTAN DI BAWAH INI =================\n");

	printf("1. URUT NPM ASCENDING\n");
	printf("2. URUT NPM DESCENDING\n");
	printf("3. URUT NAMA ASCENDING\n");
	printf("4. URUT NAMA DESCENDING\n\n");

	printf("Masukkan pilihan anda: ");
	scanf("%d", &menuUrut);

	printf("\n");

	// Switch case pemilihan menu
	switch(menuUrut) {
		case 1 :
			npmInsertionAscen();
			tampilDataUrut();
			printf("\n");
			break;
		case 2 :
			npmInsertionDescen();
			tampilDataUrut();
			printf("\n");
			break;
		case 3 :
			namaInsertionAscen();
			tampilDataUrut();
			printf("\n");
			break;
		case 4 :
			namaInsertionDescen();
			tampilDataUrut();
			printf("\n");
			break;
		default :
			printf("Maaf, input yang anda masukkan salah/invalid");
			printf("\n");
			break;
	}
}
