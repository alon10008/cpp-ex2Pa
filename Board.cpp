#include <iostream>
#include "Board.hpp"
#include <stdexcept>
#include <string>

using namespace std;
using namespace ariel;

void ariel::Board::post(unsigned int row, unsigned int clm, Direction direct, string msg) {

    if(msg.length() > Board::longest)
    {
        Board::longest = msg.length();
    }
    switch(direct)
    {
        case Direction::Vertical:
            for(unsigned int i=0 ; i<msg.length() ; i++)
            {
                Board::b[row + i][clm] = msg[i]; 
            }
            break;
        case Direction::Horizontal:
            for(unsigned int i=0 ; i<msg.length() ; i++)
            {
                Board::b[row][clm + i] = msg[i];
            }
            break;
    }

}

string ariel::Board::read(unsigned int row, unsigned int clm, Direction direct,unsigned int length) {

    if(length < 1)
    {
        throw out_of_range("WRONG INPUT!\n");
    }
    string msg;
    switch(direct)
    {
        case Direction::Vertical:
            for(unsigned int i=0 ; i<length ; i++)
            {
                if(Board::b[row + i][clm] == '\0')
                {
                    msg += '_';
                }
                else
                {
                    msg += Board::b[row +i][clm];
                }
            }
            break;
        case Direction::Horizontal:
            for(unsigned int i=0 ; i<length ; i++)
            {
                if(Board::b[row][clm + i] == '\0')
                {
                    msg += '_';
                }
                else
                {
                    msg += Board::b[row][clm + i];
                }
            }
            break;
    }
    return msg;

}

void ariel::Board::show() {

    
    /*cout << "size of rows: " << Board::b.size() << endl;
    int size = 0;
    for(map<int, map<int, char>>::iterator it=Board::b.begin() ; it!=Board::b.end() ; it++)
    {
        if(it->second.size() > size)
        {
            size = it->second.size();
        }
    }
    cout << "size of clms: " << size << endl;
    char ans[Board::b.size()][size];
    
    for(int i=0 ; i<Board::b.size() ; i++)
    {
        for(int j=0 ; j<size ; j++)
        {
            ans[i][j] = '_';
        }
    }  
    int i = 0, j = 0;
    int row, clm;
    for(map<int, map<int, char>>::iterator it=Board::b.begin() ; it!=Board::b.end() ; it++)
    {

        
         
        for(map<int, char>::iterator iter=it->second.begin() ; iter!=it->second.end() ; iter++)
        {
            clm = iter->first;
            ans[i][j] = iter->second;
            it++;
            if(Board::b[it->first][iter->first] != '\0')
            {
                ans[i+1][j] = Board::b[it->first][iter->first];
            }
            it--;
            j++;
        }
        j = 0;
        i++;
    }
    for(int i=0 ; i<Board::b.size() ; i++)
    {
        for(int j=0 ; j<size ; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    } */   

}

