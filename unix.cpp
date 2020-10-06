//TRAVAIL UNIX : Benoit Le Guern Prépa 2


#include <stdio.h>
#include <stdlib.h>


typedef struct maillon
{
	struct maillon *next;
    struct maillon *prev;
    int val;
} maillon;



void afficher_liste(maillon *);
void effacer_liste(maillon *);
maillon *creer_liste(int);
maillon *trier_liste(maillon *);




int main(int argc, char* argv[])
{
	maillon *liste =NULL;
	int nbelem;
  
	if(argc < 2)
	{
		printf("usage: %s nbelem", argv[0]);
		return -1;
	}
  
	nbelem = atoi(argv[1]);
	liste = creer_liste(nbelem);
	afficher_liste(liste);
	liste = trier_liste(liste);
	afficher_liste(liste);
	effacer_liste(liste);
	liste = NULL;
	
	return 0;
}

void afficher_liste(maillon *liste)
{
	int num = 0;

	printf("Affichage de la liste :\n");

	while(liste != NULL)
	{
		printf("Maillon %d : Valeur : %d \n", num+1, liste->val);
		liste = liste->next;

		num++;
	}
}

maillon *creer_liste(int nbelem)
{
     int i, num;
     maillon *init, *temp, *nouvelle;

	 printf("Creation de la liste (un | = un maillon) : ");

	 init = (maillon*) malloc(sizeof(maillon));
     init->val = rand();
	 temp = init;

	 printf("|");
 
	 for(i = 0, num = 1; i<(nbelem-1); i++, num++)
	 {
		 nouvelle = (maillon*) malloc(sizeof(maillon)); 
         nouvelle->val = rand();

         nouvelle->prev = temp;
         temp->next = nouvelle;
		 temp = nouvelle;

		 printf("|");
     }

     temp->next = NULL;

	 printf("\n%d maillon(s) cree(s)\n\n", num);
	 
	 return(init);
}


void effacer_liste(maillon *liste)
{
	int num;
	maillon *temp;

	printf("\nEffacement de la liste (un | = un maillon) : ");

	for(num = 0; liste != NULL; num++)
	{
		temp = liste->next;
		free(liste);
		liste = temp;

		printf("|");
	}
	
	printf("\n%d maillon(s) efface(s) : FIN\n", num);
}





maillon *trier_liste(maillon *liste)
{
	int changement, valeur;
	maillon *precedante, *actuelle, *suivante;

	printf("\nTri des maillons en cours...\n");

	do
	{
		changement=0;

		precedante = NULL;
		actuelle = liste;
		suivante = actuelle->next;

		while(actuelle->next!=NULL)
		{
			if(actuelle->val > suivante->val)
			{
				if(precedante!=NULL)
				{
					valeur = precedante->next->val;
					precedante->next->val = suivante->val;
					suivante->val = valeur;
				}
				else
				{
					valeur = actuelle->val;
					actuelle->val=suivante->val;
					suivante->val = valeur;
				}
			
				changement--;
			}

			precedante=actuelle;
			actuelle=suivante;
			suivante=actuelle->next;
		}

	}while(changement != 0);

	printf("Tri effectue\n\n");

	return (liste);
}
