////
////  teste.c
////  Compiladores
////
////  Created by Italo Lemos on 06/06/17.
////  Copyright © 2017 Italo Lemos. All rights reserved.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//int i, auxiliar;
//int contador =0;
//int parentese = 0;
//int varrerArray (int inicio, int tamanho, char arrayCaracteres[]){
//    printf("inicio eh: %d ", inicio);
//    for (i=inicio; i<tamanho; i++){
//        if(arrayCaracteres[i]=='k'){
//            char a = 'k';
//            printf("\n a contem: %c \n", a);
//            
//            varrerArray(i+1, tamanho, arrayCaracteres);
//        }
//        if(arrayCaracteres[i] == '('){
//            parentese = 1;
//            auxiliar = i;
//            while(parentese == 1){
//                contador++;
//                if(arrayCaracteres[auxiliar]==')'){
//                    parentese = 0;
//                }
//                auxiliar++;
//            }//fim do while
//            auxiliar=0;
//            char b[contador];
//            for(i = i+1; i<contador; i++){
//                b[auxiliar] = arrayCaracteres[i];
//            }
//            printf("\n o array b eh: %s", b);
//        }
//        
//    }
//    
//    return 0;
//}
//
//int main()
//{
//    int tamanhoArray;
//    
//    printf("Qual o tamanho do array?\n");
//    scanf("%d", &tamanhoArray);
//    printf("\n tamanho array %d", tamanhoArray);
//    char arrayFinal[tamanhoArray];
//    char arrayDestino[tamanhoArray];
//    //criação do array
//    for(i=0 ; i<tamanhoArray; i++){
//        printf("\nDigite o elemento numero %d do array: ", i+1);
//        scanf("%s", &arrayFinal[i] );
//    }
//    
//    varrerArray(0, tamanhoArray, arrayFinal);
//    
//    printf("%s", arrayFinal);
//    return 0;
//}
