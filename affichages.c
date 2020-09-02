#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"snake.h"

/*Affiche le chronomètre*/
void chronometre(int* seconde, int* minute) {
	char le_temps[10];
	*seconde+=1;

	if(*seconde==60) {
		*seconde=0;
		*minute+=1;
	}

	sprintf(le_temps,"%02d:%02d",*minute,*seconde);
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(CHRONO_X, COMPTEUR_Y-4-TailleSupPolice(2)+TailleInfPolice(2), TailleChaineEcran(le_temps, 2), TailleSupPolice(2)+TailleInfPolice(2));
	ChoisirCouleurDessin(CouleurParNom("white"));
	EcrireTexte(CHRONO_X,COMPTEUR_Y,le_temps,2);
	
}

/*Affiche le score du joueur*/
void le_score(int* score) {
	char score_a_afficher[20];
	sprintf(score_a_afficher,"Score : %09d", *score );
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(SCORE_X, COMPTEUR_Y-4-TailleSupPolice(2)+TailleInfPolice(2), TailleChaineEcran(score_a_afficher, 2), TailleSupPolice(2)+TailleInfPolice(2));
	ChoisirCouleurDessin(CouleurParNom("white"));
	EcrireTexte(SCORE_X,COMPTEUR_Y,score_a_afficher,2);

}

/*Affiche le nombre de pommes mangées*/
void pomme_mangee(int* nombre_de_pomme) {
	char affichage_nombre_de_pomme[20];
	sprintf(affichage_nombre_de_pomme,"Pomme x %05d", *nombre_de_pomme );
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(NOMBRE_POMME_X, COMPTEUR_Y-4-TailleSupPolice(2)+TailleInfPolice(2), TailleChaineEcran(affichage_nombre_de_pomme, 2), TailleSupPolice(2)+TailleInfPolice(2));
	ChoisirCouleurDessin(CouleurParNom("red"));
	EcrireTexte(NOMBRE_POMME_X,COMPTEUR_Y,affichage_nombre_de_pomme,2);
}
/*affiche le taux de multiplication du joueur + le temps restant avant que le multiplicateur repasse à 1 */
void affichage_temps_multiplicateur(double* temps_multiplicateur, int* multiplicateur, char temps_restant[20]) {
	if(*temps_multiplicateur > 0.0){
	sprintf(temps_restant,"Score x%d : %02.1lf", *multiplicateur, *temps_multiplicateur);
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(NOMBRE_POMME_X, COMPTEUR_Y+36-TailleSupPolice(2)+TailleInfPolice(2), TailleChaineEcran(temps_restant, 2)+TailleChaineEcran("0", 2), TailleSupPolice(2)+TailleInfPolice(2));
	ChoisirCouleurDessin(CouleurParNom("purple"));
	EcrireTexte(NOMBRE_POMME_X,COMPTEUR_Y+40,temps_restant,2);
	*temps_multiplicateur -= 0.1;
	} else {
		/*si temps_multiplication est <= 0, on cache ce qui était affiché
		+ remet le multiplicateur à 0 */
		*multiplicateur=1;
		*temps_multiplicateur=-1.0;
		ChoisirCouleurDessin(CouleurParNom("black"));
		RemplirRectangle(NOMBRE_POMME_X, COMPTEUR_Y+36-TailleSupPolice(2)+TailleInfPolice(2), TailleChaineEcran(temps_restant, 2)+TailleChaineEcran("0", 2), TailleSupPolice(2)+TailleInfPolice(2));		
	}
}

/*affiche les points acquis par le joueur lorsqu'il mange une pomme d'or*/
void affichage_pomme_dor( int* temps_pomme_dor,int* multiplicateur, char points_pomme_dor[20]) {
	if(*temps_pomme_dor > 0) {
 	sprintf(points_pomme_dor,"+ %d", (*multiplicateur)*50);
	ChoisirCouleurDessin(CouleurParNom("black"));
	RemplirRectangle(SCORE_X, COMPTEUR_Y+36-TailleSupPolice(2)+TailleInfPolice(2), TailleChaineEcran(points_pomme_dor, 2)+TailleChaineEcran("0", 2), TailleSupPolice(2)+TailleInfPolice(2));
	ChoisirCouleurDessin(CouleurParNom("gold"));
	EcrireTexte(SCORE_X,COMPTEUR_Y+40,points_pomme_dor,2);
	*temps_pomme_dor -= 1;
	} else { 
		/*après 5 sec, cache le message des points obtenu par la pomme d'or*/
		ChoisirCouleurDessin(CouleurParNom("black"));
		RemplirRectangle(SCORE_X, COMPTEUR_Y+36-TailleSupPolice(2)+TailleInfPolice(2), TailleChaineEcran(points_pomme_dor, 2) + TailleChaineEcran("0", 2), TailleSupPolice(2)+TailleInfPolice(2));
		*temps_pomme_dor=-1;	
	}
}


/*affiche l'effet obtenu par le joueur lorsqu'il mange une pomme du hazard*/
void affichage_effet_pomme_hazard( int* temps_affichage_effet, int* effet_pomme_hazard) {
	if(*temps_affichage_effet > 0) {
		ChoisirCouleurDessin(CouleurParNom("black"));
		RemplirRectangle(CHRONO_X, COMPTEUR_Y+36-TailleSupPolice(2)+TailleInfPolice(2), TailleChaineEcran("Vitesse x4 !", 2), TailleSupPolice(2)+TailleInfPolice(2));
		ChoisirCouleurDessin(CouleurParNom("silver"));
		if(*effet_pomme_hazard==0) {
			EcrireTexte(CHRONO_X,COMPTEUR_Y+40,"Vitesse x4 !",2);
		}
		if(*effet_pomme_hazard==1) {
			EcrireTexte(CHRONO_X,COMPTEUR_Y+40,"Score x2 !",2);
		}
		if(*effet_pomme_hazard==2) {
			EcrireTexte(CHRONO_X,COMPTEUR_Y+40,"Taille x2 !",2);
		}	
		if(*effet_pomme_hazard==4) {
			EcrireTexte(CHRONO_X,COMPTEUR_Y+40,"Rien ...",2);
		}			
	*temps_affichage_effet-=1;
 	} else {
 		/*si temps_affichage_effet <=0, on cache le message de l'effet obtenu*/
 		ChoisirCouleurDessin(CouleurParNom("black"));
		RemplirRectangle(CHRONO_X, COMPTEUR_Y+36-TailleSupPolice(2)+TailleInfPolice(2), TailleChaineEcran("Vitesse x4 !", 2), TailleSupPolice(2)+TailleInfPolice(2));
		*temps_affichage_effet=-1;		
 	}
 }
 
