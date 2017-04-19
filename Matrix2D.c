#include "Matrix2D.h"


MX CreatMx(float data[], int R, int C, int z){ //创建矩阵，data为一维数据，浮点型，按行遍历。R为行数，C为列数。z为参数，等于0时则创建0矩阵，等于1则按data中数据创建。
	MX M;
	M.R = R; M.C = C;

	M.pMx = (float **)malloc(R*sizeof(float*));
	for (int i = 0; i<R; i++){
		M.pMx[i] = (float *)malloc(C*sizeof(float));
	}//以上申请空间

	for (int i = 0, n = 0; i<R; i++){ //赋值，该处待更改，因为实际数据可能不是一个一维数组
		for (int j = 0; j<C; j++, n++){
			if (z == 0) M.pMx[i][j] = 0.0; //是否创建0矩阵
			else M.pMx[i][j] = data[n];
		}
	}
	return M; //返回该矩阵
}

void FreeMx(float **p, int R){ //释放矩阵，p为首地址，R为列数
	for (int i = 0; i < R; i++){
		free(p[i]);//先释放一维指针
		p[i] = NULL;
	}
	free(p);//最后释放二维指针
	p = NULL;
}

/*
将pResult设置为单位矩阵
*/
void Matrix2DIdentity(MX *pResult)
{

}

// ---------------------------------------------------------------------------

/*
计算pMtx的转置，并将结果放到pResult
*/
void Matrix2DTranspose(MX *pResult, MX *pMtx)
{

}

// ---------------------------------------------------------------------------

/*
Result = Mtx0*Mtx1
*/
void Matrix2DConcat(MX *pResult, MX *pMtx0, MX *pMtx1)
{

}

// ---------------------------------------------------------------------------

/*
将pResult设置为平移矩阵，平移位移为x和y
*/
void Matrix2DTranslate(MX *pResult, float x, float y)
{

}

// ---------------------------------------------------------------------------

/*
将pResult设置为缩放矩阵，x和y分别为水平和垂直方向的缩放比例
*/
void Matrix2DScale(MX *pResult, float x, float y)
{

}

// ---------------------------------------------------------------------------

/*
将pResult设置为旋转矩阵，旋转量为Angle，为度数
*/
void Matrix2DRotDeg(MX *pResult, float Angle)
{

}

// ---------------------------------------------------------------------------

/*
将pResult设置为旋转矩阵，旋转量为Angle，为弧度
*/
void Matrix2DRotRad(MX *pResult, float Angle)
{

}

// ---------------------------------------------------------------------------

MX MultiMx(MX X, MX Y){ //矩阵乘法，M=X*Y，自带创建M矩阵
	float ar[1];
	MX M = CreatMx(ar, X.R, Y.C, 0);

	for (int i = 0; i < X.R; ++i){
		for (int k = 0; k < X.C; ++k){
			float r = X.pMx[i][k];
			for (int j = 0; j < Y.C; ++j){
				M.pMx[i][j] += r*Y.pMx[k][j];
			}
		}
	}
	return M; //返回运算结果
}

// ---------------------------------------------------------------------------


/*矩阵乘法测试
void main()
{
float A[6] = { 1.0,2.0,3.0,4.0,5.0,6.0};
float B[6] = { 100.0,10.0,10.0,100.0,1.0,1000.0 };

MX X = CreatMx(A, 2, 3, 1);
MX Y = CreatMx(B, 3, 2, 1);
MX M = MultiMx(X, Y);

printf("%f\n", M.pMx[0][0]);
printf("%f\n", M.pMx[1][1]);
FreeMx(X.pMx, X.R);
FreeMx(Y.pMx, Y.R);
}
*/