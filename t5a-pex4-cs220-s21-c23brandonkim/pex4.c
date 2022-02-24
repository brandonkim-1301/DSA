/** pex4.c
 * ===========================================================
 * Name: Brandon Kim, 24 MAR 2021
 * Section: T5A
 * Project: PEX4
 * Purpose: Use a ternary tree hold a dictionary for a spell checker
 * Documentation: Dr. Bouvier corrected my memory allocation for new nodes and suggested 
 *      calling empty subtree insertions in my insertion function.
 * ===========================================================
 **/

#include "ternaryTree.h"
#include "ternaryTreeUnitTest.h"

int main(int argc, char *argv[]) {

    if(argc < 1) {     // CHANGE TO != 3 FOR FINAL SUBMISSION
        
        // Failure, if no arguments are read
        return 1;
    } 

    // Loads a dictionary text file into a ternary tree
    WordList* dictionary = loadDictionary(argv[1]);
    runAllDictionaryTests(argv[1], dictionary); 
    TernaryTree* wordTree = createTree();
    wordTree = loadTree(wordTree, dictionary);

    // Checks for a balanced tree insertion
    runBalancedTreeInsertionTests(argv[1], dictionary);
    runAllInsertionTests(argv[1], wordTree);

    // Spell checks words using the ternary tree
    spellCheckList(wordTree, argv[2]);

    // Checks the spell checker
    runAllSpellCheckTests();

    // Deletes the dictionary and the ternary tree
    wordListDelete(dictionary);   
    deleteTree(wordTree); 

    return 0;
}