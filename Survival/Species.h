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
		Species breed(Species& guy); 
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
		bool isNotDead();
}; //crashes at random, "stack corrupted around baby"
//https://social.msdn.microsoft.com/Forums/vstudio/en-US/14e7318e-6fff-4d68-a823-9cbe7b7bc20a/debugging-runtime-check-failure-2-stack-around-the-variable-loggerthread-was-corrupted?forum=vcgeneral
Species* matingSeason(Species set[], int& size);
void giveClan(char clan, Species* set, int size);
#endif