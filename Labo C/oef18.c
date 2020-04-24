#include<stdio.h>

int main(){
	int i=7, j;
	double d;
	int *ip, *jp, *tp;
	double *dp;
	const int * p1;
	int * const p2 = &i;
	int t[25] = {10,20,30,40,50,60};
	/* 1*/ i = j;			//fout	niets want j is leeg
	/* 2*/ jp = &i;			//ok 	jp wijst naar i (7)
	/* 3*/ j = *jp;			//ok	j wordt hier 7
	/* 4*/ *ip = i;			//fout	ip is een zwevende pointer
	/* 5*/ ip = jp;			//ok	ip en jp zijn nu dezelfde pointer
	/* 6*/ &i = ip;			//fout	een adres kan jen niet wijzigen
	/* 7*/ (*ip)++;			//ok	i wordt 8
	/* 8*/ *ip *=i;			//ok	8 wordt nu 64
	/* 9*/ ip++;			//fout	ip wijst nu naar iets random
	/*10*/ tp = t+2;		//ok 	tp wijst nu naar derde in t
	/*11*/ j = &t[5] - tp;	//ok 	50-30=20
	/*12*/ t++;				//fout	array kan je niet opschuiven
	/*13*/ (*t)++;			//ok	1ste in array wordt +1
	/*14*/ *tp--;			//fout	eerste vraag je pointer op en dan doe je 1 naar voor		
	/*15*/ j = (*tp)++;		//ok	tp is daarnet 1 naar voor en dan 1 plus dus 21
	/*16*/ i = *tp++;		//ok	i krijgt de waarde van *tp dus 21 daarna schuif je pointer op
	/*17*/ p1 = ip;			//ok	p1 belooft meer dan ip
	/*18*/ jp = p1;			//fout	je kan geen const wijzigen
	/*19*/ (*p1)--;			//fout	const mag je niet aanpassen
	/*20*/ dp = &i;			//fout	pointer naar double kan niet worden geinitialiseerd met een int
	/*21*/ dp = ip;			//fout	idem
	/*22*/ jp = p2;			//ok	p2 is const pointer maar die wijzigt niet 
	/*23*/ p2 = p1;			//fout	p2 is const pointer
	/*24*/ *p2 += i;		//ok	verdubbeld
	return 0;
}

