#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

void vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(vector<map<string,stack<set<string> > > > vect,int i,string sleutel,string str1,string str2,stringstr3){
	vect[i-1][sleutel].push_back({str1,str2,str3});	
}

bool i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(vector<map<string,stack<set<string> > > > vect,int i, string woord, string element){
	bool aanwezig = false;
	map<string,stack<set<string> > >::const iterator it = vect[i].find(woord);
	if(it!=vect[i].end()){
		if(!it.second.is_empty()){
			aanwezig = (it->second.top().count()!=1);
		}
	}
	return aanwezig;
}

int main(){
	
}
