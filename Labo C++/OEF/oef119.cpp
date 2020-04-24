# include <iostream>
# include <fstream>
# include <set>
# include <map>
# include <vector>
# include <string>
using namespace std ;

int main() {
	map<int,string> tekst_op_regelnr;
	vector<int>volgorde_regelnummers;
	
	ifstream input("regelnummers.txt");
	if(!input.is_open()){
		cout<<"bestand niet gevonden..."<<endl;
	}
	else {
		int nr;
		while(input>>nr){
			tekst_op_regelnr[nr]="";
			volgorde_regelnummers.push_back(nr);
		}
		
		ifstream input2("nbible.txt");
		if(!input2.is_open()){
			cout<<"bestand niet gevonden..."<<endl;
		}
		else{
			int tel=1;
			string lijn;
			while(getline(input2,lijn)){
				if(tekst_op_regelnr.count(tel)>0){
					tekst_op_regelnr[tel]=lijn;
				}
				tel++;
			}
			for(int i=0;i<volgorde_regelnummers.size();i++){
				cout<<tekst_op_regelnr[volgorde_regelnummers[i]]<<endl;
			}
		}
		return 0;
	}
}
