#include <iostream>
#include <math.h>
#include <tuple>
#include <Eigen/Core> // Eigen Library
#include <Eigen/LU>   // Eigen Library

using namespace std;
using namespace Eigen;

float measurements[3] = { 1, 2, 3 };

tuple<MatrixXf, MatrixXf> kalman_filter(MatrixXf x, MatrixXf P, MatrixXf u, MatrixXf F, MatrixXf H, MatrixXf R, MatrixXf I)
{
    for (int n = 0; n < sizeof(measurements) / sizeof(measurements[0]); n++) {
        //****** TODO: Kalman-filter function********//
        
        // Measurement Update
        // Code the Measurement Update
        // Initialize and Compute Z, y, S, K, x, and P
        MatrixXf Z(1, 1);
        Z << measurements[n];
        
        MatrixXf y(1, 1);
        y << Z - (H * x);
        
        MatrixXf S(1, 1);
        S << H * P * H.transpose() + R;
        
        MatrixXf K(2, 1);
        K << P * H.transpose() * S.inverse();
        
        x << x + (K * y);
        P << (I - (K * H)) * P;

        // Prediction
        // Code the Prediction
        // Compute x and P
        x << (F * x) + u;
        P << F * P * F.transpose();
    
    }

    return make_tuple(x, P);
}

int main()
{

    MatrixXf x(2, 1);// Initial state (location and velocity) 
    x << 0,
    	 0; 
    MatrixXf P(2, 2);// Initial Uncertainty
    P << 100, 0, 
    	 0, 100; 
    MatrixXf u(2, 1);// External Motion
    u << 0,
    	 0; 
    MatrixXf F(2, 2);// Next State Function (Transition Function)
    F << 1, 1,
    	 0, 1; 
    MatrixXf H(1, 2);// Measurement Function
    H << 1,
    	 0; 
    MatrixXf R(1, 1); // Measurement Uncertainty
    R << 1;
    MatrixXf I(2, 2);// Identity Matrix
    I << 1, 0,
    	 0, 1; 

    tie(x, P) = kalman_filter(x, P, u, F, H, R, I);
    cout << "x= " << x << endl;
    cout << "P= " << P << endl;

    return 0;
}

/*
此处比图片提供的公式多了 External Motion
x的状态(state)有t时刻和t-1时刻之分，只要不交叉访问，直接先后对x赋值即可，不需建立类似xt、xt_1多个状态变量
*********************************************************************************************************
尝试替换第 10 行，观察运行结果(state和covariance)：
float measurements[3] = { 1, 2, 3 };
float measurements[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
float measurements[10] = { 1, 2, 3, 3, 3, 3, 3, 3, 3, 3 };
*/ 
