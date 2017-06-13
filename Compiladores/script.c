#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//comentar ao executar o profiler
#define teste
//#define estatistica

#ifdef estatistica
int count_k = 0;
int count_s = 0;
#endif

//controle do tamanho da memoria.
//int size = 100000;

/*char *read_input()
 {
 #ifdef teste
 printf("%s\n", &"ENTER COMMAND: ");
 #endif
 char *input;
 int pos = 1;
 char *word = (char *)malloc(pos * sizeof(char));
 
 while ((input = getchar()) != '\n' && input != EOF && input != '\0')
 {
 *(word + pos - 1) = input;
 pos++;
 word = (char *)realloc(word, pos * sizeof(char));
 }
 *(word + pos - 1) = '\0';
 
 return word;
 }*/

void remove_par(char *source, char* dest)
{
    int open_par = 0;
    int close_par = 0;
    
    int open = 0;
    int close = 0;
    
    int pos = 0;
    //char* new_word;
    
    int i = 0;
    int slen = strlen(source);
    
    for (i ; i < slen; i++) {
        if (source[i] == '(')
        {
            open_par++;
        }
        else {
            break;
        }
    }
    
    int index = 0;
    
    i = open_par;
    //j = strlen(source);
    
    for (i ; i < slen; i++)
    {
        if (source[i] == ')' && open == close && close_par <= open_par)
        {
            close_par++;
        }
        else if (source[i] == ')')
        {
            dest[index] = source[i];
            index++;
            close++;
            
        }
        else if (source[i] == '(')
        {
            dest[index] = source[i];
            index++;
            open++;
        }
        else if (close_par > open_par)
        {
            break;
        }
        else {
            dest[index] = source[i];
            index++;
        }
    }
    
    //printf("%d\n", strlen(new_word));
    //printf("%s\n", word);
    dest[index] = '\0';
    
}

int get_index_a(char* word)
{
    int index = 1;
    
    int open = 0;
    if (word[index] == '(')
    {
        open++;
        while (open != 0)
        {
            index++;
            if (word[index] == ')')
            {
                open--;
            }
            else if (word[index] == '(')
            {
                open++;
            }
        }
    }
    
    return index;
}

int get_index_b(char* word, int index)
{
    index++;
    int open = 0;
    if (word[index] == '(')
    {
        open++;
        while (open != 0)
        {
            index++;
            if (word[index] == ')')
            {
                open--;
            }
            else if (word[index] == '(')
            {
                open++;
            }
        }
    }
    
    return index;
    
}
int get_index_c(char* word, int index)
{
    
    index++;
    int open = 0;
    if (word[index] == '(')
    {
        open++;
        while (open != 0)
        {
            index++;
            if (word[index] == ')')
            {
                open--;
            }
            else if (word[index] == '(')
            {
                open++;
            }
            
        }
    }
    
    return index;
}

void get_rule_S(char *source, char *dest, int *flag)
{
    int pos = 1;
    //char *temp = (char *)malloc(pos* sizeof(char));
    
    int a = get_index_a(source);
    int b = get_index_b(source, a);
    int c = get_index_c(source, b);
    
    
    //printf("Indice a : %d, Indice b: %d, Indice c: %d ", a, b, c);
    int slen = strlen(source);
    if (c < slen)
    {
        
        /*
         if (strlen(dest) <= strlen(source) + (2*(b - c)) + 2){
         
         (char *)realloc(dest, 10* (strlen(source) + (2 * (b - c) +2))*sizeof(char));
         }
         */
        
        int i = 1;
        
        for (i; i <= a; i++)
        {
            dest[pos - 1] = source[i];
            pos++;
            
        }
        
        i = (b + 1);
        
        for (i; i <= c; i++)
        {
            dest[pos - 1] = source[i];
            pos++;
            
        }
        dest[pos - 1] = '(';
        pos++;
        
        i = (a + 1);
        
        for (i; i <= b; i++)
        {
            dest[pos - 1] = source[i];
            pos++;
            
        }
        
        i = (b + 1);
        
        for (i; i <= c; i++)
        {
            dest[pos - 1] = source[i];
            pos++;
            
        }
        
        dest[pos - 1] = ')';
        pos++;
        
        i = (c + 1);
        
        for (i; i < slen; i++)
        {
            dest[pos - 1] = source[i];
            pos++;
        }
        dest[pos - 1] = '\0';
    }
    
    else {
        dest[strlen(dest) + 1] = '\0';
        printf("Destino : %s\n", dest);
        *flag = 1;
    }
}

void get_rule_K(char *source, char *dest, int  *flag)
{
    
    int pos = 1;
    //char *temp = (char *)malloc(pos* sizeof(char));
    
    int a = get_index_a(source);
    int b = get_index_b(source, a);
    int c = get_index_c(source, b);
    
    int slen = strlen(source);
    
    if (b < slen)
    {
        /*
         if (strlen(dest) < strlen(source) - (b - a)){
         dest = (char *)realloc(dest, strlen(source) - (b - a)*sizeof(char));
         }
         */
        //printf("Indice a : %d, Indice b: %d, Indice c: %d ", a, b);
        
        int i = 1;
        
        for (i; i <= a; i++)
        {
            dest[pos - 1] = source[i];
            pos++;
            
        }
        
        i = (b + 1);
        
        for (i; i < slen; i++)
        {
            
            dest[pos - 1] = source[i];
            pos++;
            
        }
        
        dest[pos - 1] = '\0';
        
    }
    else {
        //printf("TESTE %d, %c\n", a, source[a]);
        dest[strlen(dest) + 1] = '\0';
        printf("Destino : %s\n", dest);
        *flag = 1;
    }
    
}

