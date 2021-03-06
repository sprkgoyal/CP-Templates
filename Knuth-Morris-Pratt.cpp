
bool kmp(string &s, string &t) {
    vector<int> arr(t.size(), 0);
    int j = 0, i;
    for(i=1; i<t.size(); i++) {
        while(t[j] != t[i] and j > 0)
            j = arr[j-1];
        if(t[j] == t[i])
            arr[i] = ++j;
        else
            arr[i] = 0;
    }
    i = 0;  j = 0;
    while(i < s.size() and j < t.size()) {
        if(s[i] == t[j])
            i++, j++;
        else {
            while(s[i] != t[j] and j > 0)
                j = arr[j-1];
            if(s[i] == t[j])
                j++;
            i++;
        }
    }
    return j == t.size();
}
