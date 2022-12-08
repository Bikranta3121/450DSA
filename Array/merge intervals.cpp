class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        int x=intervals[0][0];
        int y=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
           if(x<=intervals[i][0] and intervals[i][0]<=y)
            y=max(intervals[i][1],y);
           else
           {
               v.push_back({x,y});
               x=intervals[i][0];
               y=intervals[i][1];
           } 
        }
        v.push_back({x,y});
        return v;

    }
};
