#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

struct data_barang{
    char *nama[20], *kategori[20];
    int harga, kode;
};

typedef struct data_barang barang;
barang data['0'];

FILE *file_data;

int main()
{
    int z = 0;

    file_data = fopen("Data.txt", "r");

    while (!feof(file_data)) 
    {
        fscanf(file_data,"\nKode : %d\nKategori : %s\nNama Barang : %s\nHarga : %d",&data[z].kode,&data[z].kategori,&data[z].nama,&data[z].harga);
        z++;
    }

    int i;

    for (i = 0; i < z; i++)
    {
        printf("%d\n", data[i].kode);
        printf("%s\n", data[i].kategori);
        printf("%s\n", data[i].nama);
        printf("%d\n\n", data[i].harga);
    }

    fclose(file_data);

    return 0;
}
