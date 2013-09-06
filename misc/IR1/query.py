import math
import operator
from stemming.porter2 import stem
import nltk
from indexer import indexer, indexCacm
from nltk.corpus import stopwords
from nltk import word_tokenize, wordpunct_tokenize
def bm25(idf, tf, fl, avgfl, B, K1):
    # idf - inverse document frequency
    # tf - term frequency in the current document
    # fl - field length in the current document
    # avgfl - average field length across documents in collection
    # B, K1 - free paramters

    return idf * ((tf * (K1 + 1)) / (tf + K1 * (1 - B + B * (fl / avgfl))))

def idf_bad(num_docs, term_num_docs):
    return math.log10(num_docs/term_num_docs)

def idf_good(num_docs, term_num_docs):
    return math.log10((num_docs-term_num_docs+0.5)/(term_num_docs + 0.5))

def tf_good(f, max_f_per_doc):
    return (0.5 + ((0.5*f)/max_f_per_doc))

def query(q, index, wordToDoc, docToWord):
    d = {}
    word_list = word_tokenize(q)
    for word in word_list:
        word = word.lower()
        stemmed_word = stem(word)
        if stemmed_word not in stopwords.words('english'):
            post_list = index.searchWord(stemmed_word)
            for docid, tf in post_list:
		score = bm25(idf_bad(len(docToWord), len(wordToDoc[stemmed_word])), tf, 1, 1, 0.75, 1.5)
                d[docid] = d.get(docid, 0) + score
    sorted_d = sorted(d.iteritems(), key=operator.itemgetter(1))
    return sorted_d


cacmDataSet = "cacm.all"
def main():
    index, wordToDoc, docToWord = indexCacm (cacmDataSet)
    d = query("What articles exist which deal with TSS (Time Sharing System), an operating system for IBM computers?", index, wordToDoc, docToWord)
    for docid, score in d:
        print str(docid)+" "+str(score)
if __name__ == '__main__':
    main()
