#include <stdio.h>
#include "liat.h"

int main(int argc,char *argv[])
{
    int n=0;    //Le nombre de ligne à afficher lors de l'option -n
    int c=0;    //Le nombre de octet à afficher lors de l'option -c
    FILE *file=NULL;
    ouverture(&file);
    tail(file,10);
    Option_n(file,n);
    Option_f(file);
    Option(file,c);
    fermeture(file);

    
}
        
