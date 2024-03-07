#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
#include<unistd.h>
#include<vector>
using namespace std;
const int star4_role_sum=24;
const int star4_weapon_sum=18;
const int star3_sum=13;
const string role_pool_name="翩舞歈莲";
const string up_star5_role_name="妮露";
string up_star5_weapon_name[2]={"圣显之钥","磐岩结绿"};
string up_star4_role_name[3]={"香菱","芭芭拉","北斗"};
string up_star4_weapon_name[5]={"西福斯的月光","流浪的晚星","祭礼弓","匣里灭辰","雨裁"};
const string star5_role_name[5]={"琴","迪卢克","莫娜","七七","刻晴"};
const string star5_weapon_name[10]={"阿莫斯之弓","天空之翼","四风原典","天空之卷","和璞鸢","天空之脊","狼的末路","天空之傲","天空之刃","风鹰剑"};
const string star4_role_name[star4_role_sum]={"早柚","罗莎莉亚","雷泽","九条裟罗","云堇","砂糖","香菱","五郎","托马","烟绯","辛焱","迪奥娜","重云","诺艾尔","班尼特","菲谢尔","凝光","行秋","北斗","芭芭拉","久岐忍","鹿野院平藏","柯莱","多莉"};
const string star4_weapon_name[star4_weapon_sum]={"弓藏","祭礼弓","绝弦","昭心","祭礼残章","流浪乐章","匣里灭辰","雨裁","祭礼大剑","匣里龙吟","祭礼剑","笛剑","西风猎弓","西风秘典","西风长枪","钟剑","西风大剑","西风剑"};
const string star3_name[star3_sum]={"弹弓","神射手之誓","鸦羽弓","翡玉法球","讨龙英杰谭","魔导绪论","黑缨枪","以理服人","沐浴龙血的剑","铁影阔剑","飞天御剑","黎明神剑","冷刃"};
int role_sum=1,weapon_sum=1,last_role_star4=0,last_weapon_star4=0;
bool floor=false,purple,gold;
vector<string>v;
bool rate(double p)
{
	int a=rand()%10000+1;
	double b=(double)a/10000;
	if(b<=p)
		return true;
	return false;
}
void role()
{
	double n;
	string ans;
	if(role_sum<=73)n=0.006;
	else if(role_sum==90)n=1;
	else n=0.006+0.06*(role_sum-73);
	bool is_star5=rate(n);
	if(is_star5)
	{
		last_role_star4=1-(role_sum-last_role_star4);
		bool is_up;
		if(floor==false)
			is_up=rate(0.5);
		else
			is_up=true;
		if(is_up)
		{
			ans=up_star5_role_name+" 五星";
			gold=true;
			floor=false;
		}
		else
		{
			int a=rand()%5;
			ans=star5_role_name[a]+" 五星";
			gold=true;
			floor=true;
		}
		role_sum=1;
	}
	else
	{
		double n2;
		if(role_sum-last_role_star4<=8)n=0.051;
		else if(role_sum-last_role_star4==10)n=1;
		else n=0.051+0.51*(role_sum-last_role_star4-8);
		bool is_star4=rate(n);
		if(is_star4)
		{
			last_role_star4=role_sum;
			bool is_up=rate(0.5);
			if(is_up)
			{
				int a=rand()%3;
				ans=up_star4_role_name[a]+" 四星";
				purple=true;
			}
			else
			{
				bool is_role=rate(0.5);
				if(is_role)
				{
					while(1)
					{
						int a=rand()%star4_role_sum;
						if(star4_role_name[a]!=up_star4_role_name[0]&&star4_role_name[a]!=up_star4_role_name[1]&&star4_role_name[a]!=up_star4_role_name[2])
						{
							ans=star4_role_name[a]+" 四星";
							purple=true;
							break;
						}
					}
				}
				else
				{
					int a=rand()%star4_weapon_sum;
					ans=star4_weapon_name[a]+" 四星";
					purple=true;
				}
			}
		}
		else
		{
			int a=rand()%star3_sum;
			ans=star3_name[a]+" 三星";
		}
		++role_sum;
	}
	v.push_back(ans);
}
void weapon()
{
	double n;
	string ans;
	if(weapon_sum<=65)n=0.007;
	else if(weapon_sum==80)n=1;
	else n=0.007+0.07*(weapon_sum-65);
	bool is_star5=rate(n);
	if(is_star5)
	{
		last_weapon_star4=1-(weapon_sum-last_weapon_star4);
		bool is_up=rate(0.75);
		if(is_up)
		{
			int a=rand()%2;
			ans=up_star5_weapon_name[a]+" 五星";
			gold=true;
			floor=false;
		}
		else
		{
			int a=rand()%10;
			ans=star5_weapon_name[a]+" 五星";
			gold=true;
			floor=true;
		}
		weapon_sum=1;
	}
	else
	{
		double n2;
		if(weapon_sum-last_weapon_star4<=8)n=0.06;
		else if(weapon_sum-last_weapon_star4==10)n=1;
		else n=0.06+0.6*(weapon_sum-last_weapon_star4-8);
		bool is_star4=rate(n);
		if(is_star4)
		{
			last_weapon_star4=weapon_sum;
			bool is_up=rate(0.75);
			if(is_up)
			{
				int a=rand()%5;
				ans=up_star4_weapon_name[a]+" 四星";
				purple=true;
			}
			else
			{
				while(1)
				{
					int a=rand()%star4_weapon_sum;
					bool tag=false;
					for(int i=0;i<5;++i)
						if(star4_weapon_name[a]==up_star4_weapon_name[i])
							tag=true;
					if(tag==false)
					{
						ans=star4_weapon_name[a]+" 四星";
						purple=true;
						break;
					}
				}
			}
		}
		else
		{
			int a=rand()%star3_sum;
			ans=star3_name[a]+" 三星";
		}
		++weapon_sum;
	}
	v.push_back(ans);
}

