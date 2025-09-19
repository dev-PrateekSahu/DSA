#include<bits/stdc++.h>
using namespace std;

int main (){
    vector<int>nums={4, 6, 3, 2, 0, 8, 9, 1, 7, 5};
    for(int i = 0; i<nums.size()-1; i++){
        cout<<(nums[i]^nums[i+1])<<endl;
    }
}