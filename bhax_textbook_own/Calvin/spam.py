import numpy as np  # importing numerical computing package
from urllib.request import urlopen  # importing url handling
from sklearn import model_selection as ms # importing model selection tools
from sklearn import linear_model as lm #  importing linear models
from sklearn import naive_bayes as nb #  importing naive Bayes classifiers
from sklearn import metrics #  importing performance metrics
from matplotlib import pyplot as plt  # importing MATLAB-like plotting framework
import itertools

class Assess(object):
	def __init__(self):
		self.values_url = 'https://arato.inf.unideb.hu/ispany.marton/DataMining/Practice/Datasets/spamdata.csv'
		self.names_url = 'https://arato.inf.unideb.hu/ispany.marton/DataMining/Practice/Datasets/spambase.names.txt'
		self.data = np.array(object)
		self.attribute_names = []  # list for names
		self.input_names = []
		self.target_names = ['not spam','spam']
		self.X = np.array(object)
		self.y = np.array(object)
		self.X_train = np.array(object)
		self.X_test = np.array(object)
		self.y_train = np.array(object)
		self.y_test = np.array(object)
		self.logreg_classifier = lm.LogisticRegression()


	def readValues(self):
		return np.loadtxt(urlopen(self.values_url), skiprows=1, delimiter=";")  # numpyos filebeolvasás txtbe. 1sor átugrás, rekordok ;-el vannak elvalasztva

	def readNames(self):
		for line in urlopen(self.names_url):
			name = line.decode('utf-8')  # transforming bytes to string
			name = name[0:name.index(':')]  # extracting attribute name from string
			self.attribute_names.append(name)  # append the name to a list
	
	def inputAndTarget(self):
		self.input_names = self.attribute_names[0:56]
		self.X = self.data[:,0:56]
		self.y = self.data[:,57]
		del self.data
	
	def partitionData(self):
		X_train,X_test,y_train,y_test = ms.train_test_split(self.X,self.y,test_size=.3,
		shuffle = True,random_state=2020)

	def fitLogReg(self):
		self.logreg_classifier.fit(self.X_train,self.y_train)
		ypred_logreg = logreg_classifier.predict(X_train)
		

	



	

def separateInputFromTarget():
	X = data[:,0:56]
	y = data[:,57]
	del data
	input_names = attribute_names[0:56]
	target_names = ['not spam','spam']

def partitioning():
	X_train, X_test, y_train, y_test = ms.train_test_split(X,y, test_size=0.3, 
                                shuffle = True, random_state=2020)

def fittingLogisticRegression():
	logreg_classifier = lm.LogisticRegression()
	logreg_classifier.fit(X_train,y_train)
	ypred_logreg = logreg_classifier.predict(X_train)   # spam prediction for train
	cm_logreg_train = metrics.confusion_matrix(y_train, ypred_logreg)
	return cm_logreg_train # train confusion matrix

def visalize():
	mlpc = nn.MLPClassifier(hidden_layer_sizes=(3,))
	mlpc.fit(X_train,y_train)
	yprobab_mlp = mlpc.predict_proba(X_test)
	fpr_mlp,tpr_mlp,_ = metrics.roc_curve(y_test,yprabab_mlp[:,1])
	roc_auc_mlp = metrics.auc(fpr_mlp,tpr_mlp)
	plt.plot(fpr_mlp,tpr_mlp,color='green',lw=lw,label='MLP (area = %0.2f)' % roc_auc_mlp)

""" readDataSetValues()
readDataSetNames()
separateInputFromTarget()
partitioning()
fittingLogisticRegression()

print(fittingLogisticRegression()[1]) """

my_assess = Assess()
my_assess.readValues()
my_assess.readNames()
my_assess.inputAndTarget()
my_assess.partitionData()
