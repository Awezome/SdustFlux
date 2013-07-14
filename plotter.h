#ifndef PLOTTER_H_
#define PLOTTER_H_

#include <QWidget>
#include <QList>
#include <QPen>

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QStringList;
class QImage;
class QResizeEvent;
class QPoint;
QT_END_NAMESPACE

class Plotter : public QWidget
{
    Q_OBJECT

public:
    Plotter(int maximum, int minimum, 
            const QStringList &timeList, 
            const QStringList &annotateList,
            const QList<double> &valueList, 
            QWidget * parent = 0);
protected:
    void paintEvent(QPaintEvent * event);
    void resizeEvent(QResizeEvent *event);

private:
    void drawLine(const QPoint &prePoint, const QPoint &curPoint,
                  const QList<QPen> &penList, QPainter * const painter);
    int calcScreenCoord(double data, const QRect &rect);

private:
    bool m_isTimeListChanged;
    int m_maximum;
    int m_minimum;
    int *m_preYCoord;
    int *m_curYCoord;
    int m_groupCount;
    QStringList m_timeList;
    QStringList m_annotateList;
    QList<double> m_valueList;
    QImage m_image;

    QList<QPen> orangePenList;
    QList<QPen> bluePenList;
    QList<QPen> redPenList;
};

#endif // PLOTTER_H_
