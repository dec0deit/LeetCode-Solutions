/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#define ll long long int
class Solution {
public:
    NestedInteger deserialize(string s) {
        function<bool(char)> isNumber = [](char c){
             return (c == '-') || isdigit(c);
        };
        stack<NestedInteger> st;
        st.push(NestedInteger());
        for(auto it = s.begin() ; it != s.end();){
            if(isNumber
            (*it)){
                auto it2 = find_if_not(it,s.end(),isNumber);
                int val = stoi(string(it,it2));
                st.top().add(NestedInteger(val));
                it = it2;
            }
            else{
                if(*it == '[')
                    st.push(NestedInteger());
                else if(*it == ']'){
                    NestedInteger ni = st.top();
                    st.pop();
                    st.top().add(ni);
                }
                it++;
            }
        }

        NestedInteger result = st.top().getList().front();

        return result;
    }
};
// @lc code=end

