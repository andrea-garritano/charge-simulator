/*
 * Charge.cpp
 *
 *  Created on: 15/mag/2012
 *      Author: andrea
 */

#include "Charge.h"
#include <cmath>



Charge::~Charge() {
	// TODO Auto-generated destructor stub
}


void Charge::moving(){
	Dx=(Dx+Sx);
	Dy=(Dy+Sy);

	while (Dx<0)
	{
		Dx++;
	}
	while (Dx>1)
	{
		Dx--;
	}

	while (Dy<0)
	{
		Dy++;
	}
	while (Dy>1)
	{
		Dy--;
	}
}

void Charge::speeding(float x,float y){
	setSx(Sx+x);
	setSy(Sy+y);
}

void Charge::accelerate (Charge *V, int i, int n)
{
	float Ax[n], Ay[n];
	float ax=0, ay=0;
	float distance, force, direction;

	for (int cont=0; cont<n; cont++)
	{
		if (cont==i)
		{
			Ax[cont]=0;
			Ay[cont]=0;
		}
		else
		{
			distance=pow(V[i].getDx()-V[cont].getDx(),2) +
					pow(V[i].getDy()-V[cont].getDy(),2);
			force=V[i].getCharge()*V[cont].getCharge()/(distance*10000);

			direction=atan((V[i].getDy()-V[cont].getDy())/(V[i].getDx()-V[cont].getDx()));

			if ((V[i].getDx()-V[cont].getDx())<0)
			{
				direction=direction+M_PI;
			}
			Ax[cont]=force*cos(direction);
			Ay[cont]=force*sin(direction);
		}
	}



	for (int cont=0; cont<n; cont++)
	{
		ax=ax+Ax[cont];
		ay=ay+Ay[cont];
	}
	speeding(ax,ay);
}
