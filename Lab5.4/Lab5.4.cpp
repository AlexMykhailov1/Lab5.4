// Lab 5.4.cpp
// Михайлов Олександр
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 24

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double S1(const int K, const int N, const int i, double t) {

	t = t + (sqrt(1 + cos(sin(i)) * cos(sin(i)))) / (1 + cos(sin(i)) * cos(sin(i)));
	if (i <= K)
		return t;
	else
		return S1(K, N, i - 1, t);
}

double S2(const int K, const int N, const int i, double t) {

	t = t + (sqrt(1 + cos(sin(i)) * cos(sin(i)))) / (1 + cos(sin(i)) * cos(sin(i)));
	if (i >= N)
		return t;
	else
		return S2(K, N, i + 1, t);
}

double S3(const int K, const int N, const int i) {
	if (i < K)
		return 0;
	else
		return (sqrt(1 + cos(sin(i)) * cos(sin(i)))) / (1 + cos(sin(i)) * cos(sin(i))) + S3(K, N, i - 1);
}

double S4(const int K, const int N, const int i) {
	if (i > N)
		return 0;
	else
		return (sqrt(1 + cos(sin(i)) * cos(sin(i)))) / (1 + cos(sin(i)) * cos(sin(i))) + S4(K, N, i + 1);
}

double S5(const int K, const int N) {
	double s = 0;
	for (int i = K; i <= N; i++)
		s += (sqrt(1 + cos(sin(i)) * cos(sin(i)))) / (1 + cos(sin(i)) * cos(sin(i)));
	return s;
}

int main()
{
	int K = 1, N;

	cout << "N = "; cin >> N;

	cout << "(rec down --) S1 = " << S1(K, N, N, 0) << endl;
	cout << "(rec down ++) S2 = " << S2(K, N, K, 0) << endl;
	cout << "(rec up --)   S3 = " << S3(K, N, N) << endl;
	cout << "(rec up ++)   S4 = " << S4(K, N, K) << endl;
	cout << "(iter)        S5 = " << S5(K, N) << endl;

	cin.get();
	return 0;
}
