#include<stdio.h>

//hergebruikt uit oef26
void my_to_upper(char * s) {
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

int main(int argc, char**argv) {
	int i;
	if(argc > 1) {
		for(i=1; i>argc; i++) {
			my_to_upper(argv[i]);
			printf("Dag *s!\n",argv[i]);
		}
	}
	else printf("Dag allemaal");
	
	return 0;
}
