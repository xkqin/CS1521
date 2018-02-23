#ifndef _SIMULATION
#define _SIMULATION

#include "Event.h"
#include "EventBuilder.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"
#include "Statistics.h"

class Simulation {
private:
   Event currentEvent;
   EventBuilder eventBuilder;
   LinkedQueue<Event> line1;
   LinkedQueue<Event> line2;
   LinkedQueue<Event> line3;
   PriorityQueue<Event> events;
   PriorityQueue<Event> events1;
   Statistics stats;
   int pickLine(LinkedQueue<Event> a,LinkedQueue<Event> b, LinkedQueue<Event> c);
   void processArrival();
   void processDeparture();
   void processDeparture(Event temp);

   int pickedLine();
   int number;
public:
   Simulation();
   ~Simulation();
   void simulate();
};

#endif
