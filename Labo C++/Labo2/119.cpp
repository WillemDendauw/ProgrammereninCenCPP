#include<iostream>
#include<set>
#include<string>
#include<ctime>
#include "containers.h"
using namespace std;
/*
void verwijder(set<int> & verzameling){
	set<int>::iterator it = verzameling.begin();
	int aantal = verzameling.size();
	for(int i = 0; i< aantal; i+=3){
		int xx = *it;
		it++;
		verzameling.erase(xx);
	}
}*/
//volgens de oplossing werkt dit, maar blijkt toch niet juist te zijn, verwijderd eerste 3de van de lijst ipv om de 3

void verwijder(set<int>& verzameling){
	set<int>::iterator it = verzameling.begin();
	int aantal =verzameling.size();
	for(int i=0; i<aantal;i+=3){
		set<int>::iterator it_hulp = it;
		it++;
		verzameling.erase(it_hulp);
		if(it!=verzameling.end()) it++;
		if(it!=verzameling.end()) it++;
	}
}

int main(){
	srand(time(0));
	int aantal = rand()%20 + 11;
	int max = 2*aantal;
	set<int> verzameling;
	while(verzameling.size()!=aantal){
		verzameling.insert(rand()%max);
	}
	cout<<verzameling<<endl;
	verwijder(verzameling);
	cout<<endl<<verzameling;
	return 0;
}
