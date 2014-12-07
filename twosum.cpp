class Solution {
	public:
		vector<int> twoSum(vector<int> &numbers, int target) {
			map<int,int> m;
			vector<int> v;
			for(int i=0;i<numbers.size();++i){
				if(m.find(target-numbers[i])==m.end()){
					m[numbers[i]]=i;
				}else{
					if(i<m[target-numbers[i]]){
						v.push_back(i+1);
						v.push_back(m[target-numbers[i]]+1);
					}else{
						v.push_back(m[target-numbers[i]]+1);
						v.push_back(i+1);
					}
				}
			}
			return v;
		}
};
