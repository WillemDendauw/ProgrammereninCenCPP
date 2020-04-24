#include "containers.h"
#include <iostream>
#include <map>
#include <unordered_set>
#include <iterator>
#include <vector>
using namespace std;

void zoek(const string& woord, const vector<map<char,unordered_set<string>>> & v){
	if(woord.size() <v.size()){
		if(v[woord.size()].count(woord[0])==1){
			map<char,unordered_set<string>>::const_iterator it=
				v[woord.size()].find(woord[0]);
			cout<<it->second;
		}
		else{
			cout<<"geen woorden van die lengte met startletter "<<woord[0]<<endl;
		}
	}
	else{
		cout<<"geen woorden gevonden die zo lang zijn"<<endl;
	}
}

int main(){
	vector<map<char,unordered_set<string>>> v(10);
	string woord;
	cout<<"geef woorden, eindig met STOP"<<endl;
	cin>>woord;
	while(woord!=STOP){
		if(woord.size() > v.size() - 1){
			v.resize(woord.size()+1);
		}
		v[woord.size()][woord[0]].insert(woord);
		cin>>woord;
	}
	//cout<<v;
	zoek("sinterklaas",v);
	return 0;
}
