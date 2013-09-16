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
import pickle

class indexer:
    # load the index from a saved file
    def loadFromFile (self, indexFile):
        # TODO assert that trie should be empty right now,
        # otherwise you'll loose the index
        fp = open(indexFile, 'r')
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
            fp = open (fileName, 'wb')
            trie.save (fp, self.index)
            fp.close ()

#print triefind.match ("hello world", trieobj)
#print trieobj.has_key ("hje")

indexFileName = "version_index_1.ind"
docDictionary = "doc_dictionary.dict"

# called only once
def indexCacm (dataSet):
    index = indexer ()
    wordToDoc, docToWord = preprocess(dataSet)
    print "Start Indexing"

    # Index creation for "term -> posting list"
    for word in wordToDoc:
        #print word
        index.index[word] = []
        for id in wordToDoc[word]:
            index.index[word].append((id,wordToDoc[word][id]))

    # Number of terms in document
    docSizeDic = {}
    totalSize = 0
    for doc in docToWord:
	total = 0
	for term in docToWord[doc]:
	    total += docToWord[doc][term]
	docSizeDic[doc] = total
	totalSize += total

    print "Done Indexing"
    #for id,fq in index.index["use"]:
    #    print id + "," + str(fq)

    index.saveIndex (indexFileName)
    print os.path.getsize (indexFileName)

    #fp = open(indexFileName, 'wb')
    #pickle.dump (index, fp)
    #fp.close()
	
    fp = open (docDictionary, 'wb')
    pickle.dump ((docSizeDic, totalSize/len(docSizeDic)), fp)
    fp.close()
    return index, docSizeDic, totalSize/len(docSizeDic)

# Load previous index
def loadIndexFromDisk ():
    fp = open (indexFileName,'rb')
    index = trie.load (fp)
    #index = pickle.load(fp)
    fp.close()

    fp = open(docDictionary, 'rb')
    docDict = pickle.load (fp)
    fp.close()
    return index, docDict[0], docDict[1]

if __name__ == '__main__':
    indexCacm ("cacm.all")

