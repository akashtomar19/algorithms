#include<bits/stdc++.h>

using namespace std;
unordered_map<string,bool>mep;
bool part(vector<int>&nums,int i,int sum){
    string s = to_string(sum)+" "+to_string(i);
    if(mep.count(s))return mep[s];
    if(sum==0)return true;
    if(sum<0||i==nums.size())return false;
    
    return mep[s]=part(nums,i+1,sum-nums[i])||part(nums,i+1,sum);
}



bool solve(vector<int>&nums){
    int sum=0;
    for(int i : nums){
        sum+=i;
    }
    int n = nums.size();
    if(sum&1)return false;
    bool dp[sum/2+1][n+1];
    for(int i=0;i<=n;i++){
        dp[0][i]=true;
    }
    for(int i=1;i<=sum/2+1;i++){
        dp[i][0]=false;
    }
    // dp[i][j] is the sum i can be obtained till the elemnet j
    for(int i=1;i<=sum/2;i++){
        for(int j=1;j<=n;j++){
            if(nums[j-1]>i)dp[i][j]=false;
            else dp[i][j]=dp[i-nums[j-1]][j-1]||dp[i][j-1];
        }
    }
    return dp[sum/2][n];
}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>a(n);
	    int sum=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	    }
	    if(sum&1){
	        cout<<"NO"<<endl;
	        continue;
	    }
	    if(part(a,0,sum/2)){
	        cout<<"YES";
	    }else{
	        cout<<"NO";
	    }
	    cout<<endl;
	}
	return 0;
}
