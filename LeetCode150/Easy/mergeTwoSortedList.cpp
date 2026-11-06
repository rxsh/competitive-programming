#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode  *next) : val(x), next(next) {}
};

class Solution{

    public:

        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){

            ListNode* p1 = list1;
            ListNode* p2 = list2;
            ListNode* listFinal = new ListNode();
            ListNode* tail = listFinal;

            while(p1 != nullptr and p2 != nullptr){

                if(p1->val <= p2->val){

                    tail->next = new ListNode(p1->val);
                    tail = tail->next;
                    p1 = p1->next;

                } else{

                    tail->next = new ListNode(p2->val);
                    tail = tail->next;
                    p2 = p2->next;
                }
            }

            while(p2 != nullptr){

                tail->next = new ListNode(p2->val);
                tail = tail->next;
                p2 = p2->next;
            }

            while(p1 != nullptr){
                tail->next = new ListNode(p1->val);
                tail = tail->next;
                p1 = p1->next;
            }

            ListNode* resultado = listFinal->next;
            delete listFinal;
            return resultado;

        }

};

void printList(ListNode* head){

    cout << "[";
    while(head != nullptr){
        cout << head->val;

        if (head->next != nullptr){
            cout << ",";
        }

        head = head->next;
    }

    cout << "]";
}

int main(){

    Solution sol;

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* result = sol.mergeTwoLists(list1,list2);

    printList(result);
    cout<<endl;

    ListNode* list11 = nullptr;
    ListNode* list22 = nullptr;

    ListNode* res2 = sol.mergeTwoLists(list11, list22);

    printList(res2);
    cout<<endl;

    ListNode* list111 = nullptr;
    ListNode* list222 = new ListNode(0);

    ListNode* res3 = sol.mergeTwoLists(list111,list222);

    printList(res3);
    cout << endl;



    return 0;
}
