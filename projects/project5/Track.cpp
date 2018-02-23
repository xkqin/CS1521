#include "Track.h"
#include "Disc.h"
#include <iostream>
#include <string>
using namespace std;
Track::Track()
  :number(0)
{
}
Track::Track(Disc* discPtr)
{
  this ->discPtr = discPtr;
  //  this->printTrack() 
  // printTrack()
}
int Track::readPlayTime(int minutes, int seconds)
{
  // int index = time.find_first_of(':');
  return minutes*60+seconds;// (((int)substr(0,index))*60 + ((int)substr(index+1,time.length()-index)));
}
  
void Track::readTrack()
{
  cout << "Enter the Track name" << endl;
  cin >> name;
  if(discPtr -> isMutiArtist())
    {
      cout << "Enter the artist name " << endl;
      cin >> artist;
    }
  else
    {
      artist = discPtr ->getArtist();
    }
  char ans;
  int minutes,seconds;
  cout << "Enter the time as type of minutes:seconds" << endl;
  cin >> minutes >> ans >> seconds;
  playTime = readPlayTime(minutes,seconds);
  cout << "Enter the location that you want stored" << endl;
  cin >> location;
  number = discPtr -> getNumberOfTracks() + 1;
}

void Track::printTrack() const
{
  cout << "No." << number << " Track's name is" << name << endl;
  if(discPtr->isMutiArtist())
    {
      cout << "No." << number << " Track's artist name is " << artist << endl;
    }
  cout << "No." << number << " Track's Play time is " << playTime/60 << ":" 
       << playTime%60 << endl;
  cout << "No." << number << " Track's location is: " << location;
}


bool Track::isLessThan( const Track* aTrack) const
{
  bool isLess = false;
  if(number < (aTrack -> getNumber()))
    {
      isLess = true;
    }
  return isLess;
}

int Track::getNumber() const
{
  return number;
}

int Track::getPlayTime() const
{
  return playTime;
}
