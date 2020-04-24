#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include "containers.h"
using namespace std;

const int AANTAL = 5;

int main(){
	stack<string> st;
	st.push("een");
	st.push("twee");
	st.push("drie");
	cout<<st;
	cout<<st;
	
	vector<string> tabel[AANTAL];
	tabel[1].push_back("aap");
	tabel[1].push_back("noot");
	tabel[1].push_back("mies");
	for(int i=0;i<AANTAL;i++){
	//	cout<<tabel[i];
	}
	
	vector<vector<int>> v;
	for(int i=0; i<AANTAL;i++){
		vector<int> w(i);
		for(int k=0;k<v.size();k++){
			w[k] = 10+10*k;
		}
		v.push_back(w);
	}
	//cout<<v;
	for(int i=v.size()-1;i>=0;i--){
		for(int k=v[i].size()-1;k>=0;k--){
			cout<<v[i][k]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
