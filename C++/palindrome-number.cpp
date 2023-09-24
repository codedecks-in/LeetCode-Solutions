class Solution {
public:
    bool isPalindrome(int x) {

	int rem=0;long long s=0;
	int temp=x;
	while(x> 0)
	{
		rem=x%10;
		x=x/10;
		s=(s*10)+rem;
	}
	if(temp==s)
	{
		return true;
	}
	else
	{
		return false;
    }
}
};