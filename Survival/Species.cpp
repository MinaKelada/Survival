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
	injured_ = 0;
	injuredAmount_ = 0;
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
void Species::injury(int strength){
	if (strength <= 10){
		injured_ = 1;
		injuredAmount_ = 3;
	}
	else if (strength <= 20 && strength >= 10){
		injured_ = 2;
		injuredAmount_ = 6;
	}
	else if (strength <= 30 && strength >= 20){
		injured_ = 3;
		injuredAmount_ = 9;
	}
	cout << name_ << " has received an injury that affects their ";
	switch (rand() % 3){
	case 0:
		cout << "strength";
		reduceStats(1, injuredAmount_);
		break;
	case 1:
		cout << "speed";
		reduceStats(2, injuredAmount_);
		break;
	case 2:
		cout << "intelligence";
		reduceStats(3, injuredAmount_);
		break;
	}
	cout << "  by " << injuredAmount_ << " for " << injured_ << " year/s" << endl;
	
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
			intelligence_ = 0;
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
int Species::getSpeed(){
	return speed_;
}
void Species::reduceStats(int strength){
	health_ -= strength;
	if (health_ <= 0){
		dead();
	}
	else if (rand() % 31 > 15){
		injury(strength);
	}
	
}
	int Species::getType()const {
		return envo_.getType();
	}
