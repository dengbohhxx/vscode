    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code herezzzz
        int aandb=0;
        for(int i=0;i<array.size();i++)
        {
            aandb=aandb^array[i];
        }
        int k=0;
        while(!(aandb&(1<<k)))
        {
            k++;
        }
        int a=0;
        int b=0;
        for(int i=0;i<array.size();i++)
        {
            if(array[i]&(1<<k))
            {
                a=a^array[i];
            }
            else
            {
                b=b^array[i];
            }
        }
        vector<int> vec(2);
        vec[0]=a<=b?a:b;
        vec[1]=a<b?b:a;
        return vec;
    }
};