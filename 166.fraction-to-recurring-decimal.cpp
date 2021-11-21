class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
      long long num = numerator;
      long long den = denominator;
      if(num == 0){
          return "0";
      }
      int sign = 1;
      sign *= num > 0 ? 1 : -1;
      sign *= den >= 0 ? 1: -1;
      num = abs(num);
      den = abs(den);
      string res="";
      res=to_string(num/den);
      num = num%den;
      vector<int> temp;
      int every = 0;
      while(num!=0){
        temp.push_back(num);
        num *= 10;
        every = num/den;
        res += to_string(every);
        auto it = find(temp.begin(),temp.end(),num);
        if(it != temp.end()){
            
        }
        num = num%den;
        
      }
    }
};
// @lc code=end

