#include <QtGui>

#include "plotter.h"

Plotter::Plotter(int maximum, int minimum, 
            const QStringList &timeList,
            const QStringList &annotateList,
            const QList<double> &valueList, 
            QWidget * parent)
  : QWidget(parent), m_image(rect().width(), rect().right(), QImage::Format_RGB32)    
{
    this->setFixedSize(800,300);
    m_isTimeListChanged = true;
    m_maximum = maximum;
    m_minimum = minimum;
    m_timeList = timeList;
    m_annotateList = annotateList;
    m_valueList = valueList;
    m_groupCount = valueList.size() / timeList.size();

    m_preYCoord = new int[m_groupCount];
    m_curYCoord = new int[m_groupCount];

    orangePenList << QPen(QColor(247, 194, 64), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(225, 206, 145), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(190, 195, 202), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(202, 208, 215), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(214, 220, 227), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(225, 232, 239), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    bluePenList   << QPen(QColor(175, 217, 248), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(194, 217, 237), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(190, 195, 202), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(202, 208, 215), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(214, 220, 227), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(225, 232, 239), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    redPenList    << QPen(QColor(203, 75, 75), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(208, 147, 151), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(190, 195, 202), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(202, 208, 215), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(214, 220, 227), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
                  << QPen(QColor(225, 232, 239), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    //setAttribute(Qt::WA_DeleteOnClose);
}

void Plotter::paintEvent(QPaintEvent * /*event*/)
{
    QPainter painter(this);
    QRect rect = this->rect();
    
    // 如果 <m_timeList, m_maximum, m_minimum> 没有改变，
    // 则直接从内存提取图样，而不需要重新绘制
    if (!m_isTimeListChanged)
    {
        painter.drawImage(rect, m_image);
        return;
    }

    // 改变 <m_image> 大小
    m_image = m_image.scaled(QSize(rect.width(), rect.height()));
    // 当 m_timeList 改变时
    QPainter copyPainter(&m_image);
    QRect copyRect = rect.adjusted(+50, +10, -10, -20);
    
    // 先画背景
    copyPainter.fillRect(rect, QColor(237, 244, 252));
   
    // 再画边框
    QPen fontPen(QColor(84, 84, 84), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    copyPainter.setPen(fontPen);
    copyPainter.drawRect(copyRect);

    //设置透明度
    //copyPainter.setOpacity(0.5);

    // 画Y轴坐标值
    int rows = 20; // 行数
    int yOff = m_minimum;
    int avgValue = (m_maximum-m_minimum) / rows; // 行之间的增量
    int xCoord = copyRect.x();
    int yCoord = calcScreenCoord(yOff, copyRect); // Y 坐标
    QString text;
    QFont font;
    QFontMetrics fm(font);
    int pixelsWidth;
    int pixelsHeight = fm.height() / 2.618;
    
    // 设置画笔
    QPen gridLinePen(QColor(221, 221, 221), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    fontPen.setWidth(1);
    while (yOff <= m_maximum)  {
        text = tr("%1").arg(yOff);
        pixelsWidth = fm.width(text) + 5;
        copyPainter.setPen(fontPen);
        copyPainter.drawText(xCoord-pixelsWidth, yCoord+pixelsHeight, text);
        copyPainter.setPen(gridLinePen);
        copyPainter.drawLine(xCoord+3, yCoord, xCoord+copyRect.width()-4, yCoord);

        yOff += avgValue;
        yCoord = calcScreenCoord(yOff, copyRect);
    }
    
    // 画X轴坐标值
    QFont timeFont;
    timeFont.setPointSize(12);
    QFontMetrics timefm(timeFont);
    copyPainter.setFont(timeFont);
    int cols = m_timeList.size()-1;
    int avgPix = copyRect.width() / cols;
    int curXCoord = copyRect.x();
    int preXCoord = curXCoord;
    yCoord = copyRect.y() + copyRect.height();
    int timeSize = m_timeList.size();
    for (int i = 0; i < timeSize; ++i) {
        for( int j = 0 ; j < m_groupCount; ++j ) {
            m_curYCoord[j] = calcScreenCoord(m_valueList[timeSize * j + i], copyRect);
            m_preYCoord[j] = (0 == i ? m_curYCoord[j] : m_preYCoord[j]);
        }
        
        text = m_timeList.at(i);
        pixelsWidth = timefm.width(text) / 2;
        copyPainter.setPen(fontPen);
        copyPainter.drawText(curXCoord-pixelsWidth, yCoord+15, text);
        if (0 != i) {
            copyPainter.setPen(gridLinePen);
            copyPainter.drawLine(curXCoord, copyRect.y()+1, curXCoord, yCoord-4);
        }

        // 绘制点和线
        for( int j = 0 ; j < m_groupCount ; ++j ) {
            drawLine(QPoint(preXCoord + 5, m_preYCoord[j] + 1), 
                     QPoint(curXCoord, m_curYCoord[j] + 1),
                     (j%3 == 0 ? orangePenList : (j%3 == 1 ? bluePenList : redPenList)),
                     &copyPainter);
        }

        preXCoord  = curXCoord;
        curXCoord += avgPix;
        for( int j = 0 ; j < m_groupCount ; ++j ) {
            m_preYCoord[j] = m_curYCoord[j];
        }
    }

    // 将绘制好的图片贴到桌面上
    painter.drawImage(rect, m_image);
    m_isTimeListChanged = false;
}

/* 
 * 计算坐标值
 * 返回值：在屏幕上显示的Y坐标
 */
int Plotter::calcScreenCoord(double data, const QRect &rect)
{
    // 每个像素对应的单位值
    double valuePerPixel = (double)(double(m_maximum-m_minimum) / (rect.height() - 4));
    
    double finalCoord = (double)((data-m_minimum) / valuePerPixel);
    finalCoord = (rect.y()+rect.height() - 3) - finalCoord;

    return finalCoord;
}

void Plotter::drawLine(const QPoint &prePoint, const QPoint &curPoint, 
                       const QList<QPen> &penList, QPainter * const painter)
{
    // 绘制当前节点，前面一个节点已经绘制
    // 必须先画节点，再画线
    int xOff = 1;
    int x1 = prePoint.x();
    int y1 = prePoint.y();
    int x2 = curPoint.x();
    int y2 = curPoint.y();
    // 求斜率
    double slope =  double(double(y2 - y1) / double(x2 - x1));
    /*qDebug() << tr("(x1, y1) = (%1, %2)   (x2, y2) = (%3, %4)")
                  .arg(x1)
                  .arg(y1)
                  .arg(x2)
                  .arg(y2);*/
    if (slope > 0.0){
        xOff = -1;
        x1 -= 3;
        y1 += 1;
    }
    else if (slope < 0.0){
        x1 -= 2; 
        y1 -= 2;
        y2 += 1;
    }

    for( int i = 0 ; i < 6 ; ++i ){
        painter->setPen(penList.at(i));
        painter->drawLine(x1 + xOff * i, y1 + i, x2 + xOff * i, y2 + i);
    }

    QPen oldPen = painter->pen();
    painter->setPen(oldPen);
    painter->drawPixmap(x2 - 4, y2 - 5, QPixmap(":/image/image/node.png"));
}

void Plotter::resizeEvent(QResizeEvent * /*event*/)
{
    m_isTimeListChanged = true;
}

