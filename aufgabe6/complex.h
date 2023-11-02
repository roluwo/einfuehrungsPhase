//complex.h

#include <stdio.h>

typedef struct{
    float realTeil;
    float imaginaerTeil;
}complexNumber;

complexNumber add(complexNumber z,complexNumber w);
complexNumber sub(complexNumber z,complexNumber w);
complexNumber mult(complexNumber z,complexNumber w);
complexNumber div(complexNumber z,complexNumber w);
void printComplex(complexNumber z);