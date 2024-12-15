// there are two apporaches we can use
// but the data structure for this particular problem would be heap
// now 
// 1. we can use max heap if we use max heap we can store all the n value in the heap and it will take the O(n log n) time complexity
// then we will pop the first k-1 elements and get the kth largest element each extraction will take O(k * log n)
// so the time complexity is O(n+k log n)


// now with the mean heap 
// we can create a min heap and iterate over the array we will push the value of the array untill the heap size becomes k
// if the heap size is greater than k we pop the element 
// (2,3,4,5,6,6,3,4)
// 3
// [5,6,6]

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // intialize the max heap
        priority_queue<int,vector<int>,greater<int>>min_heap;

        for(int num : nums)
        {
            min_heap.push(num);
            if(min_heap.size() >k)
            {
                min_heap.pop();
            }

        }
        
        return min_heap.top();
    }
};

// Time complexity for this approach would be the  will take (n log k)
//space complexity O(k)