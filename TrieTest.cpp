
#include "Trie.h"
#include <iostream>
#include <fstream>


int main(int argc, char *argv[]){
    std::ifstream fileDict;
    if(argc < 3){
        std::cout<< "stopping here 1" << std::endl;
        return 0;
    }
    std::string file1 = argv[1];
    fileDict.open(file1);
    std::string line;
    Trie test;
    while (std::getline(fileDict, line))
    {
        test.addWord(line);
    }
    std::ifstream fileQuerie;
    std::string file2 = argv[2];
    fileQuerie.open(file2);
    std::vector<std::string> querieVect;
    std::vector<std::string> listOfWords;
    while (std::getline(fileQuerie, line)){
        querieVect.push_back(line);
    }
    unsigned int i;
    unsigned int j;
    for(i = 0; i < querieVect.size(); i++){
        if(test.isWord(querieVect[i])){
            std::cout << querieVect[i] << " is found." << std::endl;
        }
        else{
            listOfWords = test.allWordsWithPrefix(querieVect[i]);
            std::cout << querieVect[i] << " is not found, did you mean:" << std::endl;
            if(listOfWords.size() == 0){
                std::cout << '\t' << '\t' << '\t' << "No alternatives found" << std::endl;
            }
            else{
                for(j = 0; j < listOfWords.size(); j++){
                    std::cout << '\t' << '\t' << '\t' << listOfWords[j] << std::endl;
                }
            }
        }
    }

}
