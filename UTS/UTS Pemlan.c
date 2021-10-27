#include <stdio.h>
#include <string.h>

typedef struct daerah {
    char kota[50];
    char provinsi[20];
} daerah;

struct dataVaksinasi {
    daerah daerah;
    double jumlahPendudukTotal;
    double jumlahLansia;
    double totalPendudukTervaksinasi;
    double totalLansiaTervaksinasi;
    char levelPPKM[1];
} dataVaksinasi[10], tukar;

void penentuanLevel();
void urutAscen();
void urutDescen();
void cariLevel();
void cariProvinsi();
void cariKabupatenKota();

const int jumlahData = 10;

int main() {
    int menu;
    char kembali;

    // Daerah 1
    strcpy(dataVaksinasi[0].daerah.provinsi, "Jawa Timur");
    strcpy(dataVaksinasi[0].daerah.kota, "Surabaya");
    dataVaksinasi[0].jumlahPendudukTotal = 287000;
    dataVaksinasi[0].jumlahLansia = 7200;
    dataVaksinasi[0].totalPendudukTervaksinasi = 210500;
    dataVaksinasi[0].totalLansiaTervaksinasi = 5760;

    // Daerah 2
    strcpy(dataVaksinasi[1].daerah.provinsi, "Jawa Timur");
    strcpy(dataVaksinasi[1].daerah.kota, "Sidoarjo");
    dataVaksinasi[1].jumlahPendudukTotal = 175250;
    dataVaksinasi[1].jumlahLansia = 5620;
    dataVaksinasi[1].totalPendudukTervaksinasi = 105180;
    dataVaksinasi[1].totalLansiaTervaksinasi = 3375;

    // Daerah 3
    strcpy(dataVaksinasi[2].daerah.provinsi, "Jawa Timur");
    strcpy(dataVaksinasi[2].daerah.kota, "Mojokerto");
    dataVaksinasi[2].jumlahPendudukTotal = 126820;
    dataVaksinasi[2].jumlahLansia = 6620;
    dataVaksinasi[2].totalPendudukTervaksinasi = 82450;
    dataVaksinasi[2].totalLansiaTervaksinasi = 2880;

    // Daerah 4
    strcpy(dataVaksinasi[3].daerah.provinsi, "Jawa Timur");
    strcpy(dataVaksinasi[3].daerah.kota, "Gresik");
    dataVaksinasi[3].jumlahPendudukTotal = 165526;
    dataVaksinasi[3].jumlahLansia = 4465;
    dataVaksinasi[3].totalPendudukTervaksinasi = 74490;
    dataVaksinasi[3].totalLansiaTervaksinasi = 1120;

    // Daerah 5
    strcpy(dataVaksinasi[4].daerah.provinsi, "Jawa Timur");
    strcpy(dataVaksinasi[4].daerah.kota, "Jombang");
    dataVaksinasi[4].jumlahPendudukTotal = 142560;
    dataVaksinasi[4].jumlahLansia = 5240;
    dataVaksinasi[4].totalPendudukTervaksinasi = 55580;
    dataVaksinasi[4].totalLansiaTervaksinasi = 1580;

    // Daerah 6
    strcpy(dataVaksinasi[5].daerah.provinsi, "Jawa Timur");
    strcpy(dataVaksinasi[5].daerah.kota, "Pasuruan");
    dataVaksinasi[5].jumlahPendudukTotal = 114520;
    dataVaksinasi[5].jumlahLansia = 6840;
    dataVaksinasi[5].totalPendudukTervaksinasi = 62990;
    dataVaksinasi[5].totalLansiaTervaksinasi = 2874;

    // Daerah 7
    strcpy(dataVaksinasi[6].daerah.provinsi, "Jawa Timur");
    strcpy(dataVaksinasi[6].daerah.kota, "Malang");
    dataVaksinasi[6].jumlahPendudukTotal = 188240;
    dataVaksinasi[6].jumlahLansia = 5580;
    dataVaksinasi[6].totalPendudukTervaksinasi = 135540;
    dataVaksinasi[6].totalLansiaTervaksinasi = 3630;

    // Daerah 8
    strcpy(dataVaksinasi[7].daerah.provinsi, "Jawa Timur");
    strcpy(dataVaksinasi[7].daerah.kota, "Lamongan");
    dataVaksinasi[7].jumlahPendudukTotal = 112680;
    dataVaksinasi[7].jumlahLansia = 4856;
    dataVaksinasi[7].totalPendudukTervaksinasi = 60850;
    dataVaksinasi[7].totalLansiaTervaksinasi = 2186;

    // Daerah 9
    strcpy(dataVaksinasi[8].daerah.provinsi, "Jawa Timur");
    strcpy(dataVaksinasi[8].daerah.kota, "Bangkalan");
    dataVaksinasi[8].jumlahPendudukTotal = 107540;
    dataVaksinasi[8].jumlahLansia = 3645;
    dataVaksinasi[8].totalPendudukTervaksinasi = 45180;
    dataVaksinasi[8].totalLansiaTervaksinasi = 1168;

    // Daerah 10
    strcpy(dataVaksinasi[9].daerah.provinsi, "Jawa Timur");
    strcpy(dataVaksinasi[9].daerah.kota, "Sampang");
    dataVaksinasi[9].jumlahPendudukTotal = 100540;
    dataVaksinasi[9].jumlahLansia = 3228;
    dataVaksinasi[9].totalPendudukTervaksinasi = 46250;
    dataVaksinasi[9].totalLansiaTervaksinasi = 1032;

    do {
        system("cls"); // System clear untuk membersihkan terminal
		// Output judul program
		printf("===================================================\n");
		printf("====== PROGRAM MANAJEMEN LEVEL PPKM COVID-19 ======\n");
		printf("=========== HANIF AL FATHONI 20081010001 ==========\n");
		printf("===================================================\n");
		// Menu pilihan
		printf("\n=== SILAHKAN PILIH MENU YANG DI BAWAH INI ===\n");
		printf("1. PENENTUAN LEVEL PPKM\n");
		printf("2. PENGURUTAN MENURUT LEVEL PPKM\n");
		printf("3. PENCARIAN MENURUT LEVEL PPKM, PROVINSI, KABUPATEN/KOTA\n");

        // Input pilihan menu dari user
		printf("Masukkan pilihan anda: ");
		scanf("%d", &menu);

		printf("\n");

		// Switch case untuk masing-masing menu
		switch(menu) {
			case 1 :
				penentuanLevel();
				printf("\n");
				break;
			case 2 :
				urutLevel();
				printf("\n");
				break;
			case 3 :
				pencarianData();
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

void penentuanLevel() {
    int i;
    double persentaseVaksin, persentaseLansia;

    for(i = 0; i < jumlahData; i++) {

        persentaseVaksin = (dataVaksinasi[i].totalPendudukTervaksinasi / dataVaksinasi[i].jumlahPendudukTotal) * 100;
        persentaseLansia = (dataVaksinasi[i].totalLansiaTervaksinasi / dataVaksinasi[i].jumlahLansia) * 100;

        if(persentaseVaksin >= 70 && persentaseLansia >= 60) {
            strcpy(dataVaksinasi[i].levelPPKM, "1");
        }
        else if(persentaseVaksin >= 50 && persentaseLansia >= 40) {
            strcpy(dataVaksinasi[i].levelPPKM, "2");
        }
        else {
            strcpy(dataVaksinasi[i].levelPPKM, "3");
        }
    }

    //tampilkan hasil level
    for(i = 0; i < jumlahData; i++) {
        printf("Provinsi:\t%s\n", dataVaksinasi[i].daerah.provinsi);
        printf("Kabupaten/Kota:\t%s\n", dataVaksinasi[i].daerah.kota);
        printf("Level PPKM:\t%s\n", dataVaksinasi[i].levelPPKM);
        printf("Jumlah Penduduk Total:\t%lf\n", dataVaksinasi[i].jumlahPendudukTotal);
        printf("Jumlah Lansia:\t%lf\n", dataVaksinasi[i].jumlahLansia);
        printf("Jumlah Penduduk Tervaksinasi:\t%lf\n", dataVaksinasi[i].totalPendudukTervaksinasi);
        printf("Jumlah Lansia Tervaksinasi:\t%lf\n", dataVaksinasi[i].totalLansiaTervaksinasi);
        printf("\n");
    }
}

void tampilDataUrut() {
    int i;

    printf("LEVEL PPKM\tNAMA KABUPATEN/KOTA\tNAMA PROVINSI\n\n");

    for(i = 0; i < jumlahData; i++) {
        printf("%s\t\t%s\t\t\t%s\n", dataVaksinasi[i].levelPPKM, dataVaksinasi[i].daerah.kota, dataVaksinasi[i].daerah.provinsi);
    }
}

void urutAscen() {
    int i, j, minimum;

	// Looping selection sort
	for (i = 0; i < (jumlahData-1); i++) {
		minimum = i;

		// Looping pengurutan nilai
		for (j = i+1; j < jumlahData; j++) {
			if (strcmp(dataVaksinasi[j].levelPPKM, dataVaksinasi[minimum].levelPPKM) < 0)
				minimum = j;
		}
		if (minimum != i) {
            tukar = dataVaksinasi[minimum];
            dataVaksinasi[minimum] = dataVaksinasi[i];
            dataVaksinasi[i] = tukar;
		}
	}
}

void urutDescen() {
    int i, j, minimum;

	// Looping selection sort
	for (i = 0; i < (jumlahData-1); i++) {
		minimum = i;

		// Looping pengurutan nilai
		for (j = i+1; j < jumlahData; j++) {
			if (strcmp(dataVaksinasi[j].levelPPKM, dataVaksinasi[minimum].levelPPKM) > 0)
				minimum = j;
		}
		if (minimum != i) {
            tukar = dataVaksinasi[minimum];
            dataVaksinasi[minimum] = dataVaksinasi[i];
            dataVaksinasi[i] = tukar;
		}
	}
}

void urutLevel() {
    int menu;

    printf("============================ Pengurutan LEVEL PPKM =============================\n\n");
	printf("\n================== SILAHKAN PILIH OPSI PENGURUTAN DI BAWAH INI =================\n");

	printf("1. URUT LEVEL PPKM ASCENDING\n");
	printf("2. URUT LEVEL PPKM DESCENDING\n");

	printf("Masukkan pilihan anda: ");
	scanf("%d", &menu);

	printf("\n");

	// Switch case pemilihan menu
	switch(menu) {
		case 1 :
			urutAscen();
			tampilDataUrut();
			printf("\n");
			break;
		case 2 :
			urutDescen();
			tampilDataUrut();
			printf("\n");
			break;
		default :
			printf("Maaf, input yang anda masukkan salah/invalid");
			printf("\n");
			break;
	}
}

void tampilHasilPencarian(int i) {
    printf("Provinsi:\t%s\n", dataVaksinasi[i].daerah.provinsi);
    printf("Kabupaten/Kota:\t%s\n", dataVaksinasi[i].daerah.kota);
    printf("Level PPKM:\t%s\n", dataVaksinasi[i].levelPPKM);
    printf("Jumlah Penduduk Total:\t%lf\n", dataVaksinasi[i].jumlahPendudukTotal);
    printf("Jumlah Lansia:\t%lf\n", dataVaksinasi[i].jumlahLansia);
    printf("Jumlah Penduduk Tervaksinasi:\t%lf\n", dataVaksinasi[i].totalPendudukTervaksinasi);
    printf("Jumlah Lansia Tervaksinasi:\t%lf\n", dataVaksinasi[i].totalLansiaTervaksinasi);
    printf("\n");
}

void cariLevel() {
    int i, flag = 0;
    char cari[1];

    printf("==================== Pencarian Data Menurut LEVEL ====================\n\n");

	printf("Masukkan LEVEL PPKM yang datanya ingin dicari: ");
	gets(cari);
	scanf("%s", &cari);

	for(i = 0; i < jumlahData; i++) {
		if (strcmp(dataVaksinasi[i].levelPPKM, cari) == 0) {
            flag = 1;
            tampilHasilPencarian(i);
		}
	}

	if (flag == 0) {
        printf("Data yang tidak ditemukan \n");
    }
}

void cariProvinsi() {
    int i, flag = 0;
    char cari[20];

    printf("==================== Pencarian Data Menurut Provinsi ====================\n\n");

	printf("Masukkan Provinsi yang datanya ingin dicari: ");
	gets(cari);
	scanf("%[^\n]", &cari);

	for(i = 0; i < jumlahData; i++) {
		if (strcmp(dataVaksinasi[i].daerah.provinsi, cari) == 0) {
            flag = 1;
            tampilHasilPencarian(i);
		}
	}

	if (flag == 0) {
        printf("Data yang tidak ditemukan \n");
    }
}

void cariKabupatenKota() {
    int i, flag = 0;
    char cari[50];

    printf("==================== Pencarian Data Menurut Kabupaten/Kota ====================\n\n");

	printf("Masukkan Kabupaten/Kota yang datanya ingin dicari: ");
	gets(cari);
	scanf("%s", &cari);

	for(i = 0; i < jumlahData; i++) {
		if (strcmp(dataVaksinasi[i].daerah.kota, cari) == 0) {
            flag = 1;
            tampilHasilPencarian(i);
		}
	}

	if (flag == 0) {
        printf("Data yang tidak ditemukan \n");
    }
}

void pencarianData() {
    int menu;

    printf("========================= Pencarian Data LEVEL PPKM =============================\n\n");
	printf("\n================== SILAHKAN PILIH OPSI PENCARIAN DI BAWAH INI =================\n");

	printf("1. CARI MENURUT LEVEL PPKM\n");
	printf("2. CARI MENURUT PROVINSI\n");
	printf("3. CARI MENURUT KABUPATEN/KOTA\n");

    printf("Masukkan pilihan anda: ");
	scanf("%d", &menu);

	printf("\n");

	// Switch case pemilihan menu
	switch(menu) {
		case 1 :
			cariLevel();
			printf("\n");
			break;
		case 2 :
			cariProvinsi();
			printf("\n");
			break;
		case 3 :
			cariKabupatenKota();
			printf("\n");
			break;
		default :
			printf("Maaf, input yang anda masukkan salah/invalid");
			printf("\n");
			break;
	}
}
