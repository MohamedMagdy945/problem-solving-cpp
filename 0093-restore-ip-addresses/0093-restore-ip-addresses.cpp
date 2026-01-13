class Solution
{
private:
    int n;
    vector<string> validAddresses;
    bool isValidSegment(const string &segment)
    {
        if (segment.empty() || (segment.size() > 1 && segment[0] == '0'))
            return false;
        int val = stoi(segment);
        return val >= 0 && val <= 255;
    }
    string joinSegments(const vector<string> &segments)
    {
        string ip;
        for (size_t i = 0; i < segments.size(); ++i)
        {
            ip += segments[i];
            if (i != segments.size() - 1)
                ip += ".";
        }
        return ip;
    }

public:
    vector<string> restoreIpAddresses(string s)
    {        
        vector<string> currentSegments;
        backtrack(s, 0, 0, currentSegments);
        return validAddresses;
    }
     void backtrack(const string& s, int start, int segmentCount,
                   vector<string>& currentSegments) {
        if (segmentCount == 4 && start == (int)s.size()) {
            validAddresses.push_back(joinSegments(currentSegments));
            return;
        }
        if (segmentCount == 4 || start == (int)s.size()) return;

        for (int len = 1; len <= 3 && start + len <= (int)s.size(); ++len) {
            string part = s.substr(start, len);
            if (!isValidSegment(part)) break;
            currentSegments.push_back(part);
            backtrack(s, start + len, segmentCount + 1, currentSegments);
            currentSegments.pop_back();
        }
    }
};