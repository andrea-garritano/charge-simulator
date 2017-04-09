#ifndef CHARGE_H_
#define CHARGE_H_

using namespace std;

class Charge {
public:
	Charge (){}
	Charge(float c, float sx, float sy, bool m, float dx, float dy) : charge(c), Sx(sx), Sy(sy), move(m), Dx(dx), Dy(dy) {};

	virtual ~Charge();

	float getDx(){
		return Dx;
	}

	float getDy(){
		return Dy;
	}
	void setDx(float x){
		Dx=x;
	}
	void setDy(float y){
		Dy=y;
	}
	float getSx(){
		return Sx;
	}

	float getSy(){
		return Sy;
	}
	void setSx(float x){
		Sx=x;
	}
	void setSy(float y){
		Sy=y;
	}
	void setCharge(float c){
		charge=c;
	}
	float getCharge(){
		return charge;
	}
	void setMove(bool m){
		move=m;
	}
	bool getMove(){
		return move;
	}
	void moving();
	void accelerate(Charge *V, int i, int n); //i posizione attuale


private:
	float Dx;
	float Dy;

	float Sx;
	float Sy;

	float charge;
	bool move;

	void speeding(float x, float y);
};

#endif
