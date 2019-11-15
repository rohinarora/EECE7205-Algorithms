class Solution():
    def LCSHelper(self,A,B):
        n=len(A)
        m=len(B)
        memo=[[0]*(m+1) for _ in range(n+1)]
        for i in range(n+1):
            for j in range(m+1):
                if (i==0) or (j==0):
                    memo[i][j]=0
                elif A[i-1]==B[j-1]:
                    memo[i][j]=memo[i-1][j-1]+1
                else:
                    memo[i][j]=max(memo[i-1][j],memo[i][j-1])
        return memo
    def longestCommonSubsequence(self,A,B):
        self.memo= self.LCSHelper(A,B)
        print ("Length of LCS is ",self.memo[-1][-1])
        common_subseq=self.reconstruct(A,B)
        print ("LCS is ",common_subseq)
        return self.memo
    def reconstruct(self,A,B):
        n=len(A)
        m=len(B)
        row=n
        col=m
        LCS=""
        while(row>0 and col>0):
            if A[row-1] == B[col-1]:
                LCS=A[row-1]+LCS
                row=row-1
                col=col-1
            elif self.memo[row-1][col] > self.memo[row][col-1]:
                row=row-1
            else:
                col=col-1
        return LCS


sol_obj = Solution()

C = "abcd"
D = "acd"

sol_obj.longestCommonSubsequence(C, D)
