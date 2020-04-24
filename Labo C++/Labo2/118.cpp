#include "containers.h"

void vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(
	vector<map<string,stack<set<string>>>>& vect, int i,
	const string& sleutel, const string& str1, const string& str2,
	const string& str3){
		set<string> s;
		s.insert(str1);
		s.insert(str2);
		s.insert(str3);
		vect[i-1][sleutel].push(move(s));
}
	
bool i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(
	const vector<map<string, stack<set<string>>>>& vect, int i,
	const string& woord, const string& element){
		
		if(i<1){
			return false;
		}
		bool aanwezig = false;
		map<string,stack<set<string>>>::const_iterator it =vect[i-1].find(woord);
		if(it != vect[i-1].end()){
			if(!it->second.empty()){
				aanwezig =(it->second.top().count(element)!= 0);
			}
		}
		return aanwezig;
}

void controleer(const vector<map<string,stack<set<string>>>>& vect, int i, const string& woord,
	const string& element){
		
		if(i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(vect,i,woord,element)){
			cout<<"\nmap op index " << i << " bevat sleutel '" << woord<< "', en element '" << element <<"'"
			<<" zit in zijn bovenste zet van de bijhorende stack";
		}
		else{
			cout<<"\n FOUT voor "<<i<<" "<<woord<<" "<<element;
		}
}

int main(){
	vector<map<string,stack<set<string>>>> v(5);
	vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(v,1,"noot","do","re","mi");
	//cout<<v;
	controleer(v,1,"noot","re");
	controleer(v,1,"noot","sol");
	controleer(v,1,"appelmoes","re");
	controleer(v,0,"noot","re");
	return 0;
}
