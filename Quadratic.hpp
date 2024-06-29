class Quad{
private:
float a, b, c;
public:
void coeff(){
    std::cout<<"general form::- A(X^2) + B(X) + C\n";
    std::cout<<"@@@@@@@@@@@@@@@@@@@@@\n";
    std::cout << "enter the co.eff A:";
    std::cin >> a;
    std::cout << "enter the co.eff B:";
    std::cin >> b;
    std::cout << "enter the co.eff C:";
    std::cin >> c;
  }
void roots (){
float d, r1, r2, impart, rlpart;
d = b * b - 4 * a * c;
r1 = (-b + sqrt (d)) / (2 * a);
r2 = (-b - sqrt (d)) / (2 * a);

if (a == 0){
r2 = -c / b;
std::cout << "the following is not a quadratic equation\n";
std::cout << "the value of zero for the above is " << r2;
      }
else if (d > 0){
std::cout << "the roots are real and distinct\n";
std::cout << "the first root is " << r1 << " and the second root is " <<r2;
      }
else if (d == 0){ 
std::cout << "both the roots are same and real\n";
r1 = (-b) / 2 * a;
std::cout << "the value of roots are " << r1 << " and " << r1;
}
else{ 
std::cout << "the roots are imaginary\n";
impart = sqrt (-d) / (2 * a);
rlpart = -b / 2 * a;
std::cout << "the first root is " << rlpart << "+" << impart << "i\n";
std::cout << "the second root is " << rlpart << "-" << impart << "i\n";
      }
   }
};
