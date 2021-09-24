#include <stdio.h>

struct datamhs {
	int npm;
	char nama[20];
	char prodi[20];
	float ipk;
};

void inputData(struct datamhs[], int);
void tampilData(struct datamhs[], int);
void hapusData(struct datamhs[], int, int);
void cariData(struct datamhs[], int, int);

int main() {
	struct datamhs mhs[20];
	int n, menu, npm;
	char kembali;
	
	printf("==============================================\n");
	printf("====== PROGRAM MANAJEMEN DATA MAHASISWA ======\n");
	printf("======== HANIF AL FATHONI 20081010001 ========\n");
	printf("==============================================\n");
	
	printf("\nMasukkan jumlah data mahasiswa yang akan anda input: ");
	scanf("%d", &n);
	inputData(mhs, n);
	printf("\n");
	
	do {
		printf("\n=== SILAHKAN PILIH MENU YANG DI BAWAH INI ===\n");
		printf("1. TAMPILKAN DATA MAHASISWA\n");
		printf("2. HAPUS DATA MAHASISWA\n");
		printf("3. CARI DATA MAHASISWA\n");
		
		printf("Masukkan pilihan anda: ");
		scanf("%d", &menu);
		
		printf("\n");
		
		switch(menu) {
			case 1 :
				tampilData(mhs, n);
				printf("\n");
				break;
			case 2 :
				printf("======================= Hapus Data Mahasiswa =======================\n\n");
				tampilData(mhs, n);
				printf("\n");
				printf("Masukkan NPM Mahasiswa yang ingin dihapus berdasarkan daftar data di atas: ");
				scanf("%d", &npm);
				hapusData(mhs, n, npm);
				printf("\n");
				break;
			case 3 :
				printf("============== Cari Data Mahasiswa ==============\n");
				printf("Masukkan NPM Mahasiswa yang ingin dicari: ");
				scanf("%d", &npm);
				cariData(mhs, n, npm);
				printf("\n");
				break;
			default :
				printf("Maaf, input yang anda masukkan salah/invalid");
				printf("\n");
				break;
		}
		printf("\n");
		
		printf("Ingin kembali ke menu pilihan? (Y/T): ");
		scanf("%c", &kembali); scanf("%c", &kembali);
	}
	while(kembali == 'y' || kembali == 'Y');
}

void inputData(struct datamhs daftar[80], int s) {
	int i;
	
	printf("============== Input Data Mahasiswa ==============\n");\
	
	for(i = 0; i < s; i++) {
		printf("Masukkan detail data untuk mahasiswa ke-%d\n", i+1);
		
		printf("Masukkan NPM mahasiswa: ");
		fflush(stdin);
		scanf("%d", &daftar[i].npm);
		
		printf("Masukkan nama mahasiswa: ");
		fflush(stdin);
		scanf("%[^\n]", daftar[i].nama);
		
		printf("Masukkan program studi mahasiswa: ");
		fflush(stdin);
		scanf("%[^\n]", daftar[i].prodi);
		
		printf("Masukkan ipk mahasiswa: ");
		fflush(stdin);
		scanf("%f", &daftar[i].ipk);
		
		printf("\n");
	}
}

void tampilData(struct datamhs daftar[80], int s) {
	int i;
	
	printf("======================= Daftar Data Mahasiswa =======================\n\n");
	
	for(i = 0; i < s; i++) {
		printf("\n=== DATA MAHASISWA KE-%d ===\n", i+1);
		printf("NPM Mahasiswa : %d \n", daftar[i].npm);
		printf("Nama Mahasiswa : %s \n", daftar[i].nama);
		printf("Program Studi Mahasiswa : %s \n", daftar[i].prodi);
		printf("IPK Mahasiswa : %f \n", daftar[i].ipk);
	}
}

void hapusData(struct datamhs daftar[80], int s, int nomor) {
	int i, j, ketemu = 0;
	
	for(i = 0; i < s; i++) {
		if(daftar[i].npm == nomor) {
			ketemu = 1;
			j = i;
			break;
		}
	}
	if (ketemu == 1) {
		for(i = j; i < s-1; i++) {
			daftar[i] = daftar[i+1];
		}
	}
	else {
		printf("\nData tidak ditemukan.\n");
	}
	
	printf("\n=== Data mahasiswa setelah dihapus ===\n");
	for(i = 0; i < s-1; i++) {
		printf("\n=== DATA MAHASISWA KE-%d ===\n", i+1);
		printf("NPM Mahasiswa : %d \n", daftar[i].npm);
		printf("Nama Mahasiswa : %s \n", daftar[i].nama);
		printf("Program Studi Mahasiswa : %s \n", daftar[i].prodi);
		printf("IPK Mahasiswa : %f \n", daftar[i].ipk);
	}
}

void cariData(struct datamhs daftar[80], int s, int nomor) {
	int i;
	
	for(i = 0; i < s; i++) {
		if (daftar[i].npm == nomor) {
			printf("NPM Mahasiswa : %d \n", daftar[i].npm);
			printf("Nama Mahasiswa : %s \n", daftar[i].nama);
			printf("Program Studi Mahasiswa : %s \n", daftar[i].prodi);
			printf("IPK Mahasiswa : %f \n", daftar[i].ipk);
			
			return ;
		}
	}
	printf("Data tidak ditemukan\n");
}