void concat_Y(char *source, char *dest)
{
    char *Y = "S(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))(S(S(KS)(S(KK)(SKK)))(K(S(SKK)(SKK))))";
    //printf("Tamanho Source %d Tamanho Y %d\n", strlen(source), strlen(Y));
    
    int sleny = strlen(Y);
    
    int i = 0;
    
    for (i; i < sleny; i++)
    {
        dest[i] = Y[i];
    }
    
    int slens = strlen(source);
    
    i = 1;
    
    for (i; i < slens; i++)
    {
        dest[strlen(Y) + (i - 1)] = source[i];
    }
    
    dest[strlen(Y) + strlen(source) - 1] = '\0';
    //printf("DESTINO aqui%s\n", dest);
}


void gen_nstring(char *source, char *dest, int n) {
    //(Y(KK))Y=1   Y((Y(KK))K) Y=2    Y((Y((Y(KK))K))K) Y=3
    char *ystring = "(Y(KK))\0";
    int count = 1;
    
    int slen = strlen(ystring);
    
    int i = 0;
    
    for (i; i < slen; i++)
    {
        
        source[i] = ystring[i];
    }
    
    source[strlen(ystring)] = '\0';
    
    while (count < n)
    {
        
        if (count != 1) {
            
            dest[0] = 'Y';
            dest[1] = '(';
            dest[2] = '(';
            
            int slens = strlen(source);
            int i = 0;
            
            for (i; i < slens; i++)
            {
                dest[i + 3] = source[i];
            }
            
            dest[strlen(source) + 3] = ')';
            dest[strlen(source) + 4] = 'K';
            dest[strlen(source) + 5] = ')';
            dest[strlen(source) + 6] = '\0';
            
        }
        else {
            
            dest[0] = 'Y';
            dest[1] = '(';
            
            int slens = strlen(source);
            int i = 0;
            
            for (i; i < slens; i++)
            {
                dest[i + 2] = source[i];
            }
            dest[strlen(source) + 2] = 'K';
            dest[strlen(source) + 3] = ')';
            dest[strlen(source) + 4] = '\0';
        }
        
        int slend = strlen(dest);
        int i = 0;
        
        for (i; i < slend; i++)
        {
            source[i] = dest[i];
        }
        source[slend] = '\0';
        
        count++;
    }
    
}
void reduct_string(char* source, char* dest)
{
    
    int *flag = 0;
    //int buffer = size;
    
    while (flag == 0)
    {
        
#ifdef teste
        printf("Fonte: %s\n", source);
#endif
        
        switch (source[0]) {
            case 'S':
                
                get_rule_S(source, dest, flag);
                
#ifdef estatistica
                count_s++;
#endif
                break;
                
            case 'K':
                
                get_rule_K(source, dest, flag);
                
#ifdef estatistica
                count_k++;
#endif
                break;
                
            case '(':
                remove_par(source, dest);
                break;
                
            case 'Y':
                concat_Y(source, dest);
                break;
                
            default:
                *flag = 1;
        }
        
        //strcpy_s(source, strlen(dest) + 1, dest);
        
        //memmove(source, dest, strlen(dest)+1);
        
        strcpy(source, dest);
        
        
        /*if (strlen(source) > buffer / 2) {
         buffer = buffer * 2;
         dest = (char *)realloc(dest, buffer * sizeof(char));
         source = (char *)realloc(source, buffer * sizeof(char));
         #ifdef teste
         printf("ENTROU\n");
         #endif
         }*/
        
#ifdef teste
        printf("Destino : %s\n", dest);
#endif
        //source = dest;
        //printf("ERROR1\n");
        
    }
    
    
}

char source[1000000000];
char dest[1000000000];

//int main(void)
//{
//    //(Y(KK))Y=1   Y((Y(KK))K) Y=2    Y((Y((Y(KK))K))K) Y=3
//    //char *source = (char *)malloc(size * sizeof(char));
//    //char *dest = (char *)malloc(size * sizeof(char));
//    
//    //char source[100000];
//    //char dest[100000];
//    
//    /*	source[0] = 'a';
//     source[1] = 'b';
//     source[2] = 'c';
//     source[3] = 'd';
//     source[4] = 'e';
//     source[5] = 'f';
//     source[6] = 'g';
//     source[7] = 'h';
//     source[8] = 'i';
//     source[9] = '\0'; */
//    
//    
//    //int tamanho = strlen(source[0]) - 3;
//    
//    //strcpy(dest, source);
//    
//    //printf(dest);
//    
//    gen_nstring(source, dest, 1);
//    
//#ifdef teste
//    printf("ENTRADA Y: %s\n", source);
//#endif
//    
//    reduct_string(source, dest);
//    
//    
//#ifdef estatistica
//    printf("Numero de reducoes de K: %d\n", count_k);
//    printf("Numero de reducoes de S: %d\n", count_s);
//#endif
//    
//    return(0);
//}
//
