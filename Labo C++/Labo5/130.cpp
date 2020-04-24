#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;


class bestand_niet_lang_genoeg: public invalid_argument{
	public:
		bestand_niet_lang_genoeg(const string& message):invalid_argument(message){}
};

string regel_uit_bestand(const string& bestandsnaam, int nr){
	ifstream invoer;
	invoer.open(bestandsnaam);
	if(!invoer.is_open()){
		throw bestandsnaam+"kon niet geopend worden";
	}
	string woord, magweg;
	invoer >> woord;
	getline(invoer, magweg); //rest van de regel
	if(woord != "VERHAAL"){
		throw woord.c_str();
	}
	string zin;
	int teller =0;
	while(!invoer.fail() && teller < nr){
		getline(invoer, zin);
		teller++;
	}
	if(invoer.fail()){
		throw bestand_niet_lang_genoeg(bestandsnaam+" heeft geen "+to_string(nr)+" regels.");
	}
	return zin;
}


int main(){
	vector<string> bestandsnamen{"niks","een","twee","drie","vier","vijf","zes","zeven","acht","negen","tien","elf","twaalf"};
	vector<int> nrs{8,5,2,10,7,3,8,4,1,1,6,2,4};
	string bestanden_niet_gevonden="";
	string bestanden_niet_lang_genoeg="";
	string eerste_woorden ="";
	
	for(int i=0; i<bestandsnamen.size(); i++){
		try{
			cout<< regel_uit_bestand(bestandsnamen[i]+".txt",nrs[i])<<endl;
		}
		catch(const char* x){
			eerste_woorden += x;
			eerste_woorden += " ";
		}
		catch(const string &s){
			bestanden_niet_gevonden += s+"\n";
		}
		catch(bestand_niet_lang_genoeg bnlg){
			bestanden_niet_lang_genoeg += string(bnlg.what());
		}
		
	}
	
	cout<<endl<<endl<<"BESTANDEN NIET GEVONDEN:"<<endl;
	cout<<bestanden_niet_gevonden;
	
	cout<<endl<<"BESTANDEN NIET LANG GENOEG:"<<endl;
	cout<<bestanden_niet_lang_genoeg<<endl;
	
	cout<<endl<<"BESTANDEN ZONDER STARTWOORD 'VERHAAL':"<<endl;
	cout<<"dit waren de woorden die er wel als eerste stonden:"<<endl<<endl;
	
	cout<<eerste_woorden<<endl<<endl;
	
	return 0;
}
