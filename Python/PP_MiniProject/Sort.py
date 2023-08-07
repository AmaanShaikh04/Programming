import matplotlib.pyplot as plt
import numpy as np

import seaborn as sns; sns.set()

def bubble_sort(array):
    n = len(array)
    for i in range(n):
        already_sorted = True
        for j in range(n - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
                already_sorted = False
            # sns.heatmap(np.reshape(array, (5, 5)), cbar=False, ax=ax)
            ax.cla()
            sns.barplot(x=np.arange(n), y=array,
                        hue=(np.arange(n) == j + 1) + 2 * (np.arange(n) > n - i - 1),
                        dodge=False, palette=['turquoise', 'crimson', 'deepskyblue'], ax=ax)
            ax.legend_.remove()
            ax.set_xticks([])

            plt.pause(0.1)
        plt.pause(1)
        if already_sorted:
            break
    return array

fig, ax = plt.subplots()
array = np.random.uniform(2, 100, 10)
bubble_sort(array)