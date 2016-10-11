/*
 * Stephen Reese u0396206
 This is a header for the class that make a trie holding letters that make up a dictionary.
 */

#include "TrieNode.h"
#include <iostream>

class Trie{

    TrieNode* root;
    //a vector too hold all the words with a prefix
    std::vector<std::string> allTheWords;
public:
    //default constructor
    Trie();
    //destructor
    ~Trie();
    //copy constructor
    Trie(const Trie& copyTrie);
    //copy overload =
    Trie& operator =(Trie copyTrie);
    //adds a word
    void addWord(std::string word);
    //checks if a word is in the Trie
    bool isWord(std::string word);
    //give all the words with the given prefirx
    std::vector<std::string> allWordsWithPrefix (std::string prefix);
    //helper method to find the words
    void findWords(std::string prefrix, TrieNode* parentNode);


        };
