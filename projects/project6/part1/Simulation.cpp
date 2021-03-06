#include"Simulation.h"
#include <iostream>
//using namespace std;
Simulation::Simulation()
{
}
Simulation::~Simulation()
{
}

void Simulation::simulate()
{
  Event curEvent = eventBuilder.createArrivalEvent(1);
  // cout << "Event" << currentEvent.getNumber() << endl;
  //  if(currentEvent.getNumber() != 0)
  // {
      events.add(curEvent);
      // }
  while( !events.isEmpty())
    {
      currentEvent = events.peek();
      if(currentEvent.getType() == ARRIVAL)
	{
	  processArrival();
	}
      else 
	{
	  processDeparture();
	}
      stats.addEvent(currentEvent);
    }
  stats.reportStats();
}


void Simulation::processArrival()
{
  bool first = line.isEmpty();
  //  cout << "Processing arrival ";
  line.enqueue(currentEvent);
  events.remove();
  if(first)
    {
      Event Dep = eventBuilder.createDepartureEvent(currentEvent.getTime(),
						    currentEvent.getLength(),
						    currentEvent.getNumber());
      events.add(Dep);
    }
  Event newArrival = eventBuilder.createArrivalEvent(currentEvent.getNumber()+1);
  if(newArrival.getNumber() != 0)
    {
      events.add(newArrival);
    }
}
void Simulation::processDeparture()
{
  line.dequeue();      
  events.remove();
  cout << line.isEmpty();
  if( !line.isEmpty())
    {
      Event Dep,done;
      done = line.peekFront();
      
      Dep = eventBuilder.createDepartureEvent(currentEvent.getTime(),
					      done.getLength(),
					      done.getNumber());
      events.add(Dep);
    }
}
      

