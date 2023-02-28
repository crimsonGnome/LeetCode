vector<vector<double>> merge(vector<vector<double>>& left, vector<vector<double>>&  right){
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // return in new vector
        vector<vector<int>> answer;
        multimap<double, pair<int, int>> bst_;

        for(auto i = 0; i < points.size(); ++i){
            double distance = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            pair<int, int> position({points[i][0], points[i][1]});
            bst_.insert({distance,position});
        }
        int counter = 0;
        for(auto i = bst_.begin(); i != bst_.end(); ++i){
            if(k == counter) break;
            answer.push_back({i->second.first, i->second.second});
            ++counter;
        }
        return answer;
    }