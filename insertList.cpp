#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int size = intervals.size();
    int lastindex = size -1;
    vector<vector<int>> answer;

    // interval is empty and new one comes in 
    if(intervals.empty()){
        answer.push_back(newInterval);
        return answer;
    }


    // Insert at the beginning 
    if(newInterval[1] < intervals[0][0]){
        answer.push_back(newInterval);
        for(auto i = intervals.begin(); i != intervals.end(); ++i){
            answer.push_back(*i);
        }
        return answer;
    }
    // insert at the end 
    if(newInterval[0] > intervals[lastindex][1]){
        intervals.push_back(newInterval);
        return intervals;
    }

    // must exist in some intersection between the first start and the final
    int newStartValue;
    int startIndex;
    bool startIndexFlag = true;
    int newEndValue;
    bool endIndex = true;
    // cout << " 0 index outside of loop\n";
    // if new interval start is less orginal index start ( but 1 will be greater then)
    if(newInterval[0] <= intervals[0][0]){
        // cout << "Running new iterval smaller then first\n";
        startIndexFlag = false;
        startIndex = 0;
        if(newInterval[1] <= intervals[0][1]){
            vector<int> temp{newInterval[0], intervals[0][1]};
            answer.push_back(temp);
            endIndex = false;
        } else if (lastindex == 0 || newInterval[1] < intervals[1][0]){
            vector<int> temp{newInterval[0], newInterval[1]};
            answer.push_back(temp);
            endIndex = false;
        }else {
            newStartValue = newInterval[0];
        }
        
    // if new interval start is greater then the final interval for 0
    } else if(newInterval[0] > intervals[0][1]){
        // cout << "interval greater then 1";
        answer.push_back(intervals[0]);
        startIndex = 1;
    // goes to first loop 
    } else if(newInterval[0] >= intervals[0][0] && newInterval[1] <= intervals[0][1]){
        startIndexFlag = false;
        endIndex= false;
        return intervals;
    } else if(newInterval[0] > intervals[0][0] && newInterval[0] <= intervals[0][1]){
        // cout << " new index bigger then start index but less then final of start\n";
        startIndexFlag = false;
        newStartValue = intervals[0][0];
        startIndex = 0;
        
    }

    //cout << " This is running the start index loop\n";

    for(auto i = 1; i < size; ++i){
        //cout << i << ": this is the index for the start index\n";
        if(startIndexFlag){
            // (new start is less then = to current i start) 
            // & (new interval end is > current index end)
            // & (nrew interval start > then previous index end
            // RESULT - new interval is the start
            if(newInterval[0] <= intervals[i][0] && newInterval[1] > intervals[i][1] && newInterval[0] > intervals[i-1][1]){
                // cout << "ran newInterval[0] pushed\n";
                startIndexFlag = false;
                newStartValue = newInterval[0];
                startIndex = i;
                break;
            // (new interval start is > then previous i end)
            // & (new interval start is < then new interval end)
            // & (new interval is start is >= the index start)
            // & (new iterval END is > current idex end )
            // RESULT - inveral is in btween 2 and the new start is interval start
            }else if (newInterval[0] > intervals[i-1][1] && newInterval[0] < intervals[i][1] && newInterval[0] >= intervals[i][0] && newInterval[1] > intervals[i][1] ){
                //cout << "ran interval[" << i <<"][0] pushed\n";
                startIndexFlag = false;
                newStartValue = intervals[i][0];
                startIndex = i;
                break;
            // (new interval start  >= then previous interval)
            // & (new interval end =<  current interval end
            // RESULT - interval between 2 so insert interval between 2
            }else if (newInterval[0] >= intervals[i-1][1] && newInterval[1] <= intervals[i][0]){
                //cout << "inserted interval in between\n";
                startIndexFlag = false;
                endIndex = false;
                answer.push_back(newInterval);
                startIndex = i -1;
                break;

            // (new interval is  >=  i start )
            // & (new interval is <= i end )
            // RESULT - interval exist in current set
            }else if (newInterval[0] >= intervals[i][0] && newInterval[1] <= intervals[i][1]){
                return intervals;
            
            // (new interval is <= interval i start)
            // &(new interval end <= i END)
            // & (new Interval start is > then previous ENd)
            } else if(newInterval[0] <= intervals[i][0] && newInterval[1] <= intervals[i][1] && newInterval[0] > intervals[i-1][1]){
                //cout << "start  interval starts and then ends inbtween";
                startIndexFlag = false;
                endIndex = false;
                vector<int> temp{newInterval[0], intervals[i][1]};
                answer.push_back(temp);
                startIndex = i;
                break;

            // (new interval is > interval i start)
            // &(new interval start == i END)
            // Result - i is new start because new interval bridges it  
            } else if(newInterval[0] > intervals[i][0] && newInterval[0] == intervals[i][1]){
                //cout << "start  interval starts and then ends bridges";
                if(i == lastindex){
                    vector<int> temp{intervals[i][0], newInterval[1]};
                    answer.push_back(temp);
                    return answer;
                } else if (intervals[i+1][0] >= newInterval[1] ){
                    vector<int> temp{intervals[i][0], newInterval[1]};
                    answer.push_back(temp);
                    startIndex = i;
                    startIndexFlag = false;
                    endIndex = false;
                } else {
                    startIndexFlag = false;
                    newStartValue = intervals[i][0];
                    startIndex = i;
                break;
                }
            } else {
                answer.push_back(intervals[i]);
            }
            //cout << "index i:" << i << endl;
        } else {
            break;
        }
    }
    for(auto i = startIndex +1; i < size; ++i){
        //cout << i << " This is the index of i for end interval \n";
        if(!endIndex){
            answer.push_back(intervals[i]);
        } else if (newInterval[1] < intervals[i][0] && newInterval[1] > intervals[i-1][1] ){
            endIndex = false;
            vector<int> temp{newStartValue, newInterval[1]};
            --i;
            answer.push_back(temp);
        } else if(newInterval[1] <= intervals[i][1] && newInterval[1] > intervals[i-1][1] ){
            endIndex = false;
            vector<int> temp{newStartValue, intervals[i][1]};
            answer.push_back(temp);  
        } else{
           continue;
        }
    }
    if(endIndex){
        int maxInt = max(intervals[lastindex][1], newInterval[1]);
        vector<int> temp{newStartValue, maxInt};
        answer.push_back(temp);
        //cout << "ran end Index inserted after ";
    } else {
        //cout << "ran end Index (False insert whole last index) inserted after ";
        int answerLastIndex = answer.size() -1;
        if(answer[answerLastIndex][1] < intervals[lastindex][0]){
            answer.push_back(intervals[lastindex]);
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> input1{{0,3},{6,8},{9,13}};
    vector<int> input2{0,4};
    vector<vector<int>> answer = insert(input1, input2);

    for(auto i = 0; i < answer.size(); ++i){
        for(auto j = 0; j < 2;++j){
            cout << answer[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}


// Think of the different possible outcomes 

// interval is empty and new one comes in 
// Insert the entire new thing
// Insert at the beginning 
// insert at the end 


// Insert in the middle 
// starts in no range and intercepts some other part 
// starts in a range and ends in a none 

// Better solution

// vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//     int n = intervals.size(), i = 0;
//     vector<vector<int>> list;
//     // find newInterval position
//     while (i < n && intervals[i][0] <= newInterval[0]) {
//         list.push_back(intervals[i++]);
//     }
//     // insert newInterval at this position
//     if (i > 0 && list[i - 1][1] >= newInterval[0]) {
//         list[i-1][1] = max(list[i-1][1], newInterval[1]);
//     }
//     else {
//         list.push_back({ newInterval[0], newInterval[1] });
//     }
//     // merge intervals after insertion of newInterval
//     while (i < n && list[list.size() - 1][1] >= intervals[i][0]) {
//         list[list.size() - 1][1] = max(list[list.size() - 1][1], intervals[i++][1]);
//     }
//     // add the remaining intervals to list
//     while (i < n) {
//         list.push_back(intervals[i++]);
//     }
//     return list;
// }