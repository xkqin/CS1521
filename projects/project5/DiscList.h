#ifndef _DISC_LIST
#define _DISC_LIST

#include <iostream>
#include <string>

#include "Disc.h"
#include "LinkedList.h"
class DiscList
{
 private:
  LinkedList<Disc*>* discListPtr;
  int findDiscPosition(Disc* discPtr) const;
 public:
  /** Constructor */
  DiscList();
  /** Disstructor */
  ~DiscList();
  /** judg if the Disc is empty.
   *
   *  @return True if the Disc is empty.*/ 
  bool isEmpty() const;
  /** get the number of the disc
   *
   *  @reutrn inr the number of the discs. */
  int getNumberOfDiscs() const;
  /** Insert the Disc
   *
   *  @pre the pointer must be a Disc pointer
   *
   *  @post If successful, the Track will be inseted in to the DiscList
   *
   *  @return True if insert successful. */

  bool insertDisc( Disc* aDiscPtr);
  /** Removw the Disc
   *
   *  @pre the pointer must be a Disc pointer
   *
   *  @post If successful, the Disc will be removed from the Disc List
   *
   *  @return True if remove successful. */

  bool removeDisc(const Disc* aDiscPtr);
  /** retrieve the Disc by number
   *
   *  @pre the disc number must greater than 1 and less than the number of the Disc
   *  or it will throw an exception
   *
   *  @return the Disc pointer which is the number associted with the number. */

  Disc* retrieveDisc(const int number) const;
};

#endif
