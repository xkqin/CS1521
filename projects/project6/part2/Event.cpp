#include "Event.h"

Time Event::getTime() const
{
  return time;
}
Time Event::getLength() const
{
  return length;
}
int Event::getNumber() const
{
  return number;
}
EventType Event::getType() const
{
  return type;
}
int Event::getLine() const
{
  return line;
}
void Event::setLine(const int theLine)
{
  line = theLine;
}
void Event::setTime(const Time theTime)
{
  time = theTime;
}
void Event::setLength(const Time theLength)
{
  length = theLength;
}
void Event::setNumber(const int theNumber)
{
  number = theNumber;
}
void Event::setType(const EventType theType)
{
  type = theType;
}
bool Event::operator<(const Event& rhs) const
{
  return time < rhs.time;
}
bool Event::operator>(const Event& rhs) const
{
  return time > rhs.time;
}
bool Event::operator<=(const Event& rhs) const
{
  return time <= rhs.time;
}
bool Event::operator>=(const Event& rhs) const
{
  return time >= rhs.time;
}
bool Event::operator==(const Event& rhs) const
{
  return time == rhs.time;
}
bool Event::operator!=(const Event& rhs) const
{
  return time != rhs.time;
}
