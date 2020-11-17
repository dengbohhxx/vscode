// 以下内容请不要修改
class Random5 {
public:
	static int randomNumber();
};

class Random7 {
public:
    int rand5() {
        return Random5::randomNumber();
    }
    // 以上内容请不要修改
    

    int randomNumber() {
        // 代码写这里,通过rand5函数随机产生[1,7]
        int random=rand5()-1;
        int res=random*5+rand5()-1;
        while(res>20)
        {
            random=rand5()-1;
            res=random*5+rand5()-1;
        }
        return res%7+1;
    }
};