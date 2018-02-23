#ifndef _TRACK
#define _TRACK

#include <iostream>
#include <string>

#include "LinkedList.h"
class Disc;
/** @class Track Track.h "Track.h"
 *
 *  Definition of SetInterface class  */

class Track
{
 private:
  string name;
  string artist;
  int playTime;
  int number;
  string location;
  Disc *discPtr;
  int readPlayTime(int minutes, int seconds);
  Track();
 public:
  /** Consructor. */
  Track(Disc *discPtr);
  /** read the Tack from user.*/
  void readTrack();
  /** print the Track that user insert.*/
  void printTrack() const;
  /** judge if the pointer in class is less than the 
   *  pointer passed in
   *
   *  @pre the poiter passed in must be the same as the class itself.
   *  
   *  @post if successful, the pointer in class is less than 
   *  the pointer passed in
   *
   *  @return True if it is less than. */
  bool isLessThan(const Track* aTrack) const;
  /** get the number of Track
   *
   *  return the number of the Track. */
  int getNumber() const;
  /** get the playtime of the track.
   *
   *  @return the playtime of the track. */
  int getPlayTime() const;
};

#endif
