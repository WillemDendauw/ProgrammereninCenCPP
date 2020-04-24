#include <iostream>
#include <fstream>
using namespace std;
class Rechthoek {
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
		virtual void print(ostream &os) const;
	protected:
		string kleur;
};

class Vierkant: public Rechthoek {
	public:
		Vierkant(int=1);
		virtual void print(ostream& os) const;
};

class GekleurdVierkant: public Vierkant, public GekleurdeRechthoek {
	public:
		GekleurdVierkant(int =1, const string & = "onbekend");
};

//rechthoek

Rechthoek::Rechthoek(int h, int b): hoogte(h), breedte(b) {}
Rechthoek::Rechthoek() : Rechthoek(1,1) {}
int Rechthoek::omtrek() const{
	return(hoogte+breedte)*2;
}
int Rechthoek::oppervlakte() const {return (h*b);}
void Rechthoek::print(ostream& os) const {
	os<<"Rechthoek: "<<breedte<<" op "<<hoogte<<endl;
}

//gekleurderechthoek
GekleurdeRechthoek::GekleurdeRechthoek(): kleur("onbekend"){}
GekleurdeRechthoek::GekleurdeRechthoek(int h, int b, const string &kl):Rechthoek(h,b), kleur(kl) {}
void GekleurdeRechthoek::print(ostream& os)const{
	Rechthoek::print(os);
	os <<" kleur: "<<kleur<<endl;
}

//Vierkant
Vierkant::Vierkant(int zijde):Rechthoek(zijde,zijde){}
void Vierkant::print(ostream& os)const {
	os <<"Vierkant: zijde "<<hoogte<<endl;
}

//GekleurdVierkant
GekleurdVierkant::GekleurdVierkant(int zijde, const string &kl):GekleurdeRechthoek(,zijde, zijde,kl), Vierkant(zijde){}
void GekleurdVierkant::print(ostream& os)const {
	Vierkant::print(os);
	os <<" kleur: "<<kleur<<endl;
}

//extern
ostream& operator<<(ostream& os, const Rechthoek &rh){
	rh.print(os);
	return os;
}

ostream& operator<<(ostream& os, const GekleurdVierkant &v){
	v.print(os);
	return os;
}

int main(){
	GekleurdVierkant gv1;
	cout << gv1;
	cout << " oppervlakte "<< bv.Vierkant::oppervlakte() <<endl;
		<<" omtrek: "<<gv.Vierkant::omtrek() <<endl;
		
	GekleurdVierkant gv2(12);
	gv2.print(cout);
	cout << " oppervlakte : " << gv2 . Vierkant :: oppervlakte () << endl
		<< " omtrek : " << gv2 . GekleurdeRechthoek :: omtrek () << endl ;
	GekleurdVierkant gv3 (15 , " geel ");
	cout << gv3 ;
	cout << " oppervlakte : " << gv3 . GekleurdeRechthoek :: oppervlakte () << endl
		<< " omtrek : " << gv3 . GekleurdeRechthoek :: omtrek () << endl ;
	return 0;
}




















