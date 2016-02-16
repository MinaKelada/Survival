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
	Environment envo_;
public:
		Species();
		void drastic();
		void breed(Species&);
		void mutate();
		void fight(Species&);
		int farm();
		int feed();
		void change();
		void injury();
		void heal();
		void setEnvo(Environment&);
		void dead();
		void displayName();
		void displayAtt();
		void displayEnvo();
};
#endif