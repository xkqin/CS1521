#ifndef _STACK_INTERFACE
#define _STACK_INTERFACE

/** @class StackInterface StackInterface.h "StackInterface.h"
 *
 *  Definition of StackInterface class template. */
template <typename ItemType>
class StackInterface {
 public:
  /** Virtual destructor. */
  virtual ~StackInterface() {}

  /** Sees whether this stack is empty.
   *
   *  @return True if the stack is empty, or false. */
  virtual bool isEmpty() const = 0;

  /** Adds a new entry to the top of this stack.
   *
   *  @post If successful, newEntry is stored at the top of this
   *        stack.
   *
   *  @param newEntry The object to be added as a new entry.
   *
   *  @return True if addition was successful, or false. */
  virtual bool push(const ItemType& newEntry) = 0;

  /** Removes the top of this stack.
   *
   *  @post If successful, the top of this stack has been removed.
   *
   *  @return True if removal was successful, or false. */
  virtual bool pop() = 0;

  /** Retrieves the top of this stack.
   *
   *  @pre This stack is not empty.
   *
   *  @post None.
   *
   *  @return The top of this stack.
   *
   *  @throws PrecondViolatedExcep If the precondition is violated. */
  virtual ItemType peek() const = 0;
};

#endif
