#include <iostream>
#include <string>
#include "qrcodegen.hpp"
#include "stb_image_write.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION


int main()
{
    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText("Lets give it a shot", qrcodegen::QrCode::Ecc::LOW);
    std::string svg = qr.toSvgString(4);
    int width, height, channels;
    unsigned char *png_data = stbi_write_png((const unsigned char *)svg.c_str(), svg.size(), &width, &height, &channels, 0);

    if (png_data != nullptr)
    {
        std::cout << "ye le qr code" << std::endl;
    }
    else
    {
        std::cerr << "nahi ho paya" << std::endl;
        return 1;
    }
    return 0;
}
