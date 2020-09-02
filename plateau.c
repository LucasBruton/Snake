#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"snake.h"

/* Met toutes les cases du jeu à O*/
void initialisation_plateau(int cases[60][40],int cases_precedentes[60][40]) {
	int i,j;

	for(j=0;j<40;j++) {
		for(i=0;i<60;i++){
			cases[i][j]=0;
			cases_precedentes[i][j]=-1;
		}
	}

}

/*Création du premier plateau + du serpent + des pommes */
void premier_plateau(int cases[60][40] , int cases_precedentes[60][40]) {
	int j, i, x, y; 
	/*génère un jeu de 60 x 40 cases aux coordonnées (PLATEAU_X, PLATEAU_Y)*/
	for(y=PLATEAU_Y,j=0;y<40*CASE;y+=CASE,j++) {
		for(x=PLATEAU_X,i=0;x<(60*CASE)+PLATEAU_X;x+=CASE,i++) {
			/* les pommes = 2 représentent les pommes normales*/
				if(cases[i][j]==2) {
					ChoisirCouleurDessin(CouleurParNom("red"));
					RemplirRectangle(x,y,CASE,CASE);
					cases_precedentes[i][j]=2;
				}
				/*les cases = 1 représentent le serpent*/
				/* le compteur d'une case indique le nombre de fois qu'une case va représenter le serpent*/
				if(cases[i][j]==1) {
					ChoisirCouleurDessin(CouleurParNom("green"));
					RemplirRectangle(x,y,CASE,CASE);
					cases_precedentes[i][j]=1;					
				}
				/*les cases = 0 représentent le terrain*/
				if(cases[i][j]==0) {
					ChoisirCouleurDessin(CouleurParNom("blue"));
					RemplirRectangle(x,y,CASE,CASE);
					cases_precedentes[i][j]=0;
				}
			}
		}
	}


void plateau(int cases[60][40], int compteur[60][40], int cases_precedentes[60][40], int* taille_serpent) {
	int i,j,x,y;
	for(y=PLATEAU_Y,j=0;y<40*CASE;y+=CASE,j++) {
		for(x=PLATEAU_X,i=0;x<(60*CASE)+PLATEAU_X;x+=CASE,i++) {
			/*test si la case précédente est différente de la nouvelle qui va être générer*/
			/*on modifie donc que les cases qui ont changés de valeurs*/

				/*les cases = 2 représentent les pommes normales*/
				if(cases[i][j]==2 && cases[i][j]!=cases_precedentes[i][j]) {
					ChoisirCouleurDessin(CouleurParNom("red"));
					RemplirRectangle(x,y,CASE,CASE);
					cases_precedentes[i][j]=2;
				}
				/*les cases = 3 représentent les pommes d'or*/
				if(cases[i][j]==3 && cases[i][j]!=cases_precedentes[i][j]) {
					ChoisirCouleurDessin(CouleurParNom("gold"));
					RemplirRectangle(x,y,CASE,CASE);
					cases_precedentes[i][j]=3;
				}
				/*les cases = 4 représentent les pommes qui multiplient les prochains gains par 2*/
				if(cases[i][j]==4 && cases[i][j]!=cases_precedentes[i][j]) {
					ChoisirCouleurDessin(CouleurParNom("purple"));
					RemplirRectangle(x,y,CASE,CASE);
					cases_precedentes[i][j]=4;
				}
				/*les cases = 5 représentent les pommes du hazard*/
			if(cases[i][j]==5 && cases[i][j]!=cases_precedentes[i][j]) {
					ChoisirCouleurDessin(CouleurParNom("silver"));
					RemplirRectangle(x,y,CASE,CASE);
					cases_precedentes[i][j]=5;
				}								
				/*les cases = 1 représentent le serpent*/
				/* le compteur d'une case indique  le nombre de fois qu'une case va représenter le serpent*/

				if(cases[i][j]==1&&compteur[i][j]==*taille_serpent) {
					ChoisirCouleurDessin(CouleurParNom("green"));
					RemplirRectangle(x,y,CASE,CASE);
					compteur[i][j]-=1;
					cases_precedentes[i][j]=1;
					
				}
				compteur[i][j]-=1;
				/*transforme la queue du serpent (= à la case du serpent dont le compteur vaut 0) en terrain*/
				if(compteur[i][j]==0&&cases[i][j]==1) {	
					ChoisirCouleurDessin(CouleurParNom("blue"));
					RemplirRectangle(x,y,CASE,CASE);
					cases[i][j]=0;
					cases_precedentes[i][j]=0;
				}
			}

		}
	}



	

