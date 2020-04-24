#include <memory>
#include <vector>
#include <iostream>
using namespace std;

class Langeslang : public vector<unique_ptr<int>>{
	private:
		void schrijf(ostream&)const;
	public:
		void vul(const vector<int>& v);
		Langeslang& concatenate(Langeslang & c);
		friend ostream& operator<<(ostream& out, const Langeslang& l){
			l.schrijf(out);
			return out;
		}
};

void Langeslang::schrijf(ostream& out) const{
	for(int i=0; i<size();i++){
		out<<*(operator[](i))<<" "; //of *((*this)[i])
	}
}

void Langeslang::vul(const vector<int>& v){
	resize(v.size());
	for(int i=0; i<size(); i++){
		(*this)[i] = make_unique<int>(v[i]);
	}
}

Langeslang& Langeslang::concatenate(Langeslang& c) {
	int s_b = size();
	resize(s_b+c.size());
	if(this == &c){
		for(int i=0; i<s_b; i++){
			(*this)[i+s_b] = make_unique<int>(*c[i]);
		}
	}
	else {
		for(int i = s_b; i<size(); i++){
			(*this)[i]=move(c[i-s_b];)
		}
		c.resize();
	}
	return *this;
}
	
int main(){
	Langeslang a;
	Langeslang b;
	Langeslang c;
	
	a.vul({1,2}); // via a vind je de getallen 1 en 2
	b.vul({3,4,5}); // via b vind je de getallen 3, 4 en 5
	c.vul({6,7}); // via c vind je de getallen 6 en 7
	cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
	
	a.concatenate(a);
	// via a vind je nu de 4 getallen 1, 2, 1 en 2
	cout<<"na a.concatenate(a)"<<endl;
	cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
	
	a.concatenate(b).concatenate(c);
	// via a vind je nu de 9 getallen 1, 2, 1, 2, 3, 4, 5, 6 en 7
	// b is leeg
	// c is leeg
	cout<<"na a.concatenate(b).concatenate(c)"<<endl;
	cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
	return 0;
}
