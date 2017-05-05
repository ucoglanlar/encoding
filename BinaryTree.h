
/* 
 * File:   BinaryTree.h
 * Author: batu
 *
 * Created on May 2, 2017, 2:15 PM
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>

using namespace std;

class BinaryTree{

private:
    
    char charecter;
    int frequency;
    BinaryTree* left;
    BinaryTree* right;
    string code;
    
    //Generate Huffman code 
    void printCode(string code){
        
        //Return if node is null
        if(this == NULL){
            return;
        }
        
        //Add zero if going to left child
        this->getLeft()->printCode(code + "0");
        
        //Print out code if a leaf node
        if(this->getCharecter() != '`'){
            cout << this->getCharecter() << "    " << this->getFrequency() << " " << code << endl;
        }
        
        //Add one if going to right child
        this->getRight()->printCode(code + "1");

        
    };
    
public:
    
    //Create an empty BinaryTree
    BinaryTree(){
        
        charecter = '`';
        frequency = 0;
        left = NULL;
        right = NULL;        
    }
    
    //Initialize BinaryTree with character, frequency, left and right children
    BinaryTree(char c, int f, BinaryTree* l, BinaryTree* r){
        
        charecter = c;
        frequency = f;
        left = l;
        right = r;
        
    }
    
    //Copy constructor
    BinaryTree(const BinaryTree& b){
        
        charecter = b.getCharecter();
        frequency = b.getFrequency();
        left = b.getLeft();
        right = b.getRight();
        
    }
    
    //Getters
    char getCharecter() const{
        return charecter;
    }
    
    int getFrequency() const{
        return frequency;
    }
    
    BinaryTree* getLeft() const{
        return left;
    }
    
    BinaryTree* getRight() const{
        return right;
    }
    
    string getCode() const{
        return code;
    }
    
    //Setters
    void setCharecter(char c) {
        charecter = c;
    }
    
    void setFrequency(int f) {
        frequency = f;
    }
    
    void setLeft(BinaryTree* b) {
        left = b;
    }
    
    void setRight(BinaryTree* b) {
        right = b;
    }
    
    void setCode(string s) {
        code = s;
    }
    
    //Override less than operator for comparisons
    bool operator<(const BinaryTree& b) const{
        
        if(frequency < b.getFrequency()){
            return true;
        }
        
        return false;
    
    }
    
    //Override equality operator
    BinaryTree& operator=(const BinaryTree& b){
        
        charecter = b.getCharecter();
        frequency = b.getFrequency();
        left = b.getLeft();
        right = b.getRight();
        
        return *this;
    
    }
    
    //Prints out entire tree 
    void printTree(){
        
        printCode("");
        
    }
    

};

#endif /* BINARYTREE_H */

