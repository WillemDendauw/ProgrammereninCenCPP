#include<stdio.h>

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

/*recursief*/
void print_lijstr(const knoop * l) {
	if(l){
		printf("%d",l->d);
		print_lijstr(l->opv);
	}
}

int main() {
	knoop * l= 0;
	voeg_vooraan_toe(7,&l);
	voeg_vooraan_toe(3,&l);
	print_lijst(l);
	return 0;
}

//als je eerste knoop mogelijk een andere knoop wordt, dan moet je 2 sterretjes gebruiken (zéér belanrijk op test! het is het eerste dat je u afvraagd!)

