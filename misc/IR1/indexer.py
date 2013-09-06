#-------------------------------------------------------------------------------
# Name:        Indexer-HHAK
# Purpose:     IR Project Part1
#
# Author:      Anil Kag
#
# Created:     05/09/2013
# Copyright:   (c) Anil Kag 2013
# Licence:     GPLv3
#-------------------------------------------------------------------------------

#! python2.7

# TRIE
from Bio import triefind
from Bio import trie

# Structure Definitions
from collections import namedtuple
PostingListNode = namedtuple ("PostingList","docId frequency")

# PreProcessing imports
from preprocess import preprocess

# Sizeof object
import sys
import os

class indexer:
    # load the index from a saved file
    def loadFromFile (self, indexFile):
        # TODO assert that trie should be empty right now,
        # otherwise you'll loose the index
        fp = open(indexFile)
        self.index = trie.load (fp)
        self.modified = False

    # initialize a new TRIE
    def __init__ (self):
        self.index = trie.trie ()
        self.modified = True

    # insert keyData Pairs in index
    def insertWords (self, listKeyDataPair):
        self.modified = True
        for key, data in listKeyDataPair:
            self.index[key] = data

    # Search the word in index, if found return the data found
    def searchWord (self, word):
        if self.index.has_key (word):
            return self.index[word]
        return []

    # save index to fileName
    # TODO there's some fuzziness in this work
    def saveIndex (self, fileName):
        if self.modified:
            fp = open (fileName, 'w')
            trie.save (fp, self.index)

#print triefind.match ("hello world", trieobj)
#print trieobj.has_key ("hje")

def indexCacm (dataSet):
    index = indexer ()
    wordToDoc, docToWord = preprocess(dataSet)
    print "Start Indexing"
    for word in wordToDoc:
        #print word
        index.index[word] = []
        for id in wordToDoc[word]:
            index.index[word].append((id,wordToDoc[word][id]))

    print "Done Indexing"
    #for id,fq in index.index["use"]:
    #    print id + "," + str(fq)

    fileName = "version_index_1.ind"
    index.saveIndex (fileName)
    print os.path.getsize (fileName)
    return index, wordToDoc, docToWord
    #print "size of index: " + str(sys.getsizeof (index)) + "Bytes"


#if __name__ == '__main__':
#    main()
