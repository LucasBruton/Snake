#ifndef SNAKE_H
#define SNAKE_H

/*valeur de chaque case dessiné*/
#define CASE 10
/*représente 1 sec*/
#define CYCLE 1000000L
/*représente 0.1 sec*/
#define MISE_A_JOUR 100000L
/*premières coordonnées de la tête du serpent*/
#define POS_TETE_SERPENT_X 30
#define POS_TETE_SERPENT_Y 15
/*coordonnées de la première case du plateau*/
#define PLATEAU_X 80
#define PLATEAU_Y 0
/*coordonnée en x du chronomètre*/
#define CHRONO_X 50
/*coordonnée en x du compteur de pomme*/
#define NOMBRE_POMME_X 225
/*coordonnée en x du score*/
#define SCORE_X 500
/*coordonnée en y des compteurs*/
#define COMPTEUR_Y 446
/*Position de la souris dans la fenêtre*/
#define tx 300
#define ty 300


void menu(void);
void gameover(int*, int*, int* , int*);

void premier_plateau(int cases[60][40], int cases_precedentes[60][40]);
void plateau(int cases [60][40],int compteur[60][40], int cases_precedentes[60][40], int*);
void chronometre(int*,int*);
void initialisation_snake(int cases[60][40], int compteur[60][40], int*);
void initialisation_plateau(int cases[60][40], int cases_precedentes[60][40]);
void deplacement_haut(int*, int*,int cases[60][40], int compteur[60][40], int*, int*, int*, int*, int*, double*, int*, int*, int*, int*);
void deplacement_bas(int*, int*,int cases[60][40], int compteur[60][40], int*, int*, int*, int*, int*, double*, int*, int*, int*, int*);
void deplacement_droite(int*, int*,int cases[60][40], int compteur[60][40], int*, int*, int*, int*, int*, double*, int*, int*, int*, int*);
void deplacement_gauche(int*, int*,int cases[60][40], int compteur[60][40], int*, int*, int*, int*, int*, double*, int*, int*, int*, int*);
void initialisation_pomme(int cases[60][40]);
void nouvelle_pomme(int cases[60][40], int*, int*, int*, int compteur[60][40], int*);
void le_score(int*);
void pomme_mangee(int*);
void pomme_speciale(int*, int cases[60][40], int compteur[60][40]);
void effet_pomme_du_hazard(int*, int*, int*, int*, int*, int*, double*);
void affichage_temps_multiplicateur(double*, int*, char temps_restant[20]);
void affichage_pomme_dor( int* temps_pomme_dor,int* multiplicateur, char points_pomme_dor[20]);
void affichage_effet_pomme_hazard( int*, int*);


#endif 