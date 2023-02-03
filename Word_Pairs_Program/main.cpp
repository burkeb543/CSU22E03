#include <iostream>

#include <string>

#include <fstream>

#include "node.hpp"

// forward declarations
bool process_Word(std::string new_word, node * & tree);
void process_Word_Pairs(std::string previous_str, std::string new_word, node * & tree);
void print_Alphabetically(std::string word_input, node * tree);
bool check_For_Book(const std::string & name);
void store_Word_Pairs(std::string new_word, node * & tree);
void print_Word_Pairs(std::string word_in, node * tree);

int main() {
  node * root = nullptr;

  int wordcount = 0;
  int individual_word_count = 0;

  std::string fileName;
  std::cout << "Please enter the name of the book file:" << std::endl;
  std::cin >> fileName;

  std::ifstream bookFile;
  bool doesBookExist = check_For_Book(fileName);

  while (!doesBookExist) {
    std::cout << "An error occurred attempting to open the file \"" << fileName << "\"." << std::endl;
    std::cout << "Please enter the name of the book file:" << std::endl;
    std::cin >> fileName;
    doesBookExist = check_For_Book(fileName);
  }
  std::string prev_word;
  bookFile.open(fileName);
  while (bookFile.eof() == false) {
    std::string t_word;
    bookFile >> t_word;
    if (bookFile.fail() == false) {
      wordcount++;
      if (process_Word(t_word, root))
        individual_word_count++;
      if (wordcount > 1)
        process_Word_Pairs(prev_word, t_word, root);
      prev_word = t_word;
    }
  }
  bookFile.close();
  std::cout << "The file \"" << fileName << "\" contains " << wordcount << " words of which " << individual_word_count << " are distinct." << std::endl;
  while (std::cin.eof() == false) {
    std::cout << "Please enter the word you wish to check:" << std::endl;
    std::string checkWord;
    std::cin >> checkWord;
    if (std::cin.eof() == false)
      print_Word_Pairs(checkWord, root);
  }
  std::cout << "Goodbye";
  return 0;
}

//Check if book exists
bool check_For_Book(const std::string & name) {
  std::ifstream f(name.c_str());
  return f.good();
}

// returns true if the word is new, false otherwise
bool process_Word(std::string new_word, node * & tree) {
  bool newWord;
  if (tree == nullptr) {
    tree = new node();
    tree -> assign(new_word);
    newWord = true;
  } else {
    if (new_word == * tree) {
      newWord = false;
    } else {
      if (new_word < * tree) {
        newWord = process_Word(new_word, tree -> before);
      } else {
        newWord = process_Word(new_word, tree -> after);
      }
    }
  }
  return newWord;
}
//Store word as a word pair with the word before it
void process_Word_Pairs(std::string previous_str, std::string new_word, node * & tree) {
  if ( * tree != previous_str) {
    if (previous_str < * tree)
      process_Word_Pairs(previous_str, new_word, tree -> before);
    else {
      process_Word_Pairs(previous_str, new_word, tree -> after);
    }
  } else {
    tree -> word_Pair_Num++;
    store_Word_Pairs(new_word, tree -> pairs);
  }
}
void store_Word_Pairs(std::string new_word, node * & tree) {
  if (tree == nullptr) {
    //Word pair doesn't exist, create new node
    tree = new node();
    tree -> assign(new_word);
  } else {
    if ( * tree == new_word) {
      tree -> pair_Num++;
    } else if (new_word < * tree) {
      store_Word_Pairs(new_word, tree -> before);
    } else {
      store_Word_Pairs(new_word, tree -> after);
    }
  }
}
//Check if word previously inputted by user and if it has word pairs
void print_Word_Pairs(std::string word_in, node * tree) {
  if (tree == nullptr)
    std::cout << "The word \"" << word_in << "\" was not found." << std::endl;
  else if ( * tree == word_in) {
    if (tree -> pairs == nullptr)
      std::cout << "Word pairs starting with \"" << word_in << "\" were not found." << std::endl;
    else {
      switch (tree -> word_Pair_Num) {
      case 1:
        std::cout << "Word pairs starting with \"" << word_in << "\" were found once." << std::endl;
        break;
      case 2:
        std::cout << "Word pairs starting with \"" << word_in << "\" were found twice." << std::endl;
        break;
      default:
        std::cout << "Word pairs starting with \"" << word_in << "\" were found " << tree -> word_Pair_Num << " times." << std::endl;
      }
      print_Alphabetically(word_in, tree -> pairs);
    }
  } else {
    if (word_in < * tree) {
      print_Word_Pairs(word_in, tree -> before);
    } else {
      print_Word_Pairs(word_in, tree -> after);
    }
  }
}
//Print word pairs in alphabetical order
void print_Alphabetically(std::string word_input, node * tree) {
  if (tree != nullptr) {
    print_Alphabetically(word_input, tree -> before);
    switch (tree -> pair_Num) {
    case 1:
      std::cout << "\"" << word_input << " " << * tree << "\" was found once." << std::endl;
      break;
    case 2:
      std::cout << "\"" << word_input << " " << * tree << "\" was found twice." << std::endl;
      break;
    default:
      std::cout << "\"" << word_input << " " << * tree << "\" was found " << tree -> pair_Num << " times." << std::endl;
    }
    print_Alphabetically(word_input, tree -> after);
  }
}
