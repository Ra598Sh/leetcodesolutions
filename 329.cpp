class Solution {
public:
    int dp[1000][1000];
    int cal(int i,int j,int n,int m,vector<vector<int> >& arr)
    {
        if(i<0||j<0||i>=n||j>=m)
            return 0;
        if(dp[i][j]!=0)
            return dp[i][j];
        int maxer=0;
        dp[i][j]=1;
        int a1=0,a2=0,a3=0,a4=0;
        if(i-1>=0&&arr[i-1][j]>arr[i][j])
            a1=max(dp[i][j],1+cal(i-1,j,n,m,arr));
        if(j-1>=0&&arr[i][j-1]>arr[i][j])
            a2=max(dp[i][j],1+cal(i,j-1,n,m,arr));
        if(i+1<n&&arr[i+1][j]>arr[i][j])
            a3=max(dp[i][j],1+cal(i+1,j,n,m,arr));
        if(j+1<m&&arr[i][j+1]>arr[i][j])
            a4=max(dp[i][j],1+cal(i,j+1,n,m,arr));
        maxer=max(max(a1,a2),max(a3,a4));
        dp[i][j]=max(dp[i][j],maxer);
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0)
            return 0;
        int m=matrix.front().size(),i,j,ans=0;
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
                cal(i,j,n,m,matrix);
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
                ans=max(ans,dp[i][j]);
        return ans;
    }
};