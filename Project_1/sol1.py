import math
class Solution():
    """docstring for Solution."""

    def __init__(self):
        pass
    def sum(self,A,start,stop):
        sum=0
        for i in range(start,stop+1):
            sum=sum+A[i]
        return sum

    def MMG(self,A,N,M):
        self.C=[[0]*(N) for _ in range(M)]
        self.B=[[-1]*(N) for _ in range(M)]
        self.C[0][0]=A[0]
        for i in range(1,N):
            self.C[0][i]=A[i]+self.C[0][i-1]
        for j in range(1,M):
            for i in range(j,N):
                best_val=-1000
                arg_max=-1
                for k in range(j-1,i):
                    current_val=min(self.C[j-1][k],self.sum(A,k+1,i))
                    if current_val>best_val:
                        best_val=current_val
                        arg_max=k
                self.C[j][i]=best_val
                self.B[j][i]=arg_max
        self.G=[0]*(M)

        column=N-1
        m=M
        while(m>0):
            m=m-1
            self.G[m]=column-self.B[m][column]
            column=self.B[m][column]
        print ("C Matrix is : ",self.C)
        #print ("B Matrix is : ",self.B)
        return (self.G)


sol_obj=Solution()
A=[3,9,7,8,2,6,5,10,1,7,6,4]
answer=sol_obj.MMG(A,len(A),6)
print ("Optimal Grouping of matrix A is :",answer)
