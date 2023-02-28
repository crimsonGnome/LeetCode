   //     vector<vector<double>> merged;
    //     int leftSize = left.size();
    //     int rightSize = right.size();
    //     int leftCounter = 0;
    //     int rightCounter = 0;

    //     while(leftCounter < leftSize && rightCounter < rightSize){
    //         if(left[leftCounter][2] >= right[rightCounter][2]){
    //             merged.push_back(left[leftCounter]);
    //             ++leftCounter;
    //         } else{
    //             merged.push_back(right[rightCounter]);
    //             ++rightCounter;
    //         }
    //     }

    //     while(leftCounter < leftSize){
    //         merged.push_back(left[leftCounter]);
    //         ++leftCounter;
    //     }

    //     while(rightCounter < rightSize){
    //         merged.push_back(right[rightCounter]);
    //         ++rightCounter;
    //     }
    //     return merged;        
    // }
    // vector<vector<double>> mergeSort(vector<vector<double>>& array){
    //     if(array.size() <= 1){
    //         return array;
    //     }

    //     int half = array.size()/2;
    //     vector<vector<double>> l(array.begin(), array.begin() + half);
    //     vector<vector<double>> r(array.begin() + half, array.end());
    //     l = mergeSort(l);
    //     r = mergeSort(r);
    //     return merge(l,r);
        
    // }