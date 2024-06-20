class kick{
private:    
int i,n;
float am1,am2,t1,t2,p1,p2,t,*a1,*a2,*a3;

public:

void up(){
std::cout<<"enter the no.of cycles of the loop:::\n";
std::cin>>n;
std::cout<<"plz enter the amplitude , inverse of T , phase of wave 1 respectively :::\n";
std::cin>>am1>>t1>>p1;
std::cout<<"plz enter the amplitude , inverse of T , phase of wave 2 respectively :::\n";
std::cin>>am2>>t2>>p2;
std::cout<<"you entered the following  amplitude   t inverse   phase\n";
std::cout<<"wave 1"<<"                         "<<am1<<"         "<<t1<<"         "<<p1<<"\n";
std::cout<<"wave 2"<<"                         "<<am2<<"         "<<t2<<"         "<<p2<<"\n";
}

void at_ease(){
a1 = new float[n];
a2 = new float[n];                 // allocating array size
a3 = new float[n];
t=0.0;
    
p1 = (4*atan(1)/180.0)*p1;        //    
p2 = (4*atan(1)/180.0)*p2;        //conversions
t1 = (8*atan(1)/t1);               //
t2 = (8*atan(1)/t2);               //
   
for(i=0;i<n;i++){
a1[i] = am1*sin(t1*t + p1) ;
a2[i] = am2*sin(t2*t + p2) ;
a3[i] = a1[i] + a2[i];
t = t + 0.1 ;
        }
     }
   
void still(){
std::ofstream outfl("supp.dat");
t=0.0;
for(i=0;i<n;i++){
outfl<<t<<"    "<<a1[i]<<"    "<<a2[i]<<"    "<<a3[i]<<std::endl;
t = t + 0.1;
        }    
    outfl.close();

        // Plot the data using gnuplot
        FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
        if (!gnuplotPipe) {
            std::cerr << "Error opening pipe to gnuplot" << std::endl;
            return;
        }
        fprintf(gnuplotPipe, "set title 'Superposition of Waves'\n");
        fprintf(gnuplotPipe, "set xlabel 'Time'\n");
        fprintf(gnuplotPipe, "set ylabel 'Amplitude'\n");
        fprintf(gnuplotPipe, "plot 'supp.dat' using 1:2 with lines title 'Wave_1'\n");
        fprintf(gnuplotPipe, "replot 'supp.dat' using 1:3 with lines title 'Wave_2'\n");
        fprintf(gnuplotPipe, "replot 'supp.dat' using 1:4 with lines title 'Resultant'\n");
           
    }
};