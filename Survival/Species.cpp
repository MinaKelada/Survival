#include<iostream>
#include"Species.h"
#include "Environment.h"
using namespace std;
Species::Species(){
	lifespan_ = rand() % 101;
	health_ = rand()% 101;
	gender_ = rand()% 2;
	food_ = 0;
	strength_ = rand()% 101;
	speed_ = rand()% 101;
	intelligence_ = rand() % 21;
	injured_ = 0;
	injuredAmount_ = 0;
	strcpy(name_, "");
}
Species::Species(Species& sam){
	copy(sam);
	cout << "enter con" << endl;
}
Species::Species(int lifespan, int health, int strength, int speed, int intelligence){
	lifespan_ = lifespan;
	health_ = health;
	gender_ = rand() % 2;
	food_ = 0;
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
Species Species::breed(const Species& guy){
	int lifespan = (lifespan_ + guy.lifespan_) / 2;
	int health = (health_ + guy.health_) / 2;
	int strength = (strength_ + guy.strength_) / 2;
	int speed = (speed_ + guy.speed_) / 2;
	int intelligence = (intelligence_ + guy.intelligence_) / 2;
	Species baby(lifespan, health, strength, speed, intelligence);
	//should add give environment to this
	return baby;

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
	cout << name_ << " " << lifespan_ << " " << health_ << " " << (gender_ ? "Female" : "Male") << " " << strength_ << " " << speed_ << " " << intelligence_ << endl;
}
void Species::longDisplayAtt(){
	cout << "Name is: " << name_ << endl;
	cout << "Lifespan is: " << lifespan_ << endl;
	cout << "Health is: " << health_ << endl;
	cout << "Gender is: " << (gender_ ? "Female": "Male") << endl; //switched sides of gender for this and short
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
	Species* matingSeason(Species set [], int& size){
		int i;
		int kid = 0;
		Species* total;
		Species* nextGen;
		nextGen = new Species[size];
		i = 0;
		while(i<size){ 
			if (set[i].getGender() == 1){
				cout << set[i].displayName() << "will breed with "<< endl;
				nextGen[kid] = set[i].select(set, size);
				nextGen[kid].setAIName(char(set[i].displayName()[0]+1), kid);  
				nextGen[kid].shortDisplayAtt();
				kid++;
				i++;
			}
			else{
				i++;
			}
		}	
		total = new Species[size + kid];
		i = 0;
		while (i < size){
			total[i] = set[i];
			total[i].shortDisplayAtt();
			i++;
		}
		int next = 0;
		size += kid; 
		while (i < (size)){
			total[i] = nextGen[next]; 
			total[i].shortDisplayAtt();
			i++;
			next++;     
		}
		delete [] nextGen;
		return total;
	}
	Species Species::select(Species set[], int size){
		int i;
		int pref = setPref();
		int keeper = -1;
		cout << "select" << endl;
		for (i = 0; i < size; i++){
			if (set[i].getGender() == 0){
				if (keeper < 0){
						keeper = i;
					}
				switch (pref){
				case 0:
					if (set[i].health_ > set[keeper].health_){
						keeper = i;
					}
				case 1:
					if (set[i].strength_ > set[keeper].strength_){
						keeper = i;
					}
				case 2:
					if (set[i].speed_ > set[keeper].speed_){
						keeper = i;
					}
				case 3:
					if (set[i].intelligence_ > set[keeper].intelligence_){
						keeper = i;
					}
				}
			}
		}
		Species baby = breed(set[keeper]);
		return baby;
	}
	int Species::getGender(){
		return gender_;
	}
	int Species::setPref(){
		int pref;
		if (health_ < strength_&& health_ < speed_&& health_ < intelligence_){
			pref = 0;
		}
		else if (strength_ < health_ && strength_ < speed_&& strength_ < intelligence_){
			pref = 1;
		}
		else if (speed_ < health_ && speed_ < strength_ && speed_ < intelligence_){
			pref = 2;
		}
		else if (intelligence_ < health_ && intelligence_ < speed_&& intelligence_ < strength_){
			pref = 3;
		}
		return pref;
	}
	Species& Species::operator=(Species& sam){
		copy(sam);
		cout << "entered operator" << endl;
		return *this;
	}
	Species& Species::copy(Species& sam){ //returning reference might be bad
		lifespan_ = sam.lifespan_;
		health_ = sam.health_;
		gender_ = sam.gender_;
		food_ = sam.food_;
		strength_ = sam.strength_;
		speed_ = sam.speed_;
		intelligence_ = sam.intelligence_;
		injured_ = sam.injured_;
		injuredAmount_ = sam.injuredAmount_;
		strcpy(name_, sam.name_);
		return *this;
	}