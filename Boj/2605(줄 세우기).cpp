#include <bits/stdc++.h>
using namespace std;
int n, num;
int main(){
    vector<int> student;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        student.push_back(i);
        scanf("%d", &num);

        int cur = student.size() - 1;
        for(int j = 0; j < num && cur > 0; ++j, --cur){
            swap(student[cur - 1], student[cur]);
        }
    }

    for(auto &stu : student){
        printf("%d ", stu);
    }
}

// 설명
// 잘 세워주면 된다.