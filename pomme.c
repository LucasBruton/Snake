#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"snake.h"

/*Création de 5 pommes*/
void initialisation_pomme(int cases[60][40]) {
	int i, pomme_x, pomme_y, test=0;
	for(i=0;i<5;i++) {
		/*génère des coordonnées aléatoires pour la pomme 
		+ test si la case est déja occupé par un bout du serpent ou une pomme*/
		while(test!=1) {
		pomme_x=rand()%60;
		pomme_y=rand()%40;
		if(cases[pomme_x][pomme_y]==1 || cases[pomme_x][pomme_y]==2) {
			test=0;
		} else {
			cases[pomme_x][pomme_y]=2;
			test=1;
		}
		}
	test=0;
	}
}


/*Création d'une nouvelle pomme classique + augmente le score, le nombre de pommes mangées et la taille du serpent*/
void nouvelle_pomme(int cases[60][40], int* score, int* nombre_de_pomme, int *taille_serpent, int compteur[60][40], int* multiplacteur) {
	int test=0, pomme_x, pomme_y;
	*score+=5*(*multiplacteur);
	*nombre_de_pomme+=1;
	*taille_serpent+=2;
	/*génère des coordonnées aléatoires pour la pomme 
	+ test si la case est déja occupé par un bout du serpent ou une pomme*/	
	while(test!=1) {
		pomme_x=rand()%60;
		pomme_y=rand()%40;
		if(compteur[pomme_x][pomme_y]>0 || cases[pomme_x][pomme_y]==2 || cases[pomme_x][pomme_y]==3 || cases[pomme_x][pomme_y]==4 || cases[pomme_x][pomme_y]==5) { 
			test=0;
		} else {
			cases[pomme_x][pomme_y]=2;
			test=1;
		}

	}
}

/*Création d'une pomme qui donne 50 points*/
void pomme_dor(int cases[60][40], int compteur[60][40]) {
	int test=0, pomme_x, pomme_y;
	/*génère des coordonnées aléatoires pour la pomme 
	+ test si la case est déja occupé par un bout du serpent ou une pomme*/	
	while(test!=1) {
		pomme_x=rand()%60;
		pomme_y=rand()%40;
		if(compteur[pomme_x][pomme_y]>0 || cases[pomme_x][pomme_y]==2 || cases[pomme_x][pomme_y]==3 || cases[pomme_x][pomme_y]==4 || cases[pomme_x][pomme_y]==5) {
			test=0;
		} else {
			cases[pomme_x][pomme_y]=3;
			test=1;
		}

	}
}

/*Création d'une pomme qui double les gains de points*/
void pomme_multiplicateur_x2(int cases[60][40],int compteur[60][40]) {
	int test=0, pomme_x, pomme_y;
	
	/*génère des coordonnées aléatoires pour la pomme 
	+ test si la case est déja occupé par un bout du serpent ou une pomme*/	
	while(test!=1) {
		pomme_x=rand()%60;
		pomme_y=rand()%40;
		if(compteur[pomme_x][pomme_y]>0 || cases[pomme_x][pomme_y]==2 || cases[pomme_x][pomme_y]==3 || cases[pomme_x][pomme_y]==4 || cases[pomme_x][pomme_y]==5) { 
			test=0;
		} else {
			cases[pomme_x][pomme_y]=4;
			test=1;
		}

	}
}
/*Création d'une pomme du hazard*/
void pomme_du_hazard(int cases[60][40],int compteur[60][40]) {
	int test=0, pomme_x, pomme_y;
	/*génère des coordonnées aléatoires pour la pomme 
	+ test si la case est déja occupé par un bout du serpent ou une pomme*/	
	while(test!=1) {
		pomme_x=rand()%60;
		pomme_y=rand()%40;
		if(compteur[pomme_x][pomme_y]>0 || cases[pomme_x][pomme_y]==2 || cases[pomme_x][pomme_y]==3 || cases[pomme_x][pomme_y]==4 || cases[pomme_x][pomme_y]==5) { 
			test=0;
		} else {
			cases[pomme_x][pomme_y]=5;
			test=1;
		}

	}
}

/*lorsqu'une pomme du hazard est mangée, un effet choisi aléatatoirment parmi 5 se délenche*/
void effet_pomme_du_hazard(int* effet_pomme_hazard, int* temps_acceleration, int* temps_affichage_effet, int* score, int* taille_serpent, int* multiplicateur, double* temps_multiplicateur) {
	*effet_pomme_hazard=rand()%5;
	/*effet = quadruplé la vitesse du jeu entre 2/4 et 28/4 sec (puisque le jeu va 4 fois plus vite)*/
	if(*effet_pomme_hazard==0) {
		*temps_acceleration=(rand()%15 + 1) * 2;
		*temps_affichage_effet=*temps_acceleration*10;;
	}
	/*effet = double le score du joueur*/
	if(*effet_pomme_hazard==1) {
		*score*=2;
		*temps_affichage_effet=50;
	}
	/*effet = double la taille du serpent*/
	if(*effet_pomme_hazard==2) {
		*taille_serpent*=2;
		*temps_affichage_effet=50;
	}
	/*effet= futurs gains du joueur sont multipliés par 10 et on rajoute 10 sec à temps_multiplicateur*/
	if(*effet_pomme_hazard==3) {
		*multiplicateur*=10;
		*temps_multiplicateur+=10;
	}
	/*effet = rien*/
	if(*effet_pomme_hazard==4) {
		*temps_affichage_effet=50;
	}
}

/*Toutes les 4 secondes, une pomme spéciale est créée*/
void pomme_speciale(int *s, int cases[60][40], int compteur[60][40]) {
	int pomme_hazard;
	*s+=1;
		if(*s%4==0) {
			pomme_hazard=rand()%3;
			if(pomme_hazard==0) {
				pomme_dor(cases, compteur);
			}
			if(pomme_hazard==1) {
				pomme_multiplicateur_x2(cases, compteur);
			}
			if(pomme_hazard==2) {
				pomme_du_hazard(cases, compteur);
			}
			
		}

	 }

