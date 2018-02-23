#include <iostream>
#include <string>
#include<cctype>
using namespace std;

string clean(string &words)
{
  //  int position, length;

  //   string final;
  string testChars = "!@#$%^&*()_-+={}[]:;\"\'`<>,.?/|\\";
   if(words.find_first_of(testChars) == 0)
   {
    words = words.substr(1, words.length()-1);
    clean(words);
  }
   
 if(words.find_last_of(testChars) == (words.length()-1))
   {
     words = words.substr( 0,words.length() - 1);
     clean(words);
   }
  //else  
      //return words;
  return words;
}

string toLower(string words)
{
  for(unsigned int i=0; i<(words.size()); ++i)
    {
      words[i] = tolower(words[i]);
    }

  return words;
}


int main()
{
  string x="ASDWEE";
  

  cout << toLower(x);
  cout << endl;
}
