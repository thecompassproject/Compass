

template<typename Func>
void rk43(Func fx, Func fy, Func fz, double& x, double& y, double& z, double& vx, double& vy, double& vz, double h) {
   
    double k1_x = h * vx;
    double k1_y = h * vy;
    double k1_z = h * vz;

    double k1_vx = h * fx(x, y, z, vx, vy, vz);
    double k1_vy = h * fy(x, y, z, vx, vy, vz);
    double k1_vz = h * fz(x, y, z, vx, vy, vz);

    
    double k2_x = h * (vx + 0.5 * k1_vx);
    double k2_y = h * (vy + 0.5 * k1_vy);
    double k2_z = h * (vz + 0.5 * k1_vz);

    double k2_vx = h * fx(x + 0.5 * k1_x, y + 0.5 * k1_y, z + 0.5 * k1_z, vx + 0.5 * k1_vx, vy + 0.5 * k1_vy, vz + 0.5 * k1_vz);
    double k2_vy = h * fy(x + 0.5 * k1_x, y + 0.5 * k1_y, z + 0.5 * k1_z, vx + 0.5 * k1_vx, vy + 0.5 * k1_vy, vz + 0.5 * k1_vz);
    double k2_vz = h * fz(x + 0.5 * k1_x, y + 0.5 * k1_y, z + 0.5 * k1_z, vx + 0.5 * k1_vx, vy + 0.5 * k1_vy, vz + 0.5 * k1_vz);

    
    double k3_x = h * (vx + 0.5 * k2_vx);
    double k3_y = h * (vy + 0.5 * k2_vy);
    double k3_z = h * (vz + 0.5 * k2_vz);

    double k3_vx = h * fx(x + 0.5 * k2_x, y + 0.5 * k2_y, z + 0.5 * k2_z, vx + 0.5 * k2_vx, vy + 0.5 * k2_vy, vz + 0.5 * k2_vz);
    double k3_vy = h * fy(x + 0.5 * k2_x, y + 0.5 * k2_y, z + 0.5 * k2_z, vx + 0.5 * k2_vx, vy + 0.5 * k2_vy, vz + 0.5 * k2_vz);
    double k3_vz = h * fz(x + 0.5 * k2_x, y + 0.5 * k2_y, z + 0.5 * k2_z, vx + 0.5 * k2_vx, vy + 0.5 * k2_vy, vz + 0.5 * k2_vz);

   
    double k4_x = h * (vx + k3_vx);
    double k4_y = h * (vy + k3_vy);
    double k4_z = h * (vz + k3_vz);

    double k4_vx = h * fx(x + k3_x, y + k3_y, z + k3_z, vx + k3_vx, vy + k3_vy, vz + k3_vz);
    double k4_vy = h * fy(x + k3_x, y + k3_y, z + k3_z, vx + k3_vx, vy + k3_vy, vz + k3_vz);
    double k4_vz = h * fz(x + k3_x, y + k3_y, z + k3_z, vx + k3_vx, vy + k3_vy, vz + k3_vz);

    
    x += (1.0 / 6.0) * (k1_x + 2 * k2_x + 2 * k3_x + k4_x);
    y += (1.0 / 6.0) * (k1_y + 2 * k2_y + 2 * k3_y + k4_y);
    z += (1.0 / 6.0) * (k1_z + 2 * k2_z + 2 * k3_z + k4_z);

    vx += (1.0 / 6.0) * (k1_vx + 2 * k2_vx + 2 * k3_vx + k4_vx);
    vy += (1.0 / 6.0) * (k1_vy + 2 * k2_vy + 2 * k3_vy + k4_vy);
    vz += (1.0 / 6.0) * (k1_vz + 2 * k2_vz + 2 * k3_vz + k4_vz);
}


