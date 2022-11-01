
# this code is to encrypt the sentence entered by the user to avoid sniffing while sending and receiving messages.

original = input("Enter the sentence to be encrypted: ")

key = 3

encrypted = "".join( [ chr( ord(i) + key )  for i in original ] ) # encrrypting by adding 3 to the ascii code of each character at the sentence

decrypted = "".join( [ chr( ord(i) - key )  for i in encrypted ]) # decrypting by subtracting the added 3  

print("original-->  " , original)
print("encrypted--> " , encrypted)
print("decrypted--> " , decrypted)
