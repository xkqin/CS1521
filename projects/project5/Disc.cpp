#include <iostream>
#include <string>
#include "Disc.h"
#include "PrecondViolatedExcep.h"
using namespace std;
Disc::Disc()
{
  trackListPtr = new LinkedList<Track*>();
}
Disc::~Disc()
{
  trackListPtr -> clear();
  delete trackListPtr;
  trackListPtr = nullptr;
}

bool Disc::isEmpty() const
{
  return (trackListPtr -> isEmpty());
}

int Disc::getNumberOfTracks() const
{
  return trackListPtr -> getLength();
}

bool Disc::insertTrack( Track* trackPtr)
{
  return  trackListPtr -> insert(getNumberOfTracks()+1,trackPtr);

}
  
bool Disc::removeTrack(const Track* trackPtr)
{
  bool remove = false;
  for(int i=1; i <= (trackListPtr -> getLength()); ++i)
    {
      if(trackPtr == retrieveTrackByNumber(i))
	{
	  remove=trackListPtr -> remove(i);
	  break;
	}
    }
  return remove;
}

Track* Disc::retrieveTrackByNumber(const int trackNumber) const
{
  if( trackNumber > getNumberOfTracks() || trackNumber < 1 )
    {
      string message ="Can not retrieve the track with wrong number !";
      throw PrecondViolatedExcep(message);
    }
  return trackListPtr -> getEntry(trackNumber);
}
string Disc::getArtist() const
{
  return artist;
}
string Disc::getTitle() const
{
  return title;
}
bool Disc::isMutiArtist() const
{
  return mutiArtist;
}
void Disc::readDisc()
{
  cout << "Enther the title of the disc " << endl;
  cin >> title;
  cout << "Is it the artist of the disc is mutil-artist(Y/N) " << endl;
  char ans;
  cin >> ans;
  if(ans=='y' || ans == 'Y')
    {
      mutiArtist = true;
    }
  else if (ans == 'n' || ans == 'Y')
    {
      mutiArtist = false;
    }
  if(mutiArtist == true)
    {
      cout << "Enter the artist of the disc " << endl;
      cin >> artist;
    }
  cout << "Enter the year of the disc " << endl;
  cin >> year;
  cout << "Enter the genre of the disc " << endl;
  cin >> genre;
  int count=1;
  char A;
  do{
    Track* newTrack = new Track(this);
    cout << "The "<< count << " Track of your disc " <<endl;
    newTrack -> readTrack();
    addToTotalPlayTime(newTrack -> getPlayTime());
    if(insertTrack(newTrack))
      {
	count++;
	cout << "Do you want to enter another Track (Y/N)" << endl;
	cin >> A;
      }
  }while(A == 'Y'||A == 'y');

}
void Disc::printDisc() const
{
  cout << "The title of the disc is : " << title<< endl;
  if(mutiArtist)
    {
      cout << "The disc is made by muti-artist" << endl;
    }
  else cout << "The artist is : " << artist << endl;
  cout << "There are " << trackListPtr -> getLength() << " Tracks" << endl;
  cout << "The disc year is : " << year << endl;
  cout << "The disc genre is : " << genre << endl;
  cout << "The disc total play time is : " << totalPlayTime << endl;
  try{
    for(int i=1; i <= getNumberOfTracks(); ++i)
      {
	retrieveTrackByNumber(i) -> printTrack();
      }
  }
  catch (PrecondViolatedExcep& e){
    cerr << "Error :"
	 << e.what()
	 << endl;
  }
}
void Disc::addToTotalPlayTime(const int time)
{
  totalPlayTime += time;
}
bool Disc::isLessThan(const Disc* aDisc)const
{
  bool isle = false;
  if  (title.compare(aDisc -> getTitle()) < 0)
   {
     isle = true;
   }
 return isle;
}
  
  
bool Disc::isLessThanOrEqualTo(const Disc* aDisc) const
{
  bool isle;
  if  (title.compare(aDisc -> getTitle()) <= 0)
    {
      isle = true;
    }
  return isle;

}
