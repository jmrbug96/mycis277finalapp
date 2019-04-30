#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Book.h"
#include "FilterLists.h"
using namespace std;

void displayMenu();

int main() {

  displayMenu();

  return 0;
}

void displayMenu(){
  int choice;
  char choice2;
  bool noFl, ba, bb, u3, f, nf, pd, pdl;
  const string PURPLE_TEXT = "\033[38;5;200m";
  const string LIGHT_GREEN_TEXT = "\033[38;5;119m";
  const string RESET_TEXT = "\033[0m";

  cout << PURPLE_TEXT << string(30, '=') << endl;
  cout << '=' << setw(29) << '=' << endl;
  cout << '=' << setw(20) << LIGHT_GREEN_TEXT << "BOOK INQUIRY" << PURPLE_TEXT << setw(8) << '=' << endl;
  cout << '=' << setw(29) << '=' << endl;
  cout << string(30, '=') << RESET_TEXT << endl << endl;


  cout << "1 - Add book(s)\n";
  cout << "2 - Delete file(s)(Does not work with repl.it)\n";
  cout << "3 - List Full List\n";
  cout << "4 - List Fiction\n";
  cout << "5 - List Non-Fiction\n";
  cout << "6 - List books that have less than 300 pages\n";
  cout << "7 - List books in the public domain\n";
  cout << "8 - List with public domain link\n";
  cout << "99 - Quit\n";
  cout << endl;
  cout << "Enter your choice(1+): ";
  cin >> choice;

  switch(choice){
    case 1:{
      Book bookObj;
      Book *bookObjPtr = &bookObj;
      bookObjPtr->addBook();
    }

    break;

    case 2:{
      Book bookObj;
      Book *bookObjPtr = &bookObj;
      bookObjPtr->deleteFiles();
    }

    break;

    case 3:{
      system("clear");
      InputCheck inChkObj;
      InputCheck *inChkPtr = &inChkObj;
      cout << "List full list by author or book?(a or b): ";
      cin >> choice2;

      inChkPtr->checkInput(choice2, 'a', 'A', 'b', 'B');

      //If 'a' or 'A', set noFlags to False, byAuthor to True, byBook to False, under300 to False, only fiction to False, and only non-fiction to False.
      if(choice2 == 'a' || choice2 == 'A'){
        noFl = 1;
        ba = 1;
        bb = 0;
        u3 = 0;
        f = 0;
        nf = 0;
        pd = 0;
        pdl = 0;
      }
      //If 'b' or 'B', set noFlags to False, byAuthor to False, byBook to True, under300 to False, only fiction to False, and only non-fiction to False.
      else if(choice2 == 'b' || choice2 == 'B'){
        noFl = 1;
        ba = 0;
        bb = 1;
        u3 = 0;
        f = 0;
        nf = 0;
        pd = 0;
        pdl = 0;
      }

      FilterLists flObj(noFl, ba, bb, u3, f, nf, pd, pdl);
      FilterLists *flObjPtr = &flObj;

      flObjPtr->formatList();
    }

    break;

    case 4:{
      system("clear");
      InputCheck inChkObj;
      InputCheck *inChkPtr = &inChkObj;
      cout << "List fiction list by author or book?(a or b): ";
      cin >> choice2;

      inChkPtr->checkInput(choice2, 'a', 'A', 'b', 'B');

      //If 'a' or 'A', set noFlags to False, byAuthor to True, byBook to False, under300 to False, only fiction to true, only non-fiction to False
      //pubDom to false and pubDomLink to false.
      if(choice2 == 'a' || choice2 == 'A'){
        noFl = 0;
        ba = 1;
        bb = 0;
        u3 = 0;
        f = 1;
        nf = 0;
        pd = 0;
        pdl = 0;
      }

      //If 'b' or 'B', set noFlags to False, byAuthor to False, byBook to True, under300 to False, only fiction to true, only non-fiction to False
      //pubDom to false, and pubDomLink to false.
      else if(choice2 == 'b' || choice2 == 'B'){
        noFl = 0;
        ba = 0;
        bb = 1;
        u3 = 0;
        f = 1;
        nf = 0;
        pd = 0;
        pdl = 0;
      }

      FilterLists flObj(noFl, ba, bb, u3, f, nf, pd, pdl);
      FilterLists *flObjPtr = &flObj;

      flObjPtr->formatList();
    }

    break;

    case 5:{
      system("clear");
      InputCheck inChkObj;
      InputCheck *inChkPtr = &inChkObj;
      cout << "List non-fiction list by author or book?(a or b): ";
      cin >> choice2;

      inChkPtr->checkInput(choice2, 'a', 'A', 'b', 'B');

      //If 'a' or 'A', set noFlags to False, byAuthor to True, byBook to False, under300 to False, only fiction to False, only non-fiction to true
      //pubdom to false, and pubDomLink to false.
      if(choice2 == 'a' || choice2 == 'A'){
        noFl = 0;
        ba = 1;
        bb = 0;
        u3 = 0;
        f = 0;
        nf = 1;
        pd = 0;
        pdl = 0;
      }

      //If 'b' or 'B', set noFlags to False, byAuthor to False, byBook to True, under300 to False, only fiction to False, only non-fiction to true
      //pubDom to false, and pubDomLink to false.
      else if(choice2 == 'b' || choice2 == 'B'){
        noFl = 0;
        ba = 0;
        bb = 1;
        u3 = 0;
        f = 0;
        nf = 1;
        pd = 0;
        pdl = 0;
      }

      FilterLists flObj(noFl, ba, bb, u3, f, nf, pd, pdl);
      FilterLists *flObjPtr = &flObj;

      flObjPtr->formatList();
    }

    break;

    case 6:{
      system("clear");
      InputCheck inChkObj;
      InputCheck *inChkPtr = &inChkObj;
      cout << "List books under 300 pages by author or book?(a or b): ";
      cin >> choice2;

      inChkPtr->checkInput(choice2, 'a', 'A', 'b', 'B');

      //If 'a' or 'A', set noFlags to False, byAuthor to True, byBook to False, under300 to true, only fiction to False, only non-fiction to False
      //pubDom to false and pubDomLink to false.
      if(choice2 == 'a' || choice2 == 'A'){
        noFl = 0;
        ba = 1;
        bb = 0;
        u3 = 1;
        f = 0;
        nf = 0;
        pd = 0;
        pdl = 0;
      }
      //If 'b' or 'B', set noFlags to False, byAuthor to False, byBook to True, under300 to true, only fiction to False, only non-fiction to False
      //pubDom to false and pubDomLink to false.
      else if(choice2 == 'b' || choice2 == 'B'){
        noFl = 0;
        ba = 0;
        bb = 1;
        u3 = 1;
        f = 0;
        nf = 0;
        pd = 0;
        pdl = 0;
      }

      FilterLists flObj(noFl, ba, bb, u3, f, nf, pd, pdl);
      FilterLists *flObjPtr = &flObj;

      flObjPtr->formatList();
    }

    break;

    case 7:{
      system("clear");
      InputCheck inChkObj;
      InputCheck *inChkPtr = &inChkObj;
      cout << "List public domain books by author or book?(a or b): ";
      cin >> choice2;

      inChkPtr->checkInput(choice2, 'a', 'A', 'b', 'B');

      //If 'a' or 'A', set noFlags to False, byAuthor to True, byBook to False, under300 to False, only fiction to False, only non-fiction to False
      //pubDom to true, and pubDomLink to false.
      if(choice2 == 'a' || choice2 == 'A'){
        noFl = 0;
        ba = 1;
        bb = 0;
        u3 = 0;
        f = 0;
        nf = 0;
        pd = 1;
        pdl = 0;
      }
      //If 'b' or 'B', set noFlags to False, byAuthor to False, byBook to True, under300 to False, only fiction to False, only non-fiction to False
      //pubDom to true and pubDomLink to false.
      else if(choice2 == 'b' || choice2 == 'B'){
        noFl = 0;
        ba = 0;
        bb = 1;
        u3 = 0;
        f = 0;
        nf = 0;
        pd = 1;
        pdl = 0;
      }

      FilterLists flObj(noFl, ba, bb, u3, f, nf, pd, pdl);
      FilterLists *flObjPtr = &flObj;

      flObjPtr->formatList();
    }

    break;

    case 8:{
      system("clear");
      InputCheck inChkObj;
      InputCheck *inChkPtr = &inChkObj;
      cout << "List public domain books with links by author or book?(a or b): ";
      cin >> choice2;

      inChkPtr->checkInput(choice2, 'a', 'A', 'b', 'B');

      //If 'a' or 'A', set noFlags to False, byAuthor to True, byBook to False, under300 to False, only fiction to False, only non-fiction to False
      //pubDom to true, and pubdom link to true.
      if(choice2 == 'a' || choice2 == 'A'){
        noFl = 0;
        ba = 1;
        bb = 0;
        u3 = 0;
        f = 0;
        nf = 0;
        pd = 1;
        pdl = 1;
      }
      //If 'b' or 'B', set noFlags to False, byAuthor to False, byBook to True, under300 to False, only fiction to False, only non-fiction to False
      //pubDom to true, and pubDomLink to true.
      else if(choice2 == 'b' || choice2 == 'B'){
        noFl = 0;
        ba = 0;
        bb = 1;
        u3 = 0;
        f = 0;
        nf = 0;
        pd = 1;
        pdl = 1;
      }

      FilterLists flObj(noFl, ba, bb, u3, f, nf, pd, pdl);
      FilterLists *flObjPtr = &flObj;

      flObjPtr->formatList();
    }

    break;

    case 99:{
      cout << "Quitting program....." << endl;
      exit(0);
    }

    break;

    default:
      cout << "Invalid input. Exiting....." << endl;
  }

  cout << "Press any key to return to main menu" << endl;
  cin.ignore();
  cin.get();

  if(choice != 99){
    system("clear");
    displayMenu();
  }
}
