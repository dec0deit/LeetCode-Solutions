class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        map<char,int> mp;
        int i=0;
        for(auto it : s){
            while(mp[it]==0 && i<t.length()){
                if(it==t[i])
                    mp[t[i]]++;
                i++;
            }    
            if(mp[it]==0){
                return false;
                
            }
            mp[it]--;
        }
        
        return true;

    }
};