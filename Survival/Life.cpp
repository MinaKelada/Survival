#include<iostream>
#include"Life.h"
#include"Species.h"
#include"Disease.h"
#include"Disaster.h"
#include"Environment.h"

void Life::test(){
	//testing give environment functions comprehensively
	Species e1[5];
	Environment en;
	en.setEnv();
	int i = 0;
	en.display();
	Disease d;
	while (i < 5)
	{
		en.giveEnvironment(e1[i]);
		e1[i].setAIName('e', i);
		e1[i].longDisplayAtt();
		e1[i].displayEnvo();
		d.infect(e1[i]);
		e1[i].longDisplayAtt();
		i++;
	}
	//en.setEnv();
	//en.display();
	//e1[0].displayEnvo();
	//end testing
}