#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    string cuvant;
    Node* next;
};

bool palindrom(const char* cuv) {
    int stanga = 0;
    int dreapta = strlen(cuv) - 1;
    while (stanga < dreapta) {
        if (cuv[stanga] != cuv[dreapta]) {
            return false;
        }
        stanga++;
        dreapta--;
    }
    return true;
}

int main() {
    char cuvinte[][100] = {"cojoc", "calabalac", "abc", "cosmonaut", "scafandru","aerisirea"};
    int numarcuv = sizeof(cuvinte) / sizeof(cuvinte[0]);
    cout << "Palindromuri: ";

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < numarcuv; i++) {
        if (palindrom(cuvinte[i])) {
            Node* newNode = new Node;
            newNode->cuvant = cuvinte[i];
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } 
			else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    Node* currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->cuvant << " ";
        currentNode = currentNode->next;
    }

    currentNode = head;
    while (currentNode != nullptr) {
        Node* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    return 0;
}