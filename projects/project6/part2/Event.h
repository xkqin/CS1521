#ifndef _EVENT
#define _EVENT

#include "Time.h"
#include "EventType.h"

class Event
{
 private:
  Time time;
  Time length;
  int number;
  EventType type;
  int line;
 public:
  Time getTime() const;
  Time getLength() const;
  int getNumber() const;
  EventType getType() const;
  int getLine() const;
  void setLine(const int theLine);
  void setTime(const Time theTime);
  void setLength(const Time theLength);
  void setNumber(const int theNumber);
  void setType(const EventType theType);
  bool operator<(const Event& rhs) const;
  bool operator>(const Event& rhs) const;
  bool operator<=(const Event& rhs) const;
  bool operator>=(const Event& rhs) const;
  bool operator==(const Event& rhs) const;
  bool operator!=(const Event& rhs) const;
};
#endif
