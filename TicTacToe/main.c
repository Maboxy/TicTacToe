//
//  main.c
//  TicTacToe
//
//  Created by Paul Hackenberg on 07.04.21.
//

#include <stdio.h>

struct Spieler{
    char cZeichen; //X oder O
    int iIndexer; //Index vom Spieler
};

struct Spielfeld{
    int iFeld[3][3];
};


int main(int argc, const char * argv[]) {

    struct Spielfeld spielfeldObjekt;
    struct Spielfeld *spielfeldptr = &spielfeldObjekt;  //bekommen die Speicheraddresse von spielfeldObjekt
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            spielfeldptr->iFeld[i][j] = 0;
        }
    }
    
    return 0;
}
