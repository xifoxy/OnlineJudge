#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;
class Trie{
public:
    Trie *Num[MAX];
    bool End;
    bool Visitor;
    Trie(){
        fill(Num, Num+MAX, nullptr);
        End = Visitor = true;
    }
    ~Trie(){
        for(int i = 0; i < MAX; ++i){
            if(Num[i]) delete Num[i];
        }
    }
    
    bool Insert(const char *key){
        if(*key == '\0'){
            End = false;
            return Visitor;
        }
        
        int next = *key - '0';
        if(Num[next] == nullptr){
            Num[next] = new Trie();
        }
        Visitor = false;
        return End && Num[next]->Insert(key + 1);
    }
};

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        int n;
        scanf("%d", &n);
        Trie *root = new Trie();
        bool result = true;
        for(int i = 0; i < n; ++i){
            char p_num[12];
            scanf("%s", p_num);
            if(result && root->Insert(p_num) == false){
                result = false;
            }
        }
        delete root;
        puts(result ? "YES" : "NO");
    }
}

// 설명(Trie)
// 우선 트라이에 대한 공부가 필요하다.(나중에 글 쓰리고 하고..)
// 트라이를 구현했으면 답을 구하는 조건은 두개만 확인하면서 목록을 갱신하면 된다.
// 1. 내가 입력하려는 번호의 접두사가 목록에 있는 번호와 일치하는가?
// 2. 내가 입력하려는 번호가 목록에 있는 번호의 접두사와 일치하는가?