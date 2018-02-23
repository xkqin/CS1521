#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message)
  : logic_error(message.c_str() ) {
}

PrecondViolatedExcep::~PrecondViolatedExcep()
noexcept { //throw() {
}
