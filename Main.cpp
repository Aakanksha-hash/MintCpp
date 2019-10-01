#include <iostream>
typedef std::string Mint;

Mint add(Mint a, Mint b)
{
	string ans="";
	int len1 = a.length(), len2 = b.length(), sum=0, carry=0, j=len1-1;
	if(len1 < len2)
	{
		a.swap(b);
		swap(len1, len2);
	}
	while(len1--, len2--)
	{
		sum = int(a[len1])+int(b[len2])-96+carry;
		ans+=sum%10+48;
		carry = sum/10;
	}
	len1++;
	 while(len1--)
	 {
		sum = int(a[len1])-48+carry;
		ans+=sum%10+48;
		carry = sum/10;
	 }
	 if(carry)
	 ans+=carry+48;
	return string(ans.rbegin(), ans.rend());
}

Mint sub(string a, string b)
{
	string ans="";
	int len1 = a.length(), len2 = b.length(), sum=0, carry=0, j=len1-1, neg=0;
	if(len1 < len2)
	{
		a.swap(b);
		swap(len1, len2);
		neg=1;
	}
	
	while(len1--, len2--)
	{
		sum = a[len1]-b[len2]-carry;
		if(sum<0)
		{
			sum+=10;
			carry = 1;
		} else carry = 0;
		ans += sum+48;
	}
	len1++;
	 while(len1--)
	 {
		sum = int(a[len1])-carry;
		ans+=sum;
		carry = 0;
	 }
	 if(neg)
		 ans+='-';
	return string(ans.rbegin(), ans.rend());
}

int main()
{
	Mint str = "98";

	std::cout << str << '\n';
}