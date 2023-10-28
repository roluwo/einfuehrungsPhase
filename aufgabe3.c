//aufgabe3

#include <stdio.h>
#include <stdlib.h>

char fileName[100];
float* arr;
size_t arrSize = 0;
void getFileName();
void fillArray();
void printArray();
float findHighestFloat();

int main() {
    
    getFileName();
    fillArray();
    
    printf("%.2f\n", findHighestFloat());
    printf("Array:\n");
    printArray();
    
    free(arr);

    return 0;

}

void getFileName() {
    printf("Wie heißt die Datei?\n");
    scanf("%99s", fileName);
}

void fillArray() {

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
    
        perror("Could not open File");
        exit(1);

    }

    size_t currentIndex = 0;
    float value;

    while (fscanf(file, "%f\n", &value) != EOF) {
        if (currentIndex >= arrSize) {
                                       
            arrSize += 1;  //Erweiterung des Arrays
            arr = (float*)realloc(arr, arrSize * sizeof(float));
            if (arr == NULL) {
                
                perror("Array not reallocated.");
                exit(1);

            }
    
        }
    
        arr[currentIndex] = value;
        currentIndex++;

    }

    fclose(file);

}

void printArray() {
    for (int i = 0; i<arrSize; i++) {
        printf("%.2f\n", arr[i]);
    }
}

float findHighestFloat() {

    if (arrSize == 0){
        
        perror("Array is empty");
        exit(1);

    }
    
    float currentHigh = arr[0];

    for (int i = 1; i < arrSize; i++) {

        if (currentHigh<arr[i]){

            currentHigh = arr[i];

        }

    }

    return currentHigh;

}