//aufgabe2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 9
#define MAX 9

void createMatrices(int matrix1[x][x], int matrix2[x][x], int resultMatrix[x][x]);
void multiplyMatrices(int matrix1[x][x], int matrix2[x][x], int resultMatrix[x][x]);
void printMatrix(int matrix[x][x]);

int main() {
    int matrix1[x][x], matrix2[x][x], resultMatrix[x][x];
    
    createMatrices(matrix1[x][x], matrix2[x][x], resultMatrix[x][x]);
    
    printMatrix(matrix1[x][x]);
    printMatrix(matrix2[x][x]);
    printMatrix(resultMatrix[x][x]);
    
    multiplyMatrices(matrix1[x][x], matrix2[x][x], resultMatrix[x][x]);
    
    printMatrix(matrix1[x][x]);
    printMatrix(matrix2[x][x]);
    printMatrix(resultMatrix[x][x]);

}

void createMatrices(int matrix1[x][x], int matrix2[x][x], int resultMatrix[x][x]) {

    srand(time(NULL));//Initialisierung des RandomGenerators

    for (int i = 0; i < x; i++) {
        
        for (int j = 0; j < x; j++) {
            
            matrix1[i][j] = rand() % MAX+1;//Random aus modulo 10
            matrix2[i][j] = rand() % MAX+1;
            resultMatrix[i][j] = 0; //Initialisierung als NullMatrix
        
        }
    }
}

void multiplyMatrices(int matrix1[x][x], int matrix2[x][x], int resultMatrix[x][x]){

     for (int i = 0; i < x; i++) {
        
        for (int j = 0; j < x; j++) {
            
           for (int k = 0; k < x; k++) { 

            resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j]; //Formel für die MatrixMultiplikation

           }
        
        }
    }
}

void printMatrix(int matrix[x][x]) {

    for (int i = 0; i < x; i++) {
        
        for (int j = 0; j < x; j++) {
            
            if (j < x-1) {
                printf("%i", matrix[i][j]);
            }
            else {
                printf("%i\n", matrix[i][j]); //Zeilenumbruch nach letzter Spalte
            }
        
        }
    }

}