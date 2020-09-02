    #include <stdio.h>
    #include <stdlib.h>
    #include <graph.h>
    #include "snake.h"
     
     
    void menu(void){
        /* il s agit des variables pour la position de la souris 
        pour pouvoir passer au plateau en cliquant*/
      	int x,y;  
      
        InitialiserGraphique();
       	/*creation de la fenetre du menu*/
        CreerFenetre(10,10,800,600);
      
      	/*image de fond*/
        ChargerImageFond("SNAKE_MENU.png");
      	
      	/*choisir d abord la couleur du texte et ensuite l ecrire*/
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(300,145,"JEU DU SERPENT",2);

        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(250,165,"Par Lucas Brutton et Gabriel Chavanon",1);

        ChoisirCouleurDessin(CouleurParNom("white"));
        EcrireTexte(145,250,"Les regles du jeu sont simples, tous le monde peut les comprendre:",1);
        EcrireTexte(155,280,"1)-Dirige le serpent avec les fleches de ton clavier",1);
        EcrireTexte(155,310,"2)-Essaie de manger le plus de fruits possible,",1);
        EcrireTexte(155,330,"sans te prendre les murs ou tes anneaux",1);
        EcrireTexte(155,350,"Attention ! Certaines pommes ont des effets differents",1);
        EcrireTexte(155,380,"3)-Si tu es vraiment un(e) boss, essaie d'obtenir le meilleur score,",1);
        EcrireTexte(155,400," le plus rapidement possible",1);

            ChoisirCouleurDessin(CouleurParNom("blue"));
        EcrireTexte(370,510,"JOUER",2);

            ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(320,570,"Bonne Chance",2);

		/*condition pour faire en sorte de changer de fenetre tant
        que tant que l on ne clique pas*/
        while(!SourisCliquee())
        {
            SourisPosition();
            if (_X!=x||_Y!=y)
            {

            }
        }
        FermerGraphique();
    }

