#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include "LinkedSet.h"

using namespace std;
string clean(string &words);
string toLower(string words);


int main()
{
  char ans;
  do{
  ifstream fin;
  ofstream fout; 
  string file = "";
  string dic = "";
  cout << "Enter the dictionary that you want to correct the spelled words "
       << endl;
  cin >> dic;
  cout << "Enter the spell cheker file that you want to correct the spelled words "
       << endl;
  cin >> file;

  fin.open(dic.c_str());
   
  while (!fin) {
    cerr << "dictionary "
	 << dic
	 << " failed to open for input."
	 << endl;
    cout << "Enter a dictionary: ";
    cin >> dic;
    fin.open( dic.c_str() );
  }
  LinkedSet<string> dictionary;

  string str;
  while(fin >> str )
    {
      str = clean(str);
      str = toLower(str);
      dictionary.add(str);
     
    }
  fin.close();
  
  fin.open(file.c_str());

  while (!fin) {
    cerr << "File "
	 << fin
	 << " failed to open for input."
	 << endl;
    cout << "Enter a filename: ";
    cin >> file;
    fin.open(file.c_str() );
  }
  LinkedSet<string> filename;
  string word;
  while(fin >> word)
    {
      word = clean(word);
      word = toLower(word);
      filename.add(word);
	
     }
  fin.close();
  LinkedSet<string> bag ( filename.difference(dictionary));
    vector<string> bagItems = bag.toVector();
  int count = (int) bagItems.size();
  for (int i = 0; i < count; ++i) {
    cout << bagItems[i]
         << " ";
	 }
  cout << endl;
  cout << " Do you want to again ? (Y/N)" << endl;
  cin >> ans;

  } while(ans == 'Y'|| ans == 'y');

  return 0;      
}


string clean(string &words)
{

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
  return words;
}

string toLower( string words)
{
  for(unsigned int i=0; i<(words.length()); ++i)
    {
      words[i] = tolower(words[i]);
    }

  return words;
}
