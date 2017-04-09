#include <iostream>
#include "Charge.h"
#include "Container.h"
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <string>

int main(int argc, char** argv)
{

	int number_experiment, number_charge;
	cout<<"Simulatore di cariche elettriche di Stefano Moretto & Andrea Garritano"<<endl;
	cout<<" 1) Rotazione di due cariche elettriche"<<endl<<
			" 2) Orbita ellittica con due cariche elettriche"<<endl<<
			" 3) Orbita circolare con due cariche elettriche"<<endl<<
			" 4) Orbita doppia con tre cariche"<<endl<<
			" 5) Metronomo"<<endl<<
			" 6) Orbita intorno a due cariche"<<endl<<
			" 7) Relax"<<endl<<
			" 0) Custom"<<endl;
	cin>>number_experiment;
	//number_experiment=1;
	switch (number_experiment)
	{
	case 2:
	case 3:
		number_charge=2;
		break;
	case 1:
	case 4:
	case 5:
	case 6:
		number_charge=3;
		break;
	case 0:
		cout<<"Numero di cariche: ";
		cin>>number_charge;
		break;
	case 7:
			number_charge=8;
			break;
	}

	Charge V[number_charge];

switch(number_experiment){
    case 1: //rotazione
		V[0]= Charge(1, 0.0004, -0.0095, true, 0.45, 0.1);
		V[1]= Charge(-1, 0.0004, 0.0105, true, 0.15, 0.1);
		V[2]= Charge(0, 0.0004, 0.0005, true, 0.3, 0.1);
		break;
	case 2: //orbita ellittica
		V[0]= Charge(1, 0, 0, false, 0.5, 0.5);
		V[1]= Charge(-1, 0, -0.01, true, 0.1, 0.5);
		break;
	case 3: //orbita perfetta
		V[0]= Charge(1, 0, 0, false, 0.5, 0.5);
		V[1]= Charge(-1, 0, -0.015, true, 0.1, 0.5);
		break;
	case 4: //tre cariche
		V[0]= Charge(2, 0, 0, false, 0.5, 0.5);
		V[1]= Charge(-1, 0, -0.0269, true, 0.2, 0.5);
		V[2]= Charge(-1, 0, -0.0269, true, 0.8, 0.5);
		break;

	case 6: //tre cariche

		V[0]= Charge(1, 0, 0, false, 0.3, 0.5);
		V[1]= Charge(-1, 0.021, 0, true, 0.3, 0.3);
		V[2]= Charge(1, 0, 0, false, 0.7, 0.5);
		break;

	case 5: //metronomo
		V[0]= Charge(1, 0, 0, false, 0.5, 0.3);
		V[1]= Charge(-1, 0.035, 0, true, 0.5, 0.5);
		V[2]= Charge(1, 0, 0, false, 0.5, 0.7);
		break;
	case 0: //custom
		for (int cont=0; cont<number_charge; cont++)
		{
			float quantity_charge, xo, yo, Sxo, Syo;
			bool move;
			string sn;
			cout<<"\n Valore della carica: ";
			cin>>quantity_charge;
			cout<<"Coordinate [0->10]:"<<endl<<
					"x: ";
			cin>>xo;
			cout<<"y: ";
			cin>>yo;
			xo=xo/10;
			yo=yo/10;
			cout<<"Mobile? (s/n)";
			cin>>sn;
			if (!sn.compare("s"))
			{
				move=true;
				cout<<"Velocita' [0->10]:"<<endl<<
						"x: ";
				cin>>Sxo;
				cout<<"y: ";
				cin>>Syo;
				Sxo=Sxo/1000;
				Syo=Syo/1000;
			}
			else
			{
				move=false;
				Sxo=0;
				Syo=0;
			}
			V[cont]= Charge(quantity_charge, Sxo, Syo, move, xo, yo);
		}
		break;
	case 7:
			V[0]= Charge(0.01, 0, 0, true, 0.7, 0.7);
			V[1]= Charge(0.01, 0, 0, true, 0.3, 0.3);
			V[2]= Charge(0.01, 0, 0, true, 0.7, 0.3);
			V[3]= Charge(0.01, 0, 0, true, 0.3, 0.7);

			V[4]= Charge(0.1, 0, 0, true, 0.5, 0.3);
			V[5]= Charge(0.1, 0, 0, true, 0.3, 0.5);
			V[6]= Charge(0.1, 0, 0, true, 0.7, 0.5);
			V[7]= Charge(0.1, 0, 0, true, 0.5, 0.7);

			//V[2]= Charge(0, 0.002, 0, true, 0.2, 0.5);
			break;
}


	cout<<"Debug";

	Gtk::Main kit(argc, argv);

	Gtk::Window win;
	switch (number_experiment)
		{
		case 1:
			win.set_title("Charge Simulator - Rotazione di due cariche elettriche");
			break;
		case 2:
			win.set_title("Charge Simulator - Orbita ellittica con due cariche elettriche");
			break;
		case 3:
			win.set_title("Charge Simulator - Orbita circolare con due cariche elettriche");
			break;
		case 4:
			win.set_title("Charge Simulator - Orbita doppia con tre cariche");
			break;
		case 5:
			win.set_title("Charge Simulator - Metronomo");
			break;
		case 6:
			win.set_title("Charge Simulator - Orbita intorno a due cariche");
			break;
		case 0:
			win.set_title("Charge Simulator - Custom");
			break;
		case 7:
			win.set_title("Charge Simulator - Relax");
			break;
		}

	win.set_default_size(700, 700);

	Container *c;
	c=Container::Instance();
	c->addCharges(V, number_charge);
	c->set_line_width(0.01);
	win.add(*c);
	c->show();

	Gtk::Main::run(win);


   return 0;
}
