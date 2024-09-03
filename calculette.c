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

void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choix;
    char option;
    float a, b, res;
    bool continuer = true;
    bool utiliser_resultat = false;

    printf("Bienvenue dans la calculatrice.\n");
    while(true){
        if(!utiliser_resultat){
            printf("\nEntrez le premier nombre : ");
            while (scanf("%f", &a) != 1) {
                printf("Entrée invalide pour le premier nombre.\n");
                while (getchar() != '\n');
            }
        }else{
            a = res;  // Utiliser le dernier résultat comme premier opérande
            printf("\nUtiliser le dernier résultat (%.2f) comme premier nombre.\n", a);
            vider_buffer();  // Nettoyer le buffer

        }

        printf("Entrez le deuxième nombre : ");
        while (scanf("%f", &b) != 1) {
            printf("Entrée invalide pour le deuxième nombre.\n");
            while (getchar() != '\n');
            vider_buffer();  // Nettoyer le buffer

        }

        printf("Choisissez l'opération à réaliser :\n");
        printf("1 - Addition\n");
        printf("2 - Soustraction\n");
        printf("3 - Multiplication\n");
        printf("4 - Division\n");
        printf("Entrez le numéro de l'opération : ");
        while (scanf("%d", &choix) != 1) {
            printf("Entrée invalide pour le choix d'opération.\n");
            vider_buffer();  // Nettoyer le buffer

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
                continuer;
        }

        printf("\nQue souhaitez-vous faire ensuite ?\n");
        printf("1 - Utiliser le dernier résultat comme premier nombre pour une nouvelle opération\n");
        printf("2 - Entrer de nouveaux nombres pour une nouvelle opération\n");
        printf("3 - Réinitialiser et recommencer\n");
        printf("4 - Quitter\n");
        printf("Entrez votre choix : ");
        while (scanf(" %c", &option) != 1) {
            printf("Entrée invalide pour le choix suivant.\n");
            vider_buffer();  // Nettoyer le buffer
        }

        switch (option) {
            case '1':
                utiliser_resultat = true;
                break;
            case '2':
                utiliser_resultat = false;
                break;
            case '3':
                utiliser_resultat = false;
                a = b = res = 0;  // Réinitialiser les valeurs
                break;
            case '4':
                printf("Merci d'avoir utilisé la calculatrice. Au revoir !\n");
                return 0;
            default:
                printf("Option invalide. Veuillez entrer un numéro entre 1 et 4.\n");
                break;
        }
    }
    
    return 0;
}