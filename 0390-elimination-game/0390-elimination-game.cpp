class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        int remaining = n;
        bool start_end = false;
        while(remaining > 1){
            if(!start_end || remaining % 2 == 1){
                head += step;
            }
            remaining /= 2;
            step *= 2;
            start_end = !start_end;
        }
        return head;
    }
};

// class Solution {
// public:
//     int lastRemaining(int n) {
//         vector<int> arr;
//         for(int i = 1; i <= n; i++){
//             arr.push_back(i);
//         }
//         bool start_end = false;
//         while(arr.size() > 1){
//             vector<int> temp;

//             if(!start_end){
//                 for(int i = 1; i < arr.size(); i+=2){
//                     temp.push_back(arr[i]);
//                 }
//             }else{
//                 for(int i = arr.size() - 2; i >= 0; i-=2){
//                     temp.push_back(arr[i]);
//                 }
//                 reverse(temp.begin(), temp.end());
//             }
//             arr = temp;
//             start_end = !start_end;
//         }
//         return arr[0];
//     }
// };