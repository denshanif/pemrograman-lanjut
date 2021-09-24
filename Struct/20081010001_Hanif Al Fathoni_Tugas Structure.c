#include <stdio.h>
#include <stdbool.h>

struct datamhs {
	char npm[20];
	char nama[20];
	char prodi[20];
	float ipk;
} mhs[80];

int indexTerakhir = 0;

void tambahData();
void tampilData();
void hapusData();
void cariData();
void editData();
int cariIndex(char npm[20]);

int main() {
	int menu;
	char kembali;
	
	printf("==============================================\n");
	printf("====== PROGRAM MANAJEMEN DATA MAHASISWA ======\n");
	printf("======== HANIF AL FATHONI 20081010001 ========\n");
	printf("==============================================\n");
	
	do {
		system("clear");
		printf("\n=== SILAHKAN PILIH MENU YANG DI BAWAH INI ===\n");
		printf("1. TAMBAH DATA MAHASISWA\n");
		printf("2. TAMPILKAN DATA MAHASISWA\n");
		printf("3. HAPUS DATA MAHASISWA\n");
		printf("4. CARI DATA MAHASISWA\n");
		printf("5. EDIT DATA MAHASISWA\n");
		
		printf("Masukkan pilihan anda: ");
		scanf("%d", &menu);
		
		printf("\n");
		
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

bool cekNPM(char npm[20], int index) {
	int i;
	for (i = 0; i < indexTerakhir; i++) {
		if (index != i && strcmp(npm, mhs[i].npm) == 0) {
			return false;
		}
	}
	return true;
}

void inputData(int index) {
	printf("\n\n============== Input Data Mahasiswa ==============\n");\
	
	printf("Masukkan NPM mahasiswa: ");
	fflush(stdin);
	scanf("%s", &mhs[index].npm);
	
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
			
		printf("Masukkan ipk mahasiswa: ");
		fflush(stdin);
		scanf("%f", &mhs[index].ipk);
			
		printf("\n");
	}
}

void tambahData() {
	inputData(indexTerakhir);
	indexTerakhir++;
}

int cariIndex(char npm[20]) {
	int i;
	int index = -1;
	
	for (i = 0; i < indexTerakhir && index < 0; i++) {
		if (strcmp(mhs[i].npm, npm) == 0) {
			index = i;
		}
	}
	return index;
}

void tampilData() {
	int i;
	
	printf("======================= Daftar Data Mahasiswa =======================\n\n");
	
	for(i = 0; i < indexTerakhir; i++) {
		printf("\n=== DATA MAHASISWA KE-%d ===\n", i+1);
		printf("NPM Mahasiswa : %s \n", mhs[i].npm);
		printf("Nama Mahasiswa : %s \n", mhs[i].nama);
		printf("Program Studi Mahasiswa : %s \n", mhs[i].prodi);
		printf("IPK Mahasiswa : %f \n", mhs[i].ipk);
	}
}

void hapus(int index) {
	int i, tempat = 0;
	
	for (i = 0; i < indexTerakhir; i++) {
		if (i != index) {
			mhs[tempat] = mhs[i];
			tempat++;
		}
	}
	indexTerakhir--;
	
	printf("\n=== Data mahasiswa setelah dihapus ===\n");
	for(i = 0; i < indexTerakhir; i++) {
		printf("\n=== DATA MAHASISWA KE-%d ===\n", i+1);
		printf("NPM Mahasiswa : %s \n", mhs[i].npm);
		printf("Nama Mahasiswa : %s \n", mhs[i].nama);
		printf("Program Studi Mahasiswa : %s \n", mhs[i].prodi);
		printf("IPK Mahasiswa : %f \n", mhs[i].ipk);
	}
}

void hapusData() {
	char npm[20];
	
	printf("Masukkan NPM mahasiswa yang datanya ingin dihapus: ");
	scanf("%s", &npm);
	
	int index = cariIndex(npm);
	if (index < 0) {
		printf("Data tidak ditemukan\n");
		hapusData();
	}
	else {
		hapus(index);
	}
}

void cariData() {
	char cari[20];
	
	printf("Masukkan nama atau NPM mahasiswa yang datanya ingin dicari: ");
	scanf("%s", &cari);
	
	int i;
	
	for(i = 0; i < indexTerakhir; i++) {
		if (strcmp(mhs[i].npm, cari) == 0 || strcmp(mhs[i].nama, cari) == 0) {
			printf("NPM Mahasiswa : %s \n", mhs[i].npm);
			printf("Nama Mahasiswa : %s \n", mhs[i].nama);
			printf("Program Studi Mahasiswa : %s \n", mhs[i].prodi);
			printf("IPK Mahasiswa : %f \n", mhs[i].ipk);
			
			return ;
		}
	}
	printf("Data tidak ditemukan\n");
}

void editData() {
	char npm[20];
	
	printf("Masukkan NPM mahasiswa yang datanya ingin diedit: ");
	scanf("%s", &npm);
	
	int index = cariIndex(npm);
	if (index < 0) {
		printf("Data tidak ditemukan\n");
	}
	else {
		inputData(index);
	}
}
