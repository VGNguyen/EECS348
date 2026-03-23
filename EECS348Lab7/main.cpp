#include <iostream>
#include <fstream> 
using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin(ifstream &inFile){
    //Pass in the open file with &inFile so that each call of the function will continue where the last one left off 
    //Load each value into the data 2d array
    for (int i = 0; i<SIZE;i++){
      for(int j = 0; j<SIZE;j++){
        inFile >> data[i][j];
      }
    }
    
  }
  

  // 2. Display a matrix
  void display() const {
    //Loop through each row and print each value and then add newline, repeat for each line
      for (int i = 0; i<SIZE;i++){
        for(int j = 0; j<SIZE;j++){
            std::cout <<data[i][j] << " ";
      }
      std::cout << "\n" ;
    }
  }
    

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const {
    //Define a third matrix
    Matrix arr3;
    
    //Loop through every value and add up arr1 and arr2 at that place and put that into arr3
    for (int i=0; i<SIZE;i++){
        for(int j = 0; j<SIZE;j++){
            arr3.data[i][j] = data[i][j]+other.data[i][j];
        }
        
    }
    //return added array
    return arr3;
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const {
        //Define new third array to store values that is the size of arr1's rows and arr2's columns
        Matrix arr3;
        for (int i = 0; i <SIZE; i++){
            for(int j =0; j<SIZE;j++){
                //Matrix multiplication has you multiple each value in a row, add those values together, and then place them in the multiplied array
                int temp = 0;
                for (int k = 0; k < SIZE; k++){
                    temp += (data[i][k])*(other.data[k][j]);

                }
                //Set the value in the matrix to the temp value and reset temp
                arr3.data[i][j] = temp;
                temp = 0;
                
            }
            
        }
        //return completed array
        return arr3;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const{
    int sum = 0;
    //The diagonal has the same column and row i so loop through the size of array and add each of those up into sum
    for(int i = 0; i<SIZE;i++){
      sum+=data[i][i];
    }
    return sum;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2){
    int temp[SIZE];
    //Load each value from the first row individually into a temp array
    for(int i=0; i < SIZE; i++){
      temp[i]=data[row1][i];
    }
    //Replace row1's values with row2's values
    for(int i=0; i < SIZE; i++){
      data[row1][i] = data[row2][i];
    }
    //Replace row2 values with the values stored in temp
    for(int i=0; i < SIZE; i++){
      data[row2][i] = temp[i];
    }
  }
};

int main() {
  //Use ifstream and open the file with the data
  ifstream inFile;
  inFile.open("matrix-data.txt");
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1:" << endl;
  mat1.readFromStdin(inFile);
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2:" << endl;
  mat2.readFromStdin(inFile);
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();
  //Make sure to close the file
  inFile.close();
  return 0;
}
