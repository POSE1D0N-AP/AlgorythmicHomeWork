#include<iostream>
#include<math.h>
using namespace std;

class Point{
  private:
    int x;
    int y;
  public:
    Point(){}
    Point(int x, int y){
      this -> x = x;
      this -> y = y;
    }
    void setPoint(int x,int y){
      this -> x = x;
      this -> y = y;
    }
    void inputPoint(){
      int x, y;
      cin >> x >> y;
      this -> x = x;
      this -> y = y;
    }
    int getPointX(){
      return x;
    }
    int getPointY(){
      return y;
    }
};

class Rectangle{
  private: 
    Point a;
    Point b;
    Point c;
    Point d;
    bool flagCorrect = true;
  public:
    Rectangle(Point a, Point b, Point c, Point d){
      double ab = sideLenght(a, b), bc = sideLenght(b, c), cd = sideLenght(c, d), da = sideLenght(d, a);
      if(ab - cd == 0 && da - bc == 0){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
      }
      else{
        cout << "#0 ERROR! Incorrect input data!!!" << endl;
        flagCorrect = false;
      }
    }
    void setA(Point a){
      this-> a = a;
    }
    void setB(Point b){
      this-> b = b;
    }
    void setC(Point c){
      this-> c = c;
    }
    void setD(Point d){
      double ab = sideLenght(a, b), bc = sideLenght(b, c), cd = sideLenght(c, d), da = sideLenght(d, a);
      if(ab - cd == 0 && da - bc == 0){
        this->d = d;
        flagCorrect = true;
      }
      else{
        cout << "#1 ERROR! Incorrect input data!!!" << endl;
        flagCorrect = false;
      }
    }
    double sideLenght(Point a, Point b){
      return sqrt(pow(b.getPointX()-a.getPointX(), 2) + pow(b.getPointY() - a.getPointY(),2));
    }
    double perimeter(){
      double p;
      if(flagCorrect){
      p = sideLenght(a, b) + 
          sideLenght(b, c) + 
          sideLenght(c, d) + 
          sideLenght(d, a);
      }
      else {
        p = 0;
      }
      return p;
    }

};



int main(){
  while(1 == 1){
    string cmd;
    Point a;
    Point b;
    Point c;
    Point d;
    cin >> cmd;
    if(cmd == "input"){
      cout << "Input A: ";
      a.inputPoint();
      cout << "Input B: ";
      b.inputPoint();
      cout << "Input C: ";
      c.inputPoint();
      cout << "Input D: ";
      d.inputPoint();
    }
    else if(cmd == "perimeter"){
      Rectangle r(a, b, c, d);
      cout << "P: " << r.perimeter() << endl;
    }
    else if(cmd == "stop"){
      break;
    }
    else {
      cout << "unkown command: " << cmd << endl;
    }
  }
  return 0;
 }