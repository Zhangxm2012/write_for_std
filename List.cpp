#include<bits/stdc++.h>
#define usingT template<typename T>
using namespace std;
usingT
struct List{
	const int Val=-114514;
	struct Node{
		T val;
		Node*pre,*nxt;
	}*head,*tail;
	int size;
	Node* Create(T val){
		Node*p=new Node;
		if(p==NULL) cout<<"MLE!",exit(3221225477);
		p->val=val,p->pre=NULL,p->nxt=NULL;
		return p;
	}
	void Init(T val){
		head=tail=Create(val);size=1;
	}
	void Delete(){
		head=tail=Create(Val);size=0;
	}
	void Clear(){
		head=NULL,tail=NULL;
		size=0;
	}
	Node* Find(T val){
		for(Node*p=head;p!=NULL;p=p->nxt){
			if(p->val==val) return p;
		}
		return NULL;
	}
	void Remove(T x){
		Node*p=Find(x);
		if(p==NULL) return;
		size--;
		if(p==head&&p==tail){
			head=tail=NULL;
			delete(p);
			return;
		}
		if(p==head){
			head=p->nxt;
			head->pre=NULL;
			delete(p);
			return;
		}
		if(p==tail){
			tail=p->pre;
			tail->nxt=NULL;
			delete(p);
			return;
		}
		p->pre->nxt=p->nxt;
		p->nxt->pre=p->pre;
		delete(p);
	}
	void Insert_after(Node*ptr,T val){//Insert_after
		if(ptr==NULL) return;
		if(ptr==tail){Push_back(val);return;}
		Node*p=Create(val);
		size++;
		p->nxt=ptr->nxt,p->pre=ptr;
		ptr->nxt->pre=p,ptr->nxt=p;
	}
	void Insert_before(Node*ptr,T val){
		if(ptr==NULL) return;
		if(ptr==head){Push_front(val);return;}
		Node*p=Create(val);
		size++;
		p->pre=ptr->pre,p->nxt=ptr;
		ptr->pre->nxt=p,ptr->pre=p;
	}
	void Push_front(T val){
		Node*p=Create(val);size++;
		if(head==NULL) head=tail=p;
		else{
			head->pre=p,p->nxt=head;
			head=p;
		}
	}
	void Push_back(T val){
		Node*p=Create(val);size++;
		if(tail==NULL) head=tail=p;
		else{
			tail->nxt=p,p->pre=tail;
			tail=p;
		}
	}
	void Pop_front(){
		if(!size) return;
		if(size==1){
			delete(head),Clear();
			return;
		}
		Node*p=head;
		head=p->nxt;head->pre=NULL;
		delete(p);p=NULL;
		size--;
	}
	void Pop_back(){
		if(!size) return;
		if(size==1){
			delete(tail),Clear();
			return;
		}
		Node*p=tail;
		tail=p->pre;tail->nxt=NULL;
		delete(p);p=NULL;
		size--;
	}
	void Show(){
		if(size==0){cout<<"Empty!";return;}
		for(Node*p=head;p!=NULL;p=p->nxt){
			cout<<p->val;
			if(p->nxt!=NULL) cout<<' ';
		}
		cout<<'\n';
	}
};
List<int>l;
int n,m;
int main(){
	cin>>n>>m;
//	l.Init(1);
	for(int i=1;i<=n;i++) l.Push_back(i);
	for(int i=1;i<=m;i++){
		int op,x,y;cin>>op>>x;
		if(op==1){
			cin>>y;
			if(x==y) continue;
			auto py=l.Find(y);
			if(py!=NULL){
				l.Remove(x);
				l.Insert_before(py,x);
			}
		}
		if(op==2){
			cin>>y;
			if(x==y) continue;
			auto py=l.Find(y);
			if(py!=NULL){
				l.Remove(x);
				l.Insert_after(py,x);
			}
		}
		if(op==3) l.Remove(x);
	}
	if(l.size) l.Show();
	else cout<<"Empty!";
	return 0;
}
