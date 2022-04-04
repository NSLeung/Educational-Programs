#include <iostream>
using namespace std;
class Base {
    public:
    static int i;
    static int bob; // see if static fn can access
    Base() {
        cout << "Base ctor " << endl;
        data = 1;
        // bob = 2;
    }
    ~Base() {
        cout << "Base dtor " << endl;

    }
    //lets make a virtual function
    virtual void fun() {
        cout << "fun in Base " << endl;
    }
    //lets make a static function
    static void pop() {
        cout << "static bois in base " << bob << endl;
    }
    protected:
        int data;
};

class Derived : public Base {
    public:
        Derived() {
            cout << "Derived ctor " << endl;
            data = 2;
        }
        ~Derived() {
            cout << "Derived dtor " << endl;

        }
        void fun() {
            cout << "fun in derived " << endl;
        }
};

class Distance {
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
      
   public:
      // required constructors
      Distance() {
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i) {
         feet = f;
         inches = i;
      }
      //overloading stream operators
      friend ostream &operator<<( ostream &output, const Distance &D ) { 
         output << "F : " << D.feet << " I : " << D.inches;
         return output;            
      }

      friend istream &operator>>( istream  &input, Distance &D ) { 
         input >> D.feet >> D.inches;
         return input;            
      }
};
int Base::i = 50; 
int Base::bob = 30;
int main() {
    // Derived *b = new Derived(); //prints Base first even if Derived
    // delete b;   //dtor called in reverse
    Derived d;
    Base* b = &d;
    b->fun();

    // static stuff
    Base b1;
    Base b2;
    b1.i = 1;
    b2.i = 2;

    cout << b1.i << endl;
    cout << b2.i << endl;
    
    //static stuff
    b1.pop();



    // Distance D1(11, 10), D2(5, 11), D3;

    // cout << "Enter the value of object : " << endl;
    // cin >> D3;
    // cout << "First Distance : " << D1 << endl;
    // cout << "Second Distance :" << D2 << endl;
    // cout << "Third Distance :" << D3 << endl;

    // //random pre/post increment stuff
    // int a = 3;
    // int b = 2;
    // int c = a++ + ++b;  //2 + 4
    // cout << "a: " << a << " b: " << b << " c: " << c << endl;
    
    return 0;
}