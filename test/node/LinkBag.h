#ifndef _LINK_BAG
#definde _LINK_BAG


#include "BagInterface.h"
#include "node.h"

template <typename ItemType>
class LinkBag : public BagInterface<ItemType>
{
 privat:
  Node<ItemType>* headPtr;

  int itemCount;

  Node<ItemType>* getPointerTo(const ItemType& target) const;
  
 public:
  LinkBag();

  LinkBag(const LinkBag<ItemType>& aBag);

  virtual ~LinkedBag();
 
  virtual int getCurrentSize() const;
 
  virtual bool isEmpty() const;
 
  virtual bool add(const ItemType& newEntry);
 
  virtual bool remove(const ItemType& anEntry);
 
  virtual void clear();
 
  virtual int getFrequencyOf(const ItemType& anEntry) const;
 
  virtual bool contains(const ItemType& anEntry) const;
 
  virtual vector<ItemType> toVector() const;
};

#include "LinkBag.cpp"

#endif
