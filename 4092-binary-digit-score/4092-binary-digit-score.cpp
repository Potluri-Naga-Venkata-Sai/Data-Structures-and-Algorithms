class Solution {
public:
    int calculateScore(int a, int b) {
        int n1 = a, n2 = b;
        string s1 = "";
        string s2 = "";
        while(n1 > 0){
            s1 += (n1 % 2) + '0';
            n1 /= 2;
        }
        while(n2 > 0){
            s2 += (n2 % 2) + '0';
            n2 /= 2; 
        }

        // reverse(s1.begin(), s1.end());
        // reverse(s2.begin(), s2.end());

        // count one's
        int num1 = stoi(s1);
        int num2 = stoi(s2);
        int cnt1 = 0, cnt2 = 0;
        int result = 0;

        while(num1 > 0){
            int digit = num1 % 10;
            if(digit == 1){
                cnt1++;
            }
            num1 /= 10;
        }

        while(num2 > 0){
            int digit2 = num2 % 10;
            if(digit2 == 1){
                cnt2++;
            }
            num2 /= 10;
        }
        if(cnt1 >= cnt2){
            result = cnt1 * cnt2;
        }else{
            result = cnt2 / cnt1;
        }
        return result;
    }
};