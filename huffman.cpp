
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
    
    //Create binary heap of BinaryTree pointers
    BinaryHeap<BinaryTree> heap (1000001);
    
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
           
           BinaryTree n((char)i , freq[i], NULL, NULL);
           
           heap.insert(n);
           
        }
        
        
    }
    
    cout << endl << endl;
    cout << "Heap Contents" << endl;
    //Print frequencies of each character
    while(!heap.isEmpty()){
        
        BinaryTree node;
        heap.deleteMin(node);
        
        cout << node.getCharecter() << " : " << node.getFrequency() << endl;
        
    }
    
    
    return 0;
}

