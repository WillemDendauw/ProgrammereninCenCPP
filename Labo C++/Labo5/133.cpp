#include "figuren.h"
#include <memory>

class Blokkendoos: vector<unique_ptr<Figuur>>{
	private:
		unique_ptr<Figuur> max_opp;
		void schrijf(ostream&) const;
		
	public:
		Blokkendoos();
		Blokkendoos(const string& bestandsnaam);
		unique_ptr<Figuur> geef_figuur_met_grootste_oppervlakte();
		void push_back(unique_ptr<Figuur>& figuur);
		
		friend ostream& operator<<(ostream& out, const Blokkendoos& l){
			l.schrijf(out);
			return out;
		}
};

Blokkendoos::Blokkendoos() = default;

void Blokkendoos::push_back(unique_ptr<Figuur>& figuur){
	if(max_opp==nullptr){
		max_opp = move(figuur);
	}
	else{
		vector<unique_ptr<Figuur>>::push_back(move(figuur));
		if(max_opp->oppervlakte()<operator[](size()-1)->oppervlakte()){
			max_opp.swap(operator[](size()-1));
		}
	}
}

Blokkendoos::Blokkendoos(const string& bestandsnaam){
	unique_ptr<Figuur> up;
	ifstream input(bestandsnaam);
	string soort;
	input >> soort;
	while(!input.fail()){
		if(soort == "rechthoek"){
			double lengte, breedte;
			input>>lengte>>breedte;
			up = make_unique<Rechthoek>(lengte,breedte);
		}
		else if(soort == "vierkant"){
			double zijde;
			input >> zijde;
			up = make_unique<Vierkant>(zijde);
		}
		else{
			double straal;
			input >> straal;
			up = make_unique<Cirkel>(straal);
		}
		push_back(up);
		input >> soort;
	}
}

void Blokkendoos::schrijf(ostream& out)const{
	for(int i=0; i<size(); i++){
		out<<endl<<" "<<i<<" ";
		out<<*(operator[](i));
	}
	out<<endl<<"MAX "<<*max_opp<<endl;
	/*
	for(const auto& ptr: *this){
		out<<*ptr<<endl;
	}*/
}

unique_ptr<Figuur> Blokkendoos::geef_figuur_met_grootste_oppervlakte(){
	int index_tweedegrootste = 0;
	for(int i=1; i<size(); i++){
		if(operator[](i)->oppervlakte() > operator[](index_tweedegrootste)->oppervlakte()){
			index_tweedegrootste =i;
		}
	}
	
	operator[](index_tweedegrootste).swap(operator[](size()-1));
	unique_ptr<Figuur> hulpptr;
	hulpptr.swap(max_opp);
	max_opp.swap((*this)[size()-1]);
	resize(size()-1);
	return move(hulpptr);
}

int main(){
	Blokkendoos blokkendoos("figuren.txt");
	cout<<endl<<"ALLE FIGUREN: ";
	cout<<blokkendoos<<endl;
	cout<<endl<<"De 3 Grootste, van groot naar klein: "<<endl;
	for(int i=0; i<3; i++){
		cout<<"figuur met grootste opp: "<<*blokkendoos.geef_figuur_met_grootste_oppervlakte()<<endl;
	}
	
	cout<<endl<<"De nieuwe blokkendoos bevat alleen nog de kleinere figuren: ";
	cout<<blokkendoos<<endl;
	
	return 0;
}























