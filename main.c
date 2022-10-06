#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
	Задание №0 
	В пространстве заданы n материальных точек. С некоторого момента точка с 
	наименьшей массой исчезает, передавая свою массу ближайшей к ней точке. 
	Так продолжается до тех пор, пока не останется одна точка. Реализовать этот процесс и найти 
	оставшуюся точку.
*/

int getIndexOfMin(int arr[], int size){
	int index = 0;
	int min = INT_MAX;
	for(int i = 0 ; i < size ; i++){
		if(arr[i] != 0 && arr[i] < min){
			min = arr[i];
			index = i;
		}
	}
	return index;
}

int getIndexOfClosest(int arr[], int size, int baseIndex){
	int i = baseIndex + 1; // right pointer
	int j = baseIndex - 1; // left pointer
	while(1){
		// guard 
		if(i >= size){
			i = 0; // if we reached end of array, bounce to beggining
		}
		if(j < 0){
			j = size - 1; // if we reached start of array , bounce to end
		}
		
		if(arr[i] != 0){
			return i;
		}
		if(arr[j] != 0){
			return j;
		}
		i++;
		j--;
	}
}

void fillArray(int array[], int size){
	srand(time(NULL));
	for(int i = 0; i < size ; i++){
		array[i] = rand() % 20;
	}
}

void printArray(int array[], int size){
    printf("- ");
	for(int i = 0; i < size ; i++){
		printf("%d - ", array[i]);
	}
	printf("\n");
}

bool transferMass(int array[], int size){
	printf("Before transfering mass: \n");
	int indexOfMin = getIndexOfMin(array,size);
	int indexOfClosest = getIndexOfClosest(array,size,indexOfMin);
	printArray(array,size);
	printf("Index of min[%d] = %d , Index of closest to min[%d] = %d\n", 
						array[indexOfMin], indexOfMin, array[indexOfClosest], indexOfClosest);
						
	if(indexOfClosest == indexOfMin){
		printf("That's the end\n");
		return false;
	}
	
	array[indexOfClosest] += array[indexOfMin];
	array[indexOfMin] = 0;
	
	printf("After transfering mass: \n");
	printArray(array,size);
	
	return true;
}

int main(int argc, char *argv[]) {
	int size = 100;
	int * array = calloc(size, sizeof(int));
	fillArray(array,size);
	while(transferMass(array,size) == true);
	
	free(array);
	return 0;
}