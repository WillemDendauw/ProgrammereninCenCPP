#include<iostream>
#include<fstream>
#include<string>
using namespace std;



int main() {
	string s = "ik ben Willem Dendauw";
	int k = s.find("willem"); //geeft 7 terug
	printf(" het woord willem vind ik terug op plaats %d \n",k);
	s.insert(7, "Omer "); //voeg Omer in op plaats 7
	printf("Ik heb het woord Omer toegevoegd op plaats 7 en nu is het dus: \n");
	for(char c: s){
		cout<<c;
	}
	printf("\nNu verwijder ik de woorden ik ben: \n");
	s.erase(0,6);
	for(char c: s){
		cout<<c;
	}
	printf("\nNu verander ik het woord Omer door de jonge heer:\n");
	s.replace(0,5,"de jonge heer");
	for(char c: s){
		cout<<c;
	}
	return 0;
}
