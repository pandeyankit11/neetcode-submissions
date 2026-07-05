class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0;
        int curr_len=0;
        unordered_map<char,int>m;

        int left=0;

        for(int right=0;right<s.size();right++){
            m[s[right]]++;


            while(m[s[right]]>1){
                m[s[left]]--;
                if(m[s[left]]==0)
                m.erase(s[left]);

                left++;
            }

            max_len=max(max_len,right-left+1);
        }
        return max_len;
    }
};
