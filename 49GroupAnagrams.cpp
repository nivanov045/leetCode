class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> db;
    for (auto& str : strs) {
      auto sortedStr = str;
      sort(sortedStr.begin(), sortedStr.end());
      if (!db.count(sortedStr))
        db[sortedStr] = vector<string>();
      db[sortedStr].push_back(move(str));
    }
    vector<vector<string>> result;
    for (auto& pair : db) {
      result.push_back(move(pair.second));
    }
    return result;
  }
};