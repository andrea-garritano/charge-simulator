#ifndef GTKMM_EXAMPLE_CLOCK_H
#define GTKMM_EXAMPLE_CLOCK_H

#include <gtkmm/drawingarea.h>
#include "Charge.h"

class Container : public Gtk::DrawingArea
{
public:
  //Container();
  static Container* Instance();

  virtual ~Container();
  void set_line_width(double width);
  void set_n_charge(double info);
  double get_n_charge();

  void addCharges(Charge *V, int n)
  	{
  		C=V;
  		N=n;
  	}

private:
  static Container* _instance;

	Charge *C;
	int N;

protected:
  //Override default signal handler:
  Container();

  virtual bool on_expose_event(GdkEventExpose* event);

  bool on_timeout();

  double frame;
  double m_line_width;
  double charge;


};

#endif // GTKMM_EXAMPLE_CLOCK_H
