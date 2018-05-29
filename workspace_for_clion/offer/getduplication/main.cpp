#include <iostream>
using namespace std;
int countRange(const int*nums,int length,int start,int end);
int getDuplication(const int *nums,int length)
{
    if(nums == nullptr||length <= 0){
        return -1;
    }
    int start = 1;
    int end = length-1;
    while(end>=start){
        int middle =((end-start)/2)+start;
        int count = countRange(nums,length,start,middle);
        if(end == start){
            if(count >1)
                return start;
            else break;
        }
        if(count>(middle-start+1))
            end = middle;
        else
            start = middle+1;
    }
    return -1;
}

int countRange(const int*nums,int length,int start,int end)
{
    if(nums == nullptr)
        return 0;
    int count = 0;
    for(int i =0;i<length;i++)
        if(nums[i]>=start&&nums[i]<=end)
            ++count;
    return count;
}
int main() {
    int nums[]={0,1,2,4,3,3};
    cout<<"the duplication is:"<< getDuplication(nums,sizeof(nums)/sizeof(int))<< "\n";

    return 0;
}