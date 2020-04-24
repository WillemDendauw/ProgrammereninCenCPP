#include<stdio.h>

int main() {
	char woord[50] = "snEEuwwITJE<3";
	printf("Geef een woord op: ");
	scanf("%49s",woord);
	my_toupper(woord);
	return 0;
}

void my_toupper(char * s) {
	if(*s >= 'a' && *s <= 'z') {
		*s = *s - 'a' + 'A';
	}
	s++;
	while(*s !=0){
		if(*s >= 'A' && *s <= 'Z') {
			*s = *s - 'A'+'a';
		}
		s++;
	}
}
