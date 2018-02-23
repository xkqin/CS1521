
#include "NotFoundException.h"

NotFoundException::NotFoundException(const string& message)
  : logic_error(message.c_str() ) {
}

NotFoundException::~NotFoundException()
noexcept { //throw() {
}
