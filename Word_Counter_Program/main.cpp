#include <iostream>
#include <string>
#include <time.h>
#include "word.hpp"

int main()
{
    word book1;
    int counter = 0;
    clock_t tStart = clock();

    while (std::cin.eof() == false) {
        counter++;
        std::string next_Word;
        std::cin >> next_Word;
        book1.addWordToList(next_Word);
    }

    book1.reverse();

    int* wordCount;
    int* wordCountArray = new int[counter+1];
    wordCount = wordCountArray;

    std::string* stringTemp;
    std::string* stringDynamicAr = new std::string[counter+1];
    stringTemp = stringDynamicAr;

    for (int n = 0; n <= counter; n++)
    {
        wordCountArray[n] = 1;
        stringDynamicAr[n] = book1.getWord(n);
    }


    for (int i = 1; i <= counter; i++) {
        for (int j = i + 1; j <= counter; j++) {
            if (book1.sameWord(stringDynamicAr[i], stringDynamicAr[j])) {
                wordCountArray[i]++;
                wordCountArray[j] -= 100000; 
             }
        }
    }

    book1.print(wordCount);
    
    delete[] wordCount;
    book1.deleteList(&book1.head);
    std::cout << "Time taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << "\n";

  return 0;
}