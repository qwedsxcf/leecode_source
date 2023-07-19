class Solution {
public:
    int A(int n){//计算全排列的数目
        int res=1;
        for(int i=1;i<=n;i++){
            res=res*i;
        }
        return res;
    }
    vector<double> dicesProbability(int n) {
        vector<double> res;//用于返回结果
        int all_num=pow(6,n);//n个骰子的全部可能情概况
        cout<<all_num<<"  ";
        //加和结果的最大值为全部是6：6n；最小值为全是1：n
        int sum[6*n+1];//索引i处存储加和是i的所有可能数
        for (int i=0;i<=6*n;i++){
            sum[i]=0;//全部初始化为0
        }
        int num[n];//可能的情况进行排列
        for(int i=0;i<n;i++){
            num[i]=1;//初始化为最小情况，即全部是1
        }
        int cnt=0;//用于统计当次的加和结果
        while(1){
            cnt=0;//每一次循环开始时置为0
            for(int i=n-1;i>=0;i--){
                cnt=cnt+num[i];//计算当次结果的加和
            }
            //用于记录当次结果中分别有几个1、2、3、4、5、6
            int num1=0, num2=0, num3=0, num4=0, num5=0, num6=0;
            for (int i=n-1;i>=0;i--){
                if(num[i]==1){
                    num1++;
                }
                else if(num[i]==2){
                    num2++;
                }
                else if(num[i]==3){
                    num3++;
                }
                else if(num[i]==4){
                    num4++;
                }
                else if(num[i]==5){
                    num5++;
                }
                else if(num[i]==6){
                    num6++;
                }
            }
            //由于存在很多各数字数目相同，但是排列顺序不同的情形，为了减小计算量
            //我们将这些可能情况按照数字从小到大的顺序进行排列，便可以只统计1次
            //但是在统计次数的时候，还是需要把全部的数目算上
            //他的数目就是n给数字的全排列除以各个相同数字的全排列
            //即全排列考虑了相同数字的不同位置，我们需要把重复的结果去除
            sum[cnt]+=A(n)/(A(num1)*A(num2)*A(num3)*A(num4)*A(num5)*A(num6));
            if(cnt==6*n){//算完最大情况了，可以退出了
                break;
            }
            for(int i=n-1;i>=0;i--){
                if(num[i]<6){//把记录当次结果的num从小到大增加
                    num[i]=num[i]+1;
                    for (int j=i+1;j<n;j++){
                        num[j]=num[i];//排在后面的数字大于等于排在前面的数字，因为我们按照从小到大的顺序统计的
                    }
                    break;
                }
                
            }
        }
        cnt=0;
        for(int i=0;i<=6*n;i++){
            cnt=cnt+sum[i];
        }
        cout<<cnt;
        //cout<<cnt;
        for(int i=0;i<=6*n;i++){
            if(sum[i]!=0){
                //保存计算结果
                res.push_back(float(sum[i])/float(cnt));
            }
        }
        return res;
    }
};
