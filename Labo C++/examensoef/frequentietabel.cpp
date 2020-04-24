#include <iostream>
#include <fstream>
using namespace std;

int main () {
	int frequentie [26] = {0};
	ifstream invoer("lord.txt", ios::in);
	if (!invoer.is_open () ){
		cout <<" bestand niet gevonden " << endl ; // wordt later een exceptie
	}
	else {
		char letter ;
		invoer >> letter ;
		while ( !invoer.fail () ){
			if ( 'a'<= letter && letter <= 'z'){
				frequentie[(letter-'a')] ++;
			}
			invoer >> letter ;
		}
		for ( int i =0; i <26; i ++) {
			cout <<(char)('a'+i) <<" " << frequentie [i]<< endl ;
		}
	}
	invoer.close () ; // optioneel , gebeurt automatisch op het einde
	return 0;
}

