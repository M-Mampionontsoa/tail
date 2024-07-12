#include <stdio.h>
#include "liat.h"

void ouverture(FILE **file)
{
    *file=fopen("/home/mario/Linux/package","r");
    if(file==NULL)
    {
        exit(1);
    }
}
    
void fermeture(FILE *file)
{
    fclose(file);
}

void tail(FILE *file, int ligne) 
{
    fseek(file, 0, SEEK_END);
    long taille = ftell(file);
    long position = taille;
    int count = 0;
    char tab;

    while (position >= 0 && count <= ligne) 
    {
        fseek(file, position, SEEK_SET);
        tab= fgetc(file);
        if (tab == '\n' && position < taille- 1) 
        {
            count++;
        }
        position--;
    }

    if (position < 0) 
    {
        fseek(file, 0, SEEK_SET);
    } 
    else 
    {
        fseek(file, position + 2, SEEK_SET);
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)) 
    {
        printf("%s", line);
    }
}


void Option_n(FILE *file, int ligne) {
    fseek(file, 0, SEEK_END);       ///On se positionne à la fin du fichier grace à la fonction fseek
    long taille_fichier = ftell(file);
    long position = taille_fichier;
    int count = 0;
    char tab;

///On se positionne à la fin du fichier et compte le fichier en commençant par la fin
    
    while (position >= 0 && count <= ligne) {
        fseek(file, position, SEEK_SET);
        tab = fgetc(file);
        if (tab== '\n' && position < taille_fichier - 1) {
            count++;
        }
        position--;
    }

    if (position < 0)
    {
        fseek(file, 0, SEEK_SET);
    } 
    else 
    {
        fseek(file, position + 2, SEEK_SET);
    }

    char line[10000];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
}

void Option_f(FILE *file) {
    fseek(file, 0, SEEK_END);
    long position_act = ftell(file);

    while (1) 
    {
        fseek(file, position_act, SEEK_SET);
        char ch = fgetc(file);
        if (ch == EOF)
        {
            exit(1); 
            
        }
        putchar(ch);
        position_act = ftell(file);
    }
}

void Option_c(FILE *file, int octets) {
    fseek(file, octets, SEEK_END);
    int tab;
    while((tab = fgetc(file)) != EOF)
    {
        putchar(tab);
    }
}