void print()
{
	for(int i=0;i<v.size();++i)
	{
		sleep(1);
		cout<<v[i]<<endl;
	}
	v.clear();
}
void pool(int x)
{
	string n;
	while(1)
	{
		cout<<"a.祈愿一次/b.祈愿十次"<<endl;
		cin>>n;
		if(n=="a")
		{
			purple=false;
			gold=false;
			if(x==1)
				role();
			else if(x==2)
				weapon();
			if(gold==true)
			{
				cout<<"一道金光划过天边"<<endl;
				sleep(2);
				print();
			}
			else if(purple==true)
			{
				cout<<"一道紫光划过天边"<<endl;
				sleep(2);
				print();
			}
			else
			{
				cout<<"一道蓝光划过天边"<<endl;
				sleep(2);
				print();
			}
		}
		else if(n=="b")
		{
			purple=false;
			gold=false;
			for(int i=0;i<10;++i)
			{
				if(x==1)
					role();
				else if(x==2)
					weapon();
			}
			if(gold==true)
			{
				cout<<"一道金光划过天边"<<endl;
				sleep(2);
				print();
			}
			else if(purple==true)
			{
				cout<<"一道紫光划过天边"<<endl;
				sleep(2);
				print();
			}
			else
			{
				cout<<"一道蓝光划过天边"<<endl;
				sleep(2);
				print();
			}
		}
		else if(n=="quit")exit(0);
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	cout<<"原神抽卡模拟器（输入quit结束程序）"<<endl;
	cout<<"本期up："<<endl;
	cout<<"[1]"<<role_pool_name<<"："<<endl;
	cout<<up_star5_role_name<<" 五星"<<endl;
	for(int i=0;i<3;++i)
		cout<<up_star4_role_name[i]<<" 四星"<<endl;
	cout<<"[2]神铸赋形："<<endl;
	cout<<up_star5_weapon_name[0]<<" 五星"<<endl;
	cout<<up_star5_weapon_name[1]<<" 五星"<<endl;
	for(int i=0;i<5;++i)
		cout<<up_star4_weapon_name[i]<<" 四星"<<endl;
	string n;
	while(1)
	{
		cout<<"请选择up池：";
	
		cin>>n;
		if(n=="1")pool(1);
		else if(n=="2")pool(2);
		else if(n=="quit")exit(0);
	}
	return 0;
}
