#ifndef _DISC
#define _DISC

#include <iostream>
#include <string>
#include "Track.h"
#include "LinkedList.h"


/** @class Track Track.h "Track.h"
 *
 *  Definition of SetInterface class  */
class Disc
{
 private:
  string title;
  string artist;
  int year;
  string genre;
  int totalPlayTime;
  bool mutiArtist;
  LinkedList<Track*>* trackListPtr;
 public:
  /** constructor*/
  Disc();
  /** Disctructor */
  ~Disc();
  /** judge if it is empty
   *
   *  @return if the Disc is empty. */
  bool isEmpty() const;
  /** Get the number of track 
   *
   *  @return the number of the track. */
  int getNumberOfTracks() const;
  /** Insert the Track 
   * 
   *  @pre the pointer must be a Track pointer
   *
   *  @post If successful, the Track will be inseted in to the Disc
   *
   *  @return True if insert successful. */
  bool insertTrack( Track* trackPtr);
  /** Remove the Track 
   * 
   *  @pre the pointer must be a Track pointer
   *
   *  @post If successful, the Track will be remove from the Disc
   *
   *  @return True if remove successful. */

  bool removeTrack(const Track* trackPtr);
  /** retrieve the track by number
   *
   *  @pre the track number must greater than 1 and less than the number of the Track
   *  or it will throw an exception 
   *  
   *  @return the track pointer which is the number associted with the number. */
  Track* retrieveTrackByNumber(const int trackNumber) const;
  /** get the artist name
   *
   *  return the name of the artist. */
  string getArtist() const;
  /** get the title name
   *
   *  return the name of the title. */
  string getTitle() const;
  /** judge if it is mutiple artist
   *  
   *  return True if it is muti-artist. */
  bool isMutiArtist() const;
  /**  read the information of disc from user. */
  void readDisc();
  /** print the information about the disc that user entered. */
  void printDisc() const;
  /** add the time to the totaltime.*/
  void addToTotalPlayTime(const int time);
  /** judge if the pointer in class is less than the
   *  pointer passed in
   *
   *  @pre the poiter passed in must be the same as the class itself.
   *
   *  @post if successful, the pointer in class is less than
   *  the pointer passed in
   *
   *  @return True if it is less than. */

  bool isLessThan(const Disc* aDisc)const;
  /** judge if the pointer in class is less than of eual to
   *  pointer passed in
   *
   *  @pre the poiter passed in must be the same as the class itself.
   *
   *  @post if successful, the pointer in class is less than or equal to
   *  the pointer passed in
   *
   *  @return True if it is less than. */

  bool isLessThanOrEqualTo( const Disc* aDisc) const;
};
#endif
