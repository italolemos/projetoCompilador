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

#define TAMANHO 100;
int i, j;
int inicio = 0;
int parentese = 1;
int auxiliar=0;

// kab=a
void regrak(int inicio, int tamanho, char arrayCharacters[]){
    char arrayA[10];
    int index = 1; //Ate aonde leu o arrayCharacters
    int indexA = 0;// Ate aonde o array esta preenchido
    
    for (i=0; i<tamanho; i++) {
        if(arrayCharacters[inicio+1] == '('){
            if (arrayCharacters[i] == ')'){
                break;
            }
            arrayA[i] = arrayCharacters[i+1];
            index++;
            indexA++;
        }
//        else {
//            printf("else\n");
//            //Pega o Segundo Elemento do array
//            arrayA[inicio] = arrayCharacters[inicio+1];
//            
//            inicio++;
//        }
    }
    
    for (j=index; j<tamanho; j++, indexA++) {
        arrayA[indexA] = arrayCharacters[j];
    }
   
//    for (i=0; i<10; i++){
//        printf("%c\n", arrayA[i]);
//    }

}

void remover_parentesis(char source[], char dest[]){
    bool open_first = false;
    bool last_close = false;
    int aux = 0, open = 0;
    
    
    int i;
    for (i=0; i<20; i++){
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
    
    for (i=0; i<20; i++){
        printf("Posicao %d - %c\n",i, dest[i]);
    }
}

int main(int argc, const char * argv[]) {
//    int vetorTamanho = 10000;

    
    char src[20] = "(KK)(S(kkk))";
    char dest[20];
    
    remover_parentesis(src, dest);
//    int len = strlen(src);
//    printf("%d", len);
    
    regrak(0, 10, src);
    
    return 0;
}
