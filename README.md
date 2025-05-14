# Image Processing Project

## Overview

This project is an image processing application that provides various filters and transformations for image manipulation. It's implemented in C++ and offers a user-friendly command-line interface for applying different effects to images.

## Features

The application supports the following filters and operations:

1. Grayscale Conversion
2. Black and White
3. Invert Image
4. Merge Images
5. Flip Image (Horizontal/Vertical)
6. Rotate Image (90°/180°/270°)
7. Darken and Lighten Image
8. Crop Image
9. Frame Image (Simple/Fancy)
10. Detect Image Edges
11. Resize Image
12. Blur Image
13. Sunlight Effect
14. Purple Effect
15. Infrared Effect

## Supported Image Formats

- JPEG (.jpg, .jpeg)
- PNG (.png)
- BMP (.bmp)
- TGA (.tga)

## Dependencies

- C++ compiler
- STB Image library (included in the project)
  - stb_image.h
  - stb_image_write.h

## Project Structure

- `CS112_A3_Part2B_S16_20230287_20230613_20230802.cpp` - Main program file
- `Image_Class.h` - Image processing class implementation
- Individual filter files (filter1.cpp through filter17.cpp)
- Sample images for testing

## How to Use

1. **Compile the Program**

   ```bash
   g++ CS112_A3_Part2B_S16_20230287_20230613_20230802.cpp -o image_processor
   ```

2. **Run the Program**

   ```bash
   ./image_processor
   ```

3. **Follow the Interactive Menu**
   - Enter the image filename with extension
   - Choose a filter from the menu (1-15)
   - Follow the prompts for specific filter parameters
   - Choose to save as a new image or overwrite the existing one
   - Continue with more filters or type 'exit' to quit

## Authors

- Fahd Deya El-din Salah El-din Ahmed (20230287)

  - Email: fahd.cu2004@gmail.com
  - Contributions: Filters 1, 7, 10, 17 and menus

- Mohamed Ashraf Mahmoud Ahmed (20230613)

  - Email: mohamedashraf1304@gmail.com
  - Contributions: Filters 2, 4, 8, 11, 13

- Nesrain Sadeq Mohammed (20230802)
  - Email: nesreensadiq347@gmail.com
  - Contributions: Filters 3, 5, 6, 9, 12, 16

## Example Usage

```
Welcome to filters program
Please enter the image name with file extension that you want to edit (or 'exit'):
> input.jpg

now you need to choose a filter to apply.
1) Grayscale Conversion filter.
2) Black and White filter.
[...]

> 1
you choose to apply Grayscale Conversion filter.
the filter applied successfully.

you want to save the new image or apply the filter in the same image?
1) same image.
2) new image.

> 2
please enter the name of the new file 'hint: with the extension'
> output.jpg
new image created successfully.
```

## Notes

- Make sure input images are in the same directory as the program or provide the full path
- For merge operations, both images should be accessible
- Some filters may require additional parameters (e.g., crop dimensions, frame thickness)
- The program will validate file extensions and image formats before processing
