/*
 * Stephen Reese u0396206
 this class make a node class that contants the an array of nullptrs
*/
#include "TrieNode.h"
#include <iostream>


    //constructor
    TrieNode::TrieNode(){
         isWord = false;
         //set all the children to nullptr
         for (int i=0; i<26; i++){
             children[i]= nullptr;
         }
    }
//copy constructor
    TrieNode::TrieNode(const TrieNode& copyNode){
        isWord = copyNode.isWord;
        for (int i=0; i<26; i++){
            children[i]= copyNode.children[i];
        }

    }

    //copy overload =
    TrieNode& TrieNode::operator =(TrieNode copyNode){
        std::swap(isWord, copyNode.isWord);
        std::swap(children, copyNode.children);
        return *this;
    }

//destructor
   TrieNode::~TrieNode(){
       unsigned int i;
       for(i = 0; i < 26; i++){
           delete  children[i];
       }
   };
