# include < stdio .h >
# include < string .h >
# define AANTAL_WOORDEN 10
# define GEMIDDELDE_LENGTE_WOORDEN 7
# define TOTALE_LENGTE_ARRAY AANTAL_WOORDEN * (1+ GEMIDDELDE_LENGTE_WOORDEN )

void lees ( char ** pt ){
	int i;
	for (i =0; i < AANTAL_WOORDEN ; i ++) {
		scanf ("%s" ,* pt );
		*( pt +1) = * pt + strlen (* pt ) +1;
		pt ++;
	}
	* pt =0;
}
	
void schrijf ( const char * const * pt ){
	while (* pt !=0) {
		puts (* pt ++) ;
	}
}

int main(){
	char* pt[AANTAL_WOORDEN+1]; /* zodat je ook nog een nullpointer kan toevoegen
	op het einde van de pointertabel */
	char t[TOTALE_LENGTE_ARRAY];
	pt[0] = t;
	printf("Geef %d woorden in:\n", AANTAL_WOORDEN);
	lees(pt); /* leest alle woorden in */
	schrijf(pt); /* schrijft alle woorden onder elkaar uit */
	return 0;
}

