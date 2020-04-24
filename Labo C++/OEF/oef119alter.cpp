//zelfde als oef119 maar dan alternatief met procedures
# include <iostream>
# include <fstream>
# include <set>
# include <map>
# include <vector>
# include <string>
using namespace std ;

void regelnummer_opslaan(map<int,string> &m, vector<int>& v, const string& bestand){
	ifstream input;
	input.open(bestand);
	if(!input.is_open()){
		cout<<"bestand niet gevonden"<<endl;
	}
	else {
		int nr;
		while(input>>nr){
			m[nr]="";
			v.push_back(nr);
		}
	}
}

void tekstregels_opzoeken(map<int,string>&m, const string & bestand){
	ifstream input;
	input.open(bestand);
	if(!input.is_open()){
		cout<<"bestand niet gevonden"<<endl;
	}
	else{
		jwz
	}
}
