#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>
using namespace std;
class PrecondViolateExcep : public logic_error
{
 public:
  explicit PrecondViolateExcep(const string& message = "");

  virtual ~PrecondViolateExcep() noexcept;
};
#endif
