//main.c

#include "complex.h"

int main(){
    complexNumber x = {2,4};
    complexNumber y = {1,3};

    printComplex(add(x,y));
    printComplex(sub(x,y));
    printComplex(mult(x,y));
    printComplex(div(x,y));
}

