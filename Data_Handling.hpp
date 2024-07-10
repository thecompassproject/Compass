class peace{
private:    
int n, x, d;
float *lo,sum,u1,u2,u3,u4,j,k,l,q,t,sam;

public:
void saman(){
std::cout << "To enter data by reading a file, enter 1. Else, enter 2 to input data manually: ";
std::cin >> d;

if (d == 2){
std::cout << "Enter size of the data sample: ";
std::cin >> n;
lo = new float[n];
std::cout << "Enter the data (hit the enter key after every entry) of size " << n << "\n";
for (x = 0; x < n; x++){
    std::cin >> lo[x];
    }
} 

else{
    int size = 40;
    char* name = new char[size];
    std::cout<<"enter the name of data file along with the extention::::";
    std::cin>>name;
    std::ifstream inputFile(name);
    float value;
    n = 0;
    while(inputFile >> value){
        n++;
    }

inputFile.close();
inputFile.open(name);
lo = new float[n];

for(x = 0; x < n; x++){
    inputFile >> lo[x];
        }
        }
    }

void sejal(){
    sum = 0;
for(x = 0; x < n; x++){
    sum += lo[x];
    }
u1 = sum / n;
std::cout << "The mean / the first moment of the given data is [ " << u1 << " ]\n";
}

void sage(){
    j = 0;
for(x = 0; x < n; x++){
    j += pow((lo[x] - u1), 2);
    }
u2 = j / (n - 1);
std::cout << "The variance / the second moment of the given data is [ " << u2 << " ]\n";
    }

void raavi(){
    k = sqrt(u2);
    std::cout << "The standard deviation of the given data is [ " << k << " ]\n";
    }

void romi(){
    l = 0;
for(x = 0; x < n; x++){
    l += pow((lo[x] - u1), 3);
    }
q = pow(k, 3);
u3 = l / ((n - 1) * q);
std::cout << "The skewness / the third moment of the given data is [ " << u3 << " ]\n";
}

void dualipa(){
    t = 0;
    for(x = 0; x < n; x++){
        t += pow((lo[x] - u1), 4);
        }
    sam = (n - 1) * pow(k, 4);
    u4 = t / sam;
    std::cout << "The kurtosis / the fourth moment of the given data is [ " << u4 << " ]\n";
  }
};
