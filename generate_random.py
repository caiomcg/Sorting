#!/usr/bin/env python

#Add random number to a file

import sys # System options
from random import randint # Randomization
 
if __name__ == "__main__": # Check if executed, not imported
    if len(sys.argv) > 2: # Verify if the amount of arguments is correct
        with open (sys.argv[1], 'a') as f:  # Open the output file
            for element in range(0, int(sys.argv[2])): # Iterate through a range
                f.write(str(randint(0, 1000)) + "\n") # Write the randomized number
