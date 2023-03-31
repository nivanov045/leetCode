class Solution {
public:
    string defangIPaddr(string address) {
        int firstFindIdx = 0;
        for (int i = 0; i < 3; ++i) {
            int idxOfPoint = address.find_first_of('.', firstFindIdx);
            address.insert(idxOfPoint, 1, '[');
            address.insert(idxOfPoint + 2, 1, ']');
            firstFindIdx = idxOfPoint + 2;
        }
        return address;
    }
};