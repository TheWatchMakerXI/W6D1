#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struttura per una domanda
typedef struct {
    char question[256];
    char options[3][128];
    int correct_option;
} Question;

// Variabile globale per il punteggio totale
int total_score = 0;

// Funzione per mostrare il menu iniziale e ricevere la scelta dell'utente
char showMenu() {
    char choice;
    printf("Benvenuto al gioco di domanda/risposta!\n");
    printf("Scegli un'opzione:\n");
    printf("A) Iniziare una nuova partita\n");
    printf("B) Uscire dal gioco\n");
    printf("Scelta: ");
    scanf(" %c", &choice);
    return choice;
}

// Funzione per eseguire una nuova partita
void startNewGame() {
    char username[50];
    printf("Inserisci il tuo nome: ");
    scanf("%s", username);

    // Array di domande
    Question questions[3] = {
        {"Qual è il capitale d'Italia?", {"Roma", "Milano", "Napoli"}, 0},
        {"Qual è la valuta del Giappone?", {"Dollaro", "Yen", "Euro"}, 1},
        {"Chi ha scritto 'Divina Commedia'?", {"Dante", "Petrarca", "Boccaccio"}, 0}
    };

    int score = 0;

    // Ciclo attraverso le domande
    for (int i = 0; i < 3; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 3; j++) {
            printf("%d) %s\n", j + 1, questions[i].options[j]);
        }
        int answer;
        printf("Risposta: ");
        scanf("%d", &answer);
        if (answer - 1 == questions[i].correct_option) {
            score++;
        }
    }

    printf("%s, hai totalizzato un punteggio di %d su %d!\n", username, score, 3);
    total_score += score;
    printf("Punteggio totale accumulato: %d\n", total_score);
}

int main() {
    char choice;
    while (1) {
        choice = showMenu();
        if (choice == 'A' || choice == 'a') {
            startNewGame();
        } else if (choice == 'B' || choice == 'b') {
            printf("Grazie per aver giocato! Punteggio totale finale: %d\n", total_score);
            break;
        } else {
            printf("Scelta non valida. Riprova.\n");
        }
    }
    return 0;
}
