class OddAppearance {
public:
    vector<int> findOdds(vector<int> arr, int n) {
         vector<int> vec(2,0);
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = temp ^arr[i];
    }
    int k = 1;
    while (   !(temp &(1<<k))   )
    {
        k++;
    }
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & (1 << k))
            a = arr[i] ^ a;
        else
            b = arr[i] ^ b;
    }
        vec[0]=b<a ? b:a;
        vec[1]=b>a ? b:a;
        return vec;// write code here
    }
};