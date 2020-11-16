import numpy as np;  # importing numerical computing package
from urllib.request import urlopen;  # importing url handling
from sklearn import model_selection as ms; # importing model selection tools
from sklearn import linear_model as lm; #  importing linear models
from sklearn import naive_bayes as nb; #  importing naive Bayes classifiers
from sklearn import metrics; #  importing performance metrics
from matplotlib import pyplot as plt;  # importing MATLAB-like plotting framework
import itertools;

def readDataSetValues():
	url = 'https://arato.inf.unideb.hu/ispany.marton/DataMining/Practice/Datasets/spamdata.csv';
	raw_data = urlopen(url);
	data = np.loadtxt(raw_data, skiprows=1, delimiter=";");  # numpyos filebeolvasás txtbe. 1sor átugrás, rekordok ;-el vannak elvalasztva
	del raw_data;

def readDataSetNames():
	url_names = 'https://arato.inf.unideb.hu/ispany.marton/DataMining/Practice/Datasets/spambase.names.txt	';
	raw_names = urlopen(url_names);
	attribute_names = [];   #  list for names
	for line in raw_names:
	    name = line.decode('utf-8');  # transforming bytes to string
	    name = name[0:name.index(':')]; # extracting attribute name from string
	    attribute_names.append(name);  # append the name to a list
	del raw_names;

def separateInputFromTarget():
	X = data[:,0:56];
	y = data[:,57];
	del data;
	input_names = attribute_names[0:56];
	target_names = ['not spam','spam'];

def partitioning():
	X_train, X_test, y_train, y_test = ms.train_test_split(X,y, test_size=0.3, 
                                shuffle = True, random_state=2020);

def fittingLogisticRegression():
	logreg_classifier = lm.LogisticRegression();
	logreg_classifier.fit(X_train,y_train);
	ypred_logreg = logreg_classifier.predict(X_train);   # spam prediction for train
	return cm_logreg_train = metrics.confusion_matrix(y_train, ypred_logreg); # train confusion matrix



readDataSetValues()
readDataSetNames()
separateInputFromTarget()
partitioning()
fittingLogisticRegression()

print(fittingLogisticRegression()[1])