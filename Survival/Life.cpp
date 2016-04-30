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
	//initial sets of environments, disease, and disaster
	Environment a;
	Environment b;
	Environment c;
	Environment d;
	Disaster disaster;
	Disease disease;
	//random amount of species objects in each array
	int a1Size = 1 + rand() % 10;
	Species* a1 = new Species[a1Size];
	int a2Size = 1 + rand() % 10;
	Species* a2 = new Species[a2Size];
	int a3Size = 1 +rand() % 10;
	Species* a3 = new Species[a3Size];
	int a4Size = 1 + rand() % 10;
	Species* a4 = new Species[a4Size];
	//sets names for all species objects
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
	while (!TotalDead(a1, a1Size) && !TotalDead(a2, a2Size) && !TotalDead(a3, a3Size) && !TotalDead(a4, a4Size) && year < 10){
		//while loop runs until one species goes extinct or ten years pass
		//ten years function added to ensure that the objects are deleted after
		year++;
		cout << "Year: " << year << endl;
		//feeding, healing, and aging
		lunch(a1, a1Size);
		restUp(a1, a1Size); // added in because I believe heal function has not been used in program yet
		lunch(a2, a2Size);
		restUp(a2, a2Size);
		lunch(a3, a3Size);
		restUp(a3, a3Size);
		lunch(a4, a4Size);
		restUp(a4, a4Size);
		//mating
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
		//disease
		fluSeason(a1, a1Size, a2, a2Size, a3, a3Size, a4, a4Size, disease);
		//disaster
		tornadoSeason(a1, a1Size, a2, a2Size, a3, a3Size, a4, a4Size, disaster);
		//fight
		FightNight4(a1, a1Size, a2, a2Size, a3, a3Size, a4, a4Size);
		//resets disease and disaster so the same objects can used through the while loop
		disease.reset();
		disaster.reset();
	}
	//if statements to give info for why the simulation ended
	if (TotalDead(a1, a1Size)){
		cout << "First species (a1, clan a) is extinct" << endl;
	}
	if (TotalDead(a2, a2Size)){
		cout << "Second species (a2, clan d) is extinct" << endl;
	}
	if (TotalDead(a3, a3Size)){
		cout << "Third species (a3, clan h) is extinct" << endl;
	}
	if (TotalDead(a4, a4Size)){
		cout << "Fourth species (a4, clan k) is extinct" << endl;
	}
	if (year >= 10){
		cout << "Simulation lasted longer than 10 years" << endl;
	}
	delete[] a1;
	delete[] a2;
	delete[] a3;
	delete[] a4;
	cout << "End of Simulation" << endl;
}
void Life::User(){
	//maybe written at a later date to turn this simulation into a game similar to oregan trail
}