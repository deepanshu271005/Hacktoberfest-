class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<spells.size();i++){
              
          long long num=spells[i];
          int myindex=-1;

          int low=0;
          int high=potions.size()-1;
          int mid;
          while(low<=high){
            mid=(low+high)/2;
           long long strength=num*potions[mid];
            
             if(strength>=success){
                myindex=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
          }
          if(myindex==-1){
            ans.push_back(0);//no strength is stronger than the success

          }
          else{
            ans.push_back(potions.size()-myindex);
          }

        }   

      return ans ;
    }
};
