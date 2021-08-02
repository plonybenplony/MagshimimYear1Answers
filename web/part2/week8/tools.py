class Cipher:
    def encode(str1, n = 3):
    	str2 = ""

    	for i in range(len(str1)):
            if i % 2 == 0 and str1[i].isalpha():
                str2 += chr(ord(str1[i]) + n)
                str2[-1] = ((ord(str2[-1]) - ord('a')) % 26) + ord('a')
            else:
                str2 += str1[i]

    	return str2


    def decode(str1, n = 3):
        prestr = ""
        str2 = ""    

        if str1[3:6].isdecimal():
            n = int(str1[3:6])
            prestr = str1[:6]
            str1 = str1[6:]

        for i in range(len(str1)):
            if i % 2 == 0 and str1[i].isalpha():
                str2 += chr(ord(str1[i]) - n)
                str2[-1] = ((ord(str2[-1]) - ord('a')) % 26) + ord('a')
            else:
        	    str2 += str1[i]     
        return prestr + str2