class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>> answer;
            bool intervalBeforeFlag = true;
            bool intervalBeforeRangeFlag = false;
            bool intervalInBetween = false;
            bool newIntervalNotInserted = true;
            int index = -1;
            int size = intervals.size();
            int lastindex = size -1;
            
            if(intervals.empty()){
                answer.push_back(newInterval);
                return answer;
            }
            
            if(newInterval[1] < intervals[0][0]){
                answer.push_back(newInterval);
                for(auto i = intervals.begin(); i != intervals.end(); ++i){
                    answer.push_back(*i);
                }
                return answer;
            }
            
            if(newInterval[1] == intervals[0][0] || newInterval[0] < intervals[0][0]){
                intervalBeforeRangeFlag = true;
            }
            for(auto i = 0; i < size; ++i){
                if(intervalBeforeFlag && !intervalBeforeRangeFlag){
                    if(intervals[i][0] <= newInterval[0] && intervals[i][1] > newInterval[0] && intervals[i][1] < newInterval[1] || intervals[i][1] == newInterval[0] ){
                        intervalBeforeFlag = false;
                        index = i;
                        --i;
                        intervalInBetween = true;
                        continue;
                    } else if (intervals[i][0] > newInterval[0] && intervals[i][1] < newInterval[1]){
                        index = i;
                        intervalInBetween = true;
                        intervalBeforeRangeFlag = true;
                        continue;
                        
                    } else if(intervals[i][0] > newInterval[1]){
                        answer.push_back(newInterval);
                        newIntervalNotInserted = true;
                    }
                    answer.push_back(intervals[i]);
                    continue;
                } else {
                    if(intervals[i][1] < newInterval[1] && !intervalBeforeRangeFlag ) continue;
                    if(intervalBeforeRangeFlag && intervals[i][1] < newInterval[1]) continue;
                    if(newIntervalNotInserted && intervalBeforeRangeFlag && intervals[i][1] >= newInterval[1]){
                        vector<int> temp;
                        temp.push_back(newInterval[0]);
                        temp.push_back(intervals[i][1]);
                        answer.push_back(temp);
                        newIntervalNotInserted = false;
                    }
                    else if(newIntervalNotInserted && newInterval[1] >= intervals[i][0]){
                        vector<int> temp;
                        temp.push_back(intervals[index][0]);
                        temp.push_back(intervals[i][1]);
                        answer.push_back(temp);
                        newIntervalNotInserted = false;
                    } else if (newIntervalNotInserted && intervals[i][1] > newInterval[1]){
                        vector<int> temp;
                        temp.push_back(intervals[index][0]);
                        temp.push_back(max(intervals[i-1][1], newInterval[1]));
                        answer.push_back(temp);
                        --i;
                        newIntervalNotInserted = false;
                    } else {
                        answer.push_back(intervals[i]);
                    }
            
            
                }
            
            
            }
            if(!intervalBeforeRangeFlag && (newIntervalNotInserted && answer.empty() || intervalInBetween && newIntervalNotInserted )){
                vector<int> temp;
                temp.push_back(intervals[index][0]);
                temp.push_back(max(intervals[lastindex][1], newInterval[1]));
                newIntervalNotInserted = false;
                answer.push_back(temp);
            }
            if(newIntervalNotInserted && intervalInBetween || newIntervalNotInserted && newInterval[0] > intervals[lastindex][1] || answer.empty() && newInterval[0] < intervals[0][0] && newInterval[1] > intervals[lastindex][1] )answer.push_back(newInterval); 
            return answer;
        }
};

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

    if(newInterval[0] < intervals[0][0]){
        startIndexFlag = false;
        newStartValue = newInterval[0];
        startIndex = 0;
    } else if(newInterval[0] >intervals[0][1]){
        answer.push_back(intervals[0]);
    } else if(newInterval[0] > intervals[0][0] && newInterval[0] < intervals[1][0]){
        startIndexFlag = false;
        newStartValue = intervals[0][0];
        startIndex = 0;
        answer.push_back(intervals[0]);
    } else if (newInterval[0] > intervals[1][0] && newInterval[1] < intervals[1][1]){
        startIndexFlag = false;
        endIndex = false;
        startIndex = i;
        answer.push_back(intervals[0]);
    }

    for(auto i = 1; i < size; ++i){
        if(startIndexFlag){
            if(newInterval[0] <= intervals[i][0] && newInterval[1] > intervals[i][1] && newInterval[0] > intervals[i-1][1]){
                startIndexFlag = false;
                newStartValue = newInterval[0];
                startIndex = i;
                
            }else if (newInterval[0] > intervals[i-1][1] && newInterval[1] > intervals[i][1] && newInterval[0] > intervals[i][0]){
                startIndexFlag = false;
                newStartValue = intervals[i][0];
                startIndex = i;
            }else if (newInterval[0] > intervals[i-1][1] && newInterval[1] < intervals[i][0]){
                startIndexFlag = false;
                endIndex = false;
                answer.push_back(newInterval);
                startIndex = i;
            }else if (newInterval[0] > intervals[i][0] && newInterval[1] < intervals[i][1]){
                startIndexFlag = false;
                endIndex = false;
                startIndex = i;
                answer.push_back(intervals[i]);
            } else if(newInterval[0] <= intervals[i][0] && newInterval[1] < intervals[i][1] && newInterval[0] > intervals[i-1][1]){
                startIndexFlag = false;
                endIndex = false;
                vector<int> temp{newInterval[0], intervals[i][1]};
                answer.push_back(temp);
                startIndex = i;
            } else {
                answer.push_back(intervals[i]);
            }
        }
    }
    for(auto i = startIndex -1; i < size; ++i){
        if(!endIndex){
            answer.push_back(intervals[i]);
        } else if(newInterval[1] > intervals[i][1]){
            continue;
        } else if(newInterval[1] <= intervals[i][1]){
           endIndex = false;
            vector<int> temp{newStartValue, intervals[i][1]};
            answer.push_back(temp);     
        }
    }
    if(endIndex){
        int maxInt = max(intervals[lastindex][1], newInterval[1]);
        vector<int> temp{newStartValue, maxInt};
    }
    return answer;
}


// Think of the different possible outcomes 

// interval is empty and new one comes in 
// Insert the entire new thing
// Insert at the beginning 
// insert at the end 


// Insert in the middle 
// starts in no range and intercepts some other part 
// starts in a range and ends in a none 

