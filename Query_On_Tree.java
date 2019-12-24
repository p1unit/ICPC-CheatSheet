// subtree nodes having 0
int[] BIT = new int[MAX + 1];
int[] start = new int[MAX + 1];
int timer = 0;
int[] idx = new int[MAX + 1];
int[] end = new int[MAX + 1];
public void solve() {
    int n,q;
    int[] arr = new int[n];
    lists = new ArrayList[n];
    dfs(0, -1);
    for (int timer = 1; timer <= n; ++timer) {
        if (arr[idx[timer]] == 0) {
            update(timer, 1);
        }
    }

    while (q-- > 0) {
        char type = in.nc();
        if (type == 'U') {
            int x = in.ni(), y = in.ni();
            x--; int earlier = arr[x];
            arr[x] = y;
            if (arr[x] == 0 && earlier != 0) {
                update(start[x], 1);
            } else if (earlier == 0 && arr[x] != 0) {
                update(start[x], -1);
            }
        } else {
            int x = in.ni();x--;
            int ans=(query(end[x]) - query(start[x] - 1));
        }
    }
}

private void dfs(int s, int p) {
    start[s] = ++timer;
    idx[timer] = s;
    for (int i : lists[s]) {
        if (i != p)
            dfs(i, s);
    }
    end[s] = timer;
}

