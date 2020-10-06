
////////////////////////
/*   STEVE TROUDART   */
////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct maillon{
	struct maillon *next;
    struct maillon *prev;
    int val;
} maillon;



void afficher_liste(maillon *);
void effacer_liste(maillon *);
maillon *creer_liste(int);
maillon *trier_liste(maillon *);

//Fonction Main
int main(int argc, char* argv[]){
	maillon *liste =NULL;
	int nbelem;
  
	if(argc < 2)
	{
		printf("usage: %s nbelem", argv[0]);
		return -1;}
  
	nbelem = atoi(argv[1]);
	liste = creer_liste(nbelem);
	afficher_liste(liste);
	liste = trier_liste(liste);
	afficher_liste(liste);
	effacer_liste(liste);
	liste = NULL;
	
	return 0;
}

void afficher_liste(maillon *liste){
	printf("La liste :\n");

	while(liste != NULL){
		printf("Valeur : %d \n", liste->val);
		liste = liste->next;}
}

maillon *creer_liste(int nbelem){


     int i, nombre;
     maillon *init, *temp, *nouv;

	 init = (maillon*) malloc(sizeof(maillon));
     init->val = rand();
	 temp = init;
 
	 for(i = 1, nombre = 1; i<nbelem; i++, nombre++){
		 nouv = (maillon*) malloc(sizeof(maillon)); 
         nouv->val = rand();

         nouv->prev = temp; temp->next = nouv; temp = nouv;}

     temp->next = NULL;

	 printf("\n%d crees\n", nombre);
	 
	 return(init);
}


void effacer_liste(maillon *liste){
	int nombre;
	maillon *temp;

	printf("Effacement de la liste...");

	for(nombre = 0; liste != NULL; nombre++)
	{
		temp = liste->next; free(liste); liste = temp;
	}
	
	printf("\n%d effaces\n", nombre);
}





maillon *trier_liste(maillon *liste){
	int permut, val;
	maillon *pre;
	maillon *act;
	maillon *sui;

	printf("Tri en cours...\n");

	do
	{
		permut=0;

		pre = NULL;
		act = liste;
		sui = act->next;

		while(act->next!=NULL)
		{
			if(act->val > sui->val)
			{
				if(pre!=NULL)
				{
					val = pre->next->val; pre->next->val = sui->val; sui->val = val;
				}
				else
				{
					val = act->val; act->val=sui->val; sui->val = val;
				}
			
				permut--;
			}

			pre=act; act=sui; sui=act->next;
		}

	}while(permut != 0);

	printf("Tri effectue!!!\n");

	return (liste);
}
