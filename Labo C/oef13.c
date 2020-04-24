#include <stdio.h>

int main(){
	int grootte;
	char letters[] = {'p','o','r','e','o','i','f','o','i','e','c','i','i',':','a','-','t','()'};
	grootte = sizeof(letters)/sizeof(char);
	//printf("%d",grootte);
	schrijf_even_posities(letters, grootte);
}

void schrijf_even_posities(char array[],int groot) {
	int i;
	for(i=0; i<groot; i=i+2) {
		printf("%c",array[i]);
	}
}

