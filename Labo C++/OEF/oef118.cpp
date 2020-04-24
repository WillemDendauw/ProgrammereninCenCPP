#include <iostream>
#include <set>
#include <string>
#include "oef113.h"
using namespace std;

int main(){
	srand(time(0));
	int aantal = rand()%20+10
	int max = 2*aantal;
	set<int> verzameling;
	while(verzameling.size()!=aantal){
		verzameling.insert(rand%max);
	}
	cout<<verzameling<<endl;
	set<int>::iterator it = verzameling.begin();
	int aantal = verzameling.size();
	for(int i=0; i<aantal; i+=3){
		set<int>::iterator it_hulp = it;
		it++;
		verzameling.erase(it_hulp);
		if(it!=verzameling.end()){
			it++
		}
	}
	return 0;
}
