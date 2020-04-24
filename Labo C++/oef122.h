#include<iostream>
#ifndef oef122_H
#define oef122_H

using namespace std;

class Rechthoek {
 public:
   Rechthoek();
   Rechthoek(int, int);
   int oppervlakte() const;
   int omtrek() const;
   virtual void print(ostream& out) const;
   friend ostream& operator<<(ostream& out, const Rechthoek& r);
   
   private:
   	int breedte;
   	protected:
	int hoogte;
};

Rechthoek::Rechthoek(): hoogte(1),breedte(1){
}

Rechthoek::Rechthoek(int br, int ho):breedte(br),hoogte(ho){
}

int Rechthoek::omtrek() const{
	int omtrek = 2*hoogte + 2*breedte;
	return omtrek;
}

int Rechthoek::oppervlakte() const{
	int oppervlakte = breedte * hoogte;
	return oppervlakte;
}

void Rechthoek::print(ostream& out) const{
	out << "Rechthoek " << breedte << " op " << hoogte << endl;
	
}

ostream& operator<<(ostream& out, const Rechthoek& r) {
	//out << "Rechthoek " << r.hoogte << " op " << r.breedte << endl;
	r.print(out);
	return out;
}

// afgeleid van Rechthoek; pas aan in hoofding
class GekleurdeRechthoek : public Rechthoek {
 public:
 	GekleurdeRechthoek();
 	GekleurdeRechthoek(int, int);
 	GekleurdeRechthoek(int, int, string);
 	void print(ostream& out) const;
   	friend ostream& operator<<(ostream& out, const GekleurdeRechthoek& r);
   	
   	protected:
   	 string kleur;
};

ostream& operator<<(ostream& out, const GekleurdeRechthoek& r) {
	//out << "Rechthoek " << r.hoogte << " op " << r.breedte << endl;
	r.print(out);
	return out;
}

GekleurdeRechthoek::GekleurdeRechthoek():kleur("onbekend"){
}

GekleurdeRechthoek::GekleurdeRechthoek(int br, int h):Rechthoek(br,h),kleur("onbekend"){
}

GekleurdeRechthoek::GekleurdeRechthoek(int br, int h, string kl):Rechthoek(br,h),kleur(kl){
}

void GekleurdeRechthoek::print(ostream& out) const {
	Rechthoek::print(out);
	out <<"  kleur: " << kleur << endl;
}

// afgeleid van Rechthoek; pas aan in hoofding
class Vierkant : public Rechthoek {
 public:
 	Vierkant();
 	Vierkant(int);
 	void print(ostream& out) const;
};

Vierkant::Vierkant(){
}

Vierkant::Vierkant(int zijde):Rechthoek(zijde,zijde){
}

void Vierkant::print(ostream& out) const{
	out << "Vierkant: " << hoogte << " op " << hoogte << endl;
}


// afgeleid van GekleurdRechthoek en Vierkant; pas aan in hoofding
class GekleurdVierkant : public GekleurdeRechthoek, Vierkant {
	public:
	GekleurdVierkant();
	GekleurdVierkant(int zijde);
	GekleurdVierkant(int zijde, string kleur);
	void print(ostream& out) const;
    // geen extra attributen voorzien!
};

GekleurdVierkant::GekleurdVierkant():GekleurdeRechthoek(){
}

GekleurdVierkant::GekleurdVierkant(int zijde):GekleurdeRechthoek(zijde, zijde){
}

GekleurdVierkant::GekleurdVierkant(int zijde, string kleur):GekleurdeRechthoek(zijde,zijde,kleur){
}

void GekleurdVierkant::print(ostream& out) const{
	Vierkant::print(out);
	out << "  kleur: " << kleur <<endl;
}
#endif
