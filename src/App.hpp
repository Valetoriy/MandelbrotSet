#pragma once

#include <complex>

class App {
   public:
    App(const double &a_r, const int &i_w, const double &v_w,
        const std::complex<double> &o);

    auto exec() const -> void;

   private:
    double aspect_ratio;
    int image_width;
    int image_height;

    double viewport_width;
    double viewport_height;

    std::complex<double> origin;
    std::complex<double> horizontal;
    std::complex<double> vertical;
    std::complex<double> lower_left_corner;
};
