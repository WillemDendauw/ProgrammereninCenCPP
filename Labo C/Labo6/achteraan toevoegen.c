#include <stdio.h>
#include <stdlib.h>

struct knoop {
	int getal;
	struct knoop *next;
};
typedef struct knoop knoop;

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

void print_lijst(const knoop*l) {
	while(l){
		printf("%d\n",l->getal);
		l = l->next;
	}
}

int main() {
	knoop *l = maak_lijst();
	print_lijst(l);
	return 0;
}
