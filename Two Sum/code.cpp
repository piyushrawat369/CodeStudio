#include<algorithm>
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
    vector<pair<int,int>> solution;
    sort(arr.begin(),arr.end());
    int start_index=0;
    int end_index=arr.size()-1;
for(int start_index=0;start_index<=end_index-1;)
    {
        if(arr[start_index]+arr[end_index]==target)
        {
             pair<int,int> pairing(arr[start_index],arr[end_index]);
             solution.push_back(pairing);
              start_index++;
              end_index--;
        }
        else if(arr[start_index]+arr[end_index]<target)
        {
            start_index++;
        }
        else
        {
            end_index--;
        }
    }
        if(solution.size()==0)
        {
            pair<int,int>pairing(-1,-1);
            solution.push_back(pairing);
            return  solution;
        }
          
    
    return solution;
}
