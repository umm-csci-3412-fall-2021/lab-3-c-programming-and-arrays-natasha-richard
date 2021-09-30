#include "mergesort.h"
#include <stdlib.h>

//This is a helper method that checks whether the array needs to be sorted based on its current range
bool needsSorting(int range) {
  return range >= 2;
}

//This is the method where all the sorting is done
void mergeRanges(int* values, int startIndex, int midPoint, int endIndex) {
  int rangeSize = endIndex - startIndex;
  //Will allocate the amount of space needed based on the current range
  int* destination = (int*) malloc(rangeSize*sizeof(int));
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
    destination[copyIndex] = values[firstIndex];
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
  //freeing the memory
  free(destination);
}

//This method recursively calls itself and mergeRanges.
void mergesortRange(int* values, int startIndex, int endIndex) {
  int rangeSize = endIndex - startIndex;
  if(needsSorting(rangeSize)) {
    int midPoint = (startIndex + endIndex) / 2;
    mergesortRange(values, midPoint, endIndex);
    mergesortRange(values, startIndex, midPoint);
    mergeRanges(values, startIndex, midPoint, endIndex);
  }
}

//The actual method being called to sort the given array.
void mergesort(int length, int* array) {
  mergesortRange(array, 0, length);
}
