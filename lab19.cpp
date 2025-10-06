#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib> // rand, srand
#include <ctime>   // time
using namespace std;

// each review node in the linked list
struct ReviewNode{
    double rating; // random rating between 1.0 and 5.0
    string comment; // full comment text
    ReviewNode* next; // pointer to the next review node
};

// movie class that hold a title and its linked list of reviews
class Movie{
private:
    string title; // movie title
    ReviewNode* head; // start of linked list

public:
    Movie(string t = ""){
        title = t;
        head = nullptr;
    }

    // destructor : free all nodes
    ~Movie() {
        while (head != nullptr) {
            ReviewNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    string getTitle(){
        return title
    }
}

// add review to the head of the list
void addReview(double r, string c){
    Reviewnode* n = new ReviewNode;
    n->rating = r;
    n->comment = c;
    n->next = head;
    head = n;
}
