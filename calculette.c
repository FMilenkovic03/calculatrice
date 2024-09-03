#include <stdio.h>
#include <stdlib.h>

float addition(float a, float b);
float soustraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);


float addition(float a, float b){
	return a+b;
}

float soustraction(float a, float b){
	return a-b;
}

float multiplication(float a, float b){
	return a*b;
}

float division(float a, float b){
	if(b == 0){
		printf("erreur, pas de division par 0");
		return 0;
	}
	return a/b;
}

int main(){
	int choix;
	float a, b, res;
	printf("number a :");
	scanf("%f", &a);
	printf("number b :");
	scanf("%f", &b);

	printf("écrivez 1 pour addition, 2 pour soustraction, 3 pour multiplication, 4 pour division : ");
	scanf("%d", &choix);
	switch(choix)
	{
		case 1:
			res = addition(a, b);
			break;
		case 2:
			res = soustraction(a, b);
			break;
		case 3:
			res = multiplication(a, b);
			break;
		case 4:
			res = division(a, b);
			break;
		default:
        	printf("Erreur : choix invalide.\n");
        	return 1;  // Retourner un code d'erreur ou simplement continuer selon ton choix
	}
	printf("Le résultat est : %f\n", res);
	return 0;
}