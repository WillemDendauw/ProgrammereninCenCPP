#include <stdio.h>
#include <stdlib.h>

struct knoop {
	int getal;
	struct knoop *next;
};
typedef struct knoop knoop;

void print_lijst(const knoop*l) {
	while(l){
		printf("%d\n",l->getal);
		l = l->next;
	}
}

knoop * maak_omgekeerde_lijst(){
	knoop *l = 0,*h;
	int g;
	scanf("%d",&g);
	while(g!=0){
		h= malloc(sizeof(knoop));
		h->next = l;
		l = h;
		scanf("%d",&g);
	}
	return l;
}

int main() {
	knoop *l = maak_omgekeerde_lijst();
	print_lijst(l);
	return 0;
}
