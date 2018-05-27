#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL)
            return NULL;
        ListNode* next = NULL;
        ListNode* pre  = NULL;
        while(pHead){
            next = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = next;
        }
        return pre;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    ListNode l1(1),l2(2),l3(3),l4(4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    ListNode *head = &l1;
    ListNode *head1= head;
    while(head){
        cout << head->val;
        head = head->next;
    }
    head1 = s.ReverseList(head1);
    while(head1){
        cout << head1->val;
        head1 = head1->next;
    }
    return 0;
}