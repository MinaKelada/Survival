#include<iostream>
#include"Life.h"
#include"Species.h"
#include"Disease.h"
#include"Disaster.h"
#include"Environment.h"
using namespace std;
void Life::noUser(){
	int i;
	int year = 0;
	Environment a;
	Environment b;
	Environment c;
	Environment d;
	Disaster disaster;
	Disease disease;
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
		cout << a1[i];
		a1[i].displayEnvo();
	}
	for (i = 0; i < a2Size; i++){
		a2[i].setAIName('d', i);
		a2[i].setClan('d');
		a2[i].setEnvo(b);
		cout << a2[i];
		a2[i].displayEnvo();

	}
	for (i = 0; i < a3Size; i++){
		a3[i].setAIName('h', i);
		a3[i].setClan('h');
		a3[i].setEnvo(c);
		cout << a3[i];
		a3[i].displayEnvo();
	}
	for (i = 0; i < a4Size; i++){
		a4[i].setAIName('k', i);
		a4[i].setClan('k');
		a4[i].setEnvo(d);
		cout << a4[i];
		a4[i].displayEnvo();
		}
	while (!TotalDead(a1, a1Size) && !TotalDead(a2, a2Size) && !TotalDead(a3, a3Size) && !TotalDead(a4, a4Size)){
		year++;
		cout << "Year: " << year << endl;
		if (matingMinimum(a1, a1Size)){
			a1 = matingSeason(a1, a1Size);
		}
		if (matingMinimum(a2, a2Size)){
			a2 = matingSeason(a2, a2Size);
		}
		if (matingMinimum(a3, a3Size)){
			a3 = matingSeason(a3, a3Size);
		}
		if (matingMinimum(a4, a4Size)){
			a4 = matingSeason(a4, a4Size);
		}
		fluSeason(a1, a1Size, a2, a2Size, a3, a3Size, a4, a4Size, disease);
		tornadoSeason(a1, a1Size, a2, a2Size, a3, a3Size, a4, a4Size, disaster);
		FightNight4(a1, a1Size, a2, a2Size, a3, a3Size, a4, a4Size);
		disease.reset();
		disaster.reset();
	}
}
void Life::User(){

}