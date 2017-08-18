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

int index_A(char source[]){
    int indexA = 1;
    int open = 0;
    
    if(source[indexA] == '('){
        open++;
        while (open != 0) {
            indexA++;
            if (source[indexA] == ')') {
                open--;
            }
            else if (source[indexA] == '('){
                open++;
            }
            
        }
    }
    
    return indexA;
}

int index_B(char source[], int indexA){
    int indexB = indexA + 1;
    int open = 0;
    
    if(source[indexB] == '('){
        open++;
        while (open != 0) {
            indexB++;
            if(source[indexB] == ')'){
                open--;
            }
            else if(source[indexB] == ')'){
                open++;
            }
        }
    }

    return indexB;
    
}

int index_C(char source[], indexB){
    int indexC = indexB + 1;
    int open = 0;
    
    if(source[indexC] == '('){
        open++;
        while (open != 0) {
            indexC++;
            if(source[indexC] == ')'){
                open--;
            }
            else if(source[indexC] == ')'){
                open++;
            }
        }
    }
    
    return indexC;
}

void regraI(char source[], char dest[]){
    int i;
    //get_a
    int a = index_A(source);
    
    //aplicar regra I
    int pos = 0;
    for (i=1; i<=a; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
    //Prencher com o resto
    for (i=a+1; i<TAMANHO; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
//        for (i=0; i<30; i++){
//            printf("Posicao %d - %c\n",i, dest[i]);
//        }
    
}

void regraB(char source[], char dest[]){
    int i;
    
    int a = index_A(source);
    int b = index_B(source, a);
    int c = index_C(source, b);
    
    
    //Aplicar Regra B
    int pos = 0;
    
    //Prencer com f
    for (i=1; i<=a; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
    //Adicionar (
    dest[pos] = '(';
    pos++;
    
    
    //Preencer com b
    for (i=a+1; i<=b; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
    //Preenche com c
    for (i=b+1; i<=c; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
    //Adicionar )
    dest[pos] = ')';
    pos++;
    
    //Prencer com o resto
    for (i=c+1; i<TAMANHO; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
//        for (i=0; i<30; i++){
//            printf("Posicao %d - %c\n",i, dest[i]);
//        }
    
}

void regraC(char source[], char dest[]){
    int i;
    
    int a = index_A(source);
    int b = index_B(source, a);
    int c = index_C(source, b);
    
    //Aplicar Regra C f x y => f y x
    int pos=0;
    
    //Prencer com f
    for (i=1; i<=a; i++) {
        dest[pos] = source[i];
        pos++;
    }

    //Preenche com y
    for (i=b+1; i<=c; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
    //Preencer com x
    for (i=a+1; i<=b; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
    //Prencer com o resto
    for (i=c+1; i<TAMANHO; i++) {
        dest[pos] = source[i];
        pos++;
    }
    
//            for (i=0; i<30; i++){
//                printf("Posicao %d - %c\n",i, dest[i]);
//            }

    
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




//char source[TAMANHO] = "S(KK)S(KKK)K(SK)KKKKSSK";
char source[TAMANHO] = "Ifxy";
char dest[TAMANHO];

int main(int argc, const char * argv[]) {
    
    regraC(source, dest);
    printf("\nTeste");
    return 0;
}

//int main(int argc, const char * argv[]) {
//
//    int j;
//    printf("teste");
//    for (j=0; j<14; j++) {
//        printf("Fonte: ");
//        printf(source);
//        printf("\n");
//        switch (source[0]) {
//            case '(':
//                remover_parentesis(source, dest);
//                break;
//            case 'K':
//                regrak(source, dest);
//                break;
//            case 'S':
//                regraS(source, dest);
//                break;
//            default:
//                break;
//        }
//        strcpy(source, dest);
//        printf("Destino: ");
//        printf(dest);
//        printf("\n");
//    }
//
//    return 0;
//}
