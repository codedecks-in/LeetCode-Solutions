class Solution {
public:
    vector<int> right_side(vector<int>& heights,int n){
        
        stack<int> arr;
        arr.push(-1);
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            int a = heights[i];
            while(arr.size()>1 && heights[arr.top()] >= a){
                arr.pop();
            } 
            ans[i] = arr.top();
            arr.push(i);
        }
        return ans;

    }
    vector<int> left_side(vector<int>& heights,int n){
        stack<int> arr;
        arr.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int a = heights[i];
            while(arr.size()>1 && heights[arr.top()] >=a){
                arr.pop();
            }
            ans[i] = arr.top();
            arr.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> right;
        vector<int> left;

        right = right_side(heights,heights.size());
        left = left_side(heights,heights.size());


        int ans = 0;
        for(int i=0;i<heights.size();i++){
            
            if(right[i]==-1){
                right[i] = heights.size();
            }
            int length = right[i]-left[i]-1;
            int height = heights[i];
            
            int area = length*height;
            cout<<length<<" "<<height<<" "<< area<<endl;
            ans = max(ans,area);
        }
        return ans;

    }
};