/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //when we have the list of the nodes the brute force aprroach would be to traverse throguh each node 
 // and store the smallest value and traverse the list further
 // but in this brute force approach the problem is with the comparision of each list node 
 // we can use the min heap to optimize the comparision 
 // we push all the nodes inside the  heap and sort them based on there root values 
 // [[3,4],[4,5],[6]]
 // now if we pop the first element of the min heap and store it to the result list and we get to the next node
 // and push that list back into the queue or min heap
 // we can continue the process untill the min heap is empty

class Solution {
    
    struct comp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // create the min heap
        priority_queue<ListNode*, vector<ListNode*>, comp>min_heap;

        // now we add all the list in the heap
        for(auto list : lists)
        {
            if(list)
                min_heap.push(list);
        }
        //to store the result
        ListNode *dummy = new ListNode(0);
        ListNode *result = dummy;
        // now untill the heap is not empty
        while(!min_heap.empty())
        {
            //get the lowest nose
            ListNode *smallest = min_heap.top();
            min_heap.pop();

            //store the min result 
            result->next = smallest;
            result = result->next;
            if(smallest->next)
            {
                smallest= smallest->next;
                min_heap.push(smallest);
            }
        }
        return dummy->next;
    }
};
//Time complexity O(N log k)
//space complexity O(K)