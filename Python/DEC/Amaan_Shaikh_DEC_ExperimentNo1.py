import requests
import pandas as pd
import numpy as np

# Step 1: Identify and retrieve the dataset
# URL to the Iris dataset
"""
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data"

# Send an HTTP GET request to the URL to download the dataset
response = requests.get(url)

# Save the dataset locally
with open("iris.csv", "wb") as file:
    file.write(response.content)
"""
# Step 1: Read the CSV file using Pandas
# Read the CSV file into a Pandas DataFrame
df = pd.read_csv("F:\College Stuff Degree\DEC\IRIS dataset\IRIS Dataset\iris.csv",
                 header=None, names=["sepal_length", "sepal_width", "petal_length", "petal_width", "class"])

# Step 2: Perform various operations on the dataset
# Display the first few rows of the DataFrame
print("Head:")
print(df.head())

# Display the last few rows of the DataFrame
print("\nTail:")
print(df.tail())

# Generate summary statistics of the DataFrame
print("\nDescribe:")
print(df.describe())

# Get a summary of the DataFrame (number of non-null values, data types, etc.)
print("\nSummary:")
print(df.info())

# One command of your choice (e.g., getting the unique classes in the 'class' column)
print("\nUnique Classes:")
print(df["class"].unique())
