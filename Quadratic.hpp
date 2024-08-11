class Quad
{
private:
      float _a, _b, _c;

public:
      void coeff(double a, double b, double c)
      {
            _a = a;
            _b = b;
            _c = c;
      }
      string roots()
      {
            float d, r1, r2, impart, rlpart;
            d = _b * _b - 4 * _a * _c;
            r1 = (-_b + sqrt(d)) / (2 * _a);
            r2 = (-_b - sqrt(d)) / (2 * _a);

            if (_a == 0)
            {
                  r2 = -_c / _b;
                  // std::cout << "the following is not a quadratic equation\n";
                  // std::cout << "the value of zero for the above is " << r2;
                  return "";
            }
            else if (d > 0)
            {
                  // std::cout << "the roots are real and distinct\n";
                  // std::cout << "the first root is " << r1 << " and the second root is " << r2;
                  return "";
            }
            else if (d == 0)
            {

                  // std::cout << "both the roots are same and real\n";
                  r1 = (-_b) / 2 * _a;
                  // std::cout << "the value of roots are " << r1 << " and " << r1;
                  return "";
            }
            else
            {
                  // std::cout << "the roots are imaginary\n";
                  impart = sqrt(-d) / (2 * _a);
                  rlpart = -_b / 2 * _a;
                  // std::cout << "the first root is " << rlpart << "+" << impart << "i\n";
                  // std::cout << "the second root is " << rlpart << "-" << impart << "i\n";
                  return "";
            }
      }
};
