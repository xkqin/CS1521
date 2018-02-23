#include"Simulation.h"
#include <iostream>
using namespace std;
Simulation::Simulation()
{

}
Simulation::~Simulation()
{
}
void Simulation::simulate()
{
  Event curEvent = eventBuilder.createArrivalEvent(1,1);
  line1.setCount(line1.getLength()+1);
  curEvent.setLine(1);
  if(currentEvent.getNumber() != 0)
    {
      events.add(curEvent);
    }
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
      while( !events1.isEmpty() )
	{
	  currentEvent = events1.peek();
	  stats.addEvent(currentEvent);
	  events1.remove();
	}

    }
      
 
  stats.reportStats();

}

int Simulation::pickedLine()
{
  
 
  int result = 1 ;
  if(line1.getLength() <= line2.getLength())
    {
     result = 1;
    }
  else result = 2;

  if(result == 1 )
    {
      if(line1.getLength() <= line3.getLength())
	{
	  result = 1;
	}
      else result = 3;
    }
  else if(line2.getLength() <= line3.getLength())
    {
      result = 2;
    }
  else result = 3;
 //  LinkedQueue<Event> smallest;
 /*
  int number;
   if(line1.getLength()<line2.getLength() && line1.getLength()<line3.getLength())
     {
       //      smallest = line1;
        number = 1;
     }
   //  else
   //  {
   if(line2.getLength()<line1.getLength() && line2.getLength()<=line3.getLength())
     {
	  //  smallest = line2;
       number = 2;
     }
   
   if(line3.getLength()<=line1.getLength() && line3.getLength()<line2.getLength())
     {
       // else {
       // smallest = line3;
       number = 3;
       }
       //       else number = 1;
       //    }
   //  smallest.setLength() = line1.getLength();
   
    int number ;
   number = 1;
   if(number == 1)
     {
       if(line1.getLength() > line2.getLength())
	 {
	   number = 2;
	 }
       if(line1.getLength() > line3.getLength())
	 {
	   number = 3;
	 }
     }
   if(number == 2 )
     {
       if(line2.getLength() > line1.getLength())
	 {
	   number = 1;
	 }
       if(line2.getLength() > line3.getLength())
	 {
	   number = 3;
	 }
	 }
  int number;

  if((smallest -> getLength()) > line2.getLength())
    {
      smallest =& line2;
      number = 2;
    }
 else if((smallest->getLength()) > line3.getLength())
    {
      smallest =& line3;
      number = 3;
    }
 else
   {
     smallest = &line1;
     number =1;
     }*/
       return result;
}

void Simulation::processArrival()
{
  int number = currentEvent.getLine();
  bool first;
  if(number == 1)
    {
      first = line1.isEmpty();
      line1.enqueue(currentEvent);
      events.remove();
    }      
  if(number == 2)
    {
      first = line2.isEmpty();	  
      line2.enqueue(currentEvent);
      events.remove();
    }
  if(number == 3)
    {
      first = line3.isEmpty();
      line3.enqueue(currentEvent);
      events.remove();
    }
  if(first)
    {
      Event Dep = eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                    currentEvent.getLength(),
                                                    currentEvent.getNumber(),
						    currentEvent.getLine());
      events.add(Dep);
    }
 
 
  
 Event newArrival = eventBuilder.createArrivalEvent(currentEvent.getNumber()+1,
						     pickedLine());


 if( !events.isEmpty() && newArrival > events.peek() && (events.peek().getType()) == DEPARTURE)
   {
     Event temp = events.peek();
     processDeparture(temp);
   }

 newArrival.setLine(pickedLine());


 if(pickedLine() == 1) 
   {
     line1.setCount(line1.getLength()+1);
   }
else if(pickedLine() == 2) 
   {
     line2.setCount(line2.getLength()+1);
   }
else if(pickedLine() == 3) 
   {
     line3.setCount(line3.getLength()+1);
   }




  if(newArrival.getNumber() != 0)
    {
      events.add(newArrival);
    }

}
void Simulation::processDeparture()
{
  int number = currentEvent.getLine();
  if(number == 1) 
    {
      line1.dequeue();
      events.remove();
      if( !line1.isEmpty() )
	{
	  Event  done = line1.peekFront();
	  
	  Event  Dep = eventBuilder.createDepartureEvent(currentEvent.getTime(),
							 done.getLength(),
							 done.getNumber(),
							 done.getLine());
	  events.add(Dep);
	}
    }
  if(number == 2) 
    {
      line2.dequeue();
      events.remove();
      if( !line2.isEmpty())
	{
	  
	  Event  done = line2.peekFront();
	  
	  Event  Dep = eventBuilder.createDepartureEvent(currentEvent.getTime(),
							 done.getLength(),
							 done.getNumber(),
							 done.getLine());
	  events.add(Dep);
	}
    }
  if(number == 3) 
    {
      line3.dequeue();
      events.remove();
      if( !line3.isEmpty())
	{
	  
	  Event  done = line3.peekFront();
	  
	  Event  Dep = eventBuilder.createDepartureEvent(currentEvent.getTime(),
							 done.getLength(),
							 done.getNumber(),
							 done.getLine());
	  events.add(Dep);
	}
    }
  
}

void Simulation::processDeparture(Event temp)
{

  int number = temp.getLine();
  if(number == 1) 
    {
      line1.dequeue();
      events.remove();
      if( !line1.isEmpty() )
	{
	  Event  done = line1.peekFront();
	  
	  Event  Dep = eventBuilder.createDepartureEvent(temp.getTime(),
							 done.getLength(),
							 done.getNumber(),
							 done.getLine());
	  events.add(Dep);

	}
    }
   if(number == 2) 
    {
      line2.dequeue();
      events.remove();
      if( !line2.isEmpty())
	{
	  
	  Event  done = line2.peekFront();
	  
	  Event  Dep = eventBuilder.createDepartureEvent(temp.getTime(),
							 done.getLength(),
							 done.getNumber(),
							 done.getLine());
	  events.add(Dep);
	}
    }
   if(number == 3) 
    {
      line3.dequeue();
      events.remove();
      if( !line3.isEmpty())
	{
	  
	  Event  done = line3.peekFront();
	  
	  Event  Dep = eventBuilder.createDepartureEvent(temp.getTime(),
							 done.getLength(),
							 done.getNumber(),
							 done.getLine());
	  events.add(Dep);
	}
    }
  
   events1.add(temp);
}


