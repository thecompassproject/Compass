class Fitit{
private:
int n;
double *x, *y, a, b;

public:
void inp(){
std::cout << "Enter the no. of data pairs to be entered:\n";
std::cin >> n;

x = new double[n];
y = new double[n];

std::cout << "Enter the x-axis values:\n";
for (int i = 0; i < n; i++)
    std::cin >> x[i];

std::cout << "Enter the y-axis values:\n";
for (int i = 0; i < n; i++)
    std::cin >> y[i];
  }

void calc(){
double xsum = 0, x2sum = 0, ysum = 0, xysum = 0;

for (int i = 0; i < n; i++){
    xsum += x[i];
    ysum += y[i];
    x2sum += pow(x[i], 2);
    xysum += x[i] * y[i];
  }

a = (n * xysum - xsum * ysum) / (n * x2sum - xsum * xsum);
b = (x2sum * ysum - xsum * xysum) / (x2sum * n - xsum * xsum);
}

void printit(){
double *y_fit = new double[n];
std::cout << "S.no" <<"     " << "y(fitted)" << std::endl;
std::cout << "-----------------------------------------------------------------\n";
for (int i = 0; i < n; i++){
    y_fit[i] = a * x[i] + b;
    std::cout << i + 1 << "." << std::setw(8)  << y_fit[i] <<std::endl;
    }
std::cout << "\nThe linear fit line is of the form:\n\n"<<"y = " << a << "x + " << b << std::endl;
std::ofstream  out("sqr.dat");
for (int i = 0; i < n; i++){
    y_fit[i] = a * x[i] + b;
    out<< x[i] <<"   "<< y[i] <<"   "<< y_fit[i] << std::endl;
    }
  }
};