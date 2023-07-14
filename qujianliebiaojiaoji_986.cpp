class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;

        int len1=int(firstList.size());
        int len2=int(secondList.size());
        if (len1==0){
            return res;
        }
        else if(len2==0){
            return res;
        }
        
        int idx1=0;
        int idx2=0;
        while (idx1<len1 && idx2<len2){
            if((firstList[idx1][1]-firstList[idx1][0])<=(secondList[idx2][1]-secondList[idx2][0])){
                if(secondList[idx2][0]<firstList[idx1][0]&&secondList[idx2][1]<=firstList[idx1][1]&&secondList[idx2][1]>=firstList[idx1][0]){
                    res.push_back({firstList[idx1][0],secondList[idx2][1]});
                    idx2++;
                }
                else if(secondList[idx2][0]<=firstList[idx1][0]&&secondList[idx2][1]>=firstList[idx1][1]){
                    res.push_back({firstList[idx1][0],firstList[idx1][1]});
                    idx1++;
                }
                else if(secondList[idx2][0]>firstList[idx1][0]&&secondList[idx2][0]<=firstList[idx1][1]&&secondList[idx2][1]>firstList[idx1][1]){
                    res.push_back({secondList[idx2][0],firstList[idx1][1]});
                    idx1++;
                }
                else{
                    if(firstList[idx1][0]>secondList[idx2][1]){
                        idx2++;
                    }
                    else{
                        idx1++;
                    }
                }
                //cout<<1<<idx1<<" "<<idx2<<endl;
            }
            else{
                if(secondList[idx2][0]<firstList[idx1][0]&&secondList[idx2][1]<firstList[idx1][1]&&secondList[idx2][1]>=firstList[idx1][0]){
                    res.push_back({firstList[idx1][0],secondList[idx2][1]});
                    idx2++;
                }
                else if(secondList[idx2][0]>=firstList[idx1][0]&&secondList[idx2][1]<=firstList[idx1][1]){
                    res.push_back({secondList[idx2][0],secondList[idx2][1]});
                    idx2++;
                }
                else if(secondList[idx2][0]>firstList[idx1][0]&&secondList[idx2][0]<=firstList[idx1][1]&&secondList[idx2][1]>firstList[idx1][1]){
                    res.push_back({secondList[idx2][0],firstList[idx1][1]});
                    idx1++;
                }
                else{
                    if(firstList[idx1][0]>secondList[idx2][1]){
                        idx2++;
                    }
                    else{
                        idx1++;
                    }
                }
                //cout<<2<<idx1<<" "<<idx2<<endl;
            }
        }
        return res;

    }
};
