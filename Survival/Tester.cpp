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
		cout << e1[i];

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
		cout << e1[i];
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
void Tester::deadBreed(){
	Species* e1 = new Species[5];
	Environment en;
	en.setEnv();
	giveClan('b', e1, 5);
	

	int i = 5;
	int x = 0;
	while(x < 5){
		en.giveEnvironment(e1[x]);
		e1[x].setAIName('i', x);
		e1[x].setClan('u');
		x++;
	}
	e1[2].dead();
	if (matingMinimum(e1, 5)){
		e1 = matingSeason(e1, i);
	}

	x = 0;
	while (x < i){
		cout << e1[x];
		x++;
	}
	delete [] e1;
	cout << "end program" << endl;
}
void Tester::fightTest(){
	Species one;
	Species two;
	one.setAIName('x', 0);
	one.setClan('x');
	two.setAIName('z', 0);
	two.setClan('z');
	one.longDisplayAtt();
	two.longDisplayAtt();
	one.fight(two);
	one.longDisplayAtt();
	two.longDisplayAtt();
}
void Tester::FightNightTest(){
	Species* e1 = new Species[7];
	int size1 = 7;
	Species* e2 = new Species[7];
	int size2 = 7;
	Species* e3 = new Species[7];
	int size3 = 7;
	Species* e4 = new Species[7];
	int size4 = 7;
	int i;
	i = 0;
	while (i < 7){
		e1[i].setAIName('k', i);
		e1[i].setClan('z');
		e2[i].setAIName('a', i);
		e2[i].setClan('v');
		e3[i].setAIName('c', i);
		e3[i].setClan('s');
		e4[i].setAIName('u', i);
		e4[i].setClan('n');
		i++;
	}
	FightNight4(e1, size1, e2, size2, e3, size3, e4, size4);
	i = 0;
	while (i < 7){
		e1[i].heal();
		e2[i].heal();
		e3[i].heal();
		e4[i].heal();
		i++;
	}
}