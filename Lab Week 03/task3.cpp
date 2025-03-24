#include<iostream>
#include<cstring>
using namespace std;
class Book{
    char name[100];
    char author[100];
    int pages;
    public:
    Book(const char* n, const char* a, int p):pages(p){
        strncpy(name, n, sizeof(name)-1);
        name[sizeof(name)-1]='\0';
        strncpy(author, a, sizeof(author)-1);
        author[sizeof(author)-1]='\0';
    }
    void display() const {
        cout << "\nBook: " << name << " by " << author << ", Pages: " << pages;
    }
    int getPages(){return pages;}
    char* getName(){return name;}
   
};
class Newspaper{
    char name[100];
    char date[10];
    char edition[100];
public:

Newspaper(const char* n, const char* d, const char* e) { 
    strncpy(name, n, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';

    strncpy(date, d, sizeof(date) - 1);
    date[sizeof(date) - 1] = '\0';

    strncpy(edition, e, sizeof(edition) - 1);
    edition[sizeof(edition) - 1] = '\0';
}
    char * getEdition(){return edition;}
    char* getName(){return name;}
    void display() const {
    cout << "\nNewspaper: " << name << ", Date: " << date << ", Edition: " << edition ;
    }
    
};
//library has books and newspapers (aggregation)
class Library{
    Book *books[100];
    Newspaper *newspapers[100];
    int bookCount; 
    int newspaperCount; 

public:
    Library() : bookCount(0), newspaperCount(0) {
        for (int i = 0; i < 100; i++) books[i] = nullptr;
        for (int i = 0; i < 100; i++) newspapers[i] = nullptr;
    }
    void addBook(const Book& other){
        if (bookCount < 100) {
            books[bookCount] = new Book(other);//copy constructor called here
            bookCount++;
        }
    }
    void addNewspaper(const Newspaper& other){
        if (newspaperCount < 100) {
            newspapers[newspaperCount] = new Newspaper(other);
            newspaperCount++;
        }
    }
    void sortBooksByPages(){
        for(int i=0; i<bookCount-1; i++){
            for(int j =0; j<bookCount-1-i; j++){
                if(books[j]->getPages() > books[j+1]->getPages()){
                    Book *temp = books[j];
                    books[j]= books[j+1];
                    books[j+1] = temp;
                }
                    
            }
        }
    }
    void sortNewspapersByEdition(){
        for(int i=0; i<newspaperCount-1; i++){
            for(int j =0; j<newspaperCount-1-i; j++){
                if(strcmp(newspapers[j]->getEdition(), newspapers[j+1]->getEdition()) > 0){
                    Newspaper *temp = newspapers[j];
                    newspapers[j]= newspapers[j+1];
                    newspapers[j+1] = temp;
                }
                    
            }
        }
    }
    Book* searchBookByTitle(const char* n){
        for(int i=0; i<bookCount; i++){
            if( strcmp(books[i]->getName(), n) == 0){
                return books[i];
            }
        }
    }
    Newspaper* searchNewspaperByName(const char* n){
        for(int i=0; i<bookCount; i++){
            if( strcmp(newspapers[i]->getName(), n) == 0){
                return newspapers[i];
            }
        }
    }
    void displayCollection() const {
        for (int i = 0; i < bookCount; i++) {
            books[i]->display();
        }
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i]->display();
        }
    }
    ~Library() {
        for (int i = 0; i < bookCount; i++) {
            delete books[i];
        }
        for (int i = 0; i < newspaperCount; i++) {
            delete newspapers[i];
        }
    }

};


int main(){
    // Create book objects 
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277); 
    Book book2("To Kill a Mockingbird", "Harper Lee", 324); 

    // Create newspaper objects 
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition"); 
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition"); 

    // Create a library object .
    Library library; 

    // Add books and newspapers to the library 
    library.addBook(book1); 
    library.addBook(book2); 
    library.addNewspaper(newspaper1); 
    library.addNewspaper(newspaper2); 

    // Display the entire collection 
    cout << "Before Sorting:\n"; 
    library.displayCollection(); 
     // Sort books by pages and newspapers by edition 
     library.sortBooksByPages(); 
     library.sortNewspapersByEdition(); 
  
     cout << "\n\nAfter Sorting:\n"; 
     library.displayCollection(); 
  
     // Search for a book by title 
     Book* foundBook = library.searchBookByTitle("The Catcher in the Rye"); 
     if (foundBook) { 
         cout << "\n\nFound Book:\n"; 
         foundBook->display(); 
     } else { 
         cout << "\n\nBook not found.\n"; 
     } 
  
     // Search for a newspaper by name 
     Newspaper* foundNewspaper = library.searchNewspaperByName("The Times"); 
     if (foundNewspaper) { 
         cout << "\n\nFound Newspaper:\n"; 
         foundNewspaper->display(); 
     } else { 
         cout << "\n\nNewspaper not found.\n"; 
     }
    return 0;
}