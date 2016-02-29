#ifndef species_
#define species_
#include"Environment.h"
class Species{
	char name_[20];
	int lifespan_;
	int health_;
	int food_;
	int gender_; //0 = male 1 = female
	int strength_;
	int speed_;
	int intelligence_;
	int injured_;
	int injuredAmount_;
	Environment envo_;
public:
		Species();
		Species(Species&);
		Species(int lifespan, int health_, int strength, int speed, int intelligence);
		void drastic();
		Species breed(const Species& guy);
		void mutate();
		void fight(Species&);
		int farm();
		int feed();
		void change();
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
		Species select(Species set [], int size);
		int getGender();
		int setPref();
		Species& operator=(Species&);
		Species& copy(Species&);
}; //still attempting to debug breeding functions and all functions related to it. delete [] nextGen in Species.cpp breaks code
//program only continues for a little while longer if delte is commented out
//also stops at e2 will breed
Species* matingSeason(Species set[], int& size);
#endif