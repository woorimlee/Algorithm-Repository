import sys
import re

T = input()
# css = chromosomes
css = sys.stdin.read().splitlines()

for cs in css : 
    if re.match(r'\b[A-F]?A+F+C+[A-F]?\b', cs) : 
        print("Infected!")
    else : 
        print("Good")
