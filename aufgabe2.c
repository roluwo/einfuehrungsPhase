//aufgabe2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 9
#define MAX 9

void createMatrices(int matrix1[X][X], int matrix2[X][X], int resultMatrix[X][X]);
void multiplyMatrices(int matrix1[][X], int matrix2[X][X], int resultMatrix[X][X]);
void printMatrix(int matrix[X][X]);

int main() {
    int matrix1[X][X], matrix2[X][X], resultMatrix[X][X];
    
    createMatrices(matrix1[X][X], matrix2[X][X], resultMatrix[X][X]);
    
    printMatrix(matrix1[X][X]);
    printMatrix(matrix2[X][X]);
    printMatrix(resultMatrix[X][X]);
    
    multiplyMatrices(matrix1[X][X], matrix2[X][X], resultMatrix[X][X]);
    
    printMatrix(matrix1[X][X]);
    printMatrix(matrix2[X][X]);
    printMatrix(resultMatrix[X][X]);

}

void createMatrices(int matrix1[X][X], int matrix2[X][X], int resultMatrix[X][X]) {

    srand(time(NULL));//Initialisierung des RandomGenerators

    for (int i = 0; i < X; i++) {
        
        for (int j = 0; j < X; j++) {
            
            matrix1[i][j] = rand() % MAX+1;//Random aus modulo 10
            matrix2[i][j] = rand() % MAX+1;
            resultMatrix[i][j] = 0; //Initialisierung als NullMatrix
        
        }
    }
}

void multiplyMatrices(int matrix1[X][X], int matrix2[X][X], int resultMatrix[X][X]){

     for (int i = 0; i < X; i++) {
        
        for (int j = 0; j < X; j++) {
            
           for (int k = 0; k < X; k++) { 

            resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j]; //Formel für die MatrixMultiplikation

           }
        
        }
    }
}

void printMatrix(int matrix[X][X]) {

    for (int i = 0; i < X; i++) {
        
        for (int j = 0; j < X; j++) {
            
            if (j < X-1) {
                printf("%i", matrix[i][j]);
            }
            else {
                printf("%i\n", matrix[i][j]); //Zeilenumbruch nach letzter Spalte
            }
        
        }
    }

}