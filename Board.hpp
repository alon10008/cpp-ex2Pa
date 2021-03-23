#include <iostream>
#include <string>
#include "Direction.hpp"
#include <map>

using namespace std;

namespace ariel{

   class Board {
       private:
           map<unsigned int, map<unsigned int, char>> b;
           int longest;
       public:
           Board() {longest = 0;};
           ~Board() {};
           void post(unsigned int row, unsigned int clm, Direction direct, string msg);
           string read(unsigned int row, unsigned int clm, Direction direct, unsigned int length);
           void show();
   };       

}
