import math
from stemming.porter2 import stem
import nltk
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
    return log10(num_docs/term_num_docs)

def idf_good(num_docs, term_num_docs):
    return log10((num_docs-term_num_docs+0.5)/(term_num_docs + 0.5))

def tf_good(f, max_f_per_doc):
    return (0.5 + ((0.5*f)/max_f_per_doc))

def query(q, index):
    word_list = word_tokenize(q)
    for word in word_list:
        stemmed_word = stem(word)
        if stemmed_word not in stopwords.words('english'):
            post_list = index.query(stemmed_word)

