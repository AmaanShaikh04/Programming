import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Read the CSV file into a DataFrame
df = pd.read_csv("F:\\College Stuff Degree\\DEC\\Nifty 50\\Nifty 50\\TATASTEEL.csv",
                 skiprows=1, header=None,
                 names=["Date", "Symbol", "Series", "Prev Close", "Open", "High", "Low", "Last", "Close", "VWAP", "Volume", "Turnover", "Trades", "Deliverable Volume", "%Deliverble"])

# Convert the "Date" column to datetime format
df["Date"] = pd.to_datetime(df["Date"])

# Calculate the minimum and maximum of the "Close" prices
min_price = df["Close"].min()
max_price = df["Close"].max()

# Calculate the z-score of the "Close" prices
df["Close_zscore"] = (df["Close"] - df["Close"].mean()) / df["Close"].std()

# Print the minimum and maximum values
print("Minimum Close Price:", min_price)
print("Maximum Close Price:", max_price)

# Print the z-score values
print("Z-Scores of Close Prices:")
print(df["Close_zscore"])

# Set the style of the plot
sns.set(style="whitegrid")

# Create a figure and axes
fig, ax = plt.subplots()

# Plot the histogram
sns.histplot(df["Close"], bins=20, kde=True, ax=ax)

# Set labels and title
ax.set_xlabel("Close Price")
ax.set_ylabel("Frequency")
ax.set_title("TATASTEEL Close Prices Histogram")

# Calculate the y-axis range based on the close price difference of 100
y_min = min_price - (min_price % 100)
y_max = 800
ax.set_ylim(y_min, y_max)

# Set the y-axis ticks with a difference of 100
y_ticks = range(0, int(y_max) + 100, 100)
ax.set_yticks(y_ticks)

# Set the x-axis ticks with a difference of 100
x_ticks = range(0, int(max_price) + 100, 100)
ax.set_xticks(x_ticks)

# Remove the right and top spines
sns.despine()

# Show the plot
plt.show()