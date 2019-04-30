#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "FilterLists.h"
using namespace std;

//Initialize filter options.
FilterLists::FilterLists(bool noFl, bool ba, bool bb, bool u3, bool f, bool nf, bool pd, bool pdl){
  noFlags = noFl;
  byAuthor = ba;
  byBook = bb;
  under300 = u3;
  onlyFiction = f;
  onlyNonFiction = nf;
  pubDomain = pd;
  pubDomLink = pdl;

  if(byAuthor == true){
    subStr = "Author: ";
  }

  else if(byBook == true){
    subStr = "Book: ";
  }

  if(noFlags == true){
    onlyFiction == false;
    onlyNonFiction == false;
    pubDomain == false;
    pubDomLink == false;
    under300 == false;
  }
}

//Initialize vector with all information in full_list.txt first.
void FilterLists::initVector(){
  ifstream inFile(fileName);

  if(!inFile.is_open()){
    cerr << "Unable to open input file.\n";
    exit(1);
  }

  while(getline(inFile, temp)){
    vec.push_back(temp);
  }

  inFile.close();
}

//If onlyFiction == true, remove all non-fiction books from vector.
void FilterLists::initFiction(){
  string tempSubStr = "Fiction";
  vector<string> tempVec;

  //If the 3rd element of vec is not equal to "Fiction", erase the first 6 elements and check the new 3rd element, else temporarily assign first 6 elements to tempVec.
  for(count = 0; count < vec.size(); count++){

    if(vec[2] != tempSubStr){
      vec.erase(vec.begin(), vec.begin() + 6);
    }

    else{
      tempVec.insert(tempVec.end(), vec.begin(), vec.begin() + 6);
      vec.erase(vec.begin(), vec.begin() + 6);
    }
  }

  if(!vec.empty()){
    vec.clear();
  }

  vec.assign(tempVec.begin(), tempVec.end());

  if(!tempVec.empty()){
    tempVec.clear();
  }
}

//If onlyNonFiction == true, remove all fiction books from vector.
void FilterLists::initNonFiction(){
  string tempSubStr = "Non-Fiction";
  vector<string> tempVec;

  //If the 3rd element of vec is not equal to "Non-Fiction", erase the first 6 elements and check the new 3rd element, else temporarily assign first 6 elements to tempVec;
  for(count = 0; count < vec.size(); count++){

    ifstream inFile("full_list.txt");

    if(vec[2] != tempSubStr){
      vec.erase(vec.begin(), vec.begin() + 6);
    }

    else{
      tempVec.insert(tempVec.end(), vec.begin(), vec.begin() + 6);
      vec.erase(vec.begin(), vec.begin() + 6);
    }
  }

  if(!vec.empty()){
    vec.clear();
  }

  vec.assign(tempVec.begin(), tempVec.end());

  if(!tempVec.empty()){
    tempVec.clear();
  }
}

//If under300 == true, remove all books that are >= 300 pages from vector.
void FilterLists::initUnder300(){
  vector<string> tempVec;

  //Use stringstream to initialize string element to int-type variable intTemp.
  for(count = 0; count < vec.size(); count++){
    temp = vec[3];
    stringstream sTemp(temp);
    sTemp >> intTemp;

    if(intTemp >= 300){
      vec.erase(vec.begin(), vec.begin() + 6);
    }

    else{
      tempVec.insert(tempVec.end(), vec.begin(), vec.begin() + 6);
      vec.erase(vec.begin(), vec.begin() + 6);
    }
  }

  if(!vec.empty()){
    vec.clear();
  }

  vec.assign(tempVec.begin(), tempVec.end());

  if(!tempVec.empty()){
    tempVec.clear();
  }
}

//If pubDomain == true, remove all books that are not public domain from vector.
void FilterLists::initPubDom(){
  vector<string> tempVec;

  string tempSubStr = "Public Domain: Yes";

  //If the 5th element of vec is not equal to "Public Domain: Yes", erase the first 6 elements and check the new 5th element, else temporarily assign first 6 elements to tempVec.
  for(count = 0; count < vec.size(); count++){
    if(vec[4] == tempSubStr){
      tempVec.insert(tempVec.end(), vec.begin(), vec.begin() + 6);
    }

    vec.erase(vec.begin(), vec.begin() + 6);
  }

  if(!vec.empty()){
    vec.clear();
  }

  vec.assign(tempVec.begin(), tempVec.end());

  if(!tempVec.empty()){
    tempVec.clear();
  }
}

