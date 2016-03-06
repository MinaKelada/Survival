#include<iostream>
#include"Tester.h"
#include"Species.h"
#include"Disease.h"
#include"Disaster.h"
#include"Environment.h"
using namespace std;
void Tester::genTest(){
	//testing give environment functions comprehensively
	Species* e1 = new Species[5];
	Environment en;
	en.setEnv();
	giveClan('b', e1, 5);
	int i = 0;
	//en.display();
	int size = 5;

	while (i < 5)
	{
		en.giveEnvironment(e1[i]);
		e1[i].setAIName('z', i);
		e1[i].shortDisplayAtt();

	//	e1[i].displayEnvo();
	//	e1[i].shortDisplayAtt();
	//	//c.affect(e1[i]);
	//	//c.reset();
	//	e1[i].shortDisplayAtt();
		i++;	
	}
	e1 = matingSeason(e1, size);
	cout << "end of mating season" << endl;

	/*i = 0;
	while (i < size){
		e1[i].shortDisplayAtt(); 
		i++;
	}*/
	e1 = matingSeason(e1, size);
	cout << "end of mating season" << endl;
	i = 0;
	while (i < size){
		e1[i].shortDisplayAtt();
		i++;
	}
	delete[] e1;
	//Species sam;
	//sam.setAIName('a', 1);
	//sam.shortDisplayAtt();
	//for (int i = 0; i < 1; i++){
	//	Species Sammy;
	//	Sammy.setAIName('a', 2);
	//	Sammy.shortDisplayAtt();
	//	sam = Sammy;
	//}
	//
	//sam.shortDisplayAtt();
	//Species test[5];
	//int size = 5;
	//matingSeason(test, size);
	cout << "end program" << endl; //program crashes after this as well
	//en.setEnv();
	//en.display();
	//e1[0].displayEnvo();
	//end testing*/
}
void Tester::feedTest(){
	Species e1;
	e1.setAIName('i', 1);
	e1.setClan('u');
	e1.longDisplayAtt();
	e1.feed();
	e1.longDisplayAtt();
}