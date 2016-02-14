#ifndef species_
#define species_
class Species{
	char name_[20];
	int lifespan_;
	int health_;
	int gender_; //0 = male 1 = female
public:
		void set();
		void drastic();
		void breed(Species&);
		void mutate();


};
#endif