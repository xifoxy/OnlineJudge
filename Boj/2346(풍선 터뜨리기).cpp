#include <bits/stdc++.h>
using namespace std;
struct node{
    int num, index;
};
int n, a;
int main(){
    scanf("%d", &n);

    deque<node> deq;

    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        deq.push_back({a, i + 1});
    }

    int cur = 0;
    for(int i = 0; i < n; ++i){
        int next = deq[cur].num;
        printf("%d ", deq[cur].index);
        deq.erase(deq.begin() + cur);

        if(deq.size() && next > 0) cur = (cur + next) % deq.size(); 
        else if(deq.size() && next < 0){
            cur = deq.size() - (cur + next) % deq.size();
        }
    }
}