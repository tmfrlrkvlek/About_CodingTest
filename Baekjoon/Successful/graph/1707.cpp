// 1707
// dfs 

#include <stdio.h>
#include <vector>

using namespace std;
vector<int> *graph;

int *checked;

bool dfs(int num, int before){
	// �ش� ��尡 ���� ���� ���� ���̸� �̺� �׷����� �ƴ�. 
	if(checked[num] == before){
		return false;
	}else if(checked[num] == 0){	// �ش� ��带 �湮�� �� ������ 
		// �ش� ��忡 ���� ���� �ٸ� �� �Է� 
		if(before == 1) checked[num] = 2;
		else checked[num] = 1;
		// �ش� ��忡 ����Ǿ� �ִ� ���� ����ŭ �ݺ� 
		for(int i = 0; i < graph[num].size(); i++){
			// ���� dfs�� return ���� false�� false ��ȯ 
			if(!dfs(graph[num][i], checked[num])){
				return false;
			}
		}
		// ��� ������ ��忡 ���� dfs return���� true�� true ��ȯ 
		return true;
	}
	// �ش� ��带 �湮�� �� ������ true ��ȯ 
	return true;	
}

int main(void){
	
	// test case ���� �Է� 
	int k;
	scanf("%d", &k);
	
	// test case ������ŭ �ݺ� 
	while(k--){
		// ��� ��, ���� �� �Է� 
		int v, e;
		scanf("%d %d", &v, &e);
		// �湮 ����, ��� ���� ���� 
		checked = new int[v + 1]{0};	// 0 : �湮 x, 1, 2: ��� ���� 
		// ���� ���� �Է� 
		graph = new vector<int>[v + 1];
		for(int i = 0; i < e; i++){
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
		}
		// �̺� �׷��� �Ǻ� ��� ���� 
		bool result = true;
		// ��� ��忡 ���� �ݺ� 
		for(int i = 1; i < v + 1; i++){
			// ���� �湮�� �� ������ dfs ���� 
			if(checked[i] == 0){
				// ���� return ���� false�� NO ��� �� break 
				if(!(result = dfs(i, 2))) {
					printf("NO\n");
					break;
				}
			}
		}
		// ���� return���� true�� YES ��� 
		if(result) printf("YES\n");
	}
}
