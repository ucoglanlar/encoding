
/* 
 * File:   huffman.cpp
 * Author: batu
 *
 * Created on May 2, 2017, 2:10 PM
 */

#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "BinaryHeap.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //int array which stores the frequencies of each character. The ASCII code of each character is the index/key in the array
    int* freq = new int[128];
    
    //Open file to be read
    ifstream file(argv[1]);
    
    //Current character being read
    char curr;
    
    //Read each character in the file
    while( file >> curr){
        //Increase count of current character
        freq[(int)curr]++;
    }
    
    //Print frequencies of each character
    for(int i = 0; i < 128; i++){
        
        if(freq[i] != 0){
          cout << (char) i << " : " << freq[i] << endl;
        }
    }
    
    
    return 0;
}

