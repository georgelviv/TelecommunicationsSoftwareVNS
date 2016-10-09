#include <iostream>
#include "utils.h"

using namespace std;

const int m = 2, n = 2;

void gnomeSort (double arr[], int size);
void insertSort (double arr[], int size);
void swap (double & a, double & b);

int main() {
	int arrSize = 20;
	double g[arrSize];
	srand((unsigned)time(NULL));
	
	printf("-- Unsorted array  -- \n");
	utils::fillRandom(g, arrSize);
	utils::printArray(g, arrSize);
	printf("--  Sorted with gnomeSort  -- \n");
	gnomeSort(g, arrSize);
	utils::printArray(g, arrSize);
	
	printf("-- Unsorted array  -- \n");
	utils::fillRandom(g, arrSize);
	utils::printArray(g, arrSize);
	printf("--  Sorted with insertSort  -- \n");
	insertSort(g, arrSize);
	utils::printArray(g, arrSize);
	
	return 0;
}

void gnomeSort (double arr[], int size) {

	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
			for (int y = i; y > 0; y--) {
				if (arr[y] < arr[y - 1])  swap(arr[y], arr[y - 1]);
			}
		} 
	}
	
}

void insertSort(double arr[], int size) {
	int j;
	for (int i = 0; i < size; i++) {
		j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

void swap (double & a, double & b) {
	double temp = a;
	a = b;
	b = temp;
}


