#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#include "isPalindrome.h"

int main() {

   vector<string> strVec = { "",
                             "a",
                             "aba",
                             "abba",
                             "deleveled",
                             "a man a plan a canal panama",
                             "ab",
                             "abbc" };

   for (vector<string>::iterator vIter = strVec.begin();
        vIter != strVec.end();
        ++vIter) {

      // Get the current string from the vector:
      string currStr = *vIter;

      // Initialize a clean string to empty:
      string clean = "";

      // Iterate over the string currStr and remove all space characters:
      for (string::iterator sIter = currStr.begin();
           sIter != currStr.end();
           ++sIter) {

         if (*sIter != ' ') {
            clean += *sIter;
         }
      }

      // Test and report whether the string in clean is a palindrome:
      if (isPalindrome(clean) ) {
         cout << "YES "
              << clean
              << " is a palindrome."
              << endl;
      }
      else {
         cout << "NO "
              << clean
              << " is not a palindrome."
              << endl;
      }
   }

   return EXIT_SUCCESS;
}
