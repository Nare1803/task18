#include<iostream>

template <typename T>
class shape {
protected:
  T dimension;
public:
  virtual T area() = 0;
  virtual ~shape(){}
};

template<typename T>
class Circle : public shape<T> {
private:
    const double pi = 3.14;
    T a;
public:
    Circle (T a1) : a(a1) {}
    T area () override {
        return pi * a * a;
    }
};

template<typename T>
class Rectangle : public shape<T> {
private:
    T a;
    T b;
public:
    Rectangle(T a1,T b1) {
        b = b1;
	a = a1;
    }
    T area () override{
       return a * b ;
      }
};
template<typename T>
 T foo(shape<T> * ptr) {
	T x = ptr -> area();
	return x;
}

int main()
{
  
  int a;
  std::cout << "Enter the integer value,that we use to count shapes :" << std::endl;
  std::cin >> a;

  int b;
  std::cout << "Enter rectangle's second side(for int) :" << std::endl;
  std::cin >> b;

  shape<int>* intptr = new Circle<int>(a);
  std::cout << "Circle's shape is : ";
  std::cout << foo(intptr) << std::endl;

  delete intptr;
  intptr = nullptr;


  double a1;
  std::cout << "Enter the double  value,that we use to count shapes :" << std::endl;
  std::cin >> a1;

  double b1;
  std::cout << "Enter rectangle's second side(for double) :" << std::endl;
  std::cin >> b1;

  shape<double>* doubleptr = new Rectangle<double>(a,b);
  std::cout << "Rectangle's shape is : ";
  std::cout << foo(doubleptr) << std::endl;

  delete doubleptr;
  doubleptr = nullptr;

  return 0;
}
