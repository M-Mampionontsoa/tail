#include <stdio.h>
void ouverture(FILE **file);
void fermeture(FILE *file);
void tail(FILE *file,int ligne);
void Option_n(FILE *file, int lignes);
void Option_f(FILE *file);
void Option_c(FILE *file, int octets);