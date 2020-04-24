#include<stdio.h>

void wis(char * s) {
	char * loper = s;
	while(*s){
		if(islower(*s) || isspace(*s)){
			*loper = *s;
			loper++;
		}
		s++;
	}
	*loper = 0;
}


int main() {
	char woord [] = "8d ’a7 !<t -) >+. -)4h &! e9 )b *( )j ’(e) !4\ n8g | ’92 o !43 e5d /. ’ 23g *( e(’ d22a ’( a25n ’(";
	wis(woord);
	puts(woord);
	
	char woord2[81];
	printf("\n\n\nGeef nu zelf een tekst in (met spaties):\n");
	fgets(woord2, 81, stdin);
	wis(woord2);
	puts(woord2);
	return 0; 
}
