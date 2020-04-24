#include<stdio.h>
#include<stdlib.h>

typedef struct knoop knoop;
struct knoop{
	int d;
	knoop * opv;
};

void voeg_vooraan_toe(int getal, knoop** l){
	knoop *h = *l;
	(*l)= (knoop*)malloc(sizeof(knoop));
	(*l)->d = getal;
	(*l)->opv = h;
}

void print_lijst(const knoop*l) {
	while(l){
		printf("%d",l->d);
		l = l->opv;
	}
}

knoop* maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens) {
	knoop* k = 0;
	int i;
	int getal = bovengrens;
	for(i=0;i<aantal;i++) {
		getal = getal - rand()%3; /*rand()%3 creëert een getal 0 of 1 of 2;*/
		voeg_vooraan_toe(getal, &k);
	}
}

void verwijder_dubbels(knoop* l) {
	while(l != 0) {
		while(l->opv !=0 && l->opv->d == l->d) {
			knoop * magweg = l->opv;
			l->opv = magweg->opv;
			free(magweg);
		}
		l = l->opv;
	}
}

void vernietig_lijst(knoop **pl){
	knoop *h;
	while(*pl!=0){
		h = *pl;
		*pl = h->opv;
		printf("Ik geef knoop %d vrij\n",h->d);
		free(h);
	}
}

int main() {
	srand(time(NULL));
	knoop * l = maak_gesorteerde_lijst_automatisch(10,100);
	print_lijst(l);
	printf("\nnu worden dubbels verwijderd: \n");
	verwijder_dubbels(l);
	printf("\nna verwijderen van dubbels: \n\n");
	print_lijst(l);
	vernietig_lijst(&l);
	return 0;
}
