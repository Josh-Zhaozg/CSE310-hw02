#include<iostream>
using namespace std;
int main(){
auto n{4};
auto INFTY = numeric_limits<double>::max();
// 初始化距离矩阵D
double D[][4]{ {0, 2, 6, 4},
			   {INFTY, 0, 3, INFTY},
			   {7, INFTY, 0, 1 },
			   {5, INFTY, 12, 0} };
// 初始化路径矩阵P
unsigned int P[][4]{ {0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0} };
	for (auto u = 0; u < n; ++u){
		for (auto v = 0; v < n; ++v){
			P[u][v] = u; //直达路径uv的终点的前一个顶点是u，终点是v
            }}
//打印D和P矩阵
	cout << "初始的距离和路径矩阵：\n";
	for (auto& row : D) { //row是引用ia的每个元素，因此row是一个int[4]的数组
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
		}	
	cout << '\n';
	for (auto& row : P) { //row是引用ia的每个元素，因此row是一个int[4]的数组
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
	}
	cout << endl;
//Floyd算法 核心算法
	for (auto w = 0; w < n; ++w){ //对每个顶点w，都绕道一次，更新D和P
		for (auto u = 0; u < n; ++u){
			for (auto v = 0; v < n; ++v){
				//绕道w使D[u][v]变得更短吗？
				if (w != u and w != v and D[u][w] + D[w][v] < D[u][v]) { 
					D[u][v] = D[u][w] + D[w][v];
					P[u][v] = P[w][v];
				}
            }}}
//打印D和P矩阵
	cout << "最终的距离和路径矩阵：\n";
	for (auto& row : D) {
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
	}
	cout << '\n';
	for (auto& row : P) {
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
	}
	cout<<endl;
	for (auto u = 0; u < n; u++)
		for (auto v = 0; v < n; v++) {
			if (u == v) continue;
			cout << u << "到" << v << "的逆向路径是:";
			cout << v << ','; //终点
			//auto w{ P[u][v] };
			for (auto w{ P[u][v] }; w != u;) {
				cout << w << ',';
				w = P[u][w];
			}
			cout << u << endl;
		}
return 0;
}