//If pubDomLink == true, remove all public domain books that do not have a link to a free copy from vector.
void FilterLists::initPubDomLink(){
  vector<string> tempVec;
  string tempSubStr = "Public Domain Link: None";

  //If the 6th element of vec is equal to "Public Domain Link: None", erase the first 6 elements and check the new 6th element, else temporarily assign first 6 elements to tempVec;
  for(count = 0; count < vec.size(); count++){
    if(vec[5] == tempSubStr){
      vec.erase(vec.begin(), vec.begin() + 6);
    }

    else{
      tempVec.insert(tempVec.end(), vec.begin(), vec.begin() + 6);
      vec.erase(vec.begin(), vec.begin() + 6);
    }
  }

  if(!vec.empty()){
    vec.clear();
  }

  vec.assign(tempVec.begin(), tempVec.end());

  if(!tempVec.empty()){
    tempVec.clear();
  }
}

//Format output of book information from vector.
void FilterLists::formatList(){
  vector<string> tempVec;

  //Initialize the vector with the contents of full_list.txt.
  initVector();

  //Check the filter options that were sent from main.
  checkFlags();

  //add "Genre: " prefix to vec[2].
  vec[2] = ("Genre: " + vec[2]);
  int genreCount = 0;
  for(count = 3; count < vec.size(); count++){
    ++genreCount;

    if(genreCount == 6){
      vec[count] = "Genre: " + vec[count];
      genreCount = 0;
    }
  }

  //Add "Number of Pages: " prefix to vec[3].
  vec[3] = ("Number of Pages: " + vec[3]);
  int pgNumCount = 0;
  for(count = 4; count < vec.size(); count++){
    ++pgNumCount;

    if(pgNumCount == 6){
      vec[count] = "Number of Pages: " + vec[count];
      pgNumCount = 0;
    }
  }

  for(count = 0; count < vec.size(); count++){

    //If byBook == true, swap the first two vector elements so the book title is the first element.
    if(byBook == true){
      swap(vec[0], vec[1]);
    }

    //Append only author or book title (whichever is to be output first) to tempVec.
    tempVec.insert(tempVec.end(), vec[0]);

    //Append first 6 elements to formattedVec and erase them from vec.
    formattedVec.insert(formattedVec.end(), vec.begin(), vec.begin() + 6);
    vec.erase(vec.begin(), vec.begin() + 6);
  }

  //Make sure vec is empty
  if(!vec.empty()){
    vec.clear();
  }

  //Assign authors or book titles (Whichever is to be output first) to vec.
  vec.assign(tempVec.begin(), tempVec.end());

  if(!tempVec.empty()){
    tempVec.clear();
  }

  //Alphabetize vec in ascending order and remove duplicate strings.
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  //This is for controlling the value of count3 below.
  //int i = 2;

  //Compare each string in formattedVec to the strings containing the author's names in vec.
  for(count = 0; count < vec.size(); count++){
    subStr = vec[count];

    //Output author or book title (whichever is set to be output first) and all related info for that author book title.
    //First line is red, 2nd line is cyan, and the rest are green.
    cout << RED_TEXT + ">> " << vec[count] << RESET_TEXT_COLOR << endl;

    //formattedVec[0] is  the author or the book title (whichever was chosen to be displayed first).
    //formattedVec[1] is the book title if formattedVec[0] is the author and vice-versa if formattedVec[0] is the book title.
    for(count2 = 0; count2 < formattedVec.size(); count2 += 6){

      //Compare every 6th element in formattedVec, starting with formattedVec[0]. If it matches vec, print formattedVec[count2 + 1].
      if(formattedVec[count2] == vec[count]){
        cout << CYAN_TEXT << "\t-- " << formattedVec[count2 + 1] << RESET_TEXT_COLOR << endl;

        //Print the 3rd, 4th, 5th, and 6th elements, every 6 elements, if formattedVec[count2 + 1] is printed.
        for(count3 = (count2 + 2); count3 < (count2 + 6); count3++){
          cout << GREEN_TEXT << "\t\t- " << formattedVec[count3] << RESET_TEXT_COLOR << endl;
        }

        cout << endl;
      }
    }
  }

  //Empty both vectors when finished using them.
  vec.clear();
  formattedVec.clear();
}

//Sort vector elements in ascending order.
void FilterLists::sortVector(){
  sort(vec.begin(), vec.end());
}

//Check filter options after calling initVector.
void FilterLists::checkFlags(){
  //If fiction == True, check vec elements and remove all non-fiction.
  if(onlyFiction == true){
    initFiction();
  }

  //If nonFiction == True, check vec elements and remove all fiction.
  if(onlyNonFiction == true){
    initNonFiction();
  }

  //If the page count is greater than 300, erase the first 6 elements, else temporarily store the first 6 elements in formattedVec and erase them from vec.
  if(under300 == true){
    initUnder300();
  }

  //If pubDomain == true, check vec elements and remove all that are not public domain.
  if(pubDomain == true){
    initPubDom();
  }

  //If pubDomLink == true, check vec elements and remove all that do not have a public domain link.
  if(pubDomLink == true){
    initPubDomLink();
  }
}
