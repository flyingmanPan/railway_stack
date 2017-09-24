#include <iostream>
#include <stack>
#include <vector>
#define test
using namespace std;

bool find(vector<int> &data,vector< stack<int> > &v_stack,
			uint64_t &num,vector<int> &result)
{
	bool found=false;
	stack<int> tmp;
	while(!data.empty())
	{
		if(data.back()!=num)
		{
			tmp.push(data.back());
			data.pop_back();
		}
		else
		{
			found=true;
			cout<<"found in raw data!\n";
			result.push_back(data.back());
			data.pop_back();
			break;
		}
	}
	if(data.empty()&&!tmp.empty()&&!found)
	{
		while(!tmp.empty())
		{
			data.push_back(tmp.top());
			tmp.pop();
		}
	}
	if(!tmp.empty()&&found)
		v_stack.push_back(tmp);
	
	if(!v_stack.empty()&&!found)
	{
		stack<int> tmp2;
		int time=0;
		int size=v_stack.size();
		for(auto i=v_stack.begin();i!=v_stack.end();i++)
		{
			cout<<time<<endl;
			if(time==size||found)
				break;
			while((*i).size()!=0&&!found)
			{
				if((*i).top()!=num)
				{
					tmp2.push((*i).top());
					(*i).pop();
				}
				else
				{
					result.push_back((*i).top());
					(*i).pop();
					found=true;
				}
			}
			time++;
			#ifdef test
				auto j=tmp2;
				cout<<" In temp:";
				while(!j.empty())
				{
					cout<<j.top()<< " ";
					j.pop();
				}
				cout<<endl;
			#endif
			if(found&&!tmp2.empty())
				v_stack.push_back(tmp2);
			else
			{
				while(!tmp2.empty())
				{
					(*i).push(tmp2.top());
					tmp2.pop();
				}
			}
		}
	}
	num++;
	return true;
}

void display(vector<int> &data,vector< stack<int> > &v_stack,
			uint64_t &num,vector<int> &result)
{
	cout<< "In data:";
	for(auto i:data)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	
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
	
	cout<< "In result:";
	for(auto i:result)
	{
		cout<<i<<" ";
	}
	cout<<endl<<endl;
}

int main()
{
	uint16_t len=0;
	uint64_t num=1;
	vector<int> data;
	vector< stack<int> > v_stack;
	vector<int> result;
	#ifndef test
		cin>>len;
		auto len2=len;
		while(len2--)
		{
			uint16_t temp;
			cin>>temp;
			data.push_back(temp);
		}
	#endif
	
	#ifdef test
		len=7;
		data.push_back(3);
		data.push_back(4);
		data.push_back(1);
		data.push_back(6);
		data.push_back(5);
		data.push_back(7);
		data.push_back(2);
	#endif
	
	cout<< "part 1 done"<<endl;
	//while(result.size()<len)
	int cmd;
	while(1)
	{
		if(num!=len)
		{
			find(data,v_stack,num,result);
			display(data,v_stack,num,result);
		}
			
		else
			break;
	}
	
	return 0;
}
