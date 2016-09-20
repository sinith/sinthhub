import sys
a=input()
b=input()
l=len(a)
cnt=0
final=0
def pas(i,j,p,cnt):
    for q in range(i+1,l):
        for r in range(j+1,l):
            if a[q]==b[r] and r>p:
         
                cnt+=1
                p=r
                break
                
    return cnt            
        
for i in range(0,l):
    cnt=0
    for j in range(0,l):
        if a[i]==b[j]:
            cnt+=1
    
            p=j
            no=pas(i,j,p,cnt)
            best=max(no,final)
            final=best
            break
            
print (final)       
