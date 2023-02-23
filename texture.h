#ifndef TEXTURE_H
#define TEXTURE_H

#include <QOpenGLFunctions_4_1_Core>

/**
    \brief Simple class for creating textures from a bitmap file.
    \original code author Dag Nylund (the teacher of the course)
    ///edits were made to the code to make it work with the rest of the program.
 */
class Texture : protected QOpenGLFunctions_4_1_Core
{
public:
    Texture();  //basic texture from code
    Texture(const std::string &filename, bool cubeMap = false);
    GLuint id() const;
    std::string textureFilename;
    float getHeightMap(int i);
    void readBitmap(const std::string& filename);

    int mColumns;
    int mRows;
    unsigned char *mCubemap[6]{nullptr};

    GLuint mTextureId{0};          //Texture ID that OpenGL makes when glGenTextures is called

private:
    GLubyte pixels[16];
    GLuint mId{0};
    unsigned char *mBitmap;
    int mBytesPrPixel{};
    bool mAlphaUsed{false};

    int mnByte;

    void setTexture();
    ///
    /// \brief readCubeMap.
    /// takes in string name and string stream for texture filename.
    /// for loop finds cubemap bmps and reads them.
    ///
    void readCubeMap();
    ///
    /// \brief setCubemapTexture, simply sets the texture for the cubemap.
    /// Generates textures and binds them to cubemap,
    ///
    void setCubemapTexture();

private:
    typedef unsigned short int OWORD;    //should be 16 bit
    typedef unsigned int ODWORD;         //should be 32 bit
    typedef int OLONG;                   //should be 32 bit

    struct OBITMAPINFOHEADER {
        ODWORD biSize;
        OLONG  biWidth;
        OLONG  biHeight;
        OWORD  biPlanes;
        OWORD  biBitCount;
        ODWORD biCompression;
        ODWORD biSizeImage;
        OLONG  biXPelsPerMeter;
        OLONG  biYPelsPerMeter;
        ODWORD biClrUsed;
        ODWORD biClrImportant;
    };

    struct OBITMAPFILEHEADER {
        OWORD  bfType;
        ODWORD bfSize;
        OWORD  bfReserved1;
        OWORD  bfReserved2;
        ODWORD bfOffBits;
    };
};

#endif // TEXTURE_H
