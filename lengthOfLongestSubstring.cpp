#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int lengthOfLongestSubstring(string s){
	map<char,int> m;
	int maxlen=0;
	int start=-1;
	map<char,int>::iterator it;
	for(int i=0;i<s.length();++i){
		it=m.find(s[i]);
		if(i==s.length()-1){
			if(it==m.end()||it->second<start){
				maxlen=max(maxlen,i-start);
			}
		}
		if(it->second>start&&it!=m.end()){
			maxlen=max(maxlen,i-start-1);
			start=it->second;
		}
		m[s[i]]=i;
	}
	return maxlen;
}	
int main(){
	string s="ctclemwwlexnkvwizzoyctqlnzxoetyioavsorrbvoqflpqlqgluzdgoefckaatpdohtgaxdqnlceb";
   	cout<<lengthOfLongestSubstring(s)<<endl;	
}
