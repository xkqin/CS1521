#ifndef _NOT_FOUND_EXCEPTION
#define _NOT_FOUND_EXCEPTION

#include <stdexcept>
#include <string>

using namespace std;

/** @class PrecondViolatedExcep PrecondViolatedExcep.h "PrecondViolatedExcep.h"
 *
 *  Specification for an object thrown on violation of precondition. */
class NotFoundException : public logic_error {
 public:

  explicit NotFoundException(const string& message = "");

  virtual ~NotFoundException() noexcept; //throw();
};

#endif
