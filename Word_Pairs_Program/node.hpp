#pragma once
#include <string>

class node: public std::string {
  public: node();
  int word_Pair_Num; //counts the number of word pairs a word has
  int pair_Num; //count times a word pair occurs

  node * pairs; //links the word pairs of a word
  node * before;
  node * after;
};