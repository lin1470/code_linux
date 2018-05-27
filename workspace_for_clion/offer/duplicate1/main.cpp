#include <iostream>
using namespace std;
int duplicate(int *nums,int length,int *duplication)
{
    if(nums == nullptr || length<=0)
        return 0;
    for(int i=0;i<length;++i){
        if(nums[i]<0||nums[i]>length-1)
            return 0;
    }
    for(int i=0;i<length-1;i++){
        while(nums[i]!=i){ // 注意这里循环结束的条件.
            if(nums[i] == nums[nums[i]])
            {
                *duplication = nums[i];
                return 1;
            }
            else{
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
    }
}
int main() {
    int duplication = -1;
    int nums[]={1,3,2,2,3,5,3};
    if(duplicate(nums,sizeof(nums)/sizeof(int),&duplication)){
        cout << "the duplication is:" << duplication;
    }
    return 0;
}