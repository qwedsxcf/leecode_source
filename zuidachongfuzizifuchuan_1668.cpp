class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int len_word=int(word.size());//获取字符串word长度
        int len_seq=int(sequence.size());//获取字符串seq长度
        int idx_seq=0;//标记字符串seq中的索引
        if (len_seq<len_word){
            return 0;//seq长度小于word长度，直接返回0
        }
        int res=0;//最终返回的结果
        int k=0;//统计当轮结果
        bool flag=false;//标记是否需要进行回退
        while(idx_seq<len_seq){//还没检测完
            for(int i=0;i<len_word;i++){//逐个匹配word中的每个字符
                if(sequence[idx_seq+i]!=word[i]){//发现有个字符不匹配
                    if(flag){//需要回退，
                        idx_seq=idx_seq-len_word+1;//索引回退
                        flag=false;//置为FALSE，防止连续多次回退
                    }
                    else{//无需回退，索引加一
                        idx_seq=idx_seq+1;
                    }
                    res=res<k ? k : res;//及时保存最新的k
                    k=0;
                    break;//退出for循环
                }
                if(i==len_word-1){//匹配成功一轮
                    idx_seq=idx_seq+i+1;
                    k++;
                    res=res<k ? k : res;
                    flag=true;//标记允许回退,针对一下这种情况
                    /*"aaabaaaabaaabaaaabaaaabaaaabaaaaba"
                    "aaaba"*/
                }
            }
        }
        return res;
    }
};
