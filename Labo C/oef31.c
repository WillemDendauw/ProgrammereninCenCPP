#include<stdio.h>
#include<string.h>

void schrijf_int(const int * a){
	printf("%d",*a);
}

void schrijf_cstring(const char *const *s){
	printf("%s",*s);
}

void schrijf_double(const double x){
	printf("%f",*x);
}

void schrijf_array(const void*t, int aantal, int grootte, char tussenteken, void(*schrijf)(const void*))){
	const char* hulp = (const char*)t;
	int i;
	schrijf(hulp);
	for(i=1; i<aantal; i++){
		printf("%c", tussenteken);
		hulp += grootte;
		schrijf(hulp);
	}
	printf("\n\n");
}

int main(){
	char * namen[] = {"Evi","Jaro","Timen","Youri","Ashaf","Jennifer"};
	int leeftijden[] = {21,30,18,14,22,19};
	double scores[] = {0.5,1.6,8.2,-2.4};
	schrijf_array ( leeftijden , sizeof ( leeftijden )/ sizeof (int ) , sizeof ( int ) , ',',( void (*) ( const void *) ) schrijf_int  );
	schrijf_array ( namen , sizeof ( namen ) / sizeof ( char *) , sizeof ( char *) , ';',( void (*) ( const void *) ) schrijf_cstring ) );
	schrijf_array ( scores , sizeof ( scores )/ sizeof ( double ) ,sizeof ( double ) , '~',( void (*) ( const void *) ) schrijf_double ) );
	return 0;
}
