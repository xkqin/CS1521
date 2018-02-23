#include <string>
#include <stdexcept>
#include "PrecondViolateExcep.h"

PrecondViolateExcep::PrecondViolateExcep(const string& message)
  : logic_error(message.c_str() ) {
}

PrecondViolateExcep::~PrecondViolateExcep()
noexcept { 
}
