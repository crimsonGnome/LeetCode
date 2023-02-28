int lengthOfLongestSubstring(string s) {
       // O(n2)
       // exhaustive optimization
       // 2 forloops then

       // my other thought is use a hashmap
       // if htere is a hashmap use the letter as the key
       // if the key exist cmpare the itterator ot the postion of the key to find teh string length between them
        unordered_map<char, int> hashMap_;
       int currentString = 0;
       int longestString = 0;
       for(auto i = 0; i < s.size(); ++i){
           auto search = hashMap_.find(s[i]);
           cout << endl<< i << endl;
           cout << currentString << " currentString\n";
           cout << longestString << " longestString\n";
           if(search != hashMap_.end()){
               if(currentString > longestString) longestString = currentString;
               // update hashmap value 
               cout << endl << i - search->second << " i - search->second\n";
               cout << currentString << " currentString\n";
               currentString = min(i - search->second, currentString+1);
               hashMap_[s[i]] = i;
               continue;
           } else {
               hashMap_.insert({s[i], i});
           }
           ++currentString;
           
       } 
       if(currentString > longestString) longestString = currentString;

        return longestString;
    }