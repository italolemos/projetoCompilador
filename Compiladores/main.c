//
//  main.c
//  Compiladores
//
//  Created by Italo Lemos on 06/06/17.
//  Copyright © 2017 Italo Lemos. All rights reserved.
//

#include <stdio.h>

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
   
    for (i=0; i<10; i++){
        printf("%c\n", arrayA[i]);
    }

}


int main(int argc, const char * argv[]) {
//    int vetorTamanho = 10000;

    
    char F_array[10] = "k(kk)kS";
//    char D_array[vetorTamanho];
   
    
    regrak(0, 10, F_array);
    
    return 0;
}
