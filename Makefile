
CC = g++
CFLAGS = -Wall -std=c++11

LIB = .

INCLUDE = .

TrieTest : libTrie.a TrieTest.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o -L$(LIB) -lTrie

libTrie.a: Trie.o TrieNode.o
	ar -rcs libTrie.a Trie.o TrieNode.o

Trie.o : $(INCLUDE)/Trie.h Trie.cpp
	$(CC) $(CFLAGS) -c -I$(INCLUDE) Trie.cpp

TrieNode.o : $(INCLUDE)/TrieNode.h TrieNode.cpp
	$(CC) $(CFLAGS) -c -I$(INCLUDE) TrieNode.cpp

TrieTest.o : TrieTest.cpp $(INCLUDE)/Trie.h TrieNode.h
	$(CC) $(CFLAGS) -c -I$(INCLUDE) TrieTest.cpp

# add a make clean and make test option
clean:
	rm TrieTest *.o

test:
	./TrieTest
