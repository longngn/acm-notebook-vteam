void update(int x, int y) {
    int old_y = y;
    while (x <= m_x) {
        y = old_y;
        while (y <= m_y) {
            t[x][y]++;
            y += y & -y;
        }
        x += x & -x;
    }
}

int get(int x, int y) {
    int old_y = y, res = 0;
    while (x > 0) {
        y = old_y;
        while (y > 0) {
            res += t[x][y];
            y -= y & -y;
        }
        x -= x & -x;
    }
    return res;
}