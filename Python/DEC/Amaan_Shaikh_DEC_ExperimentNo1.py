import requests
import pandas as pd
from scipy import stats
from sklearn.preprocessing import MinMaxScaler
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
# Read the CSV file into a Pandas DataFrame, skipping the first row
df = pd.read_csv("F:\\College Stuff Degree\\DEC\\Nifty 50\\Nifty 50\\TATASTEEL.csv",
                 skiprows=1, header=None,
                 names=["Date", "Symbol", "Series", "Prev Close", "Open", "High", "Low", "Last", "Close", "VWAP", "Volume", "Turnover", "Trades", "Deliverable Volume", "%Deliverble"])

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

null_counts = df.isnull().sum()
print("\nNull Value Counts:")
print(null_counts)

print("\nNULL values filled with 0")
# Fill null values with zeros
df.fillna(0, inplace=True)

null_counts = df.isnull().sum()
print("\nNull Value Counts:")
print(null_counts)

# Convert "Date" column to datetime format
df["Date"] = pd.to_datetime(df["Date"])

# Extract the year from the "Date" column and create a new column "Year"
df["Year"] = df["Date"].dt.year

# Calculate the rise or fall in the stocks each year
# Group by "Year" and calculate the difference between the first and last "Close" values in each group
yearly_changes = df.groupby("Year")["Close"].last() - df.groupby("Year")["Close"].first()

# Display the rise or fall for each year
print("\nYearly Rise/Fall:")
print(yearly_changes)

# Calculate mean, median, and mode for "Open" column
mean_open = df["Open"].mean()
median_open = df["Open"].median()
mode_open = df["Open"].mode()[0]  # Using Pandas' mode function

print("\nMean Open:", mean_open)
print("Median Open:", median_open)
print("Mode Open:", mode_open)

# Remove duplicates
df.drop_duplicates(inplace=True)

print("\nAfter Removing Duplicates:")
print(df.head())

# Handling outliers (example: removing rows with abnormally high "Volume")
outlier_threshold = 1000000
df = df[df["Volume"] < outlier_threshold]

print("\nAfter Handling Outliers:")
print(df.head())

# Data normalization (scaling numerical features to a common range)
scaler = MinMaxScaler()
numerical_columns = ["Prev Close", "Open", "High", "Low", "Last", "Close", "VWAP", "Volume", "Turnover", "Trades", "Deliverable Volume", "%Deliverble"]
df[numerical_columns] = scaler.fit_transform(df[numerical_columns])

print("\nAfter Data Normalization:")
print(df.head())

# Data validation: Removing rows with inconsistent or unrealistic values
df = df[(df["Open"] <= df["High"]) & (df["Open"] >= df["Low"])]

print("\nAfter Data Validation:")
print(df.head())

"""
# One command of your choice (e.g., getting the unique classes in the 'last' column)
print("\nUnique Classes:")
print(df["last"].unique())
"""
