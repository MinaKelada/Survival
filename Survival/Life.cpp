#include<iostream>
#include"Life.h"
#include"Species.h"
#include"Disease.h"
#include"Disaster.h"
#include"Environment.h"
using namespace std;
void Life::test(){
	//testing give environment functions comprehensively
	Species e1[5];
	Environment en;
	en.setEnv();
	int i = 0;
	en.display();
	Species* total;
	int size = 5;

	while (i < 5)
	{
		en.giveEnvironment(e1[i]);
		e1[i].setAIName('e', i);
		e1[i].shortDisplayAtt();
		e1[i].displayEnvo();
		e1[i].shortDisplayAtt();
		//c.affect(e1[i]);
		//c.reset();
		e1[i].shortDisplayAtt();
		i++;	
	}
	total = matingSeason(e1, size);
	i = 0;
	while (i < size){
		total[i].shortDisplayAtt(); 
		i++;
	}
	delete[] total;
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