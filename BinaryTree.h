
/* 
 * File:   BinaryTree.h
 * Author: batu
 *
 * Created on May 2, 2017, 2:15 PM
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;

class BinaryTree{

private:
    
    char charecter;
    int frequency;
    BinaryTree* left;
    BinaryTree* right;
    
    void printCode(){
    
    
    };
    
public:
    
    BinaryTree(){
        
        charecter = '`';
        frequency = 0;
        left = NULL;
        right = NULL;
        
    }
    
    BinaryTree(char c, int f, BinaryTree* l, BinaryTree* r){
        
        charecter = c;
        frequency = f;
        left = l;
        right = r;
    }
    
    BinaryTree(const BinaryTree& b){
        
        charecter = b.getCharecter();
        frequency = b.getFrequency();
        left = b.getLeft();
        right = b.getRight();
        
    }

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
    
    bool operator<(const BinaryTree& b) const{
        
        if(frequency < b.getFrequency()){
            return true;
        }
        
        return false;
    
    }
    
    BinaryTree& operator=(const BinaryTree& b){
        
        charecter = b.getCharecter();
        frequency = b.getFrequency();
        left = b.getLeft();
        right = b.getRight();
        
        return *this;
    
    }
    
    void printTree(BinaryTree* node){
        
        if(node == NULL){
            return;
        }
          
        printTree(node->left);
        
        //Only print leaf nodes
        if(node->getCharecter() != '`'){
            cout << node->getCharecter() << " : " << node->getFrequency() << endl;
        }
        
        printTree(node->right);
        
    }
    

};

#endif /* BINARYTREE_H */

