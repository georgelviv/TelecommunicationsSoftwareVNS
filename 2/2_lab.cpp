#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include "utils.h"

using namespace std;

const int m = 2, n = 2;

void setRandomValues (double array[], int arraySize);
double getExpectedValue (double array[], int arraySize);
double getVariance (double array[], int arraySize, double expectedValue);
double findMaxValue (double array[], int arraySize);
double findMinValue (double array[], int arraySize);
void buildHistogram(double array[], int arraySize, int intervalQuantity);
void analyzeArray (double array[], int arraySize);
void setNewValues (double array[], int arraySize, int m, int n);

int main() {
	int arraySize = 200;
	double g[arraySize];
	

	srand((unsigned)time(NULL));
	printf("\n");
	setRandomValues(g, arraySize);
	analyzeArray(g, arraySize);
	printf("\n \n");
	setNewValues(g, arraySize, m, n);
	analyzeArray(g, arraySize);

	return 0;
}

void analyzeArray (double array[], int arraySize) {
	double expectedValue, variance, maxV, minV;
	
	expectedValue = getExpectedValue(array, arraySize);
	variance = getVariance(array, arraySize, expectedValue);
	maxV = findMaxValue(array, arraySize);
	minV = findMinValue(array, arraySize);
	printf("ExpectedValue: %f \n", expectedValue);
	printf("Variance: %f \n", variance);
	printf("MaxValue: %f \n", maxV);
	printf("MinValue: %f \n", minV);
	buildHistogram(array, arraySize, 10);
}
 
void setRandomValues (double array[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		array[i] = utils::genRandomMuller();
	}
}

double getExpectedValue (double array[], int arraySize) {
	double sum = 0;
	
	for (int i = 0; i < arraySize; i++) {
		sum += array[i];
	}
	
	return sum / arraySize;
}

double getVariance (double array[], int arraySize, double expectedValue) {
	double s = 0;
	
	for (int i = 0; i < arraySize; i++) {
		s += pow(expectedValue * array[i], 2);
	}
	
	return s / arraySize;
}

double findMaxValue(double array[], int arraySize) {
	double maxV = array[0];
	
	for (int i = 1; i < arraySize; i++) {
		maxV < array[i] && (maxV = array[i]);
	}
	
	return maxV;
}

double findMinValue(double array[], int arraySize) {
	double minV = array[0];
	
	for (int i = 1; i < arraySize; i++) {
		minV > array[i] && (minV = array[i]);
	}
	
	return minV;
}

void buildHistogram(double array[], int arraySize, int intervalQuantity) {
	double diff, intervalSize, minV;
	int intValues[intervalQuantity];
	minV = findMinValue(array, arraySize);
	diff = findMaxValue(array, arraySize) - minV;
	intervalSize = diff / intervalQuantity;

	for (int i = 0; i < intervalQuantity; i++) {
		intValues[i] = 0;
	}	
	
	for (int i = 0; i < arraySize; i++) {
		int intervalNum = ceil((array[i] - minV) / intervalSize);
		intValues[intervalNum] += 1;
	}
	
	printf("\n");
	for (int i = 0; i < intervalQuantity; i++) {
		printf("|");
		for (int y = 0; y < intValues[i]; y++) {
			printf("-");
		}
		printf("\n");
	}
}

void setNewValues (double array[], int arraySize, int m, int n) {
	for (int i = 0; i < arraySize; i++) {
		array[i] += m;
		array[i] *= n;
	}
}

