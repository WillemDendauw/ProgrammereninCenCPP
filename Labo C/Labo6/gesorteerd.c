#include <stdio.h>
#include <stdlib.h>

struct knoop {
	int getal;
	struct knoop *next;
};
typedef struct knoop knoop;

void voeg_getal_toe(knoop **l, int g){
	knoop *h, *nieuw;
	nieuw = malloc(sizeof(knoop));
	nieuw->getal = g;
	if(*l==0 || (*l)->getal>=g){
		nieuw->next = *l;
		*l = nieuw;
	}
	else {
		h = *l;
		while(h->next && h->next->getal < g){
			h = h->next;
		}
		nieuw->next = h->next;
		h->next = nieuw;
	}
}

void print_lijst(const knoop*l) {
	while(l){
		printf("%d\n",l->getal);
		l = l->next;
	}
}

knoop * maak_gesorteerde_lijst(){
	knoop *l = 0;
	int g;
	scanf("%d",&g);
	while(g){
		voer_getal_toe(&l,g);
		scanf("%d",&g);
	}
	return l;
}

int main() {
	knoop *l = maak_gesorteerde_lijst();
	print_lijst(l);
	return 0;
}
