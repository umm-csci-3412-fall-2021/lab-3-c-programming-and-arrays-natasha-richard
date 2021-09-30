#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
  int sizeOfSizes = sizeof(sizes) / sizeof(int);
  mergesort(sizes, 0, sizeOfSizes - 2);	
  return sizes;
}

bool needsSorting(int range) {
  return range >= 2
}

void mergeRanges(int* values, int startIndex, int midPoint, int endIndex) {
  int rangeSize = endIndex - startIndex;
  int terminationBytes = 8;
  //Will allocate memory for the correct amount of integers, including the termination character
  int* destination = malloc(rangeSize*sizeof(int) + terminationBytes);
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex = 0;
  while(firstIndex < midPoint && secondIndex < endIndex) {
    if(values[firstIndex] < values[secondIndex]) {
      destination[copyIndex] = values[firstIndex];
      firstIndex++;
    } else {
      destination[copyIndex] = values[secondIndex];
      secondIndex++;
    }
    copyIndex++;
  }
  while(firstIndex < midPoint) {
    destination[copyIndex] = values[secondIndex];
    copyIndex++;
    firstIndex++;
  }
  while(secondIndex < endIndex) {
    destination[copyIndex] = values[secondIndex];
    copyIndex++;
    secondIndex++;
  }
  for(int i = 0; i < rangeSize; ++i) {
    values[i + startIndex] = destination[i];
  }
  destination[rangeSize + 1] = '\0';
  free(destination);
}

void mergesort(int* values, int startIndex, int endIndex) {
  int rangeSize = endIndex - startIndex;
  if(needsSorting(rangeSize)) {
    int midPoint = (startIndex + endIndex) / 2;
    mergesort(values, midPoint, endIndex);
    mergesort(values, startIndex, midPoint);
    mergeRanges(values, startIndex, midPoint, endIndex);
  }
}
