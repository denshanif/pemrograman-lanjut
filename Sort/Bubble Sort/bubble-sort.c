#include <stdio.h>

int main()
{
	int array[] = {22, 10, 15, 3, 8 , 2}, n = 6, i, j, tukar;

	// Bubble sort ascending
	for (i = n - 1; i > 0; i--) {
		for (j = n - 1; j >= n - i; j--) {
			if (array[j] < array[j-1]) {
				tukar      = array[j];
				array[j]   = array[j-1];
				array[j-1] = tukar;
			}
		}
	}

	printf("Array dalam urutan ascending:\n");

	for (i = 0; i < n; i++)
		printf("%d  ", array[i]);

	return 0;
}
