#ifndef species_
#define species_
#include"Environment.h"
class Species{
	char name_[30];
	int lifespan_;
	int health_;
	int food_;
	int gender_; //0 = male 1 = female
	int strength_;
	int speed_;
	int intelligence_;
	int injured_;
	int injuredAmount_;
	int injuredType_;
	char clan_;
	Environment envo_;
public:
		Species();
		Species(Species&);
		void setClan(char clan);
		void randSet();
		char clanDisplay();
		Species(int lifespan, int health_, int strength, int speed, int intelligence, int food);
		void drastic();
		Species* breed(Species& guy); 
		void mutate();
		void fight(Species&);
		int farm();
		int feed();
		void injury(int strength);
		void heal();
		void setEnvo(Environment&);
		void dead();
		char* displayName();
		void shortDisplayAtt();
		void longDisplayAtt();
		void displayEnvo();
		void setAIName(char a, int seg);
		void reduceStats(int type, int amount);
		int getSpeed();
		void reduceStats(int strength);
		int getType() const;
		Species* select(Species set [], int size);
		int getGender();
		int setPref();
		Species& operator=(Species&);
		Species& copy(Species&);
		bool isNotDead();
		void gather();
}; 	
bool matingMinimum(Species set[], int size);
Species* matingSeason(Species set[], int& size);
void giveClan(char clan, Species* set, int size);
void FightNight4(Species set1[], int size1, Species set2[], int size2, Species set3[], int size3, Species set4[], int size4);
#endif