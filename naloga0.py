# Naloga 0 v BFFuck jeziku, da se compila v Brainfuck
# Brainfuck očitno ne podpira negativnih števil, tako da ne vpisovati tega notri, hvala
# Za Brainfuck priporočam uporabo [tega](https://copy.sh/brainfuck/) interpreterja

# pip install bffuck

program = """
a=1
b=2
c=in
d=0
m=c
lt(m,3)
if(m)
eq(c,0)
if(c)
out(0)
else
out(1)
endif
else
sub(c,2)
while(c)
sub(c,1)
add(d,a)
add(d,b)
a=b
b=d
d=0
endwhile
out(a)
endif
"""

from bffuck import BFFuck
bff=BFFuck()
bf=bff.compile(program)
print(bf)
