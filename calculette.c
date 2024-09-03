#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float addition(float a, float b);
float soustraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);

float addition(float a, float b) {
    return a + b;
}

float soustraction(float a, float b) {
    return a - b;
}

float multiplication(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    if (b == 0) {
        printf("Erreur : division par zéro non permise.\n");
        return 0;  // Retourner une valeur spéciale pour indiquer une erreur
    }
    return a / b;
}

int main() {
    int choix;
    float a, b, res;
    char continuer;

    printf("Bienvenue dans la calculatrice.\n");

    do {
        printf("\nEntrez le premier nombre : ");
        while (scanf("%f", &a) != 1) {
            printf("Entrée invalide pour le premier nombre.\n");
            while (getchar() != '\n');
        }

        printf("Entrez le deuxième nombre : ");
        while (scanf("%f", &b) != 1) {
            printf("Entrée invalide pour le deuxième nombre.\n");
            while (getchar() != '\n');
        }

        printf("Choisissez l'opération à réaliser :\n");
        printf("1 - Addition\n");
        printf("2 - Soustraction\n");
        printf("3 - Multiplication\n");
        printf("4 - Division\n");
        printf("Entrez le numéro de l'opération : ");
        while (scanf("%d", &choix) != 1) {
            printf("Entrée invalide pour le choix d'opération.\n");
            while (getchar() != '\n');
        }

        switch (choix) {
            case 1:
                res = addition(a, b);
                printf("Le résultat de %.2f + %.2f est : %.2f\n", a, b, res);
                break;
            case 2:
                res = soustraction(a, b);
                printf("Le résultat de %.2f - %.2f est : %.2f\n", a, b, res);
                break;
            case 3:
                res = multiplication(a, b);
                printf("Le résultat de %.2f * %.2f est : %.2f\n", a, b, res);
                break;
            case 4:
                res = division(a, b);
                if (b != 0) {  // Ne pas afficher le résultat si la division par zéro a eu lieu
                    printf("Le résultat de %.2f / %.2f est : %.2f\n", a, b, res);
                }
                break;
            default:
                printf("Erreur : choix invalide. Veuillez entrer un numéro entre 1 et 4.\n");
                return 1;
        }

        printf("\nSouhaitez-vous effectuer un autre calcul ? (o/n) : ");
        scanf(" %c", &continuer);  // Note l'espace avant %c pour ignorer les espaces blancs

    } while (continuer == 'o' || continuer == 'O');

    printf("Merci d'avoir utilisé la calculatrice. Au revoir !\n");

    return 0;
}
