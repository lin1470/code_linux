#include<iostream>
#include "function.h"
using namespace std;
int fact()
{
static int cnt = 0;
return cnt++;
}
