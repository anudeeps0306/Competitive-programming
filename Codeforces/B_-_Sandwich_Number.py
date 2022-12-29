a = input()



# if(a[0]>='A' and a[0]<='Z' and len(a)>=8 and a[0].isalpha()):
#     if(a[1:7].isalpha()):
#          print("No")   
                
#     else:
#         if(a[7]>='A' and a[7]<='Z'  and a[7].isalpha()):
#             if(int(a[1:7])>=100000 and int(a[1:7])<=999999):
#                 print("Yes")
#             else:
#                 print("No")  
#         else:
#             print("No")
       
# else:
#     print("No")
# 
flag = 1                     

for i in range(0,10):
    if(a[0:i].isalpha()):
        flag=1
        break
    else:
        flag=0

if(i<9 and flag!=0):
    for j in range(i,10):
        if(a[i:j].isnumeric()):
            if(int(a[i:j])>=100000 and int(a[i:j])<=999999):
                flag=1
                break
            else:
                flag=0    
        else:
            flag=0 

if(j<9 and flag!=0):
    for k in range(j,10):
        if(a[j:k].isalpha):
            flag=1
            break 
        else:
            flag=0
else:
    flag=0

if(flag == 1): 
    print("Yes")
else:
    print("No")    