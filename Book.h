#ifndef BOOK_H
#define BOOK_H

#include "InputCheck.h"
using namespace std;

class Book{
  public:
    void addBook();
    void deleteFiles();
    void addToFullList();
    void listByAuthor();

  private:
    InputCheck inChkObj;
    InputCheck *inChkPtr = &inChkObj;
    int count; //numPages;
    char pubDom, genre, addAnotherBook, linkAnswer;
    string author, book, numPages, genreStr, pubDomStatusStr, pubDomLink;
};

#endif //BOOK_H
