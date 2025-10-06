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
        return title;
    }


// add review to the head of the list
void addReview(double r, string c){
    ReviewNode* n = new ReviewNode;
    n->rating = r;
    n->comment = c;
    n->next = head;
    head = n;
}

void loadReviews(string filename) { // read review comments from file
    ifstream file(filename); // open the file
    if (!file) { // check for file open error
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string movieName; // first word of line - movie
    string comment; // rest of line - review comment

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
void showReviews() {
    if (head == nullptr) {
        cout << "     (No reviews)\n";
        return;
    }

    double sum = 0.0; // sum of all ratings
    int count = 0; // number of reviews
    ReviewNode* temp = head; // start at head

    while (temp != nullptr){ // traverse the linked list
        cout << "     > Review #" << (count + 1) << ": " 
                << fixed << setprecision(1) << temp->rating 
                << " : " << temp->comment << endl;
        sum += temp->rating; // add to total rating
        count++; // count the review
        temp = temp->next; // move to next node
    }

    double avg = sum / count; // calculate average
    cout << "     Average rating: " << fixed << setprecision(5) << avg << endl;
}
};

int main() {
    srand(time(0)); // seed random number generator

    // fixed array container of 4 movies
    Movie movies[4] = {
        Movie("Inception"),
        Movie("Matrix"),
        Movie("Interstellar"),
        Movie("Prestige")
    };

    // load reviews for each movie from file
    for (int i = 0; i < 4; i++) {
        movies[i].loadReviews("reviews.txt");
    }

    // output all movies reviews
    cout << "Movie Reviews\n";
    for (int i = 0; i < 4; i++){
            cout << "Movie: " << movies[i].getTitle() << endl;
            movies[i].showReviews();
            cout << endl;
    }
    
    return 0;
}
