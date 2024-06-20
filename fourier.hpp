class fourier{
private:
int n,t,i,k;
float p,omega,a,sum,fs,timp;

public:
void input(){
  std::cout<<"enter the value of n for no.of sin waves to be superimposed:";
  std::cin>>n;
  std::cout<<"\nenter the value of timeperiod of square wave:";
  std::cin>>timp;
  std::cout<<"\nenter the value of amplitude:";
  std::cin>>a;
  std::cout<<"\nenter the no.of times you would like to run the loop:";
  std::cin>>t;
 }

void calc(){
std::ofstream out("fourier.dat");
omega=(2*(4*atan(1.0))/timp);
for(k=1;k<=t;k++){
   p=omega*k;
   sum=0.0;
    for( i=1;i<=n;i+=2){
    sum=sum+(sin(i*p))/i;
   }
fs=(4*a*sum)/(4*atan(1));
out<<k<<"      "<<fs<<std::endl;
  }
 out.close();

        // Plot the data using gnuplot
        FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
        if (!gnuplotPipe) {
            std::cerr << "Error opening pipe to gnuplot" << std::endl;
            return;
        }
        fprintf(gnuplotPipe, "set title 'Fourier Analysis Of Square Waves'\n");
        fprintf(gnuplotPipe, "set xlabel 'Time'\n");
        fprintf(gnuplotPipe, "set ylabel 'Amplitude'\n");
        fprintf(gnuplotPipe, "plot 'fourier.dat' using 1:2 with lines title 'Resultant'\n");
        
 }
};