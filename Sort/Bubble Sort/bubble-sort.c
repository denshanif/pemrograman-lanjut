#include <stdio.h>

int main()
{
	int array[100] = {22, 10, 15, 3, 8 , 2}, n = 6, i, j, tukar;

	// Bubble sort ascending
	for (i = 0 ; i < n - 1; i++)
	{
		for (j = 0 ; j < n - i - 1; j++)
			{
				if (array[j] > array[j+1])
      				{
						tukar      = array[j];
						array[j]   = array[j+1];
						array[j+1] = tukar;
					}
			}
	}

	printf("\nArray dalam urutan ascending:\n");

	for (i = 0; i < n; i++)
		printf("%d  ", array[i]);
	
	// Bubble sort descending	
	for (i = 0 ; i < n - 1; i++)
	{
		for (j = 0 ; j < n - i - 1; j++)
			{
				if (array[j] < array[j+1])
      				{
						tukar      = array[j];
						array[j]   = array[j+1];
						array[j+1] = tukar;
					}
			}
	}
	
	printf("\nArray dalam urutan descending:\n");

	for (i = 0; i < n; i++)
		printf("%d  ", array[i]);

	return 0;
}
