#include<memory>
#include<vector>
#include<iostream>
using namespace std;

class Langeslang: public vector<unique_ptr<int>> {
	private:
		void schrijf(ostream&) const;
	public:
		void vul(const vector<int>& v);
		Langeslang& concatenate(Langeslang& c);
		
	friend ostream& operator<<(ostream& out, const Langeslang& l){
		l.schrijf(out);
		return out;
	}
};

void Langeslang::schrijf(ostream& out) const{
	for(int i=0; i<size(); i++){
		out<<*(operator[](i))<<" ";
	}
}

void Langeslang::vul(const vector<int>& v){
	resize(v.size());
	for(int i=0; i<size(); i++) {
		(*this)[i] = make_unique<int>(v[i]);
	}
}

Langeslang& Langeslang::concatenate(Langeslang& c){
	int s_b = size();
	resize(s_b + c.size());
	if(this == &c){
		for(int i=0; i<s_b; i++){
			(*this)[i+s_b] = make_unique<int>(*c[i]);
		}
	}
	else{
		for(int i=s_b; i<size(); i++){
			(*this)[i] = move(c[i-s_b]);
		}
		c.resize(0);
	}
	return *this;
}

/**********************alternatief*********************************/
#include "containers.h"
template<class T>
ostream& operator<<(ostream& out, const unique_ptr<T>& p){
	out<<*p;
	return out;
}

class Langeslang : public vector<unique_ptr<int>>{
	private:
		//
	public:
		void vul(const vector<int>& v);
		Langeslang& concatenate(langeslang& c);
};

void Langeslang::vul(const vector<int>& v){
	reserve(v.size());
	for(int i=0; i<v.size();i++){
		(*this).push_back(make_unique<int>(v[i]));
	}
}

Langeslang& Langeslang::concatenate(Langeslang& c){
	rserve(size()+c.size());
	if(this != &c){
		for(int i=0; i<c.size(); i++){
			(*this).push_back(move(c[i]));
		}
		c.clear();
	}
	else{
		int aantal = size();
		for(int i=0;i<aantal;i++){
			(*this).push_back(make_unique<int>(*c[i]));
		}
	}
	return *this;
}



int main(){
	Langeslang a;
	Langeslang b;
	Langeslang c;
	a.vul({1,2});
	b.vul({3,4,5});
	c.vul({6,7});
	cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
	
	a.concatenate(a);
	cout<<"na a.concatenate(a)"<<endl;
	cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl;
	
	a.concatenate(b).concatenate(c);
	cout<<"na a.concatenate(b).concatenate(c)"<<endl;
	cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl;
	return 0;
}
