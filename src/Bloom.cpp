#include "Bloom.h"

Bloom::Bloom() {
}

QImage Bloom::blurred(const QImage& image, const QRect& rect, int radius)
{
    int tab[] = { 14, 10, 8, 6, 5, 5, 4, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2 };
    int alpha = (radius < 1)  ? 16 : (radius > 17) ? 1 : tab[radius-1];

    QImage result = image;
    int r1 = rect.top();
    int r2 = rect.bottom();
    int c1 = rect.left();
    int c2 = rect.right();

    int bpl = result.bytesPerLine();
    int rgba[4];
    unsigned char* p;

    for (int col = c1; col <= c2; col++) {
        p = result.scanLine(r1) + col * 4;
        for (int i = 0; i < 3; i++)
            rgba[i] = p[i] << 4;

        p += bpl;
        for (int j = r1; j < r2; j++, p += bpl)
            for (int i = 0; i < 3; i++)
                p[i] = (rgba[i] += ((p[i] << 4) - rgba[i]) * alpha / 16) >> 4;
    }

    for (int row = r1; row <= r2; row++) {
        p = result.scanLine(row) + c1 * 4;
        for (int i = 0; i < 3; i++)
            rgba[i] = p[i] << 4;

        p += 4;
        for (int j = c1; j < c2; j++, p += 4)
            for (int i = 0; i < 3; i++)
                p[i] = (rgba[i] += ((p[i] << 4) - rgba[i]) * alpha / 16) >> 4;
    }

    for (int col = c1; col <= c2; col++) {
        p = result.scanLine(r2) + col * 4;
        for (int i = 0; i < 3; i++)
            rgba[i] = p[i] << 4;

        p -= bpl;
        for (int j = r1; j < r2; j++, p -= bpl)
            for (int i = 0; i < 3; i++)
                p[i] = (rgba[i] += ((p[i] << 4) - rgba[i]) * alpha / 16) >> 4;
    }

    for (int row = r1; row <= r2; row++) {
        p = result.scanLine(row) + c2 * 4;
        for (int i = 0; i < 3; i++)
            rgba[i] = p[i] << 4;

        p -= 4;
        for (int j = c1; j < c2; j++, p -= 4)
            for (int i = 0; i < 3; i++)
                p[i] = (rgba[i] += ((p[i] << 4) - rgba[i]) * alpha / 16) >> 4;
    }

    return result;
}

// Change brightness (positive integer) of each pixel
QImage Bloom::brightened(const QImage& image, int brightness) {
    int tab[ 256 ];
    for (int i = 0; i < 256; ++i)
        tab[i] = qMin(i + brightness, 255);

    QImage img = image.convertToFormat(QImage::Format_ARGB32_Premultiplied);
    for (int y = 0; y < img.height(); y++) {
        QRgb* line = (QRgb*)(img.scanLine(y));
        for (int x = 0; x < img.width(); x++)
            line[x] = qRgb(tab[qRed(line[x])], tab[qGreen(line[x])], tab[qBlue(line[x])]);
    }

    return img;
}

// Composite two QImages using given composition mode and opacity
QImage Bloom::composited(const QImage& img1, const QImage& img2, int opacity, QPainter::CompositionMode mode)
{
    QImage result = img1.convertToFormat(QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&result);
    painter.setCompositionMode(mode);
    painter.setOpacity((qreal)(opacity) / 256.0);
    painter.drawImage(0, 0, img2);
    painter.end();
    return result;
}

// Apply Bloom effect with the 4 parameters
//QImage Bloom::bloomed(const QImage& img, int blurRadius, int brightness, int opacity, QPainter::CompositionMode mode) {
//    // (1) blur the original image
//    QImage step1 = this->blurred(img, img.rect(), blurRadius);

//    // (2) increase the brightness of the blurred image
//    QImage step2 = this->brightened(step1, brightness);

//    // (3) finally overlay with the original image
//    QImage step3 = this->composited(img, step2, opacity, mode);

//    return step3;
//}

//void  enlightCircle() {
//newImage.setPixel(QPoint(x, y), );
//}

QImage Bloom::enlight(const QImage& image, const QRect& rect, int radius, int limit)
{
    //image.width(), image.height(), image.format()
    QImage newImage(image);

    int r1 = rect.top();
    int r2 = rect.bottom();
    int c1 = rect.left();
    int c2 = rect.right();

//    int x, y;

//    y = r1;
//    while (y < r2)
//    {
//        x = c1;
//        while (x < c2)
//        {
//            QRgb rgb = newImage.pixel(QPoint(x, y));
//            QColor color(rgb);
//            if (color.red >= limit)
//               enlightCircle();
//            x++;
//        }
//        y++;
//    }

    //qDebuf<< "@:" << r1 << "|" << r2 << "|" << c1 << "|" << c2;// << "|#:" << rect.top() << "|" << rect.bottom() << "|" << rect.left() << "|" << rect.right() << "|";


//    int bpl = result.bytesPerLine();
//    int rgba[4];
//    unsigned char* p;

//    for (int col = c1; col <= c2; col++) {
//        p = result.scanLine(r1) + col * 4;
//        for (int i = 0; i < 3; i++)
//            rgba[i] = p[i] << 4;

//        p += bpl;
//        for (int j = r1; j < r2; j++, p += bpl)
//            for (int i = 0; i < 3; i++)
//                p[i] = (rgba[i] += ((p[i] << 4) - rgba[i]) * alpha / 16) >> 4;
//    }
    return (newImage);
}

QImage Bloom::bloomed(const QImage& img, int blurRadius, int brightness, int opacity, QPainter::CompositionMode mode) {

    blurRadius = 10;
    int limit = 150;
    QImage step1 = this->enlight(img, img.rect(), blurRadius, limit);

//    QImage step2 = this->brightened(step1, brightness);

//    // (3) finally overlay with the original image
//    QImage step3 = this->composited(img, step2, opacity, mode);

    return step1;
}
