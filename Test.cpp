#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace ariel;

TEST_CASE("Empty-Board") {
    
    Board b;
    unsigned int max = 4294967295; //max value of unsigned int : (2^32-1)
    srand(time(0));     //random seed to random generator//
    unsigned int row, clm, leng;
    Direction d;
    string ans;
    for(int i=0 ; i<1000 ; i++) // Empty board should return _________.......
    {
        ans = "";
        row = (unsigned int)rand()%max;
        clm = (unsigned int)rand()%max;
        leng = rand()%1000 + 1; //The length can't be 0!
        if(leng%2==0)
        {
            d = Direction::Horizontal;
        }
        else
        {
            d = Direction::Vertical;
        }
        for(int j=0 ; j<leng ; j++) // Create the answer //
        {
            ans += '_';
        }
        CHECK(b.read(row, clm, d, leng) == ans);

    }

}

TEST_CASE("Board-Limit") {

    Board b;
    unsigned int max = 4294967295; //max value of unsigned int : (2^32-1)
    string test = "test";
    unsigned int i = 0;
    //////HORIZONTAL/////
    while(i!=max) // post 'test'
    {
        i++;
        i *= 2;
        i--;
        CHECK_NOTHROW(b.post(i , i, Direction::Horizontal, test));
    }
    i = 0;
    while(i!=max) // read 'test'
    {
        i++;
        i *=2;
        i--;
        CHECK(b.read(i, i, Direction::Horizontal, 4) == test);
    }
    i = 0;
    /////VERTICAL//////
    while(i!=max) // post 'test'
    {
        i++;
        i *= 2;
        i--;
        CHECK_NOTHROW(b.post(i , i, Direction::Vertical, test));
    }
    i = 0;
    while(i!=max) // read 'test'
    {
        i++;
        i *=2;
        i--;
        CHECK(b.read(i, i, Direction::Vertical, 4) == test);
    }
}

TEST_CASE("Read - Post") {

////HORIZONTAL////
    Board b;
    string msg = "sometime";
    unsigned int row = 10;
    unsigned int clm = 10;
    CHECK_NOTHROW(b.post(row, clm, Direction::Horizontal, msg));  
    CHECK(b.read(row, clm, Direction::Horizontal, msg.length()) == msg);
    string change = "thing";
    CHECK_NOTHROW(b.post(row, clm + 4, Direction::Horizontal, change));
    CHECK(b.read(row, clm, Direction::Horizontal, 9) == "something");
////VERTICAL////
    row = 100;
    clm = 100;
    CHECK_NOTHROW(b.post(row, clm, Direction::Vertical, msg));  
    CHECK(b.read(row, clm, Direction::Vertical, msg.length()) == msg);
    CHECK_NOTHROW(b.post(row + 4, clm, Direction::Vertical, change));
    CHECK(b.read(row, clm, Direction::Vertical, 9) == "something");


    CHECK_THROWS(b.read(row, clm, Direction::Vertical, 0));//////size cant be 0!///////
}
