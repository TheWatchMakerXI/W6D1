#include <stdio.h>


void stampamenu()
{
    printf("\nMenu\n");
    printf("A abbaiaia\n");
    printf("B miagola");
}


int main()
{
    char scegli='\0';
 //cat ~/.zshrc   
//printf("1033[H\033[Jva prima dell contenuto

    while(scegli !='A'&& !='B')
        {
        stampamenu();
        printf("\nA te la scelta: ");
        scanf(" %c", &scegli); //lo spazio libera il buffer prima di %c
        switch (scegli)
        {
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
            break;
        }
        }
    return 0;
}


//scanf(" %99s", stringa); per prendere massimo 99 caratteri














