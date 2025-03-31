import nltk
from nltk.tokenize import sent_tokenize, word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
from nltk.tag import pos_tag

# Download necessary NLTK data files
nltk.download('punkt')
nltk.download('stopwords')
nltk.download('averaged_perceptron_tagger')

# Sample text
text = "NLTK is a leading platform for building Python programs to work with human language data."

# Sentence Tokenization
sentences = sent_tokenize(text)
print("Sentence Tokenization:")
print(sentences)

# Word Tokenization
words = word_tokenize(text)
print("\nWord Tokenization:")
print(words)

# Stop Words Filtering
stop_words = set(stopwords.words('english'))
filtered_words = [word for word in words if word.lower() not in stop_words]
print("\nStop Words Filtering:")
print(filtered_words)

# Word Stemming
ps = PorterStemmer()
stemmed_words = [ps.stem(word) for word in filtered_words]
print("\nWord Stemming:")
print(stemmed_words)

# POS Tagging
pos_tags = pos_tag(words)
print("\nPOS Tagging:")
print(pos_tags)
