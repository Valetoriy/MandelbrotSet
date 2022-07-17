#include "App.hpp"

auto main() -> int {
    constexpr auto aspect_ratio{4.0 / 3.0};
    constexpr auto image_width{1440};
    constexpr auto viewport_width{3.0};
    constexpr std::complex origin{-0.7, 0.0};
    App app(aspect_ratio, image_width, viewport_width, origin);

    app.exec();

    return 0;
}
