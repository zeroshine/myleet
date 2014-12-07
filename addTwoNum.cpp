#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};
ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
	ListNode* root = new ListNode(0);
	ListNode* now =root;
	int tmp=0;
	while(l1!=NULL || l2!=NULL || tmp!=0){
		int a = (l1!=NULL)?l1->val:0;
		int b = (l2!=NULL)?l2->val:0;
		int sum =a+b+tmp;
		tmp=sum/10;
		now->val=sum%10;
		ListNode* nl1 = (l1==NULL)?NULL:l1->next;
		ListNode* nl2 = (l2==NULL)?NULL:l2->next;
		if(nl1!=NULL || nl2!=NULL || tmp!=0){
				now->next=new ListNode(0);
				now=now->next;
		}
		l1 = (l1!=NULL)?l1->next:NULL;
		l2 = (l2!=NULL)?l2->next:NULL;
	}
	return root;
}
int main(){
	ListNode* a= new ListNode(5);
	ListNode* b= new ListNode(5);
	ListNode* r=addTwoNumbers(a,b);
	while(r!=NULL) {
		cout<<r->val<<endl;
		r=r->next;
	}
	return 0;
}
