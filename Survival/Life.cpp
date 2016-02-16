#include<iostream>
#include"Life.h"
#include"Species.h"
#include"Disease.h"
#include"Disaster.h"
#include"Environment.h"

void Life::start(){
	Species e1[5];
	Environment en;
	en.setEnv();
	int i = 0;
	
	while (i < 5)
	{
		en.giveEnvironment(e1[i]);
		e1[i].displayAtt();
		e1[i].displayEnvo();
		i++;
	}
}