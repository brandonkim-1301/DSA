/** WordCloud.h
 * ===========================================================
 * Name: Brandon Kim, 21 JAN 2021
 * Section: T5A
 * Project: Debugging a Word Cloud
 * Purpose: This project provides code that must be debugged.
 *          Types of errors include compile, runtime, and logic.
 * ===========================================================
 */

#ifndef WORDCLOUD_H
#define WORDCLOUD_H

#include "PEX1.h"

/**
 * @brief Build the word cloud.
 * @param argWordCounts - parallel array with frequency of words
 * @param argFileName - html file to output word cloud to
 * @return returns 1 on success and 0 on failure
 * @pre argWordCount points to array of WordCount values of size argNumWords
 * @post the file named argFileName will be appended to
 */
int BuildWordCloud(WordCount* argWordCount, STRING argFileName, int argNumWords);

#endif  // WORDCLOUD_H