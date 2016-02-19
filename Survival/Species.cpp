#include<iostream>
#include"Species.h"
#include "Environment.h"
using namespace std;
Species::Species(){
	lifespan_ = rand() % 101;
	health_ = rand()% 101;
	gender_ = rand()% 2;
	strength_ = rand()% 101;
	speed_ = rand()% 101;
	intelligence_ = rand() % 21;
}
void Species::setAIName(char a, int seg){
	char name[3];
	name[0] = a;
	name[1] = char(seg+48);
	name[2] = 0;
	strcpy(name_, name);
}
void Species::drastic(){

}
void Species::breed(Species&){

}
void Species::mutate(){

}
void Species::fight(Species&){

}
int Species::farm(){
	return 0;

}
int Species::feed(){
	return 0;

}
void Species::change(){
	
}
void Species::injury(){

}
void Species::heal(){

}
void Species::setEnvo(Environment& env){
	envo_ = env;
}
char* Species::displayName(){
	return name_;
}
void Species::shortDisplayAtt(){
	cout << name_ << " " << lifespan_ << " " << health_ << " " << (gender_ ? "Male" : "Female") << " " << strength_ << " " << speed_ << " " << intelligence_ << endl;
}
void Species::longDisplayAtt(){
	cout << "Name is: " << name_ << endl;
	cout << "Lifespan is: " << lifespan_ << endl;
	cout << "Health is: " << health_ << endl;
	cout << "Gender is: " << (gender_ ? "Male": "Female") << endl;
	cout << "Strength is: " << strength_ << endl;
	cout << "Speed is: " << speed_ << endl;
	cout << "Intelligence is: " << intelligence_ << endl;
}
void Species::displayEnvo(){
	envo_.display();
}
void Species::reduceStats(int type, int amount){
	switch (type){
	case 0:
		health_ -= amount;
		if (health_ <= 0){
			dead();
		}
		break;
	case 1:
		strength_ -= amount;
		if (strength_<= 0){
			strength_ = 0;
		}
		break;
	case 2:
		speed_ -= amount;
		if (speed_ <= 0){
			speed_ = 0;
		}
		break;
	case 3:
		intelligence_ -= amount;
		if (intelligence_ <= 0){
			speed_ = 0;
		}
		break;
	}
}
void Species::dead(){
	cout << name_ << " is dead" << endl;
	lifespan_ = 0;
	health_ = 0;
	food_ = 0;
	strength_ = 0;
	speed_ = 0;
	intelligence_ = 0;
}
