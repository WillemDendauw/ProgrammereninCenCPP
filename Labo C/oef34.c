#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int waarde;
	int aantal_delers;
	int*delers;
}Deeltal;

void schrijf_ints(const int*x, int aantal){
	int i;
	printf("%i",x[0]);
	for(i=1; i<aantal; i++){
		printf("-%i",x[i]);
	}
}

void schrijf_deeltal(const Deeltal * x){
	printf("%d ",x->waarde);
	schrijf_ints(x->delers,x->aantal_delers);
	printf("\n");
}

int aantal_delers_van(int x){
	int aantal = 1;
	int d;
	for(d = 2; d<= x/2; d++){
		if(x%d == 0){
			aantal++;
		}
	}
	return aantal;
}

int * delers_van(int x, int aantal){
	int * delers= (int*) malloc(aantal * sizeof(int));
	int d, index = 0;
	for(d=1; d<= x/2; d++) {
		if(x%d == 0) {
			delers[index++]= d;
		}
	}
	return delers;
}

void lees_deeltal(Deeltal * g) {
	scanf("%i",&(g->waarde));
	if(g->waarde < 0) {
		g-> waarde *= -1;
	}
	g->aantal_delers = aantal_delers_van(g->waarde);
	g->delers = delers_van(g->waarde,g->aantal_delers);
}

void lees_deeltallen(Deeltal * t, int aantal) {
	int i;
	for(i=0; i<aantal; i++) {
		lees_deeltal(&t[i]);
	}
}

void schrijf_deeltallen(const Deeltal * ptr, int aantal) {
	int i;
	for(i = 0; i<aantal; i++) {
		schrijf_deeltal(&ptr[i]);
	}
}

const Deeltal * zoek(int waarde, const Deeltal *t, int aantal){
	int i= 0;
	while(i<aantal && t[i].waarde != waarde){
		i++;
	}
	return(i==aantal ? 0 : &t[i]);
}

void free_delers(Deeltal * g){
	printf("\nIk geef (delers van) dit deeltal vrij: %d",g->waarde);
	free(g->delers);
}

void free_deeltallen ( Deeltal * g , int aantal ){
	int i;
	printf ("\nFree tabel met %d deeltallen :" , aantal );
	for (i =0; i < aantal ; i ++) {
		free_delers (& g[i]);
	}
}

void free_deeltallen_volledig ( Deeltal ** g , int aantal ){
	int i;
	printf ("\nFree tabel met %d deeltallen :" , aantal );
	for (i =0; i < aantal ; i ++) {
		free_delers (&(* g)[i]);
	}
	printf ("\nTabel zelf vrijgeven ");
	free (* g);
}


int main(){
	Deeltal g,x;
	int t[]={1,2,3};
	int aantal;
	Deeltal * deeltallen;
	const Deeltal * gezocht;
	g.waarde = 6;
	g.aantal_delers = 3;
	g.delers = t;
	
	printf("Geef een eerste deeltal in.\n");
	lees_deeltal(&x);
	schrijf_deeltal(&x);
	
	printf("Nu komt het vervolg; hoeveel; hoeveel deeltallen wil je nog ingeven?");
	scanf("%d",&aantal);
	printf("Geef nu die deeltallen in.\n");
	
	deeltallen = (Deeltal*) malloc(aantal *sizeof(Deeltal));
	lees_deeltallen(deeltallen,aantal);
	schrijf_deeltallen(deeltallen,aantal);
	
	printf ("\nIk zoek 20: ");
	gezocht = zoek (20 , deeltallen , aantal );
	if ( gezocht !=0) {
		schrijf_deeltal ( gezocht );
	}	
	else {
		printf ("\n20 niet gevonden ... ");
	}
	free_delers (& g);
	free_delers (& x);
	free_deeltallen ( deeltallen , aantal );
	printf ("\nTabel zelf vrijgeven ");
	free ( deeltallen ); /* moet je nog apart doen ! Tenzij je voor de alternatieve
	procedure free_deeltallen_volledig (...) gaat :
	free_deeltallen_volledig (& deeltallen , aantal ); */
	/* merk op : ’ gezocht ’ geef je uiteraard niet vrij ,
	want dit wijst naar geheugen dat reeds vrijgegeven werd .
	( en free op een nullpointer oproepen crasht ) */
	return 0;
}
