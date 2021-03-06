#include <string>
#include <iostream>
#include <fstream>
#include "EventBuilder.h"
using namespace std;

EventBuilder::EventBuilder()
{
  string fileName;
  cout << "Enter a file name that you want to input " << endl;
  cin >> fileName;
  inputFile.open(fileName.c_str());
  while(!inputFile)
    {
      cerr << " File "
           << fileName
           << " failed to open for input."
           << endl;
      cout << " Enter a right file name "
           << endl;
      cin >> fileName;
      inputFile.open(fileName.c_str());
    }
}
Event EventBuilder::createArrivalEvent(const int number,
				       const int lineNumber)
{
  Event arrival;
  //  if(inputFile.eof())
  // {
  //  arrival.setNumber(0);
  //   return arrival;
  // }
  arrival.setType(ARRIVAL);
  int time, length;
  if(inputFile >> time >> length)
    {
      arrival.setNumber(number);
      arrival.setTime(time);
      //inputFile >> length;
      arrival.setLength(length);
      arrival.setLine(lineNumber);
      //       cout << time << 's' << length << endl;
    }
  else
    {
      //  cout << "End of the File" << endl;
      arrival.setNumber(0);
    }
  return arrival;
}

Event EventBuilder::createDepartureEvent(const Time& currentEventTime,
                                         const Time& transactionLength,
                                         const int number,
					 const int lineNumber)
{
  Event departure;
  departure.setNumber(number);
  departure.setTime(currentEventTime + transactionLength);
  departure.setType(DEPARTURE);
  departure.setLine(lineNumber);
  departure.setLength(0);
  return departure;
}
