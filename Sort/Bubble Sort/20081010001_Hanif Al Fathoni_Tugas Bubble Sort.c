#include <stdio.h>

void tukar(int *array1, int *array2) {
	int tukar;
	
	tukar = *array1;
	*array1 = *array2;
	*array2 = tukar;
}

int main()
{
	int array[] = {22, 10, 15, 3, 8 , 2}, n = 6, i, j;

	// Bubble sort ascending
	for (i = n - 1; i > 0; i--) {
		for (j = n - 1; j >= n - i; j--) {
			if (array[j] < array[j-1]) {
				tukar(&array[j], &array[j-1]);
			}
		}
	}

	printf("Array dalam urutan ascending:\n");

	for (i = 0; i < n; i++)
		printf("%d  ", array[i]);

	return 0;
}
