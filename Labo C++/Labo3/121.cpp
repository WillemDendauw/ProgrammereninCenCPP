#include <iostream>
#include <fstream>
#include <string> // nodig bij het inlezen van een breuk
#include <sstream> // vergelijk met Scanner(String) in Java
#include <cmath> // abs berekent absolute waarde van een int (fabs is voor double)
#include <set>
using namespace std;
// zet deze functie in het bestand ’breuk.cpp’

class Breuk{
	private:
		int teller,noemer;
		void normaliseer();
	
	public:
		Breuk(int t=0, int n=1): teller(t), noemer(n){
			normaliseer();
		}
		
		friend ostream& operator>>(ostream& uit, const Breuk& b);
		
		Breuk& operator+=(const Breuk& b);
		Breuk& operator-=(const Breuk& b);
		
		Breuk operator+(const Breuk& b) const;
		Breuk operator-(const Breuk& b) const;
		
		Breuk operator-() const;
		
		Breuk& operator++();
		Breuk operator++(int a);
		
		Breuk operator+(int x) const;
		bool operator<(const Breuk& b) const;
		
		int get_teller() const { return teller;}
		
		bool operator==(const Breuk& b) const;
		bool operator!=(const Breuk& b) const;
		
		friend istream& operator>>(istream& in, Breuk& b);
};

void Breuk::normaliseer(){
	if(noemer < 0){
		noemer *= -1; teller *= -1;
	}
	int deler = mijn_ggd(teller,noemer);
	teller /= deler;
	noemer /= deler;
}

//extern (friend van breuk)
ostream& operator>>(ostream& uit, const Breuk& b){
	uit << b.teller;
	if(b.noemer !=1){
		uit<<"/"<<b.noemer;
	}
	return uit;
}

//lidfuncties
Breuk& Breuk::operator+=(const Breuk& b){
	teller = b.noemer * teller + noemer*b.teller;
	noemer = noemer * b.noemer;
	normaliseer();
	return *this;
}

Breuk& Breuk::operator-=(const Breuk& b){
	operator+=(-b);
	return *this;
} 

Breuk Breuk::operator+(const Breuk& b) const{
	return Breuk(b.noemer * teller + noemer* b.teller, noemer * b.noemer);
}

/*
Breuk Breuk::operator+(const Breuk& b) const{
	Breuk c(*this);
	c+=b;
	return c;
*/

Breuk Breuk::operator-(const Breuk& b) const{
	return Breuk(b.noemer * teller - noemer * b.teller, noemer * b.noemer);
}

/*
Breuk Breuk::operator-(const Breuk& b) const{
	Breuk c(*this);
	c-=b;
	return c;
}
*/

Breuk Breuk::operator-() const{
	return Breuk(-teller,noemer);
}

Breuk& Breuk::operator++(){
	teller += noemer;
	normaliseer();
	return *this;
}

Breuk Breuk::operator++(int a){
	Breuk temp(*this);
	teller += noemer;
	normaliseer();
	return temp;
}

//deel 2
Breuk Breuk::operator+(int x) const{
	Breuk c(*this);
	x *= c.noemer;
	c.teller += x;
	return c;
}

bool Breuk::operator<(const Breuk& b) const{
	return teller * b.noemer < noemer * b.teller;
}

Breuk operator+(int x, const Breuk& b){
	return b+x;
}

bool is_stambreuk(const Breuk& a){
	return a.get_teller()==1;
}

//deel 3
bool Breuk::operator==(const Breuk& b) const{
	return teller == b.teller && noemer == b.noemer;
}

bool Breuk::operator!=(const Breuk& b) const{
	return !operator==(b);
}

istream& oeprator>>(istream& in, Breuk& b){
	string lijn;
	getline(in, lijn);
	int teller, noemer;
	int p = lijn.find("/");
	if(p!=string::npos){
		teller = atoi(lijn.substr(0,p).c_str());
		noemer = atoi(lijn.substr(p+1).c_str());
		b = Breuk(teller, noemer);
	}
	else{
		int getal = atoi(lijn.c_str());
		b = Breuk(getal);
	}
	return in;
}

