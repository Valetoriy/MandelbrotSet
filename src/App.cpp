#include "App.hpp"

#include <fmt/format.h>

#include <iostream>

App::App(const double &a_r, const int &i_w, const double &v_w,
         const std::complex<double> &o)
    : aspect_ratio{a_r},
      image_width{i_w},
      image_height{static_cast<int>(image_width / aspect_ratio)},
      viewport_width{v_w},
      viewport_height{viewport_width / aspect_ratio},
      origin{o},
      horizontal{viewport_width, 0.0},
      vertical{0.0, viewport_height},
      lower_left_corner{origin - horizontal / 2.0 - vertical / 2.0} {}

auto App::exec() const -> void {
    fmt::print("P3\n{} {}\n255\n", image_width, image_height);

    for (int i{image_height - 1}; i >= 0; --i) {
        std::cerr << "\rОсталось скан-линий: " << i << ' ' << std::flush;
        for (int j{}; j < image_width; ++j) {
            std::complex c{viewport_width * double(j) / image_width,
                           viewport_height * double(i) / image_height};
            c += lower_left_corner;

            std::complex z{0.0, 0.0};
            int iter{};
            for (; std::abs(z) <= 2 and iter < 1000; ++iter) {
                // x = Re(z^2 + c) = Re(x^2 + i * 2 * x * y + i * i *y^2 + x0 +
                // iy0) = x^2 - y^2 + x0
                auto xtemp{z.real() * z.real() - z.imag() * z.imag() +
                           c.real()};
                // y = Im(z^2 + c) = 2 * x * y + y0
                z.imag(2 * z.real() * z.imag() - c.imag());
                z.real(xtemp);
            }

            auto t{iter / 1000.0};
            auto r = static_cast<int>(std::lerp(0, 0, t));
            auto g = static_cast<int>(std::lerp(167, 0, t));
            auto b = static_cast<int>(std::lerp(108, 0, t));

            fmt::print("{} {} {}\n", r, g, b);
        }
    }

    std::cerr << "\nГотово.\n";
}
