//
//  main.c
//  TicTacToe
//
//  Created by Paul Hackenberg / maboxy on 07.04.21.
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
    printf("Bitte gib die Position an wo du hinsetzten möchtest (1-9): ");
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

void einsetzen(struct Spieler *aktuellerSpieler, int pos, struct Spielfeld *spielfeld){
    pos--;                              //Position um 1 verringern //8-1 = 7 //da Array imme rmit 0 beginnen
    int x = pos %3;                     //Modulo Opperator 4/3 = 1Rest1 Modulo ist nur der Rest also ist 7 %3 = 1
    int y = pos / 3;                    //7/3 = 2 //da mit Ganzzahlen gerechnet wird
    
    spielfeld->iFeld[y][x] = aktuellerSpieler->iIndexer;
}

int unentschieden(struct Spielfeld *spielfeld){
    // Überprüfen ob Feld != 0 ist oder ob ein Feld == 0 ist
    
    for(int i = 0; i < 3; i++){ //Spielfeld wird "Erstellt und alle einzelnen Feld 0 gesetzt
        for(int j = 0; j < 3; j++){
            if(spielfeld->iFeld[i][j] == 0){
                return 0;   //es gibt ein Feld mit einer 0
            }
        }
    }
    return 1;   //Unentscheiden
}

int gewonnen(struct Spielfeld *spielfeld){
    // gewonnen ist, wenn 3 gleiche Zahlen != 0 in einer Reihe stehen
    // senkrecht,   wagerecht,  diagonal
    //  0, 1, 2   , 0, 1, 2   , (00 11 22) (02 11 20)
    
    for(int i = 0; i < 3; i++){
        if(spielfeld->iFeld[i][0] == spielfeld->iFeld[i][1] && spielfeld->iFeld[i][0] == spielfeld->iFeld[i][2] && spielfeld->iFeld[i][0] != 0 ){
            return 1;   //gewonnen wagerecht
        }
    }
    
    for(int i = 0; i < 3; i++){
        if(spielfeld->iFeld[0][i] == spielfeld->iFeld[1][i] && spielfeld->iFeld[0][i] == spielfeld->iFeld[2][i] && spielfeld->iFeld[0][i] != 0 ){
            return 1;   //gewonnen senkrecht
        }
    }
    
    if(spielfeld->iFeld[0][0] == spielfeld->iFeld[1][1] && spielfeld->iFeld[0][0] == spielfeld->iFeld[2][2] && spielfeld->iFeld[0][0] != 0 ){
        return 1;   //gewonnen diagonal
    }
    
    if(spielfeld->iFeld[0][2] == spielfeld->iFeld[1][1] && spielfeld->iFeld[0][2] == spielfeld->iFeld[2][2] && spielfeld->iFeld[0][2] != 0 ){
        return 1;   //gewonnen diagonal
    }
    
    return 0;   //niemand hat gewonnen
}


int main(int argc, const char * argv[]) {
    printf("-_- Welcome to TictacToe in C :) -_- \n");
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
    spieler2.cZeichen = 'O';
    spieler2.iIndexer = 2;
    struct Spieler *spieler2ptr = &spieler2;
    
    struct Spieler *aktuellerSpieler = spieler1ptr;
    
    while(1 == 1){ // Eine Spielrunde
        ausgeben(spielfeldptr); //Aufruf der Funktion "ausgeben" dadurch wird das Spielfeld in der Konsole ausgegeben
        int iUeberprueftes = 1;
        int iUeberprueftes2 = 1;
        int iEingelesen;
        while(iUeberprueftes == 1 || iUeberprueftes2 == 1){
            iEingelesen = einlesen(spieler1ptr);
            printf("Eingelesene: %d \n", iEingelesen);
            iUeberprueftes = ueberpuefen1(iEingelesen);
            printf("Überprüfte1: %d \n", iUeberprueftes);
            iUeberprueftes2 = ueberpruefen2(iEingelesen, spielfeldptr);
            printf("Überprüfte2: %d \n", iUeberprueftes2);
        }
        einsetzen(aktuellerSpieler, iEingelesen, spielfeldptr);
        
        // Überprüfen ob gewonnen
        int iGewonnen = gewonnen(spielfeldptr);
        if(iGewonnen == 1){
            ausgeben(spielfeldptr);
            printf("Der Spieler %c hat gewonnen \n", aktuellerSpieler->cZeichen);
            break;
        }
        
        // Überprüfen ob unentschieden
        int iIstunentscheiden = unentschieden(spielfeldptr);
        if(iIstunentscheiden == 1){
            ausgeben(spielfeldptr);
            printf("IHR HABT UNENTSCHEIDEN GESPIELT \n");
            break;
        }

        // aktuellen Spieler wechseln
        if(aktuellerSpieler == spieler1ptr){
            aktuellerSpieler = spieler2ptr;
        }
        else{
            aktuellerSpieler = spieler1ptr;
        }
        
    }
    return 0;
}
