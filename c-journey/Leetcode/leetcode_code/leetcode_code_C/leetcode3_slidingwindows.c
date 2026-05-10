#include <string.h>
int lengthOfLongestSubstring(char* s) 
{
	int len=strlen(s);
	int lastpos[256];
	memset(lastpos,-1,sizeof(lastpos));
	int left=0;
	int maxlen=0;
	
	for(int right=0;right<len;right++)
	{
		unsigned char ch=s[right];
		if(lastpos[ch]>=left)
			left=lastpos[ch]+1;
		
		lastpos[ch]=right;
		
		int current=right-left+1;
		if(current>maxlen)
			maxlen=current;
		
		
	}
    
    return maxlen;
}