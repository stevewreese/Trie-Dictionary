/*
 * Stephen Reese u0396206
 this class make a node class that contants the vectors
 */
#include <iostream>
#include <vector>

struct TrieNode{
    //checks if word or not
    bool isWord;
    //vector of nodes
    TrieNode *children[26];

    //copy constructor
    TrieNode();
    //copy constructor
    TrieNode(const TrieNode& copyNode);
    //copy overload =
    TrieNode& operator =(TrieNode copyNode);
    //destructor
    ~TrieNode();

};
