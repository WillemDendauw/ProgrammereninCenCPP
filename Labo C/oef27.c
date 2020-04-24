#include<stdio.h>

const char* pointerNaarEersteKleineLetter(const char* l){
	while(*l && (*l<'a' || *l>'z')) {
		l++;
	}
	return l;
}

void verzetNaarEersteHoofdletter(const char **l) {
	while(**l && (**l<'A' || **l>'Z')) {
		(*l)++;
	}
}

int main(){
	const char zus1[50] = "sneeuwWITje";
	const char zus2[50] = "rozeROOD";
	const char* begin;
	const char* eind;
	begin = zus1;
	verzetNaarEersteHoofdletter(&begin);
	eind = pointerNaarEersteKleineLetter(begin);
	schrijf(begin,eind); /* schrijft ’WIT’ uit */
	printf("\n");
	begin = zus2;
	verzetNaarEersteHoofdletter(&begin);
	eind = pointerNaarEersteKleineLetter(begin);
	schrijf(begin,eind); /* schrijft ’ROOD’ uit */
	return 0;
}

void schrijf ( const char * begin , const char * eind ){
	while ( begin < eind ){
		printf ("%c" ,* begin );
		begin ++;
	}
}
