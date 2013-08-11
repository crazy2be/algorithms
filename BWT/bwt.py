def ibwt(r, *args):
        "Inverse Burrows-Wheeler transform. args is the original index \
if it was not indicated by a null byte"
 
        firstCol = "".join(sorted(r))
        count = [0]*256
        byteStart = [-1]*256
        output = [""] * len(r)
        shortcut = [None]*len(r)
        #Generates shortcut lists
        for i in range(len(r)):        	
                shortcutIndex = ord(r[i])
                shortcut[i] = count[shortcutIndex]
                count[shortcutIndex] += 1
                shortcutIndex = ord(firstCol[i])
                if byteStart[shortcutIndex] == -1:
                        byteStart[shortcutIndex] = i
 
        localIndex = (r.index("\x00") if not args else args[0])
        localIndex = 7;
        for i in range(len(r)):
                #takes the next index indicated by the transformation vector
                nextByte = r[localIndex]
                output [len(r)-i-1] = nextByte
                shortcutIndex = ord(nextByte)
                #assigns localIndex to the next index in the transformation vector
                localIndex = byteStart[shortcutIndex] + shortcut[localIndex]
        return "".join(output).rstrip("\x00")
        
print(ibwt("^BANANA|\0"));