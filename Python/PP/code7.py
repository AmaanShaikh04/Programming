import pandas as pd
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
df = pd.read_csv("C:/Users/Harsh/Desktop/pp/Toyota.csv")
print(df)

#disply first 5 records
df.head()

#disply last 5 records
df.tail()

#shows all attributes with data types
df.info()

#shows statiscal info
df.describe()

#disply data types of attributes
df.dtypes

var=df.columns #To get the column labels of dataframe
print(var)

df.index.values
df.index

df.index #get the index (row labels) of dataframe

# Slice the result for first 5 rows
print(df[0:5]['FuelType'])

# Reading Specific Columns
print (df.loc[:,['FuelType','Age']])

#checking for missing values
df.isnull().sum()

#checking for missing values
df.isnull()

# filling missing value using fillna() 
df.fillna(99,inplace=True)
df.head()

#corr() is used to find the pairwise correlation of all columns in the Pandas Dataframe
data=df.corr()
data.head()


import matplotlib.pyplot as plt
df.hist()
plt.show()

df.plot(kind='density',subplots=True,sharex=False)
plt.show()

df.plot(kind='box',subplots=True,sharex=False,sharey=False)
plt.show()

correlations=df.corr()
fig=plt.figure()
ax=fig.add_subplot(111)
cax=ax.matshow(correlations,vmin=-1,vmax=1)
fig.colorbar(cax)
plt.show()

pd.plotting.scatter_matrix(df)
plt.show()


import seaborn as sns
corel=df.corr()
sns.heatmap(corel, vmax=.8, square=True)
sns.heatmap(corel, vmax=.8, annot=True,square=True)
plt.show()

#lmplot() method is used to draw a scatter plot onto a FacetGrid. Parameters
sns.lmplot(x='Age',y='KM',data=df,fit_reg=False,hue='FuelType',legend=True,palette="Set1")
plt.show()

sns.boxplot(x=df['FuelType'],y=df['KM'])
plt.show()