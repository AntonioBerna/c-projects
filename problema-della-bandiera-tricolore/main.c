#include <stdio.h>
#include <stdbool.h>

// Global Macro
#define GREEN 0
#define WHITE 1
#define RED 2

// All Test
void printArray(int array[], int n);
void swap(int array[], int i, int j);
bool splitColorsCheck(int array[], int n);

// First Test
void splitColors(int array[], int n);

// Second Test
void splitColors2(int array[], int k);


int main(int argc, char *argv[]) {
	// First Test
	printf("First Test:\n");
	int first_array[] = {1, 0, 2, 0, 0, 1, 2, 2, 1};
	int n = sizeof(first_array) / sizeof(first_array[0]);
	printf("Bandiera Inserita: ");
	printArray(first_array, n);
	splitColors(first_array, n);
	printf("Bandiera Generata: ");
	printArray(first_array, n);
	printf("Bandiera Ordinata? %s", splitColorsCheck(first_array, n) ? "Si" : "No");
	
	printf("\n\n");

	// Second Test
	printf("Second Test:\n");
	int second_array[] = {1, 0, 2, 0, 0, 1, 2, 2, 1, 0, 1, 2};
	int k = sizeof(second_array) / sizeof(second_array[0]);
	printf("Bandiera Inserita: ");
	printArray(second_array, k);
	splitColors2(second_array, k);
	printf("Bandiera Generata: ");
	printArray(second_array, n);
	printf("Bandiera Ordinata? %s", splitColorsCheck(second_array, k) ? "Si" : "No");
	printf("\n");
}

void printArray(int array[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void splitColors(int array[], int n) {
	int last_green = 0, last_white = 0, last_red = n - 1;

	while (last_white <= last_red) {
		if (array[last_white] == WHITE) {
			last_white++;
		} else {
			if (array[last_white] == GREEN) {
				swap(array, last_white, last_green);
				last_white++;
				last_green++;
			} else {
				swap(array, last_white, last_red);
				last_red--;
			}
		}
	}
}

bool splitColorsCheck(int array[], int n) {
	int color = array[0];
	int how_many_colors = 1;
	int i;
	
	if (color != GREEN) {
		return false;
	} else {
		for (i = 1; i < n; i++) {
			if (array[i] != color) {
				color = array[i];
				how_many_colors++;
				i++;	
			}
		}
	}
	
	return how_many_colors == 3 ? true : false;
}

void splitColors2(int array[], int k) {
	int last_green = 0, last_white = k - 1, last_red = k - 1;

	while (last_green <= last_white) {
		if (array[last_green] == GREEN) {
			last_green++;
		} else {
			if (array[last_green] == WHITE) {
				swap(array, last_green, last_white);
				last_white--;
			} else {
				swap(array, last_red, last_white);
				swap(array, last_green, last_white);
				swap(array, last_red, last_white);
				last_red--;
			}
		}
	}
}