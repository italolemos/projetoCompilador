//
//  main.c
//  Compiladores
//
//  Created by Italo Lemos on 06/06/17.
//  Copyright © 2017 Italo Lemos. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define TAMANHO 50

void regraS(char source[], char dest[]){
    int i;
    
    //get_a
    int openA = 0;
    int indexA = 1;
    
    if(source[indexA] == '('){
        openA++;
        while (openA != 0){
            indexA++;
            if(source[indexA] == ')'){
                openA--;
            }
            else if(source[indexA] == '('){
                openA++;
            }
        }
    }
    
    
    //get_b
    int openB = 0;
    int indexB = indexA + 1;
    
    if(source[indexB] == '('){
        openB++;
        while (openB != 0) {
            indexB++;
            if(source[indexB] == ')'){
                openB--;
            }
            else if(source[indexB] == ')'){
                openB++;
            }
        }
    }
    
    //get_c
    int openC = 0;
    int indexC = indexB + 1;
    
    if(source[indexC] == '('){
        openC++;
        while (openC != 0) {
            indexC++;
            if(source[indexC] == ')'){
                openC--;
            }
            else if(source[indexC] == ')'){
                openC++;
            }
        }
    }
    
    //Preenche com a
    int pos = 0;
    for (i=1; i<=indexA; i++) {
        dest[pos] = source[i];
        pos++;
    }
    

    //Preenche com c
    for (i=indexB+1; i<=indexC; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
    //Adicionar (
    dest[pos] = '(';
    pos++;
    
    //Preencer com b
    for (i=indexA+1; i<=indexB; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
    //Preenche com c
    for (i=indexB+1; i<=indexC; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
    //Adicionar )
    dest[pos] = ')';
    pos++;
    
    //Preencher resto
    for (i=indexC+1; i<TAMANHO; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
//    for (i=0; i<100; i++){
//        printf("Posicao %d - %c\n",i, dest[i]);
//    }
    
}

// kab=a
void regrak(char source[], char dest[]){
    int i;
    
    //get_a
    int open = 0;
    int indexA = 1;
    
    if(source[indexA] == '('){
        open++;
        while (open != 0){
            indexA++;
            if(source[indexA] == ')'){
                open--;
            }
            else if(source[indexA] == '('){
                open++;
            }
        }
    }
    
    
    //get_b
    int openB = 0;
    int indexB = indexA + 1;
    if(source[indexB] == '('){
        openB++;
        while (openB != 0) {
            indexB++;
            if(source[indexB] == ')'){
                openB--;
            }
            else if(source[indexB] == ')'){
                openB++;
            }
        }
    }
    
    //Preenche com a
    int pos = 0;
    for (i=1; i<=indexA; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
    //Preenche com b e com o resto
    for (i=indexB+1; i<TAMANHO; i++) {
        dest[pos] = source[i];
        pos++;
    }
    

//    for (i=0; i<30; i++){
//        printf("Posicao %d - %c\n",i, dest[i]);
//    }
    
}

void remover_parentesis(char source[], char dest[]){
    bool open_first = false;
    bool last_close = false;
    int aux = 0, open = 0;
    
    
    int i;
    for (i=0; i<TAMANHO; i++){
        if (source[i] == '('){
            if (open == 0 && open_first == false && last_close == false){
                open_first = true;
            }
            else {
                dest[aux] = source[i];
                aux++;
                open++;
            }
        }
        else if (source[i] == ')'){
                if (open != 0){
                    dest[aux] = source[i];
                    aux++;
                    open--;
                }
                else{
                    open_first = false;
                    last_close = true;
                }
            }
        else {
            dest[aux] = source[i];
            aux++;
        }
    }
    
//    for (i=0; i<30; i++){
//        printf("Posicao %d - %c\n",i, dest[i]);
//    }
}
//void reduzir(char source[], char dest[]){
//    int aux = 0;
//    
//    while(aux==0){
//        
//        switch (source[0]) {
//            case '(':
//                remover_parentesis(char source, char dest);
//                break;
//            default:
//                break;
//        }
//    }
//}



char source[TAMANHO] = "S(KK)S(KKK)K(SK)KKKKSSK";
char dest[TAMANHO];

int main(int argc, const char * argv[]) {

    int j;
    
    for (j=0; j<14; j++) {
        printf("Fonte: ");
        printf(source);
        printf("\n");
        switch (source[0]) {
            case '(':
                remover_parentesis(source, dest);
                break;
            case 'K':
                regrak(source, dest);
                break;
            case 'S':
                regraS(source, dest);
                break;
            default:
                break;
        }
        strcpy(source, dest);
        printf("Destino: ");
        printf(dest);
        printf("\n");
    }

    return 0;
}
