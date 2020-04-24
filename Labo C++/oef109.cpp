#include <memory>
#include <iostream>
using namespace std;

void schrijf(const unique_ptr<string> *s){
	if(s==nullptr){
		cout << "NULL";
	}
	else {
		cout<<*s;
	}
}

void schrijf(const unique_ptr<string> * s, int aantal){
	cout<<endl;
	for(int i=0; i<aantal-1; i++){
		schrijf(s[i]);
		cout<<" - ";
	}
	schrijf(s[aantal-1]);
}

void verwijder(string * s, int aantal, int volgnr){
	if(volgnr < aantal-1){
		for(int i = volgnr; i < aantal-1; i++){
			s[i] = move(s[i+1]);
		}
	}
	else if(volgnr == aantal-1){
		s[volgnr].reset();
	}
}

int main(){
	unique_ptr < string > pnamen []={make_unique < string >( " Rein ") ,make_unique < string >( " Ada ") ,make_unique < string >( " Eppo ") ,make_unique < string >( " Pascal ") ,make_unique < string >( " Ilse ") };
	schrijf(pnamen,5);
	verwijder(pnamen,5,1);
	schrijf(pnamen,5);
return 0;
}

