#include<bits/stdc++.h>
using namespace std;
class mystack{
public:
	vector<int> v;
	void push(int x){
		v.push_back(x);
	}
	int size(){
		return v.size();
	}
	int pop(){
		int res = v.back();
		v.pop_back();
		return res;
	}
	int peek(){
		return v.back();
	}
	bool isempty(){
		v.empty();
	}
};
int main()
{
    mystack s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isempty()<<endl;
  
    return 0; 
}