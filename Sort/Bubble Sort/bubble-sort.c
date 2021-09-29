#include <stdio.h>

// Bubble sort ascending
void bubbleSort(int array[], int n) {
	int i;
	
	for (i = 0; i < n - 1; i++)
	{
		int sudahTertukar = 0;
		
		int j;
		
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j+1])
	     	{
				int tukar  = array[j];
				array[j]   = array[j+1];
				array[j+1] = tukar;
				
				sudahTertukar = 1;
			}
		}
		
		if (sudahTertukar == 0)
			break;		
	}	
}

// Tampilkan array hasil sorting
void tampilArray(int array[], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf("%d  ", array[i]);	
	}
}

int main()
{
	int array[] = {22, 10, 15, 3, 8 , 2};
	int n = 6;
	
	bubbleSort(array, n);

	printf("Array dalam urutan ascending:\n");
	
	tampilArray(array, n);

	return 0;
}
