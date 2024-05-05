#include <stdio.h>

void maiusculas(char *letras){
    char *ponteiro = letras;

    while(*ponteiro != '\0'){
        if(*ponteiro >= 'a' && *ponteiro <= 'z'){
            *ponteiro = *ponteiro - ('a' - 'A'); 
        }
        ponteiro++; 
    }
}

int main(){
    char frase[100];

    printf("Insira uma frase: ");
    scanf("%[^\n]", frase); 

    maiusculas(frase);
    printf("Frase com letras maiusculas: %s\n", frase); 

    return 0;
}