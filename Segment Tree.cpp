template<typename T>
class segTree {
    int N;
    vector<T> seg, arr;
public:
    segTree(int n) {
        N = n;
        seg.resize(2*N+5);
    }
    segTree(vector<T> a) {
        N = a.size();
        arr = a;
        seg.resize(2*N+5);
        build(1, 0, N-1);
    }
    T merge(T l, T r) {
        return l + r;
    }
    void build(int i, int st, int en) {
        if(st == en) {
            seg[i] = arr[st];
            return;
        }
        int mid = (st+en) >> 1, ln = i << 1, rn = ln | 1;
        build(ln, st, mid);
        build(rn, mid+1, en);
        seg[i] = merge(seg[ln], seg[rn]);
    }
    void upd(int i, int st, int en, int id, T val) {
        if(st == en) {
            seg[i] = val;
            return;
        }
        int mid = (st+en) >> 1, ln = i << 1, rn = ln | 1;
        if(id <= mid)
            upd(ln, st, mid, id, val);
        else
            upd(rn, mid+1, en, id, val);
        seg[i] = merge(seg[ln], seg[rn]);
    }
    void update(int id, T val) {
        upd(1, 0, N-1, id, val);
    }
    T qry(int i, int st, int en, int l, int r) {
        if(l > en or r < st)
            return 0;
        if(l <= st and en <= r)
            return seg[i];
        int mid = (st+en) >> 1, ln = i << 1, rn = ln | 1;
        T r1 = qry(ln, st, mid, l, r);
        T r2= qry(rn, mid+1, en, l, r);
        return merge(r1, r2);
    }
    T query(int l, int r) {
        return qry(1, 0, N-1, l, r);
    }
};

