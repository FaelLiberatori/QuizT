#ifndef IMAGEREADER_H
#include <QObject>
#include <QDir>
#include <QFileInfo>
#define IMAGEREADER_H

class ImageReader: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nextImage READ loadImage NOTIFY loadImageChanged)

signals:
    void loadImageChanged();

public:

    ImageReader(QString directory)
    {
        dir = directory;

        QStringList filter;
        filter << "*.jpg";
        QDir imageFolder(dir);
        QFileInfoList imageFiles = imageFolder.entryInfoList(filter, QDir::Files|QDir::NoDotAndDotDot);

        imageCount = imageFiles.length();
    }

    QString loadImage()
    {
        nextImage();

        return currentImage.replace(":/", ""); //A not so good way to convert url :(
    }

private:
    QString dir;
    QString currentImage;
    int currentImageNumber = -1;
    int imageCount;

    void nextImage()
    {
        if(currentImageNumber >= imageCount - 1)
            currentImageNumber = 0;
        else
            currentImageNumber++;

        currentImage = dir + QString::number(currentImageNumber) + ".jpg";
    }
};

#endif // IMAGEREADER_H
