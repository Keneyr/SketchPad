#ifndef SHAPE_H
#define SHAPE_H
#include <QImage>
#include <QPen>
#include"include/DrawingArea.h"

class Shape{
public:
    Shape(DrawingArea* board);
    virtual ~Shape();

    //纯虚函数
    virtual QImage* draw()=0;
    virtual QImage* dispose(){return new QImage(*mDrawingArea->mBaseImage);}

    virtual QImage* drawWithControlPoints();
    virtual void setControlPoint(QVector<QPoint*>::iterator, const QPoint&);
    virtual bool grabControlPoint(QVector<QPoint*>::iterator&,const QPoint &);

    virtual void setDeg(int);
    int getDeg(){return deg;}

    virtual bool contain(const QPoint &);
    virtual void move(const QPoint& p);
    virtual void addScaleFactor(int factor);

    virtual void setFillColor(const QColor &color);
    void setBorderColor(const QColor &);
    void setWidth(int);

protected:
    QColor fillColor;
    QColor borderColor;
    int width;

    QImage *getBaseImage();
    QPen *getPen();

    QVector<QPoint*> points;
    QPoint center;
    int deg; //degree

private:
    DrawingArea* mDrawingArea;
};

#endif // SHAPE_H
