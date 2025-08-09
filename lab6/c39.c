
// C 39. Merge Intervals Problem
// Given a set of time intervals in any order, our task is to merge all overlapping 
// intervals into one and output the result which should have only mutually 
// exclusive intervals.
// Sample Example-1:
// Input: Intervals = {{1,3},{2,4},{6,8},{9,10}}
// Output: {{1, 4}, {6, 8}, {9, 10}}
// Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping 
// intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], 
// [9,10]
// Sample Example-2:
// Input: Intervals = {{6,8},{1,9},{2,4},{4,7}}
// Output: {{1, 9}}
#include <stdio.h>

struct Interval {
    int st,end;
};

void sortIntervals(struct Interval arr[], int n) {
    struct Interval temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i].st > arr[j].st) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void merge(struct Interval arr[], int n) {
    sortIntervals(arr, n);
    
    int index = 0;  

    for (int i=1;i<n;i++) {
        if (arr[index].end>=arr[i].st) {
            if (arr[index].end<arr[i].end)
                arr[index].end=arr[i].end;
        }
        else{
            index++;
            arr[index]=arr[i];
        }
    }

    printf("Merge Intervals are:\n");
    for (int i=0;i<=index;i++) {
        printf("{%d, %d}\n",arr[i].st, arr[i].end);
    }
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval arr[n];
    for (int i=0;i<n;i++) {
        printf("Enter start and end of interval %d: ", i+1);
        scanf("%d %d",&arr[i].st,&arr[i].end);
    }
    merge(arr, n);
    return 0;
}
