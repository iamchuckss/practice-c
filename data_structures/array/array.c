/*
 * array.c
 *
 * Author: Chuck
 * Created on 19/03/2018
 *
 * Implementation of Array in C
 *
 */

  /*
 Return Codes
 -1 - Array Erased
 0 - Success
 1 - Invalid Position
 2 - Position already initialized (use update function)
 3 - Position not initialized (use insert function)
 4 - Position already empty
 5 - Array is full
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

CArray* getCArray(int size) {
    CArray* array = (CArray*) malloc(sizeof(CArray));
    array->array = (int*) malloc(sizeof(int) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->array[i] = 0;
    }
    return array;
}

int insertValueCArray(CArray *array, int position, int value) {
    if (position >= 0 && position < array->size) {
        if (array->array[position] == 0) {
            array->array[position] = value;
            return SUCCESS;
        } else {
            return POSITION_INIT;
        }
    } else {
        return INVALID_POSITION;
    }
}

int removeValueCArray(CArray *array, int position) {

    if (position >= 0 && position < array->size) {
        if (array->array[position] != 0) {
            array->array[position] = 0;

            return SUCCESS;
        } else {
            return POSITION_EMPTY;
        }
    }
    return INVALID_POSITION;
}


int pushValueCArray(CArray *array, int value) {
    int status = 0;
    // look for first empty spot
    for (int i = 0; i < array->size; i++) {
        if (array->array[i] == 0) {
            array->array[i] = value;
            status = 1;
            break;
        }
    }
    if (status == 1) return SUCCESS;
    else return ARRAY_FULL;
}

int updateValueCArray(CArray *array, int position, int value) {
    if (position >= 0 && position < array->size) {
        if (array->array[position] != 0) {
            array->array[position] = value;
            return SUCCESS;
        } else {
            return POSITION_NOT_INIT;
        }
    } else {
        return INVALID_POSITION;
    }
}

int eraseCArray(CArray *array) {
    for (int i = 0; i < array->size; i++) {
        array->array[i] = 0;
    }
    return 0;
}

int switchValuesCArray(CArray *array, int position1, int position2) {
    if (position1 >= 0 && position1 < array->size
        && position2 >= 0 && position2 < array->size) {
        swap(array, position1, position2);
        return SUCCESS;
    }
    return INVALID_POSITION;
}

int reverseCArray(CArray *array)
{
    for (int i = 0; i < array->size / 2; i++) {
        swap(array, array->size - i - 1, i);
    }
    return SUCCESS;
}

int displayCArray(CArray *array)
{
    for (int i = 0; i < array->size; i++) {
        print("%d ", array->array[i]);
    }
    printf("\n");
    return 0;
}

void swap(CArray *array, int position1, int position2) {
    int temp = array->array[position1];
	array->array[position1] = array->array[position2];
	array->array[position2] = temp;
}

int blenderCArray(CArray *array) {
    srand(time(NULL) * array->size);
    int total = array->size * 100;
    for (int i = 0; i < total; i++) {
        swap(array, rand() % array->size, rand() % array->size);
    }
    return 0;
}

CArray * getCopyCArray(CArray *arr) {
    CArray* array = (CArray*)malloc(sizeof(CArray));
    array->array = (int*)malloc(sizeof(int) * arr->size);
    array->size = arr->size;
    for (int i = 0; i < arr->size; i++) {
        array->array[i] = arr->array[i];
    }
    return array;
}

int bubbleSortCArray(CArray *array) {
    for (int i = 0; i < array->size - 1; i++) {
        for (int j = 0; j < array->size - i - 1; j++) {
            if (array->array[j] > array->array[j+1]) {
                swap(array, j, j + 1);
            }
        }
    }
    return 0;
}

int selectionSortCArray(CArray *array) {
    int min;
    for (int i = 0; i < array->size - 1; i++) {
        min = i;
        for (int j = i + 1; j < array->size; j++) {
            if (array->array[j] < array->array[min]) min = j;
        }
        swap(array, min, i);
    }
    return 0;
}

int insertionSortCArray(CArray *array) {
    for (int i = 1; i < array->size; i++) {
        int num = array->array[i];
        int j = i - 1;
        while (j >= 0 && array->array[j] > num) {
            array ->array[j + 1] = array->array[j];
            j--;
        }
        array->array[j + 1] = num;
    }
    return 0;
}

int valueOcurranceCArray(CArray *array, int value) {
}

CArray * valuePositionsCArray(CArray *array, int value) {
}

int findMinCArray(CArray *array) {
}

int findMaxCArray(CArray *array) {
}
