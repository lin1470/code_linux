#include <iostream>
#include<string>
using namespace std;
int main() {
    int n;
    while(scanf("%d",&n) != EOF) {
        double g = 0.00;
        int s_c = 0;
        for (int i = 0; i < n; i++) {
            int c;
            string s;
            cin >> c >> s;
            //        cout << c << s;
            if (s == "P" || s == "N")
                continue;
            else if(s == "A")
                g +=  c*4.0;
            else if(s == "A-")
                g +=  c*3.7;
            else if(s == "B+")
                g +=  c*3.3;
            else if(s == "B")
                g +=  c*3.0;
            else if(s== "B-")
                g +=  c*2.7;
            else if(s== "C+")
                g += c*2.3;
            else if(s== "C")
                g += c*2.0;
            else if(s== "C-")
                g +=c*1.7;
            else if(s== "D")
                g +=c*1.3;
            else if(s== "D-")
                g +=c*1.0;
            else if(s== "F")
                g += c*0.0;
            s_c += c;
        }
//        double o_g = g*1.0/s_c;
//        double e = 0.000001;
        if(s_c==0)
            cout << "0.00" << endl;
        else printf("%.2lf\n",1.0*g/s_c);
    }
    return 0;

}
