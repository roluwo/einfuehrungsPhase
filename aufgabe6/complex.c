//complex.c

#include "complex.h"

complexNumber add(complexNumber z,complexNumber w){
    complexNumber result;

    result.realTeil = z.realTeil + w.realTeil;
    result.imaginaerTeil = z.imaginaerTeil + w.imaginaerTeil;

    return result;
}
complexNumber sub(complexNumber z,complexNumber w){
    complexNumber result;

    result.realTeil = z.realTeil - w.realTeil;
    result.imaginaerTeil = z.imaginaerTeil - w.imaginaerTeil;

    return result;
}
complexNumber mult(complexNumber z,complexNumber w){
    complexNumber result;

    result.realTeil = (z.realTeil*w.realTeil - z.imaginaerTeil*w.imaginaerTeil);
    result.imaginaerTeil = (z.realTeil*w.imaginaerTeil + z.imaginaerTeil*w.realTeil);

    return result;
}
complexNumber div(complexNumber z,complexNumber w){
    complexNumber result;

    if(w.realTeil+w.imaginaerTeil){
        
        result.realTeil = (z.realTeil * w.realTeil + z.imaginaerTeil * w.imaginaerTeil) / ((w.realTeil * w.realTeil) * (w.imaginaerTeil * w.imaginaerTeil));
        result.imaginaerTeil = (z.imaginaerTeil * w.realTeil - z.realTeil * w.imaginaerTeil) / ((w.realTeil * w.realTeil) * (w.imaginaerTeil * w.imaginaerTeil));
    }

    return result;
}
void printComplex(complexNumber z){
    printf("Realteil: %f\nImaginärteil: %f\n", z.realTeil, z.imaginaerTeil);
}