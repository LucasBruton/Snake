#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"snake.h"

/*Met à 1 les cases qui représentent le serpent */
void initialisation_snake(int cases[60][40], int compteur[60][40], int* taille_serpent) {
	int j, valeur_compteur=*taille_serpent;
	for(j=POS_TETE_SERPENT_Y;j<POS_TETE_SERPENT_Y+10;j++) {
		cases[POS_TETE_SERPENT_X][j]=1;
		compteur[POS_TETE_SERPENT_X][j]=valeur_compteur;
		valeur_compteur-=1;

	}
}


/* Ces fonctions s'occupent : 
-du déplacement du serpent;
-de détecter si le serpent a mangé une pomme;
-de détecter si le joueur a perdu.
*/
void deplacement_haut(int* tete_serpent_x, int* tete_serpent_y, int cases[60][40], int compteur[60][40], int *taille_serpent, int *perdu, int* score, int* nombre_de_pomme, int* multiplacteur, double* temps_multiplicateur, int* temps_pomme_dor, int* effet_pomme_hazard, int* temps_acceleration, int* temps_affichage_effet) {
	/*mise à jour des coordonnées de la tête du serpent*/
	*tete_serpent_y -=1;
	/*détecte si la tête du serpent touche une partie de son corps*/
	if(cases[*tete_serpent_x][*tete_serpent_y]==1){
		*perdu=1;
	}
	/*détecte sii la tête du serpent touche un mur*/
	if(*tete_serpent_y==-1) {
		*perdu=1;
	}
	/*détecte si une pomme est mangée*/
	if(cases[*tete_serpent_x][*tete_serpent_y]==2) {
		nouvelle_pomme(cases, score, nombre_de_pomme, taille_serpent, compteur, multiplacteur);
	}
	/*détecte si une pomme d'or est mangée*/
	if(cases[*tete_serpent_x][*tete_serpent_y]==3) {
		*score+=50*(*multiplacteur);
		*taille_serpent+=2;
		*nombre_de_pomme+=1;
		*temps_pomme_dor=20;
	}
	/*détecte si une pomme multiplicateur x2 est mangée*/
	if(cases[*tete_serpent_x][*tete_serpent_y]==4) {
		*multiplacteur*=2;
		*taille_serpent+=2;
		*nombre_de_pomme+=1;
		if(*temps_multiplicateur==-1.0) {
			*temps_multiplicateur=30.0;
		}
	}
	/*détecte si une pomme du hazard est mangée*/
	if(cases[*tete_serpent_x][*tete_serpent_y]==5) {
		effet_pomme_du_hazard(effet_pomme_hazard, temps_acceleration, temps_affichage_effet, score, taille_serpent, multiplacteur, temps_multiplicateur);
		*nombre_de_pomme+=1;
	}
	/*création d'une nouvelle tête de serpent*/
	compteur[*tete_serpent_x][*tete_serpent_y]=*taille_serpent;
	cases[*tete_serpent_x][*tete_serpent_y]=1;
}

void deplacement_droite(int* tete_serpent_x, int* tete_serpent_y, int cases[60][40], int compteur[60][40], int *taille_serpent, int *perdu, int* score, int* nombre_de_pomme, int* multiplacteur, double* temps_multiplicateur, int* temps_pomme_dor, int* effet_pomme_hazard, int* temps_acceleration,int* temps_affichage_effet) {	
	*tete_serpent_x +=1;
	if(cases[*tete_serpent_x][*tete_serpent_y]==1){
		*perdu=1;
	}
	if(*tete_serpent_x==60) {
		*perdu=1;
	}
	if(cases[*tete_serpent_x][*tete_serpent_y]==2) {
		nouvelle_pomme(cases, score, nombre_de_pomme, taille_serpent, compteur, multiplacteur);
	}
	if(cases[*tete_serpent_x][*tete_serpent_y]==3) {
		*score+=50*(*multiplacteur);
		*taille_serpent+=2;
		*nombre_de_pomme+=1;
		*temps_pomme_dor=20;
	}	
	if(cases[*tete_serpent_x][*tete_serpent_y]==4) {
		*multiplacteur*=2;
		*nombre_de_pomme+=1;
		*taille_serpent+=2;
		if(*temps_multiplicateur==-1.0) {
			*temps_multiplicateur=30.0;
		}
	}	
	if(cases[*tete_serpent_x][*tete_serpent_y]==5) {
		effet_pomme_du_hazard(effet_pomme_hazard, temps_acceleration, temps_affichage_effet, score, taille_serpent, multiplacteur, temps_multiplicateur);
		*nombre_de_pomme+=1;
	}
	compteur[*tete_serpent_x][*tete_serpent_y]=*taille_serpent;
	cases[*tete_serpent_x][*tete_serpent_y]=1;
}

