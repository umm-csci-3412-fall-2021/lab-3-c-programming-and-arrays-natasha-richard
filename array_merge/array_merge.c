#include "array_merge.h"
#include "../mergesort/mergesort.c"


int countDistinct(int a[], int x){
int i, j, count = 1;
for(i =1; i<x; i++){
	for(j=0; j<i; j++){
	if(a[i] == a[j])
		{break;}
	}
	if(i == j) {
	count++;}
}
	return count;
}
int* removeDuplicate(int a[], int size){
int i, j, k;
for(i=0; i<size; i++){
	for(j=i+1; j<size; j++){
		if(a[i] == a[j]){
			for(k=j; k<(size-1); k++){
			a[k] = a[k+1];}
		size--;
		j--;
		}
	}
}
return a;
}
int* array_merge(int num_arrays, int* sizes, int** values) {
 
       	if(num_arrays == 0) {
	 int* output = (int*) malloc(sizeof(int));
	 output[0] = 0;
	       	return output;
       	}
  int totalSize = 0;
  int i;
  for(i=0; i<num_arrays; i++) {
 	 totalSize = totalSize + sizes[i];
  
 }
 
int* bigArray = (int*) malloc((totalSize)*sizeof(int));
int totalCount = 0;
int n, j;
  for(n=0; n<num_arrays; n++){
  	for(j=0; j<sizes[n]; j++){
	bigArray[totalCount] = values[n][j];
	totalCount++;
	}
  }
  mergesort(totalSize, bigArray);
int distinctNums = countDistinct(bigArray, totalSize);
int* output = (int*) malloc((distinctNums + 1)*sizeof(int));
output[0] = distinctNums;
removeDuplicate(bigArray, totalSize);
int x;
for(x=0; x<distinctNums; x++){
output[x+1] = bigArray[x];}
free(bigArray);
  return output;
  }
