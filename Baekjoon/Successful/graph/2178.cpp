// 2178
// bfs

#include <stdio.h>
#include <queue>

using namespace std;


int main(void){
	
	int n, m;
	scanf("%d %d", &n, &m);
	// ��� & ���� ���� ���� 
	int nodenum = n * m;
	int map[nodenum];
	// ��� �� p1������ �Ÿ� ���� 
	int dist[nodenum]={1, 0};
	
	// ���� ���� �Է� 
	for(int i = 0; i < nodenum; i++){
		scanf("%1d", &map[i]);
	}
	
	// �湮�ؾ��� ��� ���� & ���� ��� p1���� ���� 
	queue<int> queue({0});

	// queue�� ������������� �ݺ� 
	while(!queue.empty()){
		// queue�� ���� �� ���� ������ ��� now�� �Է� 
		int cur = queue.front();
		// queue�� ���� �� ���� ������ ���� ���� 
		queue.pop();
		
		// ���� ��ġ�� p2�� ����� �Ÿ� ��� �� ���� 
		if (cur == nodenum - 1){
			printf("%d", dist[cur]);
			return 0;
		}else{
			// ������� idx ���� 
			int array[4] = {-1, -1, -1, -1};
			if(cur >= m) array[0] = cur - m; 			// �� ��� 
			if(cur < nodenum - m) array[1] = cur + m;	// �Ʒ� ��� 
			if(cur % m != 0) array[2] = cur - 1;		// ���� ��� 
			if(cur % m != m - 1) array[3] = cur + 1;	// ���� ��� 
			for(int i = 0; i < 4; i++){
				int idx = array[i];
				// �ش� ���� �̵��� �Ұ����ϰų� �ش� ��忡 �̹� �湮�� �� ������ continue 
				if(idx == -1 || map[idx] == 0 || dist[idx] != 0) continue; 
				//�ش� �������� �Ÿ� = ���� �������� �Ÿ� + 1
				dist[idx] = dist[cur] + 1;
				// queue�� �߰� 
				queue.push(idx);
			}
		}
	}
}
