//
//  main.c
//  TicTacToe
//
//  Created by Paul Hackenberg on 07.04.21.
//

#include <stdio.h>

struct Spieler{
    char cZeichen; //X oder O
    int iIndexer; //Index vom Spieler "1" oder "2"
};

struct Spielfeld{
    int iFeld[3][3];
};

void ausgeben(struct Spielfeld *spielfeldAusgebenptr){//Funktion Will einen Pointer auf ein Spielfeld struct
    for(int i = 0; i < 3; i++){         //Durch For-Schliefe kann jedes einzelne Feld ausgegeben werden
        for(int j = 0; j < 3; j++){
            printf("%d ", spielfeldAusgebenptr->iFeld[i][j]);
        }
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    printf("Welcome to TictacToe in C \n");
    struct Spielfeld spielfeldObjekt;
    struct Spielfeld *spielfeldptr = &spielfeldObjekt;  //bekommen die Speicheraddresse von spielfeldObjekt
    
    for(int i = 0; i < 3; i++){ //Spielfeld wird "Erstellt und alle einzelnen Feld 0 gesetzt
        for(int j = 0; j < 3; j++){
            spielfeldptr->iFeld[i][j] = 0;
        }
    }
    
    struct Spieler spieler1;    //ersten Spieler intitialisieren
    spieler1.cZeichen = 'X';
    spieler1.iIndexer = 1;
    struct Spieler *spieler1ptr = &spieler1; //Pointer von Spieler1 in die ptr Variable "laden"
    
    struct Spieler spieler2;    //Spieler 2 initialisieren
    spieler1.cZeichen = 'O';
    spieler1.iIndexer = 2;
    struct Spieler *spieler2ptr = &spieler2;
    
    ausgeben(spielfeldptr); //Aufruf der Funktion "ausgeben" dadurch wird das Spielfeld in der Konsole ausgegeben
    
    return 0;
}
