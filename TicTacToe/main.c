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
        printf("| ");
        for(int j = 0; j < 3; j++){
            if(spielfeldAusgebenptr->iFeld[i][j] == 1){
                printf("X | ");   //Bei Feld von Spieler 1 wird ein X ausgegeben
            }
            else if(spielfeldAusgebenptr->iFeld[i][j] == 2){
                printf("O | ");   //Bei Feld von Spieler 2 wird ein O ausgegeben
            }else{
                printf(" | ");    //Falss keine Eingabe richtig war oder leer ist wird nichts ausgegeben
            }
        }
        printf("\n");   //Spielfeld wird in 3x3 Optik ausgegeben
    }
    printf("\n");
}

int einlesen(struct Spieler *aktuellerSpieler){ //einlesen der Feldkoordinate
    int iPosition;
    printf("Bitte gib die Position an wo du hinsetzten möchtest (nur Ganzzahlen): ");
    scanf("%d", &iPosition);
    return iPosition;
}

int ueberpuefen1(int pos){  //Auf korrekte Eingabe Überprüfen
    if(pos < 0){
        return 1; //1 steht für "falsche Eingabe"
    }
    else if(pos > 9){
        return 1;
    }
    else{
        return 0;
    }
}

int ueberpruefen2(int pos, struct Spielfeld *spielfeld){
    pos--;                              //Position um 1 verringern //8-1 = 7 //da Array imme rmit 0 beginnen
    int x = pos %3;                     //Modulo Opperator 4/3 = 1Rest1 Modulo ist nur der Rest also ist 7 %3 = 1
    int y = pos / 3;                    //7/3 = 2 //da mit Ganzzahlen gerechnet wird
    if(spielfeld->iFeld[y][x] != 0){    //Überprüfen ob Feld schon belegt ist 
        return 1;
    }else{
        return 0;
    }
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
    
    int iUeberprueftes = 1;
    
    while(iUeberprueftes == 1){
        int iEingelesen = einlesen(spieler1ptr);
        printf("Eingelesene: %d \n", iEingelesen);
        iUeberprueftes = ueberpuefen1(iEingelesen);
        printf("Überprüfte: %d \n", iUeberprueftes);
    }

    
    return 0;
}
