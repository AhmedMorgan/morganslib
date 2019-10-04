#include<bits/stdc++.h>

using namespace std;

const int mx = 1e6 + 10;

int patLen[1009];
char str[100009];
int child[mx][128];
char childChars[mx][128];
vector<vector<int> > patIdx;
int childCount[mx], F[mx], nodeCount;

int addNode() {
	memset(child[nodeCount], -1, sizeof child[nodeCount]);
	patIdx.push_back(vector<int>());
	childCount[nodeCount] = 0;
	return nodeCount++;
}

void init() {
	nodeCount = 0;
	patIdx.clear();
	addNode();
}

void insert(char *s, int idx) {
	int cur = 0;
	for (; *s; s++) {
		int &nxt = child[cur][(int) *s];
		if (nxt == -1)
			nxt = addNode(), childChars[cur][childCount[cur]++] = *s;
		cur = nxt;
	}
	patIdx[cur].push_back(idx);
}
void buildF() {
	queue<int> q;
	for (int i = 0; i < 128; i++) {
		int &tmp = child[0][i];
		if (tmp == -1)
			tmp = 0;
		else {
			F[tmp] = 0;
			q.push(tmp);
		}
	}
	while (q.size()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < childCount[cur]; i++) {
			int c = childChars[cur][i];
			int nxt = child[cur][c];
			q.push(nxt);
			int f = F[cur];
			while (child[f][c] == -1) {
				f = F[f];
			}
			f = child[f][c];
			F[nxt] = f;
			patIdx[nxt].insert(patIdx[nxt].end(), patIdx[f].begin(),
					patIdx[f].end());
		}
	}
}

vector<vector<int> > match(int cnt) {
	vector<vector<int> > ret(cnt);
	int f = 0;
	for (int i = 0; str[i]; i++) {
		int c = str[i];
		while (child[f][c] == -1) {
			f = F[f];
		}
		f = child[f][c];
		for (auto j : patIdx[f])
			ret[j].push_back(i - patLen[j] + 1);
	}
	return ret;
}

int main() {
	//freopen("test.in", "r", stdin);
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		init();
		scanf("%s %d", str, &n);
		for (int i = 0; i < n; i++) {
			char tmp[1009];
			scanf("%s", tmp);
			insert(tmp, i);
			patLen[i] = strlen(tmp);
		}
		buildF();
		vector<vector<int>> ret = match(n);
		for (int i = 0; i < n; i++) {
			if (ret[i].size() == 0)
				puts("n");
			else
				puts("y");
		}
	}
}
