#include <stdio.h>
#include <stdlib.h>
#ifndef MAGO_H
#define MAGO_H

#include <unistd.h> // Per usare sleep
void displayMagoCattivo() {
    printf("          ____   \n");
    printf("         /    \\  \n");
    printf("        /______\\ \n");
    printf("       (        )\n");
    printf("        \\ ~  ~ / \n");
    printf("         \\_==_/  \n");
    printf("          |  |   \n");
    printf("         /|__|\\  \n");
    printf("        //    \\\\ \n");
    printf("       ||      ||\n");
    printf("       ||  |   ||\n");
    printf("       ||  |   ||\n");
    printf("       ||__|___||\n");
    printf("       /       \\ \n");
    printf("      /|  | | | |\\ \n");
    printf("     /_|__|_|_|_|_\\\n");
    printf("     ~~~~~~~~~~~~~~\n");
}

void introduzioneGioco() {
    printf("\n\n");
    displayMagoCattivo();
    printf("\n\n");
    printf("Benvenuto, sciocco mortale!\n");
    printf("Io sono lo Stregone Oscuro, il padrone di questo gioco.\n");
    printf("Solo i più astuti riusciranno a sopravvivere alle mie domande.\n");
    printf("Se fallisci, la mia maledizione cadrà su di te per l'eternità.\n");
    printf("Preparati... il gioco sta per cominciare!\n");
    printf("Rispondi alle domande e dimostra il tuo valore, se ne hai il coraggio...\n");
}
#endif // MAGO_H

// Dichiarazione delle funzioni
void displayFiamme();
void gameOverAnimation();




// Funzione per mostrare le fiamme
void displayFiamme() {
    const char *frames[] = {
        "         (  .      )\n"
        "     )           (              )\n"
        "           .  '   .   '  .  '  .\n"
        "  (    , )       (.   )  (   ',    )\n"
        "   .' ) ( . )    ,  ( ,     )   ( .\n"
        "  ). , ( .   (  ) ( , ')  .' (  ,    )\n"
        " (_,) . ), ) _) _,')  (, ) '. )  ,. (' )\n",

        "          (.   )  )\n"
        "     )           (              )\n"
        "           .  '   .   '  .  '  .\n"
        "  (    , )       (.   )  (   ',    )\n"
        "   .' ) ( . )    ,  ( ,     )   ( .\n"
        "  ). , ( .   (  ) ( , ')  .' (  ,    )\n"
        " (_,) . ), ) _) _,')  (, ) '. )  ,. (' )\n",

        "           (.  .  )\n"
        "     )           (              )\n"
        "           .  '   .   '  .  '  .\n"
        "  (    , )       (.   )  (   ',    )\n"
        "   .' ) ( . )    ,  ( ,     )   ( .\n"
        "  ). , ( .   (  ) ( , ')  .' (  ,    )\n"
        " (_,) . ), ) _) _,')  (, ) '. )  ,. (' )\n"
    };
    int num_frames = sizeof(frames) / sizeof(frames[0]);

    for (int i = 0; i < 10; ++i) { // Loop per mostrare l'animazione 10 volte
        for (int j = 0; j < num_frames; ++j) {
            printf("\033[H\033[J"); // Codice ANSI per pulire lo schermo
            printf("%s\n", frames[j]);
            fflush(stdout); // Assicurati che l'output sia immediatamente visibile
            usleep(200000); // Pausa per 200 millisecondi
        }
    }
}

void gameOverAnimation() {
    displayFiamme();
}
int main() {
    displayMagoCattivo();
    introduzioneGioco();
   
    // Simula una perdita del gioco
    printf("Hai perso il gioco! Preparati a essere consumato dalle fiamme!\n");
    sleep(2); // Pausa per drammatizzare
    gameOverAnimation();
    return 0;
    // Inizia il gioco delle domande qui
}