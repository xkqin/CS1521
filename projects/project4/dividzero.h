#ifndef _DIVID_ZERO
#define _DIVID_ZERO

#include <stdexcept>
#include <string>

using namespace std;

/** @class dividZero dividZero.h "dividZero.h"
 *
 *  Specification for an object thrown on violation of precondition. */
class dividzero : public overflow_error {
 public:

  explicit dividzero(const string& message = "");

  virtual ~dividzero() noexcept; //throw();
};

#endif
