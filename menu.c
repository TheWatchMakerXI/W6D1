#include <stdio.h>


void stampamenu()
{
    printf("\nMenu\n");
    printf("A abbaiaia\n");
    printf("B miagola");
}



    
 //cat ~/.zshrc   
//printf("1033[H\033[Jva prima dell contenuto

   int main()
    {
    char scegli = 'c'; // inizializzazione con un valore qualsiasi che non sia 'A' o 'B'

    while(scegli != 'A' && scegli != 'B' && scegli != 'a' && scegli != 'b') {
        stampamenu();
        printf("\nA te la scelta: ");
        scanf(" %c", &scegli); // lo spazio libera il buffer prima di %c
        
        switch (scegli) {
            case 'A':
            case 'a':
                printf("\nMa che ti sembro un cane?");
                break;

            case 'B':
            case 'b':
                printf("\nMa che ti sembro un gatto?");    
                break;  
            default:
                printf("\nritenta");
                scegli = 'c'; // reimpostare scegli a un valore diverso da 'A' o 'B'
                break;
        }
    }

    return 0;
}

















