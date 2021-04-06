/*
    Program to keep track of the books you've read
    or are currently reading
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Book{
    //Defining public variables
    public:
        //Declaring the constructors and the deconstructor
        Book();
        Book(string m, string t, string a, bool f);
        ~Book();

        string toString();
        void printFile();
        //Declaring the accessors and mutators
        void setTitle(string t){title = t;};
        string getTitle(){return title;};

        void setAuthor(string a){author = a;};
        string getAuthor(){return author;};

        void setMonthRead(string m){monthRead = m;};
        string getMonthRead(){return monthRead;};

        void setFinished(bool f){isFinished = f;};
        bool getFinished(){return isFinished;};
    //Declaring the private variables
    private:
        string monthRead;
        string title;
        string author;
        bool isFinished;
};

//Default constructor
Book::Book(){
    monthRead = "null";
    title = "book";
    author = "author";
    isFinished = false;
}


Book::Book(string m, string t, string a, bool f){
    monthRead = m;
    title = t;
    author = a;
    isFinished = f;    
}

//Destructor
Book::~Book(){
  cout << "Destructor called!" << endl;
}

void Book::printFile(){
    //Open the file
    ofstream myOutput("Book Tracker.txt", ios::app);
    
    //Checks for errors
    if(myOutput.fail()) {
        cout << "ERROR: no permissions to write to Book Tracker.txt" << endl;
        exit(1);
    }
    
    //Checks if the user is done reading the book
    if(getFinished()){
        //Print to the file
        myOutput << getTitle() << ", " << getAuthor() << ", " << getMonthRead() 
                 << ", " << "Finished" << endl;
    }
    else{
        //Print to the file
        myOutput << getTitle() << ", " << getAuthor() << ", " << getMonthRead() 
                 << ", " << "In Progress" << endl;
    }
    //close the file
    myOutput.close();

}

//Returns all of the info as a string
string Book::toString(){
    if(getFinished()){
        return getTitle() + ", " + getAuthor() + ", " + getMonthRead() 
                + ", " + "Finished";
    }
    else{
        return getTitle() + ", " + getAuthor() + ", " + getMonthRead() 
                + ", " + "In Progress";
    }
}

//Overloads the << operate and allows the Book variable to be printed
ostream& operator<<(ostream& os, Book b) {
    //Returns all of the variables as a string
    if (b.getFinished()) {
        os << b.getTitle() << ", " << b.getAuthor() << ", "
            << b.getMonthRead() << ", " << "Finished";
    } 
    else {
        os << b.getTitle() << ", " << b.getAuthor() << ", "
            << b.getMonthRead() << ", " << "In Progress";  
    }
  return os;
}

int main() {
    //Create an object
    Book *b1 = new Book();
    //Assign all of the variables
    b1->setTitle("Don Quixote");
    b1->setMonthRead("November");
    b1->setAuthor("Miguel des Cervantes");
    b1->setFinished(false);
    //Print using the toString() function
    cout << b1->toString() << endl;
    //Print the book info into the file
    b1->printFile();
  
    //Create an object
    Book *b2 = new Book("October", "Neuromancer", "William Gibson", true);
    //Print using the overload operator 
    cout << *b2 << endl;
    //Print the book info into the file
    b2->printFile();
  
    delete b1;
    delete b2;

    return 0;
}