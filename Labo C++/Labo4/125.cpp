#include<iostream>
#include<vector>
using namespace std;

class Rechthoek{
	public:
		Rechthoek();
		Rechthoek(int,int);
		int omtrek() const;
		int oppervlakte() const;
		virtual void print(ostream& os) const;
	protected:
		int hoogte;
	private:
		int breedte;
};

class GekleurdeRechthoek: public Rechthoek{
	public:
		GekleurdeRechthoek();
		GekleurdeRechthoek(int, int, const string& = "onbekend");
		virtual void print(ostream& os) const;
	protected:
		string kleur;
};

class Vierkant: public Rechthoek{
	public:
		Vierkant(int = 1);
		virtual void print(ostream &os) const;
};

class GekleurdVierkant : public Vierkant, public GekleurdeRechthoek{
	public:
		GekleurdVierkant(int = 1, const string& ="onbekend");
		void print(ostream& os) const;
};

/**********************Rechthoek***************************/
Rechthoek::Rechthoek(int h, int b) : hoogte(h) , breedte(b) {}
Rechthoek::Rechthoek() : Rechthoek(1,1){}
int Rechthoek::omtrek() const{
	return(hoogte+breedte) * 2;
}
int Rechthoek::oppervlakte() const { return (hoogte*breedte);}

void Rechthoek::print(ostream& os) const{
	os<<"Rechthoek: "<<breedte<<" op "<<hoogte<<endl;
}

/**********************GekleurdeRechthoek*********************/
GekleurdeRechthoek::GekleurdeRechthoek(int h, int b, const string &kl): Rechthoek(h,b), kleur(kl){}
GekleurdeRechthoek::GekleurdeRechthoek() : kleur("onbekend"){}
void GekleurdeRechthoek::print(ostream& os) const{
	Rechthoek::print(os);
	os<<" kleur: " << kleur <<endl;
}

/*********************Vierkant***************************/
Vierkant::Vierkant(int zijde) : Rechthoek(zijde, zijde){}
void Vierkant::print(ostream& os) const{
	os << "Vierkant: zijde " << hoogte <<endl; 
}

/********************GekleurdVierkant******************/
GekleurdVierkant::GekleurdVierkant(int zijde, const string& kl) : GekleurdeRechthoek(zijde, zijde, kl), Vierkant(zijde){}
void GekleurdVierkant::print(ostream & os) const{
	Vierkant::print(os);
	os << "kleur: "<<kleur<<endl;
}

/*********************extern*************************/
ostream& operator<<(ostream& os, const Rechthoek& rh){
	rh.print(os);
	return os;
}

ostream& operator<<(ostream& os, const GekleurdVierkant &v){
	v.print(os);
	return os;
}

int main () {
	vector<unique_ptr<Rechthoek>> v;
	v.push_back(unique_ptr<Rechthoek>(4,6));
	v.push_back(unique_ptr<GekleurdeRechthoek>());
	v.push_back(unique_ptr<GekleurdeRechthoek>(6,9,"rood"));
	v.push_back(unique_ptr<Vierkant>(10));
	for(int i=0; i<v.size(); i++){
		cout << *v[i];
		cout<< " oppervlakte: "<< v[i]->oppervlakte() << endl
			<< " omtrek " << v[i]->omtrek() << endl;
	}

	Rechthoek r2(4,6);
	GekleurdeRechthoek gr1;
	GekleurdeRechthoek gr3(6,9,"rood");
	Vierkant v2(10);
	vector<Rechthoek*> v;
	v.push_back(&r2);
	v.push_back(&gr1);
	v.push_back(&gr3);
	v.push_back(&v2);
	for(int i=0 ; i<v.size() ; i++) {
		cout << v[i];
		cout << " oppervlakte: " << v[i].oppervlakte() << endl
		<< " omtrek: " << v[i].omtrek() << endl;
	}
	return 0;

}
