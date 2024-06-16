

template<typename Func>
void euler3(Func fx, Func fy, Func fz, double& x, double& y, double& z, double& vx, double& vy, double& vz, double h) {
   
    double dvx = h * fx(x, y, z, vx, vy, vz);
    double dvy = h * fy(x, y, z, vx, vy, vz);
    double dvz = h * fz(x, y, z, vx, vy, vz);

   
    x += h * vx;
    y += h * vy;
    z += h * vz;

    vx += dvx;
    vy += dvy;
    vz += dvz;
}

