//aufgabe2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 9
#define MAX 9

void createMatrices(int mat1[X][X], int mat2[X][X], int resultMat[X][X]);
void multiplyMatrices(int mat1[][X], int mat2[X][X], int resultMat[X][X]);
void printMatrix(int mat[X][X]);

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

void createMatrices(int mat1[X][X], int mat2[X][X], int resultMat[X][X]) {

    srand(time(NULL));//Initialisierung des RandomGenerators

    for (int i = 0; i < X; i++) {
        
        for (int j = 0; j < X; j++) {
            
            mat1[i][j] = rand() % MAX+1;//Random aus modulo 10
            mat2[i][j] = rand() % MAX+1;
            resultMat[i][j] = 0; //Initialisierung als NullMatrix
        
        }
    }
}

void multiplyMatrices(int mat1[X][X], int mat2[X][X], int resultMat[X][X]){

     for (int i = 0; i < X; i++) {
        
        for (int j = 0; j < X; j++) {
            
           for (int k = 0; k < X; k++) { 

            resultMat[i][j] += mat1[i][k] * mat2[k][j]; //Formel für die MatrixMultiplikation

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