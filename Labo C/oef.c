#include<stdio.h>
#include<string.h>

const char* alfabkleinste(const char* const *woorden, int aantal) {
	const char* kl = woorden[0];
	int i;.
	for(i=1; i<aantal; i++) {
		if(strcmp(kl,woorden[i])>0){
			kl = woorden[i];
		}
	}
	return kl;
}

int main() {
	
	return 0;
}
