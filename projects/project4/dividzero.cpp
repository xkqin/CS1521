#include "dividzero.h"

dividzero::dividzero(const string& message)
  : overflow_error(message.c_str() ) {
}

dividzero::~dividzero()
noexcept { 
}
