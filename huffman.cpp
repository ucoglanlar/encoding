
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
    
    BinaryTree* left; 
    BinaryTree* right;
    BinaryTree* topRoot;
    
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
    
    //Loop through frequency array and insert characters into heap
    for(int i = 0; i < 128; i++){
        
        //Only insert characters that appear in the file
        if(freq[i] != 0){
           
            
           BinaryTree n((char)i , freq[i], NULL, NULL);
           
           heap.insert(n); 
           
        }
        
        
    }
    
    cout  << "Building Tree" << endl;
    cout  << "Heap Contents" << endl;
    
    //Build Heap
    while(!heap.isEmpty()){
        
        BinaryTree min1; 
        BinaryTree min2;
              
        //Remove first min from heap
        heap.deleteMin(min1);
        
        //Finished
        if(heap.isEmpty()){
            cout << "DONE!" << endl << endl;
            
            //Set the root of the binary heap equal to min1, the last item in the heap
            topRoot = new BinaryTree(min1.getCharecter(), min1.getFrequency(), min1.getLeft(), min1.getRight());
            
            break;
        }
        
        //Remove second min from heap
        heap.deleteMin(min2);
        
        //Make frequency of root equal to the sum of its children
        int rootFreq = min1.getFrequency() + min2.getFrequency();
        
        //Assign left and right pointers to have same values as min1 and min2
        left = new BinaryTree(min1.getCharecter(), min1.getFrequency(), min1.getLeft(), min1.getRight());
        right = new BinaryTree(min2.getCharecter(), min2.getFrequency(), min2.getLeft(), min2.getRight());
        
        //Create root and make children equal to min1 and min2
        BinaryTree root('`', rootFreq, left, right);
        
        //Insert new root back into heap
        heap.insert(root);
        
    }
    
    cout << "\nPrinting Tree" << endl;
    
    topRoot->printTree(topRoot);
    
    
    return 0;
}

