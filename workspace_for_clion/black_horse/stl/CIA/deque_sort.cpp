//
// Created by bruce on 18-6-8.
//

#include<iostream>
#include<deque>
#include <vector>
#include <algorithm>

using namespace std;


class Player{
public:
    Player()= default;
    Player(string name,int score):mName(name),mScore(score){}
public:
    string mName;
    int mScore;
};

void Create_Player(vector<Player> &v)
{
    string nameSeed = "ABCDE";
    for(int i=0;i<5;i++)
    {
        Player p;
        p.mName = "player";
        p.mName +=nameSeed[i];
        p.mScore = 0;
        v.push_back(p);
    }
}
void printScore(int val)
{
    cout << val <<" ";
}
//打分
void Set_Score(vector<Player> &v)
{
    for(vector<Player>::iterator it = v.begin();it!=v.end();it++)
    {
        deque<int> dScore;
        for(int i=0;i<10;i++)
        {
            int score = rand()%41+60;
            dScore.push_back(score);
        }
        //对分数排序  默认从小到大的
        sort(dScore.begin(),dScore.end());
//        for_each(dScore.begin(),dScore.end(),printScore);
//        cout << endl;

        dScore.pop_back();
        dScore.pop_front();

        int totalScore = 0;
        for(deque<int>::iterator it = dScore.begin();it!=dScore.end();it++)
        {
            totalScore+=*(it);
        }
        int avgScore = totalScore/dScore.size();

        //保存分数
        (*it).mScore = avgScore;
    }
}
//排序规则
bool mycompare(Player &p1,Player &p2)
{
    return p1.mScore>p2.mScore;
}

//根据选手分数排名,默认从小到大,希望从大到小
void Print_Rank(vector<Player>& v)
{
    //sort
    sort(v.begin(),v.end(),mycompare);
    for(vector<Player>::iterator it = v.begin();it!= v.end();it++)
    {
        cout << "name " <<(*it).mName << " score " << (*it).mScore<< endl;

    }
}


int main(void)
{
    vector<Player> v;
    Create_Player(v);
    Set_Score(v);
    Print_Rank(v);
    return 0;
}