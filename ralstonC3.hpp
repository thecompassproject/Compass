
template<typename Func>
void ralston3(Func fx, Func fy, Func fz, double& x, double& y, double& z, double& vx, double& vy, double& vz, double h) {
    
    double k1_x = h * vx;
    double k1_y = h * vy;
    double k1_z = h * vz;

    double k1_vx = h * fx(x, y, z, vx, vy, vz);
    double k1_vy = h * fy(x, y, z, vx, vy, vz);
    double k1_vz = h * fz(x, y, z, vx, vy, vz);

    
    double k2_x = h * (vx + 0.75 * k1_vx);
    double k2_y = h * (vy + 0.75 * k1_vy);
    double k2_z = h * (vz + 0.75 * k1_vz);

    double k2_vx = h * fx(x + 0.75 * k1_x, y + 0.75 * k1_y, z + 0.75 * k1_z, vx + 0.75 * k1_vx, vy + 0.75 * k1_vy, vz + 0.75 * k1_vz);
    double k2_vy = h * fy(x + 0.75 * k1_x, y + 0.75 * k1_y, z + 0.75 * k1_z, vx + 0.75 * k1_vx, vy + 0.75 * k1_vy, vz + 0.75 * k1_vz);
    double k2_vz = h * fz(x + 0.75 * k1_x, y + 0.75 * k1_y, z + 0.75 * k1_z, vx + 0.75 * k1_vx, vy + 0.75 * k1_vy, vz + 0.75 * k1_vz);

    
    x += (1.0 / 3.0) * k1_x + (2.0 / 3.0) * k2_x;
    y += (1.0 / 3.0) * k1_y + (2.0 / 3.0) * k2_y;
    z += (1.0 / 3.0) * k1_z + (2.0 / 3.0) * k2_z;

    vx += (1.0 / 3.0) * k1_vx + (2.0 / 3.0) * k2_vx;
    vy += (1.0 / 3.0) * k1_vy + (2.0 / 3.0) * k2_vy;
    vz += (1.0 / 3.0) * k1_vz + (2.0 / 3.0) * k2_vz;
}

