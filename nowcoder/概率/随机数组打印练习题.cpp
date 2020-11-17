class RandomPrint {
public:
    vector<int> print(vector<int> arr, int N, int M) {
        // write code here
        int p;
		vector<int> ret;
		for(int i = 0;i < M;++ i){
			p = rand() % (N - i);
			ret.push_back(arr[p]);
			swap(arr[p],arr[N - i - 1]);
		}
		return ret;
    }
};