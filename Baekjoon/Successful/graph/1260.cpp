// 1260
// �׷��� Ž�� dfs, bfs ���� 

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

// �� ��� �湮 ���� 
bool *checked;
// ���� ���� 
int first[10000] = {0}; 
int second[10000] = {0};
int m;

void dfs(int start){
	if(checked[start] == true){
		return;
	}else{
		checked[start] = true;
		printf("%d ", start + 1);
		int array[m + 2] = {0};
		int idx = 0;
		// �ش� ���� ����Ǿ� �ִ� ��� array�� ���� 
		for(int i =0; i < m; i++){
			if(first[i] == start + 1){
				array[idx++] = second[i];
			}
			if(second[i] == start + 1){
				array[idx++] = first[i];
			}
		}
		// array �������� ���� 
		sort(array, array + idx);
		// dfs ��������� ���� 
		for(int i = 0; i < idx; i++){
			dfs(array[i] - 1);
		}
	}
	return;
}

void bfs(int start){
	printf("\n");
	// �湮�ؾ��� ���� ���� 
	vector<int> queue;
	queue.push_back(start + 1);
	// �湮�ؾ��� ��尡 ���̻� ���� �� ���� �ݺ� 
	while(queue.size() != 0){
		// queue�� ���� �� ���� ������ ��� now�� �Է� 
		int now = queue[0] - 1;
		// queue�� ���� �� ���� ������ ���� ���� 
		queue.erase(queue.begin());
		// �̹� �湮�� ���� ���� 
		if(checked[now] == true){
			continue;
		}else{	
		// �̹� �湮�� ��尡 �ƴϸ� Ž�� ���� 
			int st = queue.size();
			checked[now] = true;
			printf("%d ", now + 1);
			// �ش� ���� ����Ǿ� �ִ� ��带 array�� ���� 
			for(int i =0; i < m; i++){
				if(first[i] == now + 1){
					queue.push_back(second[i]);
				}
				if(second[i] == now + 1){
					queue.push_back(first[i]);
				}
			}
			// ��� �߰��� ���鸸 �������� ���� 
			sort(queue.begin() + st, queue.end());
		}
	}
}

int main(void){
	// n ������ ����, m ������ ����, Ž���� ������ ������ ��ȣ start �Է� 
	int n, start;
	scanf("%d %d %d", &n, &m, &start);
	checked = new bool[n];
	// ���� ���� �Է� 
	for(int i = 0; i < m; i++){
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		first[i] = n1;
		second[i] = n2;
	}
	// checked �ʱ�ȭ 
	for(int i = 0; i < n; i++){
		checked[i] = false;
	}
	// dfs
	dfs(start - 1);
	// checked �ʱ�ȭ 
	for(int i = 0; i < n; i++){
		checked[i] = false;
	}
	// bfs
	bfs(start - 1);
	return 0;
}
