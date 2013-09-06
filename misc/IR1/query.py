import math
import operator
from stemming.porter2 import stem
import nltk
from indexer import indexer, indexCacm, loadIndexFromDisk
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

def query(q, index, docSizeDic, avgLen):
    d = {}
    word_list = word_tokenize(q)
    for word in word_list:
        word = word.lower()
        stemmed_word = stem(word)
        if stemmed_word not in stopwords.words('english'):
            post_list = index.searchWord(stemmed_word)
            for docid, tf in post_list:
		score = bm25(idf_bad(len(docSizeDic), len(post_list)), tf, docSizeDic[docid], avgLen, 0.75, 1.5)
                d[docid] = d.get(docid, 0) + score
    sorted_d = sorted(d.iteritems(), key=operator.itemgetter(1))
    sorted_d.reverse()
    return sorted_d


cacmDataSet = "cacm.all"
def main():
    index, docSizeDic, avgLen = indexCacm ("cacm.all")
    while 1:
    	q = raw_input('Enter a query: ')
    	d = query(q, index, docSizeDic, avgLen)
	if d != None:    	
	    for docid, score in d:
        	print str(docid)+" "+str(score)
	else:
            print "No Results";

if __name__ == '__main__':
    main()
