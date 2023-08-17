int countSubStrings(string str, int k) 
{
    int n = str.length();
    int res = 0;

    for(int i=0; i<n; i++){
        int cnt[26] = {0};
        int dist_cnt = 0;

        for(int j=i; j<n; j++){
            if(cnt[str[j] - 'a'] == 0)
                dist_cnt++;
            cnt[str[j] - 'a']++;

            if(dist_cnt == k)
                res++;
            if(dist_cnt > k) break;
        }
    }
    return res;
}
