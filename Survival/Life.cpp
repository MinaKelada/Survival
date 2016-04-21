#include<iostream>
#include"Life.h"
#include"Species.h"
#include"Disease.h"
#include"Disaster.h"
#include"Environment.h"
using namespace std;
void Life::noUser(){
	int i;
	Environment a;
	Environment b;
	Environment c;
	Environment d;
	int a1Size = rand() % 20;
	Species* a1 = new Species[a1Size];
	int a2Size = rand() % 20;
	Species* a2 = new Species[a2Size];
	int a3Size = rand() % 20;
	Species* a3 = new Species[a3Size];
	int a4Size = rand() % 20;
	Species* a4 = new Species[a4Size];
	for (i = 0; i < a1Size; i++){
		a1[i].setAIName('a', i);
		a1[i].setClan('a');
		a1[i].setEnvo(a);
		a1[i].longDisplayAtt();
		a1[i].displayEnvo();
	}
	for (i = 0; i < a2Size; i++){
		a2[i].setAIName('d', i);
		a2[i].setClan('d');
		a2[i].setEnvo(b);
		a2[i].longDisplayAtt();
		a2[i].displayEnvo();

	}
	for (i = 0; i < a3Size; i++){
		a3[i].setAIName('h', i);
		a3[i].setClan('h');
		a3[i].setEnvo(c);
		a3[i].longDisplayAtt();
		a3[i].displayEnvo();

	}
	for (i = 0; i < a4Size; i++){
		a4[i].setAIName('k', i);
		a4[i].setClan('k');
		a4[i].setEnvo(d);
		a4[i].longDisplayAtt();
		a4[i].displayEnvo();

	}
}
void Life::User(){

}