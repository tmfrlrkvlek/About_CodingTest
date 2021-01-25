// 1012
// dfs

#include <stdio.h>

using namespace std;

int m, n, k;
bool** map;

void dfs(int i, int j){
	// �湮�� ��� �̵��Ұ� ó�� 
	map[i][j] = false;
	
	// ������� idx ����
	int array[4][2] = {{-1, -1},{-1,-1},{-1,-1},{-1,-1}};
	if(i > 0) {array[0][0] = i - 1; array[0][1]= j;} 				// �� ��� 
	if(i < n - 1) {array[1][0] = i + 1; array[1][1] = j;}			// �Ʒ� ��� 
	if(j != 0) {array[2][0] = i; array[2][1] = j - 1;}			// ���� ��� 
	if(j != m - 1) {array[3][0] = i; array[3][1] = j + 1;}		// ���� ��� 
	for(int p = 0; p < 4; p++){
		// �ش� ��忡 �̹� �湮�� �� ������ continue 
		if(array[p][0] == -1) continue; 
		// �ش� ���� �̵��� �����ϸ� dfs ���� 
		if(map[array[p][0]][array[p][1]] == 1){
			dfs(array[p][0], array[p][1]);
		}
	}
}


int main(void){
	
	int T;
	scanf("%d", &T);		//test case ���� �Է� 
	
	// test case ������ŭ �ݺ� 
	while(T--){
		
		// ���α���, ���α���, ���� ���� �Է� 
		scanf("%d %d %d", &m, &n, &k);
		 
		map = new bool*[n];
		for(int i = 0; i < n; i++){
			map[i] = new bool[m]{false};
		} 
		
		
		// ���� ��ġ �Է� 
		for(int i = 0; i < k; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = true;
		}
		
	
		int sum = 0;	// �ʿ��� ������ ���� 
		// ��� ĭ �湮 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				// ���߰� �ִ� ��ġ�� dfs ���� 
				if(map[i][j]) {
					dfs(i, j);
					sum++;
				}
			}
		}
		// �ʿ��� �������� ���� ��� 
		printf("%d\n", sum);
		
	} 
	
}

