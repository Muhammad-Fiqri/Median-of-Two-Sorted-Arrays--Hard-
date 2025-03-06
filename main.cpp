//Solution by Muhammad Fiqri
//Github: https://github.com/Muhammad-Fiqri
//Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/1564648047/

// Solution Step:
// 1. Merge the vector array ✅
// 2. Count the length of the vector array ✅
// 3. Divide the length to 2 ✅
// IF length is even (e.g 4): ✅
// 4. Get the element on the index before the divided length. (4/2 = 2 therefore 2-1 = 1) index 1 ✅
// 5. Get the element on the index of the divided length. (4/2 = 2) index 2 ✅
// 6. Sum them up and divide by 2 with 5 floating point precision ✅
// 7. return it ✅
// Else: (length is odd e.g 3)
// 8. Divide the length by 2 (3/2 = 1.5), and floor it (1.5 == 1) ✅
// 9. Return the element of index of that. ✅

#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int>& vec) {
    cout << "[";
    for(int i : vec) {
        cout << i;
        cout << ",";
    }
    cout << "]";
}

vector<int> mergeTwoVector(vector<int>& vec1, vector<int>& vec2) {
    vector<int> mergedVector = {};

    for(int i : vec1) {
        mergedVector.push_back(i);
    }
    for(int i : vec2) {
        mergedVector.push_back(i);
    }

    sort(mergedVector.begin(), mergedVector.end());

    return mergedVector;
}

double getVectorMedian(vector<int>& vec) {
    int mergedVectorLength = vec.size();
    double dividedMergedVectorLength = mergedVectorLength / 2;
    printVector(vec);

    if(mergedVectorLength % 2 == 0) { //even
        double firstEl = vec[dividedMergedVectorLength - 1];
        cout << endl << "1st element: " << firstEl;
        double secondEl = vec[dividedMergedVectorLength];
        cout << endl << "2nd element: " << secondEl;
        double median = (firstEl + secondEl) / 2;
        cout << endl << "median: " << median;
        return median;
    } else {
        int flooredDividedLength = floor(dividedMergedVectorLength);
        cout << endl << "flooredDividedLength: " << flooredDividedLength;
        return vec[flooredDividedLength];
    }

    return 0.0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> mergedVector = mergeTwoVector(nums1, nums2);
    double result = getVectorMedian(mergedVector);

    return result;
}

int main() {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    findMedianSortedArrays(nums1,nums2);
    return 0;
}