#ifndef FILTER_H
#define FILTER_H

#include <QThread>
#include "Image.h"
#include <string>

class Filter : public QThread
{
    Q_OBJECT
public:
    Filter( Image* inputImage, Image* outputImage );
    Filter( Image* inputImage, float scaleFactor );
    Filter( Image* inputImage, float scaleFactor, int numberOfPasses );
    Filter( Image* inputImage, int outputWidth, int outputHeight );
    Filter( Image* inputImage );
    ~Filter();

    virtual void apply() = 0;
    virtual void run() Q_DECL_OVERRIDE = 0;

    Image* getOutputImage();
    int getScaleFactor();
    std::string getName();
    void setNewInputImage( Image* image );

protected:

    void fillBufferBGRA( u_char* inputBuffer );
    void fillImageBGRA( u_char* outputBuffer );

    void fillBufferRGB( u_char* inputBuffer );
    void fillImageRGB( u_char* outputBuffer );

    Image* _inputImage;
    Image* _outputImage;

    float _scaleFactor;

    std::string _name;

signals:

    void setProgress( int percentage );
};

#endif // FILTER_H
