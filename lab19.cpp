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

void loadReviews(string filename) {
    if stream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string movieName;
    string comment;

    //read one full line so comments can have spaces
    while (getline(file, movieName, ' ')) { // read movie name up to first space
        getline(file, comment);  //     read the rest of the line as comment
        if (movieName == title) {
            double randomRating = (rand() % 41 + 10) / 10.0; // 1.0 - 5.0
            addReview(randomRating, comment);
        }
    }

    file.close();
}

// display all reviews and average rating
void showReviews {
    if (head == nulptr) {
        cout << "     (No reviews)\n)";
        return;
    }

    double sum = 0.0;
    int count = 0;
    ReviewNode* temp = head;

    while
}
