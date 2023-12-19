#include<iostream>

using namespace std;
template <typename T>

class Array {
  public:
    int dimensions, size, *shape;
    T* values;
    T* inv;
    Array(int dimensions, int* shape, T* values) {
      this->dimensions = dimensions, this->shape = new int[dimensions];
      int size = 1;
      for (int i = 0; i < dimensions; i++) {size*=shape[i]; this->shape[i] = shape[i];}
      this->size = size, this->values = new T[size];
      for (int i = 0; i < size; i++) this->values[i] = values[i];
    }
    float det() {
      int n = shape[0];
      float *b = new float[n*n], *inv = new float[n*n];
      for (int i=0; i<n*n; i++) b[i] = this->values[i], inv[i] = i%n?0:1;
      float product = 1;
      for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
          float x = b[n*i+i];
          if (i==j) {
            for (int k=0; k<n; k++) {
              b[n*i+k] /= x, inv[n*i+k] /= x;
            }
            product *= x;
            continue;
          }
          float v = b[n*j+i]/x;
          for (int k=0; k<n; k++) {
            b[n*j+k] -= v*b[n*i+k];
            inv[n*j+k] -= v*inv[n*i+k];
          }
        }
      }
      delete[] b;
      return product;
    }
    void print() {
      cout << "[";
      for (int i=0; i<shape[0]; i++) {
        cout << "[ ";
        for (int j=0; j<shape[0]; j++) {
          cout << this->values[3*i+j] << " ";
        }
        cout << "]";
        if (i==shape[0]-1)      cout << "]";
        cout << "\n ";
      }
    }
    
    void del() {
      delete[] this->shape;
      delete[] this->values;
    }
};


int main()
{
  int a[2] = {3,3};
  float b[9] = {1,2,3,-4,5,6,7,-8,9};
  
  Array<float> array(2, a, b);
  array.print();
  cout << "The determinant is: " << array.det();
  array.del();
  return 0;
}
