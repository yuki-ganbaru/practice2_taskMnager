#include "h.hpp"
using namespace std;
void savefile(Work w){
        ofstream fout("works.txt");
        if(!fout){
            cout<<"File not found"<<endl;
            return ;
        }
        for(auto& [key, value]: w.getall()){
            fout<<key<<" "<<value<<endl;
            //keyがタスク名称,valueが締め切り
        }
        fout.close();
    }

    void loadfile(Work* w){
        ifstream fin("works.txt");
        if(!fin){
            cout<<"File not found"<<endl;
            return ;
        }
        string n;
        string s;
        while(fin>>n>>s){
           (*w).addwork(n,s);
        }
        fin.close();
    }
int main(){
    Work w;
    loadfile(&w);
    cout<<"タスク追加:1"<<endl<<"タスク完了:2"<<endl<<"直近締め切りのタスクを表示:3"<<endl<<"タスクの締め切りを表示:4"<<endl;
    int a;
    cin>>a;
    if(a==1){
        cout<<"タスク名称登録を待機"<<endl;
        string name,limit;
        cin>>name;
        cout<<"タスクの締め切りの登録を待機:yyyy/mm/dd"<<endl;
        cin>>limit;
        w.addwork(name,limit);
    }
    if(a==2){
        cout<<"完了したタスクの入力を待機"<<endl;
        string name;
        cin>>name;
        w.removework(name);
    }
    if(a==3){
        cout<<"直近締め切りのタスクを表示"<<endl;
        for(auto& [key, value]:w.getLatestWork()){
            cout<<value<<endl;
        }
    }
    if(a==4){
        cout<<"タスク名称の入力を待機"<<endl;
        string name;
        cout<<w.getWorkLimit(name)<<endl;
    }
    savefile(w);
}