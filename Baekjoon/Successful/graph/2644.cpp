// 2644
// bfs

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;


int main(void){
	
	int n, p1, p2, m;
	scanf("%d", &n);
	scanf("%d %d", &p1, &p2);
	scanf("%d", &m);
	// ��� & ���� ���� ���� 
	vector<int> family[n + 1];
	// ��� �� p1������ �Ÿ� ���� 
	int dist[n + 1]={0};
	
	// ���� ���� �Է� 
	for(int i = 0; i < m; i++){
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		family[n1].push_back(n2);
		family[n2].push_back(n1);
	}
	
	// �湮�ؾ��� ��� ���� & ���� ��� p1���� ���� 
	queue<int> queue({p1});

	// queue�� ������������� �ݺ� 
	while(!queue.empty()){
		// queue�� ���� �� ���� ������ ��� now�� �Է� 
		int cur = queue.front();
		// queue�� ���� �� ���� ������ ���� ���� 
		queue.pop();
		
		// ���� ��ġ�� p2�� ����� �Ÿ� ��� �� ���� 
		if (cur == p2){
			printf("%d", dist[cur]);
			return 0;
		}else{
			int max = family[cur].size();
			// �ش� ��忡 ����Ǿ� �ִ� ���� ����ŭ �ݺ� 
			for(int i = 0; i < max; i++){
				// ����Ǿ��ִ� ��� ��ȣ  
				int p = family[cur][i];
				// �ش� ��忡 �̹� �湮�� �� ������ continue 
				if(dist[p] != 0) continue;
				//�ش� �������� �Ÿ� = ���� �������� �Ÿ� + 1
				dist[p] = dist[cur] + 1;
				// queue�� �߰� 
				queue.push(p);
			}
			// �ش� ��� ���� ���� �ʱ�ȭ ���̻� �ʿ� ���� 
			family[cur].clear();
		}
	}
	// �� ��尡 ����Ǿ� ���� ���� ��� -1 ���  
	printf("%d", -1);
}
