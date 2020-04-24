#include "oef122.h"
#include <iostream>

using namespace std;

int main () {
   Rechthoek r1;
   r1.print(cout);
   cout << "  oppervlakte: " << r1.oppervlakte() << endl
        << "  omtrek: " << r1.omtrek() << endl;
       
   Rechthoek r2(4,6);
   cout << r2;
   cout << "  oppervlakte: " << r2.oppervlakte() << endl
        << "  omtrek: " << r2.omtrek() << endl;
        
   GekleurdeRechthoek gr1;
   gr1.print(cout);
   cout << "  oppervlakte: " << gr1.oppervlakte() << endl
        << "  omtrek: " << gr1.omtrek() << endl;
        
   GekleurdeRechthoek gr2(5,7);
   cout << gr2;
   cout << "  oppervlakte: " << gr2.oppervlakte() << endl
        << "  omtrek: " << gr2.omtrek() << endl;
        
   GekleurdeRechthoek gr3(6,9,"rood");
   gr3.print(cout);
   cout << "  oppervlakte: " << gr3.oppervlakte() << endl
        << "  omtrek: " << gr3.omtrek() << endl;
	
   Vierkant v1;
   cout << v1;
   cout << "  oppervlakte: " << v1.oppervlakte() << endl
        << "  omtrek: " << v1.omtrek() << endl;
        
   Vierkant v2(10);
   v2.print(cout);
   cout << "  oppervlakte: " << v2.oppervlakte() << endl
        << "  omtrek: " << v2.omtrek() << endl; 
		
   GekleurdVierkant gv1;
   cout << gv1;   
   cout << "  oppervlakte: " << gv1.Vierkant::oppervlakte(); //het maakt niet uit dat er meerdere klassen tussen zitten maar hij weet niet via welke klasse hij eraan moet graken
        << "  omtrek: " << gv1.GekleurdeRechthoek::omtrek();
        
   GekleurdVierkant gv2(12);
   gv2.print(cout);
   cout << "  oppervlakte: " << gv2.Vierkant::oppervlakte();
        << "  omtrek: " << gv2.Vierkant::omtrek();
        
   GekleurdVierkant gv3(15,"geel");
   cout << gv3;
   cout << "  oppervlakte: " << gv3.Vierkant::oppervlakte();
        << "  omtrek: " << gv3.Vierkant::omtrek();
   return 0;
}
