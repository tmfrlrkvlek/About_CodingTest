// 10026
// [DFS] ���� �켱 Ž�� ���� 

#include <stdio.h>
#include <vector>

using namespace std;

int nSum = 0;							// ���ϻ��� �ƴ� ��� ���� ���� �� 
int norSum = 0;							// ���ϻ����� ��� ���� ���� �� 
bool *checked;							// ��� �湮 ���� üũ 

void DFS(vector<int> graph[], vector<char> pixels, int idx, int kind){
	if (checked[idx] == true){
		return;
	}
	else{
		if(kind == 0){						// �� �������� ó�� DFS�� ȣ���� �� Sum�� �������� �ش�. 
			nSum++;
		}else if(kind == 1){
			norSum++;
		}
		checked[idx] = true;
		for(int i = 0; i < graph[idx].size(); i++){
			DFS(graph, pixels, graph[idx][i], 2);	// kind = 2�� ������ �� ���� DFS ���ʹ� Sum�� ������Ű�� �ʵ��� �Ѵ�. 
		}
	}
	return;
}

int main(void){
	int n;
	scanf("%d\n", &n);
	vector<int> pictures[n * n + 1];		// ���ϻ����� �ƴ� ��� ���� �׷��� 
	vector<int> norPictures[n * n + 1];		// ���ϻ����� ��� ���� �׷��� 
	vector<char> pixels;					// �׸� �ȼ��� ���� 
	pixels.push_back('n');
	checked = new bool[n * n + 1];			 
	checked[0] = {true};
	// �Է� �� �׷��� ���� 
	for(int i = 0; i < n; i++){
		char pix;
		for(int j = 0; j < n; j++){
			int current = i * n + j + 1; 
			// �ȼ� �Է� 
			scanf("%c", &pix);
			pixels.push_back(pix);
			checked[current] = false;
			// �׷��� ���� 
			if (i != 0){
				if(pixels[current] == 'G' || pixels[current] == 'R'){	
					if(pixels[current - n] == 'G' || pixels[current - n] == 'R'){
						norPictures[current].push_back(current - n);
						norPictures[current - n].push_back(current);
					}
				}else{
					if(pixels[current - n] == pix){
						norPictures[current].push_back(current - n);
						norPictures[current - n].push_back(current);
					}
				}
				if(pixels[current - n] == pix){
					pictures[current].push_back(current - n);
					pictures[current - n].push_back(current);
				}
				
			}
			if (j != 0){
				if(pixels[current] == 'G' || pixels[current] == 'R'){
					if(pixels[current - 1] == 'G' || pixels[current - 1] == 'R'){
						norPictures[current].push_back(current - 1);
						norPictures[current - 1].push_back(current);
					}
				}else{
					if(pixels[current - 1] == pix){
						norPictures[current].push_back(current - 1);
						norPictures[current - 1].push_back(current);
					}
				}
				if(pixels[current - 1] == pix){
					pictures[current].push_back(current - 1);
					pictures[current - 1].push_back(current);
				}
			}
		}
		scanf("%c", &pix);						// �Էµ� '\n' ���� 
	}
	
	// 1 ~ 25 ��� ��� �ѹ��� DFS ���� - ���ϻ��� �ƴ� ��� ���� 
	int i = 1;
	while(i != n * n + 1){						
		DFS(pictures, pixels, i++, 0);
	}
	
	// ���� DFS�� ���� �ʱ�ȭ 
	for(i = 1; i < n * n + 1; i++){				
		checked[i] = false;
	}
	i = 1;
	
	// 1 ~ 25 ��� ��� �ѹ��� DFS ���� - ���ϻ����� ��� ���� 
	while(i != n * n + 1){						
		DFS(norPictures, pixels, i++, 1);
	}
	
	// ����� ��� 
	printf("%d %d", nSum, norSum);
	
}
