import sys
import re

diary = input()
diary = re.sub("([aeiou])p[aeiou]", r"\1", diary)
print(diary)
