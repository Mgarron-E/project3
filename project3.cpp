#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <unordered_map>
class likePirate{ 
public:
  static std::map<std::string, std::string> word;

  static std::string change(const std::string& sentance){
    std::string result = sentance;
    for(const auto& pair : word){
      size_t pos = result.find(pair.first);
      while(pos != std::string::npos){
	result.replace(pos, pair.first.length(), pair.second);
	pos = result.find(pair.first, pos + pair.second.length());
      }
    }
    return result;
  }
};
std::map<std::string, std::string> likePirate::word = {

  {"hello", "ahoy"},
  {"excuse me", "arrr"},
  {("sir","boy","man"),"matey"},
  {"madame","proud beauty"},
  {"officer", "foul blaggart"},
  {"the","th'"},
  {"my"," me"},
  {"your","yer"},
  {"is","be"},
  {"are","be"},
  {"restroom","head"},
  {"resturant", "galley"},
  {"hotel","fleabag inn"},
  {"coins","doubloons"},
  {"pirate","buccaneer"},
  {"friend","mate"},
  {"you","ye"}
};
using namespace std;
class Roman{
 public:
  int romanInt(string s){
    unordered_map<char, int> romanIntM = {
      {'I',1},
      {'V',5},
      {'X',10},
      {'L',50},
      {'C',100},
      {'D',500},
      {'M',1000}
    };
    int result = 0;
    int prevValue = 0;

    for (int i =s.size() - 1; i >= 0; --i){
      int currentValue = romanIntM[s[i]];
      if(currentValue < prevValue){
	result -= currentValue;
      }else{
	result +=currentValue;
      }
      prevValue = currentValue;
    }
    return result;
  }
};
      
  
int main(){
  std::string sentance;
  std::cout<<"Enter sentance: ";
  std::getline(std::cin, sentance);
  for (char& c : sentance){
    c = std::tolower(c);
  }
  
  std::string modifiedSentance = likePirate::change(sentance);
  modifiedSentance[0] = std::toupper(modifiedSentance[0]);
  std::cout <<"Modified: "<<modifiedSentance << std::ends;
  

  Roman converter;
  string Numeral;
  cout<<"Enter Roman Numeral: ";
  cin >> Numeral;
  int intValue = converter.romanInt(Numeral);
  cout << "Int: " << intValue << ends;
  return 0;
}
  
  
      
