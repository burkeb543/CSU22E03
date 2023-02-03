
class word {
public:
    class Node {
    public:
        std::string str;
        class Node* nextWord;
        Node(std::string setSt)
        {
            this->str = setSt;
            nextWord = nullptr;
        }
    };
    Node* head;
    word() { head = nullptr; }

    //Function to reverse list
    void reverse()
    {
        Node* currentWord = head;
        Node* prevWord = nullptr, * nextWord = nullptr;

        while (currentWord != nullptr) {
            nextWord = currentWord->nextWord;
            currentWord->nextWord = prevWord;

            prevWord = currentWord;
            currentWord = nextWord;
        }
        head = prevWord;
    }

    void print(int * a)
    {
        class Node* temp = head;
        int i = 1;
        while (temp != nullptr) {
            if (a[i] >= 1) {
              std::cout << "\"" << temp->str << "\"";
              std::cout << " " << a[i] << "\n";
              temp = temp->nextWord;
              i++;
            }
            else {
              temp = temp->nextWord;
              i++;
            }
        }
    }

    std::string getWord(int i)
    {
        Node* temp = head;
        while (i > 0) {
            i--;
            if (i == 0)
                return temp->str;
            temp = temp->nextWord;
        }
        return "ERROR";
    }

    void addWordToList(std::string currWord)
    {
        Node* temp = new Node(currWord);
        temp->nextWord = head;
        head = temp;
    }

    bool sameWord(std::string A, std::string B)
    {
      int length_A = A.length(), length_B = B.length();
      if (length_A != length_B) { 
        return false;
        }
      if (A[length_A - 1] != B[length_B - 1]) { 
        return false;
      }
      else {
          for (int i = 0; i < length_A; i++) {
              if (A[i] != B[i])
                  return false;
                  }
      }
      return true;
    }

    void deleteList(Node** head_ref)  
    {  
      /* deref head_ref to get the real head */
      Node* current = *head_ref;  
      Node* next;  
        
      while (current != NULL)  
      {  
          next = current->nextWord;  
          free(current);  
          current = next;  
      }  
            
      /* deref head_ref to affect the real head back  
          in the caller. */
      *head_ref = NULL;  
    }  

};