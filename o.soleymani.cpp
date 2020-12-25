#include <iostream>
using namespace std;
 class city{
  protected:
  string namecity;
  double Area;
  public:
 city( string name1= "Tehran",double area1= 100):namecity(name1),Area(area1){}
      virtual double AreaAve(void)=0;
};
 class district: public city{
  string namedis;
  public:
  double area, people;
  double ave= 0;
  district(string name1= "Tehran", string name2= "paeez",double area1 =1, double area2= 100, double p= 0):city(name1,area1){
   people =p;
   namedis=name2;
   area=area2;
  }
  virtual double AreaAve(void){
    ave= area/people;
    return ave;
  }
   virtual double Health (void){
   return 0;
 }
  void print()const{
   cout << "Name of City is:\t" << namecity << endl;
   cout << "Area of city:\t" << Area << endl << endl;
   cout << "Name of district:\t" << namedis << endl;
   cout << "Area is:\t" << area << endl;
   cout << "People is:\t" << people << endl;
   cout << "The area for each person is:\t" << ave << endl;
  }
};
 class person: public district{
  string familynm;
  public:
  double family, ave1= 0;
  person(string name= "ali",const double p= 0){
   familynm= name;
   family= p;
  }
  virtual double AreaAve(void){
   ave1= (family/people) * 100;
    return ave1;
  }
   virtual double Health (void){
   return 0;
 }
   void print()const{
   cout << "Name of Family:\t" << familynm << endl;
   cout << "Family member is:\t" << family << endl;
   cout << "Percentage of number of family members in the neighborhood:\t" << ave1 << endl;
  }
 };
 class health: public person{
  double height, mass, bmi;
  public:
 health(const double a = 0,const double b = 0 ){
  mass = a;
  height = b;
 }
 virtual double Health (void){
   bmi= mass/ (height* height);
   return bmi;
 }
 void print()const{
  cout << "BMI is:\t" << bmi << endl;
  if(bmi < 18.5)
    cout << "THIN" << endl;
  if(bmi >= 18.5 && bmi <= 24.9)
    cout << "NORMAL" << endl;
  if(bmi > 25)
    cout << "FAT" << endl;
 }
};

int main(){
 district a("Esfahan","Bahar",100000,200,40);
 a.AreaAve();
 a.print();
 cout << endl;
 person b("Khani",5);
 b.AreaAve();
 b.print();
 cout << endl;
 health c( 100, 1.65);
 c.print();
 district d("Khansar","Aseman",60000,150,30);
 d.AreaAve();
 d.print();
 cout << endl;
 person e("Khani",3);
 e.AreaAve();
 e.print();
 cout << endl;
 health f( 65, 1.75);
 f.print();

}
