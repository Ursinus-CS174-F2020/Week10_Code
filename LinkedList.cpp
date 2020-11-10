#include <stdio.h>

class Node {
  private:
      Node* next; // Arrow to next node
      int value;
  
  public:
      Node(int value) {
          // x->y
          // (*x).y
          this->value = value;
          next = nullptr;
      }
      void updateReference(Node* next) {
          this->next = next;
      }
      Node* getNext() {
          return this->next;
      }
      int getValue() {
          return this->value;
      }
      void setValue(int value) {
          this->value = value;
      }
};

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() {
            head = nullptr;
        }

        ~LinkedList() {
            while (head != nullptr) {
                removeFirst();
            }
        }

        bool isEmpty() {
            return head == nullptr;
        }

        void addLast(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr){
                head = newNode;
            }
            else {
                Node* node = head;
                // Go until I find the end of the list
                // where the arrow points to nothing
                while (node->getNext() != nullptr) {
                    node = node->getNext();
                }
                node->updateReference(newNode);
            }
        }

        void addFirst(int value) {
          Node* newNode = new Node(value);
          if (head == nullptr) {
              head = newNode;
          }
          else {
              newNode->updateReference(head);
              head = newNode;
          }
        }

        int removeFirst() {
            int ret = -1;
            if (head != nullptr) {
                ret = head->getValue();
                Node* newHead = head->getNext();
                delete head;
                head = newHead;
            }
            return ret;
        }

        void printList() {
          Node* node = head;
          while (node != nullptr) {
            printf("%i", node->getValue());
            if (node->getNext() != nullptr) {
              printf(", ");
            }
            node = node->getNext();
          }
        }
};

int main() {
    LinkedList L;
    L.addFirst(3);
    L.addFirst(2);
    L.addLast(4);
    L.addLast(5);
    L.addFirst(1);
    L.addLast(6);
    printf("\n");
    L.printList();
    printf("\n");
}
