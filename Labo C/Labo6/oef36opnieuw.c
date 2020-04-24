#include<stdio.h>
#include<stdlib.h>

typedef struct knoop knoop;
struct knoop {
	int getal;
	knoop * next;
};

void voeg_vooraan_toe(int x, knoop ** pl){
	knoop * even_bijhouden = *pl;
	*pl = (knoop*) malloc(sizeof(knoop));
	(*pl)->getal = x;
	(*pl)->next = even_bijhouden;
}

void print_lijst(const knoop *l) {
	while( l!=0 ){
		printf("%d ",l->getal);
		l = l->next;
	}
	printf("X\n");
}

void print_lijst_rec(const knoop * l) {
	if(l!=0){
		printf("%d ",l->getal);
		print_lijst_rec(l->next);
	}
	else {
		printf("X\n");
	}
}

void vernietig_lijst(knoop **pl){
	knoop *h;
	while(*pl!=0){
		h = *pl;
		*pl = h->next;
		printf("Ik geef knoop %d vrij\n",h->getal);
		free(h);
	}
}

int main() {
	voeg_vooraan_toe(7,&l);
	voer_vooraan_toe(3,&l);
	print_lijst(l);
	print_lijst_rec(l);
	vernietig_lijst(&l);
	return 0;
}
