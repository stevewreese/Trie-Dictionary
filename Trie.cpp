/*
 * Stephen Reese u0396206
 This class makes a trie holding letters that make up a dictionary.
*/

#include "Trie.h"
#include <iostream>

    //default constructor
    Trie::Trie() {
        root = new TrieNode();
    }

    //destructor
     Trie::~Trie(){
         delete root;
     }
    //copy constructor
    Trie::Trie(const Trie& copyTrie){
        root = copyTrie.root;
    }

    //copy overload =
    Trie& Trie::operator =(Trie copyTrie){
        std::swap(root, copyTrie.root);
        return *this;
    }

/*
 *adds a word to the trie
 */
    void Trie::addWord(std::string word){
        //temp node to travers the trie
        TrieNode* tempNode;
        tempNode = root;
        unsigned int i;
        for(i = 0; i < word.length(); i++){
            char b = tolower(word[i]);
            //find index
            int c = b - 'a';
            if(tempNode->children[c] == nullptr){
                //make a new node
                TrieNode *nextNode = new TrieNode();                ;
                tempNode->children[c] = nextNode;
                if(i == word.length() - 1){
                    nextNode->isWord = true;
                }
                tempNode = nextNode;
            }
            else{
                tempNode = tempNode->children[c];
                if(i == word.length() - 1){
                    tempNode->isWord = true;
                }
            }
        }
    }


/*
  checks if a word is in the Trie
 */
    bool Trie::isWord(std::string word){
        TrieNode* tempNode;
        tempNode = root;
        unsigned int i;
        for(i = 0; i < word.length(); i++){
            //make char lowercase
            char b = tolower(word[i]);
            //the char minus 'a' gives us an index
            int c = b - 'a';
            if(tempNode->children[c] != nullptr){
                tempNode = tempNode->children[c];
                //if at end of word make node isWod = true;
                if(i == word.length() - 1){
                    return  tempNode->isWord;
                }
            }
            else{
                return false;
            }
        }
        return false;
    }

/*
 * gets all the words with the given prefirx
 */
    std::vector<std::string> Trie::allWordsWithPrefix (std::string prefix){
        //clear vector when called again
        allTheWords.clear();
        TrieNode* parent = root;
        unsigned int i;
        for(i = 0; i < prefix.length(); i++){
            int c = prefix[i] - 'a';
            if(parent->children[c] == nullptr){
                return allTheWords;
                }
            else{
                parent = parent->children[c];
            }
        }

        findWords(prefix, parent);
        return allTheWords;
    }
/*
 *Helper method to find the words recuserviely

 */
void Trie::findWords(std::string prefrix, TrieNode* parentNode){
        std::string word = prefrix;
        if(parentNode->isWord){
            allTheWords.push_back(word);
        }
        unsigned int i;
        for(i = 0; i < 26; i++){
            if(parentNode->children[i] != nullptr){
                char c = i + 'a';
                findWords(word + c, parentNode->children[i]);
            }
        }
    };
