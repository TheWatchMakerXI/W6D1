#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struttura per una domanda
typedef struct {
    char question[256];
    char options[3][128];
    int correct_option;
} Question;

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

char showMenu() {
    char choice;
    printf("\n\n");
    displayMagoCattivo();
    printf("\n\n");
    printf("Benvenuto, sciocco mortale!\n");
    printf("Io sono lo Stregone Oscuro, il padrone di questo gioco.\n");
    printf("Solo i più astuti riusciranno a sopravvivere alle mie domande.\n");
    printf("Se fallisci, la mia maledizione cadrà su di te per l'eternità.\n");
    printf("Preparati... il gioco sta per cominciare!\n");
    printf("Rispondi alle domande e dimostra il tuo valore, se ne hai il coraggio...\n");
    printf("Quindi sciocco mortale, accetti di mettere in gioco la tua anima(A) oppure vuoi ritornare a casa a vivere la tua misarabile vita da sciocco(B)\n");
    scanf(" %c", &choice);
    return choice;
}

// Variabile globale per il punteggio totale
int total_score = 0;

// Funzione per simulare il lancio di un dado
int rollDice() {
    return (rand() % 6) + 1;
}

// Funzione per eseguire una nuova partita
void startNewGame() {
    char username[50];
    printf("Inserisci il tuo nome: ");
    scanf("%s", username);

    // Array di domande
    Question questions[10] = {
        {
            "Chi è l'autore de \"Il Signore degli Anelli\"?",
            {"J.R.R. Tolkien", "C.S. Lewis", "J.K. Rowling"},
            0
        },
        {
            "Chi è il fedele compagno di Frodo?",
            {"Legolas", "Samvise Gamgee", "Boromir"},
            1
        },
        {
            "In quale mondo immaginario è ambientato \"Il Signore degli Anelli\"?",
            {"Narnia", "Terra di Mezzo", "Westeros"},
            1
        },
        {
            "Come si chiama il malvagio signore oscuro in \"Il Signore degli Anelli\"?",
            {"Sauron", "Saruman", "Morgoth"},
            0
        },
        {
            "Come si chiama la città elfica dove si forma la Compagnia dell'Anello?",
            {"Gran Burrone", "Gondor", "Rohan"},
            0
        },
        {
            "Chi è il re di Rohan?",
            {"Theoden", "Denethor", "Elrond"},
            0
        },
        {
            "Come si chiama il luogo dove fu forgiato l'Unico Anello?",
            {"Monte Fato", "Fosso di Helm", "Isengard"},
            0
        },
        {
            "Che tipo di creatura è Legolas?",
            {"Hobbit", "Nano", "Elfo"},
            2
        },
        {
            "Come si chiama la spada di Aragorn dopo che è stata riforgiata?",
            {"Glamdring", "Anduril", "Pungolo"},
            1
        },
        {
            "Come si chiama lo zio di Frodo che trovò originariamente l'Unico Anello?",
            {"Bilbo Baggins", "Gandalf", "Gollum"},
            0
        }
    };

    int score = 0;

    printf("Lancia il dado per determinare le domande...\n");
    getchar(); // per consumare il newline rimasto nel buffer
    printf("Premi Enter per lanciare il dado...\n");
    getchar();

    // Genera tre numeri casuali per selezionare le domande
    int selected_questions[3];
    for (int i = 0; i < 3; i++) {
        selected_questions[i] = rollDice() - 1; // rollDice() restituisce un valore tra 1 e 6, sottraiamo 1 per l'indice
    }

    // Ciclo attraverso le domande selezionate
    for (int i = 0; i < 3; i++) {
        int q_index = selected_questions[i];
        printf("%s\n", questions[q_index].question);
        for (int j = 0; j < 3; j++) {
            printf("%d) %s\n", j + 1, questions[q_index].options[j]);
        }
        int answer;
        printf("Risposta: ");
        scanf("%d", &answer);
        if (answer - 1 == questions[q_index].correct_option) {
            score++;
        }
    }

    printf("%s, hai totalizzato un punteggio di %d su %d!\n", username, score, 3);
    total_score += score;
    printf("Punteggio totale accumulato: %d\n", total_score);
}

int main() {
    // Inizializza il generatore di numeri casuali
    srand(time(NULL));

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
