#include <string>
using namespace std;


inline std::string trim(std::string& str)
{
  str.erase(str.find_last_not_of(' ')+1);         //suffixing spaces
  str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
  return str;
}
template <size_t N>
bool checkIfValid(string inputStr, const string (&validStrings)[N], int arrSize){
  bool found = false;
  for(int i = 0; i < arrSize ; i++){
    if(inputStr == validStrings[i]){
      found = true;
      break;
    }
  }
  return found;
}

template <size_t N>
int indexOfString(string inputStr, const string (&validStrings)[N], int arrSize){
  int found = -1;
  for(int i = 0; i < arrSize ; i++){
    if(inputStr == validStrings[i]){
      found = i;
      break;
    }
  }
  return found;
}