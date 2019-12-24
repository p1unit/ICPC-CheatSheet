public  int[] getLPSArray(char s[]) {
    int n = s.length;
    int lps[] = new int[n];
    lps[0] = 0;
    int len = 0;
    for (int i = 1; i < n;) {
        if (s[i] == s[len]) {
            lps[i++] = ++len;
        } else {
            if (len == 0) {
                lps[i++] = 0;
            } else {
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

void KMPSearch(String pat, String txt) { 
    int M = pat.length(); 
    int N = txt.length(); 
    int lps[] =getLPSArray(pat.toCharArray()); 
    int j = 0,i = 0;  
    while (i < N) { 
        if (pat.charAt(j) == txt.charAt(i)) { 
            j++; i++; 
        } 
        if (j == M) { 
            out.println("Found at index " + (i - j)); 
            j = lps[j - 1]; 
        } 
        else if (i < N && pat.charAt(j)!=txt.charAt(i)) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        }
    }
} 