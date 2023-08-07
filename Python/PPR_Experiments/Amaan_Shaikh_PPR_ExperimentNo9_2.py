"""
Experiment No 9
Author: Amaan Shaikh
Branch: TYCO
File name: Amaan_Shaikh_PPR_ExperimentNo9_2.py
"""

import os


try:
    print('Opening file...\n', end='')
    if os.path.isfile('temp.txt'):
        print('File opened successfully!')
    else:
        print('\nError opening file!')
        raise FileNotFoundError()

except FileNotFoundError:
    print('Creating file', end='')
    fx = open('temp.txt', 'x')
    fx.close()
    print('\nFile created!')

while (1):
    print('\nChoose one of the following operations\n1. Read\n2. Write\n3. Append\n4. Close\n')
    choice = int(input("Your Choice: "))

    # Read
    if choice == 1:
        print('\nReading file:\n', end='')

        # opening file in read mode
        fr = open('temp.txt', 'r')
        str1 = fr.read()
        print(str1)
        fr.close()

    # Write
    elif choice == 2:
        print("\nStarting write mode", end='')
        # opening file in write mode
        fw = open('temp.txt', 'w')

        inp = input('\nInput: ')
        fw.write(inp)
        fw.close()

    # Append
    elif choice == 3:
        print("\nStarting append mode", end='')

        # opening file in append mode
        fa = open('temp.txt', 'a')
        inp = input('\nInput: ')
        fa.write(inp)
        fa.close()

    # Close
    elif choice == 4:
        print('\nClosing file', end='')

        print('\nFile has been closed!')
        break
    else:
        print('\nIllegal operation!')