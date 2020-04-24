#include<iostream>
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
	Rechthoek r1;
	r1.print(cout);
	cout << " oppervlakte: " << r1.oppervlakte() << endl
		<< " omtrek: " << r1.omtrek() << endl;
	Rechthoek r2(4,6);
	cout << r2;
	cout << " oppervlakte: " << r2.oppervlakte() << endl
		<< " omtrek: " << r2.omtrek() << endl;
	GekleurdeRechthoek gr1;
	gr1.print(cout);
	cout << " oppervlakte: " << gr1.oppervlakte() << endl
		<< " omtrek: " << gr1.omtrek() << endl;
	GekleurdeRechthoek gr2(5,7);
	cout << gr2;
	cout << " oppervlakte: " << gr2.oppervlakte() << endl
		<< " omtrek: " << gr2.omtrek() << endl;
	GekleurdeRechthoek gr3(6,9,"rood");
	gr3.print(cout);
	cout << " oppervlakte: " << gr3.oppervlakte() << endl
		<< " omtrek: " << gr3.omtrek() << endl;
	Vierkant v1;
	cout << v1;
	cout << " oppervlakte: " << v1.oppervlakte() << endl
		<< " omtrek: " << v1.omtrek() << endl;
	Vierkant v2(10);
	v2.print(cout);
	cout << " oppervlakte: " << v2.oppervlakte() << endl
		<< " omtrek: " << v2.omtrek() << endl;
	GekleurdVierkant gv1;
	cout << gv1;
	cout << " oppervlakte: " << gv1.Vierkant::oppervlakte() << endl
		<< " omtrek: " << gv1.Vierkant::omtrek() << endl;
	GekleurdVierkant gv2 (12) ;
	gv2 . print ( cout );
	cout << " oppervlakte : " << gv2 . Vierkant :: oppervlakte () << endl
		<< " omtrek : " << gv2 . GekleurdeRechthoek :: omtrek () << endl ;
	GekleurdVierkant gv3 (15 , " geel ");
	cout << gv3 ;
	cout << " oppervlakte : " << gv3 . GekleurdeRechthoek :: oppervlakte () << endl
		<< " omtrek : " << gv3 . GekleurdeRechthoek :: omtrek () << endl ;
	return 0;
}
