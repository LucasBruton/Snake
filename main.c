#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include"snake.h"

void clavier(int*, int*, int*, int*);

int main(void) {
	/*fait appelle à la fonction menu*/
	menu();

	srand(time(NULL));

	int sortie=0,perdu=0,s=0,min=0,pause=1, cases[60][40], cases_precedentes[60][40],compteur[60][40], taille_serpent = 10, deplacement=1, nombre_de_deplacement=0,
	score=0, multiplicateur=1, nombre_de_pomme=0, tete_serpent_x=POS_TETE_SERPENT_X, tete_serpent_y=POS_TETE_SERPENT_Y, s_pomme_speciale=0, 
	temps_acceleration=0, temps_pomme_dor=-2, effet_pomme_hazard=-1, temps_affichage_effet=0;
	unsigned long cycle=Microsecondes()+CYCLE, mise_a_jour=Microsecondes()+MISE_A_JOUR;
	double temps_multiplicateur=-1.0;
	char temps_multiplicateur_restant[20], points_pomme_dor[20];

	/*initialise le jeu*/
	InitialiserGraphique();
	CreerFenetre(10,10,770,500);
	EffacerEcran(CouleurParNom("black"));
	initialisation_plateau(cases, cases_precedentes);
	initialisation_snake(cases,compteur,&taille_serpent);
	initialisation_pomme(cases);
	premier_plateau(cases, cases_precedentes);

	/*Boucle principale du jeu*/
	while(sortie==0 && perdu==0) {
		if(ToucheEnAttente()) {
			clavier(&sortie, &pause, &deplacement, &nombre_de_deplacement);
		}
		/*Lorsque Microsecondes() est > à mise_a_jour, 
		on fait une mise à jour des coordonées du serpent, des différents éléments à afficher et des pommes
		+ détecte si le joueur a perdu*/ 
		if(Microsecondes()>mise_a_jour&&(pause==1)) {
			/*si la variable temps_acceleration est > 0, le jeu va 4 fois plus vite*/
			if(temps_acceleration >0 ) {
				mise_a_jour=Microsecondes()+MISE_A_JOUR/4;
			} else {
				mise_a_jour=Microsecondes()+MISE_A_JOUR;
			}
			/*réinitialise la valeur de la variable nombre_de_deplacement*/
			nombre_de_deplacement=0;
			/*la variable déplacement s'occupe de la direction du snake*/
			if(deplacement==1) {
				deplacement_haut(&tete_serpent_x, &tete_serpent_y, cases, compteur, &taille_serpent, &perdu, &score, &nombre_de_pomme, &multiplicateur, &temps_multiplicateur, &temps_pomme_dor, &effet_pomme_hazard, &temps_acceleration, &temps_affichage_effet);
			}
			if(deplacement==2) {
				deplacement_droite(&tete_serpent_x, &tete_serpent_y, cases, compteur, &taille_serpent, &perdu, &score, &nombre_de_pomme, &multiplicateur, &temps_multiplicateur, &temps_pomme_dor, &effet_pomme_hazard, &temps_acceleration, &temps_affichage_effet);
			}
			if(deplacement==3) {
				deplacement_bas(&tete_serpent_x, &tete_serpent_y, cases, compteur, &taille_serpent, &perdu, &score, &nombre_de_pomme, &multiplicateur, &temps_multiplicateur, &temps_pomme_dor, &effet_pomme_hazard, &temps_acceleration, &temps_affichage_effet);
			}
			if(deplacement==4) {
				deplacement_gauche(&tete_serpent_x, &tete_serpent_y, cases, compteur, &taille_serpent, &perdu, &score, &nombre_de_pomme, &multiplicateur, &temps_multiplicateur, &temps_pomme_dor, &effet_pomme_hazard, &temps_acceleration, &temps_affichage_effet);
			}
			/*tant que le joueur n'a pas perdu, on fait une mise à jour des différents affichages tous les 0.1 sec*/
			if(perdu==0) {
				plateau(cases,compteur, cases_precedentes, &taille_serpent);
				le_score(&score);
				pomme_mangee(&nombre_de_pomme);	
				/*si la variable temps_multiplicateur est >-1.0, on fait une mise à jour du multiplicateur*/
				if(temps_multiplicateur != -1.0) {
					affichage_temps_multiplicateur(&temps_multiplicateur, &multiplicateur, temps_multiplicateur_restant);
				}
				/*si une pomme d'or est mangé, indique le gain de la pomme pendant 5 sec*/
				if(temps_pomme_dor!=-1) {
					affichage_pomme_dor(&temps_pomme_dor, &multiplicateur, points_pomme_dor);
				}
				/*si une pomme du hazard est mangé, l'effet obtenu est affiché (excepté l'effet qui multiplie le multiplicateur par 10 et 
				qui ajoute 10 sec à la variable temps_muliplicateur puisque c'est la focntion affichage_temps_multiplicateur qui s'enoccupe*/
				if(temps_affichage_effet!=-1) {
					affichage_effet_pomme_hazard(&temps_affichage_effet, &effet_pomme_hazard);
				}

		}
	}
		/*fait la mise à jour du chrono toutes les secondes + création d'une pomme spéciale toutes les 4 secones*/
		if(Microsecondes()>cycle&&(pause==1)) {
			if(temps_acceleration > 0 ) {
				cycle=Microsecondes()+CYCLE/4;
				temps_acceleration-=1;
			} else {
				cycle=Microsecondes()+CYCLE;
			}
			chronometre(&s, &min);
			pomme_speciale(&s_pomme_speciale, cases, compteur);

		}	
	}
	FermerGraphique();
	/*active la fonction gameover si le joueur a perdu*/
	if(perdu==1) {
		gameover(&s, &min, &nombre_de_pomme, &score);
	} 
	
	return 0;	
}


/*s'occupe des touches du jeu*/
void clavier(int *sortie, int *pause, int *direction, int *nombre_de_deplacement) {
	int t=Touche();
	if(t==XK_Escape) {
		*sortie=1;
	} 
	if(t==XK_space) {
		*pause*=-1;
	}
	/*avant de modifer la direction du snake, on vérifie que le joueur n'essaye pas de revenir sur lui même*/
	/*la variable nombre_de_déplacement fait en sorte que le serpent, avant d'avoir réaliser un déplacement,  
	ne puisse revenir sur lui même lorsque le joueur appuie sur deux flèches directionnelles avec un interval inférieur à MISE_A_JOUR*/
	if(t==XK_Up && *direction!=3 && *nombre_de_deplacement==0) {
		*direction=1;
		*nombre_de_deplacement=1;
	}
	if(t==XK_Right && *direction!=4 && *nombre_de_deplacement==0) {
		*direction=2;
		*nombre_de_deplacement=1;
	}
	if(t==XK_Down && *direction!=1 && *nombre_de_deplacement==0) {
		*direction=3;
		*nombre_de_deplacement=1;
	}
	if(t==XK_Left && *direction!=2 && *nombre_de_deplacement==0) {
		*direction=4;
		*nombre_de_deplacement=1;
	}

}
