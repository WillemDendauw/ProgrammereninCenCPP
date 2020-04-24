#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std;

class Persoon{
	public:
		string voornaam;
		string naam;
		int leeftijd;
		Persoon(const string& v, const string& n, int l):voornaam(v),naam(n),leeftijd(l){}
};

ostream& operator<<(ostream& out, const Persoon& p){
	out<<p.naam <<" "<<p.voornaam<<" ("<<p.leeftijd<<")";
	return out;
}

class Groep : public vector<Persoon>{
	public:
		Persoon geef_extremum(function<bool(const Persoon&, const Persoon&)> func){
			int index_beste=0;
			for(int i=1;i<size();i++){
				if(func(operator[](i),operator[](index_beste))){
					index_beste = i;
				}
			}
			return operator[](index_beste);
		}
};

int main(){
	Groep gr;
	gr.push_back(Persoon("Ann","Nelissen",12));
	gr.push_back(Persoon("Bert","Mertens",22));
	gr.push_back(Persoon("Celle","Lauwers",55));
	cout<<"Eerste qua naam: " << gr.geef_extremum([](const Persoon& a, const Persoon& b){return a.naam < b.naam;}) << endl;
	cout<<"Eerste qua voornaam: " << gr.geef_extremum([](const Persoon& a, const Persoon& b){return a.voornaam < b.voornaam;}) <<endl;
	cout<<"Jongste: " << gr.geef_extremum([](const Persoon& a, const Persoon& b){return a.leeftijd < b.leeftijd;})<<endl;
	cout<<"Oudste: " << gr.geef_extremum([](const Persoon& a, const Persoon& b){return a.leeftijd > b.leeftijd;})<<endl;
	return 0;
}
