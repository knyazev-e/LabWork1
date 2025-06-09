/* Kniazeva Eva Andreevna
st128104@student.spbu.ru
labwork 1 */

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <cstdint>

#pragma pack(push, 1)

/**
 * @struct FileHeader
 * @brief Represents the BMP file header.
 *
 * Contains metadata about the BMP file such as type, size, and pixel data offset.
 */
struct FileHeader {
    uint16_t type;         ///< File type identifier (should be 0x4D42 for BMP).
    uint32_t file_size;    ///< Size of the BMP file in bytes.
    uint16_t reversed1;    ///< Reserved; actual value depends on the application.
    uint16_t reversed2;    ///< Reserved; actual value depends on the application.
    uint32_t offset;       ///< Offset to the start of pixel data.
};

/**
 * @struct InfoHeader
 * @brief Contains detailed information about the BMP image.
 *
 * Includes dimensions, bit depth, compression type, and color information.
 */
struct InfoHeader {
    uint32_t header_size;       ///< Size of this header (usually 40 bytes).
    int32_t width;              ///< Width of the image in pixels.
    int32_t height;             ///< Height of the image in pixels (negative for top-down).
    uint16_t planes;            ///< Number of color planes (must be 1).
    uint16_t bit_count;         ///< Bits per pixel (e.g., 24 for true color).
    uint32_t compression;       ///< Compression method being used.
    uint32_t image_size;        ///< Size of the raw bitmap data.
    int32_t x_pxl_per_mtr;      ///< Horizontal resolution (pixels per meter).
    int32_t y_pxl_per_mtr;      ///< Vertical resolution (pixels per meter).
    uint32_t colors_used;       ///< Number of colors in the palette.
    uint32_t colors_important;  ///< Number of important colors used.
};

/**
 * @struct Pixel
 * @brief Represents a single pixel in the BMP image.
 *
 * Stores blue, green, and red color components.
 */
struct Pixel {
    uint8_t blue;   ///< Blue component.
    uint8_t green;  ///< Green component.
    uint8_t red;    ///< Red component.
};

#pragma pack(pop)

/**
 * @class Image
 * @brief Handles BMP image loading, saving, rotation, and Gaussian blur.
 *
 * Manages pixel data and BMP headers internally.
 */
class Image {
public:
    /**
     * @brief Default constructor. Initializes an empty image.
     */
    Image();

    /**
     * @brief Destructor. Releases allocated pixel memory.
     */
    ~Image();

    /**
     * @brief Reads a BMP file from the specified path.
     * @param path Path to the BMP file.
     * @return True if the file was successfully read; false otherwise.
     */
    bool readFile(const std::string& path);

    /**
     * @brief Writes the BMP image to the specified path.
     * @param path Path to save the BMP file.
     * @return True if the file was successfully written; false otherwise.
     */
    bool writeFile(const std::string& path);

    /**
     * @brief Frees the allocated pixel memory.
     */
    void clearMemory();

    /**
     * @brief Rotates the image 90 degrees clockwise.
     */
    void rotateClockwise();

    /**
     * @brief Rotates the image 90 degrees counterclockwise.
     */
    void rotateCounterClockwise();

    /**
     * @brief Applies a Gaussian blur filter to the image.
     */
    void gaussianBlur();

private:
    Pixel **pixels;       ///< 2D array of pixels.
    FileHeader file_header;  ///< BMP file header.
    InfoHeader info_header;  ///< BMP info header.
};

#endif
