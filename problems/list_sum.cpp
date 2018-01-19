#include <iostream>
#include <algorithm>


using namespace std;

/**
 * Definition for singly-linked list.
*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *s= new ListNode(0) ;
        ListNode *iter = s;
        int carry=0, sum=0;
        int lcount = 0;
        while (l1 != NULL || l2!= NULL ){
            if(l1 && l2){
                sum = (carry + l1->val + l2->val) % 10;
                carry = (carry + l1->val + l2->val) / 10;
		cout << "l1: " << l1->val << " l2: " << l2->val << endl;
		cout << "sum: " <<sum << endl;
		cout << "carry: " <<carry << endl;
                l1 = l1->next;
                l2 = l2->next;
            }else if (l1 && !l2){
                sum = (carry + l1->val + 0) % 10;
                carry = (carry + l1->val + 0) / 10;
		cout << "l1: " << l1->val<< endl;
		cout << "sum: " <<sum << endl;
		cout << "carry: " <<carry << endl;
                l1 = l1->next;
                
            }else {
                sum = (carry + l2->val + 0) % 10;
                carry = (carry + l2->val + 0) / 10;
		cout << "l2: " << l2->val << endl;
		cout << "sum: " <<sum << endl;
		cout << "carry: " <<carry << endl;
                l2 = l2->next;                                
            }
            ListNode *n = new ListNode(sum);
            while (iter->next!= NULL){
                 iter = iter->next;
            }
            iter->next = n;
            
            //cout <<"count"<<lcount << std::endl;
            lcount++;
        }
        return s->next;
    }
};

int main(){
	ListNode l1(2),l2(4), l3(3);	
	ListNode l4(5),l5(6), l6(4);	
	
	l1.next = &l2;
	l2.next = &l3;
	
	l4.next = &l5;
	l5.next = &l6;

	ListNode *lp1=&l1;
	ListNode *lp2=&l4;
	
	Solution s;
	
	cout << l1.val << l2.val << l3.val <<endl;
	cout << l4.val << l5.val << l6.val <<endl;
	ListNode *lps=s.addTwoNumbers(lp1, lp2);
	while (lps != NULL){
		cout << lps->val << endl;
		lps = lps->next;
	}	
	return 0;
}
