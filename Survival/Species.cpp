#include<iostream>
#include"Species.h"
#include "Environment.h"
using namespace std;
void Species::randSet(){
	lifespan_ = rand() % 101;
	health_ = rand() % 101;
	gender_ = rand() % 2;
	food_ = rand()% 101;
	strength_ = rand() % 101;
	speed_ = rand() % 101;
	intelligence_ = rand() % 21;
	injured_ = 0;
	injuredAmount_ = 0;
	strcpy(name_, "");
}
Species::Species(){
	randSet();
}
void giveClan(char clan, Species* set, int size){
	int i;
	i = 0;
	while (i < size){
		set[i].setClan(clan);
		i++;
	}
}
void Species::setClan(char clan){
	clan_ = clan;
}
Species::Species(Species& sam){
	copy(sam);
}
char Species::clanDisplay(){
	return clan_;
}
Species::Species(int lifespan, int health, int strength, int speed, int intelligence, int food){
	lifespan_ = lifespan;
	health_ = health;
	gender_ = rand() % 2;
	food_ = food;
	strength_ = strength;
	speed_ = speed;
	intelligence_ = intelligence;
	injured_ = 0;
	injuredAmount_ = 0;
	strcpy(name_, "");
	
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
Species* Species::breed(Species& guy){
	cout << displayName() << " has decided to breed with " << guy.displayName() << endl;
	int lifespan = (lifespan_ + guy.lifespan_) / 2;
	int health = (health_ + guy.health_) / 2;
	int strength = (strength_ + guy.strength_) / 2;
	int speed = (speed_ + guy.speed_) / 2;
	int intelligence = (intelligence_ + guy.intelligence_) / 2;
	guy.food_ = guy.food_ / 2;
	food_ = food_ / 2;
	int food = food_ + guy.food_;
	Species* baby = new Species(lifespan, health, strength, speed, intelligence, food);
	guy.envo_.giveEnvironment(*baby);
	baby->setClan(clan_);
	return baby;
}
void Species::mutate(){

}
void Species::fight(Species& other){
	cout << name_ << " has gotten into a fight with " << other.name_ << endl;
	if (other.strength_ < strength_){
		if (other.speed_ < speed_){
			cout << other.name_ << " lost " << strength_ << " health" << endl;
			other.reduceStats(0, strength_);

		}
		else{
			cout << other.name_ << " has run away" << endl;
		}
	}
	else if (strength_ < other.strength_){
		if (speed_ < other.speed_){
			
			cout << name_ << " lost " << other.strength_ << " health" << endl;
			reduceStats(0, other.strength_);
		}
		else{
			cout << name_ << " has run away" << endl;
		}
	}
	else{
		
		cout << name_ << " and " << other.name_ << " have traded blows" << endl;
		cout << name_ << ": Health:" << health_ << endl;
		cout << other.name_ << ": Health:" << other.health_ << endl;
		reduceStats(0, other.strength_);
		other.reduceStats(0, strength_);
	}

}
int Species::farm(){
	return 0;

}
int Species::feed(){
	int bmr = strength_ / 2;
	int damage = 0;
	cout << name_ << " needs to eat " << bmr << " units of food" << endl;
	food_ = food_ - bmr;
	if (food_ <= 0){
		damage = food_ * -1;
		cout << name_ << " does not have enough food. Lost " << damage << " health" << endl;
		food_ = 0;
		health_ = health_ - damage;
	}
	else{
		cout << name_ << " has " << food_ << " left " << endl;
	}
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
	cout << name_ << " of clan " << clan_ << " " << lifespan_ << " " << health_ << " " << (gender_ ? "Female" : "Male") << " " << strength_ << " " << speed_ << " " << intelligence_ << " " << food_ << endl;
}
void Species::longDisplayAtt(){
	cout << "Name is: " << name_ << " of clan " << clan_ << endl;
	cout << "Lifespan is: " << lifespan_ << endl;
	cout << "Health is: " << health_ << endl;
	cout << "Gender is: " << (gender_ ? "Female": "Male") << endl; //switched sides of gender for this and short
	cout << "Strength is: " << strength_ << endl;
	cout << "Speed is: " << speed_ << endl;
	cout << "Intelligence is: " << intelligence_ << endl;
	cout << "Food: " << food_ << endl;
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
	Species* matingSeason(Species* set, int& size){
		int i;
		int kid = 0;
		Species* total;
		Species* nextGen;
		nextGen = new Species[size];
		i = 0;
		while(i<size){ 
			if (set[i].getGender() == 1 && set[i].isNotDead()){
				Species* baby;
				baby = set[i].select(set, size);
				nextGen[kid] = *baby;
				delete baby;
				char name = char(set[size - 1].displayName()[0] + 1);
				if (name == '{'){
					name = 'A';
				}
				nextGen[kid].setAIName(name, kid);  
				cout << set[i].displayName() << " has given birth to: ";
				nextGen[kid].shortDisplayAtt();
				kid++;
				i++;
			}
			else{
				i++;
			}
		}	
		Species* oldGen = new Species[size];
		i = 0;
		while (i < size){
			oldGen[i] = set[i];
			i++;
		}
		delete[] set;
		total = new Species[size + kid];
		i = 0;
		while (i < size){
			total[i] = oldGen[i];
			i++;
		}
		int next = 0;
		size += kid; 
		while (i < (size)){
			total[i] = nextGen[next]; 
			i++;
			next++;     
		}
		delete [] oldGen; 
		delete [] nextGen;
		return total;
		//this code is giving back the pointer that it just destroyed so the pointer that was given to it has to equal this function
		//or it will return a debug error because you're deleting something which no longer exists
	}
	Species* Species::select(Species set[], int size){
		int i;
		int pref = setPref();
		int keeper = -1;
		for (i = 0; i < size; i++){ //program seems unable to handle all females
			if (set[i].getGender() == 0 && set[i].isNotDead()){
				if (keeper < 0){
						keeper = i;
					}
				switch (pref){
				case 0:
					if (set[i].health_ > set[keeper].health_){
						keeper = i;
					}
					break;
				case 1:
					if (set[i].strength_ > set[keeper].strength_){
						keeper = i;
					}
					break;
				case 2:
					if (set[i].speed_ > set[keeper].speed_){
						keeper = i;
					}
					break;
				case 3:
					if (set[i].intelligence_ > set[keeper].intelligence_){
						keeper = i;
					}
					break;
				}
			}
		}

		Species* baby = breed(set[keeper]);
		return baby;
	}
	int Species::getGender(){
		return gender_;
	}
	int Species::setPref(){
		int pref = 0; //can sometimes go through without being defined. Believe it's due to equal values
		if (health_ <= strength_&& health_ <= speed_&& health_ <= intelligence_){
			pref = 0;
		}
		else if (strength_ <= health_ && strength_ <= speed_&& strength_ <= intelligence_){
			pref = 1;
		}
		else if (speed_ <= health_ && speed_ <= strength_ && speed_ <= intelligence_){
			pref = 2;
		}
		else if (intelligence_ <= health_ && intelligence_ <= speed_&& intelligence_ <= strength_){
			pref = 3;
		}
		return pref;
	}
	Species& Species::operator=(Species& sam){
		copy(sam);
		return *this;
	}
	Species& Species::copy(Species& sam){ 
		lifespan_ = sam.lifespan_;
		health_ = sam.health_;
		gender_ = sam.gender_;
		food_ = sam.food_;
		strength_ = sam.strength_;
		speed_ = sam.speed_;
		intelligence_ = sam.intelligence_;
		injured_ = sam.injured_;
		injuredAmount_ = sam.injuredAmount_;
		sam.envo_.giveEnvironment(*this);
		strcpy(name_, sam.name_);
		clan_ = sam.clan_;
		return *this;
	}
	bool Species::isNotDead(){
		return lifespan_ != 0;
	}
	bool matingMinimum(Species set[], int size){
		int i = 0;
		bool male = false;
		while (i < size){
			if (set[i].getGender() == 0 && set[i].isNotDead()){
				male = true;
			}
			i++;
		}
		return male;
	}
	