void deplacement_bas(int* tete_serpent_x, int* tete_serpent_y, int cases[60][40], int compteur[60][40], int *taille_serpent, int *perdu, int* score, int* nombre_de_pomme, int* multiplacteur, double* temps_multiplicateur, int* temps_pomme_dor, int* effet_pomme_hazard, int* temps_acceleration, int* temps_affichage_effet) {
	*tete_serpent_y +=1;
	if(cases[*tete_serpent_x][*tete_serpent_y]==1){
		*perdu=1;
	}
	if(*tete_serpent_y==40) {
		*perdu=1;
	}
	if(cases[*tete_serpent_x][*tete_serpent_y]==2) {
		nouvelle_pomme(cases, score, nombre_de_pomme, taille_serpent, compteur, multiplacteur);
	}
	if(cases[*tete_serpent_x][*tete_serpent_y]==3) {
		*score+=50*(*multiplacteur);
		*nombre_de_pomme+=1;
		*taille_serpent+=2;
		*temps_pomme_dor=20;
	}
	if(cases[*tete_serpent_x][*tete_serpent_y]==4) {
		*multiplacteur*=2;
		*nombre_de_pomme+=1;
		*taille_serpent+=2;
		if(*temps_multiplicateur==-1.0) {
			*temps_multiplicateur=30.0;
		}		
	}
	if(cases[*tete_serpent_x][*tete_serpent_y]==5) {
		effet_pomme_du_hazard(effet_pomme_hazard, temps_acceleration, temps_affichage_effet, score, taille_serpent, multiplacteur, temps_multiplicateur);
		*nombre_de_pomme+=1;
	}		
	compteur[*tete_serpent_x][*tete_serpent_y]=*taille_serpent;
	cases[*tete_serpent_x][*tete_serpent_y]=1;
	
}

void deplacement_gauche(int* tete_serpent_x, int* tete_serpent_y, int cases[60][40], int compteur[60][40], int *taille_serpent, int *perdu, int* score, int* nombre_de_pomme, int* multiplacteur, double* temps_multiplicateur, int* temps_pomme_dor, int* effet_pomme_hazard, int* temps_acceleration, int* temps_affichage_effet) {
	*tete_serpent_x -=1;
	if(cases[*tete_serpent_x][*tete_serpent_y]==1){
		*perdu=1;
	}
	if(*tete_serpent_x==-1) {
		*perdu=1;
	}
	if(cases[*tete_serpent_x][*tete_serpent_y]==2) {
		nouvelle_pomme(cases, score, nombre_de_pomme, taille_serpent, compteur, multiplacteur);
	}
	if(cases[*tete_serpent_x][*tete_serpent_y]==3) {
		*score+=50*(*multiplacteur);
		*taille_serpent+=2;
		*nombre_de_pomme+=1;
		*temps_pomme_dor=20;
	}
	if(cases[*tete_serpent_x][*tete_serpent_y]==4) {
		*multiplacteur*=2;
		*taille_serpent+=2;
		*nombre_de_pomme+=1;
		if(*temps_multiplicateur==-1.0) {
			*temps_multiplicateur=30.0;
		}
	}
	if(cases[*tete_serpent_x][*tete_serpent_y]==5) {
		effet_pomme_du_hazard(effet_pomme_hazard, temps_acceleration, temps_affichage_effet, score, taille_serpent, multiplacteur, temps_multiplicateur);
		*nombre_de_pomme+=1;
	}		
	compteur[*tete_serpent_x][*tete_serpent_y]=*taille_serpent;
	cases[*tete_serpent_x][*tete_serpent_y]=1;	

}