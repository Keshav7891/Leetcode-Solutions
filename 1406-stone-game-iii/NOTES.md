{
int op3 = nums[i]+nums[i+1]+nums[i+2] - help(i+3,nums);
score = max(score,op3);
}
return score;
}
string stoneGameIII(vector<int>& stoneValue)
{
int res = help(0, stoneValue);
if(res==0)
{
return "Tie";
}
else if(res>1)
{
return "Alice";
}
else
{
return "Bob";
}
}
};