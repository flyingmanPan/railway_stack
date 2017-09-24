#include <iostream>
#include <stack>
#include <vector>
//#define test
using namespace std;

void display(vector< stack<int> > &v_stack)
{
	auto temp=v_stack;
	for(auto i:temp)
	{
		cout<<"In :";
		while(!i.empty())
		{
			cout<<i.top()<< " ";
			i.pop();
		}
		cout<<endl;
	}
}

int main()
{
	uint16_t len=0;
	uint64_t num=1;
	stack<int> data;
	vector< stack<int> > v_stack;
	cin>>len;
	auto len2=len;
	while(len2--)
	{
		uint16_t temp;
		cin>>temp;
		data.push(temp);
	}

	v_stack.push_back(data);
	v_stack.push_back(data);
	cout<< "part 1 done"<<endl;
	//while(result.size()<len)
	int cmd;
	while(1)
	{
		cin>>cmd;
		if(cmd==1)
		{
			display(v_stack);
		}
		else if(cmd==2)
		{
			auto i=v_stack.begin();
			(*i).pop();
		}
		else
			break;
	}
	
	return 0;
}
