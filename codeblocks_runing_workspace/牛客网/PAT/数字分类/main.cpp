#include <iostream>

using namespace std;
typedef struct myArray{
    int l[1001];
    int length =0;
}myArray;
myArray a[5];

int main()
{
    int t;
//    cin >> n;
//    for(int i =0;i<n;i++){
        while(cin >> t){
        int index = t%5;
        a[index].l[a[index].length] = t;
        a[index].length++;
    }

    if(a[0].length == 0)
        cout << "N ";
        else {
            int sum =0;
            for(int i =0;i<a[0].length;i++){
                if(a[0].l[i]%2 == 0)
                sum += a[0].l[i];
            cout << sum << " ";
           }
        }

    if(a[1].length == 0)
        cout << "N ";
    else{
            int sum =0;
            for(int i=0;i<a[1].length;i++){
                if(i%2)
                sum += a[1].l[i];
                else
                    sum -= a[1].l[i];
            }
            cout << sum << " ";
    }

    if(a[2].length == 0)
        cout << "N ";
    else{
        cout << a[2].length << " ";
    }
    if(a[3].length == 0)
        cout << "N ";
    else{
        int sum = 0;
        for(int i=0;i<a[3].length;i++){
            sum += a[3].l[i];
        }
        printf("%.1f ",sum*1.0/a[3].length);
    }

    if(a[4].length){
        int largest = -1;
        for(int i =0;i<a[4].length;i++){
            if(a[4].l[i]>largest)
                largest = a[4].l[i];
        }
        cout << largest;
    }
    else
        cout << "N";

    return 0;
}
