#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
using namespace std;

const int MAXSIZE = 100;

struct cell
{
	int x, y;
	int dis;
	
	cell() {}
	cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};


struct path
{
	int px, py;
};


void printJumps (path Arr[][MAXSIZE], int targetPos[], int knightPos[], int dis)
{
	
//	int i = targetPos[0], j = targetPos[1];
//	int i, j;
	ofstream output;
	output.open("output.txt");
	
	stack <path> list;
 	path temp;
	int i = targetPos[0], j = targetPos[1];
	int parentx, parenty;
	
	while (true)
	{	
		temp.px = i;
		temp.py = j;
		
		list.push(temp);
		
		if(i == knightPos[0] && j == knightPos[1])
			break;
		
		parentx = i;
		parenty = j;
		
		i = Arr[parentx][parenty].px;
		j = Arr[parentx][parenty].py;
	
	}
	
	cout << "\nShortest Number of Jumps to reach (" << targetPos[0] << ", " << targetPos[1] << ") from (" << knightPos[0] << ", " << knightPos[1] << ") : " << dis << "\n";
	output << "Shortest Number of Jumps to reach (" << targetPos[0] << ", " << targetPos[1] << ") from (" << knightPos[0] << ", " << knightPos[1] << ") : " << dis << "\n";
	cout << "Path Taken: \n";
	output << "Path Taken: \n";
	while(!list.empty())
	{
		cout << "(" << list.top().px << ", " << list.top().py << ")" << endl;
		output << "(" << list.top().px << ", " << list.top().py << ")" << endl;
		list.pop();
	}
	cout << "\n";		
	output << "\n";
}


bool isInside(int x, int y, int boardSize[])
{
	if (x >= 1 && x <= boardSize[0] && y >= 1 && y <= boardSize[1])
		return true;
	return false;
}

void minJumps(int knightPos[], int targetPos[], int boardSize[], int legalMove[])
{
	int dx[] = {(legalMove[0] * -1), (legalMove[1] * -1), legalMove[1], legalMove[0], (legalMove[0] * -1), (legalMove[1] * -1), legalMove[1], legalMove[0]};
	int dy[] = {(legalMove[1] * -1), (legalMove[0] * -1), (legalMove[0] * -1), (legalMove[1] * -1), legalMove[1], legalMove[0], legalMove[0], legalMove[1]};
	
	queue<cell> q;

	q.push(cell(knightPos[0], knightPos[1], 0));

	cell t;
	int x, y;
	int M = boardSize[0] + 1;
	int N = boardSize[1] + 1;
	bool visit[ M + 1 ][ N + 1 ];
	path Arr[ MAXSIZE ][ MAXSIZE ];
	
	Arr[knightPos[0]][knightPos[1]].px = knightPos[0];
	Arr[knightPos[0]][knightPos[1]].py = knightPos[1];

	for (int i = 1; i <= boardSize[0]; i++)
		for (int j = 1; j <= boardSize[1]; j++)
			visit[i][j] = false;

	visit[knightPos[0]][knightPos[1]] = true;

	while (!q.empty())
	{
		t = q.front();
		
		q.pop();
		visit[t.x][t.y] = true;
		
		if (t.x == targetPos[0] && t.y == targetPos[1])
		{
			printJumps (Arr, targetPos, knightPos, t.dis);
			return;
		}
		
		for (int i = 0; i < 8; i++)
		{
			x = t.x + dx[i];
			y = t.y + dy[i];
			
			if (isInside(x, y, boardSize) && !visit[x][y])
			{
				if(!visit[x][y])
				{
					q.push(cell(x, y, t.dis + 1));
					Arr[x][y].px = t.x;
					Arr[x][y].py = t.y;
				}	
			}
		}
	}
	
	cout << "No path can be found.\n";
	
}

int main()
{
	int M, N, p, q, X, Y, U, V;
	
	ifstream input;
	input.open("input.txt");
	
	if(!input.is_open())
	{
		cerr << "File not found.\nAborting...\n";
		return -1;
	}
	
	while(!input.eof())
	{
		input >> M >> N >> p >> q >> X >> Y >> U >> V;
	
		if((M >= 2 && M <= 100) && (N >= 2 && N <= 100) && (X >= 1 && X <= M) && (Y >= 1 && Y <= N) && (U >= 1 && U <= M) && (V >= 1 && V <= N))
		{
			int boardSize [] = {M, N};
			int legalMove[] = {p, q};
			int knightPos[] = {X, Y};
			int targetPos[] = {U, V};
			
			minJumps(knightPos, targetPos, boardSize, legalMove);
		}
				
	}
	
	return 0;
}







