#-------------------------------------------------------------------------------
# Name:        Indexer-HHAK
# Purpose:     IR Project Part1 , Uses Patricia in Python
#
# Author:      Anil Kag
#
# Created:     05/09/2013
# Copyright:   (c) Anil Kag 2013
# Licence:     GPLv3
#-------------------------------------------------------------------------------

#! python2.7

# TRIE
from patricia import PatriciaTrie

# PreProcessing imports
from preprocess import preprocess

# Serialization and Deserialization
import pickle

# Sizeof object
import sys
import os

class indexer:
    # load the index from a saved file
	def loadFromFile (self, indexFile):
		# TODO assert that trie should be empty right now,
		# otherwise you'll loose the index
		fp = open(indexFile, 'rb')
		self.index = pickle.load (fp)
		self.modified = False

	# initialize a new TRIE
	def __init__ (self):
		self.index = PatriciaTrie ()
		self.modified = True

    # insert keyData Pairs in index
	def insertWord (self, key, data):
		# TODO assert that same word doesn't repeat
		self.modified = True
		self.index.insert(key, data)

    # Search the word in index, if found return the data found
	def searchWord (self, word):
		try:
			return self.index.lookup (word)
		except KeyError:
			print "Oops.. Key Error"
			return None

    # save index to fileName
	def saveIndex (self, fileName):
		if self.modified:
			fp = open (fileName, 'wb')
			pickle.dump (self.index, fp)

def main ():
	index = indexer ()
	wordToDoc, docToWord = preprocess("cacm.all")
	print "Start Indexing"
	for word in wordToDoc:
		#print word
		postingList = []
		for id in wordToDoc[word]:
			postingList.append((id,wordToDoc[word][id]))		
		# insert the word,list through API
		index.insertWord (word, postingList)

	print "Done Indexing"
	#for id,fq in index.index["use"]:
	#	print id + "," + str(fq)

	fileName = "version_index_patricia1.ind"
	index.saveIndex (fileName)
	print "Size of index: " + str(os.path.getsize (fileName)) + "Bytes"
	#print "size of index: " + str(sys.getsizeof (index)) + "Bytes"
    

if __name__ == '__main__':
    main()