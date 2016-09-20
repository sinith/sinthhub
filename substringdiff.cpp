#include<bits/stdc++.h>
#define bs 1000000007
using namespace std;
int tests;
int ans;
int dp[500][500];
int solve(string st1, string st2)
{
for (int i = 0; i <= st1.size(); i++)
{
for (int j = 0; j <= st2.size(); j++)
{
dp[i][j] = 0;
}
}
for (int i = 0; i < st2.size(); i++)
{
if (st2[i] == st1[0])
dp[1][i+1] = 1;
if (i)
dp[1][i+1] += dp[1][i];
}
for (int i = 1; i < st1.size(); i++)
{
for (int j = 0; j < st2.size(); j++)
{
dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
if (st1[i] == st2[j])
{
dp[i + 1][j + 1] += dp[i][j];
}
dp[i + 1][j + 1] = (dp[i + 1][j + 1] % bs);
if (dp[i + 1][j + 1] < 0)
dp[i + 1][j + 1] += bs;
}
}
return dp[st1.size()][st2.size()];
}
int main(){
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin >> tests;
for (; tests; --tests)
{
ans = 0;
string st;
cin >> st;
for (int cp = 1; cp < st.size(); cp++)
{
string st1, st2;
for (int i = 0; i < st.size(); i++)
{
if (i < cp)
st1 += st[i];
else
st2 += st[i];
}
ans += solve(st2, st1);
ans %= bs;
}
cout << ans << endl;
}
return 0;
}