istream& operator>>(istream& in, Breuk& b){
	string getalbeeld;
	in >> getalbeeld;
	stringstream ss;
	ss << getalbeeld;
	int positie = getalbeeld.find("/");
	if(positie != string::npos){
		int t;
		char c;
		int n;
		ss >> t;
		ss >> c;
		ss >> n;
		if(c == '/' && !ss.fail()){
			b = Breuk(t,n);
		}
		else{
			b = Breuk();
		}
	}
	else{
		int t;
		ss>>t;
		string overschot;
		ss >> overschot;
		if(overschot == ""){
			b = Breuk(t);
		}
		else{
			b = Breuk();
		}
	}
	return in;
}



int mijn_ggd(int a, int b){
	if(a < 0 || b < 0){
		return mijn_ggd(abs(a),abs(b));
	}
	if(a < b){
		return mijn_ggd(b,a);
	}
	if(b == 0){
		return a;
	}
	return mijn_ggd(b,a%b);
}
void deel1(){
	Breuk a(2,5);
	Breuk b(1,-2);
	cout << a << " + " << b << " = ";
	cout << (a+b) << " [-1/10 ?]" << endl;
	cout << "De tegengestelde breuk van " << a << " is " << -a << " [-2/5 ?]." << endl;
	Breuk f = a + b;
	cout << "De som van " << a << " en " << b << " is " << f << " [-1/10 ?]" << endl;
	Breuk g(f);
	cout << "en dat is gelijk aan de breuk " << g <<" [-1/10 ?]."<<endl;
	cout << a << " - " << b << " = ";
	cout << (a-b) << " [9/10 ?]" << endl;
	cout << a << " += " << b << " geeft als resultaat dat de breuk " << a << " verandert in ";
	a += b;
	cout << a << " [-1/10 ?]" << endl;
	cout << a << " -= " << b << " geeft als resultaat dat de breuk " << a << " verandert in ";
	a -= b;
	3 OGP IN C++ - P 2
	cout << a << " [2/5 ?]" << endl;
	cout << "Ik verhoog nu de breuk a=" << a <<" met 2 eenheden; dan is a=";
	cout << ++(++a) << " [12/5 ?]" << endl;
	cout << "Na dit uitschrijven zal b=" << b++ <<" ook met een eenheid verhoogd zijn, nl. ";
	cout << "b=" << b << " [1/2 ?]" << endl;
	Breuk c(2,3);
	Breuk d(3,4);
	Breuk e(1,2);
	(c -= d) += e;
	cout << "Indien hier 5/12 staat, heb je de operatoren -= en += goed geschreven: " << c << endl;
}
void deel2(){
	Breuk d(2,10);
	Breuk e(3);
	cout << d << " is stambreuk: "<<is_stambreuk(d)<<endl;
	Breuk f(3,4);
	cout << endl << "We starten van een breuk, en tellen er telkens een eenheid bij op: " << endl << endl;
	for(int i=0; i<10; i++){
		cout <<i<<" meer dan "<< f << " is " << (i+f) << " = " << (f+i) << endl;
	}
	cout << endl << "Al deze breuken in een verzameling: " << endl;
	set<Breuk> verz;
	for(int i=0; i<10; i++){
		verz.insert(i+f);
		verz.insert(f+i);
	}
	for(Breuk b : verz){
		cout << b << endl;
	}
}
void deel3(){
	Breuk a(13,12);
	Breuk b(2);
	Breuk c;
	cout<<endl<<"Geef c op (onder de vorm teller/noemer (bvb 13/12) of teller (bvb 13) : ";
	cin >> c;
	if(a == c){
		cout << a << " is gelijk aan " << c <<endl;
	}
	if(a != c){
		cout << a << " is niet gelijk aan " << c <<endl;
	}
}

int main(){
	deel1();
	deel2();
	deel3();
	return 0;
}

