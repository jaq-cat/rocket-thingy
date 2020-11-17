#include <cmath>

const float RADTODEG = 2.0 * (3.141 / 360.0);

// cosine math
float rX(float m, float rot) {
    return m * cos((rot * RADTODEG));
}

// sine math
float rY(float m, float rot) {
    return m * sin((rot * RADTODEG));
}
