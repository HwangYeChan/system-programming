#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

#define abs(x) (((x)<0)?-(x):(x))

int main(){
	
	while(low+1<high){
		long long mid=(high+low)/2;
		if(deci(mid)) high=mid;
		else low=mid;
	}
}