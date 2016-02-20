#include<iostream>
#include"Disease.h"
#include"Species.h"
using namespace std;
		Disease::Disease(){
			reset();
		}
		void Disease::reset(){
			strength_ = rand() % 21;
			contagious_ = rand() % 50;
			affects_ = rand() % 4; //0 = health, 1 = strength, 2 = speed, 3 intelligence
			switch (affects_){
			case 0:
				strcpy(affectH_, "health");
				break;
			case 1:
				strcpy(affectH_, "strength");
				break;
			case 2:
				strcpy(affectH_, "speed");
				break;
			case 3:
				strcpy(affectH_, "intelligence");
				break;
			}
		}
	void Disease::infect(Species& C){
		bool infected = 0;
		int chance = rand() % 101;
		if (contagious_ > chance){
			infected = 1;
		}
		if (infected){
			cout << C.displayName() << " " << "has been infected" << endl;
			cout << "This reduces " << C.displayName() << "'s " << affectH_ << " by " << strength_ << endl;
			C.reduceStats(affects_,strength_);
		}
	
	}