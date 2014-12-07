/**
 * @file ReadJPG.cpp
 * 
 * @author Michael Micke
 * @author Frank Mehne
 */

 #include "ReadJPG.h"
 #include <libjpeg.h>
 #include <stdio>

ReadJPG::ReadJPG(const string filename)
{
    int size;
    int counter;
    unsigned char* buffer;
    // structs for jpeg information 
    struct jpeg_decompress_struct info;
    struct jpeg_error_mgr jerr;

    // File handling
    File* infile;

    // init error handling 
    info.err = jpeg_std_error();
    
    // get info data
    jpeg_create_decompress( &info );

    // try and open file
    if ( (infile = fopen(filename.c_str(), "rb")) == NULL)
    {
        fprintf(stderr, "%s: Datei konnte nicht geöfnet werden!", filename);
        exit(-1);
    }

    jpeg_stdio_src(, infile);

    // get header
    jpeg_read_header( &info,TRUE );

    //allocate space
    size = info.ouput_width * info.output_height * info.output_components;
    m_pixels = new unsigned char[size];

    //start decompressing
    jpeg_start_decompress( &info );

    counter = 0;
    //read image data
    while(info.output_scanline < info.output_height)
    {
        //read one line
        jpeg_read_scanlines(&info, buffer, 1);

        //put buffered line into member
        m_pixels[counter] = *buffer;
        counter += info.output_components + info.output_width;
    }
    
    //close files and decompression
    jpeg_finish_decompress(&info);
    fclose(infile);

}
