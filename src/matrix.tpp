#pragma once
#include"../include/matrix.hpp"


template<typename type, unsigned int SIZE>
Matrix<type,SIZE>::Matrix() {
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            if (i==j)
            value[i][j] = 1.0;
            else
            value[i][j] = 0.0;
        }
    }
}



template<typename type, unsigned int SIZE>
Matrix<type,SIZE>::Matrix(type tmp[SIZE][SIZE]) {
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}

template<typename type, unsigned int SIZE>
Matrix<type,SIZE>::~Matrix(){
    //std::cout<<"Deleting matrix"<<std::endl;
}

template<typename type, unsigned int SIZE>
Vector<type,SIZE> Matrix<type,SIZE>::operator * (Vector<type,SIZE> const & tmp) const{
    Vector<type,SIZE> result;
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}



template<typename type, unsigned int SIZE>
type &Matrix<type,SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}



template<typename type, unsigned int SIZE>
const type &Matrix<type,SIZE>::operator () (unsigned int row, unsigned int column) const{

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


template<typename type, unsigned int SIZE>
Matrix<type,SIZE> Matrix<type,SIZE>::operator + (Matrix<type,SIZE> tmp) {
    Matrix result;
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}


template<typename type, unsigned int SIZE>
Matrix<type,SIZE> Matrix<type,SIZE>::operator - (Matrix<type,SIZE> tmp) {
    Matrix result;
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            result(i, j) = this->value[i][j] - tmp(i, j);
        }
    }
    return result;
}

template<typename type, unsigned int SIZE>
std::istream &operator>>(std::istream &in, Matrix<type,SIZE> &mat) {
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            in >> mat(i, j);
        }
    }
    return in;
}



template<typename type, unsigned int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<type,SIZE> &mat) {
    out.precision(10);
    for (unsigned int  i = 0; i < SIZE; ++i) {
        for (unsigned int  j = 0; j < SIZE; j++) {
            out << "| " <<std::setw(10) << std::fixed << std::setprecision(10) << mat(i, j) << " * "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

template<typename type, unsigned int SIZE>
bool Matrix<type,SIZE>::operator == (Matrix<type,SIZE> const &tmp) const{
    unsigned int  i,j;
    for (i=0;i<SIZE;++i){
        for (j=0;j<SIZE;++j){
            if (!(abs(value[i][j]-tmp.value[i][j])<=0.000001))
                return 0;
        }
    }
    return 1;
}

template<typename type, unsigned int SIZE>
Matrix<type,SIZE> Matrix<type,SIZE>::gauss() const{
    Matrix mat = *this;

    unsigned int  i,j,k;
    type ratio;
    for (i=0;i<SIZE-1;i++){
        if (value[i][i] == 0)
            return 0;
        for (j=i+1; j<SIZE; j++){
            ratio = value[j][i] / value[i][i];
            for (k=0; k<SIZE; k++){
                mat.value[j][k] = (value[j][k] - ratio*value[i][k]);
            }
        }
    }
    return mat;
}

template<typename type, unsigned int SIZE>
type Matrix<type,SIZE>::determinant() const{
    type det;
    unsigned int  i;
    Matrix tmp = this->gauss();
    det = 1;
    for (i=0;i<SIZE;++i){
        det*=tmp.value[i][i];
    }
    return det;
}


template<typename type, unsigned int SIZE>
Matrix<type,SIZE> Matrix<type,SIZE>::operator*(Matrix<type,SIZE> const &mat) const{
    unsigned int  i,j,k;
    Matrix res;
    for (i=0; i<SIZE; i++){
        res.value[i][i] = 0;    //zerowanie elementow macierzy ktore sa rowne 1 
                                //(z konstruktora bezparametrycznego)
    }
    for (i=0; i< SIZE; ++i){
        for (j=0; j< SIZE; ++j){
            for (k=0;k<SIZE;k++){
                res.value[i][j]+= value[i][k] * mat.value[k][j];
            }
        }
    }
    return res;
}