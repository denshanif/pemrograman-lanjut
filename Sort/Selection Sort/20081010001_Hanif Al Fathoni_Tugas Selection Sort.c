#include <stdio.h>

// Deklarasi fungsi tukar untuk penukaran nilai antar elemen array
void tukar(int *arr1, int *arr2) {
	int tampung = *arr1;
	*arr1 = *arr2;
	*arr2 = tampung;
}

// Deklarasi fungsi pengurutan nilai ascending dengan selection sort
void selection(int arr[], int n) {
	int i, j, minimum;
	
	for (i = 0; i < (n-1); i++) {
		minimum = i;
		
		// Looping pengurutan nilai
		for (j = i+1; j < n; j++) {
			if (arr[j] < arr[minimum])
				minimum = j;
		}
		if (minimum != i) {
			tukar(&arr[minimum], &arr[i]); // Nilai array pada index minimum dan index i dioper ke fungsi tukar untuk melakukan penukaran nilai
		}
	}
}

int main() {
	int arr[] = {32, 75, 69, 58, 21, 40}; // Deklarasi array
	int n = 6, i;
	
	// Output menampilkan array sebelum dilakukan selection sort
	printf("Sebelum dilakukan pengurutan selection sort: \n");
	for (i = 0; i < n; i++) {
		printf("%d  ", arr[i]);
	}
	
	printf("\n");
	
	// Pemanggilan fungsi selection sort. Pada pemanggilan ini, nilai variabel arr dan n dioperkan ke fungsi selection
	selection(arr, n);
	
	// Output menampilkan array setelah dilakukan selection sort ascending
	printf("\nSetelah dilakukan pengurutan selection sort secara ascending: \n");
	for (i = 0; i < n; i++) {
		printf("%d  ", arr[i]);
	}
	
	printf("\n");
}
