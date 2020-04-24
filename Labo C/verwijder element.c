#include <stdio.h>
#include <stdlib.h>

struct knoop {
	int getal;
	struct knoop *next;
};
typedef struct knoop knoop;

void verwijder_element(knoop **l, int g) {
	knoop *m,*h;
	if(*l){
		if((*l)->getal == g){
			m = *l;
			*l=(*l)->next;
			free(m);
		}
		else {
			h = *l;
			while(h->next && h->next->getal != g){
				h = h->next;
			}
			if(h->next){
				m = h->next;
				h->next = m->next;
				free(m);
			}
		}
	}
}

knoop * maak_lijst(){
	knoop *l = 0, *h;
	int g;
	scanf("%d",&g);
	while(g) {
		l = (knoop *) malloc(sizeof(knoop));
		h = l;
		h->getal = g;
		scanf("%d",&g);
		while(g!=0){
			h->next = malloc(sizeof(knoop));
			h = h->next;
			h->getal = g;
			scanf("%d",&g);
		}
		h->next = 0;
	}
	return l;
}

void vernietig_lijst(knoop **l){
	knoop *h;
	while(*l){
		h=*l;
		*l = h->next;
		free(h);
	}
}

int main() {
	knoop **l = maak_lijst();
	verwijder_element(*l, 9);
	print_lijst(l);
	return 0;
}
