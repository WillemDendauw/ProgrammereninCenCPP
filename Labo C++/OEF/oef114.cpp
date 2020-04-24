#include "oef113.h"
#include <unordered_set>
#include <map>
int main(){
	
	map<char,unordered_set<string> >m;
	string woord;
	cout<<"geef woorden, eindig met STOP"<<endl;
	cin>>woord;
	while(woord!="STOP"){
		m[woord[0]].insert(woord);
		cin>>woord;
	}
	cout<<"Geef een letter, ik zeg je hoeveel verschillende woorder er beginnen met die letter";
	char letter;
	cin>>letter;
	if(m.count(letter)==1){
		cout<<"er waren "<<m[letter].size()<<" verschillende woorden met die startletter"<<endl;
	}
	else {
		cout<<"er waren geen woorden met die letter"<<endl;
	}
	return 0;
}
