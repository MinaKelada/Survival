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
	injuredType_ = 0;
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
	char name[5];
	name[0] = a;
	if (seg < 10){
		name[1] = char(seg + 48);
		name[2] = 0;
	}
	else if (seg >= 10 && seg < 100){
		int frac1;
		int frac2;
		frac1 = seg % 10;
		seg /= 10;
		frac2 = seg % 10;
		name[1] = char(frac2+48);
		name[2] = char(frac1+48);
		name[3] = 0;
	}
	else if (seg >= 100){
		int frac1;
		int frac2;
		int frac3;
		frac1 = seg % 10;
		seg /= 10;
		frac2 = seg % 10;
		seg /= 10;
		frac3 = seg % 10;
		name[1] = char(frac3 + 48);
		name[2] = char(frac2 + 48);
		name[3] = char(frac1 + 48);
		name[4] = 0;
	}
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
			other.injury(strength_);
		}
		else{
			cout << other.name_ << " has run away" << endl;
		}
	}
	else if (strength_ < other.strength_){
		if (speed_ < other.speed_){
			
			cout << name_ << " lost " << other.strength_ << " health" << endl;
			reduceStats(0, other.strength_);
			injury(other.strength_);
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
		injury(other.strength_);
		other.reduceStats(0, strength_);
		other.injury(strength_);
	}

}
int Species::farm(){
	cout << name_ << " has decided to farm. ";
	food_ = food_ + rand() % 50;
	cout << "They now have " << food_ << " pieces of food" << endl;
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
		if (health_ <= 0){
			dead();
		}
	}
	else{
		cout << name_ << " has " << food_ << " left " << endl;
	}
	return 0;
}
void Species::injury(int strength){
	if (isNotDead()){
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
		if (injured_ > 0){
			cout << name_ << " has received an injury that affects their ";
			injuredType_ = 1 + rand() % 3; //recently changed, keep an eye on
			switch (injuredType_){
			case 1:
				cout << "strength";
				reduceStats(1, injuredAmount_);
				break;
			case 2:
				cout << "speed";
				reduceStats(2, injuredAmount_);
				break;
			case 3:
				cout << "intelligence";
				reduceStats(3, injuredAmount_);
				break;
			}
			cout << " by " << injuredAmount_ << " for " << injured_ << " year/s" << endl;
		}
	}
	
}
void Species::removeInjury(){
	cout << name_ << "'s injury has been removed." << endl;
	switch (injuredType_){
	case 1:
		increaseStats(1, injuredAmount_);
		cout << name_ << "'s strength is now " << strength_ << endl;
		break;
	case 2:
		increaseStats(2, injuredAmount_);
		cout << name_ << "'s speed is now " << speed_ << endl;
		break;
	case 3:
		increaseStats(3, injuredAmount_);
		cout << name_ << "'s intelligence is now " << intelligence_ << endl;
		break;
	}
	injuredType_ = 0;
	injuredAmount_ = 0;
}
void Species::heal(){
	if (isNotDead()){
		if (injured_ > 0){
			injured_--;
			if (injured_ == 0){
				removeInjury();
			}
		}
		increaseStats(0, 10);
		cout << name_ << " has healed! Their health is now " << health_ << endl;
	}

}
void Species::setEnvo(Environment& env){
	envo_ = env;
}
char* Species::displayName(){
	return name_;
}
ostream& Species::shortDisplayAtt(ostream& ost){
	ost << name_ << " of clan " << clan_ << " LifeSpan: " << lifespan_ << " Health: " << health_ << " " << (gender_ ? "Female" : "Male") << " Strength: " << strength_ << " Speed:" << speed_ << " Intelligence: " << intelligence_ << " Food: " << food_ << " ";
	return ost;
}
ostream& operator<<(ostream& ost, Species& set){
	return set.shortDisplayAtt(ost);
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
void Species::increaseStats(int type, int amount){
	switch (type){
	case 0:
		health_ += amount;
		break;
	case 1:
		strength_ += amount;
		break;
	case 2:
		speed_ += amount;
		break;
	case 3:
		intelligence_ += amount;
		break;
	}
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
				cout << nextGen[kid] << endl;
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
		for (i = 0; i < size; i++){ 
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
		injuredType_ = sam.injuredType_;
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
	void FightNight4(Species set1[], int size1, Species set2[], int size2, Species set3[], int size3, Species set4[], int size4){
		Species* contestant1;
		Species* contestant2;
		int contSize1;
		int contSize2;
		int select1 = 1 + rand() % 4;
		int select2 = 1 + rand() % 4;
		if (select1 == select2){
			select2++;
			if (select2 > 4){
				select2 = 3;
			}
		}
		switch (select1){
		case 1:
			contestant1 = set1;
			contSize1 = size1;
			break;
		case 2:
			contestant1 = set2;
			contSize1 = size2;
			break;
		case 3:
			contestant1 = set3;
			contSize1 = size3;
			break;
		case 4:
			contestant1 = set4;
			contSize1 = size4;
			break;
		default:
			cout << "No contestants selected in FightNight" << endl;
		}
		switch (select2){
		case 1:
			contestant2 = set1;
			contSize2 = size1;
			break;
		case 2:
			contestant2 = set2;
			contSize2 = size2;
			break;
		case 3:
			contestant2 = set3;
			contSize2 = size3;
			break;
		case 4:
			contestant2 = set4;
			contSize2 = size4;
			break;
		default:
			cout << "No contestants selected in FightNight" << endl;
		}
		int i;
		i = 0;
		if (!TotalDead(contestant1, contSize1) && !TotalDead(contestant2, contSize2)){
			while (i < contSize1 && i < contSize2){
				if (contestant1[i].isNotDead()){
					if (contestant2[i].isNotDead()){
						contestant1[i].fight(contestant2[i]);
					}
				}
				i++;
			}
		}
	}
	void Species::gather(){
		if (intelligence_ > 100){
			farm();
		}
		else{
			food_ = food_ + rand() % 20;
			cout << name_ << " has gathered food, they now have " << food_ << " pieces of food" << endl;
		}
	}
	bool TotalDead(Species* spec, int specSize){
		int i;
		bool dead = true;
		for (i = 0; i < specSize; i++){
			if (spec[i].isNotDead()){
				dead = false;
			}
		}
		return dead;
	}
	void fluSeason(Species* a1, int a1Size, Species* a2, int a2Size, Species* a3, int a3Size, Species* a4, int a4Size, Disease& dis){
		int select = 1 + rand() % 4;
		Species* unlucky;
		int uSize;
		switch (select){
		case 1:
			unlucky = a1;
			uSize = a1Size;
			break;
		case 2:
			unlucky = a2;
			uSize = a2Size;
			break; 
		case 3:
				unlucky = a3;
				uSize = a3Size;
				break;
		case 4:
			unlucky = a4;
			uSize = a4Size;
			break;
		default:
			cout << "No one selected in disease" << endl;
		}
		int i;
		for (i = 0; i < uSize; i++){
			dis.infect(unlucky[i]);
		}
	}
void tornadoSeason(Species* a1, int a1Size, Species* a2, int a2Size, Species* a3, int a3Size, Species* a4, int a4Size, Disaster& dis){
	int select = 1 + rand() % 4;
	Species* unlucky;
	int uSize;
	switch (select){
	case 1:
		unlucky = a1;
		uSize = a1Size;
		break;
	case 2:
		unlucky = a2;
		uSize = a2Size;
		break;
	case 3:
		unlucky = a3;
		uSize = a3Size;
		break;
	case 4:
		unlucky = a4;
		uSize = a4Size;
		break;
	default:
		cout << "No one selected in Disaster" << endl;
	}
	int i;
		for (i = 0; i < uSize; i++){
			dis.affect(unlucky[i]);
		}
	}
void lunch(Species* set, int size){
	int i;
	for (i = 0; i < size; i++){
		if (set[i].isNotDead()){
			set[i].age();
			if (set[i].isNotDead()){
				set[i].gather();
				set[i].feed();
			}
			if (set[i].isNotDead()){
				cout << set[i];
			}
		}
	}
}
void Species::age(){
	if (isNotDead()){
		lifespan_ -= 1;
		if (lifespan_ <= 0){
			cout << name_ << " died of old age." << endl;
			dead();
		}
	}
}