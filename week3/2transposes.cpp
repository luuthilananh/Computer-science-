#include<iostream>
using namespace std;
#define N 10
//doi cho vi tri cac so trong ma tran
// user defined function to print 2 day array with correct format
void print_arr (int arr[][N], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()

{
    int n;
    cin >> n;
    int arr[N][N];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> arr[i][j];
        }
    }

    int transpose[N][N];

	for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            // insert arr[row][col] to transpose[col][row]
            transpose[j][i] = arr[i][j];
        }

    }
	print_arr(transpose, n);

return 0;
}