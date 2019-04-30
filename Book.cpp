#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Book.h"
using namespace std;


void Book::addBook(){
  system("clear");
  cout << "Enter author(Enter 'q' at any time to return to main menu): ";
  cin.ignore();
  getline(cin, author);

  if(author == "q" || author == "Q"){
    return;
  }

  cout << endl;

  cout << "Enter book: ";
  getline(cin, book);

  if(book == "q" || book == "Q"){
    return;
  }

  cout << endl;

  cout << "Enter number of pages: ";
  getline(cin, numPages);

  if(numPages == "q" || numPages == "Q"){
    return;
  }

  cout << endl;


  //Get genre.
  cout << "Fiction or non-fiction(f or n): ";
  cin >> genre;

  if(genre == 'q' || genre == 'Q'){
    return;
  }

  cout << endl;

  //Check for valid input.
  inChkPtr -> checkInput(genre, 'f', 'F', 'n', 'N');

  if(genre == 'f' || genre == 'F'){
    genreStr = "Fiction";
  }

  else if(genre == 'n' || genre == 'N'){
    genreStr = "Non-Fiction";
  }

  //Get public domain status.
  cout << "Is the book public domain?(y or n): ";
  cin >> pubDom;

  if(pubDom == 'q' || pubDom == 'Q'){
    return;
  }

  cout << endl;

  //Check for valid input.
  inChkPtr -> checkInput(pubDom, 'y', 'Y', 'n', 'N');

  if(pubDom == 'y' || pubDom == 'Y'){
    pubDomStatusStr = "Yes";

    cout << "Do you have a link to the free book?(y or n): ";
    cin >> linkAnswer;

    if(linkAnswer == 'q' || linkAnswer == 'Q'){
      return;
    }

    cout << endl;

    //Check for valid input.
    inChkPtr -> checkInput(linkAnswer, 'y', 'Y', 'n', 'N');

    if(linkAnswer == 'y' || linkAnswer == 'Y'){
      cout << "Enter the link: ";
      cin.ignore();
      getline(cin, pubDomLink);

      if(pubDomLink == "q" || pubDomLink == "Q"){
        return;
      }

      cout << endl;
    }

    else if(linkAnswer == 'n' || linkAnswer == 'N'){
      pubDomLink = "None";
    }
  }

  else if(pubDom == 'n' || pubDom == 'N'){
    pubDomStatusStr = "No";
    pubDomLink = "None";
  }

  addToFullList();

  cout << "Would you like to add another book?(y or n): ";
  cin >> addAnotherBook;
  inChkPtr -> checkInput(addAnotherBook, 'y', 'Y', 'n', 'N');

  if(addAnotherBook == 'y' || addAnotherBook == 'Y'){
    system("clear");
    addBook();
  }

  else if(addAnotherBook == 'n' || addAnotherBook == 'N'){
    return;
  }
}

void Book::deleteFiles(){
  string fileName;
  char delChoice;

  //Get filename string.
  cout << "Enter the name of the file to be deleted: ";
  cin.ignore();
  getline(cin, fileName);
  cout << endl;

  //Double-check decision to avoid accidental deletion.
  cout << "The file will be PERMANENTLY deleted. Are you sure(y or n)?: ";
  cin >> delChoice;
  cout << endl;

  //Check for valid input.
  inChkPtr -> checkInput(delChoice, 'y', 'Y', 'n', 'N');

  if(delChoice == 'y' || delChoice == 'Y'){
    fileName = (fileName);
    cout << "Deleting file '" << (fileName) << "'....." << endl;
    remove(fileName.c_str());
    if(remove(fileName.c_str()) == 0){
      perror("Error deleting file");
    }

    else{
      cout << "File '" << fileName << "' successfully deleted!" << endl;
    }

    cout << "Would you like to delete another file?(y or n): ";
    cin >> delChoice;
    cout << endl;

    inChkPtr -> checkInput(delChoice, 'y', 'Y', 'n', 'N');

    if(delChoice == 'y' || delChoice == 'Y'){
      deleteFiles();
    }

    else if(delChoice == 'n' || delChoice == 'N'){
      cout << "Exiting program....." << endl;
      exit(0);
    }
  }

  else if(delChoice == 'n' || delChoice == 'N'){
    cout << "Files will not be deleted. Exiting program....." << endl;
    exit(0);
  }
}

void Book::addToFullList(){
  const string FULL_LIST = "full_list.txt";
  fstream fullList(FULL_LIST, ios::in | ios::out | ios::app);

  if(fullList.fail()){
    cerr << "Unable to open file '" << FULL_LIST << "'. Exiting....." << endl;
    exit(1);
  }

  else{
    cout << "File '" << FULL_LIST << "' opened successfully!" << endl;
  }

  fullList << "Author: " << author << endl;
  fullList << "Book: " << book << endl;
  fullList << genreStr << endl;
  fullList << numPages << endl;
  fullList << "Public Domain: " << pubDomStatusStr << endl;
  fullList << "Public Domain Link: " << pubDomLink << endl;

  cout << "Data written to file '" << FULL_LIST << "' successfully!" << endl;

  fullList.flush();
  fullList.close();

  cout << "File '" << FULL_LIST << "' saved and closed successfully!" << endl;
}
