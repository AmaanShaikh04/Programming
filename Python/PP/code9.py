import re
S1="hitman hat you gone for bit batting bat"
x = re.findall('bat', S1)
print(x)
x= re.findall('bit', S1)
print(x)
x= re.findall('but', S1)
print(x)
x= re.findall('hat', S1)
print(x)
x= re.findall('hut', S1)
print(x)
x= re.findall('hut', S1)
print(x)

import re
s1="Panda says hello,Panda says good morning"
s2=re.findall("Panda",s1)
print(s2)

#pattern = word and single letter separated by a comma and single space
import re
def valid_name(in_str):
    found = re.search(r'^\w+(,{1}\s{1}[A-Z])$', in_str)
    if found:
        print(in_str, '-contains the pattern.')
    else:
        print(in_str, '-does not contain the pattern.')

valid_name('Harsh, Panda')
valid_name('Panda')
valid_name('Panda H')
valid_name('Harsh, P')