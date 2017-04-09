#include <ctime>
#include <cmath>
#include <cairomm/context.h>
#include "Container.h"
#include <iostream>


Container::Container()
{
  Glib::signal_timeout().connect( sigc::mem_fun(*this, &Container::on_timeout), 17 );

  #ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  //Connect the signal handler if it isn't already a virtual method override:
  signal_expose_event().connect(sigc::mem_fun(*this, &Charge::on_expose_event), false);
  #endif

}

float a=0, b=0, c=0;

Container::~Container()
{
}

Container* Container::_instance = 0;
Container* Container::Instance() {
	if ( _instance == 0 )
	{
	_instance =	new Container();
	}
	return _instance;
}


bool Container::on_expose_event(GdkEventExpose* event)
{
	Glib::RefPtr<Gdk::Window> window = get_window(); // Create the window
	  if(window)
	  {
		  Gtk::Allocation allocation = get_allocation();
				const int width = allocation.get_width();
				const int height = allocation.get_height();
			Cairo::RefPtr<Cairo::Context> cr = window->create_cairo_context();
			Cairo::RefPtr<Cairo::Context> cx = window->create_cairo_context();
		  	    if(event)
		  	    {
					//The area will be redrawn by the event
		  	        cr->rectangle(event->area.x, event->area.y,
		  	                event->area.width, event->area.height);
		  	        cr->clip();
		  	    }
				cr->scale(width, height);
				cr->translate(0, 0);
				cr->set_line_width(m_line_width);
				cr->set_source_rgb(0.0, 0.0, 0.0);
				cr->save();

				frame++;;

				for (int k=0;k<N;k++)
				{
					std::cout<<"carica "<<k<<": ("<<C[k].getDx()<<";"<<C[k].getDy()<<")"<<"("<<C[k].getSx()<<";"<<C[k].getSy()<<")"<<std::endl;
					std::cout<<"       "<<C[k].getCharge()<<std::endl;
				}

				for (int cont=0; cont<N; cont++)
				{
				    if (C[cont].getMove())
				    {
						   C[cont].accelerate(C,cont,N);
					}

				}
				for (int cont=0; cont<N; cont++)
				{
				   if (C[cont].getMove())
				   {
					   C[cont].moving();
				   }
				}

				for (int k=0; k<N; k++)
				{
					cr->save();

					// draw a circle
					cr->arc(C[k].getDx(), C[k].getDy(), 0.01, 0.0, 2 * M_PI); // full circle
					if (C[k].getCharge()>0.0)
					{
						cr->set_source_rgb(1.0, 0.0, 0.0);
					}
					if (C[k].getCharge()<0.0)
					{
						cr->set_source_rgb(0.0, 0.0, 1.0);
					}
					if (C[k].getCharge()==0.0)
					{
						cr->set_source_rgb(0.0, 1.0, 0.0);
					}
					cr->fill_preserve();
					cr->restore();  // back to opaque black
					cr->stroke();
				}

  }

  return true;
}


bool Container::on_timeout()
{
    // force our program to redraw the window
    Glib::RefPtr<Gdk::Window> win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(),
                get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
    return true;
}

void Container::set_line_width(double width)
{
	m_line_width =  width;
}


