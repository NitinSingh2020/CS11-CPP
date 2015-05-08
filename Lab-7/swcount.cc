#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>


// So we don't have to type "std::" everywhere...
using namespace std;


void initSkipList(set<string>& skipList);
string processWord(string word);
void processText(set<string>& skipList, map<string, int>& wordCounts);
void outputWordsByCount(map<string, int>& wordCounts);


int main()
{
  set<string> skipList;
  map<string, int> wordCounts;

  // Initialize the skip-list.
  initSkipList(skipList);

  // Process the text on console-input, using the skip-list.
  processText(skipList, wordCounts);

  // Finally, output the word-list and the associated counts.
  outputWordsByCount(wordCounts);
}


/*
 * This function initializes the skip-list of words.
 *
 * skipList = the set of words to skip
 */
void initSkipList(set<string>& skipList)
{
  // Use a pre-specified skip-list.

  const char *swords[] = {
    "a", "all", "am", "an", "and", "are", "as", "at",
    "be", "been", "but", "by",
    "did", "do",
    "for", "from",
    "had", "has", "have", "he", "her", "hers", "him", "his",
    "i", "if", "in", "into", "is", "it", "its",
    "me", "my",
    "not",
    "of", "on", "or",
    "so",
    "that", "the", "their", "them", "they", "this", "to",
    "up", "us",
    "was", "we", "what", "who", "why", "will", "with",
    "you", "your",
    0
  };

  for (int i = 0; swords[i] != 0; i++)
    skipList.insert(string(swords[i]));
}


/*
 * This helper-function converts a word to all lower-case, and then removes
 * any leading and/or trailing punctuation.
 *
 * Parameters:
 *   word    The word to process.  It is passed by-value so that it can be
 *           manipulated within the function without affecting the caller.
 *
 * Return value:
 *   The word after all leading and trailing punctuation have been removed.
 *   Of course, if the word is entirely punctuation (e.g. "--") then the result
 *   may be an empty string object (containing "").
 */
string processWord(string word)
{
  /*****************************************/
  /* TODO:  Your implementation goes here! */
  /*****************************************/
  size_t endIdx = word.length() - 1;
  size_t startIdx = endIdx;

  // Convert the word to the lower case
  std::transform(word.begin(), word.end(), word.begin(), ::tolower);

  // Remove all leading and trailing punctuation
  for (size_t i = 0; i < word.length(); i++) {
    if (!ispunct(word[i])) {
      startIdx = i;
      break;
    }
  }

  if (startIdx <= endIdx) {
    for (size_t j = word.length() - 1; j >= 0; j-- ) {
      if (!ispunct(word[j])) {
        endIdx = j;
        break;
      }
    }

  return word.substr(startIdx, endIdx - startIdx + 1);
  }

  return "";
}


void processText(set<string>& skipList, map<string, int>& wordCounts)
{
  /***********************************/
  /* TODO:  Implement this function! */
  /***********************************/
  string word;
  int numberOfWords = 0;
  int numberOfStopWords = 0;

  // Read input until there is no more!
  while (cin >> word)
  {
    // Do something with each word.
    word = processWord(word);

    if (word.length() != 0) {
      numberOfWords++;

      // If a stop-word.
      if (skipList.find(word) != skipList.end()) {
        numberOfStopWords++;
      } else {
        wordCounts[word]++;
      }

    }
  }

  cout << "Total words in document:  " << numberOfWords << endl;
  cout << "Unique words:  " << wordCounts.size() << endl;
  cout << "Skipped " << numberOfStopWords << " words." << endl;
}


/*
 * This helper-function outputs the generated word-list in descending order
 * of count.  The function uses an STL associative container to sort the words
 * by how many times they appear.  Because multiple words can have the same
 * counts, a multimap is used.
 */
void outputWordsByCount(map<string, int>& wordCounts)
{
  multimap<int, string, greater<int> > sortByCount;
  map<string, int>::const_iterator wIter;

  for (wIter = wordCounts.begin(); wIter != wordCounts.end(); wIter++)
    sortByCount.insert(pair<int, string>(wIter->second, wIter->first));

  multimap<int, string>::const_iterator cIter;
  for (cIter = sortByCount.begin(); cIter != sortByCount.end(); cIter++)
    cout << cIter->second << "\t" << cIter->first << endl;
}
