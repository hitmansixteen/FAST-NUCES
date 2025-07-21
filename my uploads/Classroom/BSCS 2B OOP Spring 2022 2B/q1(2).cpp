#include<iostream>
using namespace std;

class SparseMatrix{
	int rows;
	int column;
	int ** mat;
public:
	SparseMatrix(){
	rows=column=0;
	mat = nullptr;
	}
	SparseMatrix(int r,int c,int** m){
		rows=r;
		column=c;
		mat = new int*[rows];
		for(int i=0;i<rows;i++){
			mat[i]=new int[column];
		}
		for(int i=0;i<rows;i++){
			for(int j=0;j<column;j++){
				mat[i][j]=m[i][j];
			}
		}
		
	}

	friend ostream& operator<<(ostream& out,SparseMatrix& m){
	
	int* compact_len = new int[m.rows];
		int** compact = new int*[m.rows];
		int count;
		for(int i=0;i<m.rows;i++){
			count=0;
			for(int j=0;j<m.column;j++){
				if(m.mat[i][j]!=0)
					count++;
			}
			compact_len[i]=count;
			compact[i] = new int[count*2];
		}
		int x;
		for(int i=0;i<m.rows;i++){
			x=0;
			for(int j=0;j<m.column;j++){
				if(m.mat[i][j]!=0){
					compact[i][x]=j;
					compact[i][++x]=m.mat[i][j];
					++x;
				}	
			}
		}
		for(int i=0;i<m.rows;i++){
			for(int j=0;j<compact_len[i];j++){
				out<<compact[i][j]<<" ";
			}
			cout<<endl;
		}

		return out;
	}

	int** operator++(){
		for(int i=0;i<this->rows;i++){
			for(int j=0;j<this->column;j++){
				this->mat[i][j]++;
			}
		}
		return this->mat;
	}

	int** operator++(int){
		SparseMatrix temp;
		
		for(int i=0;i<temp.rows;i++){
			for(int j=0;j<temp.column;j++){
				temp.mat[i][j]=this->mat[i][j];
			}
		}

		for(int i=0;i<rows;i++){
			for(int j=0;j<column;j++){
				this->mat[i][j]++;
			}
		}
		return temp.mat;
	}


	~SparseMatrix(){
		for(int i=0;i<rows;i++){
			delete[] mat[i];
		}
		delete[] mat;
	}
};

int main()
{
	int **mat= new int*[3];
	for (int i = 0; i < 3; i++)
	{
		mat[i]=new int[7];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cin>>mat[i][j];
		}
	}

	SparseMatrix matrix(3,7,mat);

	cout<<endl<<endl;
	cout<<matrix++;
	cout<<endl<<endl;
	cout<<++matrix;



	system("pause");
	return 0;
}