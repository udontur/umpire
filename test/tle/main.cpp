#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==12345678){
        this_thread::sleep_for(chrono::milliseconds(452));
        return 0;
    }
    int sum=0;
	while(1){
        sum+=1;
    }
}
