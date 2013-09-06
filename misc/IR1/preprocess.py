from stemming.porter2 import stem
import nltk
from nltk.corpus import stopwords
from nltk import word_tokenize, wordpunct_tokenize

class preprocessing:
      dictionary_of_terms = {}
      dictionary_of_docs = {}

def preprocess(filename):
      file_content = open(filename)
      dictionary_docs = {}
      dictionary_terms = {}
      citations = 0
      for line in file_content:
            if line[:2] == ".I":
                  citations = 0
                  doc_id = line[3:]
                  #print doc_id
#                  if int(doc_id) == 3000:
#                        break
                  continue
            elif line[:2] == ".X":
                  citations = 1
            elif line[:1] == ".":
                  citations = 0
                  continue
            
            if citations == 1:
                  continue
            word_list = word_tokenize(line)
            for word in word_list:
		  word = word.lower()
                  stemmed_word = stem(word)
                  if stemmed_word not in stopwords.words('english'):
                        #print stemmed_word
                        if not dictionary_terms.has_key(stemmed_word):
                             dictionary_terms[stemmed_word] = {}
                             dictionary_terms[stemmed_word][doc_id]=1
                        else:
                              if not dictionary_terms[stemmed_word].has_key(doc_id):
                                    dictionary_terms[stemmed_word][doc_id] = 1
                              else:
                                    dictionary_terms[stemmed_word][doc_id] += 1

                        if not dictionary_docs.has_key(doc_id):
                             dictionary_docs[doc_id] = {}
                             dictionary_docs[doc_id][stemmed_word]=1
                        else:
                              if not dictionary_docs[doc_id].has_key(stemmed_word):
                                    dictionary_docs[doc_id][stemmed_word] = 1
                              else:
                                    dictionary_docs[doc_id][stemmed_word] += 1
      
      #print "\nTERMS DICTIONARY\n"                  
      #for words in dictionary_terms:
      #      print words
      #      for ids in dictionary_terms[words]:
      #            print ids + ":," ,
      #            print dictionary_terms[words][ids],
      #            print "->",
      #      print ""

      #print "\nDOCS DICTIONARY\n"
      #for docs in dictionary_docs:
      #      print "DOCS ID " + docs
      #      for terms in dictionary_docs[docs]:
      #            print terms + ":"
      #            print dictionary_docs[docs][terms]

      return dictionary_terms, dictionary_docs

#dictionary_object = preprocessing()
#dictionary_object.dictionary_of_terms, dictionary_object.dictionary_of_docs = preprocess("cacm.all")



