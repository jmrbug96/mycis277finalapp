#ifndef FILTERLISTS_H
#define FILTERLISTS_H
using namespace std;

class FilterLists{
  public:
    //Set filter options that were set in main.
    FilterLists(bool noFl, bool ba, bool bb, bool u3, bool f, bool nf, bool pd, bool pdl);

    //Initialize vector with all information from full_list.txt first.
    void initVector();

    //Format output of book information from vector.
    void formatList();

    //If onlyFiction == true, remove all non-fiction books from vector.
    void initFiction();

    //If onlyNonFiction == true, remove all fiction books from vector.
    void initNonFiction();

    //If under300 == true, remove all books that are >= 300 pages from vector.
    void initUnder300();

    //If pubDomain == true, remove all books that are not public domain from vector.
    void initPubDom();

    //If pubDomLink == true, remove all public domain books that do not have a link to a free copy from vector.
    void initPubDomLink();

    //Alphabetize vector in ascending order.
    void sortVector();

    //Check filter options after calling initVector.
    void checkFlags();

  private:
    const string RED_TEXT = "\033[31;1m";
    const string CYAN_TEXT = "\033[36;1m";
    const string GREEN_TEXT = "\033[32;1m";
    const string RESET_TEXT_COLOR = "\033[0m";
    string temp, temp2;
    int count, count2, count3, intTemp;
    vector<string> vec, formattedVec;
    const string fileName = "full_list.txt";
    string subStr;

    //Filter options.
    bool noFlags, byAuthor, byBook, under300, onlyFiction, onlyNonFiction, pubDomain, pubDomLink;
};

#endif //FILTERLISTS_H
