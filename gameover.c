#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "snake.h"



void gameover(int *s, int *min, int* nombre_de_pomme, int *score){
  
  	/* il s agit des variables pour la position de la souris 
    pour pouvoir passer au plateau en cliquant*/
  	int x,y; 
    InitialiserGraphique();
  
 	/*creation de la fenetre de fin de partie*/
    CreerFenetre(10,10,850,600);
  
  	/*image de fond*/
    ChargerImageFond("SNAKE_FIN.png");
    ChoisirCouleurDessin(CouleurParNom("red"));
    EcrireTexte(310,145,"FIN DU JEU",2);

    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(190,250,"Fun Facts de ta partie :",2);
	
  	/*Compteurs des pommes mangees par le joueur lors de la partie*/
    char pommes_mangee_fin[50];
    sprintf(pommes_mangee_fin,"1)-Tu as mange : %d pommes", *nombre_de_pomme);
    EcrireTexte(245,280,pommes_mangee_fin,1);

	/*Temps de la partie du joueur*/
    char temps_fin[60];
    sprintf(temps_fin,"2)-Ton temps est de : %02d minutes et de %02d secondes", *min,*s );
    EcrireTexte(155,310,temps_fin,1);

	/*Score du joueur*/
    char score_fin[50];
    sprintf(score_fin,"-Ton score est donc de : %d ", *score );
    EcrireTexte(165,370,score_fin,2);

    ChoisirCouleurDessin(CouleurParNom("cyan"));
    EcrireTexte(245,420,"MERCI D AVOIR JOUE ",2);

    while(!SourisCliquee());
    FermerGraphique();
}

