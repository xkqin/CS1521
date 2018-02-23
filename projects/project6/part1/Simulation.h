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
   LinkedQueue<Event> line;
   PriorityQueue<Event> events;
   Statistics stats;

   void processArrival();
   void processDeparture();

public:
   Simulation();
   ~Simulation();
   void simulate();
};

#endif
