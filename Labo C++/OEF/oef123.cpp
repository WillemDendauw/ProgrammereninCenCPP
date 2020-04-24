#include <iostream>
#include <fstream>

vector<unique_ptr<Rechthoek>> v;
v.push_back(make_unique<Rechthoek>(4,6));
v.push_back(make_unique<GekleurdeRechthoek>());
v.push_back(make_unique<GekleurdeRechthoek>(6,9,"rood"));
v.push_back(make_unique<Vierkant>(10));
for(int i=0; i<v.size();i++){
	cout << *v[i];
	cout << " oppervlate: "<<v[i]->oppervlakte() <<endl
		<<" omtrek " <<v[i]->omtrek() <<endl;
}
